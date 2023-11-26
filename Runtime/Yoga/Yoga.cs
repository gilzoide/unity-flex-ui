using System;
using System.Runtime.InteropServices;

namespace Gilzoide.FlexUi.Yoga
{
    public class Yoga
    {
        const string YogaDll = "flex-ui";

        #region YGConfig

        [DllImport(YogaDll)] public static extern IntPtr YGConfigNew();
        [DllImport(YogaDll)] public static extern void YGConfigFree(IntPtr config);
        [DllImport(YogaDll)] public static extern IntPtr YGConfigGetDefault();

        [DllImport(YogaDll)] public static extern void YGConfigSetUseWebDefaults(IntPtr config, bool enabled);
        [DllImport(YogaDll)] public static extern bool YGConfigGetUseWebDefaults(IntPtr config);
        [DllImport(YogaDll)] public static extern void YGConfigSetPointScaleFactor(IntPtr config, float enabled);
        [DllImport(YogaDll)] public static extern float YGConfigGetPointScaleFactor(IntPtr config);
        [DllImport(YogaDll)] public static extern void YGConfigSetErrata(IntPtr config, Errata errata);
        [DllImport(YogaDll)] public static extern Errata YGConfigGetErrata(IntPtr config);
        [DllImport(YogaDll)] public static extern void YGConfigSetExperimentalFeatureEnabled(IntPtr config, ExperimentalFeature feature, bool enabled);
        [DllImport(YogaDll)] public static extern bool YGConfigIsExperimentalFeatureEnabled(IntPtr config, ExperimentalFeature feature);

        #endregion

        #region YGNode

