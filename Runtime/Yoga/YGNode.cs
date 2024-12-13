using System;
using System.Runtime.InteropServices;
using UnityEngine;

namespace Gilzoide.FlexUi.Yoga
{
    public struct YGNode : IDisposable, IEquatable<YGNode>
    {
        internal IntPtr _nodePtr;

        public bool IsNull => _nodePtr == IntPtr.Zero;

        internal YGNode(IntPtr nodePtr)
        {
            _nodePtr = nodePtr;
        }

        public void Instantiate()
        {
            _nodePtr = Yoga.YGNodeNew();
        }

        public void Dispose()
        {
            if (!IsNull)
            {
                Free();
                _nodePtr = IntPtr.Zero;
            }
        }

        public void ApplyTo(RectTransform rectTransform)
        {
            rectTransform.SetInsetAndSizeFromParentEdge(RectTransform.Edge.Top, LayoutGetTop(), LayoutGetHeight());
            rectTransform.SetInsetAndSizeFromParentEdge(RectTransform.Edge.Left, LayoutGetLeft(), LayoutGetWidth());
        }

        public bool Equals(YGNode other)
        {
            return _nodePtr == other._nodePtr;
        }


        public void StyleSetPosition(Edge edge, YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Undefined:
                    StyleSetPosition(edge, float.NaN);
                    break;

                case Unit.Point:
                    StyleSetPosition(edge, value.Value);
                    break;

                case Unit.Percent:
                    StyleSetPositionPercent(edge, value.Value);
                    break;

                case Unit.Auto:
                    throw new ArgumentOutOfRangeException(nameof(value), "Auto is not supported for position");
            }
        }

