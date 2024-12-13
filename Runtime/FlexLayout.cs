using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Threading.Tasks;
using AOT;
using Gilzoide.FlexUi.Yoga;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

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
        [SerializeField, NoAuto] private YGValue _positionLeft = YGValue.Undefined;
        [SerializeField, NoAuto] private YGValue _positionTop = YGValue.Undefined;
        [SerializeField, NoAuto] private YGValue _positionRight = YGValue.Undefined;
        [SerializeField, NoAuto] private YGValue _positionBottom = YGValue.Undefined;

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
        [SerializeField, NoAuto] private YGValue _minWidth = YGValue.Undefined;
        [SerializeField, NoAuto] private YGValue _minHeight = YGValue.Undefined;
        [SerializeField, NoAuto] private YGValue _maxWidth = YGValue.Undefined;
        [SerializeField, NoAuto] private YGValue _maxHeight = YGValue.Undefined;
        [SerializeField] private YGValue _aspectRatio = YGValue.Undefined;

        [FoldoutHeader("Margin")]
        [SerializeField] private YGValue _marginLeft = YGValue.Zero;
        [SerializeField] private YGValue _marginTop = YGValue.Zero;
        [SerializeField] private YGValue _marginRight = YGValue.Zero;
        [SerializeField] private YGValue _marginBottom = YGValue.Zero;

        [FoldoutHeader("Padding")]
        [SerializeField, NoAuto] private YGValue _paddingLeft = YGValue.Zero;
        [SerializeField, NoAuto] private YGValue _paddingTop = YGValue.Zero;
        [SerializeField, NoAuto] private YGValue _paddingRight = YGValue.Zero;
        [SerializeField, NoAuto] private YGValue _paddingBottom = YGValue.Zero;

        [FoldoutHeader("Gap")]
        [SerializeField, Min(0)] private float _gapColumn = 0;
        [SerializeField, Min(0)] private float _gapRow = 0;

#if UNITY_EDITOR || !UNITY_2021_2_OR_NEWER
        [SerializeField, HideInInspector] internal List<bool> _foldoutState = new List<bool>();
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
        public FlexLayout ParentLayoutNode => _parentNode;

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

        public float GapColumn
        {
            get => _gapColumn;
            set
            {
                _gapColumn = value;
                LayoutNode.StyleSetGap(Gutter.Column, value);
                RefreshRootLayout();
            }
        }
        public float GapRow
        {
            get => _gapRow;
            set
            {
                _gapRow = value;
                LayoutNode.StyleSetGap(Gutter.Row, value);
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
                    UpdateNodeMeasure();
                    UpdateNodeStyle();
                    RefreshRootLayout();
                }
                return _layoutNode;
            }
        }
        private YGNode _layoutNode;
        private FlexLayout _parentNode;
        internal readonly List<FlexLayout> _childrenNodes = new List<FlexLayout>();
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
            if (!IsActive())
            {
                return;
            }

            if (LayoutNode.HasMeasureFunc())
            {
                LayoutNode.SetDirty();
                RefreshRootLayout();
            }
            else if (IsRootLayoutNode && !_isRefreshScheduled)
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
                if (root && root.IsActive() && root.IsRootLayoutNode)
                {
                    root.RefreshLayout();
                }
            }
            finally
            {
                root._isRefreshScheduled = false;
            }
        }

        [ContextMenu("Refresh Layout")]
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
            // gap
            layoutNode.StyleSetGap(Gutter.Column, _gapColumn);
            layoutNode.StyleSetGap(Gutter.Row, _gapRow);
        }

        protected void UpdateNodeMeasure()
        {
            if (_layoutNode.GetChildCount() == 0 && TryGetComponent(out ILayoutElement _))
            {
                _layoutNode.SetContext(RectTransform);
                _layoutNode.SetMeasureFunc(RectTransformMeasureFuncPtr);
            }
            else
            {
                _layoutNode.SetContext(default);
                _layoutNode.SetMeasureFunc(IntPtr.Zero);
            }
        }

        protected void RefreshParent()
        {
            Transform parent = RectTransform.parent;
            if (parent && parent.TryGetComponent(out FlexLayout parentNode) && parentNode.IsActive())
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
                if (child.TryGetComponent(out FlexLayout childLayout) && childLayout.IsActive())
                {
                    TrackChild(childLayout, false);
                }
            }
            OnChildrenChanged();
        }

        protected void TrackChild(FlexLayout child, bool callChildrenChanged = true)
        {
            child._parentNode = this;
            int binaryIndex = _childrenNodes.BinarySearch(child, this);
            if (binaryIndex < 0)
            {
                int childIndex = ~binaryIndex;
                _childrenNodes.Insert(childIndex, child);
                LayoutNode.InsertChild(child.LayoutNode, childIndex);
            }
            if (callChildrenChanged)
            {
                OnChildrenChanged();
            }
        }

        protected void UntrackChild(FlexLayout child, bool callChildrenChanged = true)
        {
            child._parentNode = null;
            LayoutNode.RemoveChild(child.LayoutNode);
            _childrenNodes.Remove(child);
            if (callChildrenChanged)
            {
                OnChildrenChanged();
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

        protected void OnChildrenChanged()
        {
            RefreshDrivenRectTransformTracker();
            RefreshRootLayout();
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

        [MonoPInvokeCallback(typeof(Yoga.Yoga.YGMeasureFunc))]
        private static Vector2 RectTransformMeasureFunc(IntPtr nodePtr, float width, MeasureMode widthMode, float height, MeasureMode heightMode)
        {
            var node = new YGNode(nodePtr);
            RectTransform rectTransform = node.GetContext<RectTransform>();
            switch (widthMode)
            {
                case MeasureMode.Undefined:
                    width = LayoutUtility.GetPreferredWidth(rectTransform);
                    break;

                case MeasureMode.AtMost:
                    width = Mathf.Min(width, LayoutUtility.GetPreferredWidth(rectTransform));
                    break;

                default:
                    break;
            }
            switch (heightMode)
            {
                case MeasureMode.Undefined:
                    height = LayoutUtility.GetPreferredHeight(rectTransform);
                    break;

                case MeasureMode.AtMost:
                    height = Mathf.Min(height, LayoutUtility.GetPreferredHeight(rectTransform));
                    break;

                default:
                    break;
            }
            return new Vector2(width, height);
        }
        private static readonly IntPtr RectTransformMeasureFuncPtr = Marshal.GetFunctionPointerForDelegate<Yoga.Yoga.YGMeasureFunc>(RectTransformMeasureFunc);
    }
}
