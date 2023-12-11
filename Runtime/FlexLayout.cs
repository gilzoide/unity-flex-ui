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

        [SerializeField] private FlexLayoutConfig _configuration;

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
        [SerializeField] private Align _alignItems = Align.FlexStart;
        [SerializeField] private Align _alignSelf = Align.Auto;
        [SerializeField] private Align _alignContent = Align.Auto;

        [FoldoutHeader("Size")]
        [SerializeField] private YGValue _width = YGValue.Auto;
        [SerializeField] private YGValue _height = YGValue.Auto;
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

#if UNITY_EDITOR || !UNITY_2021_2_OR_NEWER
        [SerializeField, HideInInspector] internal bool[] _foldoutState = { false, false, false, false, false, false };
#endif

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

        public RectTransform RectTransform
        {
            get
            {
                if (!_rectTransform)
                {
                    _rectTransform = (RectTransform) transform;
                }
                return _rectTransform;
            }
        }

        #region Property getters/setters

        public FlexLayoutConfig Configuration
        {
            get => _configuration;
            set
            {
                _configuration = value;
                if (value)
                {
                    LayoutNode.SetConfig(value.Config);
                }
                else
                {
                    LayoutNode.SetConfig(YGConfig.GetDefaultConfig());
                }
                RefreshRootLayout();
            }
        }
        public PositionType PositionType
        {
            get => _positionType;
            set
            {
                _positionType = value;
                LayoutNode.StyleSetPositionType(value);
                RefreshRootLayout();
            }
        }
        public YGValue PositionLeft
        {
            get => _positionLeft;
            set
            {
                _positionLeft = value;
                LayoutNode.StyleSetPosition(Edge.Left, value);
                RefreshRootLayout();
            }
        }
        public YGValue PositionTop
        {
            get => _positionTop;
            set
            {
                _positionTop = value;
                LayoutNode.StyleSetPosition(Edge.Top, value);
                RefreshRootLayout();
            }
        }
        public YGValue PositionRight
        {
            get => _positionRight;
            set
            {
                _positionRight = value;
                LayoutNode.StyleSetPosition(Edge.Right, value);
                RefreshRootLayout();
            }
        }
        public YGValue PositionBottom
        {
            get => _positionBottom;
            set
            {
                _positionBottom = value;
                LayoutNode.StyleSetPosition(Edge.Bottom, value);
                RefreshRootLayout();
            }
        }
        public Direction Direction
        {
            get => _direction;
            set
            {
                _direction = value;
                LayoutNode.StyleSetDirection(value);
                RefreshRootLayout();
            }
        }
        public FlexDirection FlexDirection
        {
            get => _flexDirection;
            set
            {
                _flexDirection = value;
                LayoutNode.StyleSetFlexDirection(value);
                RefreshRootLayout();
            }
        }
        public Wrap FlexWrap
        {
            get => _flexWrap;
            set
            {
                _flexWrap = value;
                LayoutNode.StyleSetFlexWrap(value);
                RefreshRootLayout();
            }
        }
        public YGValue FlexBasis
        {
            get => _flexBasis;
            set
            {
                _flexBasis = value;
                LayoutNode.StyleSetFlexBasis(value);
                RefreshRootLayout();
            }
        }
        public float FlexGrow
        {
            get => _flexGrow;
            set
            {
                _flexGrow = value;
                LayoutNode.StyleSetFlexGrow(value);
                RefreshRootLayout();
            }
        }
        public float FlexShrink
        {
            get => _flexShrink;
            set
            {
                _flexShrink = value;
                LayoutNode.StyleSetFlexShrink(value);
                RefreshRootLayout();
            }
        }
        public Justify JustifyContent
        {
            get => _justifyContent;
            set
            {
                _justifyContent = value;
                LayoutNode.StyleSetJustifyContent(value);
                RefreshRootLayout();
            }
        }
        public Align AlignItems
        {
            get => _alignItems;
            set
            {
                _alignItems = value;
                LayoutNode.StyleSetAlignItems(value);
                RefreshRootLayout();
            }
        }
        public Align AlignSelf
        {
            get => _alignSelf;
            set
            {
                _alignSelf = value;
                LayoutNode.StyleSetAlignSelf(value);
                RefreshRootLayout();
            }
        }
        public Align AlignContent
        {
            get => _alignContent;
            set
            {
                _alignContent = value;
                LayoutNode.StyleSetAlignContent(value);
                RefreshRootLayout();
            }
        }
        public YGValue Width
        {
            get => _width;
            set
            {
                _width = value;
                LayoutNode.StyleSetWidth(value);
                RefreshRootLayout();
            }
        }
        public YGValue Height
        {
            get => _height;
            set
            {
                _height = value;
                LayoutNode.StyleSetHeight(value);
                RefreshRootLayout();
            }
        }
        public YGValue MinWidth
        {
            get => _minWidth;
            set
            {
                _minWidth = value;
                LayoutNode.StyleSetMinWidth(value);
                RefreshRootLayout();
            }
        }
        public YGValue MinHeight
        {
            get => _minHeight;
            set
            {
                _minHeight = value;
                LayoutNode.StyleSetMinHeight(value);
                RefreshRootLayout();
            }
        }
        public YGValue MaxWidth
        {
            get => _maxWidth;
            set
            {
                _maxWidth = value;
                LayoutNode.StyleSetMaxWidth(value);
                RefreshRootLayout();
            }
        }
        public YGValue MaxHeight
        {
            get => _maxHeight;
            set
            {
                _maxHeight = value;
                LayoutNode.StyleSetMaxHeight(value);
                RefreshRootLayout();
            }
        }
        public YGValue AspectRatio
        {
            get => _aspectRatio;
            set
            {
                _aspectRatio = value;
                LayoutNode.StyleSetAspectRatio(value.Value);
                RefreshRootLayout();
            }
        }
        public YGValue MarginLeft
        {
            get => _marginLeft;
            set
            {
                _marginLeft = value;
                LayoutNode.StyleSetMargin(Edge.Left, value);
                RefreshRootLayout();
            }
        }
        public YGValue MarginTop
        {
            get => _marginTop;
            set
            {
                _marginTop = value;
                LayoutNode.StyleSetMargin(Edge.Top, value);
                RefreshRootLayout();
            }
        }
        public YGValue MarginRight
        {
            get => _marginRight;
            set
            {
                _marginRight = value;
                LayoutNode.StyleSetMargin(Edge.Right, value);
                RefreshRootLayout();
            }
        }
        public YGValue MarginBottom
        {
            get => _marginBottom;
            set
            {
                _marginBottom = value;
                LayoutNode.StyleSetMargin(Edge.Bottom, value);
                RefreshRootLayout();
            }
        }

        public YGValue PaddingLeft
        {
            get => _paddingLeft;
            set
            {
                _paddingLeft = value;
                LayoutNode.StyleSetPadding(Edge.Left, value);
                RefreshRootLayout();
            }
        }
        public YGValue PaddingTop
        {
            get => _paddingTop;
            set
            {
                _paddingTop = value;
                LayoutNode.StyleSetPadding(Edge.Top, value);
                RefreshRootLayout();
            }
        }
        public YGValue PaddingRight
        {
            get => _paddingRight;
            set
            {
                _paddingRight = value;
                LayoutNode.StyleSetPadding(Edge.Right, value);
                RefreshRootLayout();
            }
        }
        public YGValue PaddingBottom
        {
            get => _paddingBottom;
            set
            {
                _paddingBottom = value;
                LayoutNode.StyleSetPadding(Edge.Bottom, value);
                RefreshRootLayout();
            }
        }

        #endregion

        protected YGNode LayoutNode
        {
            get
            {
                if (_layoutNode.IsNull)
                {
                    _layoutNode.Instantiate();
                    UpdateNodeStyle();
                    RefreshRootLayout();
                }
                return _layoutNode;
            }
        }
        private YGNode _layoutNode;
        private FlexLayout _parentNode;
        private readonly List<FlexLayout> _childrenNodes = new List<FlexLayout>();
        private DrivenRectTransformTracker _drivenRectTransformTracker = new DrivenRectTransformTracker();
        private bool _isRefreshScheduled;
        private RectTransform _rectTransform;

        protected override void OnEnable()
        {
            base.OnEnable();
            RefreshParent();
            RefreshChildren();
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

        protected virtual void OnTransformChildrenChanged()
        {
            ClearTrackedChildren();
            RefreshChildren();
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
            // configuration
            if (_configuration)
            {
                layoutNode.SetConfig(_configuration.Config);
            }
            else
            {
                layoutNode.SetConfig(YGConfig.GetDefaultConfig());
            }
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
        }

        protected void RefreshParent()
        {
            Transform parent = RectTransform.parent;
            if (parent && parent.TryGetComponent(out FlexLayout parentNode))
            {
                if (parentNode != _parentNode)
                {
                    ClearParent();
                    parentNode.TrackChild(this);
                }
            }
            else
            {
                ClearParent();
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

        protected void RefreshChildren()
        {
            foreach (Transform child in RectTransform)
            {
                if (child.TryGetComponent(out FlexLayout childLayout))
                {
                    TrackChild(childLayout, false);
                }
            }
            RefreshDrivenRectTransformTracker();
        }

        protected void TrackChild(FlexLayout child, bool refreshDrivenRectTransformTracker = true)
        {
            child._parentNode = this;
            int binaryIndex = _childrenNodes.BinarySearch(child, this);
            if (binaryIndex < 0)
            {
                int childIndex = ~binaryIndex;
                _childrenNodes.Insert(childIndex, child);
                LayoutNode.InsertChild(child.LayoutNode, childIndex);
            }
            if (refreshDrivenRectTransformTracker)
            {
                RefreshDrivenRectTransformTracker();
            }
        }

        protected void UntrackChild(FlexLayout child, bool refreshDrivenRectTransformTracker = true)
        {
            child._parentNode = null;
            int index = _childrenNodes.BinarySearch(child, this);
            if (index >= 0)
            {
                LayoutNode.RemoveChild(_childrenNodes[index].LayoutNode);
                _childrenNodes.RemoveAt(index);
            }
            if (refreshDrivenRectTransformTracker)
            {
                RefreshDrivenRectTransformTracker();
            }
        }

        protected void RefreshDrivenRectTransformTracker()
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
            RefreshRootLayout();
        }

        protected override void Reset()
        {
            base.Reset();
            if (IsRootLayoutNode)
            {
                Width = Height = YGValue.Auto;
            }
            else
            {
                Vector2 size = RectTransform.rect.size;
                Width = size.x;
                Height = size.y;
            }
        }
#endif
    }
}
