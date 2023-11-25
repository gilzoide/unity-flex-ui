using System.Collections.Generic;
using Gilzoide.FlexUi.Yoga;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

namespace Gilzoide.FlexUi
{
    [ExecuteAlways]
    [RequireComponent(typeof(RectTransform))]
    public class FlexLayout : MonoBehaviour, ILayoutGroup
    {
        [Header("Flex")]
        [SerializeField] private Direction _direction = Direction.Inherit;
        [SerializeField] private FlexDirection _flexDirection = FlexDirection.Row;
        [SerializeField] private Wrap _flexWrap = Wrap.Wrap;
        [SerializeField] private YGValue _flexBasis = YGValue.Auto;
        [SerializeField, Min(0)] private float _flexGrow = 0;
        [SerializeField, Min(0)] private float _flexShrink = 1;

        [Header("Alignment")]
        [SerializeField] private Justify _justifyContent = Justify.FlexStart;
        [SerializeField] private Align _alignItems = Align.Auto;
        [SerializeField] private Align _alignSelf = Align.Auto;
        [SerializeField] private Align _alignContent = Align.Auto;

        [Header("Layout")]
        [SerializeField] private YGValue _width = YGValue.Auto;
        [SerializeField] private YGValue _height = YGValue.Auto;
        [SerializeField] private YGValue _minWidth = YGValue.Undefined;
        [SerializeField] private YGValue _minHeight = YGValue.Undefined;
        [SerializeField] private YGValue _maxWidth = YGValue.Undefined;
        [SerializeField] private YGValue _maxHeight = YGValue.Undefined;
        [SerializeField] private YGValue _aspectRatio = YGValue.Undefined;

        public bool IsRootLayoutNode => _parentNode == null;
        public FlexLayout RootLayoutNode
        {
            get
            {
                FlexLayout node = this;
                while (!node.IsRootLayoutNode)
                {
                    node = node._parentNode;
                }
                return node;
            }
        }

        public RectTransform RectTransform { get; private set; }

        protected YGNode LayoutNode
        {
            get
            {
                if (_layoutNode.IsNull)
                {
                    _layoutNode.Instantiate();
                    UpdateNodeStyle();
                }
                return _layoutNode;
            }
        }
        private YGNode _layoutNode;
        private FlexLayout _parentNode;
        private readonly List<FlexLayout> _childrenNodes = new List<FlexLayout>();
        private DrivenRectTransformTracker _drivenRectTransformTracker = new DrivenRectTransformTracker();

        void Awake()
        {
            RectTransform = transform as RectTransform;
        }

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
            RefreshTrackedChildren();
        }

        public void SetLayoutHorizontal()
        {
            if (!IsRootLayoutNode)
            {
                return;
            }

            Rect rect = RectTransform.rect;
            LayoutNode.CalculateLayout(rect.width, rect.height, _direction);
        }

        public void SetLayoutVertical()
        {
            if (!IsRootLayoutNode)
            {
                return;
            }

            foreach (FlexLayout child in _childrenNodes)
            {
                child.ApplyLayout();
            }
        }

        public void ClearTrackedChildren()
        {
            _drivenRectTransformTracker.Clear();

            foreach (FlexLayout child in _childrenNodes)
            {
                if (child && child._parentNode == this)
                {
                    child._parentNode = null;
                }
            }
            _childrenNodes.Clear();

            if (!_layoutNode.IsNull)
            {
                _layoutNode.RemoveAllChildren();
            }
        }

        public void RefreshTrackedChildren()
        {
            ClearTrackedChildren();
            if (!isActiveAndEnabled)
            {
                return;
            }

            int childIndex = 0;
            foreach (Transform child in transform)
            {
                if (!(child is RectTransform rectTransform)
                    || !child.TryGetComponent(out FlexLayout childLayout))
                {
                    continue;
                }

                _drivenRectTransformTracker.Add(this, rectTransform, DrivenTransformProperties.Anchors | DrivenTransformProperties.AnchoredPosition | DrivenTransformProperties.SizeDelta);

                childLayout._parentNode = this;
                _childrenNodes.Add(childLayout);
                LayoutNode.InsertChild(childLayout.LayoutNode, childIndex);

                childIndex++;
            }

            LayoutRebuilder.MarkLayoutForRebuild(RootLayoutNode.RectTransform);
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
            layoutNode.StyleSetAspectRatio(_aspectRatio.Value);
        }

        protected void ApplyLayout()
        {
            LayoutNode.ApplyTo(RectTransform);
        }

#if UNITY_EDITOR
        private void OnValidate()
        {
            UpdateNodeStyle();
            LayoutRebuilder.MarkLayoutForRebuild(RootLayoutNode.RectTransform);
        }
#endif
    }
}
