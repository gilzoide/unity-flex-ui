using System;
using UnityEngine;

namespace Gilzoide.FlexUi.Yoga
{
    public struct YGNode : IDisposable, IEquatable<YGNode>
    {
        private IntPtr _nodePtr;

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

        public bool IsNull => _nodePtr == IntPtr.Zero;

        public void StyleSetWidth(YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Point:
                    StyleSetWidth(value.Value);
                    break;

                case Unit.Percent:
                    StyleSetWidthPercent(value.Value);
                    break;

                case Unit.Auto:
                    StyleSetWidthAuto();
                    break;

                case Unit.Undefined:
                default:
                    break;
            }
        }

        public void StyleSetHeight(YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Point:
                    StyleSetHeight(value.Value);
                    break;

                case Unit.Percent:
                    StyleSetHeightPercent(value.Value);
                    break;

                case Unit.Auto:
                    StyleSetHeightAuto();
                    break;

                case Unit.Undefined:
                default:
                    break;
            }
        }

        public void StyleSetMinWidth(YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Point:
                    StyleSetMinWidth(value.Value);
                    break;

                case Unit.Percent:
                    StyleSetMinWidthPercent(value.Value);
                    break;

                case Unit.Auto:
                    throw new ArgumentOutOfRangeException(nameof(value), "Auto unit is not supported");

                case Unit.Undefined:
                default:
                    break;
            }
        }

        public void StyleSetMaxWidth(YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Point:
                    StyleSetMaxWidth(value.Value);
                    break;

                case Unit.Percent:
                    StyleSetMaxWidthPercent(value.Value);
                    break;

                case Unit.Auto:
                    throw new ArgumentOutOfRangeException(nameof(value), "Auto unit is not supported");

                case Unit.Undefined:
                default:
                    break;
            }
        }

        public void StyleSetMinHeight(YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Point:
                    StyleSetMinHeight(value.Value);
                    break;

                case Unit.Percent:
                    StyleSetMinHeightPercent(value.Value);
                    break;

                case Unit.Auto:
                    throw new ArgumentOutOfRangeException(nameof(value), "Auto unit is not supported");

                case Unit.Undefined:
                default:
                    break;
            }
        }

        public void StyleSetMaxHeight(YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Point:
                    StyleSetMaxHeight(value.Value);
                    break;

                case Unit.Percent:
                    StyleSetMaxHeightPercent(value.Value);
                    break;

                case Unit.Auto:
                    throw new ArgumentOutOfRangeException(nameof(value), "Auto unit is not supported");

                case Unit.Undefined:
                default:
                    break;
            }
        }

        public void StyleSetFlexBasis(YGValue value)
        {
            switch (value.Unit)
            {
                case Unit.Point:
                    StyleSetFlexBasis(value.Value);
                    break;

                case Unit.Percent:
                    StyleSetFlexBasisPercent(value.Value);
                    break;

                case Unit.Auto:
                    StyleSetFlexBasisAuto();
                    break;

                case Unit.Undefined:
                default:
                    break;
            }
        }

        #region YGNode

        public YGNode Clone()
        {
            return new YGNode
            {
                _nodePtr = Yoga.YGNodeClone(_nodePtr),
            };
        }

        public void Free()
        {
            Yoga.YGNodeFree(_nodePtr);
        }
        public void FreeRecursive()
        {
            Yoga.YGNodeFreeRecursive(_nodePtr);
        }
        public void Finalize_()
        {
            Yoga.YGNodeFinalize(_nodePtr);
        }

        public void Reset()
        {
            Yoga.YGNodeReset(_nodePtr);
        }

        public void CalculateLayout(float availableWidth, float availableHeight, Direction ownerDirection)
        {
            Yoga.YGNodeCalculateLayout(_nodePtr, availableWidth, availableHeight, ownerDirection);
        }

        public bool GetHasNewLayout()
        {
            return Yoga.YGNodeGetHasNewLayout(_nodePtr);
        }
        public void SetHasNewLayout(bool hasNewLayout)
        {
            Yoga.YGNodeSetHasNewLayout(_nodePtr, hasNewLayout);
        }

        public bool IsDirty()
        {
            return Yoga.YGNodeIsDirty(_nodePtr);
        }
        public void MarkDirty()
        {
            Yoga.YGNodeMarkDirty(_nodePtr);
        }

        public void InsertChild(YGNode child, int index)
        {
            Yoga.YGNodeInsertChild(_nodePtr, child._nodePtr, (nuint) index);
        }
        public void SwapChild(YGNode child, int index)
        {
            Yoga.YGNodeSwapChild(_nodePtr, child._nodePtr, (nuint) index);
        }
        public void RemoveChild(YGNode child)
        {
            Yoga.YGNodeRemoveChild(_nodePtr, child._nodePtr);
        }
        public void RemoveAllChildren()
        {
            Yoga.YGNodeRemoveAllChildren(_nodePtr);
        }
        public YGNode GetChild(int index)
        {
            return new YGNode
            {
                _nodePtr = Yoga.YGNodeGetChild(_nodePtr, (nuint) index),
            };
        }
        public int GetChildCount()
        {
            return (int) Yoga.YGNodeGetChildCount(_nodePtr);
        }
        public YGNode GetOwner()
        {
            return new YGNode
            {
                _nodePtr = Yoga.YGNodeGetOwner(_nodePtr),
            };
        }
        public YGNode GetParent()
        {
            return new YGNode
            {
                _nodePtr = Yoga.YGNodeGetParent(_nodePtr),
            };
        }

        public void Print(PrintOptions options)
        {
            Yoga.YGNodePrint(_nodePtr, options);
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
        public float LayoutGetRight()
        {
            return Yoga.YGNodeLayoutGetRight(_nodePtr);
        }
        public float LayoutGetBottom()
        {
            return Yoga.YGNodeLayoutGetBottom(_nodePtr);
        }
        public float LayoutGetWidth()
        {
            return Yoga.YGNodeLayoutGetWidth(_nodePtr);
        }
        public float LayoutGetHeight()
        {
            return Yoga.YGNodeLayoutGetHeight(_nodePtr);
        }
        public Direction LayoutGetDirection()
        {
            return Yoga.YGNodeLayoutGetDirection(_nodePtr);
        }
        public float LayoutGetMargin(Edge edge)
        {
            return Yoga.YGNodeLayoutGetMargin(_nodePtr, edge);
        }
        public float LayoutGetBorder(Edge edge)
        {
            return Yoga.YGNodeLayoutGetBorder(_nodePtr, edge);
        }
        public float LayoutGetPadding(Edge edge)
        {
            return Yoga.YGNodeLayoutGetPadding(_nodePtr, edge);
        }

        #endregion

        #region Style

        public void CopyStyle(YGNode srcNode)
        {
            Yoga.YGNodeCopyStyle(_nodePtr, srcNode._nodePtr);
        }

        public void StyleSetDirection(Direction direction)
        {
            Yoga.YGNodeStyleSetDirection(_nodePtr, direction);
        }
        public Direction StyleGetDirection()
        {
            return Yoga.YGNodeStyleGetDirection(_nodePtr);
        }

        public void StyleSetFlexDirection(FlexDirection flexDirection)
        {
            Yoga.YGNodeStyleSetFlexDirection(_nodePtr, flexDirection);
        }
        public FlexDirection StyleGetFlexDirection()
        {
            return Yoga.YGNodeStyleGetFlexDirection(_nodePtr);
        }

        public void StyleSetJustifyContent(Justify justifyContent)
        {
            Yoga.YGNodeStyleSetJustifyContent(_nodePtr, justifyContent);
        }
        public Justify StyleGetJustifyContent()
        {
            return Yoga.YGNodeStyleGetJustifyContent(_nodePtr);
        }

        public void StyleSetAlignContent(Align alignContent)
        {
            Yoga.YGNodeStyleSetAlignContent(_nodePtr, alignContent);
        }
        public Align StyleGetAlignContent()
        {
            return Yoga.YGNodeStyleGetAlignContent(_nodePtr);
        }

        public void StyleSetAlignItems(Align alignItems)
        {
            Yoga.YGNodeStyleSetAlignItems(_nodePtr, alignItems);
        }
        public Align StyleGetAlignItems()
        {
            return Yoga.YGNodeStyleGetAlignItems(_nodePtr);
        }

        public void StyleSetAlignSelf(Align alignSelf)
        {
            Yoga.YGNodeStyleSetAlignSelf(_nodePtr, alignSelf);
        }
        public Align StyleGetAlignSelf()
        {
            return Yoga.YGNodeStyleGetAlignSelf(_nodePtr);
        }

        public void StyleSetPositionType(PositionType positionType)
        {
            Yoga.YGNodeStyleSetPositionType(_nodePtr, positionType);
        }
        public PositionType StyleGetPositionType()
        {
            return Yoga.YGNodeStyleGetPositionType(_nodePtr);
        }

        public void StyleSetFlexWrap(Wrap flexWrap)
        {
            Yoga.YGNodeStyleSetFlexWrap(_nodePtr, flexWrap);
        }
        public Wrap StyleGetFlexWrap()
        {
            return Yoga.YGNodeStyleGetFlexWrap(_nodePtr);
        }

        public void StyleSetOverflow(Overflow overflow)
        {
            Yoga.YGNodeStyleSetOverflow(_nodePtr, overflow);
        }
        public Overflow StyleGetOverflow()
        {
            return Yoga.YGNodeStyleGetOverflow(_nodePtr);
        }

        public void StyleSetDisplay(Display display)
        {
            Yoga.YGNodeStyleSetDisplay(_nodePtr, display);
        }
        public Display StyleGetDisplay()
        {
            return Yoga.YGNodeStyleGetDisplay(_nodePtr);
        }

        public void StyleSetFlex(float flex)
        {
            Yoga.YGNodeStyleSetFlex(_nodePtr, flex);
        }
        public float StyleGetFlex()
        {
            return Yoga.YGNodeStyleGetFlex(_nodePtr);
        }

        public void StyleSetFlexGrow(float flexGrow)
        {
            Yoga.YGNodeStyleSetFlexGrow(_nodePtr, flexGrow);
        }
        public float StyleGetFlexGrow()
        {
            return Yoga.YGNodeStyleGetFlexGrow(_nodePtr);
        }

        public void StyleSetFlexShrink(float flexShrink)
        {
            Yoga.YGNodeStyleSetFlexShrink(_nodePtr, flexShrink);
        }
        public float StyleGetFlexShrink()
        {
            return Yoga.YGNodeStyleGetFlexShrink(_nodePtr);
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
        public YGValue StyleGetFlexBasis()
        {
            return Yoga.YGNodeStyleGetFlexBasis(_nodePtr);
        }

        public void StyleSetPosition(Edge edge, float position)
        {
            Yoga.YGNodeStyleSetPosition(_nodePtr, edge, position);
        }
        public void StyleSetPositionPercent(Edge edge, float position)
        {
            Yoga.YGNodeStyleSetPositionPercent(_nodePtr, edge, position);
        }
        public YGValue StyleGetPosition(Edge edge)
        {
            return Yoga.YGNodeStyleGetPosition(_nodePtr, edge);
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
        public YGValue StyleGetMargin(Edge edge)
        {
            return Yoga.YGNodeStyleGetMargin(_nodePtr, edge);
        }

        public void StyleSetPadding(Edge edge, float padding)
        {
            Yoga.YGNodeStyleSetPadding(_nodePtr, edge, padding);
        }
        public void StyleSetPaddingPercent(Edge edge, float padding)
        {
            Yoga.YGNodeStyleSetPaddingPercent(_nodePtr, edge, padding);
        }
        public YGValue StyleGetPadding(Edge edge)
        {
            return Yoga.YGNodeStyleGetPadding(_nodePtr, edge);
        }

        public void StyleSetBorder(Edge edge, float border)
        {
            Yoga.YGNodeStyleSetBorder(_nodePtr, edge, border);
        }
        public float StyleGetBorder(Edge edge)
        {
            return Yoga.YGNodeStyleGetBorder(_nodePtr, edge);
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
        public YGValue StyleGetWidth()
        {
            return Yoga.YGNodeStyleGetWidth(_nodePtr);
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
        public YGValue StyleGetHeight()
        {
            return Yoga.YGNodeStyleGetHeight(_nodePtr);
        }

        public void StyleSetMinWidth(float minWidth)
        {
            Yoga.YGNodeStyleSetMinWidth(_nodePtr, minWidth);
        }
        public void StyleSetMinWidthPercent(float minWidth)
        {
            Yoga.YGNodeStyleSetMinWidthPercent(_nodePtr, minWidth);
        }
        public YGValue StyleGetMinWidth()
        {
            return Yoga.YGNodeStyleGetMinWidth(_nodePtr);
        }

        public void StyleSetMinHeight(float minHeight)
        {
            Yoga.YGNodeStyleSetMinHeight(_nodePtr, minHeight);
        }
        public void StyleSetMinHeightPercent(float minHeight)
        {
            Yoga.YGNodeStyleSetMinHeightPercent(_nodePtr, minHeight);
        }
        public YGValue StyleGetMinHeight()
        {
            return Yoga.YGNodeStyleGetMinHeight(_nodePtr);
        }

        public void StyleSetMaxWidth(float maxWidth)
        {
            Yoga.YGNodeStyleSetMaxWidth(_nodePtr, maxWidth);
        }
        public void StyleSetMaxWidthPercent(float maxWidth)
        {
            Yoga.YGNodeStyleSetMaxWidthPercent(_nodePtr, maxWidth);
        }
        public YGValue StyleGetMaxWidth()
        {
            return Yoga.YGNodeStyleGetMaxWidth(_nodePtr);
        }

        public void StyleSetMaxHeight(float maxHeight)
        {
            Yoga.YGNodeStyleSetMaxHeight(_nodePtr, maxHeight);
        }
        public void StyleSetMaxHeightPercent(float maxHeight)
        {
            Yoga.YGNodeStyleSetMaxHeightPercent(_nodePtr, maxHeight);
        }
        public YGValue StyleGetMaxHeight()
        {
            return Yoga.YGNodeStyleGetMaxHeight(_nodePtr);
        }

        public void StyleSetAspectRatio(float aspectRatio)
        {
            Yoga.YGNodeStyleSetAspectRatio(_nodePtr, aspectRatio);
        }
        public float StyleGetAspectRatio()
        {
            return Yoga.YGNodeStyleGetAspectRatio(_nodePtr);
        }

        #endregion
    }
}
