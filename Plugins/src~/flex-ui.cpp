#include <yoga/Yoga.h>

extern "C" {

YGConfigRef FlexUi_ConfigNew() {
	return YGConfigNew();
}

void FlexUi_ConfigFree(YGConfigRef config) {
	YGConfigFree(config);
}

YGConfigConstRef FlexUi_ConfigGetDefault() {
	return YGConfigGetDefault();
}

void FlexUi_ConfigSetPointScaleFactor(YGConfigRef config, float enabled) {
	YGConfigSetPointScaleFactor(config, enabled);
}

void FlexUi_ConfigSetErrata(YGConfigRef config, YGErrata errata) {
	YGConfigSetErrata(config, errata);
}

void FlexUi_ConfigSetExperimentalFeatureEnabled(YGConfigRef config, YGExperimentalFeature feature, bool enabled) {
	YGConfigSetExperimentalFeatureEnabled(config, feature, enabled);
}

YGNodeRef FlexUi_NodeNew() {
	return YGNodeNew();
}

void FlexUi_NodeFree(YGNodeRef node) {
	YGNodeFree(node);
}

void FlexUi_NodeCalculateLayout(YGNodeRef node, float availableWidth, float availableHeight, YGDirection ownerDirection) {
	YGNodeCalculateLayout(node, availableWidth, availableHeight, ownerDirection);
}

void FlexUi_NodeInsertChild(YGNodeRef node, YGNodeRef child, int index) {
	YGNodeInsertChild(node, child, index);
}

void FlexUi_NodeRemoveChild(YGNodeRef node, YGNodeRef child) {
	YGNodeRemoveChild(node, child);
}

void FlexUi_NodeRemoveAllChildren(YGNodeRef node) {
	YGNodeRemoveAllChildren(node);
}

void FlexUi_NodeSetConfig(YGNodeRef node, YGConfigRef config) {
	YGNodeSetConfig(node, config);
}

float FlexUi_NodeLayoutGetLeft(YGNodeConstRef node) {
	return YGNodeLayoutGetLeft(node);
}

float FlexUi_NodeLayoutGetTop(YGNodeConstRef node) {
	return YGNodeLayoutGetTop(node);
}

float FlexUi_NodeLayoutGetWidth(YGNodeConstRef node) {
	return YGNodeLayoutGetWidth(node);
}

float FlexUi_NodeLayoutGetHeight(YGNodeConstRef node) {
	return YGNodeLayoutGetHeight(node);
}

void FlexUi_NodeStyleSetDirection(YGNodeRef node, YGDirection direction) {
	YGNodeStyleSetDirection(node, direction);
}

void FlexUi_NodeStyleSetFlexDirection(YGNodeRef node, YGFlexDirection flexDirection) {
	YGNodeStyleSetFlexDirection(node, flexDirection);
}

void FlexUi_NodeStyleSetJustifyContent(YGNodeRef node, YGJustify justifyContent) {
	YGNodeStyleSetJustifyContent(node, justifyContent);
}

void FlexUi_NodeStyleSetAlignContent(YGNodeRef node, YGAlign alignContent) {
	YGNodeStyleSetAlignContent(node, alignContent);
}

void FlexUi_NodeStyleSetAlignItems(YGNodeRef node, YGAlign alignItems) {
	YGNodeStyleSetAlignItems(node, alignItems);
}

void FlexUi_NodeStyleSetAlignSelf(YGNodeRef node, YGAlign alignSelf) {
	YGNodeStyleSetAlignSelf(node, alignSelf);
}

void FlexUi_NodeStyleSetPositionType(YGNodeRef node, YGPositionType positionType) {
	YGNodeStyleSetPositionType(node, positionType);
}

void FlexUi_NodeStyleSetFlexWrap(YGNodeRef node, YGWrap flexWrap) {
	YGNodeStyleSetFlexWrap(node, flexWrap);
}

void FlexUi_NodeStyleSetFlexGrow(YGNodeRef node, float flexGrow) {
	YGNodeStyleSetFlexGrow(node, flexGrow);
}

void FlexUi_NodeStyleSetFlexShrink(YGNodeRef node, float flexShrink) {
	YGNodeStyleSetFlexShrink(node, flexShrink);
}

void FlexUi_NodeStyleSetFlexBasis(YGNodeRef node, float flexBasis) {
	YGNodeStyleSetFlexBasis(node, flexBasis);
}

void FlexUi_NodeStyleSetFlexBasisPercent(YGNodeRef node, float flexBasis) {
	YGNodeStyleSetFlexBasisPercent(node, flexBasis);
}

void FlexUi_NodeStyleSetFlexBasisAuto(YGNodeRef node) {
	YGNodeStyleSetFlexBasisAuto(node);
}

void FlexUi_NodeStyleSetPosition(YGNodeRef node, YGEdge edge, float position) {
	YGNodeStyleSetPosition(node, edge, position);
}

void FlexUi_NodeStyleSetPositionPercent(YGNodeRef node, YGEdge edge, float position) {
	YGNodeStyleSetPositionPercent(node, edge, position);
}

void FlexUi_NodeStyleSetMargin(YGNodeRef node, YGEdge edge, float margin) {
	YGNodeStyleSetMargin(node, edge, margin);
}

void FlexUi_NodeStyleSetMarginPercent(YGNodeRef node, YGEdge edge, float margin) {
	YGNodeStyleSetMarginPercent(node, edge, margin);
}

void FlexUi_NodeStyleSetMarginAuto(YGNodeRef node, YGEdge edge) {
	YGNodeStyleSetMarginAuto(node, edge);
}

void FlexUi_NodeStyleSetPadding(YGNodeRef node, YGEdge edge, float padding) {
	YGNodeStyleSetPadding(node, edge, padding);
}

void FlexUi_NodeStyleSetPaddingPercent(YGNodeRef node, YGEdge edge, float padding) {
	YGNodeStyleSetPaddingPercent(node, edge, padding);
}

void FlexUi_NodeStyleSetWidth(YGNodeRef node, float width) {
	YGNodeStyleSetWidth(node, width);
}

void FlexUi_NodeStyleSetWidthPercent(YGNodeRef node, float width) {
	YGNodeStyleSetWidthPercent(node, width);
}

void FlexUi_NodeStyleSetWidthAuto(YGNodeRef node) {
	YGNodeStyleSetWidthAuto(node);
}

void FlexUi_NodeStyleSetHeight(YGNodeRef node, float height) {
	YGNodeStyleSetHeight(node, height);
}

void FlexUi_NodeStyleSetHeightPercent(YGNodeRef node, float height) {
	YGNodeStyleSetHeightPercent(node, height);
}

void FlexUi_NodeStyleSetHeightAuto(YGNodeRef node) {
	YGNodeStyleSetHeightAuto(node);
}

void FlexUi_NodeStyleSetMinWidth(YGNodeRef node, float minWidth) {
	YGNodeStyleSetMinWidth(node, minWidth);
}

void FlexUi_NodeStyleSetMinWidthPercent(YGNodeRef node, float minWidth) {
	YGNodeStyleSetMinWidthPercent(node, minWidth);
}

void FlexUi_NodeStyleSetMinHeight(YGNodeRef node, float minHeight) {
	YGNodeStyleSetMinHeight(node, minHeight);
}

void FlexUi_NodeStyleSetMinHeightPercent(YGNodeRef node, float minHeight) {
	YGNodeStyleSetMinHeightPercent(node, minHeight);
}

void FlexUi_NodeStyleSetMaxWidth(YGNodeRef node, float maxWidth) {
	YGNodeStyleSetMaxWidth(node, maxWidth);
}

void FlexUi_NodeStyleSetMaxWidthPercent(YGNodeRef node, float maxWidth) {
	YGNodeStyleSetMaxWidthPercent(node, maxWidth);
}

void FlexUi_NodeStyleSetMaxHeight(YGNodeRef node, float maxHeight) {
	YGNodeStyleSetMaxHeight(node, maxHeight);
}

void FlexUi_NodeStyleSetMaxHeightPercent(YGNodeRef node, float maxHeight) {
	YGNodeStyleSetMaxHeightPercent(node, maxHeight);
}

void FlexUi_NodeStyleSetAspectRatio(YGNodeRef node, float aspectRatio) {
	YGNodeStyleSetAspectRatio(node, aspectRatio);
}

}
