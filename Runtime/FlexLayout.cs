using System.Collections.Generic;
using System.Threading.Tasks;
using Gilzoide.FlexUi.Yoga;
using UnityEngine;
using UnityEngine.EventSystems;

namespace Gilzoide.FlexUi
{
    [ExecuteAlways]
    [RequireComponent(typeof(RectTransform))]
    public class FlexLayout : UIBehaviour, IComparer<FlexLayout>
    {
        public const DrivenTransformProperties DrivenRectTransformProperties = DrivenTransformProperties.Anchors | DrivenTransformProperties.AnchoredPosition | DrivenTransformProperties.SizeDelta;

        [FoldoutHeader("Position")]
        [SerializeField] private PositionType _positionType = PositionType.Relative;
        [SerializeField] private YGValue _positionLeft = YGValue.Undefined;
        [SerializeField] private YGValue _positionTop = YGValue.Undefined;
        [SerializeField] private YGValue _positionRight = YGValue.Undefined;
        [SerializeField] private YGValue _positionBottom = YGValue.Undefined;

        [FoldoutHeader("Flex")]
        [SerializeField] private Direction _direction = Direction.Inherit;
        [SerializeField] private FlexDirection _flexDirection = FlexDirection.Row;
        [SerializeField] private Wrap _flexWrap = Wrap.Wrap;
        [SerializeField] private YGValue _flexBasis = YGValue.Auto;
        [SerializeField, Min(0)] private float _flexGrow = 0;
        [SerializeField, Min(0)] private float _flexShrink = 1;

        [FoldoutHeader("Alignment")]
        [SerializeField] private Justify _justifyContent = Justify.FlexStart;
        [SerializeField] private Align _alignItems = Align.Auto;
        [SerializeField] private Align _alignSelf = Align.Auto;
        [SerializeField] private Align _alignContent = Align.Auto;

        [FoldoutHeader("Size")]
        [SerializeField] private YGValue _width = new YGValue(100, Unit.Point);
        [SerializeField] private YGValue _height = new YGValue(100, Unit.Point);
        [SerializeField] private YGValue _minWidth = YGValue.Undefined;
        [SerializeField] private YGValue _minHeight = YGValue.Undefined;
        [SerializeField] private YGValue _maxWidth = YGValue.Undefined;
        [SerializeField] private YGValue _maxHeight = YGValue.Undefined;
        [SerializeField] private YGValue _aspectRatio = YGValue.Undefined;

        [FoldoutHeader("Margin")]
        [SerializeField] private YGValue _marginLeft = YGValue.Zero;
        [SerializeField] private YGValue _marginTop = YGValue.Zero;
        [SerializeField] private YGValue _marginRight = YGValue.Zero;
        [SerializeField] private YGValue _marginBottom = YGValue.Zero;

        [FoldoutHeader("Padding")]
        [SerializeField] private YGValue _paddingLeft = YGValue.Zero;
        [SerializeField] private YGValue _paddingTop = YGValue.Zero;
        [SerializeField] private YGValue _paddingRight = YGValue.Zero;
        [SerializeField] private YGValue _paddingBottom = YGValue.Zero;

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
        private bool _isRefreshScheduled;

        protected override void Awake()
        {
            base.Awake();
            RectTransform = transform as RectTransform;
        }

        protected override void OnEnable()
        {
            base.OnEnable();
            RefreshParent();
        }

        protected override void OnDisable()
        {
            base.OnDisable();
            ClearParent();
            ClearTrackedChildren();
        }

        protected override void OnDestroy()
        {
            base.OnDestroy();
            _layoutNode.Dispose();
        }

        protected override void OnTransformParentChanged()
        {
            base.OnTransformParentChanged();
            RefreshParent();
        }

        protected override void OnRectTransformDimensionsChange()
        {
            base.OnRectTransformDimensionsChange();
            if (IsActive() && IsRootLayoutNode)
            {
                RefreshLayout();
            }
        }

        public async void RefreshRootLayout()
        {
            FlexLayout root = RootLayoutNode;
            if (root._isRefreshScheduled)
            {
                return;
            }

            root._isRefreshScheduled = true;
            try
            {
                await Task.Yield();
                if (root)
                {
                    root.RefreshLayout();
                }
            }
            finally
            {
                root._isRefreshScheduled = false;
            }
        }

