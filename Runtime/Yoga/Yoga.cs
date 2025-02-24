using System;
using System.Runtime.InteropServices;
using UnityEngine;

namespace Gilzoide.FlexUi.Yoga
{
    public class Yoga
    {
#if !UNITY_EDITOR && (UNITY_IOS || UNITY_TVOS || UNITY_VISIONOS || UNITY_WEBGL)
        const string YogaDll = "__Internal";
#else
        const string YogaDll = "flex-ui";
#endif

        #region YGConfig

        [DllImport(YogaDll, EntryPoint = "FlexUi_ConfigNew")] public static extern IntPtr YGConfigNew();
        [DllImport(YogaDll, EntryPoint = "FlexUi_ConfigFree")] public static extern void YGConfigFree(IntPtr config);
        [DllImport(YogaDll, EntryPoint = "FlexUi_ConfigGetDefault")] public static extern IntPtr YGConfigGetDefault();

        [DllImport(YogaDll, EntryPoint = "FlexUi_ConfigSetPointScaleFactor")] public static extern void YGConfigSetPointScaleFactor(IntPtr config, float enabled);
        [DllImport(YogaDll, EntryPoint = "FlexUi_ConfigSetErrata")] public static extern void YGConfigSetErrata(IntPtr config, Errata errata);
        [DllImport(YogaDll, EntryPoint = "FlexUi_ConfigSetExperimentalFeatureEnabled")] public static extern void YGConfigSetExperimentalFeatureEnabled(IntPtr config, ExperimentalFeature feature, [MarshalAs(UnmanagedType.U1)] bool enabled);

        #endregion