        public void StyleSetWidth(YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Undefined:
                    StyleSetWidth(float.NaN);
                    break;

                case Unit.Point:
                    StyleSetWidth(value.Value);
                    break;

                case Unit.Percent:
                    StyleSetWidthPercent(value.Value);
                    break;

                case Unit.Auto:
                    StyleSetWidthAuto();
                    break;
            }
        }

        public void StyleSetHeight(YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Undefined:
                    StyleSetHeight(float.NaN);
                    break;

                case Unit.Point:
                    StyleSetHeight(value.Value);
                    break;

                case Unit.Percent:
                    StyleSetHeightPercent(value.Value);
                    break;

                case Unit.Auto:
                    StyleSetHeightAuto();
                    break;
            }
        }

        public void StyleSetMinWidth(YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Undefined:
                    StyleSetMinWidth(float.NaN);
                    break;

                case Unit.Point:
                    StyleSetMinWidth(value.Value);
                    break;

                case Unit.Percent:
                    StyleSetMinWidthPercent(value.Value);
                    break;

                case Unit.Auto:
                    throw new ArgumentOutOfRangeException(nameof(value), "Auto is not supported for min width");
            }
        }

        public void StyleSetMaxWidth(YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Undefined:
                    StyleSetMaxWidth(float.NaN);
                    break;

                case Unit.Point:
                    StyleSetMaxWidth(value.Value);
                    break;

                case Unit.Percent:
                    StyleSetMaxWidthPercent(value.Value);
                    break;

                case Unit.Auto:
                    throw new ArgumentOutOfRangeException(nameof(value), "Auto is not supported for max width");
            }
        }

        public void StyleSetMinHeight(YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Undefined:
                    StyleSetMinHeight(float.NaN);
                    break;

                case Unit.Point:
                    StyleSetMinHeight(value.Value);
                    break;

                case Unit.Percent:
                    StyleSetMinHeightPercent(value.Value);
                    break;

                case Unit.Auto:
                    throw new ArgumentOutOfRangeException(nameof(value), "Auto is not supported for min height");
            }
        }

        public void StyleSetMaxHeight(YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Undefined:
                    StyleSetMaxHeight(float.NaN);
                    break;

                case Unit.Point:
                    StyleSetMaxHeight(value.Value);
                    break;

                case Unit.Percent:
                    StyleSetMaxHeightPercent(value.Value);
                    break;

                case Unit.Auto:
                    throw new ArgumentOutOfRangeException(nameof(value), "Auto is not supported for max height");
            }
        }

        public void StyleSetFlexBasis(YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Undefined:
                    StyleSetFlexBasis(float.NaN);
                    break;

                case Unit.Point:
                    StyleSetFlexBasis(value.Value);
                    break;

                case Unit.Percent:
                    StyleSetFlexBasisPercent(value.Value);
                    break;

                case Unit.Auto:
                    StyleSetFlexBasisAuto();
                    break;
            }
        }

        public void StyleSetMargin(Edge edge, YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Undefined:
                    StyleSetMargin(edge, float.NaN);
                    break;

                case Unit.Point:
                    StyleSetMargin(edge, value.Value);
                    break;

                case Unit.Percent:
                    StyleSetMarginPercent(edge, value.Value);
                    break;

                case Unit.Auto:
                    StyleSetMarginAuto(edge);
                    break;
            }
        }

        public void StyleSetPadding(Edge edge, YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Undefined:
                    StyleSetPadding(edge, float.NaN);
                    break;

                case Unit.Point:
                    StyleSetPadding(edge, value.Value);
                    break;

                case Unit.Percent:
                    StyleSetPaddingPercent(edge, value.Value);
                    break;

                case Unit.Auto:
                    throw new ArgumentOutOfRangeException(nameof(value), "Auto is not supported for padding");
            }
        }

        #region YGNode

        public void Free()
        {
            GCHandle ctx = GetContext();
            if (ctx.IsAllocated)
            {
                ctx.Free();
            }
            Yoga.YGNodeFree(_nodePtr);
        }

        public void CalculateLayout(float availableWidth, float availableHeight, Direction ownerDirection)
        {
            Yoga.YGNodeCalculateLayout(_nodePtr, availableWidth, availableHeight, ownerDirection);
        }

        public bool InsertChild(YGNode child, int index)
        {
            // Nodes with children cannot have measure functions
            SetContext(default);
            SetMeasureFunc(IntPtr.Zero);

            string error = Yoga.YGNodeInsertChild(_nodePtr, child._nodePtr, index);
            if (error != null)
            {
                Debug.LogError(error);
                return false;
            }
            else
            {
                return true;
            }
        }
        public void RemoveChild(YGNode child)
        {
            Yoga.YGNodeRemoveChild(_nodePtr, child._nodePtr);
        }
        public void RemoveAllChildren()
        {
            Yoga.YGNodeRemoveAllChildren(_nodePtr);
        }

        public int GetChildCount()
        {
            return Yoga.YGNodeGetChildCount(_nodePtr);
        }

        public void SetConfig(YGConfig config)
        {
            string error = Yoga.YGNodeSetConfig(_nodePtr, config._configPtr);
            if (error != null)
            {
                Debug.LogError(error);
            }
        }

        public void SetContext<T>(T value)
        {
            SetContext(GCHandle.Alloc(value));
        }

        public void SetContext(GCHandle value)
        {
            GCHandle ctx = GetContext();
            if (ctx.IsAllocated)
            {
                ctx.Free();
            }
            Yoga.YGNodeSetContext(_nodePtr, GCHandle.ToIntPtr(value));
        }

        public T GetContext<T>()
        {
            GCHandle handle = GetContext();
            return handle.IsAllocated ? (T) handle.Target : default;
        }

        public GCHandle GetContext()
        {
            IntPtr ptr = Yoga.YGNodeGetContext(_nodePtr);
            return ptr != IntPtr.Zero ? GCHandle.FromIntPtr(ptr) : default;
        }

        public void SetMeasureFunc(Yoga.YGMeasureFunc measureFunc)
        {
            Yoga.YGNodeSetMeasureFunc(_nodePtr, measureFunc);
        }

        public void SetMeasureFunc(IntPtr measureFunc)
        {
            Yoga.YGNodeSetMeasureFunc(_nodePtr, measureFunc);
        }

        public bool HasMeasureFunc()
        {
            return Yoga.YGNodeHasMeasureFunc(_nodePtr);
        }

        public void SetDirty()
        {
            if (HasMeasureFunc())
            {
                Yoga.YGNodeSetDirty(_nodePtr);
            }
        }

        #endregion

        #region Layout

        public float LayoutGetLeft()
        {
            return Yoga.YGNodeLayoutGetLeft(_nodePtr);
        }
        public float LayoutGetTop()
        {
            return Yoga.YGNodeLayoutGetTop(_nodePtr);
        }
        public float LayoutGetWidth()
        {
            return Yoga.YGNodeLayoutGetWidth(_nodePtr);
        }
        public float LayoutGetHeight()
        {
            return Yoga.YGNodeLayoutGetHeight(_nodePtr);
        }

        #endregion

        #region Style

        public void StyleSetDirection(Direction direction)
        {
            Yoga.YGNodeStyleSetDirection(_nodePtr, direction);
        }
        public void StyleSetFlexDirection(FlexDirection flexDirection)
        {
            Yoga.YGNodeStyleSetFlexDirection(_nodePtr, flexDirection);
        }
        public void StyleSetJustifyContent(Justify justifyContent)
        {
            Yoga.YGNodeStyleSetJustifyContent(_nodePtr, justifyContent);
        }
        public void StyleSetAlignContent(Align alignContent)
        {
            Yoga.YGNodeStyleSetAlignContent(_nodePtr, alignContent);
        }
        public void StyleSetAlignItems(Align alignItems)
        {
            Yoga.YGNodeStyleSetAlignItems(_nodePtr, alignItems);
        }
        public void StyleSetAlignSelf(Align alignSelf)
        {
            Yoga.YGNodeStyleSetAlignSelf(_nodePtr, alignSelf);
        }
        public void StyleSetPositionType(PositionType positionType)
        {
            Yoga.YGNodeStyleSetPositionType(_nodePtr, positionType);
        }

        public void StyleSetFlexWrap(Wrap flexWrap)
        {
            Yoga.YGNodeStyleSetFlexWrap(_nodePtr, flexWrap);
        }
        public void StyleSetFlexGrow(float flexGrow)
        {
            Yoga.YGNodeStyleSetFlexGrow(_nodePtr, flexGrow);
        }
        public void StyleSetFlexShrink(float flexShrink)
        {
            Yoga.YGNodeStyleSetFlexShrink(_nodePtr, flexShrink);
        }
        public void StyleSetFlexBasis(float flexBasis)
        {
            Yoga.YGNodeStyleSetFlexBasis(_nodePtr, flexBasis);
        }
        public void StyleSetFlexBasisPercent(float flexBasis)
        {
            Yoga.YGNodeStyleSetFlexBasisPercent(_nodePtr, flexBasis);
        }
        public void StyleSetFlexBasisAuto()
        {
            Yoga.YGNodeStyleSetFlexBasisAuto(_nodePtr);
        }

        public void StyleSetPosition(Edge edge, float position)
        {
            Yoga.YGNodeStyleSetPosition(_nodePtr, edge, position);
        }
        public void StyleSetPositionPercent(Edge edge, float position)
        {
            Yoga.YGNodeStyleSetPositionPercent(_nodePtr, edge, position);
        }

        public void StyleSetMargin(Edge edge, float margin)
        {
            Yoga.YGNodeStyleSetMargin(_nodePtr, edge, margin);
        }
        public void StyleSetMarginPercent(Edge edge, float margin)
        {
            Yoga.YGNodeStyleSetMarginPercent(_nodePtr, edge, margin);
        }
        public void StyleSetMarginAuto(Edge edge)
        {
            Yoga.YGNodeStyleSetMarginAuto(_nodePtr, edge);
        }

        public void StyleSetPadding(Edge edge, float padding)
        {
            Yoga.YGNodeStyleSetPadding(_nodePtr, edge, padding);
        }
        public void StyleSetPaddingPercent(Edge edge, float padding)
        {
            Yoga.YGNodeStyleSetPaddingPercent(_nodePtr, edge, padding);
        }

        public void StyleSetGap(Gutter gutter, float value)
        {
            Yoga.YGNodeStyleSetGap(_nodePtr, gutter, value);
        }

        public void StyleSetWidth(float width)
        {
            Yoga.YGNodeStyleSetWidth(_nodePtr, width);
        }
        public void StyleSetWidthPercent(float width)
        {
            Yoga.YGNodeStyleSetWidthPercent(_nodePtr, width);
        }
        public void StyleSetWidthAuto()
        {
            Yoga.YGNodeStyleSetWidthAuto(_nodePtr);
        }

        public void StyleSetHeight(float height)
        {
            Yoga.YGNodeStyleSetHeight(_nodePtr, height);
        }
        public void StyleSetHeightPercent(float height)
        {
            Yoga.YGNodeStyleSetHeightPercent(_nodePtr, height);
        }
        public void StyleSetHeightAuto()
        {
            Yoga.YGNodeStyleSetHeightAuto(_nodePtr);
        }

        public void StyleSetMinWidth(float minWidth)
        {
            Yoga.YGNodeStyleSetMinWidth(_nodePtr, minWidth);
        }
        public void StyleSetMinWidthPercent(float minWidth)
        {
            Yoga.YGNodeStyleSetMinWidthPercent(_nodePtr, minWidth);
        }

        public void StyleSetMinHeight(float minHeight)
        {
            Yoga.YGNodeStyleSetMinHeight(_nodePtr, minHeight);
        }
        public void StyleSetMinHeightPercent(float minHeight)
        {
            Yoga.YGNodeStyleSetMinHeightPercent(_nodePtr, minHeight);
        }

        public void StyleSetMaxWidth(float maxWidth)
        {
            Yoga.YGNodeStyleSetMaxWidth(_nodePtr, maxWidth);
        }
        public void StyleSetMaxWidthPercent(float maxWidth)
        {
            Yoga.YGNodeStyleSetMaxWidthPercent(_nodePtr, maxWidth);
        }

        public void StyleSetMaxHeight(float maxHeight)
        {
            Yoga.YGNodeStyleSetMaxHeight(_nodePtr, maxHeight);
        }
        public void StyleSetMaxHeightPercent(float maxHeight)
        {
            Yoga.YGNodeStyleSetMaxHeightPercent(_nodePtr, maxHeight);
        }

        public void StyleSetAspectRatio(float aspectRatio)
        {
            Yoga.YGNodeStyleSetAspectRatio(_nodePtr, aspectRatio);
        }

        #endregion
    }
}