        public void RefreshRootLayoutImmediate()
        {
            RootLayoutNode.RefreshLayout();
        }

        public int Compare(FlexLayout x, FlexLayout y)
        {
            int xSibling = x ? x.RectTransform.GetSiblingIndex() : -1;
            int ySibling = y ? y.RectTransform.GetSiblingIndex() : -1;
            return xSibling.CompareTo(ySibling);
        }

        protected void RefreshLayout()
        {
            if (IsRootLayoutNode)
            {
                Rect rect = RectTransform.rect;
                LayoutNode.CalculateLayout(rect.width, rect.height, _direction);
            }
            else
            {
                LayoutNode.ApplyTo(RectTransform);
            }

            foreach (FlexLayout child in _childrenNodes)
            {
                child.RefreshLayout();
            }
        }

        protected void UpdateNodeStyle()
        {
            YGNode layoutNode = LayoutNode;
            // position
            layoutNode.StyleSetPositionType(_positionType);
            layoutNode.StyleSetPosition(Edge.Left, _positionLeft);
            layoutNode.StyleSetPosition(Edge.Top, _positionTop);
            layoutNode.StyleSetPosition(Edge.Right, _positionRight);
            layoutNode.StyleSetPosition(Edge.Bottom, _positionBottom);
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
            // size
            layoutNode.StyleSetWidth(_width);
            layoutNode.StyleSetHeight(_height);
            layoutNode.StyleSetMinWidth(_minWidth);
            layoutNode.StyleSetMinHeight(_minHeight);
            layoutNode.StyleSetMaxWidth(_maxWidth);
            layoutNode.StyleSetMaxHeight(_maxHeight);
            layoutNode.StyleSetAspectRatio(_aspectRatio.Value);
            // margin
            layoutNode.StyleSetMargin(Edge.Left, _marginLeft);
            layoutNode.StyleSetMargin(Edge.Top, _marginTop);
            layoutNode.StyleSetMargin(Edge.Right, _marginRight);
            layoutNode.StyleSetMargin(Edge.Bottom, _marginBottom);
            // padding
            layoutNode.StyleSetPadding(Edge.Left, _paddingLeft);
            layoutNode.StyleSetPadding(Edge.Top, _paddingTop);
            layoutNode.StyleSetPadding(Edge.Right, _paddingRight);
            layoutNode.StyleSetPadding(Edge.Bottom, _paddingBottom);

            RefreshRootLayout();
        }

        protected void RefreshParent()
        {
            Transform parent = RectTransform.parent;
            if (parent && parent.TryGetComponent(out FlexLayout parentNode))
            {
                if (parentNode != _parentNode)
                {
                    if (_parentNode)
                    {
                        _parentNode.UntrackChild(this);
                    }
                    parentNode.TrackChild(this);
                }
            }
            else
            {
                _parentNode = null;
            }
        }

        protected void ClearParent()
        {
            if (_parentNode)
            {
                _parentNode.UntrackChild(this);
            }
        }

        protected void TrackChild(FlexLayout child)
        {
            child._parentNode = this;
            int binaryIndex = _childrenNodes.BinarySearch(child, this);
            if (binaryIndex < 0)
            {
                int childIndex = ~binaryIndex;
                _childrenNodes.Insert(childIndex, child);
                LayoutNode.InsertChild(child.LayoutNode, childIndex);
            }
            RefreshTrackedChildren();
        }

        protected void UntrackChild(FlexLayout child)
        {
            child._parentNode = null;
            int index = _childrenNodes.BinarySearch(child, this);
            if (index >= 0)
            {
                LayoutNode.RemoveChild(_childrenNodes[index].LayoutNode);
                _childrenNodes.RemoveAt(index);
            }
            RefreshTrackedChildren();
        }

        protected void RefreshTrackedChildren()
        {
            _drivenRectTransformTracker.Clear();
            foreach (FlexLayout child in _childrenNodes)
            {
                _drivenRectTransformTracker.Add(this, child.RectTransform, DrivenRectTransformProperties);
            }
        }

        protected void ClearTrackedChildren()
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

#if UNITY_EDITOR
        protected override void OnValidate()
        {
            base.OnValidate();
            UpdateNodeStyle();
        }
#endif
    }
}