        [DllImport(YogaDll)] public static extern IntPtr YGNodeNew();
        [DllImport(YogaDll)] public static extern IntPtr YGNodeClone(IntPtr node);
        [DllImport(YogaDll)] public static extern void YGNodeFree(IntPtr node);
        [DllImport(YogaDll)] public static extern void YGNodeFreeRecursive(IntPtr node);
        [DllImport(YogaDll)] public static extern void YGNodeFinalize(IntPtr node);
        [DllImport(YogaDll)] public static extern void YGNodeReset(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeCalculateLayout(IntPtr node, float availableWidth, float availableHeight, Direction ownerDirection);

        [DllImport(YogaDll)] public static extern bool YGNodeGetHasNewLayout(IntPtr node);
        [DllImport(YogaDll)] public static extern void YGNodeSetHasNewLayout(IntPtr node, bool hasNewLayout);
        [DllImport(YogaDll)] public static extern bool YGNodeIsDirty(IntPtr node);
        [DllImport(YogaDll)] public static extern void YGNodeMarkDirty(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeInsertChild(IntPtr node, IntPtr child, nuint index);
        [DllImport(YogaDll)] public static extern void YGNodeSwapChild(IntPtr node, IntPtr child, nuint index);
        [DllImport(YogaDll)] public static extern void YGNodeRemoveChild(IntPtr node, IntPtr child);
        [DllImport(YogaDll)] public static extern void YGNodeRemoveAllChildren(IntPtr node);
        [DllImport(YogaDll)] public static extern IntPtr YGNodeGetChild(IntPtr node, nuint index);
        [DllImport(YogaDll)] public static extern nuint YGNodeGetChildCount(IntPtr node);
        [DllImport(YogaDll)] public static extern IntPtr YGNodeGetOwner(IntPtr node);
        [DllImport(YogaDll)] public static extern IntPtr YGNodeGetParent(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeSetConfig(IntPtr node, IntPtr config);
        [DllImport(YogaDll)] public static extern IntPtr YGNodeGetConfig(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodePrint(IntPtr node, PrintOptions options);

        #endregion

        #region YGNodeLayout

        [DllImport(YogaDll)] public static extern float YGNodeLayoutGetLeft(IntPtr node);
        [DllImport(YogaDll)] public static extern float YGNodeLayoutGetTop(IntPtr node);
        [DllImport(YogaDll)] public static extern float YGNodeLayoutGetRight(IntPtr node);
        [DllImport(YogaDll)] public static extern float YGNodeLayoutGetBottom(IntPtr node);
        [DllImport(YogaDll)] public static extern float YGNodeLayoutGetWidth(IntPtr node);
        [DllImport(YogaDll)] public static extern float YGNodeLayoutGetHeight(IntPtr node);
        [DllImport(YogaDll)] public static extern Direction YGNodeLayoutGetDirection(IntPtr node);
        [DllImport(YogaDll)] public static extern float YGNodeLayoutGetMargin(IntPtr node, Edge edge);
        [DllImport(YogaDll)] public static extern float YGNodeLayoutGetBorder(IntPtr node, Edge edge);
        [DllImport(YogaDll)] public static extern float YGNodeLayoutGetPadding(IntPtr node, Edge edge);

        #endregion

        #region YGNodeStyle

        [DllImport(YogaDll)] public static extern void YGNodeCopyStyle(IntPtr dstNode, IntPtr srcNode);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetDirection(IntPtr node, Direction direction);
        [DllImport(YogaDll)] public static extern Direction YGNodeStyleGetDirection(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetFlexDirection(IntPtr node, FlexDirection flexDirection);
        [DllImport(YogaDll)] public static extern FlexDirection YGNodeStyleGetFlexDirection(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetJustifyContent(IntPtr node, Justify justifyContent);
        [DllImport(YogaDll)] public static extern Justify YGNodeStyleGetJustifyContent(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetAlignContent(IntPtr node, Align alignContent);
        [DllImport(YogaDll)] public static extern Align YGNodeStyleGetAlignContent(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetAlignItems(IntPtr node, Align alignItems);
        [DllImport(YogaDll)] public static extern Align YGNodeStyleGetAlignItems(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetAlignSelf(IntPtr node, Align alignSelf);
        [DllImport(YogaDll)] public static extern Align YGNodeStyleGetAlignSelf(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetPositionType(IntPtr node, PositionType positionType);
        [DllImport(YogaDll)] public static extern PositionType YGNodeStyleGetPositionType(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetFlexWrap(IntPtr node, Wrap flexWrap);
        [DllImport(YogaDll)] public static extern Wrap YGNodeStyleGetFlexWrap(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetOverflow(IntPtr node, Overflow overflow);
        [DllImport(YogaDll)] public static extern Overflow YGNodeStyleGetOverflow(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetDisplay(IntPtr node, Display display);
        [DllImport(YogaDll)] public static extern Display YGNodeStyleGetDisplay(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetFlex(IntPtr node, float flex);
        [DllImport(YogaDll)] public static extern float YGNodeStyleGetFlex(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetFlexGrow(IntPtr node, float flexGrow);
        [DllImport(YogaDll)] public static extern float YGNodeStyleGetFlexGrow(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetFlexShrink(IntPtr node, float flexShrink);
        [DllImport(YogaDll)] public static extern float YGNodeStyleGetFlexShrink(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetFlexBasis(IntPtr node, float flexBasis);
        [DllImport(YogaDll)] public static extern void YGNodeStyleSetFlexBasisPercent(IntPtr node, float flexBasis);
        [DllImport(YogaDll)] public static extern void YGNodeStyleSetFlexBasisAuto(IntPtr node);
        [DllImport(YogaDll)] public static extern YGValue YGNodeStyleGetFlexBasis(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetPosition(IntPtr node, Edge edge, float position);
        [DllImport(YogaDll)] public static extern void YGNodeStyleSetPositionPercent(IntPtr node, Edge edge, float position);
        [DllImport(YogaDll)] public static extern YGValue YGNodeStyleGetPosition(IntPtr node, Edge edge);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetMargin(IntPtr node, Edge edge, float margin);
        [DllImport(YogaDll)] public static extern void YGNodeStyleSetMarginPercent(IntPtr node, Edge edge, float margin);
        [DllImport(YogaDll)] public static extern void YGNodeStyleSetMarginAuto(IntPtr node, Edge edge);
        [DllImport(YogaDll)] public static extern YGValue YGNodeStyleGetMargin(IntPtr node, Edge edge);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetPadding(IntPtr node, Edge edge, float padding);
        [DllImport(YogaDll)] public static extern void YGNodeStyleSetPaddingPercent(IntPtr node, Edge edge, float padding);
        [DllImport(YogaDll)] public static extern YGValue YGNodeStyleGetPadding(IntPtr node, Edge edge);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetBorder(IntPtr node, Edge edge, float border);
        [DllImport(YogaDll)] public static extern float YGNodeStyleGetBorder(IntPtr node, Edge edge);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetWidth(IntPtr node, float width);
        [DllImport(YogaDll)] public static extern void YGNodeStyleSetWidthPercent(IntPtr node, float width);
        [DllImport(YogaDll)] public static extern void YGNodeStyleSetWidthAuto(IntPtr node);
        [DllImport(YogaDll)] public static extern YGValue YGNodeStyleGetWidth(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetHeight(IntPtr node, float height);
        [DllImport(YogaDll)] public static extern void YGNodeStyleSetHeightPercent(IntPtr node, float height);
        [DllImport(YogaDll)] public static extern void YGNodeStyleSetHeightAuto(IntPtr node);
        [DllImport(YogaDll)] public static extern YGValue YGNodeStyleGetHeight(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetMinWidth(IntPtr node, float minWidth);
        [DllImport(YogaDll)] public static extern void YGNodeStyleSetMinWidthPercent(IntPtr node, float minWidth);
        [DllImport(YogaDll)] public static extern YGValue YGNodeStyleGetMinWidth(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetMinHeight(IntPtr node, float minHeight);
        [DllImport(YogaDll)] public static extern void YGNodeStyleSetMinHeightPercent(IntPtr node, float minHeight);
        [DllImport(YogaDll)] public static extern YGValue YGNodeStyleGetMinHeight(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetMaxWidth(IntPtr node, float maxWidth);
        [DllImport(YogaDll)] public static extern void YGNodeStyleSetMaxWidthPercent(IntPtr node, float maxWidth);
        [DllImport(YogaDll)] public static extern YGValue YGNodeStyleGetMaxWidth(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetMaxHeight(IntPtr node, float maxHeight);
        [DllImport(YogaDll)] public static extern void YGNodeStyleSetMaxHeightPercent(IntPtr node, float maxHeight);
        [DllImport(YogaDll)] public static extern YGValue YGNodeStyleGetMaxHeight(IntPtr node);

        [DllImport(YogaDll)] public static extern void YGNodeStyleSetAspectRatio(IntPtr node, float aspectRatio);
        [DllImport(YogaDll)] public static extern float YGNodeStyleGetAspectRatio(IntPtr node);

        #endregion
    }
}