        #region YGNode

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeNew")] public static extern IntPtr YGNodeNew();
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeFree")] public static extern void YGNodeFree(IntPtr node);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeCalculateLayout")] public static extern void YGNodeCalculateLayout(IntPtr node, float availableWidth, float availableHeight, Direction ownerDirection);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeInsertChild")] public static extern string YGNodeInsertChild(IntPtr node, IntPtr child, int index);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeRemoveChild")] public static extern void YGNodeRemoveChild(IntPtr node, IntPtr child);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeRemoveAllChildren")] public static extern void YGNodeRemoveAllChildren(IntPtr node);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeGetChildCount")] public static extern int YGNodeGetChildCount(IntPtr node);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeSetConfig")] public static extern string YGNodeSetConfig(IntPtr node, IntPtr config);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeSetContext")] public static extern void YGNodeSetContext(IntPtr node, IntPtr context);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeGetContext")] public static extern IntPtr YGNodeGetContext(IntPtr node);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeSetMeasureFunc")] public static extern void YGNodeSetMeasureFunc(IntPtr node, IntPtr measureFunc);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeHasMeasureFunc")] [return: MarshalAs(UnmanagedType.U1)] public static extern bool YGNodeHasMeasureFunc(IntPtr node);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeSetDirty")] public static extern void YGNodeSetDirty(IntPtr node);

        public delegate Vector2 YGMeasureFunc(IntPtr nodePtr, float width, MeasureMode widthMode, float height, MeasureMode heightMode);
        public static void YGNodeSetMeasureFunc(IntPtr node, YGMeasureFunc measureFunc)
        {
            YGNodeSetMeasureFunc(node, Marshal.GetFunctionPointerForDelegate(measureFunc));
        }

        #endregion

        #region YGNodeLayout

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeLayoutGetLeft")] public static extern float YGNodeLayoutGetLeft(IntPtr node);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeLayoutGetTop")] public static extern float YGNodeLayoutGetTop(IntPtr node);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeLayoutGetWidth")] public static extern float YGNodeLayoutGetWidth(IntPtr node);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeLayoutGetHeight")] public static extern float YGNodeLayoutGetHeight(IntPtr node);

        #endregion

        #region YGNodeStyle

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetDirection")] public static extern void YGNodeStyleSetDirection(IntPtr node, Direction direction);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetFlexDirection")] public static extern void YGNodeStyleSetFlexDirection(IntPtr node, FlexDirection flexDirection);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetJustifyContent")] public static extern void YGNodeStyleSetJustifyContent(IntPtr node, Justify justifyContent);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetAlignContent")] public static extern void YGNodeStyleSetAlignContent(IntPtr node, Align alignContent);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetAlignItems")] public static extern void YGNodeStyleSetAlignItems(IntPtr node, Align alignItems);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetAlignSelf")] public static extern void YGNodeStyleSetAlignSelf(IntPtr node, Align alignSelf);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetPositionType")] public static extern void YGNodeStyleSetPositionType(IntPtr node, PositionType positionType);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetFlexWrap")] public static extern void YGNodeStyleSetFlexWrap(IntPtr node, Wrap flexWrap);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetFlexGrow")] public static extern void YGNodeStyleSetFlexGrow(IntPtr node, float flexGrow);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetFlexShrink")] public static extern void YGNodeStyleSetFlexShrink(IntPtr node, float flexShrink);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetFlexBasis")] public static extern void YGNodeStyleSetFlexBasis(IntPtr node, float flexBasis);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetFlexBasisPercent")] public static extern void YGNodeStyleSetFlexBasisPercent(IntPtr node, float flexBasis);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetFlexBasisAuto")] public static extern void YGNodeStyleSetFlexBasisAuto(IntPtr node);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetPosition")] public static extern void YGNodeStyleSetPosition(IntPtr node, Edge edge, float position);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetPositionPercent")] public static extern void YGNodeStyleSetPositionPercent(IntPtr node, Edge edge, float position);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetMargin")] public static extern void YGNodeStyleSetMargin(IntPtr node, Edge edge, float margin);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetMarginPercent")] public static extern void YGNodeStyleSetMarginPercent(IntPtr node, Edge edge, float margin);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetMarginAuto")] public static extern void YGNodeStyleSetMarginAuto(IntPtr node, Edge edge);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetPadding")] public static extern void YGNodeStyleSetPadding(IntPtr node, Edge edge, float padding);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetPaddingPercent")] public static extern void YGNodeStyleSetPaddingPercent(IntPtr node, Edge edge, float padding);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetGap")] public static extern void YGNodeStyleSetGap(IntPtr node, Gutter gutter, float gapLength);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetWidth")] public static extern void YGNodeStyleSetWidth(IntPtr node, float width);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetWidthPercent")] public static extern void YGNodeStyleSetWidthPercent(IntPtr node, float width);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetWidthAuto")] public static extern void YGNodeStyleSetWidthAuto(IntPtr node);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetHeight")] public static extern void YGNodeStyleSetHeight(IntPtr node, float height);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetHeightPercent")] public static extern void YGNodeStyleSetHeightPercent(IntPtr node, float height);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetHeightAuto")] public static extern void YGNodeStyleSetHeightAuto(IntPtr node);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetMinWidth")] public static extern void YGNodeStyleSetMinWidth(IntPtr node, float minWidth);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetMinWidthPercent")] public static extern void YGNodeStyleSetMinWidthPercent(IntPtr node, float minWidth);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetMinHeight")] public static extern void YGNodeStyleSetMinHeight(IntPtr node, float minHeight);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetMinHeightPercent")] public static extern void YGNodeStyleSetMinHeightPercent(IntPtr node, float minHeight);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetMaxWidth")] public static extern void YGNodeStyleSetMaxWidth(IntPtr node, float maxWidth);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetMaxWidthPercent")] public static extern void YGNodeStyleSetMaxWidthPercent(IntPtr node, float maxWidth);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetMaxHeight")] public static extern void YGNodeStyleSetMaxHeight(IntPtr node, float maxHeight);
        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetMaxHeightPercent")] public static extern void YGNodeStyleSetMaxHeightPercent(IntPtr node, float maxHeight);

        [DllImport(YogaDll, EntryPoint = "FlexUi_NodeStyleSetAspectRatio")] public static extern void YGNodeStyleSetAspectRatio(IntPtr node, float aspectRatio);

        #endregion
    }
}
