///////////////////////////////////////////////////////////
// Yoga
///////////////////////////////////////////////////////////

// Workaround to avoid exporting Yoga symbols
#include <yoga/YGMacros.h>
#undef YG_EXPORT
#define YG_EXPORT

#include <yoga/YGNodeStyle.cpp>
#include <yoga/YGPixelGrid.cpp>
#include <yoga/YGEnums.cpp>
#include <yoga/YGValue.cpp>
#include <yoga/YGConfig.cpp>
#include <yoga/YGNode.cpp>
#include <yoga/YGNodeLayout.cpp>
#include <yoga/config/Config.cpp>
#include <yoga/algorithm/CalculateLayout.cpp>
#include <yoga/algorithm/PixelGrid.cpp>
#include <yoga/algorithm/Cache.cpp>
#include <yoga/algorithm/Baseline.cpp>
#include <yoga/algorithm/FlexLine.cpp>
#include <yoga/debug/Log.cpp>
#include <yoga/debug/AssertFatal.cpp>
#include <yoga/debug/NodeToString.cpp>
#include <yoga/node/LayoutResults.cpp>
#include <yoga/node/Node.cpp>

// Workaround for ambiguous 'Node' definition
#define Node _Node
#include <yoga/event/event.cpp>
#undef Node

///////////////////////////////////////////////////////////
// Flex UI
///////////////////////////////////////////////////////////
#define EXPORT __attribute__((visibility("default")))

