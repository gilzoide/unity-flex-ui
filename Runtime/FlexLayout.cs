using System.Collections.Generic;
using Gilzoide.FlexUi.Yoga;
using UnityEngine;
using UnityEngine.UI;

namespace Gilzoide.FlexUi
{
    [ExecuteAlways]
    [RequireComponent(typeof(RectTransform))]
    public class FlexLayout : MonoBehaviour, ILayoutGroup
    {
        [Header("Flex")]
        [SerializeField] private Direction _direction;
        [SerializeField] private FlexDirection _flexDirection;
        [SerializeField] private Wrap _flexWrap;
        [SerializeField] private YGValue _flexBasis = YGValue.Auto;
        [SerializeField, Min(0)] private float _flexGrow = 0;
        [SerializeField, Min(0)] private float _flexShrink = 1;

        [Header("Alignment")]
        [SerializeField] private Justify _justifyContent;
        [SerializeField] private Align _alignItems;
        [SerializeField] private Align _alignSelf;
        [SerializeField] private Align _alignContent;

        [Header("Layout")]
        [SerializeField] private YGValue _width = YGValue.Auto;
        [SerializeField] private YGValue _height = YGValue.Auto;
        [SerializeField] private YGValue _minWidth = YGValue.Undefined;
        [SerializeField] private YGValue _minHeight = YGValue.Undefined;
        [SerializeField] private YGValue _maxWidth = YGValue.Undefined;
        [SerializeField] private YGValue _maxHeight = YGValue.Undefined;
        [SerializeField, Min(0)] private float _aspectRatio = 0;

        public bool IsRootLayoutNode => LayoutNode.GetOwner().IsNull;
        public RectTransform RootLayoutNode
        {
            get
            {
                YGNode node = LayoutNode;
                Transform nodeTransform = transform;
                while (true)
                {
                    YGNode owner = node.GetOwner();
                    if (owner.IsNull)
                    {
                        return nodeTransform as RectTransform;
                    }
                    node = owner;
                    nodeTransform = nodeTransform.parent;
                }
            }
        }

        protected YGNode LayoutNode
        {
            get
            {
                if (_layoutNode.IsNull)
                {
                    _layoutNode = YGNode.Create();
                    UpdateNodeStyle();
                }
                return _layoutNode;
            }
        }
        private YGNode _layoutNode;
        private readonly Dictionary<RectTransform, YGNode> _childrenLayoutMap = new Dictionary<RectTransform, YGNode>();
        private DrivenRectTransformTracker _drivenRectTransformTracker = new DrivenRectTransformTracker();
        private Rect _rect;

        public RectTransform SelfRectTransform => (RectTransform) transform;

        void OnEnable()
        {
            RefreshTrackedChildren();
        }

        void OnDisable()
        {
            ClearTrackedChildren();
        }

        void OnDestroy()
        {
            _layoutNode.Dispose();
        }

        void OnTransformChildrenChanged()
        {
            if (isActiveAndEnabled)
            {
                RefreshTrackedChildren();
            }
        }

        public void SetLayoutHorizontal()
        {
            if (!IsRootLayoutNode)
            {
                return;
            }

            _rect = SelfRectTransform.rect;
            LayoutNode.CalculateLayout(_rect.width, _rect.height, Direction.Inherit);
        }

        public void SetLayoutVertical()
        {
            if (!IsRootLayoutNode)
            {
                return;
            }

            foreach ((RectTransform child, YGNode layout) in _childrenLayoutMap)
            {
                layout.ApplyTo(child);
            }
        }

        public void ClearTrackedChildren()
        {
            _drivenRectTransformTracker.Clear();
            _childrenLayoutMap.Clear();
            if (!_layoutNode.IsNull)
            {
                _layoutNode.RemoveAllChildren();
            }
        }

        public void RefreshTrackedChildren()
        {
            ClearTrackedChildren();

            int childIndex = 0;
            foreach (Transform child in transform)
            {
                if (!(child is RectTransform rectTransform)
                    || !child.TryGetComponent(out FlexLayout childLayout))
                {
                    continue;
                }

                _drivenRectTransformTracker.Add(this, rectTransform, DrivenTransformProperties.Anchors | DrivenTransformProperties.AnchoredPosition | DrivenTransformProperties.SizeDelta);

                YGNode childNode = childLayout.LayoutNode;
                _layoutNode.InsertChild(childNode, childIndex);
                _childrenLayoutMap[rectTransform] = childNode;

                childIndex++;
            }

            LayoutRebuilder.MarkLayoutForRebuild(SelfRectTransform);
        }

        protected void UpdateNodeStyle()
        {
            YGNode layoutNode = LayoutNode;
            // flex
            layoutNode.StyleSetDirection(_direction);
            layoutNode.StyleSetFlexDirection(_flexDirection);
            layoutNode.StyleSetFlexWrap(_flexWrap);
            layoutNode.StyleSetFlexBasis(_flexBasis);
            layoutNode.StyleSetFlexGrow(_flexGrow);
            layoutNode.StyleSetFlexShrink(_flexShrink);
            // alignment
            layoutNode.StyleSetJustifyContent(_justifyContent);
            layoutNode.StyleSetAlignItems(_alignItems);
            layoutNode.StyleSetAlignSelf(_alignSelf);
            layoutNode.StyleSetAlignContent(_alignContent);
            // layout
            layoutNode.StyleSetWidth(_width);
            layoutNode.StyleSetHeight(_height);
            layoutNode.StyleSetMinWidth(_minWidth);
            layoutNode.StyleSetMinHeight(_minHeight);
            layoutNode.StyleSetMaxWidth(_maxWidth);
            layoutNode.StyleSetMaxHeight(_maxHeight);
            layoutNode.StyleSetAspectRatio(_aspectRatio);
        }

#if UNITY_EDITOR
        private void OnValidate()
        {
            UpdateNodeStyle();
            LayoutRebuilder.MarkLayoutForRebuild(RootLayoutNode);
        }
#endif
    }
}