extern "C" {

EXPORT YGConfigRef FlexUi_ConfigNew() {
	return YGConfigNew();
}

EXPORT void FlexUi_ConfigFree(YGConfigRef config) {
	YGConfigFree(config);
}

EXPORT YGConfigConstRef FlexUi_ConfigGetDefault() {
	return YGConfigGetDefault();
}

EXPORT void FlexUi_ConfigSetPointScaleFactor(YGConfigRef config, float enabled) {
	YGConfigSetPointScaleFactor(config, enabled);
}

EXPORT void FlexUi_ConfigSetErrata(YGConfigRef config, YGErrata errata) {
	YGConfigSetErrata(config, errata);
}

EXPORT void FlexUi_ConfigSetExperimentalFeatureEnabled(YGConfigRef config, YGExperimentalFeature feature, bool enabled) {
	YGConfigSetExperimentalFeatureEnabled(config, feature, enabled);
}

EXPORT YGNodeRef FlexUi_NodeNew() {
	return YGNodeNew();
}

EXPORT void FlexUi_NodeFree(YGNodeRef node) {
	YGNodeFree(node);
}

EXPORT void FlexUi_NodeCalculateLayout(YGNodeRef node, float availableWidth, float availableHeight, YGDirection ownerDirection) {
	YGNodeCalculateLayout(node, availableWidth, availableHeight, ownerDirection);
}

EXPORT void FlexUi_NodeInsertChild(YGNodeRef node, YGNodeRef child, int index) {
	YGNodeInsertChild(node, child, index);
}

EXPORT void FlexUi_NodeRemoveChild(YGNodeRef node, YGNodeRef child) {
	YGNodeRemoveChild(node, child);
}

EXPORT void FlexUi_NodeRemoveAllChildren(YGNodeRef node) {
	YGNodeRemoveAllChildren(node);
}

EXPORT void FlexUi_NodeSetConfig(YGNodeRef node, YGConfigRef config) {
	YGNodeSetConfig(node, config);
}

EXPORT float FlexUi_NodeLayoutGetLeft(YGNodeConstRef node) {
	return YGNodeLayoutGetLeft(node);
}

EXPORT float FlexUi_NodeLayoutGetTop(YGNodeConstRef node) {
	return YGNodeLayoutGetTop(node);
}

EXPORT float FlexUi_NodeLayoutGetWidth(YGNodeConstRef node) {
	return YGNodeLayoutGetWidth(node);
}

EXPORT float FlexUi_NodeLayoutGetHeight(YGNodeConstRef node) {
	return YGNodeLayoutGetHeight(node);
}

EXPORT void FlexUi_NodeStyleSetDirection(YGNodeRef node, YGDirection direction) {
	YGNodeStyleSetDirection(node, direction);
}

EXPORT void FlexUi_NodeStyleSetFlexDirection(YGNodeRef node, YGFlexDirection flexDirection) {
	YGNodeStyleSetFlexDirection(node, flexDirection);
}

EXPORT void FlexUi_NodeStyleSetJustifyContent(YGNodeRef node, YGJustify justifyContent) {
	YGNodeStyleSetJustifyContent(node, justifyContent);
}

EXPORT void FlexUi_NodeStyleSetAlignContent(YGNodeRef node, YGAlign alignContent) {
	YGNodeStyleSetAlignContent(node, alignContent);
}

EXPORT void FlexUi_NodeStyleSetAlignItems(YGNodeRef node, YGAlign alignItems) {
	YGNodeStyleSetAlignItems(node, alignItems);
}

EXPORT void FlexUi_NodeStyleSetAlignSelf(YGNodeRef node, YGAlign alignSelf) {
	YGNodeStyleSetAlignSelf(node, alignSelf);
}

EXPORT void FlexUi_NodeStyleSetPositionType(YGNodeRef node, YGPositionType positionType) {
	YGNodeStyleSetPositionType(node, positionType);
}

EXPORT void FlexUi_NodeStyleSetFlexWrap(YGNodeRef node, YGWrap flexWrap) {
	YGNodeStyleSetFlexWrap(node, flexWrap);
}

EXPORT void FlexUi_NodeStyleSetFlexGrow(YGNodeRef node, float flexGrow) {
	YGNodeStyleSetFlexGrow(node, flexGrow);
}

EXPORT void FlexUi_NodeStyleSetFlexShrink(YGNodeRef node, float flexShrink) {
	YGNodeStyleSetFlexShrink(node, flexShrink);
}

EXPORT void FlexUi_NodeStyleSetFlexBasis(YGNodeRef node, float flexBasis) {
	YGNodeStyleSetFlexBasis(node, flexBasis);
}

EXPORT void FlexUi_NodeStyleSetFlexBasisPercent(YGNodeRef node, float flexBasis) {
	YGNodeStyleSetFlexBasisPercent(node, flexBasis);
}

EXPORT void FlexUi_NodeStyleSetFlexBasisAuto(YGNodeRef node) {
	YGNodeStyleSetFlexBasisAuto(node);
}

EXPORT void FlexUi_NodeStyleSetPosition(YGNodeRef node, YGEdge edge, float position) {
	YGNodeStyleSetPosition(node, edge, position);
}

EXPORT void FlexUi_NodeStyleSetPositionPercent(YGNodeRef node, YGEdge edge, float position) {
	YGNodeStyleSetPositionPercent(node, edge, position);
}

EXPORT void FlexUi_NodeStyleSetMargin(YGNodeRef node, YGEdge edge, float margin) {
	YGNodeStyleSetMargin(node, edge, margin);
}

EXPORT void FlexUi_NodeStyleSetMarginPercent(YGNodeRef node, YGEdge edge, float margin) {
	YGNodeStyleSetMarginPercent(node, edge, margin);
}

EXPORT void FlexUi_NodeStyleSetMarginAuto(YGNodeRef node, YGEdge edge) {
	YGNodeStyleSetMarginAuto(node, edge);
}

EXPORT void FlexUi_NodeStyleSetPadding(YGNodeRef node, YGEdge edge, float padding) {
	YGNodeStyleSetPadding(node, edge, padding);
}

EXPORT void FlexUi_NodeStyleSetPaddingPercent(YGNodeRef node, YGEdge edge, float padding) {
	YGNodeStyleSetPaddingPercent(node, edge, padding);
}

EXPORT void FlexUi_NodeStyleSetWidth(YGNodeRef node, float width) {
	YGNodeStyleSetWidth(node, width);
}

EXPORT void FlexUi_NodeStyleSetWidthPercent(YGNodeRef node, float width) {
	YGNodeStyleSetWidthPercent(node, width);
}

EXPORT void FlexUi_NodeStyleSetWidthAuto(YGNodeRef node) {
	YGNodeStyleSetWidthAuto(node);
}

EXPORT void FlexUi_NodeStyleSetHeight(YGNodeRef node, float height) {
	YGNodeStyleSetHeight(node, height);
}

EXPORT void FlexUi_NodeStyleSetHeightPercent(YGNodeRef node, float height) {
	YGNodeStyleSetHeightPercent(node, height);
}

EXPORT void FlexUi_NodeStyleSetHeightAuto(YGNodeRef node) {
	YGNodeStyleSetHeightAuto(node);
}

EXPORT void FlexUi_NodeStyleSetMinWidth(YGNodeRef node, float minWidth) {
	YGNodeStyleSetMinWidth(node, minWidth);
}

EXPORT void FlexUi_NodeStyleSetMinWidthPercent(YGNodeRef node, float minWidth) {
	YGNodeStyleSetMinWidthPercent(node, minWidth);
}

EXPORT void FlexUi_NodeStyleSetMinHeight(YGNodeRef node, float minHeight) {
	YGNodeStyleSetMinHeight(node, minHeight);
}

EXPORT void FlexUi_NodeStyleSetMinHeightPercent(YGNodeRef node, float minHeight) {
	YGNodeStyleSetMinHeightPercent(node, minHeight);
}

EXPORT void FlexUi_NodeStyleSetMaxWidth(YGNodeRef node, float maxWidth) {
	YGNodeStyleSetMaxWidth(node, maxWidth);
}

EXPORT void FlexUi_NodeStyleSetMaxWidthPercent(YGNodeRef node, float maxWidth) {
	YGNodeStyleSetMaxWidthPercent(node, maxWidth);
}

EXPORT void FlexUi_NodeStyleSetMaxHeight(YGNodeRef node, float maxHeight) {
	YGNodeStyleSetMaxHeight(node, maxHeight);
}

EXPORT void FlexUi_NodeStyleSetMaxHeightPercent(YGNodeRef node, float maxHeight) {
	YGNodeStyleSetMaxHeightPercent(node, maxHeight);
}

EXPORT void FlexUi_NodeStyleSetAspectRatio(YGNodeRef node, float aspectRatio) {
	YGNodeStyleSetAspectRatio(node, aspectRatio);
}

}
