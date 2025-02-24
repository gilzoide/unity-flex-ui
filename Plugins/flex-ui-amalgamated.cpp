///////////////////////////////////////////////////////////
// Yoga
///////////////////////////////////////////////////////////

// Workaround to avoid exporting Yoga symbols
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#ifdef __cplusplus
#include <type_traits>
#endif

#ifdef __cplusplus
#define _YG_EXTERN_C_BEGIN extern "C" {
#define _YG_EXTERN_C_END }
#else
#define _YG_EXTERN_C_BEGIN
#define _YG_EXTERN_C_END
#endif

#if defined(__cplusplus)
#define _YG_DEPRECATED(message) [[deprecated(message)]]
#elif defined(_MSC_VER)
#define _YG_DEPRECATED(message) __declspec(deprecated(message))
#else
#define _YG_DEPRECATED(message) __attribute__((deprecated(message)))
#endif

#ifdef _WINDLL
#define _YG_EXPORT __declspec(dllexport)
#elif !defined(_MSC_VER)
#define _YG_EXPORT __attribute__((visibility("default")))
#else
#define _YG_EXPORT
#endif

#ifdef NS_ENUM
// Cannot use NSInteger as NSInteger has a different size than int (which is the
// default type of a enum). Therefor when linking the Yoga C library into obj-c
// the header is a mismatch for the Yoga ABI.
#define _YG_ENUM_BEGIN(name) NS_ENUM(int, name)
#define _YG_ENUM_END(name)
#else
#define _YG_ENUM_BEGIN(name) enum name
#define _YG_ENUM_END(name) name
#endif

#ifdef __cplusplus
#define _YG_DEFINE_ENUM_FLAG_OPERATORS(name)                       \
  extern "C++" {                                                  \
  constexpr inline name operator~(name a) {                       \
    return static_cast<name>(                                     \
        ~static_cast<std::underlying_type<name>::type>(a));       \
  }                                                               \
  constexpr inline name operator|(name a, name b) {               \
    return static_cast<name>(                                     \
        static_cast<std::underlying_type<name>::type>(a) |        \
        static_cast<std::underlying_type<name>::type>(b));        \
  }                                                               \
  constexpr inline name operator&(name a, name b) {               \
    return static_cast<name>(                                     \
        static_cast<std::underlying_type<name>::type>(a) &        \
        static_cast<std::underlying_type<name>::type>(b));        \
  }                                                               \
  constexpr inline name operator^(name a, name b) {               \
    return static_cast<name>(                                     \
        static_cast<std::underlying_type<name>::type>(a) ^        \
        static_cast<std::underlying_type<name>::type>(b));        \
  }                                                               \
  inline name& operator|=(name& a, name b) {                      \
    return reinterpret_cast<name&>(                               \
        reinterpret_cast<std::underlying_type<name>::type&>(a) |= \
        static_cast<std::underlying_type<name>::type>(b));        \
  }                                                               \
  inline name& operator&=(name& a, name b) {                      \
    return reinterpret_cast<name&>(                               \
        reinterpret_cast<std::underlying_type<name>::type&>(a) &= \
        static_cast<std::underlying_type<name>::type>(b));        \
  }                                                               \
  inline name& operator^=(name& a, name b) {                      \
    return reinterpret_cast<name&>(                               \
        reinterpret_cast<std::underlying_type<name>::type&>(a) ^= \
        static_cast<std::underlying_type<name>::type>(b));        \
  }                                                               \
  }
#else
#define _YG_DEFINE_ENUM_FLAG_OPERATORS(name)
#endif

#ifdef __cplusplus

namespace facebook::yoga {

template <typename T>
constexpr int
ordinalCount(); // can't use `= delete` due to a defect in clang < 3.9

namespace detail {
template <int... xs>
constexpr int n() {
  return sizeof...(xs);
}
} // namespace detail

} // namespace facebook::yoga
#endif

#define _YG_ENUM_DECL(NAME, ...)                               \
  typedef _YG_ENUM_BEGIN(NAME){__VA_ARGS__} _YG_ENUM_END(NAME); \
  _YG_EXPORT const char* NAME##ToString(NAME);

#ifdef __cplusplus
#define _YG_ENUM_SEQ_DECL(NAME, ...)    \
  _YG_ENUM_DECL(NAME, __VA_ARGS__)      \
  _YG_EXTERN_C_END                      \
                                       \
  namespace facebook::yoga {           \
  template <>                          \
  constexpr int ordinalCount<NAME>() { \
    return detail::n<__VA_ARGS__>();   \
  }                                    \
  }                                    \
  _YG_EXTERN_C_BEGIN
#else
#define _YG_ENUM_SEQ_DECL _YG_ENUM_DECL
#endif
#undef _YG_EXPORT
#define _YG_EXPORT

/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


/**
 * `#include <yoga/Yoga.h>` includes all of Yoga's public headers.
 */

/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

_YG_EXTERN_C_BEGIN

_YG_ENUM_SEQ_DECL(
    _YGAlign,
    _YGAlignAuto,
    _YGAlignFlexStart,
    _YGAlignCenter,
    _YGAlignFlexEnd,
    _YGAlignStretch,
    _YGAlignBaseline,
    _YGAlignSpaceBetween,
    _YGAlignSpaceAround,
    _YGAlignSpaceEvenly)

_YG_ENUM_SEQ_DECL(
    _YGDimension,
    _YGDimensionWidth,
    _YGDimensionHeight)

_YG_ENUM_SEQ_DECL(
    _YGDirection,
    _YGDirectionInherit,
    _YGDirectionLTR,
    _YGDirectionRTL)

_YG_ENUM_SEQ_DECL(
    _YGDisplay,
    _YGDisplayFlex,
    _YGDisplayNone)

_YG_ENUM_SEQ_DECL(
    _YGEdge,
    _YGEdgeLeft,
    _YGEdgeTop,
    _YGEdgeRight,
    _YGEdgeBottom,
    _YGEdgeStart,
    _YGEdgeEnd,
    _YGEdgeHorizontal,
    _YGEdgeVertical,
    _YGEdgeAll)

_YG_ENUM_DECL(
    _YGErrata,
    _YGErrataNone = 0,
    _YGErrataStretchFlexBasis = 1,
    _YGErrataStartingEndingEdgeFromFlexDirection = 2,
    _YGErrataPositionStaticBehavesLikeRelative = 4,
    _YGErrataAll = 2147483647,
    _YGErrataClassic = 2147483646)
_YG_DEFINE_ENUM_FLAG_OPERATORS(_YGErrata)

_YG_ENUM_SEQ_DECL(
    _YGExperimentalFeature,
    _YGExperimentalFeatureWebFlexBasis,
    _YGExperimentalFeatureAbsolutePercentageAgainstPaddingEdge)

_YG_ENUM_SEQ_DECL(
    _YGFlexDirection,
    _YGFlexDirectionColumn,
    _YGFlexDirectionColumnReverse,
    _YGFlexDirectionRow,
    _YGFlexDirectionRowReverse)

_YG_ENUM_SEQ_DECL(
    _YGGutter,
    _YGGutterColumn,
    _YGGutterRow,
    _YGGutterAll)

_YG_ENUM_SEQ_DECL(
    _YGJustify,
    _YGJustifyFlexStart,
    _YGJustifyCenter,
    _YGJustifyFlexEnd,
    _YGJustifySpaceBetween,
    _YGJustifySpaceAround,
    _YGJustifySpaceEvenly)

_YG_ENUM_SEQ_DECL(
    _YGLogLevel,
    _YGLogLevelError,
    _YGLogLevelWarn,
    _YGLogLevelInfo,
    _YGLogLevelDebug,
    _YGLogLevelVerbose,
    _YGLogLevelFatal)

_YG_ENUM_SEQ_DECL(
    _YGMeasureMode,
    _YGMeasureModeUndefined,
    _YGMeasureModeExactly,
    _YGMeasureModeAtMost)

_YG_ENUM_SEQ_DECL(
    _YGNodeType,
    _YGNodeTypeDefault,
    _YGNodeTypeText)

_YG_ENUM_SEQ_DECL(
    _YGOverflow,
    _YGOverflowVisible,
    _YGOverflowHidden,
    _YGOverflowScroll)

_YG_ENUM_SEQ_DECL(
    _YGPositionType,
    _YGPositionTypeStatic,
    _YGPositionTypeRelative,
    _YGPositionTypeAbsolute)

_YG_ENUM_DECL(
    _YGPrintOptions,
    _YGPrintOptionsLayout = 1,
    _YGPrintOptionsStyle = 2,
    _YGPrintOptionsChildren = 4)
_YG_DEFINE_ENUM_FLAG_OPERATORS(_YGPrintOptions)

_YG_ENUM_SEQ_DECL(
    _YGUnit,
    _YGUnitUndefined,
    _YGUnitPoint,
    _YGUnitPercent,
    _YGUnitAuto)

_YG_ENUM_SEQ_DECL(
    _YGWrap,
    _YGWrapNoWrap,
    _YGWrapWrap,
    _YGWrapWrapReverse)

_YG_EXTERN_C_END

_YG_EXTERN_C_BEGIN

typedef struct _YGNode* _YGNodeRef;
typedef const struct _YGNode* _YGNodeConstRef;

/**
 * Handle to a mutable Yoga configuration.
 */
typedef struct _YGConfig* _YGConfigRef;

/**
 * Handle to an immutable Yoga configruation.
 */
typedef const struct _YGConfig* _YGConfigConstRef;

/**
 * Allocates a set of configuration options. The configuration may be applied to
 * multiple nodes (i.e. a single global config), or can be applied more
 * granularly per-node.
 */
_YG_EXPORT _YGConfigRef _YGConfigNew(void);

/**
 * Frees the associated Yoga configuration.
 */
_YG_EXPORT void _YGConfigFree(_YGConfigRef config);

/**
 * Returns the default config values set by Yoga.
 */
_YG_EXPORT _YGConfigConstRef _YGConfigGetDefault(void);

/**
 * Yoga by default creates new nodes with style defaults different from flexbox
 * on web (e.g. `_YGFlexDirectionColumn` and `_YGPositionRelative`).
 * `UseWebDefaults` instructs Yoga to instead use a default style consistent
 * with the web.
 */
_YG_EXPORT void _YGConfigSetUseWebDefaults(_YGConfigRef config, bool enabled);

/**
 * Whether the configuration is set to use web defaults.
 */
_YG_EXPORT bool _YGConfigGetUseWebDefaults(_YGConfigConstRef config);

/**
 * Yoga will by deafult round final layout positions and dimensions to the
 * nearst point. `pointScaleFactor` controls the density of the grid used for
 * layout rounding (e.g. to round to the closest display pixel).
 *
 * May be set to 0.0f to avoid rounding the layout results.
 */
_YG_EXPORT void _YGConfigSetPointScaleFactor(
    _YGConfigRef config,
    float pixelsInPoint);

/**
 * Get the currently set point scale factor.
 */
_YG_EXPORT float _YGConfigGetPointScaleFactor(_YGConfigConstRef config);

/**
 * Configures how Yoga balances W3C conformance vs compatibility with layouts
 * created against earlier versions of Yoga.
 *
 * By deafult Yoga will prioritize W3C conformance. `Errata` may be set to ask
 * Yoga to produce specific incorrect behaviors. E.g. `_YGConfigSetErrata(config,
 * _YGErrataPositionStaticBehavesLikeRelative)`.
 *
 * _YGErrata is a bitmask, and multiple errata may be set at once. Predfined
 * constants exist for convenience:
 * 1. _YGErrataNone: No errata
 * 2. _YGErrataClassic: Match layout behaviors of Yoga 1.x
 * 3. _YGErrataAll: Match layout behaviors of Yoga 1.x, including
 * `UseLegacyStretchBehaviour`
 */
_YG_EXPORT void _YGConfigSetErrata(_YGConfigRef config, _YGErrata errata);

/**
 * Get the currently set errata.
 */
_YG_EXPORT _YGErrata _YGConfigGetErrata(_YGConfigConstRef config);

/**
 * Function pointer type for _YGConfigSetLogger.
 */
typedef int (*_YGLogger)(
    _YGConfigConstRef config,
    _YGNodeConstRef node,
    _YGLogLevel level,
    const char* format,
    va_list args);

/**
 * Set a custom log function for to use when logging diagnostics or fatal.
 * errors.
 */
_YG_EXPORT void _YGConfigSetLogger(_YGConfigRef config, _YGLogger logger);

/**
 * Sets an arbitrary context pointer on the config which may be read from during
 * callbacks.
 */
_YG_EXPORT void _YGConfigSetContext(_YGConfigRef config, void* context);

/**
 * Gets the currently set context.
 */
_YG_EXPORT void* _YGConfigGetContext(_YGConfigConstRef config);

/**
 * Function pointer type for _YGConfigSetCloneNodeFunc.
 */
typedef _YGNodeRef (*_YGCloneNodeFunc)(
    _YGNodeConstRef oldNode,
    _YGNodeConstRef owner,
    size_t childIndex);

/**
 * Enable an experimental/unsupported feature in Yoga.
 */
_YG_EXPORT void _YGConfigSetExperimentalFeatureEnabled(
    _YGConfigRef config,
    _YGExperimentalFeature feature,
    bool enabled);

/**
 * Whether an experimental feature is set.
 */
_YG_EXPORT bool _YGConfigIsExperimentalFeatureEnabled(
    _YGConfigConstRef config,
    _YGExperimentalFeature feature);

/**
 * Sets a callback, called during layout, to create a new mutable Yoga node if
 * Yoga must write to it and its owner is not its parent observed during layout.
 */
_YG_EXPORT void _YGConfigSetCloneNodeFunc(
    _YGConfigRef config,
    _YGCloneNodeFunc callback);

/**
 * Allows printing the Yoga node tree during layout for debugging purposes.
 */
_YG_EXPORT void _YGConfigSetPrintTreeFlag(_YGConfigRef config, bool enabled);

_YG_EXTERN_C_END
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <stdbool.h>
#include <stddef.h>


_YG_EXTERN_C_BEGIN

/**
 * Handle to a mutable Yoga Node.
 */
typedef struct _YGNode* _YGNodeRef;

/**
 * Handle to an immutable Yoga Node.
 */
typedef const struct _YGNode* _YGNodeConstRef;

/**
 * Heap allocates and returns a new Yoga node using Yoga settings.
 */
_YG_EXPORT _YGNodeRef _YGNodeNew(void);

/**
 * Heap allocates and returns a new Yoga node, with customized settings.
 */
_YG_EXPORT _YGNodeRef _YGNodeNewWithConfig(_YGConfigConstRef config);

/**
 * Returns a mutable copy of an existing node, with the same context and
 * children, but no owner set. Does not call the function set by
 * _YGConfigSetCloneNodeFunc().
 */
_YG_EXPORT _YGNodeRef _YGNodeClone(_YGNodeConstRef node);

/**
 * Frees the Yoga node, disconnecting it from its owner and children.
 */
_YG_EXPORT void _YGNodeFree(_YGNodeRef node);

/**
 * Frees the subtree of Yoga nodes rooted at the given node.
 */
_YG_EXPORT void _YGNodeFreeRecursive(_YGNodeRef node);

/**
 * Frees the Yoga node without disconnecting it from its owner or children.
 * Allows garbage collecting Yoga nodes in parallel when the entire tree is
 * unrechable.
 */
_YG_EXPORT void _YGNodeFinalize(_YGNodeRef node);

/**
 * Resets the node to its default state.
 */
_YG_EXPORT void _YGNodeReset(_YGNodeRef node);

/**
 * Calculates the layout of the tree rooted at the given node.
 *
 * Layout results may be read after calling _YGNodeCalculateLayout() using
 * functions like _YGNodeLayoutGetLeft(), _YGNodeLayoutGetTop(), etc.
 *
 * _YGNodeGetHasNewLayout() may be read to know if the layout of the node or its
 * subtrees may have changed since the last time _YGNodeCalculate() was called.
 */
_YG_EXPORT void _YGNodeCalculateLayout(
    _YGNodeRef node,
    float availableWidth,
    float availableHeight,
    _YGDirection ownerDirection);

/**
 * Whether the given node may have new layout results. Must be reset by calling
 * _YGNodeSetHasNewLayout().
 */
_YG_EXPORT bool _YGNodeGetHasNewLayout(_YGNodeConstRef node);

/**
 * Sets whether a nodes layout is considered new.
 */
_YG_EXPORT void _YGNodeSetHasNewLayout(_YGNodeRef node, bool hasNewLayout);

/**
 * Whether the node's layout results are dirty due to it or its children
 * changing.
 */
_YG_EXPORT bool _YGNodeIsDirty(_YGNodeConstRef node);

/**
 * Marks a node with custom measure function as dirty.
 */
_YG_EXPORT void _YGNodeMarkDirty(_YGNodeRef node);

typedef void (*_YGDirtiedFunc)(_YGNodeConstRef node);

/**
 * Called when a change is made to the Yoga tree which dirties this node.
 */
_YG_EXPORT void _YGNodeSetDirtiedFunc(_YGNodeRef node, _YGDirtiedFunc dirtiedFunc);

/**
 * Returns a dirtied func if set.
 */
_YG_EXPORT _YGDirtiedFunc _YGNodeGetDirtiedFunc(_YGNodeConstRef node);

/**
 * Inserts a child node at the given index.
 */
_YG_EXPORT void _YGNodeInsertChild(_YGNodeRef node, _YGNodeRef child, size_t index);

/**
 * Replaces the child node at a given index with a new one.
 */
_YG_EXPORT void _YGNodeSwapChild(_YGNodeRef node, _YGNodeRef child, size_t index);

/**
 * Removes the given child node.
 */
_YG_EXPORT void _YGNodeRemoveChild(_YGNodeRef node, _YGNodeRef child);

/**
 * Removes all children nodes.
 */
_YG_EXPORT void _YGNodeRemoveAllChildren(_YGNodeRef node);

/**
 * Sets children according to the given list of nodes.
 */
_YG_EXPORT void
_YGNodeSetChildren(_YGNodeRef owner, const _YGNodeRef* children, size_t count);

/**
 * Get the child node at a given index.
 */
_YG_EXPORT _YGNodeRef _YGNodeGetChild(_YGNodeRef node, size_t index);

/**
 * The number of child nodes.
 */
_YG_EXPORT size_t _YGNodeGetChildCount(_YGNodeConstRef node);

/**
 * Get the parent/owner currently set for a node.
 */
_YG_EXPORT _YGNodeRef _YGNodeGetOwner(_YGNodeRef node);

/**
 * Get the parent/owner currently set for a node.
 */
_YG_EXPORT _YGNodeRef _YGNodeGetParent(_YGNodeRef node);

/**
 * Set a new config for the node after creation.
 */
_YG_EXPORT void _YGNodeSetConfig(_YGNodeRef node, _YGConfigRef config);

/**
 * Get the config currently set on the node.
 */
_YG_EXPORT _YGConfigConstRef _YGNodeGetConfig(_YGNodeRef node);

/**
 * Sets extra data on the Yoga node which may be read from during callbacks.
 */
_YG_EXPORT void _YGNodeSetContext(_YGNodeRef node, void* context);

/**
 * Returns the context or NULL if no context has been set.
 */
_YG_EXPORT void* _YGNodeGetContext(_YGNodeConstRef node);

typedef struct _YGSize {
  float width;
  float height;
} _YGSize;

/**
 * @returns the size of the leaf node, measured under the given contraints.
 */
typedef _YGSize (*_YGMeasureFunc)(
    _YGNodeConstRef node,
    float width,
    _YGMeasureMode widthMode,
    float height,
    _YGMeasureMode heightMode);

/**
 * Allows providing custom measurements for a Yoga leaf node (usually for
 * measuring text). _YGNodeMarkDirty() must be set if content effecting the
 * measurements of the node changes.
 */
_YG_EXPORT void _YGNodeSetMeasureFunc(_YGNodeRef node, _YGMeasureFunc measureFunc);

/**
 * Whether a measure function is set.
 */
_YG_EXPORT bool _YGNodeHasMeasureFunc(_YGNodeConstRef node);

/**
 * @returns a defined offet to baseline (ascent).
 */
typedef float (*_YGBaselineFunc)(_YGNodeConstRef node, float width, float height);

/**
 * Set a custom function for determining the text baseline for use in baseline
 * alignment.
 */
_YG_EXPORT void _YGNodeSetBaselineFunc(
    _YGNodeRef node,
    _YGBaselineFunc baselineFunc);

/**
 * Whether a baseline function is set.
 */
_YG_EXPORT bool _YGNodeHasBaselineFunc(_YGNodeConstRef node);

/**
 * Sets this node should be considered the reference baseline among siblings.
 */
_YG_EXPORT void _YGNodeSetIsReferenceBaseline(
    _YGNodeRef node,
    bool isReferenceBaseline);

/**
 * Whether this node is set as the reference baseline.
 */
_YG_EXPORT bool _YGNodeIsReferenceBaseline(_YGNodeConstRef node);

/**
 * Sets whether a leaf node's layout results may be truncated during layout
 * rounding.
 */
_YG_EXPORT void _YGNodeSetNodeType(_YGNodeRef node, _YGNodeType nodeType);

/**
 * Wwhether a leaf node's layout results may be truncated during layout
 * rounding.
 */
_YG_EXPORT _YGNodeType _YGNodeGetNodeType(_YGNodeConstRef node);

typedef void (*_YGPrintFunc)(_YGNodeConstRef node);

/**
 * Set a function to be called when configured to print nodes during layout for
 * debugging.
 */
_YG_EXPORT void _YGNodeSetPrintFunc(_YGNodeRef node, _YGPrintFunc printFunc);

/**
 * Print a node to log output.
 */
_YG_EXPORT void _YGNodePrint(_YGNodeConstRef node, _YGPrintOptions options);

/**
 * @deprecated
 */
_YG_DEPRECATED(
    "_YGNodeCanUseCachedMeasurement may be removed in a future version of Yoga")
_YG_EXPORT bool _YGNodeCanUseCachedMeasurement(
    _YGMeasureMode widthMode,
    float availableWidth,
    _YGMeasureMode heightMode,
    float availableHeight,
    _YGMeasureMode lastWidthMode,
    float lastAvailableWidth,
    _YGMeasureMode lastHeightMode,
    float lastAvailableHeight,
    float lastComputedWidth,
    float lastComputedHeight,
    float marginRow,
    float marginColumn,
    _YGConfigRef config);

_YG_EXTERN_C_END
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <stdbool.h>


_YG_EXTERN_C_BEGIN

_YG_EXPORT float _YGNodeLayoutGetLeft(_YGNodeConstRef node);
_YG_EXPORT float _YGNodeLayoutGetTop(_YGNodeConstRef node);
_YG_EXPORT float _YGNodeLayoutGetRight(_YGNodeConstRef node);
_YG_EXPORT float _YGNodeLayoutGetBottom(_YGNodeConstRef node);
_YG_EXPORT float _YGNodeLayoutGetWidth(_YGNodeConstRef node);
_YG_EXPORT float _YGNodeLayoutGetHeight(_YGNodeConstRef node);
_YG_EXPORT _YGDirection _YGNodeLayoutGetDirection(_YGNodeConstRef node);
_YG_EXPORT bool _YGNodeLayoutGetHadOverflow(_YGNodeConstRef node);

// Get the computed values for these nodes after performing layout. If they were
// set using point values then the returned value will be the same as
// _YGNodeStyleGetXXX. However if they were set using a percentage value then the
// returned value is the computed value used during layout.
_YG_EXPORT float _YGNodeLayoutGetMargin(_YGNodeConstRef node, _YGEdge edge);
_YG_EXPORT float _YGNodeLayoutGetBorder(_YGNodeConstRef node, _YGEdge edge);
_YG_EXPORT float _YGNodeLayoutGetPadding(_YGNodeConstRef node, _YGEdge edge);

_YG_EXTERN_C_END
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <stddef.h>

/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <stdbool.h>


/**
 * Float value to represent "undefined" in style values.
 */
#ifdef __cplusplus
#include <limits>
constexpr float _YGUndefined = std::numeric_limits<float>::quiet_NaN();
#else
#include <math.h>
#define _YGUndefined NAN
#endif

_YG_EXTERN_C_BEGIN

/**
 * Structure used to represent a dimension in a style.
 */
typedef struct _YGValue {
  float value;
  _YGUnit unit;
} _YGValue;

/**
 * Constant for a dimension of "auto".
 */
_YG_EXPORT extern const _YGValue _YGValueAuto;

/**
 * Constant for a dimension which is not defined.
 */
_YG_EXPORT extern const _YGValue _YGValueUndefined;

/**
 * Constant for a dimension that is zero-length.
 */
_YG_EXPORT extern const _YGValue _YGValueZero;

/**
 * Whether a dimension represented as a float is defined.
 */
_YG_EXPORT bool _YGFloatIsUndefined(float value);

_YG_EXTERN_C_END

// Equality operators for comparison of _YGValue in C++
#ifdef __cplusplus
inline bool operator==(const _YGValue& lhs, const _YGValue& rhs) {
  if (lhs.unit != rhs.unit) {
    return false;
  }

  switch (lhs.unit) {
    case _YGUnitUndefined:
    case _YGUnitAuto:
      return true;
    case _YGUnitPoint:
    case _YGUnitPercent:
      return lhs.value == rhs.value;
  }

  return false;
}

inline bool operator!=(const _YGValue& lhs, const _YGValue& rhs) {
  return !(lhs == rhs);
}

inline _YGValue operator-(const _YGValue& value) {
  return {-value.value, value.unit};
}
#endif

_YG_EXTERN_C_BEGIN

_YG_EXPORT void _YGNodeCopyStyle(_YGNodeRef dstNode, _YGNodeConstRef srcNode);

_YG_EXPORT void _YGNodeStyleSetDirection(_YGNodeRef node, _YGDirection direction);
_YG_EXPORT _YGDirection _YGNodeStyleGetDirection(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetFlexDirection(
    _YGNodeRef node,
    _YGFlexDirection flexDirection);
_YG_EXPORT _YGFlexDirection _YGNodeStyleGetFlexDirection(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetJustifyContent(
    _YGNodeRef node,
    _YGJustify justifyContent);
_YG_EXPORT _YGJustify _YGNodeStyleGetJustifyContent(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetAlignContent(_YGNodeRef node, _YGAlign alignContent);
_YG_EXPORT _YGAlign _YGNodeStyleGetAlignContent(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetAlignItems(_YGNodeRef node, _YGAlign alignItems);
_YG_EXPORT _YGAlign _YGNodeStyleGetAlignItems(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetAlignSelf(_YGNodeRef node, _YGAlign alignSelf);
_YG_EXPORT _YGAlign _YGNodeStyleGetAlignSelf(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetPositionType(
    _YGNodeRef node,
    _YGPositionType positionType);
_YG_EXPORT _YGPositionType _YGNodeStyleGetPositionType(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetFlexWrap(_YGNodeRef node, _YGWrap flexWrap);
_YG_EXPORT _YGWrap _YGNodeStyleGetFlexWrap(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetOverflow(_YGNodeRef node, _YGOverflow overflow);
_YG_EXPORT _YGOverflow _YGNodeStyleGetOverflow(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetDisplay(_YGNodeRef node, _YGDisplay display);
_YG_EXPORT _YGDisplay _YGNodeStyleGetDisplay(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetFlex(_YGNodeRef node, float flex);
_YG_EXPORT float _YGNodeStyleGetFlex(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetFlexGrow(_YGNodeRef node, float flexGrow);
_YG_EXPORT float _YGNodeStyleGetFlexGrow(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetFlexShrink(_YGNodeRef node, float flexShrink);
_YG_EXPORT float _YGNodeStyleGetFlexShrink(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetFlexBasis(_YGNodeRef node, float flexBasis);
_YG_EXPORT void _YGNodeStyleSetFlexBasisPercent(_YGNodeRef node, float flexBasis);
_YG_EXPORT void _YGNodeStyleSetFlexBasisAuto(_YGNodeRef node);
_YG_EXPORT _YGValue _YGNodeStyleGetFlexBasis(_YGNodeConstRef node);

_YG_EXPORT void
_YGNodeStyleSetPosition(_YGNodeRef node, _YGEdge edge, float position);
_YG_EXPORT void
_YGNodeStyleSetPositionPercent(_YGNodeRef node, _YGEdge edge, float position);
_YG_EXPORT _YGValue _YGNodeStyleGetPosition(_YGNodeConstRef node, _YGEdge edge);

_YG_EXPORT void _YGNodeStyleSetMargin(_YGNodeRef node, _YGEdge edge, float margin);
_YG_EXPORT void
_YGNodeStyleSetMarginPercent(_YGNodeRef node, _YGEdge edge, float margin);
_YG_EXPORT void _YGNodeStyleSetMarginAuto(_YGNodeRef node, _YGEdge edge);
_YG_EXPORT _YGValue _YGNodeStyleGetMargin(_YGNodeConstRef node, _YGEdge edge);

_YG_EXPORT void
_YGNodeStyleSetPadding(_YGNodeRef node, _YGEdge edge, float padding);
_YG_EXPORT void
_YGNodeStyleSetPaddingPercent(_YGNodeRef node, _YGEdge edge, float padding);
_YG_EXPORT _YGValue _YGNodeStyleGetPadding(_YGNodeConstRef node, _YGEdge edge);

_YG_EXPORT void _YGNodeStyleSetBorder(_YGNodeRef node, _YGEdge edge, float border);
_YG_EXPORT float _YGNodeStyleGetBorder(_YGNodeConstRef node, _YGEdge edge);

_YG_EXPORT void
_YGNodeStyleSetGap(_YGNodeRef node, _YGGutter gutter, float gapLength);
_YG_EXPORT float _YGNodeStyleGetGap(_YGNodeConstRef node, _YGGutter gutter);

_YG_EXPORT void _YGNodeStyleSetWidth(_YGNodeRef node, float width);
_YG_EXPORT void _YGNodeStyleSetWidthPercent(_YGNodeRef node, float width);
_YG_EXPORT void _YGNodeStyleSetWidthAuto(_YGNodeRef node);
_YG_EXPORT _YGValue _YGNodeStyleGetWidth(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetHeight(_YGNodeRef node, float height);
_YG_EXPORT void _YGNodeStyleSetHeightPercent(_YGNodeRef node, float height);
_YG_EXPORT void _YGNodeStyleSetHeightAuto(_YGNodeRef node);
_YG_EXPORT _YGValue _YGNodeStyleGetHeight(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetMinWidth(_YGNodeRef node, float minWidth);
_YG_EXPORT void _YGNodeStyleSetMinWidthPercent(_YGNodeRef node, float minWidth);
_YG_EXPORT _YGValue _YGNodeStyleGetMinWidth(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetMinHeight(_YGNodeRef node, float minHeight);
_YG_EXPORT void _YGNodeStyleSetMinHeightPercent(_YGNodeRef node, float minHeight);
_YG_EXPORT _YGValue _YGNodeStyleGetMinHeight(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetMaxWidth(_YGNodeRef node, float maxWidth);
_YG_EXPORT void _YGNodeStyleSetMaxWidthPercent(_YGNodeRef node, float maxWidth);
_YG_EXPORT _YGValue _YGNodeStyleGetMaxWidth(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetMaxHeight(_YGNodeRef node, float maxHeight);
_YG_EXPORT void _YGNodeStyleSetMaxHeightPercent(_YGNodeRef node, float maxHeight);
_YG_EXPORT _YGValue _YGNodeStyleGetMaxHeight(_YGNodeConstRef node);

_YG_EXPORT void _YGNodeStyleSetAspectRatio(_YGNodeRef node, float aspectRatio);
_YG_EXPORT float _YGNodeStyleGetAspectRatio(_YGNodeConstRef node);

_YG_EXTERN_C_END
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <stdbool.h>


_YG_EXTERN_C_BEGIN

/**
 * Rounds a point value to the nearest whole pixel, given a pointScaleFactor
 * describing pixel density.
 * @returns the rounded value in points
 */
_YG_EXPORT float _YGRoundValueToPixelGrid(
    double value,
    double pointScaleFactor,
    bool forceCeil,
    bool forceFloor);

_YG_EXTERN_C_END
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <bitset>

/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <iterator>
#include <type_traits>

namespace facebook::yoga {

template <typename EnumT>
constexpr inline int32_t ordinalCount();

/**
 * Count of bits needed to represent every ordinal
 */
template <typename EnumT>
constexpr inline int32_t bitCount();

/**
 * Polyfill of C++ 23 to_underlying()
 * https://en.cppreference.com/w/cpp/utility/to_underlying
 */
constexpr auto to_underlying(auto e) noexcept {
  return static_cast<std::underlying_type_t<decltype(e)>>(e);
}

/**
 * Convenience function to iterate through every value in a Yoga enum as part of
 * a range-based for loop.
 */
template <typename EnumT>
auto ordinals() {
  struct Iterator {
    EnumT e{};

    EnumT operator*() const {
      return e;
    }

    Iterator& operator++() {
      e = static_cast<EnumT>(to_underlying(e) + 1);
      return *this;
    }

    bool operator==(const Iterator& other) const = default;
    bool operator!=(const Iterator& other) const = default;
  };

  struct Range {
    Iterator begin() const {
      return Iterator{};
    }
    Iterator end() const {
      return Iterator{static_cast<EnumT>(ordinalCount<EnumT>())};
    }
  };

  return Range{};
}

} // namespace facebook::yoga

namespace facebook::yoga {

enum class Errata : uint32_t {
  None = _YGErrataNone,
  StretchFlexBasis = _YGErrataStretchFlexBasis,
  StartingEndingEdgeFromFlexDirection = _YGErrataStartingEndingEdgeFromFlexDirection,
  PositionStaticBehavesLikeRelative = _YGErrataPositionStaticBehavesLikeRelative,
  All = _YGErrataAll,
  Classic = _YGErrataClassic,
};

_YG_DEFINE_ENUM_FLAG_OPERATORS(Errata)

constexpr inline Errata scopedEnum(_YGErrata unscoped) {
  return static_cast<Errata>(unscoped);
}

constexpr inline _YGErrata unscopedEnum(Errata scoped) {
  return static_cast<_YGErrata>(scoped);
}

inline const char* toString(Errata e) {
  return _YGErrataToString(unscopedEnum(e));
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class ExperimentalFeature : uint8_t {
  WebFlexBasis = _YGExperimentalFeatureWebFlexBasis,
  AbsolutePercentageAgainstPaddingEdge = _YGExperimentalFeatureAbsolutePercentageAgainstPaddingEdge,
};

template <>
constexpr inline int32_t ordinalCount<ExperimentalFeature>() {
  return 2;
} 

template <>
constexpr inline int32_t bitCount<ExperimentalFeature>() {
  return 1;
} 

constexpr inline ExperimentalFeature scopedEnum(_YGExperimentalFeature unscoped) {
  return static_cast<ExperimentalFeature>(unscoped);
}

constexpr inline _YGExperimentalFeature unscopedEnum(ExperimentalFeature scoped) {
  return static_cast<_YGExperimentalFeature>(scoped);
}

inline const char* toString(ExperimentalFeature e) {
  return _YGExperimentalFeatureToString(unscopedEnum(e));
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class LogLevel : uint8_t {
  Error = _YGLogLevelError,
  Warn = _YGLogLevelWarn,
  Info = _YGLogLevelInfo,
  Debug = _YGLogLevelDebug,
  Verbose = _YGLogLevelVerbose,
  Fatal = _YGLogLevelFatal,
};

template <>
constexpr inline int32_t ordinalCount<LogLevel>() {
  return 6;
} 

template <>
constexpr inline int32_t bitCount<LogLevel>() {
  return 3;
} 

constexpr inline LogLevel scopedEnum(_YGLogLevel unscoped) {
  return static_cast<LogLevel>(unscoped);
}

constexpr inline _YGLogLevel unscopedEnum(LogLevel scoped) {
  return static_cast<_YGLogLevel>(scoped);
}

inline const char* toString(LogLevel e) {
  return _YGLogLevelToString(unscopedEnum(e));
}

} // namespace facebook::yoga

// Tag struct used to form the opaque _YGConfigRef for the public C API
struct _YGConfig {};

namespace facebook::yoga {

class Config;
class Node;

using ExperimentalFeatureSet = std::bitset<ordinalCount<ExperimentalFeature>()>;

// Whether moving a node from an old to new config should dirty previously
// calculated layout results.
bool configUpdateInvalidatesLayout(
    const Config& oldConfig,
    const Config& newConfig);

class _YG_EXPORT Config : public ::_YGConfig {
 public:
  Config(_YGLogger logger);

  void setUseWebDefaults(bool useWebDefaults);
  bool useWebDefaults() const;

  void setShouldPrintTree(bool printTree);
  bool shouldPrintTree() const;

  void setExperimentalFeatureEnabled(ExperimentalFeature feature, bool enabled);
  bool isExperimentalFeatureEnabled(ExperimentalFeature feature) const;
  ExperimentalFeatureSet getEnabledExperiments() const;

  void setErrata(Errata errata);
  void addErrata(Errata errata);
  void removeErrata(Errata errata);
  Errata getErrata() const;
  bool hasErrata(Errata errata) const;

  void setPointScaleFactor(float pointScaleFactor);
  float getPointScaleFactor() const;

  void setContext(void* context);
  void* getContext() const;

  void setLogger(_YGLogger logger);
  void log(
      const yoga::Node* node,
      LogLevel logLevel,
      const char* format,
      va_list args) const;

  void setCloneNodeCallback(_YGCloneNodeFunc cloneNode);
  _YGNodeRef
  cloneNode(_YGNodeConstRef node, _YGNodeConstRef owner, size_t childIndex) const;

  static const Config& getDefault();

 private:
  _YGCloneNodeFunc cloneNodeCallback_;
  _YGLogger logger_;

  bool useWebDefaults_ : 1 = false;
  bool printTree_ : 1 = false;

  ExperimentalFeatureSet experimentalFeatures_{};
  Errata errata_ = Errata::None;
  float pointScaleFactor_ = 1.0f;
  void* context_ = nullptr;
};

inline Config* resolveRef(const _YGConfigRef ref) {
  return static_cast<Config*>(ref);
}

inline const Config* resolveRef(const _YGConfigConstRef ref) {
  return static_cast<const Config*>(ref);
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <stdio.h>
#include <cstdint>
#include <vector>


/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class Dimension : uint8_t {
  Width = _YGDimensionWidth,
  Height = _YGDimensionHeight,
};

template <>
constexpr inline int32_t ordinalCount<Dimension>() {
  return 2;
} 

template <>
constexpr inline int32_t bitCount<Dimension>() {
  return 1;
} 

constexpr inline Dimension scopedEnum(_YGDimension unscoped) {
  return static_cast<Dimension>(unscoped);
}

constexpr inline _YGDimension unscopedEnum(Dimension scoped) {
  return static_cast<_YGDimension>(scoped);
}

inline const char* toString(Dimension e) {
  return _YGDimensionToString(unscopedEnum(e));
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class Direction : uint8_t {
  Inherit = _YGDirectionInherit,
  LTR = _YGDirectionLTR,
  RTL = _YGDirectionRTL,
};

template <>
constexpr inline int32_t ordinalCount<Direction>() {
  return 3;
} 

template <>
constexpr inline int32_t bitCount<Direction>() {
  return 2;
} 

constexpr inline Direction scopedEnum(_YGDirection unscoped) {
  return static_cast<Direction>(unscoped);
}

constexpr inline _YGDirection unscopedEnum(Direction scoped) {
  return static_cast<_YGDirection>(scoped);
}

inline const char* toString(Direction e) {
  return _YGDirectionToString(unscopedEnum(e));
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class MeasureMode : uint8_t {
  Undefined = _YGMeasureModeUndefined,
  Exactly = _YGMeasureModeExactly,
  AtMost = _YGMeasureModeAtMost,
};

template <>
constexpr inline int32_t ordinalCount<MeasureMode>() {
  return 3;
} 

template <>
constexpr inline int32_t bitCount<MeasureMode>() {
  return 2;
} 

constexpr inline MeasureMode scopedEnum(_YGMeasureMode unscoped) {
  return static_cast<MeasureMode>(unscoped);
}

constexpr inline _YGMeasureMode unscopedEnum(MeasureMode scoped) {
  return static_cast<_YGMeasureMode>(scoped);
}

inline const char* toString(MeasureMode e) {
  return _YGMeasureModeToString(unscopedEnum(e));
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class NodeType : uint8_t {
  Default = _YGNodeTypeDefault,
  Text = _YGNodeTypeText,
};

template <>
constexpr inline int32_t ordinalCount<NodeType>() {
  return 2;
} 

template <>
constexpr inline int32_t bitCount<NodeType>() {
  return 1;
} 

constexpr inline NodeType scopedEnum(_YGNodeType unscoped) {
  return static_cast<NodeType>(unscoped);
}

constexpr inline _YGNodeType unscopedEnum(NodeType scoped) {
  return static_cast<_YGNodeType>(scoped);
}

inline const char* toString(NodeType e) {
  return _YGNodeTypeToString(unscopedEnum(e));
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <array>

/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <bitset>
#include <cstdint>
#include <cstdio>
#include <type_traits>


namespace facebook::yoga::details {

constexpr uint8_t log2ceilFn(uint8_t n) {
  return n < 1 ? 0 : (1 + log2ceilFn(n / 2));
}

constexpr uint32_t mask(uint8_t bitWidth, uint8_t index) {
  return ((1u << bitWidth) - 1u) << index;
}

} // namespace facebook::yoga::details

namespace facebook::yoga {

// The number of bits necessary to represent enums defined with _YG_ENUM_SEQ_DECL
template <
    typename Enum,
    std::enable_if_t<(ordinalCount<Enum>() > 0), bool> = true>
constexpr uint8_t minimumBitCount() {
  return details::log2ceilFn(static_cast<uint8_t>(ordinalCount<Enum>() - 1));
}

template <typename Enum>
constexpr Enum getEnumData(uint32_t flags, uint8_t index) {
  return static_cast<Enum>(
      (flags & details::mask(minimumBitCount<Enum>(), index)) >> index);
}

template <typename Enum, typename Value>
void setEnumData(uint32_t& flags, uint8_t index, Value newValue) {
  flags =
      (flags &
       ~static_cast<uint32_t>(details::mask(minimumBitCount<Enum>(), index))) |
      ((static_cast<uint32_t>(newValue) << index) &
       (details::mask(minimumBitCount<Enum>(), index)));
}

constexpr bool getBooleanData(uint32_t flags, uint8_t index) {
  return (flags >> index) & 1;
}

inline void setBooleanData(uint32_t& flags, uint8_t index, bool value) {
  if (value) {
    flags |= 1 << index;
  } else {
    flags &= ~(1 << index);
  }
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <cmath>


/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <algorithm>
#include <array>
#include <cmath>


namespace facebook::yoga {

constexpr bool isUndefined(auto value) {
  return value != value;
}

constexpr bool isDefined(auto value) {
  return !isUndefined(value);
}

constexpr auto maxOrDefined(auto a, auto b) {
  if (yoga::isDefined(a) && yoga::isDefined(b)) {
    return std::max(a, b);
  }
  return yoga::isUndefined(a) ? b : a;
}

constexpr auto minOrDefined(auto a, auto b) {
  if (yoga::isDefined(a) && yoga::isDefined(b)) {
    return std::min(a, b);
  }

  return yoga::isUndefined(a) ? b : a;
}

// Custom equality functions using a hardcoded epsilon of 0.0001f, or returning
// true if both floats are NaN.
inline bool inexactEquals(float a, float b) {
  if (yoga::isDefined(a) && yoga::isDefined(b)) {
    return std::abs(a - b) < 0.0001f;
  }
  return yoga::isUndefined(a) && yoga::isUndefined(b);
}

inline bool inexactEquals(double a, double b) {
  if (yoga::isDefined(a) && yoga::isDefined(b)) {
    return std::abs(a - b) < 0.0001;
  }
  return yoga::isUndefined(a) && yoga::isUndefined(b);
}

inline bool inexactEquals(const _YGValue& a, const _YGValue& b) {
  if (a.unit != b.unit) {
    return false;
  }

  if (a.unit == _YGUnitUndefined ||
      (yoga::isUndefined(a.value) && yoga::isUndefined(b.value))) {
    return true;
  }

  return fabs(a.value - b.value) < 0.0001f;
}

template <std::size_t Size, typename ElementT>
bool inexactEquals(
    const std::array<ElementT, Size>& val1,
    const std::array<ElementT, Size>& val2) {
  bool areEqual = true;
  for (std::size_t i = 0; i < Size && areEqual; ++i) {
    areEqual = inexactEquals(val1[i], val2[i]);
  }
  return areEqual;
}

} // namespace facebook::yoga

namespace facebook::yoga {

struct CachedMeasurement {
  float availableWidth{-1};
  float availableHeight{-1};
  MeasureMode widthMeasureMode{MeasureMode::Undefined};
  MeasureMode heightMeasureMode{MeasureMode::Undefined};

  float computedWidth{-1};
  float computedHeight{-1};

  bool operator==(CachedMeasurement measurement) const {
    bool isEqual = widthMeasureMode == measurement.widthMeasureMode &&
        heightMeasureMode == measurement.heightMeasureMode;

    if (!yoga::isUndefined(availableWidth) ||
        !yoga::isUndefined(measurement.availableWidth)) {
      isEqual = isEqual && availableWidth == measurement.availableWidth;
    }
    if (!yoga::isUndefined(availableHeight) ||
        !yoga::isUndefined(measurement.availableHeight)) {
      isEqual = isEqual && availableHeight == measurement.availableHeight;
    }
    if (!yoga::isUndefined(computedWidth) ||
        !yoga::isUndefined(measurement.computedWidth)) {
      isEqual = isEqual && computedWidth == measurement.computedWidth;
    }
    if (!yoga::isUndefined(computedHeight) ||
        !yoga::isUndefined(measurement.computedHeight)) {
      isEqual = isEqual && computedHeight == measurement.computedHeight;
    }

    return isEqual;
  }
};

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <limits>

namespace facebook::yoga {

struct FloatOptional {
 private:
  float value_ = std::numeric_limits<float>::quiet_NaN();

 public:
  explicit constexpr FloatOptional(float value) : value_(value) {}
  constexpr FloatOptional() = default;

  // returns the wrapped value, or a value x with _YGIsUndefined(x) == true
  constexpr float unwrap() const {
    return value_;
  }

  constexpr float unwrapOrDefault(float defaultValue) const {
    return isUndefined() ? defaultValue : value_;
  }

  constexpr bool isUndefined() const {
    return yoga::isUndefined(value_);
  }

  constexpr bool isDefined() const {
    return yoga::isDefined(value_);
  }
};

// operators take FloatOptional by value, as it is a 32bit value

constexpr bool operator==(FloatOptional lhs, FloatOptional rhs) {
  return lhs.unwrap() == rhs.unwrap() ||
      (lhs.isUndefined() && rhs.isUndefined());
}
constexpr bool operator!=(FloatOptional lhs, FloatOptional rhs) {
  return !(lhs == rhs);
}

constexpr bool operator==(FloatOptional lhs, float rhs) {
  return lhs == FloatOptional{rhs};
}
constexpr bool operator!=(FloatOptional lhs, float rhs) {
  return !(lhs == rhs);
}

constexpr bool operator==(float lhs, FloatOptional rhs) {
  return rhs == lhs;
}
constexpr bool operator!=(float lhs, FloatOptional rhs) {
  return !(lhs == rhs);
}

constexpr FloatOptional operator+(FloatOptional lhs, FloatOptional rhs) {
  return FloatOptional{lhs.unwrap() + rhs.unwrap()};
}

constexpr bool operator>(FloatOptional lhs, FloatOptional rhs) {
  return lhs.unwrap() > rhs.unwrap();
}

constexpr bool operator<(FloatOptional lhs, FloatOptional rhs) {
  return lhs.unwrap() < rhs.unwrap();
}

constexpr bool operator>=(FloatOptional lhs, FloatOptional rhs) {
  return lhs > rhs || lhs == rhs;
}

constexpr bool operator<=(FloatOptional lhs, FloatOptional rhs) {
  return lhs < rhs || lhs == rhs;
}

constexpr FloatOptional maxOrDefined(FloatOptional lhs, FloatOptional rhs) {
  return FloatOptional{yoga::maxOrDefined(lhs.unwrap(), rhs.unwrap())};
}

inline bool inexactEquals(FloatOptional lhs, FloatOptional rhs) {
  return yoga::inexactEquals(lhs.unwrap(), rhs.unwrap());
}

} // namespace facebook::yoga

namespace facebook::yoga {

struct LayoutResults {
  // This value was chosen based on empirical data:
  // 98% of analyzed layouts require less than 8 entries.
  static constexpr int32_t MaxCachedMeasurements = 8;

  std::array<float, 4> position = {};
  std::array<float, 4> margin = {};
  std::array<float, 4> border = {};
  std::array<float, 4> padding = {};

 private:
  Direction direction_ : bitCount<Direction>() = Direction::Inherit;
  bool hadOverflow_ : 1 = false;

  std::array<float, 2> dimensions_ = {{_YGUndefined, _YGUndefined}};
  std::array<float, 2> measuredDimensions_ = {{_YGUndefined, _YGUndefined}};

 public:
  uint32_t computedFlexBasisGeneration = 0;
  FloatOptional computedFlexBasis = {};

  // Instead of recomputing the entire layout every single time, we cache some
  // information to break early when nothing changed
  uint32_t generationCount = 0;
  Direction lastOwnerDirection = Direction::Inherit;

  uint32_t nextCachedMeasurementsIndex = 0;
  std::array<CachedMeasurement, MaxCachedMeasurements> cachedMeasurements = {};

  CachedMeasurement cachedLayout{};

  Direction direction() const {
    return direction_;
  }

  void setDirection(Direction direction) {
    direction_ = direction;
  }

  bool hadOverflow() const {
    return hadOverflow_;
  }

  void setHadOverflow(bool hadOverflow) {
    hadOverflow_ = hadOverflow;
  }

  float dimension(Dimension axis) const {
    return dimensions_[yoga::to_underlying(axis)];
  }

  void setDimension(Dimension axis, float dimension) {
    dimensions_[yoga::to_underlying(axis)] = dimension;
  }

  float measuredDimension(Dimension axis) const {
    return measuredDimensions_[yoga::to_underlying(axis)];
  }

  void setMeasuredDimension(Dimension axis, float dimension) {
    measuredDimensions_[yoga::to_underlying(axis)] = dimension;
  }

  bool operator==(LayoutResults layout) const;
  bool operator!=(LayoutResults layout) const {
    return !(*this == layout);
  }
};

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <cmath>
#include <cstdint>
#include <limits>


/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <cstring>
#include <type_traits>

namespace facebook::yoga {

// Polyfill for std::bit_cast() from C++20, to allow safe type punning
// https://en.cppreference.com/w/cpp/numeric/bit_cast
// TODO: Remove when we upgrade to NDK 26+
template <class To, class From>
std::enable_if_t<
    sizeof(To) == sizeof(From) && std::is_trivially_copyable_v<From> &&
        std::is_trivially_copyable_v<To> &&
        std::is_trivially_constructible_v<To>,
    To>
bit_cast(const From& src) noexcept {
  To dst;
  std::memcpy(&dst, &src, sizeof(To));
  return dst;
}

} // namespace facebook::yoga

static_assert(
    std::numeric_limits<float>::is_iec559,
    "facebook::yoga::detail::CompactValue only works with IEEE754 floats");

#ifdef YOGA_COMPACT_VALUE_TEST
#define VISIBLE_FOR_TESTING public:
#else
#define VISIBLE_FOR_TESTING private:
#endif

namespace facebook::yoga {

// This class stores _YGValue in 32 bits.
// - The value does not matter for Undefined and Auto. NaNs are used for their
//   representation.
// - To differentiate between Point and Percent, one exponent bit is used.
//   Supported the range [0x40, 0xbf] (0xbf is inclusive for point, but
//   exclusive for percent).
// - Value ranges:
//   points:  1.08420217e-19f to 36893485948395847680
//            0x00000000         0x3fffffff
//   percent: 1.08420217e-19f to 18446742974197923840
//            0x40000000         0x7f7fffff
// - Zero is supported, negative zero is not
// - values outside of the representable range are clamped
class _YG_EXPORT CompactValue {
  friend constexpr bool operator==(CompactValue, CompactValue) noexcept;

 public:
  static constexpr auto LOWER_BOUND = 1.08420217e-19f;
  static constexpr auto UPPER_BOUND_POINT = 36893485948395847680.0f;
  static constexpr auto UPPER_BOUND_PERCENT = 18446742974197923840.0f;

  template <_YGUnit Unit>
  static CompactValue of(float value) noexcept {
    if (value == 0.0f || (value < LOWER_BOUND && value > -LOWER_BOUND)) {
      constexpr auto zero =
          Unit == _YGUnitPercent ? ZERO_BITS_PERCENT : ZERO_BITS_POINT;
      return {zero};
    }

    constexpr auto upperBound =
        Unit == _YGUnitPercent ? UPPER_BOUND_PERCENT : UPPER_BOUND_POINT;
    if (value > upperBound || value < -upperBound) {
      value = copysignf(upperBound, value);
    }

    uint32_t unitBit = Unit == _YGUnitPercent ? PERCENT_BIT : 0;
    auto data = yoga::bit_cast<uint32_t>(value);
    data -= BIAS;
    data |= unitBit;
    return {data};
  }

  template <_YGUnit Unit>
  static CompactValue ofMaybe(float value) noexcept {
    return std::isnan(value) || std::isinf(value) ? ofUndefined()
                                                  : of<Unit>(value);
  }

  static constexpr CompactValue ofZero() noexcept {
    return CompactValue{ZERO_BITS_POINT};
  }

  static constexpr CompactValue ofUndefined() noexcept {
    return CompactValue{};
  }

  static constexpr CompactValue ofAuto() noexcept {
    return CompactValue{AUTO_BITS};
  }

  constexpr CompactValue() noexcept : repr_(0x7FC00000) {}

  CompactValue(const _YGValue& x) noexcept : repr_(uint32_t{0}) {
    switch (x.unit) {
      case _YGUnitUndefined:
        *this = ofUndefined();
        break;
      case _YGUnitAuto:
        *this = ofAuto();
        break;
      case _YGUnitPoint:
        *this = of<_YGUnitPoint>(x.value);
        break;
      case _YGUnitPercent:
        *this = of<_YGUnitPercent>(x.value);
        break;
    }
  }

  operator _YGValue() const noexcept {
    switch (repr_) {
      case AUTO_BITS:
        return _YGValueAuto;
      case ZERO_BITS_POINT:
        return _YGValue{0.0f, _YGUnitPoint};
      case ZERO_BITS_PERCENT:
        return _YGValue{0.0f, _YGUnitPercent};
    }

    if (std::isnan(yoga::bit_cast<float>(repr_))) {
      return _YGValueUndefined;
    }

    auto data = repr_;
    data &= ~PERCENT_BIT;
    data += BIAS;

    return _YGValue{
        yoga::bit_cast<float>(data),
        repr_ & 0x40000000 ? _YGUnitPercent : _YGUnitPoint};
  }

  bool isUndefined() const noexcept {
    return (
        repr_ != AUTO_BITS && repr_ != ZERO_BITS_POINT &&
        repr_ != ZERO_BITS_PERCENT && std::isnan(yoga::bit_cast<float>(repr_)));
  }

  bool isDefined() const noexcept {
    return !isUndefined();
  }

  bool isAuto() const noexcept {
    return repr_ == AUTO_BITS;
  }

 private:
  uint32_t repr_;

  static constexpr uint32_t BIAS = 0x20000000;
  static constexpr uint32_t PERCENT_BIT = 0x40000000;

  // these are signaling NaNs with specific bit pattern as payload they will be
  // silenced whenever going through an FPU operation on ARM + x86
  static constexpr uint32_t AUTO_BITS = 0x7faaaaaa;
  static constexpr uint32_t ZERO_BITS_POINT = 0x7f8f0f0f;
  static constexpr uint32_t ZERO_BITS_PERCENT = 0x7f80f0f0;

  constexpr CompactValue(uint32_t data) noexcept : repr_(data) {}

  VISIBLE_FOR_TESTING uint32_t repr() {
    return repr_;
  }
};

template <>
CompactValue CompactValue::of<_YGUnitUndefined>(float) noexcept = delete;
template <>
CompactValue CompactValue::of<_YGUnitAuto>(float) noexcept = delete;
template <>
CompactValue CompactValue::ofMaybe<_YGUnitUndefined>(float) noexcept = delete;
template <>
CompactValue CompactValue::ofMaybe<_YGUnitAuto>(float) noexcept = delete;

constexpr bool operator==(CompactValue a, CompactValue b) noexcept {
  return a.repr_ == b.repr_;
}

constexpr bool operator!=(CompactValue a, CompactValue b) noexcept {
  return !(a == b);
}

inline bool inexactEquals(CompactValue a, CompactValue b) {
  return inexactEquals((_YGValue)a, (_YGValue)b);
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <algorithm>
#include <array>
#include <cstdint>
#include <type_traits>


/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class Align : uint8_t {
  Auto = _YGAlignAuto,
  FlexStart = _YGAlignFlexStart,
  Center = _YGAlignCenter,
  FlexEnd = _YGAlignFlexEnd,
  Stretch = _YGAlignStretch,
  Baseline = _YGAlignBaseline,
  SpaceBetween = _YGAlignSpaceBetween,
  SpaceAround = _YGAlignSpaceAround,
  SpaceEvenly = _YGAlignSpaceEvenly,
};

template <>
constexpr inline int32_t ordinalCount<Align>() {
  return 9;
} 

template <>
constexpr inline int32_t bitCount<Align>() {
  return 4;
} 

constexpr inline Align scopedEnum(_YGAlign unscoped) {
  return static_cast<Align>(unscoped);
}

constexpr inline _YGAlign unscopedEnum(Align scoped) {
  return static_cast<_YGAlign>(scoped);
}

inline const char* toString(Align e) {
  return _YGAlignToString(unscopedEnum(e));
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class Display : uint8_t {
  Flex = _YGDisplayFlex,
  None = _YGDisplayNone,
};

template <>
constexpr inline int32_t ordinalCount<Display>() {
  return 2;
} 

template <>
constexpr inline int32_t bitCount<Display>() {
  return 1;
} 

constexpr inline Display scopedEnum(_YGDisplay unscoped) {
  return static_cast<Display>(unscoped);
}

constexpr inline _YGDisplay unscopedEnum(Display scoped) {
  return static_cast<_YGDisplay>(scoped);
}

inline const char* toString(Display e) {
  return _YGDisplayToString(unscopedEnum(e));
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class Edge : uint8_t {
  Left = _YGEdgeLeft,
  Top = _YGEdgeTop,
  Right = _YGEdgeRight,
  Bottom = _YGEdgeBottom,
  Start = _YGEdgeStart,
  End = _YGEdgeEnd,
  Horizontal = _YGEdgeHorizontal,
  Vertical = _YGEdgeVertical,
  All = _YGEdgeAll,
};

template <>
constexpr inline int32_t ordinalCount<Edge>() {
  return 9;
} 

template <>
constexpr inline int32_t bitCount<Edge>() {
  return 4;
} 

constexpr inline Edge scopedEnum(_YGEdge unscoped) {
  return static_cast<Edge>(unscoped);
}

constexpr inline _YGEdge unscopedEnum(Edge scoped) {
  return static_cast<_YGEdge>(scoped);
}

inline const char* toString(Edge e) {
  return _YGEdgeToString(unscopedEnum(e));
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class FlexDirection : uint8_t {
  Column = _YGFlexDirectionColumn,
  ColumnReverse = _YGFlexDirectionColumnReverse,
  Row = _YGFlexDirectionRow,
  RowReverse = _YGFlexDirectionRowReverse,
};

template <>
constexpr inline int32_t ordinalCount<FlexDirection>() {
  return 4;
} 

template <>
constexpr inline int32_t bitCount<FlexDirection>() {
  return 2;
} 

constexpr inline FlexDirection scopedEnum(_YGFlexDirection unscoped) {
  return static_cast<FlexDirection>(unscoped);
}

constexpr inline _YGFlexDirection unscopedEnum(FlexDirection scoped) {
  return static_cast<_YGFlexDirection>(scoped);
}

inline const char* toString(FlexDirection e) {
  return _YGFlexDirectionToString(unscopedEnum(e));
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class Gutter : uint8_t {
  Column = _YGGutterColumn,
  Row = _YGGutterRow,
  All = _YGGutterAll,
};

template <>
constexpr inline int32_t ordinalCount<Gutter>() {
  return 3;
} 

template <>
constexpr inline int32_t bitCount<Gutter>() {
  return 2;
} 

constexpr inline Gutter scopedEnum(_YGGutter unscoped) {
  return static_cast<Gutter>(unscoped);
}

constexpr inline _YGGutter unscopedEnum(Gutter scoped) {
  return static_cast<_YGGutter>(scoped);
}

inline const char* toString(Gutter e) {
  return _YGGutterToString(unscopedEnum(e));
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class Justify : uint8_t {
  FlexStart = _YGJustifyFlexStart,
  Center = _YGJustifyCenter,
  FlexEnd = _YGJustifyFlexEnd,
  SpaceBetween = _YGJustifySpaceBetween,
  SpaceAround = _YGJustifySpaceAround,
  SpaceEvenly = _YGJustifySpaceEvenly,
};

template <>
constexpr inline int32_t ordinalCount<Justify>() {
  return 6;
} 

template <>
constexpr inline int32_t bitCount<Justify>() {
  return 3;
} 

constexpr inline Justify scopedEnum(_YGJustify unscoped) {
  return static_cast<Justify>(unscoped);
}

constexpr inline _YGJustify unscopedEnum(Justify scoped) {
  return static_cast<_YGJustify>(scoped);
}

inline const char* toString(Justify e) {
  return _YGJustifyToString(unscopedEnum(e));
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class Overflow : uint8_t {
  Visible = _YGOverflowVisible,
  Hidden = _YGOverflowHidden,
  Scroll = _YGOverflowScroll,
};

template <>
constexpr inline int32_t ordinalCount<Overflow>() {
  return 3;
} 

template <>
constexpr inline int32_t bitCount<Overflow>() {
  return 2;
} 

constexpr inline Overflow scopedEnum(_YGOverflow unscoped) {
  return static_cast<Overflow>(unscoped);
}

constexpr inline _YGOverflow unscopedEnum(Overflow scoped) {
  return static_cast<_YGOverflow>(scoped);
}

inline const char* toString(Overflow e) {
  return _YGOverflowToString(unscopedEnum(e));
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class PositionType : uint8_t {
  Static = _YGPositionTypeStatic,
  Relative = _YGPositionTypeRelative,
  Absolute = _YGPositionTypeAbsolute,
};

template <>
constexpr inline int32_t ordinalCount<PositionType>() {
  return 3;
} 

template <>
constexpr inline int32_t bitCount<PositionType>() {
  return 2;
} 

constexpr inline PositionType scopedEnum(_YGPositionType unscoped) {
  return static_cast<PositionType>(unscoped);
}

constexpr inline _YGPositionType unscopedEnum(PositionType scoped) {
  return static_cast<_YGPositionType>(scoped);
}

inline const char* toString(PositionType e) {
  return _YGPositionTypeToString(unscopedEnum(e));
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class Wrap : uint8_t {
  NoWrap = _YGWrapNoWrap,
  Wrap = _YGWrapWrap,
  WrapReverse = _YGWrapWrapReverse,
};

template <>
constexpr inline int32_t ordinalCount<Wrap>() {
  return 3;
} 

template <>
constexpr inline int32_t bitCount<Wrap>() {
  return 2;
} 

constexpr inline Wrap scopedEnum(_YGWrap unscoped) {
  return static_cast<Wrap>(unscoped);
}

constexpr inline _YGWrap unscopedEnum(Wrap scoped) {
  return static_cast<_YGWrap>(scoped);
}

inline const char* toString(Wrap e) {
  return _YGWrapToString(unscopedEnum(e));
}

} // namespace facebook::yoga

namespace facebook::yoga {

class _YG_EXPORT Style {
  template <typename Enum>
  using Values = std::array<CompactValue, ordinalCount<Enum>()>;

  using Dimensions = Values<Dimension>;
  using Edges = Values<_YGEdge>;
  using Gutters = Values<Gutter>;

 public:
  static constexpr float DefaultFlexGrow = 0.0f;
  static constexpr float DefaultFlexShrink = 0.0f;
  static constexpr float WebDefaultFlexShrink = 1.0f;

  template <typename T>
  struct BitfieldRef {
    Style& style;
    uint8_t offset;
    operator T() const {
      return getEnumData<T>(style.flags, offset);
    }
    BitfieldRef<T>& operator=(T x) {
      setEnumData<T>(style.flags, offset, x);
      return *this;
    }
  };

  template <typename T, T Style::*Prop>
  struct Ref {
    Style& style;
    operator T() const {
      return style.*Prop;
    }
    Ref<T, Prop>& operator=(T value) {
      style.*Prop = value;
      return *this;
    }
  };

  Style() {
    alignContent() = Align::FlexStart;
    alignItems() = Align::Stretch;
  }
  ~Style() = default;

 private:
  static constexpr uint8_t directionOffset = 0;
  static constexpr uint8_t flexdirectionOffset =
      directionOffset + minimumBitCount<Direction>();
  static constexpr uint8_t justifyContentOffset =
      flexdirectionOffset + minimumBitCount<FlexDirection>();
  static constexpr uint8_t alignContentOffset =
      justifyContentOffset + minimumBitCount<Justify>();
  static constexpr uint8_t alignItemsOffset =
      alignContentOffset + minimumBitCount<Align>();
  static constexpr uint8_t alignSelfOffset =
      alignItemsOffset + minimumBitCount<Align>();
  static constexpr uint8_t positionTypeOffset =
      alignSelfOffset + minimumBitCount<Align>();
  static constexpr uint8_t flexWrapOffset =
      positionTypeOffset + minimumBitCount<PositionType>();
  static constexpr uint8_t overflowOffset =
      flexWrapOffset + minimumBitCount<Wrap>();
  static constexpr uint8_t displayOffset =
      overflowOffset + minimumBitCount<Overflow>();

  uint32_t flags = 0;

  FloatOptional flex_ = {};
  FloatOptional flexGrow_ = {};
  FloatOptional flexShrink_ = {};
  CompactValue flexBasis_ = CompactValue::ofAuto();
  Edges margin_ = {};
  Edges position_ = {};
  Edges padding_ = {};
  Edges border_ = {};
  Gutters gap_ = {};
  Dimensions dimensions_{CompactValue::ofAuto(), CompactValue::ofAuto()};
  Dimensions minDimensions_ = {};
  Dimensions maxDimensions_ = {};
  // Yoga specific properties, not compatible with flexbox specification
  FloatOptional aspectRatio_ = {};

 public:
  Direction direction() const {
    return getEnumData<Direction>(flags, directionOffset);
  }
  BitfieldRef<Direction> direction() {
    return {*this, directionOffset};
  }

  FlexDirection flexDirection() const {
    return getEnumData<FlexDirection>(flags, flexdirectionOffset);
  }
  BitfieldRef<FlexDirection> flexDirection() {
    return {*this, flexdirectionOffset};
  }

  Justify justifyContent() const {
    return getEnumData<Justify>(flags, justifyContentOffset);
  }
  BitfieldRef<Justify> justifyContent() {
    return {*this, justifyContentOffset};
  }

  Align alignContent() const {
    return getEnumData<Align>(flags, alignContentOffset);
  }
  BitfieldRef<Align> alignContent() {
    return {*this, alignContentOffset};
  }

  Align alignItems() const {
    return getEnumData<Align>(flags, alignItemsOffset);
  }
  BitfieldRef<Align> alignItems() {
    return {*this, alignItemsOffset};
  }

  Align alignSelf() const {
    return getEnumData<Align>(flags, alignSelfOffset);
  }
  BitfieldRef<Align> alignSelf() {
    return {*this, alignSelfOffset};
  }

  PositionType positionType() const {
    return getEnumData<PositionType>(flags, positionTypeOffset);
  }
  BitfieldRef<PositionType> positionType() {
    return {*this, positionTypeOffset};
  }

  Wrap flexWrap() const {
    return getEnumData<Wrap>(flags, flexWrapOffset);
  }
  BitfieldRef<Wrap> flexWrap() {
    return {*this, flexWrapOffset};
  }

  Overflow overflow() const {
    return getEnumData<Overflow>(flags, overflowOffset);
  }
  BitfieldRef<Overflow> overflow() {
    return {*this, overflowOffset};
  }

  Display display() const {
    return getEnumData<Display>(flags, displayOffset);
  }
  BitfieldRef<Display> display() {
    return {*this, displayOffset};
  }

  FloatOptional flex() const {
    return flex_;
  }
  Ref<FloatOptional, &Style::flex_> flex() {
    return {*this};
  }

  FloatOptional flexGrow() const {
    return flexGrow_;
  }
  Ref<FloatOptional, &Style::flexGrow_> flexGrow() {
    return {*this};
  }

  FloatOptional flexShrink() const {
    return flexShrink_;
  }
  Ref<FloatOptional, &Style::flexShrink_> flexShrink() {
    return {*this};
  }

  CompactValue flexBasis() const {
    return flexBasis_;
  }
  Ref<CompactValue, &Style::flexBasis_> flexBasis() {
    return {*this};
  }

  CompactValue margin(_YGEdge edge) const {
    return margin_[edge];
  }
  void setMargin(_YGEdge edge, CompactValue value) {
    margin_[edge] = value;
  }

  CompactValue position(_YGEdge edge) const {
    return position_[edge];
  }
  void setPosition(_YGEdge edge, CompactValue value) {
    position_[edge] = value;
  }

  CompactValue padding(_YGEdge edge) const {
    return padding_[edge];
  }
  void setPadding(_YGEdge edge, CompactValue value) {
    padding_[edge] = value;
  }

  CompactValue border(_YGEdge edge) const {
    return border_[edge];
  }
  void setBorder(_YGEdge edge, CompactValue value) {
    border_[edge] = value;
  }

  CompactValue gap(Gutter gutter) const {
    return gap_[yoga::to_underlying(gutter)];
  }
  void setGap(Gutter gutter, CompactValue value) {
    gap_[yoga::to_underlying(gutter)] = value;
  }

  CompactValue dimension(Dimension axis) const {
    return dimensions_[yoga::to_underlying(axis)];
  }
  void setDimension(Dimension axis, CompactValue value) {
    dimensions_[yoga::to_underlying(axis)] = value;
  }

  CompactValue minDimension(Dimension axis) const {
    return minDimensions_[yoga::to_underlying(axis)];
  }
  void setMinDimension(Dimension axis, CompactValue value) {
    minDimensions_[yoga::to_underlying(axis)] = value;
  }

  CompactValue maxDimension(Dimension axis) const {
    return maxDimensions_[yoga::to_underlying(axis)];
  }
  void setMaxDimension(Dimension axis, CompactValue value) {
    maxDimensions_[yoga::to_underlying(axis)] = value;
  }

  // Yoga specific properties, not compatible with flexbox specification
  FloatOptional aspectRatio() const {
    return aspectRatio_;
  }
  Ref<FloatOptional, &Style::aspectRatio_> aspectRatio() {
    return {*this};
  }

  CompactValue resolveColumnGap() const {
    if (gap_[yoga::to_underlying(Gutter::Column)].isDefined()) {
      return gap_[yoga::to_underlying(Gutter::Column)];
    } else {
      return gap_[yoga::to_underlying(Gutter::All)];
    }
  }

  CompactValue resolveRowGap() const {
    if (gap_[yoga::to_underlying(Gutter::Row)].isDefined()) {
      return gap_[yoga::to_underlying(Gutter::Row)];
    } else {
      return gap_[yoga::to_underlying(Gutter::All)];
    }
  }

  bool operator==(const Style& other) const {
    return flags == other.flags && inexactEquals(flex_, other.flex_) &&
        inexactEquals(flexGrow_, other.flexGrow_) &&
        inexactEquals(flexShrink_, other.flexShrink_) &&
        inexactEquals(flexBasis_, other.flexBasis_) &&
        inexactEquals(margin_, other.margin_) &&
        inexactEquals(position_, other.position_) &&
        inexactEquals(padding_, other.padding_) &&
        inexactEquals(border_, other.border_) &&
        inexactEquals(gap_, other.gap_) &&
        inexactEquals(dimensions_, other.dimensions_) &&
        inexactEquals(minDimensions_, other.minDimensions_) &&
        inexactEquals(maxDimensions_, other.maxDimensions_) &&
        inexactEquals(aspectRatio_, other.aspectRatio_);
  }

  bool operator!=(const Style& other) const {
    return !(*this == other);
  }
};

} // namespace facebook::yoga

// Tag struct used to form the opaque _YGNodeRef for the public C API
struct _YGNode {};

namespace facebook::yoga {

class _YG_EXPORT Node : public ::_YGNode {
 private:
  bool hasNewLayout_ : 1 = true;
  bool isReferenceBaseline_ : 1 = false;
  bool isDirty_ : 1 = false;
  NodeType nodeType_ : bitCount<NodeType>() = NodeType::Default;
  void* context_ = nullptr;
  _YGMeasureFunc measureFunc_ = {nullptr};
  _YGBaselineFunc baselineFunc_ = {nullptr};
  _YGPrintFunc printFunc_ = {nullptr};
  _YGDirtiedFunc dirtiedFunc_ = nullptr;
  Style style_ = {};
  LayoutResults layout_ = {};
  size_t lineIndex_ = 0;
  Node* owner_ = nullptr;
  std::vector<Node*> children_ = {};
  const Config* config_;
  std::array<_YGValue, 2> resolvedDimensions_ = {
      {_YGValueUndefined, _YGValueUndefined}};

  float relativePosition(
      FlexDirection axis,
      Direction direction,
      const float axisSize) const;

  _YGEdge getInlineStartEdgeUsingErrata(
      FlexDirection flexDirection,
      Direction direction) const;
  _YGEdge getInlineEndEdgeUsingErrata(
      FlexDirection flexDirection,
      Direction direction) const;

  void useWebDefaults() {
    style_.flexDirection() = FlexDirection::Row;
    style_.alignContent() = Align::Stretch;
  }

  template <auto Field>
  CompactValue computeEdgeValueForColumn(_YGEdge edge) const;

  template <auto Field>
  CompactValue computeEdgeValueForRow(_YGEdge rowEdge, _YGEdge edge) const;

  // DANGER DANGER DANGER!
  // If the node assigned to has children, we'd either have to deallocate
  // them (potentially incorrect) or ignore them (danger of leaks). Only ever
  // use this after checking that there are no children.
  // DO NOT CHANGE THE VISIBILITY OF THIS METHOD!
  Node& operator=(Node&&) = default;

 public:
  Node();
  explicit Node(const Config* config);
  ~Node() = default; // cleanup of owner/children relationships in _YGNodeFree

  Node(Node&&);

  // Does not expose true value semantics, as children are not cloned eagerly.
  // Should we remove this?
  Node(const Node& node) = default;

  // assignment means potential leaks of existing children, or alternatively
  // freeing unowned memory, double free, or freeing stack memory.
  Node& operator=(const Node&) = delete;

  // Getters
  void* getContext() const {
    return context_;
  }

  void print();

  bool getHasNewLayout() const {
    return hasNewLayout_;
  }

  NodeType getNodeType() const {
    return nodeType_;
  }

  bool hasMeasureFunc() const noexcept {
    return measureFunc_ != nullptr;
  }

  _YGSize measure(float, MeasureMode, float, MeasureMode);

  bool hasBaselineFunc() const noexcept {
    return baselineFunc_ != nullptr;
  }

  float baseline(float width, float height) const;

  bool hasErrata(Errata errata) const {
    return config_->hasErrata(errata);
  }

  _YGDirtiedFunc getDirtiedFunc() const {
    return dirtiedFunc_;
  }

  // For Performance reasons passing as reference.
  Style& getStyle() {
    return style_;
  }

  const Style& getStyle() const {
    return style_;
  }

  // For Performance reasons passing as reference.
  LayoutResults& getLayout() {
    return layout_;
  }

  const LayoutResults& getLayout() const {
    return layout_;
  }

  size_t getLineIndex() const {
    return lineIndex_;
  }

  bool isReferenceBaseline() const {
    return isReferenceBaseline_;
  }

  // returns the Node that owns this Node. An owner is used to identify
  // the YogaTree that a Node belongs to. This method will return the parent
  // of the Node when a Node only belongs to one YogaTree or nullptr when
  // the Node is shared between two or more YogaTrees.
  Node* getOwner() const {
    return owner_;
  }

  // Deprecated, use getOwner() instead.
  Node* getParent() const {
    return getOwner();
  }

  const std::vector<Node*>& getChildren() const {
    return children_;
  }

  Node* getChild(size_t index) const {
    return children_.at(index);
  }

  size_t getChildCount() const {
    return children_.size();
  }

  const Config* getConfig() const {
    return config_;
  }

  bool isDirty() const {
    return isDirty_;
  }

  std::array<_YGValue, 2> getResolvedDimensions() const {
    return resolvedDimensions_;
  }

  _YGValue getResolvedDimension(Dimension dimension) const {
    return resolvedDimensions_[static_cast<size_t>(dimension)];
  }

  // Methods related to positions, margin, padding and border
  bool isFlexStartPositionDefined(FlexDirection axis) const;
  bool isInlineStartPositionDefined(FlexDirection axis, Direction direction)
      const;
  bool isFlexEndPositionDefined(FlexDirection axis) const;
  bool isInlineEndPositionDefined(FlexDirection axis, Direction direction)
      const;
  float getFlexStartPosition(FlexDirection axis, float axisSize) const;
  float getInlineStartPosition(
      FlexDirection axis,
      Direction direction,
      float axisSize) const;
  float getFlexEndPosition(FlexDirection axis, float axisSize) const;
  float getInlineEndPosition(
      FlexDirection axis,
      Direction direction,
      float axisSize) const;
  float getFlexStartMargin(FlexDirection axis, float widthSize) const;
  float getInlineStartMargin(
      FlexDirection axis,
      Direction direction,
      float widthSize) const;
  float getFlexEndMargin(FlexDirection axis, float widthSize) const;
  float getInlineEndMargin(
      FlexDirection axis,
      Direction direction,
      float widthSize) const;
  float getFlexStartBorder(FlexDirection flexDirection, Direction direction)
      const;
  float getInlineStartBorder(FlexDirection flexDirection, Direction direction)
      const;
  float getFlexEndBorder(FlexDirection flexDirection, Direction direction)
      const;
  float getInlineEndBorder(FlexDirection flexDirection, Direction direction)
      const;
  float getFlexStartPadding(
      FlexDirection axis,
      Direction direction,
      float widthSize) const;
  float getInlineStartPadding(
      FlexDirection axis,
      Direction direction,
      float widthSize) const;
  float getFlexEndPadding(
      FlexDirection axis,
      Direction direction,
      float widthSize) const;
  float getInlineEndPadding(
      FlexDirection axis,
      Direction direction,
      float widthSize) const;
  float getFlexStartPaddingAndBorder(
      FlexDirection axis,
      Direction direction,
      float widthSize) const;
  float getInlineStartPaddingAndBorder(
      FlexDirection axis,
      Direction direction,
      float widthSize) const;
  float getFlexEndPaddingAndBorder(
      FlexDirection axis,
      Direction direction,
      float widthSize) const;
  float getInlineEndPaddingAndBorder(
      FlexDirection axis,
      Direction direction,
      float widthSize) const;
  float getMarginForAxis(FlexDirection axis, float widthSize) const;
  float getGapForAxis(FlexDirection axis) const;
  // Setters

  void setContext(void* context) {
    context_ = context;
  }

  void setPrintFunc(_YGPrintFunc printFunc) {
    printFunc_ = printFunc;
  }

  void setHasNewLayout(bool hasNewLayout) {
    hasNewLayout_ = hasNewLayout;
  }

  void setNodeType(NodeType nodeType) {
    nodeType_ = nodeType;
  }

  void setMeasureFunc(_YGMeasureFunc measureFunc);

  void setBaselineFunc(_YGBaselineFunc baseLineFunc) {
    baselineFunc_ = baseLineFunc;
  }

  void setDirtiedFunc(_YGDirtiedFunc dirtiedFunc) {
    dirtiedFunc_ = dirtiedFunc;
  }

  void setStyle(const Style& style) {
    style_ = style;
  }

  void setLayout(const LayoutResults& layout) {
    layout_ = layout;
  }

  void setLineIndex(size_t lineIndex) {
    lineIndex_ = lineIndex;
  }

  void setIsReferenceBaseline(bool isReferenceBaseline) {
    isReferenceBaseline_ = isReferenceBaseline;
  }

  void setOwner(Node* owner) {
    owner_ = owner;
  }

  void setChildren(const std::vector<Node*>& children) {
    children_ = children;
  }

  // TODO: rvalue override for setChildren

  void setConfig(Config* config);

  void setDirty(bool isDirty);
  void setLayoutLastOwnerDirection(Direction direction);
  void setLayoutComputedFlexBasis(const FloatOptional computedFlexBasis);
  void setLayoutComputedFlexBasisGeneration(
      uint32_t computedFlexBasisGeneration);
  void setLayoutMeasuredDimension(float measuredDimension, Dimension dimension);
  void setLayoutHadOverflow(bool hadOverflow);
  void setLayoutDimension(float dimensionValue, Dimension dimension);
  void setLayoutDirection(Direction direction);
  void setLayoutMargin(float margin, _YGEdge edge);
  void setLayoutBorder(float border, _YGEdge edge);
  void setLayoutPadding(float padding, _YGEdge edge);
  void setLayoutPosition(float position, _YGEdge edge);
  void setPosition(
      const Direction direction,
      const float mainSize,
      const float crossSize,
      const float ownerWidth);

  // Other methods
  _YGValue getFlexStartMarginValue(FlexDirection axis) const;
  _YGValue marginTrailingValue(FlexDirection axis) const;
  _YGValue resolveFlexBasisPtr() const;
  void resolveDimension();
  Direction resolveDirection(const Direction ownerDirection);
  void clearChildren();
  /// Replaces the occurrences of oldChild with newChild
  void replaceChild(Node* oldChild, Node* newChild);
  void replaceChild(Node* child, size_t index);
  void insertChild(Node* child, size_t index);
  /// Removes the first occurrence of child
  bool removeChild(Node* child);
  void removeChild(size_t index);

  void cloneChildrenIfNeeded();
  void markDirtyAndPropagate();
  float resolveFlexGrow() const;
  float resolveFlexShrink() const;
  bool isNodeFlexible();
  void reset();
};

inline Node* resolveRef(const _YGNodeRef ref) {
  return static_cast<Node*>(ref);
}

inline const Node* resolveRef(const _YGNodeConstRef ref) {
  return static_cast<const Node*>(ref);
}

} // namespace facebook::yoga

namespace facebook::yoga {

[[noreturn]] void fatalWithMessage(const char* message);

void assertFatal(bool condition, const char* message);
void assertFatalWithNode(
    const yoga::Node* node,
    bool condition,
    const char* message);
void assertFatalWithConfig(
    const yoga::Config* config,
    bool condition,
    const char* message);

} // namespace facebook::yoga

using namespace facebook;
using namespace facebook::yoga;

namespace {

template <typename T, typename NeedsUpdate, typename Update>
void updateStyle(
    yoga::Node* node,
    T value,
    NeedsUpdate&& needsUpdate,
    Update&& update) {
  if (needsUpdate(node->getStyle(), value)) {
    update(node->getStyle(), value);
    node->markDirtyAndPropagate();
  }
}

template <typename Ref, typename T>
void updateStyle(_YGNodeRef node, Ref (Style::*prop)(), T value) {
  updateStyle(
      resolveRef(node),
      value,
      [prop](Style& s, T x) { return (s.*prop)() != x; },
      [prop](Style& s, T x) { (s.*prop)() = x; });
}

template <auto GetterT, auto SetterT, typename IdxT>
void updateIndexedStyleProp(_YGNodeRef node, IdxT idx, CompactValue value) {
  updateStyle(
      resolveRef(node),
      value,
      [idx](Style& s, CompactValue x) { return (s.*GetterT)(idx) != x; },
      [idx](Style& s, CompactValue x) { (s.*SetterT)(idx, x); });
}

} // namespace

// MSVC has trouble inferring the return type of pointer to member functions
// with const and non-const overloads, instead of preferring the non-const
// overload like clang and GCC. For the purposes of updateStyle(), we can help
// MSVC by specifying that return type explicitly. In combination with
// decltype, MSVC will prefer the non-const version.
#define MSVC_HINT(PROP) decltype(Style{}.PROP())

void _YGNodeCopyStyle(
    const _YGNodeRef dstNodeRef,
    const _YGNodeConstRef srcNodeRef) {
  auto dstNode = resolveRef(dstNodeRef);
  auto srcNode = resolveRef(srcNodeRef);

  if (!(dstNode->getStyle() == srcNode->getStyle())) {
    dstNode->setStyle(srcNode->getStyle());
    dstNode->markDirtyAndPropagate();
  }
}

void _YGNodeStyleSetDirection(const _YGNodeRef node, const _YGDirection value) {
  updateStyle<MSVC_HINT(direction)>(node, &Style::direction, scopedEnum(value));
}

_YGDirection _YGNodeStyleGetDirection(const _YGNodeConstRef node) {
  return unscopedEnum(resolveRef(node)->getStyle().direction());
}

void _YGNodeStyleSetFlexDirection(
    const _YGNodeRef node,
    const _YGFlexDirection flexDirection) {
  updateStyle<MSVC_HINT(flexDirection)>(
      node, &Style::flexDirection, scopedEnum(flexDirection));
}

_YGFlexDirection _YGNodeStyleGetFlexDirection(const _YGNodeConstRef node) {
  return unscopedEnum(resolveRef(node)->getStyle().flexDirection());
}

void _YGNodeStyleSetJustifyContent(
    const _YGNodeRef node,
    const _YGJustify justifyContent) {
  updateStyle<MSVC_HINT(justifyContent)>(
      node, &Style::justifyContent, scopedEnum(justifyContent));
}

_YGJustify _YGNodeStyleGetJustifyContent(const _YGNodeConstRef node) {
  return unscopedEnum(resolveRef(node)->getStyle().justifyContent());
}

void _YGNodeStyleSetAlignContent(
    const _YGNodeRef node,
    const _YGAlign alignContent) {
  updateStyle<MSVC_HINT(alignContent)>(
      node, &Style::alignContent, scopedEnum(alignContent));
}

_YGAlign _YGNodeStyleGetAlignContent(const _YGNodeConstRef node) {
  return unscopedEnum(resolveRef(node)->getStyle().alignContent());
}

void _YGNodeStyleSetAlignItems(const _YGNodeRef node, const _YGAlign alignItems) {
  updateStyle<MSVC_HINT(alignItems)>(
      node, &Style::alignItems, scopedEnum(alignItems));
}

_YGAlign _YGNodeStyleGetAlignItems(const _YGNodeConstRef node) {
  return unscopedEnum(resolveRef(node)->getStyle().alignItems());
}

void _YGNodeStyleSetAlignSelf(const _YGNodeRef node, const _YGAlign alignSelf) {
  updateStyle<MSVC_HINT(alignSelf)>(
      node, &Style::alignSelf, scopedEnum(alignSelf));
}

_YGAlign _YGNodeStyleGetAlignSelf(const _YGNodeConstRef node) {
  return unscopedEnum(resolveRef(node)->getStyle().alignSelf());
}

void _YGNodeStyleSetPositionType(
    const _YGNodeRef node,
    const _YGPositionType positionType) {
  updateStyle<MSVC_HINT(positionType)>(
      node, &Style::positionType, scopedEnum(positionType));
}

_YGPositionType _YGNodeStyleGetPositionType(const _YGNodeConstRef node) {
  return unscopedEnum(resolveRef(node)->getStyle().positionType());
}

void _YGNodeStyleSetFlexWrap(const _YGNodeRef node, const _YGWrap flexWrap) {
  updateStyle<MSVC_HINT(flexWrap)>(
      node, &Style::flexWrap, scopedEnum(flexWrap));
}

_YGWrap _YGNodeStyleGetFlexWrap(const _YGNodeConstRef node) {
  return unscopedEnum(resolveRef(node)->getStyle().flexWrap());
}

void _YGNodeStyleSetOverflow(const _YGNodeRef node, const _YGOverflow overflow) {
  updateStyle<MSVC_HINT(overflow)>(
      node, &Style::overflow, scopedEnum(overflow));
}

_YGOverflow _YGNodeStyleGetOverflow(const _YGNodeConstRef node) {
  return unscopedEnum(resolveRef(node)->getStyle().overflow());
}

void _YGNodeStyleSetDisplay(const _YGNodeRef node, const _YGDisplay display) {
  updateStyle<MSVC_HINT(display)>(node, &Style::display, scopedEnum(display));
}

_YGDisplay _YGNodeStyleGetDisplay(const _YGNodeConstRef node) {
  return unscopedEnum(resolveRef(node)->getStyle().display());
}

void _YGNodeStyleSetFlex(const _YGNodeRef node, const float flex) {
  updateStyle<MSVC_HINT(flex)>(node, &Style::flex, FloatOptional{flex});
}

float _YGNodeStyleGetFlex(const _YGNodeConstRef nodeRef) {
  const auto node = resolveRef(nodeRef);
  return node->getStyle().flex().isUndefined()
      ? _YGUndefined
      : node->getStyle().flex().unwrap();
}

void _YGNodeStyleSetFlexGrow(const _YGNodeRef node, const float flexGrow) {
  updateStyle<MSVC_HINT(flexGrow)>(
      node, &Style::flexGrow, FloatOptional{flexGrow});
}

float _YGNodeStyleGetFlexGrow(const _YGNodeConstRef nodeRef) {
  const auto node = resolveRef(nodeRef);
  return node->getStyle().flexGrow().isUndefined()
      ? Style::DefaultFlexGrow
      : node->getStyle().flexGrow().unwrap();
}

void _YGNodeStyleSetFlexShrink(const _YGNodeRef node, const float flexShrink) {
  updateStyle<MSVC_HINT(flexShrink)>(
      node, &Style::flexShrink, FloatOptional{flexShrink});
}

float _YGNodeStyleGetFlexShrink(const _YGNodeConstRef nodeRef) {
  const auto node = resolveRef(nodeRef);
  return node->getStyle().flexShrink().isUndefined()
      ? (node->getConfig()->useWebDefaults() ? Style::WebDefaultFlexShrink
                                             : Style::DefaultFlexShrink)
      : node->getStyle().flexShrink().unwrap();
}

void _YGNodeStyleSetFlexBasis(const _YGNodeRef node, const float flexBasis) {
  auto value = CompactValue::ofMaybe<_YGUnitPoint>(flexBasis);
  updateStyle<MSVC_HINT(flexBasis)>(node, &Style::flexBasis, value);
}

void _YGNodeStyleSetFlexBasisPercent(
    const _YGNodeRef node,
    const float flexBasisPercent) {
  auto value = CompactValue::ofMaybe<_YGUnitPercent>(flexBasisPercent);
  updateStyle<MSVC_HINT(flexBasis)>(node, &Style::flexBasis, value);
}

void _YGNodeStyleSetFlexBasisAuto(const _YGNodeRef node) {
  updateStyle<MSVC_HINT(flexBasis)>(
      node, &Style::flexBasis, CompactValue::ofAuto());
}

_YGValue _YGNodeStyleGetFlexBasis(const _YGNodeConstRef node) {
  _YGValue flexBasis = resolveRef(node)->getStyle().flexBasis();
  if (flexBasis.unit == _YGUnitUndefined || flexBasis.unit == _YGUnitAuto) {
    flexBasis.value = _YGUndefined;
  }
  return flexBasis;
}

void _YGNodeStyleSetPosition(_YGNodeRef node, _YGEdge edge, float points) {
  auto value = CompactValue::ofMaybe<_YGUnitPoint>(points);
  updateIndexedStyleProp<&Style::position, &Style::setPosition>(
      node, edge, value);
}

void _YGNodeStyleSetPositionPercent(_YGNodeRef node, _YGEdge edge, float percent) {
  auto value = CompactValue::ofMaybe<_YGUnitPercent>(percent);
  updateIndexedStyleProp<&Style::position, &Style::setPosition>(
      node, edge, value);
}

_YGValue _YGNodeStyleGetPosition(_YGNodeConstRef node, _YGEdge edge) {
  return resolveRef(node)->getStyle().position(edge);
}

void _YGNodeStyleSetMargin(_YGNodeRef node, _YGEdge edge, float points) {
  auto value = CompactValue::ofMaybe<_YGUnitPoint>(points);
  updateIndexedStyleProp<&Style::margin, &Style::setMargin>(node, edge, value);
}

void _YGNodeStyleSetMarginPercent(_YGNodeRef node, _YGEdge edge, float percent) {
  auto value = CompactValue::ofMaybe<_YGUnitPercent>(percent);
  updateIndexedStyleProp<&Style::margin, &Style::setMargin>(node, edge, value);
}

void _YGNodeStyleSetMarginAuto(_YGNodeRef node, _YGEdge edge) {
  updateIndexedStyleProp<&Style::margin, &Style::setMargin>(
      node, edge, CompactValue::ofAuto());
}

_YGValue _YGNodeStyleGetMargin(_YGNodeConstRef node, _YGEdge edge) {
  return resolveRef(node)->getStyle().margin(edge);
}

void _YGNodeStyleSetPadding(_YGNodeRef node, _YGEdge edge, float points) {
  auto value = CompactValue::ofMaybe<_YGUnitPoint>(points);
  updateIndexedStyleProp<&Style::padding, &Style::setPadding>(
      node, edge, value);
}

void _YGNodeStyleSetPaddingPercent(_YGNodeRef node, _YGEdge edge, float percent) {
  auto value = CompactValue::ofMaybe<_YGUnitPercent>(percent);
  updateIndexedStyleProp<&Style::padding, &Style::setPadding>(
      node, edge, value);
}

_YGValue _YGNodeStyleGetPadding(_YGNodeConstRef node, _YGEdge edge) {
  return resolveRef(node)->getStyle().padding(edge);
}

void _YGNodeStyleSetBorder(
    const _YGNodeRef node,
    const _YGEdge edge,
    const float border) {
  auto value = CompactValue::ofMaybe<_YGUnitPoint>(border);
  updateIndexedStyleProp<&Style::border, &Style::setBorder>(node, edge, value);
}

float _YGNodeStyleGetBorder(const _YGNodeConstRef node, const _YGEdge edge) {
  auto border = resolveRef(node)->getStyle().border(edge);
  if (border.isUndefined() || border.isAuto()) {
    return _YGUndefined;
  }

  return static_cast<_YGValue>(border).value;
}

void _YGNodeStyleSetGap(
    const _YGNodeRef node,
    const _YGGutter gutter,
    const float gapLength) {
  auto length = CompactValue::ofMaybe<_YGUnitPoint>(gapLength);
  updateIndexedStyleProp<&Style::gap, &Style::setGap>(
      node, scopedEnum(gutter), length);
}

float _YGNodeStyleGetGap(const _YGNodeConstRef node, const _YGGutter gutter) {
  auto gapLength = resolveRef(node)->getStyle().gap(scopedEnum(gutter));
  if (gapLength.isUndefined() || gapLength.isAuto()) {
    return _YGUndefined;
  }

  return static_cast<_YGValue>(gapLength).value;
}

void _YGNodeStyleSetAspectRatio(const _YGNodeRef node, const float aspectRatio) {
  updateStyle<MSVC_HINT(aspectRatio)>(
      node, &Style::aspectRatio, FloatOptional{aspectRatio});
}

float _YGNodeStyleGetAspectRatio(const _YGNodeConstRef node) {
  const FloatOptional op = resolveRef(node)->getStyle().aspectRatio();
  return op.isUndefined() ? _YGUndefined : op.unwrap();
}

void _YGNodeStyleSetWidth(_YGNodeRef node, float points) {
  auto value = CompactValue::ofMaybe<_YGUnitPoint>(points);
  updateIndexedStyleProp<&Style::dimension, &Style::setDimension>(
      node, Dimension::Width, value);
}

void _YGNodeStyleSetWidthPercent(_YGNodeRef node, float percent) {
  auto value = CompactValue::ofMaybe<_YGUnitPercent>(percent);
  updateIndexedStyleProp<&Style::dimension, &Style::setDimension>(
      node, Dimension::Width, value);
}

void _YGNodeStyleSetWidthAuto(_YGNodeRef node) {
  updateIndexedStyleProp<&Style::dimension, &Style::setDimension>(
      node, Dimension::Width, CompactValue::ofAuto());
}

_YGValue _YGNodeStyleGetWidth(_YGNodeConstRef node) {
  return resolveRef(node)->getStyle().dimension(Dimension::Width);
}

void _YGNodeStyleSetHeight(_YGNodeRef node, float points) {
  auto value = CompactValue::ofMaybe<_YGUnitPoint>(points);
  updateIndexedStyleProp<&Style::dimension, &Style::setDimension>(
      node, Dimension::Height, value);
}

void _YGNodeStyleSetHeightPercent(_YGNodeRef node, float percent) {
  auto value = CompactValue::ofMaybe<_YGUnitPercent>(percent);
  updateIndexedStyleProp<&Style::dimension, &Style::setDimension>(
      node, Dimension::Height, value);
}

void _YGNodeStyleSetHeightAuto(_YGNodeRef node) {
  updateIndexedStyleProp<&Style::dimension, &Style::setDimension>(
      node, Dimension::Height, CompactValue::ofAuto());
}

_YGValue _YGNodeStyleGetHeight(_YGNodeConstRef node) {
  return resolveRef(node)->getStyle().dimension(Dimension::Height);
}

void _YGNodeStyleSetMinWidth(const _YGNodeRef node, const float minWidth) {
  auto value = CompactValue::ofMaybe<_YGUnitPoint>(minWidth);
  updateIndexedStyleProp<&Style::minDimension, &Style::setMinDimension>(
      node, Dimension::Width, value);
}

void _YGNodeStyleSetMinWidthPercent(const _YGNodeRef node, const float minWidth) {
  auto value = CompactValue::ofMaybe<_YGUnitPercent>(minWidth);
  updateIndexedStyleProp<&Style::minDimension, &Style::setMinDimension>(
      node, Dimension::Width, value);
}

_YGValue _YGNodeStyleGetMinWidth(const _YGNodeConstRef node) {
  return resolveRef(node)->getStyle().minDimension(Dimension::Width);
}

void _YGNodeStyleSetMinHeight(const _YGNodeRef node, const float minHeight) {
  auto value = CompactValue::ofMaybe<_YGUnitPoint>(minHeight);
  updateIndexedStyleProp<&Style::minDimension, &Style::setMinDimension>(
      node, Dimension::Height, value);
}

void _YGNodeStyleSetMinHeightPercent(
    const _YGNodeRef node,
    const float minHeight) {
  auto value = CompactValue::ofMaybe<_YGUnitPercent>(minHeight);
  updateIndexedStyleProp<&Style::minDimension, &Style::setMinDimension>(
      node, Dimension::Height, value);
}

_YGValue _YGNodeStyleGetMinHeight(const _YGNodeConstRef node) {
  return resolveRef(node)->getStyle().minDimension(Dimension::Height);
}

void _YGNodeStyleSetMaxWidth(const _YGNodeRef node, const float maxWidth) {
  auto value = CompactValue::ofMaybe<_YGUnitPoint>(maxWidth);
  updateIndexedStyleProp<&Style::maxDimension, &Style::setMaxDimension>(
      node, Dimension::Width, value);
}

void _YGNodeStyleSetMaxWidthPercent(const _YGNodeRef node, const float maxWidth) {
  auto value = CompactValue::ofMaybe<_YGUnitPercent>(maxWidth);
  updateIndexedStyleProp<&Style::maxDimension, &Style::setMaxDimension>(
      node, Dimension::Width, value);
}

_YGValue _YGNodeStyleGetMaxWidth(const _YGNodeConstRef node) {
  return resolveRef(node)->getStyle().maxDimension(Dimension::Width);
}

void _YGNodeStyleSetMaxHeight(const _YGNodeRef node, const float maxHeight) {
  auto value = CompactValue::ofMaybe<_YGUnitPoint>(maxHeight);
  updateIndexedStyleProp<&Style::maxDimension, &Style::setMaxDimension>(
      node, Dimension::Height, value);
}

void _YGNodeStyleSetMaxHeightPercent(
    const _YGNodeRef node,
    const float maxHeight) {
  auto value = CompactValue::ofMaybe<_YGUnitPercent>(maxHeight);
  updateIndexedStyleProp<&Style::maxDimension, &Style::setMaxDimension>(
      node, Dimension::Height, value);
}

_YGValue _YGNodeStyleGetMaxHeight(const _YGNodeConstRef node) {
  return resolveRef(node)->getStyle().maxDimension(Dimension::Height);
}
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



namespace facebook::yoga {

// Round a point value to the nearest physical pixel based on DPI
// (pointScaleFactor)
float roundValueToPixelGrid(
    const double value,
    const double pointScaleFactor,
    const bool forceCeil,
    const bool forceFloor);

// Round the layout results of a node and its subtree to the pixel grid.
void roundLayoutResultsToPixelGrid(
    yoga::Node* const node,
    const double absoluteLeft,
    const double absoluteTop);

} // namespace facebook::yoga

using namespace facebook;
using namespace facebook::yoga;

float _YGRoundValueToPixelGrid(
    const double value,
    const double pointScaleFactor,
    const bool forceCeil,
    const bool forceFloor) {
  return yoga::roundValueToPixelGrid(
      value, pointScaleFactor, forceCeil, forceFloor);
}
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

const char* _YGAlignToString(const _YGAlign value) {
  switch (value) {
    case _YGAlignAuto:
      return "auto";
    case _YGAlignFlexStart:
      return "flex-start";
    case _YGAlignCenter:
      return "center";
    case _YGAlignFlexEnd:
      return "flex-end";
    case _YGAlignStretch:
      return "stretch";
    case _YGAlignBaseline:
      return "baseline";
    case _YGAlignSpaceBetween:
      return "space-between";
    case _YGAlignSpaceAround:
      return "space-around";
    case _YGAlignSpaceEvenly:
      return "space-evenly";
  }
  return "unknown";
}

const char* _YGDimensionToString(const _YGDimension value) {
  switch (value) {
    case _YGDimensionWidth:
      return "width";
    case _YGDimensionHeight:
      return "height";
  }
  return "unknown";
}

const char* _YGDirectionToString(const _YGDirection value) {
  switch (value) {
    case _YGDirectionInherit:
      return "inherit";
    case _YGDirectionLTR:
      return "ltr";
    case _YGDirectionRTL:
      return "rtl";
  }
  return "unknown";
}

const char* _YGDisplayToString(const _YGDisplay value) {
  switch (value) {
    case _YGDisplayFlex:
      return "flex";
    case _YGDisplayNone:
      return "none";
  }
  return "unknown";
}

const char* _YGEdgeToString(const _YGEdge value) {
  switch (value) {
    case _YGEdgeLeft:
      return "left";
    case _YGEdgeTop:
      return "top";
    case _YGEdgeRight:
      return "right";
    case _YGEdgeBottom:
      return "bottom";
    case _YGEdgeStart:
      return "start";
    case _YGEdgeEnd:
      return "end";
    case _YGEdgeHorizontal:
      return "horizontal";
    case _YGEdgeVertical:
      return "vertical";
    case _YGEdgeAll:
      return "all";
  }
  return "unknown";
}

const char* _YGErrataToString(const _YGErrata value) {
  switch (value) {
    case _YGErrataNone:
      return "none";
    case _YGErrataStretchFlexBasis:
      return "stretch-flex-basis";
    case _YGErrataStartingEndingEdgeFromFlexDirection:
      return "starting-ending-edge-from-flex-direction";
    case _YGErrataPositionStaticBehavesLikeRelative:
      return "position-static-behaves-like-relative";
    case _YGErrataAll:
      return "all";
    case _YGErrataClassic:
      return "classic";
  }
  return "unknown";
}

const char* _YGExperimentalFeatureToString(const _YGExperimentalFeature value) {
  switch (value) {
    case _YGExperimentalFeatureWebFlexBasis:
      return "web-flex-basis";
    case _YGExperimentalFeatureAbsolutePercentageAgainstPaddingEdge:
      return "absolute-percentage-against-padding-edge";
  }
  return "unknown";
}

const char* _YGFlexDirectionToString(const _YGFlexDirection value) {
  switch (value) {
    case _YGFlexDirectionColumn:
      return "column";
    case _YGFlexDirectionColumnReverse:
      return "column-reverse";
    case _YGFlexDirectionRow:
      return "row";
    case _YGFlexDirectionRowReverse:
      return "row-reverse";
  }
  return "unknown";
}

const char* _YGGutterToString(const _YGGutter value) {
  switch (value) {
    case _YGGutterColumn:
      return "column";
    case _YGGutterRow:
      return "row";
    case _YGGutterAll:
      return "all";
  }
  return "unknown";
}

const char* _YGJustifyToString(const _YGJustify value) {
  switch (value) {
    case _YGJustifyFlexStart:
      return "flex-start";
    case _YGJustifyCenter:
      return "center";
    case _YGJustifyFlexEnd:
      return "flex-end";
    case _YGJustifySpaceBetween:
      return "space-between";
    case _YGJustifySpaceAround:
      return "space-around";
    case _YGJustifySpaceEvenly:
      return "space-evenly";
  }
  return "unknown";
}

const char* _YGLogLevelToString(const _YGLogLevel value) {
  switch (value) {
    case _YGLogLevelError:
      return "error";
    case _YGLogLevelWarn:
      return "warn";
    case _YGLogLevelInfo:
      return "info";
    case _YGLogLevelDebug:
      return "debug";
    case _YGLogLevelVerbose:
      return "verbose";
    case _YGLogLevelFatal:
      return "fatal";
  }
  return "unknown";
}

const char* _YGMeasureModeToString(const _YGMeasureMode value) {
  switch (value) {
    case _YGMeasureModeUndefined:
      return "undefined";
    case _YGMeasureModeExactly:
      return "exactly";
    case _YGMeasureModeAtMost:
      return "at-most";
  }
  return "unknown";
}

const char* _YGNodeTypeToString(const _YGNodeType value) {
  switch (value) {
    case _YGNodeTypeDefault:
      return "default";
    case _YGNodeTypeText:
      return "text";
  }
  return "unknown";
}

const char* _YGOverflowToString(const _YGOverflow value) {
  switch (value) {
    case _YGOverflowVisible:
      return "visible";
    case _YGOverflowHidden:
      return "hidden";
    case _YGOverflowScroll:
      return "scroll";
  }
  return "unknown";
}

const char* _YGPositionTypeToString(const _YGPositionType value) {
  switch (value) {
    case _YGPositionTypeStatic:
      return "static";
    case _YGPositionTypeRelative:
      return "relative";
    case _YGPositionTypeAbsolute:
      return "absolute";
  }
  return "unknown";
}

const char* _YGPrintOptionsToString(const _YGPrintOptions value) {
  switch (value) {
    case _YGPrintOptionsLayout:
      return "layout";
    case _YGPrintOptionsStyle:
      return "style";
    case _YGPrintOptionsChildren:
      return "children";
  }
  return "unknown";
}

const char* _YGUnitToString(const _YGUnit value) {
  switch (value) {
    case _YGUnitUndefined:
      return "undefined";
    case _YGUnitPoint:
      return "point";
    case _YGUnitPercent:
      return "percent";
    case _YGUnitAuto:
      return "auto";
  }
  return "unknown";
}

const char* _YGWrapToString(const _YGWrap value) {
  switch (value) {
    case _YGWrapNoWrap:
      return "no-wrap";
    case _YGWrapWrap:
      return "wrap";
    case _YGWrapWrapReverse:
      return "wrap-reverse";
  }
  return "unknown";
}
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


using namespace facebook;
using namespace facebook::yoga;

const _YGValue _YGValueZero = {0, _YGUnitPoint};
const _YGValue _YGValueUndefined = {_YGUndefined, _YGUnitUndefined};
const _YGValue _YGValueAuto = {_YGUndefined, _YGUnitAuto};

bool _YGFloatIsUndefined(const float value) {
  return yoga::isUndefined(value);
}
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */




namespace facebook::yoga {

void log(LogLevel level, const char* format, ...) noexcept;

void log(
    const yoga::Node* node,
    LogLevel level,
    const char* message,
    ...) noexcept;

void log(
    const yoga::Config* config,
    LogLevel level,
    const char* format,
    ...) noexcept;

_YGLogger getDefaultLogger();

} // namespace facebook::yoga

using namespace facebook;
using namespace facebook::yoga;

_YGConfigRef _YGConfigNew(void) {
  return new yoga::Config(getDefaultLogger());
}

void _YGConfigFree(const _YGConfigRef config) {
  delete resolveRef(config);
}

_YGConfigConstRef _YGConfigGetDefault() {
  return &yoga::Config::getDefault();
}

void _YGConfigSetUseWebDefaults(const _YGConfigRef config, const bool enabled) {
  resolveRef(config)->setUseWebDefaults(enabled);
}

bool _YGConfigGetUseWebDefaults(const _YGConfigConstRef config) {
  return resolveRef(config)->useWebDefaults();
}

void _YGConfigSetPointScaleFactor(
    const _YGConfigRef config,
    const float pixelsInPoint) {
  yoga::assertFatalWithConfig(
      resolveRef(config),
      pixelsInPoint >= 0.0f,
      "Scale factor should not be less than zero");

  resolveRef(config)->setPointScaleFactor(pixelsInPoint);
}

float _YGConfigGetPointScaleFactor(const _YGConfigConstRef config) {
  return resolveRef(config)->getPointScaleFactor();
}

void _YGConfigSetErrata(_YGConfigRef config, _YGErrata errata) {
  resolveRef(config)->setErrata(scopedEnum(errata));
}

_YGErrata _YGConfigGetErrata(_YGConfigConstRef config) {
  return unscopedEnum(resolveRef(config)->getErrata());
}

void _YGConfigSetLogger(const _YGConfigRef config, _YGLogger logger) {
  if (logger != nullptr) {
    resolveRef(config)->setLogger(logger);
  } else {
    resolveRef(config)->setLogger(getDefaultLogger());
  }
}

void _YGConfigSetContext(const _YGConfigRef config, void* context) {
  resolveRef(config)->setContext(context);
}

void* _YGConfigGetContext(const _YGConfigConstRef config) {
  return resolveRef(config)->getContext();
}

void _YGConfigSetExperimentalFeatureEnabled(
    const _YGConfigRef config,
    const _YGExperimentalFeature feature,
    const bool enabled) {
  resolveRef(config)->setExperimentalFeatureEnabled(
      scopedEnum(feature), enabled);
}

bool _YGConfigIsExperimentalFeatureEnabled(
    const _YGConfigConstRef config,
    const _YGExperimentalFeature feature) {
  return resolveRef(config)->isExperimentalFeatureEnabled(scopedEnum(feature));
}

void _YGConfigSetCloneNodeFunc(
    const _YGConfigRef config,
    const _YGCloneNodeFunc callback) {
  resolveRef(config)->setCloneNodeCallback(callback);
}

void _YGConfigSetPrintTreeFlag(_YGConfigRef config, bool enabled) {
  resolveRef(config)->setShouldPrintTree(enabled);
}
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



namespace facebook::yoga {

bool canUseCachedMeasurement(
    MeasureMode widthMode,
    float availableWidth,
    MeasureMode heightMode,
    float availableHeight,
    MeasureMode lastWidthMode,
    float lastAvailableWidth,
    MeasureMode lastHeightMode,
    float lastAvailableHeight,
    float lastComputedWidth,
    float lastComputedHeight,
    float marginRow,
    float marginColumn,
    const yoga::Config* config);

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



namespace facebook::yoga {

void calculateLayout(
    yoga::Node* const node,
    const float ownerWidth,
    const float ownerHeight,
    const Direction ownerDirection);

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifdef DEBUG


#include <string>

/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @generated by enums.py
// clang-format off

#include <cstdint>

namespace facebook::yoga {

enum class PrintOptions : uint32_t {
  Layout = _YGPrintOptionsLayout,
  Style = _YGPrintOptionsStyle,
  Children = _YGPrintOptionsChildren,
};

_YG_DEFINE_ENUM_FLAG_OPERATORS(PrintOptions)

constexpr inline PrintOptions scopedEnum(_YGPrintOptions unscoped) {
  return static_cast<PrintOptions>(unscoped);
}

constexpr inline _YGPrintOptions unscopedEnum(PrintOptions scoped) {
  return static_cast<_YGPrintOptions>(scoped);
}

inline const char* toString(PrintOptions e) {
  return _YGPrintOptionsToString(unscopedEnum(e));
}

} // namespace facebook::yoga

namespace facebook::yoga {

void nodeToString(
    std::string& str,
    const yoga::Node* node,
    PrintOptions options,
    uint32_t level);

void print(const yoga::Node* node, PrintOptions options);

} // namespace facebook::yoga

#endif
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



#include <stdint.h>
#include <array>
#include <functional>
#include <vector>

namespace facebook::yoga {

enum struct LayoutType : int {
  kLayout = 0,
  kMeasure = 1,
  kCachedLayout = 2,
  kCachedMeasure = 3
};

enum struct LayoutPassReason : int {
  kInitial = 0,
  kAbsLayout = 1,
  kStretch = 2,
  kMultilineStretch = 3,
  kFlexLayout = 4,
  kMeasureChild = 5,
  kAbsMeasureChild = 6,
  kFlexMeasure = 7,
  COUNT
};

struct LayoutData {
  int layouts;
  int measures;
  uint32_t maxMeasureCache;
  int cachedLayouts;
  int cachedMeasures;
  int measureCallbacks;
  std::array<int, static_cast<uint8_t>(LayoutPassReason::COUNT)>
      measureCallbackReasonsCount;
};

const char* LayoutPassReasonToString(const LayoutPassReason value);

struct _YG_EXPORT Event {
  enum Type {
    NodeAllocation,
    NodeDeallocation,
    NodeLayout,
    LayoutPassStart,
    LayoutPassEnd,
    MeasureCallbackStart,
    MeasureCallbackEnd,
    NodeBaselineStart,
    NodeBaselineEnd,
  };
  class Data;
  using Subscriber = void(_YGNodeConstRef, Type, Data);
  using Subscribers = std::vector<std::function<Subscriber>>;

  template <Type E>
  struct TypedData {};

  class Data {
    const void* data_;

   public:
    template <Type E>
    Data(const TypedData<E>& data) : data_{&data} {}

    template <Type E>
    const TypedData<E>& get() const {
      return *static_cast<const TypedData<E>*>(data_);
    }
  };

  static void reset();

  static void subscribe(std::function<Subscriber>&& subscriber);

  template <Type E>
  static void publish(_YGNodeConstRef node, const TypedData<E>& eventData = {}) {
    publish(node, E, Data{eventData});
  }

 private:
  static void publish(_YGNodeConstRef, Type, const Data&);
};

template <>
struct Event::TypedData<Event::NodeAllocation> {
  _YGConfigConstRef config;
};

template <>
struct Event::TypedData<Event::NodeDeallocation> {
  _YGConfigConstRef config;
};

template <>
struct Event::TypedData<Event::LayoutPassEnd> {
  LayoutData* layoutData;
};

template <>
struct Event::TypedData<Event::MeasureCallbackEnd> {
  float width;
  _YGMeasureMode widthMeasureMode;
  float height;
  _YGMeasureMode heightMeasureMode;
  float measuredWidth;
  float measuredHeight;
  const LayoutPassReason reason;
};

template <>
struct Event::TypedData<Event::NodeLayout> {
  LayoutType layoutType;
};

} // namespace facebook::yoga

using namespace facebook;
using namespace facebook::yoga;

_YGNodeRef _YGNodeNew(void) {
  return _YGNodeNewWithConfig(_YGConfigGetDefault());
}

_YGNodeRef _YGNodeNewWithConfig(const _YGConfigConstRef config) {
  auto* node = new yoga::Node{resolveRef(config)};
  yoga::assertFatal(
      config != nullptr, "Tried to construct _YGNode with null config");
  Event::publish<Event::NodeAllocation>(node, {config});

  return node;
}

_YGNodeRef _YGNodeClone(_YGNodeConstRef oldNodeRef) {
  auto oldNode = resolveRef(oldNodeRef);
  const auto node = new yoga::Node(*oldNode);
  Event::publish<Event::NodeAllocation>(node, {node->getConfig()});
  node->setOwner(nullptr);
  return node;
}

void _YGNodeFree(const _YGNodeRef nodeRef) {
  const auto node = resolveRef(nodeRef);

  if (auto owner = node->getOwner()) {
    owner->removeChild(node);
    node->setOwner(nullptr);
  }

  const size_t childCount = node->getChildCount();
  for (size_t i = 0; i < childCount; i++) {
    auto child = node->getChild(i);
    child->setOwner(nullptr);
  }

  node->clearChildren();

  Event::publish<Event::NodeDeallocation>(node, {_YGNodeGetConfig(node)});
  delete resolveRef(node);
}

void _YGNodeFreeRecursive(_YGNodeRef rootRef) {
  const auto root = resolveRef(rootRef);

  size_t skipped = 0;
  while (root->getChildCount() > skipped) {
    const auto child = root->getChild(skipped);
    if (child->getOwner() != root) {
      // Don't free shared nodes that we don't own.
      skipped += 1;
    } else {
      _YGNodeRemoveChild(root, child);
      _YGNodeFreeRecursive(child);
    }
  }
  _YGNodeFree(root);
}

void _YGNodeFinalize(const _YGNodeRef node) {
  Event::publish<Event::NodeDeallocation>(node, {_YGNodeGetConfig(node)});
  delete resolveRef(node);
}

void _YGNodeReset(_YGNodeRef node) {
  resolveRef(node)->reset();
}

void _YGNodeCalculateLayout(
    const _YGNodeRef node,
    const float ownerWidth,
    const float ownerHeight,
    const _YGDirection ownerDirection) {
  yoga::calculateLayout(
      resolveRef(node), ownerWidth, ownerHeight, scopedEnum(ownerDirection));
}

bool _YGNodeGetHasNewLayout(_YGNodeConstRef node) {
  return resolveRef(node)->getHasNewLayout();
}

void _YGNodeSetHasNewLayout(_YGNodeRef node, bool hasNewLayout) {
  resolveRef(node)->setHasNewLayout(hasNewLayout);
}

bool _YGNodeIsDirty(_YGNodeConstRef node) {
  return resolveRef(node)->isDirty();
}

void _YGNodeMarkDirty(const _YGNodeRef nodeRef) {
  const auto node = resolveRef(nodeRef);

  yoga::assertFatalWithNode(
      node,
      node->hasMeasureFunc(),
      "Only leaf nodes with custom measure functions "
      "should manually mark themselves as dirty");

  node->markDirtyAndPropagate();
}

void _YGNodeSetDirtiedFunc(_YGNodeRef node, _YGDirtiedFunc dirtiedFunc) {
  resolveRef(node)->setDirtiedFunc(dirtiedFunc);
}

_YGDirtiedFunc _YGNodeGetDirtiedFunc(_YGNodeConstRef node) {
  return resolveRef(node)->getDirtiedFunc();
}

void _YGNodeInsertChild(
    const _YGNodeRef ownerRef,
    const _YGNodeRef childRef,
    const size_t index) {
  auto owner = resolveRef(ownerRef);
  auto child = resolveRef(childRef);

  yoga::assertFatalWithNode(
      owner,
      child->getOwner() == nullptr,
      "Child already has a owner, it must be removed first.");

  yoga::assertFatalWithNode(
      owner,
      !owner->hasMeasureFunc(),
      "Cannot add child: Nodes with measure functions cannot have children.");

  owner->insertChild(child, index);
  child->setOwner(owner);
  owner->markDirtyAndPropagate();
}

void _YGNodeSwapChild(
    const _YGNodeRef ownerRef,
    const _YGNodeRef childRef,
    const size_t index) {
  auto owner = resolveRef(ownerRef);
  auto child = resolveRef(childRef);

  owner->replaceChild(child, index);
  child->setOwner(owner);
}

void _YGNodeRemoveChild(
    const _YGNodeRef ownerRef,
    const _YGNodeRef excludedChildRef) {
  auto owner = resolveRef(ownerRef);
  auto excludedChild = resolveRef(excludedChildRef);

  if (owner->getChildCount() == 0) {
    // This is an empty set. Nothing to remove.
    return;
  }

  // Children may be shared between parents, which is indicated by not having an
  // owner. We only want to reset the child completely if it is owned
  // exclusively by one node.
  auto childOwner = excludedChild->getOwner();
  if (owner->removeChild(excludedChild)) {
    if (owner == childOwner) {
      excludedChild->setLayout({}); // layout is no longer valid
      excludedChild->setOwner(nullptr);
    }
    owner->markDirtyAndPropagate();
  }
}

void _YGNodeRemoveAllChildren(const _YGNodeRef ownerRef) {
  auto owner = resolveRef(ownerRef);

  const size_t childCount = owner->getChildCount();
  if (childCount == 0) {
    // This is an empty set already. Nothing to do.
    return;
  }
  auto* firstChild = owner->getChild(0);
  if (firstChild->getOwner() == owner) {
    // If the first child has this node as its owner, we assume that this child
    // set is unique.
    for (size_t i = 0; i < childCount; i++) {
      yoga::Node* oldChild = owner->getChild(i);
      oldChild->setLayout({}); // layout is no longer valid
      oldChild->setOwner(nullptr);
    }
    owner->clearChildren();
    owner->markDirtyAndPropagate();
    return;
  }
  // Otherwise, we are not the owner of the child set. We don't have to do
  // anything to clear it.
  owner->setChildren({});
  owner->markDirtyAndPropagate();
}

void _YGNodeSetChildren(
    const _YGNodeRef ownerRef,
    const _YGNodeRef* childrenRefs,
    const size_t count) {
  auto owner = resolveRef(ownerRef);
  auto children = reinterpret_cast<yoga::Node* const*>(childrenRefs);

  if (!owner) {
    return;
  }

  const std::vector<yoga::Node*> childrenVector = {children, children + count};
  if (childrenVector.size() == 0) {
    if (owner->getChildCount() > 0) {
      for (auto* child : owner->getChildren()) {
        child->setLayout({});
        child->setOwner(nullptr);
      }
      owner->setChildren({});
      owner->markDirtyAndPropagate();
    }
  } else {
    if (owner->getChildCount() > 0) {
      for (auto* oldChild : owner->getChildren()) {
        // Our new children may have nodes in common with the old children. We
        // don't reset these common nodes.
        if (std::find(childrenVector.begin(), childrenVector.end(), oldChild) ==
            childrenVector.end()) {
          oldChild->setLayout({});
          oldChild->setOwner(nullptr);
        }
      }
    }
    owner->setChildren(childrenVector);
    for (yoga::Node* child : childrenVector) {
      child->setOwner(owner);
    }
    owner->markDirtyAndPropagate();
  }
}

_YGNodeRef _YGNodeGetChild(const _YGNodeRef nodeRef, const size_t index) {
  const auto node = resolveRef(nodeRef);

  if (index < node->getChildren().size()) {
    return node->getChild(index);
  }
  return nullptr;
}

size_t _YGNodeGetChildCount(const _YGNodeConstRef node) {
  return resolveRef(node)->getChildren().size();
}

_YGNodeRef _YGNodeGetOwner(const _YGNodeRef node) {
  return resolveRef(node)->getOwner();
}

_YGNodeRef _YGNodeGetParent(const _YGNodeRef node) {
  return resolveRef(node)->getOwner();
}

void _YGNodeSetConfig(_YGNodeRef node, _YGConfigRef config) {
  resolveRef(node)->setConfig(resolveRef(config));
}

_YGConfigConstRef _YGNodeGetConfig(_YGNodeRef node) {
  return resolveRef(node)->getConfig();
}

void _YGNodeSetContext(_YGNodeRef node, void* context) {
  return resolveRef(node)->setContext(context);
}

void* _YGNodeGetContext(_YGNodeConstRef node) {
  return resolveRef(node)->getContext();
}

void _YGNodeSetMeasureFunc(_YGNodeRef node, _YGMeasureFunc measureFunc) {
  resolveRef(node)->setMeasureFunc(measureFunc);
}

bool _YGNodeHasMeasureFunc(_YGNodeConstRef node) {
  return resolveRef(node)->hasMeasureFunc();
}

void _YGNodeSetBaselineFunc(_YGNodeRef node, _YGBaselineFunc baselineFunc) {
  resolveRef(node)->setBaselineFunc(baselineFunc);
}

bool _YGNodeHasBaselineFunc(_YGNodeConstRef node) {
  return resolveRef(node)->hasBaselineFunc();
}

void _YGNodeSetIsReferenceBaseline(_YGNodeRef nodeRef, bool isReferenceBaseline) {
  const auto node = resolveRef(nodeRef);
  if (node->isReferenceBaseline() != isReferenceBaseline) {
    node->setIsReferenceBaseline(isReferenceBaseline);
    node->markDirtyAndPropagate();
  }
}

bool _YGNodeIsReferenceBaseline(_YGNodeConstRef node) {
  return resolveRef(node)->isReferenceBaseline();
}

void _YGNodeSetNodeType(_YGNodeRef node, _YGNodeType nodeType) {
  return resolveRef(node)->setNodeType(scopedEnum(nodeType));
}

_YGNodeType _YGNodeGetNodeType(_YGNodeConstRef node) {
  return unscopedEnum(resolveRef(node)->getNodeType());
}

void _YGNodeSetPrintFunc(_YGNodeRef node, _YGPrintFunc printFunc) {
  resolveRef(node)->setPrintFunc(printFunc);
}

#ifdef DEBUG
void _YGNodePrint(const _YGNodeConstRef node, const _YGPrintOptions options) {
  yoga::print(resolveRef(node), scopedEnum(options));
}
#endif

// TODO: This leaks internal details to the public API. Remove after removing
// ComponentKit usage of it.
bool _YGNodeCanUseCachedMeasurement(
    _YGMeasureMode widthMode,
    float availableWidth,
    _YGMeasureMode heightMode,
    float availableHeight,
    _YGMeasureMode lastWidthMode,
    float lastAvailableWidth,
    _YGMeasureMode lastHeightMode,
    float lastAvailableHeight,
    float lastComputedWidth,
    float lastComputedHeight,
    float marginRow,
    float marginColumn,
    _YGConfigRef config) {
  return yoga::canUseCachedMeasurement(
      scopedEnum(widthMode),
      availableWidth,
      scopedEnum(heightMode),
      availableHeight,
      scopedEnum(lastWidthMode),
      lastAvailableWidth,
      scopedEnum(lastHeightMode),
      lastAvailableHeight,
      lastComputedWidth,
      lastComputedHeight,
      marginRow,
      marginColumn,
      resolveRef(config));
}
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


using namespace facebook;
using namespace facebook::yoga;

namespace {

template <auto LayoutMember>
float getResolvedLayoutProperty(
    const _YGNodeConstRef nodeRef,
    const _YGEdge edge) {
  const auto node = resolveRef(nodeRef);
  yoga::assertFatalWithNode(
      node,
      edge <= _YGEdgeEnd,
      "Cannot get layout properties of multi-edge shorthands");

  if (edge == _YGEdgeStart) {
    if (node->getLayout().direction() == Direction::RTL) {
      return (node->getLayout().*LayoutMember)[_YGEdgeRight];
    } else {
      return (node->getLayout().*LayoutMember)[_YGEdgeLeft];
    }
  }

  if (edge == _YGEdgeEnd) {
    if (node->getLayout().direction() == Direction::RTL) {
      return (node->getLayout().*LayoutMember)[_YGEdgeLeft];
    } else {
      return (node->getLayout().*LayoutMember)[_YGEdgeRight];
    }
  }

  return (node->getLayout().*LayoutMember)[edge];
}

} // namespace

float _YGNodeLayoutGetLeft(const _YGNodeConstRef node) {
  return resolveRef(node)->getLayout().position[_YGEdgeLeft];
}

float _YGNodeLayoutGetTop(const _YGNodeConstRef node) {
  return resolveRef(node)->getLayout().position[_YGEdgeTop];
}

float _YGNodeLayoutGetRight(const _YGNodeConstRef node) {
  return resolveRef(node)->getLayout().position[_YGEdgeRight];
}

float _YGNodeLayoutGetBottom(const _YGNodeConstRef node) {
  return resolveRef(node)->getLayout().position[_YGEdgeBottom];
}

float _YGNodeLayoutGetWidth(const _YGNodeConstRef node) {
  return resolveRef(node)->getLayout().dimension(Dimension::Width);
}

float _YGNodeLayoutGetHeight(const _YGNodeConstRef node) {
  return resolveRef(node)->getLayout().dimension(Dimension::Height);
}

_YGDirection _YGNodeLayoutGetDirection(const _YGNodeConstRef node) {
  return unscopedEnum(resolveRef(node)->getLayout().direction());
}

bool _YGNodeLayoutGetHadOverflow(const _YGNodeConstRef node) {
  return resolveRef(node)->getLayout().hadOverflow();
}

float _YGNodeLayoutGetMargin(_YGNodeConstRef node, _YGEdge edge) {
  return getResolvedLayoutProperty<&LayoutResults::margin>(node, edge);
}

float _YGNodeLayoutGetBorder(_YGNodeConstRef node, _YGEdge edge) {
  return getResolvedLayoutProperty<&LayoutResults::border>(node, edge);
}

float _YGNodeLayoutGetPadding(_YGNodeConstRef node, _YGEdge edge) {
  return getResolvedLayoutProperty<&LayoutResults::padding>(node, edge);
}
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


namespace facebook::yoga {

bool configUpdateInvalidatesLayout(
    const Config& oldConfig,
    const Config& newConfig) {
  return oldConfig.getErrata() != newConfig.getErrata() ||
      oldConfig.getEnabledExperiments() != newConfig.getEnabledExperiments() ||
      oldConfig.getPointScaleFactor() != newConfig.getPointScaleFactor() ||
      oldConfig.useWebDefaults() != newConfig.useWebDefaults();
}

Config::Config(_YGLogger logger) : cloneNodeCallback_{nullptr} {
  setLogger(logger);
}

void Config::setUseWebDefaults(bool useWebDefaults) {
  useWebDefaults_ = useWebDefaults;
}

bool Config::useWebDefaults() const {
  return useWebDefaults_;
}

void Config::setShouldPrintTree(bool printTree) {
  printTree_ = printTree;
}

bool Config::shouldPrintTree() const {
  return printTree_;
}

void Config::setExperimentalFeatureEnabled(
    ExperimentalFeature feature,
    bool enabled) {
  experimentalFeatures_.set(static_cast<size_t>(feature), enabled);
}

bool Config::isExperimentalFeatureEnabled(ExperimentalFeature feature) const {
  return experimentalFeatures_.test(static_cast<size_t>(feature));
}

ExperimentalFeatureSet Config::getEnabledExperiments() const {
  return experimentalFeatures_;
}

void Config::setErrata(Errata errata) {
  errata_ = errata;
}

void Config::addErrata(Errata errata) {
  errata_ |= errata;
}

void Config::removeErrata(Errata errata) {
  errata_ &= (~errata);
}

Errata Config::getErrata() const {
  return errata_;
}

bool Config::hasErrata(Errata errata) const {
  return (errata_ & errata) != Errata::None;
}

void Config::setPointScaleFactor(float pointScaleFactor) {
  pointScaleFactor_ = pointScaleFactor;
}

float Config::getPointScaleFactor() const {
  return pointScaleFactor_;
}

void Config::setContext(void* context) {
  context_ = context;
}

void* Config::getContext() const {
  return context_;
}

void Config::setLogger(_YGLogger logger) {
  logger_ = logger;
}

void Config::log(
    const yoga::Node* node,
    LogLevel logLevel,
    const char* format,
    va_list args) const {
  logger_(this, node, unscopedEnum(logLevel), format, args);
}

void Config::setCloneNodeCallback(_YGCloneNodeFunc cloneNode) {
  cloneNodeCallback_ = cloneNode;
}

_YGNodeRef Config::cloneNode(
    _YGNodeConstRef node,
    _YGNodeConstRef owner,
    size_t childIndex) const {
  _YGNodeRef clone = nullptr;
  if (cloneNodeCallback_ != nullptr) {
    clone = cloneNodeCallback_(node, owner, childIndex);
  }
  if (clone == nullptr) {
    clone = _YGNodeClone(node);
  }
  return clone;
}

/*static*/ const Config& Config::getDefault() {
  static Config config{getDefaultLogger()};
  return config;
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <algorithm>
#include <atomic>
#include <cfloat>
#include <cmath>
#include <cstring>


/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */




namespace facebook::yoga {

inline bool isRow(const FlexDirection flexDirection) {
  return flexDirection == FlexDirection::Row ||
      flexDirection == FlexDirection::RowReverse;
}

inline bool isColumn(const FlexDirection flexDirection) {
  return flexDirection == FlexDirection::Column ||
      flexDirection == FlexDirection::ColumnReverse;
}

inline FlexDirection resolveDirection(
    const FlexDirection flexDirection,
    const Direction direction) {
  if (direction == Direction::RTL) {
    if (flexDirection == FlexDirection::Row) {
      return FlexDirection::RowReverse;
    } else if (flexDirection == FlexDirection::RowReverse) {
      return FlexDirection::Row;
    }
  }

  return flexDirection;
}

inline FlexDirection resolveCrossDirection(
    const FlexDirection flexDirection,
    const Direction direction) {
  return isColumn(flexDirection)
      ? resolveDirection(FlexDirection::Row, direction)
      : FlexDirection::Column;
}

inline _YGEdge flexStartEdge(const FlexDirection flexDirection) {
  switch (flexDirection) {
    case FlexDirection::Column:
      return _YGEdgeTop;
    case FlexDirection::ColumnReverse:
      return _YGEdgeBottom;
    case FlexDirection::Row:
      return _YGEdgeLeft;
    case FlexDirection::RowReverse:
      return _YGEdgeRight;
  }

  fatalWithMessage("Invalid FlexDirection");
}

inline _YGEdge flexEndEdge(const FlexDirection flexDirection) {
  switch (flexDirection) {
    case FlexDirection::Column:
      return _YGEdgeBottom;
    case FlexDirection::ColumnReverse:
      return _YGEdgeTop;
    case FlexDirection::Row:
      return _YGEdgeRight;
    case FlexDirection::RowReverse:
      return _YGEdgeLeft;
  }

  fatalWithMessage("Invalid FlexDirection");
}

inline _YGEdge inlineStartEdge(
    const FlexDirection flexDirection,
    const Direction direction) {
  if (isRow(flexDirection)) {
    return direction == Direction::RTL ? _YGEdgeRight : _YGEdgeLeft;
  }

  return _YGEdgeTop;
}

inline _YGEdge inlineEndEdge(
    const FlexDirection flexDirection,
    const Direction direction) {
  if (isRow(flexDirection)) {
    return direction == Direction::RTL ? _YGEdgeLeft : _YGEdgeRight;
  }

  return _YGEdgeBottom;
}

/**
 * The physical edges that _YGEdgeStart and _YGEdgeEnd correspond to (e.g.
 * left/right) are soley dependent on the direction. However, there are cases
 * where we want the flex start/end edge (i.e. which edge is the start/end
 * for laying out flex items), which can be distinct from the corresponding
 * inline edge. In these cases we need to know which "relative edge"
 * (_YGEdgeStart/_YGEdgeEnd) corresponds to the said flex start/end edge as these
 * relative edges can be used instead of physical ones when defining certain
 * attributes like border or padding.
 */
inline _YGEdge flexStartRelativeEdge(
    FlexDirection flexDirection,
    Direction direction) {
  const _YGEdge leadLayoutEdge = inlineStartEdge(flexDirection, direction);
  const _YGEdge leadFlexItemEdge = flexStartEdge(flexDirection);
  return leadLayoutEdge == leadFlexItemEdge ? _YGEdgeStart : _YGEdgeEnd;
}

inline _YGEdge flexEndRelativeEdge(
    FlexDirection flexDirection,
    Direction direction) {
  const _YGEdge trailLayoutEdge = inlineEndEdge(flexDirection, direction);
  const _YGEdge trailFlexItemEdge = flexEndEdge(flexDirection);
  return trailLayoutEdge == trailFlexItemEdge ? _YGEdgeEnd : _YGEdgeStart;
}

inline Dimension dimension(const FlexDirection flexDirection) {
  switch (flexDirection) {
    case FlexDirection::Column:
      return Dimension::Height;
    case FlexDirection::ColumnReverse:
      return Dimension::Height;
    case FlexDirection::Row:
      return Dimension::Width;
    case FlexDirection::RowReverse:
      return Dimension::Width;
  }

  fatalWithMessage("Invalid FlexDirection");
}

} // namespace facebook::yoga

namespace facebook::yoga {

inline Align resolveChildAlignment(
    const yoga::Node* node,
    const yoga::Node* child) {
  const Align align = child->getStyle().alignSelf() == Align::Auto
      ? node->getStyle().alignItems()
      : child->getStyle().alignSelf();
  if (align == Align::Baseline && isColumn(node->getStyle().flexDirection())) {
    return Align::FlexStart;
  }
  return align;
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



namespace facebook::yoga {

// Calculate baseline represented as an offset from the top edge of the node.
float calculateBaseline(const yoga::Node* node);

// Whether any of the children of this node participate in baseline alignment
bool isBaselineLayout(const yoga::Node* node);

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */




namespace facebook::yoga {

inline FloatOptional resolveValue(const _YGValue value, const float ownerSize) {
  switch (value.unit) {
    case _YGUnitPoint:
      return FloatOptional{value.value};
    case _YGUnitPercent:
      return FloatOptional{value.value * ownerSize * 0.01f};
    default:
      return FloatOptional{};
  }
}

inline FloatOptional resolveValue(CompactValue value, float ownerSize) {
  return resolveValue((_YGValue)value, ownerSize);
}

} // namespace facebook::yoga

namespace facebook::yoga {

inline float paddingAndBorderForAxis(
    const yoga::Node* const node,
    const FlexDirection axis,
    const float widthSize) {
  // The total padding/border for a given axis does not depend on the direction
  // so hardcoding LTR here to avoid piping direction to this function
  return node->getInlineStartPaddingAndBorder(axis, Direction::LTR, widthSize) +
      node->getInlineEndPaddingAndBorder(axis, Direction::LTR, widthSize);
}

inline FloatOptional boundAxisWithinMinAndMax(
    const yoga::Node* const node,
    const FlexDirection axis,
    const FloatOptional value,
    const float axisSize) {
  FloatOptional min;
  FloatOptional max;

  if (isColumn(axis)) {
    min = yoga::resolveValue(
        node->getStyle().minDimension(Dimension::Height), axisSize);
    max = yoga::resolveValue(
        node->getStyle().maxDimension(Dimension::Height), axisSize);
  } else if (isRow(axis)) {
    min = yoga::resolveValue(
        node->getStyle().minDimension(Dimension::Width), axisSize);
    max = yoga::resolveValue(
        node->getStyle().maxDimension(Dimension::Width), axisSize);
  }

  if (max >= FloatOptional{0} && value > max) {
    return max;
  }

  if (min >= FloatOptional{0} && value < min) {
    return min;
  }

  return value;
}

// Like boundAxisWithinMinAndMax but also ensures that the value doesn't
// go below the padding and border amount.
inline float boundAxis(
    const yoga::Node* const node,
    const FlexDirection axis,
    const float value,
    const float axisSize,
    const float widthSize) {
  return yoga::maxOrDefined(
      boundAxisWithinMinAndMax(node, axis, FloatOptional{value}, axisSize)
          .unwrap(),
      paddingAndBorderForAxis(node, axis, widthSize));
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <vector>


namespace facebook::yoga {

struct FlexLineRunningLayout {
  // Total flex grow factors of flex items which are to be laid in the current
  // line. This is decremented as free space is distributed.
  float totalFlexGrowFactors{0.0f};

  // Total flex shrink factors of flex items which are to be laid in the current
  // line. This is decremented as free space is distributed.
  float totalFlexShrinkScaledFactors{0.0f};

  // The amount of available space within inner dimensions of the line which may
  // still be distributed.
  float remainingFreeSpace{0.0f};

  // The size of the mainDim for the row after considering size, padding, margin
  // and border of flex items. This is used to calculate maxLineDim after going
  // through all the rows to decide on the main axis size of owner.
  float mainDim{0.0f};

  // The size of the crossDim for the row after considering size, padding,
  // margin and border of flex items. Used for calculating containers crossSize.
  float crossDim{0.0f};
};

struct FlexLine {
  // List of children which are part of the line flow. This means they are not
  // positioned absolutely, or with `display: "none"`, and do not overflow the
  // available dimensions.
  const std::vector<yoga::Node*> itemsInFlow{};

  // Accumulation of the dimensions and margin of all the children on the
  // current line. This will be used in order to either set the dimensions of
  // the node if none already exist or to compute the remaining space left for
  // the flexible children.
  const float sizeConsumed{0.0f};

  // The index of the first item beyond the current line.
  const size_t endOfLineIndex{0};

  // Layout information about the line computed in steps after line-breaking
  FlexLineRunningLayout layout{};
};

// Calculates where a line starting at a given index should break, returning
// information about the collective children on the liune.
//
// This function assumes that all the children of node have their
// computedFlexBasis properly computed(To do this use
// computeFlexBasisForChildren function).
FlexLine calculateFlexLine(
    yoga::Node* const node,
    Direction ownerDirection,
    float mainAxisownerSize,
    float availableInnerWidth,
    float availableInnerMainDim,
    size_t startOfLineIndex,
    size_t lineCount);

} // namespace facebook::yoga

namespace facebook::yoga {

std::atomic<uint32_t> gCurrentGenerationCount(0);

bool calculateLayoutInternal(
    yoga::Node* const node,
    const float availableWidth,
    const float availableHeight,
    const Direction ownerDirection,
    const MeasureMode widthMeasureMode,
    const MeasureMode heightMeasureMode,
    const float ownerWidth,
    const float ownerHeight,
    const bool performLayout,
    const LayoutPassReason reason,
    LayoutData& layoutMarkerData,
    const uint32_t depth,
    const uint32_t generationCount);

static inline float dimensionWithMargin(
    const yoga::Node* const node,
    const FlexDirection axis,
    const float widthSize) {
  return node->getLayout().measuredDimension(dimension(axis)) +
      node->getMarginForAxis(axis, widthSize);
}

static inline bool styleDefinesDimension(
    const yoga::Node* const node,
    const FlexDirection axis,
    const float ownerSize) {
  bool isDefined =
      yoga::isDefined(node->getResolvedDimension(dimension(axis)).value);

  auto resolvedDimension = node->getResolvedDimension(dimension(axis));
  return !(
      resolvedDimension.unit == _YGUnitAuto ||
      resolvedDimension.unit == _YGUnitUndefined ||
      (resolvedDimension.unit == _YGUnitPoint && isDefined &&
       resolvedDimension.value < 0.0f) ||
      (resolvedDimension.unit == _YGUnitPercent && isDefined &&
       (resolvedDimension.value < 0.0f || yoga::isUndefined(ownerSize))));
}

static inline bool isLayoutDimensionDefined(
    const yoga::Node* const node,
    const FlexDirection axis) {
  const float value = node->getLayout().measuredDimension(dimension(axis));
  return yoga::isDefined(value) && value >= 0.0f;
}

static void setChildTrailingPosition(
    const yoga::Node* const node,
    yoga::Node* const child,
    const FlexDirection axis) {
  const float size = child->getLayout().measuredDimension(dimension(axis));
  child->setLayoutPosition(
      node->getLayout().measuredDimension(dimension(axis)) - size -
          child->getLayout().position[flexStartEdge(axis)],
      flexEndEdge(axis));
}

static void constrainMaxSizeForMode(
    const yoga::Node* const node,
    const enum FlexDirection axis,
    const float ownerAxisSize,
    const float ownerWidth,
    MeasureMode* mode,
    float* size) {
  const FloatOptional maxSize =
      yoga::resolveValue(
          node->getStyle().maxDimension(dimension(axis)), ownerAxisSize) +
      FloatOptional(node->getMarginForAxis(axis, ownerWidth));
  switch (*mode) {
    case MeasureMode::Exactly:
    case MeasureMode::AtMost:
      *size = (maxSize.isUndefined() || *size < maxSize.unwrap())
          ? *size
          : maxSize.unwrap();
      break;
    case MeasureMode::Undefined:
      if (maxSize.isDefined()) {
        *mode = MeasureMode::AtMost;
        *size = maxSize.unwrap();
      }
      break;
  }
}

static void computeFlexBasisForChild(
    const yoga::Node* const node,
    yoga::Node* const child,
    const float width,
    const MeasureMode widthMode,
    const float height,
    const float ownerWidth,
    const float ownerHeight,
    const MeasureMode heightMode,
    const Direction direction,
    LayoutData& layoutMarkerData,
    const uint32_t depth,
    const uint32_t generationCount) {
  const FlexDirection mainAxis =
      resolveDirection(node->getStyle().flexDirection(), direction);
  const bool isMainAxisRow = isRow(mainAxis);
  const float mainAxisSize = isMainAxisRow ? width : height;
  const float mainAxisownerSize = isMainAxisRow ? ownerWidth : ownerHeight;

  float childWidth;
  float childHeight;
  MeasureMode childWidthMeasureMode;
  MeasureMode childHeightMeasureMode;

  const FloatOptional resolvedFlexBasis =
      yoga::resolveValue(child->resolveFlexBasisPtr(), mainAxisownerSize);
  const bool isRowStyleDimDefined =
      styleDefinesDimension(child, FlexDirection::Row, ownerWidth);
  const bool isColumnStyleDimDefined =
      styleDefinesDimension(child, FlexDirection::Column, ownerHeight);

  if (resolvedFlexBasis.isDefined() && yoga::isDefined(mainAxisSize)) {
    if (child->getLayout().computedFlexBasis.isUndefined() ||
        (child->getConfig()->isExperimentalFeatureEnabled(
             ExperimentalFeature::WebFlexBasis) &&
         child->getLayout().computedFlexBasisGeneration != generationCount)) {
      const FloatOptional paddingAndBorder =
          FloatOptional(paddingAndBorderForAxis(child, mainAxis, ownerWidth));
      child->setLayoutComputedFlexBasis(
          yoga::maxOrDefined(resolvedFlexBasis, paddingAndBorder));
    }
  } else if (isMainAxisRow && isRowStyleDimDefined) {
    // The width is definite, so use that as the flex basis.
    const FloatOptional paddingAndBorder = FloatOptional(
        paddingAndBorderForAxis(child, FlexDirection::Row, ownerWidth));

    child->setLayoutComputedFlexBasis(yoga::maxOrDefined(
        yoga::resolveValue(
            child->getResolvedDimension(Dimension::Width), ownerWidth),
        paddingAndBorder));
  } else if (!isMainAxisRow && isColumnStyleDimDefined) {
    // The height is definite, so use that as the flex basis.
    const FloatOptional paddingAndBorder = FloatOptional(
        paddingAndBorderForAxis(child, FlexDirection::Column, ownerWidth));
    child->setLayoutComputedFlexBasis(yoga::maxOrDefined(
        yoga::resolveValue(
            child->getResolvedDimension(Dimension::Height), ownerHeight),
        paddingAndBorder));
  } else {
    // Compute the flex basis and hypothetical main size (i.e. the clamped flex
    // basis).
    childWidth = _YGUndefined;
    childHeight = _YGUndefined;
    childWidthMeasureMode = MeasureMode::Undefined;
    childHeightMeasureMode = MeasureMode::Undefined;

    auto marginRow = child->getMarginForAxis(FlexDirection::Row, ownerWidth);
    auto marginColumn =
        child->getMarginForAxis(FlexDirection::Column, ownerWidth);

    if (isRowStyleDimDefined) {
      childWidth =
          yoga::resolveValue(
              child->getResolvedDimension(Dimension::Width), ownerWidth)
              .unwrap() +
          marginRow;
      childWidthMeasureMode = MeasureMode::Exactly;
    }
    if (isColumnStyleDimDefined) {
      childHeight =
          yoga::resolveValue(
              child->getResolvedDimension(Dimension::Height), ownerHeight)
              .unwrap() +
          marginColumn;
      childHeightMeasureMode = MeasureMode::Exactly;
    }

    // The W3C spec doesn't say anything about the 'overflow' property, but all
    // major browsers appear to implement the following logic.
    if ((!isMainAxisRow && node->getStyle().overflow() == Overflow::Scroll) ||
        node->getStyle().overflow() != Overflow::Scroll) {
      if (yoga::isUndefined(childWidth) && yoga::isDefined(width)) {
        childWidth = width;
        childWidthMeasureMode = MeasureMode::AtMost;
      }
    }

    if ((isMainAxisRow && node->getStyle().overflow() == Overflow::Scroll) ||
        node->getStyle().overflow() != Overflow::Scroll) {
      if (yoga::isUndefined(childHeight) && yoga::isDefined(height)) {
        childHeight = height;
        childHeightMeasureMode = MeasureMode::AtMost;
      }
    }

    const auto& childStyle = child->getStyle();
    if (childStyle.aspectRatio().isDefined()) {
      if (!isMainAxisRow && childWidthMeasureMode == MeasureMode::Exactly) {
        childHeight = marginColumn +
            (childWidth - marginRow) / childStyle.aspectRatio().unwrap();
        childHeightMeasureMode = MeasureMode::Exactly;
      } else if (
          isMainAxisRow && childHeightMeasureMode == MeasureMode::Exactly) {
        childWidth = marginRow +
            (childHeight - marginColumn) * childStyle.aspectRatio().unwrap();
        childWidthMeasureMode = MeasureMode::Exactly;
      }
    }

    // If child has no defined size in the cross axis and is set to stretch, set
    // the cross axis to be measured exactly with the available inner width

    const bool hasExactWidth =
        yoga::isDefined(width) && widthMode == MeasureMode::Exactly;
    const bool childWidthStretch =
        resolveChildAlignment(node, child) == Align::Stretch &&
        childWidthMeasureMode != MeasureMode::Exactly;
    if (!isMainAxisRow && !isRowStyleDimDefined && hasExactWidth &&
        childWidthStretch) {
      childWidth = width;
      childWidthMeasureMode = MeasureMode::Exactly;
      if (childStyle.aspectRatio().isDefined()) {
        childHeight =
            (childWidth - marginRow) / childStyle.aspectRatio().unwrap();
        childHeightMeasureMode = MeasureMode::Exactly;
      }
    }

    const bool hasExactHeight =
        yoga::isDefined(height) && heightMode == MeasureMode::Exactly;
    const bool childHeightStretch =
        resolveChildAlignment(node, child) == Align::Stretch &&
        childHeightMeasureMode != MeasureMode::Exactly;
    if (isMainAxisRow && !isColumnStyleDimDefined && hasExactHeight &&
        childHeightStretch) {
      childHeight = height;
      childHeightMeasureMode = MeasureMode::Exactly;

      if (childStyle.aspectRatio().isDefined()) {
        childWidth =
            (childHeight - marginColumn) * childStyle.aspectRatio().unwrap();
        childWidthMeasureMode = MeasureMode::Exactly;
      }
    }

    constrainMaxSizeForMode(
        child,
        FlexDirection::Row,
        ownerWidth,
        ownerWidth,
        &childWidthMeasureMode,
        &childWidth);
    constrainMaxSizeForMode(
        child,
        FlexDirection::Column,
        ownerHeight,
        ownerWidth,
        &childHeightMeasureMode,
        &childHeight);

    // Measure the child
    calculateLayoutInternal(
        child,
        childWidth,
        childHeight,
        direction,
        childWidthMeasureMode,
        childHeightMeasureMode,
        ownerWidth,
        ownerHeight,
        false,
        LayoutPassReason::kMeasureChild,
        layoutMarkerData,
        depth,
        generationCount);

    child->setLayoutComputedFlexBasis(FloatOptional(yoga::maxOrDefined(
        child->getLayout().measuredDimension(dimension(mainAxis)),
        paddingAndBorderForAxis(child, mainAxis, ownerWidth))));
  }
  child->setLayoutComputedFlexBasisGeneration(generationCount);
}

static void layoutAbsoluteChild(
    const yoga::Node* const node,
    yoga::Node* const child,
    const float width,
    const MeasureMode widthMode,
    const float height,
    const Direction direction,
    LayoutData& layoutMarkerData,
    const uint32_t depth,
    const uint32_t generationCount) {
  const FlexDirection mainAxis =
      resolveDirection(node->getStyle().flexDirection(), direction);
  const FlexDirection crossAxis = resolveCrossDirection(mainAxis, direction);
  const bool isMainAxisRow = isRow(mainAxis);

  float childWidth = _YGUndefined;
  float childHeight = _YGUndefined;
  MeasureMode childWidthMeasureMode = MeasureMode::Undefined;
  MeasureMode childHeightMeasureMode = MeasureMode::Undefined;

  auto marginRow = child->getMarginForAxis(FlexDirection::Row, width);
  auto marginColumn = child->getMarginForAxis(FlexDirection::Column, width);

  if (styleDefinesDimension(child, FlexDirection::Row, width)) {
    childWidth =
        yoga::resolveValue(child->getResolvedDimension(Dimension::Width), width)
            .unwrap() +
        marginRow;
  } else {
    // If the child doesn't have a specified width, compute the width based on
    // the left/right offsets if they're defined.
    if (child->isInlineStartPositionDefined(FlexDirection::Row, direction) &&
        child->isInlineEndPositionDefined(FlexDirection::Row, direction)) {
      childWidth = node->getLayout().measuredDimension(Dimension::Width) -
          (node->getInlineStartBorder(FlexDirection::Row, direction) +
           node->getInlineEndBorder(FlexDirection::Row, direction)) -
          (child->getInlineStartPosition(FlexDirection::Row, direction, width) +
           child->getInlineEndPosition(FlexDirection::Row, direction, width));
      childWidth =
          boundAxis(child, FlexDirection::Row, childWidth, width, width);
    }
  }

  if (styleDefinesDimension(child, FlexDirection::Column, height)) {
    childHeight = yoga::resolveValue(
                      child->getResolvedDimension(Dimension::Height), height)
                      .unwrap() +
        marginColumn;
  } else {
    // If the child doesn't have a specified height, compute the height based on
    // the top/bottom offsets if they're defined.
    if (child->isInlineStartPositionDefined(FlexDirection::Column, direction) &&
        child->isInlineEndPositionDefined(FlexDirection::Column, direction)) {
      childHeight = node->getLayout().measuredDimension(Dimension::Height) -
          (node->getInlineStartBorder(FlexDirection::Column, direction) +
           node->getInlineEndBorder(FlexDirection::Column, direction)) -
          (child->getInlineStartPosition(
               FlexDirection::Column, direction, height) +
           child->getInlineEndPosition(
               FlexDirection::Column, direction, height));
      childHeight =
          boundAxis(child, FlexDirection::Column, childHeight, height, width);
    }
  }

  // Exactly one dimension needs to be defined for us to be able to do aspect
  // ratio calculation. One dimension being the anchor and the other being
  // flexible.
  const auto& childStyle = child->getStyle();
  if (yoga::isUndefined(childWidth) ^ yoga::isUndefined(childHeight)) {
    if (childStyle.aspectRatio().isDefined()) {
      if (yoga::isUndefined(childWidth)) {
        childWidth = marginRow +
            (childHeight - marginColumn) * childStyle.aspectRatio().unwrap();
      } else if (yoga::isUndefined(childHeight)) {
        childHeight = marginColumn +
            (childWidth - marginRow) / childStyle.aspectRatio().unwrap();
      }
    }
  }

  // If we're still missing one or the other dimension, measure the content.
  if (yoga::isUndefined(childWidth) || yoga::isUndefined(childHeight)) {
    childWidthMeasureMode = yoga::isUndefined(childWidth)
        ? MeasureMode::Undefined
        : MeasureMode::Exactly;
    childHeightMeasureMode = yoga::isUndefined(childHeight)
        ? MeasureMode::Undefined
        : MeasureMode::Exactly;

    // If the size of the owner is defined then try to constrain the absolute
    // child to that size as well. This allows text within the absolute child to
    // wrap to the size of its owner. This is the same behavior as many browsers
    // implement.
    if (!isMainAxisRow && yoga::isUndefined(childWidth) &&
        widthMode != MeasureMode::Undefined && yoga::isDefined(width) &&
        width > 0) {
      childWidth = width;
      childWidthMeasureMode = MeasureMode::AtMost;
    }

    calculateLayoutInternal(
        child,
        childWidth,
        childHeight,
        direction,
        childWidthMeasureMode,
        childHeightMeasureMode,
        childWidth,
        childHeight,
        false,
        LayoutPassReason::kAbsMeasureChild,
        layoutMarkerData,
        depth,
        generationCount);
    childWidth = child->getLayout().measuredDimension(Dimension::Width) +
        child->getMarginForAxis(FlexDirection::Row, width);
    childHeight = child->getLayout().measuredDimension(Dimension::Height) +
        child->getMarginForAxis(FlexDirection::Column, width);
  }

  calculateLayoutInternal(
      child,
      childWidth,
      childHeight,
      direction,
      MeasureMode::Exactly,
      MeasureMode::Exactly,
      childWidth,
      childHeight,
      true,
      LayoutPassReason::kAbsLayout,
      layoutMarkerData,
      depth,
      generationCount);

  if (child->isFlexEndPositionDefined(mainAxis) &&
      !child->isFlexStartPositionDefined(mainAxis)) {
    child->setLayoutPosition(
        node->getLayout().measuredDimension(dimension(mainAxis)) -
            child->getLayout().measuredDimension(dimension(mainAxis)) -
            node->getFlexEndBorder(mainAxis, direction) -
            child->getFlexEndMargin(mainAxis, isMainAxisRow ? width : height) -
            child->getFlexEndPosition(mainAxis, isMainAxisRow ? width : height),
        flexStartEdge(mainAxis));
  } else if (
      !child->isFlexStartPositionDefined(mainAxis) &&
      node->getStyle().justifyContent() == Justify::Center) {
    child->setLayoutPosition(
        (node->getLayout().measuredDimension(dimension(mainAxis)) -
         child->getLayout().measuredDimension(dimension(mainAxis))) /
            2.0f,
        flexStartEdge(mainAxis));
  } else if (
      !child->isFlexStartPositionDefined(mainAxis) &&
      node->getStyle().justifyContent() == Justify::FlexEnd) {
    child->setLayoutPosition(
        (node->getLayout().measuredDimension(dimension(mainAxis)) -
         child->getLayout().measuredDimension(dimension(mainAxis))),
        flexStartEdge(mainAxis));
  } else if (
      node->getConfig()->isExperimentalFeatureEnabled(
          ExperimentalFeature::AbsolutePercentageAgainstPaddingEdge) &&
      child->isFlexStartPositionDefined(mainAxis)) {
    child->setLayoutPosition(
        child->getFlexStartPosition(
            mainAxis,
            node->getLayout().measuredDimension(dimension(mainAxis))) +
            node->getFlexStartBorder(mainAxis, direction) +
            child->getFlexStartMargin(
                mainAxis,
                node->getLayout().measuredDimension(dimension(mainAxis))),
        flexStartEdge(mainAxis));
  }

  if (child->isFlexEndPositionDefined(crossAxis) &&
      !child->isFlexStartPositionDefined(crossAxis)) {
    child->setLayoutPosition(
        node->getLayout().measuredDimension(dimension(crossAxis)) -
            child->getLayout().measuredDimension(dimension(crossAxis)) -
            node->getFlexEndBorder(crossAxis, direction) -
            child->getFlexEndMargin(crossAxis, isMainAxisRow ? height : width) -
            child->getFlexEndPosition(
                crossAxis, isMainAxisRow ? height : width),
        flexStartEdge(crossAxis));

  } else if (
      !child->isFlexStartPositionDefined(crossAxis) &&
      resolveChildAlignment(node, child) == Align::Center) {
    child->setLayoutPosition(
        (node->getLayout().measuredDimension(dimension(crossAxis)) -
         child->getLayout().measuredDimension(dimension(crossAxis))) /
            2.0f,
        flexStartEdge(crossAxis));
  } else if (
      !child->isFlexStartPositionDefined(crossAxis) &&
      ((resolveChildAlignment(node, child) == Align::FlexEnd) ^
       (node->getStyle().flexWrap() == Wrap::WrapReverse))) {
    child->setLayoutPosition(
        (node->getLayout().measuredDimension(dimension(crossAxis)) -
         child->getLayout().measuredDimension(dimension(crossAxis))),
        flexStartEdge(crossAxis));
  } else if (
      node->getConfig()->isExperimentalFeatureEnabled(
          ExperimentalFeature::AbsolutePercentageAgainstPaddingEdge) &&
      child->isFlexStartPositionDefined(crossAxis)) {
    child->setLayoutPosition(
        child->getFlexStartPosition(
            crossAxis,
            node->getLayout().measuredDimension(dimension(crossAxis))) +
            node->getFlexStartBorder(crossAxis, direction) +
            child->getFlexStartMargin(
                crossAxis,
                node->getLayout().measuredDimension(dimension(crossAxis))),
        flexStartEdge(crossAxis));
  }
}

static void measureNodeWithMeasureFunc(
    yoga::Node* const node,
    float availableWidth,
    float availableHeight,
    const MeasureMode widthMeasureMode,
    const MeasureMode heightMeasureMode,
    const float ownerWidth,
    const float ownerHeight,
    LayoutData& layoutMarkerData,
    const LayoutPassReason reason) {
  yoga::assertFatalWithNode(
      node,
      node->hasMeasureFunc(),
      "Expected node to have custom measure function");

  if (widthMeasureMode == MeasureMode::Undefined) {
    availableWidth = _YGUndefined;
  }
  if (heightMeasureMode == MeasureMode::Undefined) {
    availableHeight = _YGUndefined;
  }

  const auto& padding = node->getLayout().padding;
  const auto& border = node->getLayout().border;
  const float paddingAndBorderAxisRow = padding[_YGEdgeLeft] +
      padding[_YGEdgeRight] + border[_YGEdgeLeft] + border[_YGEdgeRight];
  const float paddingAndBorderAxisColumn = padding[_YGEdgeTop] +
      padding[_YGEdgeBottom] + border[_YGEdgeTop] + border[_YGEdgeBottom];

  // We want to make sure we don't call measure with negative size
  const float innerWidth = yoga::isUndefined(availableWidth)
      ? availableWidth
      : yoga::maxOrDefined(0.0f, availableWidth - paddingAndBorderAxisRow);
  const float innerHeight = yoga::isUndefined(availableHeight)
      ? availableHeight
      : yoga::maxOrDefined(0.0f, availableHeight - paddingAndBorderAxisColumn);

  if (widthMeasureMode == MeasureMode::Exactly &&
      heightMeasureMode == MeasureMode::Exactly) {
    // Don't bother sizing the text if both dimensions are already defined.
    node->setLayoutMeasuredDimension(
        boundAxis(
            node, FlexDirection::Row, availableWidth, ownerWidth, ownerWidth),
        Dimension::Width);
    node->setLayoutMeasuredDimension(
        boundAxis(
            node,
            FlexDirection::Column,
            availableHeight,
            ownerHeight,
            ownerWidth),
        Dimension::Height);
  } else {
    Event::publish<Event::MeasureCallbackStart>(node);

    // Measure the text under the current constraints.
    const _YGSize measuredSize = node->measure(
        innerWidth, widthMeasureMode, innerHeight, heightMeasureMode);

    layoutMarkerData.measureCallbacks += 1;
    layoutMarkerData.measureCallbackReasonsCount[static_cast<size_t>(reason)] +=
        1;

    Event::publish<Event::MeasureCallbackEnd>(
        node,
        {innerWidth,
         unscopedEnum(widthMeasureMode),
         innerHeight,
         unscopedEnum(heightMeasureMode),
         measuredSize.width,
         measuredSize.height,
         reason});

    node->setLayoutMeasuredDimension(
        boundAxis(
            node,
            FlexDirection::Row,
            (widthMeasureMode == MeasureMode::Undefined ||
             widthMeasureMode == MeasureMode::AtMost)
                ? measuredSize.width + paddingAndBorderAxisRow
                : availableWidth,
            ownerWidth,
            ownerWidth),
        Dimension::Width);

    node->setLayoutMeasuredDimension(
        boundAxis(
            node,
            FlexDirection::Column,
            (heightMeasureMode == MeasureMode::Undefined ||
             heightMeasureMode == MeasureMode::AtMost)
                ? measuredSize.height + paddingAndBorderAxisColumn
                : availableHeight,
            ownerHeight,
            ownerWidth),
        Dimension::Height);
  }
}

// For nodes with no children, use the available values if they were provided,
// or the minimum size as indicated by the padding and border sizes.
static void measureNodeWithoutChildren(
    yoga::Node* const node,
    const float availableWidth,
    const float availableHeight,
    const MeasureMode widthMeasureMode,
    const MeasureMode heightMeasureMode,
    const float ownerWidth,
    const float ownerHeight) {
  const auto& padding = node->getLayout().padding;
  const auto& border = node->getLayout().border;

  float width = availableWidth;
  if (widthMeasureMode == MeasureMode::Undefined ||
      widthMeasureMode == MeasureMode::AtMost) {
    width = padding[_YGEdgeLeft] + padding[_YGEdgeRight] + border[_YGEdgeLeft] +
        border[_YGEdgeRight];
  }
  node->setLayoutMeasuredDimension(
      boundAxis(node, FlexDirection::Row, width, ownerWidth, ownerWidth),
      Dimension::Width);

  float height = availableHeight;
  if (heightMeasureMode == MeasureMode::Undefined ||
      heightMeasureMode == MeasureMode::AtMost) {
    height = padding[_YGEdgeTop] + padding[_YGEdgeBottom] + border[_YGEdgeTop] +
        border[_YGEdgeBottom];
  }
  node->setLayoutMeasuredDimension(
      boundAxis(node, FlexDirection::Column, height, ownerHeight, ownerWidth),
      Dimension::Height);
}

static bool measureNodeWithFixedSize(
    yoga::Node* const node,
    const float availableWidth,
    const float availableHeight,
    const MeasureMode widthMeasureMode,
    const MeasureMode heightMeasureMode,
    const float ownerWidth,
    const float ownerHeight) {
  if ((yoga::isDefined(availableWidth) &&
       widthMeasureMode == MeasureMode::AtMost && availableWidth <= 0.0f) ||
      (yoga::isDefined(availableHeight) &&
       heightMeasureMode == MeasureMode::AtMost && availableHeight <= 0.0f) ||
      (widthMeasureMode == MeasureMode::Exactly &&
       heightMeasureMode == MeasureMode::Exactly)) {
    node->setLayoutMeasuredDimension(
        boundAxis(
            node,
            FlexDirection::Row,
            yoga::isUndefined(availableWidth) ||
                    (widthMeasureMode == MeasureMode::AtMost &&
                     availableWidth < 0.0f)
                ? 0.0f
                : availableWidth,
            ownerWidth,
            ownerWidth),
        Dimension::Width);

    node->setLayoutMeasuredDimension(
        boundAxis(
            node,
            FlexDirection::Column,
            yoga::isUndefined(availableHeight) ||
                    (heightMeasureMode == MeasureMode::AtMost &&
                     availableHeight < 0.0f)
                ? 0.0f
                : availableHeight,
            ownerHeight,
            ownerWidth),
        Dimension::Height);
    return true;
  }

  return false;
}

static void zeroOutLayoutRecursively(yoga::Node* const node) {
  node->getLayout() = {};
  node->setLayoutDimension(0, Dimension::Width);
  node->setLayoutDimension(0, Dimension::Height);
  node->setHasNewLayout(true);

  node->cloneChildrenIfNeeded();
  for (const auto child : node->getChildren()) {
    zeroOutLayoutRecursively(child);
  }
}

static float calculateAvailableInnerDimension(
    const yoga::Node* const node,
    const Dimension dimension,
    const float availableDim,
    const float paddingAndBorder,
    const float ownerDim) {
  float availableInnerDim = availableDim - paddingAndBorder;
  // Max dimension overrides predefined dimension value; Min dimension in turn
  // overrides both of the above
  if (yoga::isDefined(availableInnerDim)) {
    // We want to make sure our available height does not violate min and max
    // constraints
    const FloatOptional minDimensionOptional =
        yoga::resolveValue(node->getStyle().minDimension(dimension), ownerDim);
    const float minInnerDim = minDimensionOptional.isUndefined()
        ? 0.0f
        : minDimensionOptional.unwrap() - paddingAndBorder;

    const FloatOptional maxDimensionOptional =
        yoga::resolveValue(node->getStyle().maxDimension(dimension), ownerDim);

    const float maxInnerDim = maxDimensionOptional.isUndefined()
        ? FLT_MAX
        : maxDimensionOptional.unwrap() - paddingAndBorder;
    availableInnerDim = yoga::maxOrDefined(
        yoga::minOrDefined(availableInnerDim, maxInnerDim), minInnerDim);
  }

  return availableInnerDim;
}

static float computeFlexBasisForChildren(
    yoga::Node* const node,
    const float availableInnerWidth,
    const float availableInnerHeight,
    MeasureMode widthMeasureMode,
    MeasureMode heightMeasureMode,
    Direction direction,
    FlexDirection mainAxis,
    bool performLayout,
    LayoutData& layoutMarkerData,
    const uint32_t depth,
    const uint32_t generationCount) {
  float totalOuterFlexBasis = 0.0f;
  _YGNodeRef singleFlexChild = nullptr;
  const auto& children = node->getChildren();
  MeasureMode measureModeMainDim =
      isRow(mainAxis) ? widthMeasureMode : heightMeasureMode;
  // If there is only one child with flexGrow + flexShrink it means we can set
  // the computedFlexBasis to 0 instead of measuring and shrinking / flexing the
  // child to exactly match the remaining space
  if (measureModeMainDim == MeasureMode::Exactly) {
    for (auto child : children) {
      if (child->isNodeFlexible()) {
        if (singleFlexChild != nullptr ||
            yoga::inexactEquals(child->resolveFlexGrow(), 0.0f) ||
            yoga::inexactEquals(child->resolveFlexShrink(), 0.0f)) {
          // There is already a flexible child, or this flexible child doesn't
          // have flexGrow and flexShrink, abort
          singleFlexChild = nullptr;
          break;
        } else {
          singleFlexChild = child;
        }
      }
    }
  }

  for (auto child : children) {
    child->resolveDimension();
    if (child->getStyle().display() == Display::None) {
      zeroOutLayoutRecursively(child);
      child->setHasNewLayout(true);
      child->setDirty(false);
      continue;
    }
    if (performLayout) {
      // Set the initial position (relative to the owner).
      const Direction childDirection = child->resolveDirection(direction);
      const float mainDim =
          isRow(mainAxis) ? availableInnerWidth : availableInnerHeight;
      const float crossDim =
          isRow(mainAxis) ? availableInnerHeight : availableInnerWidth;
      child->setPosition(
          childDirection, mainDim, crossDim, availableInnerWidth);
    }

    if (child->getStyle().positionType() == PositionType::Absolute) {
      continue;
    }
    if (child == singleFlexChild) {
      child->setLayoutComputedFlexBasisGeneration(generationCount);
      child->setLayoutComputedFlexBasis(FloatOptional(0));
    } else {
      computeFlexBasisForChild(
          node,
          child,
          availableInnerWidth,
          widthMeasureMode,
          availableInnerHeight,
          availableInnerWidth,
          availableInnerHeight,
          heightMeasureMode,
          direction,
          layoutMarkerData,
          depth,
          generationCount);
    }

    totalOuterFlexBasis +=
        (child->getLayout().computedFlexBasis.unwrap() +
         child->getMarginForAxis(mainAxis, availableInnerWidth));
  }

  return totalOuterFlexBasis;
}

// It distributes the free space to the flexible items and ensures that the size
// of the flex items abide the min and max constraints. At the end of this
// function the child nodes would have proper size. Prior using this function
// please ensure that distributeFreeSpaceFirstPass is called.
static float distributeFreeSpaceSecondPass(
    FlexLine& flexLine,
    yoga::Node* const node,
    const FlexDirection mainAxis,
    const FlexDirection crossAxis,
    const float mainAxisownerSize,
    const float availableInnerMainDim,
    const float availableInnerCrossDim,
    const float availableInnerWidth,
    const float availableInnerHeight,
    const bool mainAxisOverflows,
    const MeasureMode measureModeCrossDim,
    const bool performLayout,
    LayoutData& layoutMarkerData,
    const uint32_t depth,
    const uint32_t generationCount) {
  float childFlexBasis = 0;
  float flexShrinkScaledFactor = 0;
  float flexGrowFactor = 0;
  float deltaFreeSpace = 0;
  const bool isMainAxisRow = isRow(mainAxis);
  const bool isNodeFlexWrap = node->getStyle().flexWrap() != Wrap::NoWrap;

  for (auto currentLineChild : flexLine.itemsInFlow) {
    childFlexBasis = boundAxisWithinMinAndMax(
                         currentLineChild,
                         mainAxis,
                         currentLineChild->getLayout().computedFlexBasis,
                         mainAxisownerSize)
                         .unwrap();
    float updatedMainSize = childFlexBasis;

    if (yoga::isDefined(flexLine.layout.remainingFreeSpace) &&
        flexLine.layout.remainingFreeSpace < 0) {
      flexShrinkScaledFactor =
          -currentLineChild->resolveFlexShrink() * childFlexBasis;
      // Is this child able to shrink?
      if (flexShrinkScaledFactor != 0) {
        float childSize;

        if (yoga::isDefined(flexLine.layout.totalFlexShrinkScaledFactors) &&
            flexLine.layout.totalFlexShrinkScaledFactors == 0) {
          childSize = childFlexBasis + flexShrinkScaledFactor;
        } else {
          childSize = childFlexBasis +
              (flexLine.layout.remainingFreeSpace /
               flexLine.layout.totalFlexShrinkScaledFactors) *
                  flexShrinkScaledFactor;
        }

        updatedMainSize = boundAxis(
            currentLineChild,
            mainAxis,
            childSize,
            availableInnerMainDim,
            availableInnerWidth);
      }
    } else if (
        yoga::isDefined(flexLine.layout.remainingFreeSpace) &&
        flexLine.layout.remainingFreeSpace > 0) {
      flexGrowFactor = currentLineChild->resolveFlexGrow();

      // Is this child able to grow?
      if (!std::isnan(flexGrowFactor) && flexGrowFactor != 0) {
        updatedMainSize = boundAxis(
            currentLineChild,
            mainAxis,
            childFlexBasis +
                flexLine.layout.remainingFreeSpace /
                    flexLine.layout.totalFlexGrowFactors * flexGrowFactor,
            availableInnerMainDim,
            availableInnerWidth);
      }
    }

    deltaFreeSpace += updatedMainSize - childFlexBasis;

    const float marginMain =
        currentLineChild->getMarginForAxis(mainAxis, availableInnerWidth);
    const float marginCross =
        currentLineChild->getMarginForAxis(crossAxis, availableInnerWidth);

    float childCrossSize;
    float childMainSize = updatedMainSize + marginMain;
    MeasureMode childCrossMeasureMode;
    MeasureMode childMainMeasureMode = MeasureMode::Exactly;

    const auto& childStyle = currentLineChild->getStyle();
    if (childStyle.aspectRatio().isDefined()) {
      childCrossSize = isMainAxisRow
          ? (childMainSize - marginMain) / childStyle.aspectRatio().unwrap()
          : (childMainSize - marginMain) * childStyle.aspectRatio().unwrap();
      childCrossMeasureMode = MeasureMode::Exactly;

      childCrossSize += marginCross;
    } else if (
        !std::isnan(availableInnerCrossDim) &&
        !styleDefinesDimension(
            currentLineChild, crossAxis, availableInnerCrossDim) &&
        measureModeCrossDim == MeasureMode::Exactly &&
        !(isNodeFlexWrap && mainAxisOverflows) &&
        resolveChildAlignment(node, currentLineChild) == Align::Stretch &&
        currentLineChild->getFlexStartMarginValue(crossAxis).unit !=
            _YGUnitAuto &&
        currentLineChild->marginTrailingValue(crossAxis).unit != _YGUnitAuto) {
      childCrossSize = availableInnerCrossDim;
      childCrossMeasureMode = MeasureMode::Exactly;
    } else if (!styleDefinesDimension(
                   currentLineChild, crossAxis, availableInnerCrossDim)) {
      childCrossSize = availableInnerCrossDim;
      childCrossMeasureMode = yoga::isUndefined(childCrossSize)
          ? MeasureMode::Undefined
          : MeasureMode::AtMost;
    } else {
      childCrossSize =
          yoga::resolveValue(
              currentLineChild->getResolvedDimension(dimension(crossAxis)),
              availableInnerCrossDim)
              .unwrap() +
          marginCross;
      const bool isLoosePercentageMeasurement =
          currentLineChild->getResolvedDimension(dimension(crossAxis)).unit ==
              _YGUnitPercent &&
          measureModeCrossDim != MeasureMode::Exactly;
      childCrossMeasureMode =
          yoga::isUndefined(childCrossSize) || isLoosePercentageMeasurement
          ? MeasureMode::Undefined
          : MeasureMode::Exactly;
    }

    constrainMaxSizeForMode(
        currentLineChild,
        mainAxis,
        availableInnerMainDim,
        availableInnerWidth,
        &childMainMeasureMode,
        &childMainSize);
    constrainMaxSizeForMode(
        currentLineChild,
        crossAxis,
        availableInnerCrossDim,
        availableInnerWidth,
        &childCrossMeasureMode,
        &childCrossSize);

    const bool requiresStretchLayout =
        !styleDefinesDimension(
            currentLineChild, crossAxis, availableInnerCrossDim) &&
        resolveChildAlignment(node, currentLineChild) == Align::Stretch &&
        currentLineChild->getFlexStartMarginValue(crossAxis).unit !=
            _YGUnitAuto &&
        currentLineChild->marginTrailingValue(crossAxis).unit != _YGUnitAuto;

    const float childWidth = isMainAxisRow ? childMainSize : childCrossSize;
    const float childHeight = !isMainAxisRow ? childMainSize : childCrossSize;

    const MeasureMode childWidthMeasureMode =
        isMainAxisRow ? childMainMeasureMode : childCrossMeasureMode;
    const MeasureMode childHeightMeasureMode =
        !isMainAxisRow ? childMainMeasureMode : childCrossMeasureMode;

    const bool isLayoutPass = performLayout && !requiresStretchLayout;
    // Recursively call the layout algorithm for this child with the updated
    // main size.
    calculateLayoutInternal(
        currentLineChild,
        childWidth,
        childHeight,
        node->getLayout().direction(),
        childWidthMeasureMode,
        childHeightMeasureMode,
        availableInnerWidth,
        availableInnerHeight,
        isLayoutPass,
        isLayoutPass ? LayoutPassReason::kFlexLayout
                     : LayoutPassReason::kFlexMeasure,
        layoutMarkerData,
        depth,
        generationCount);
    node->setLayoutHadOverflow(
        node->getLayout().hadOverflow() ||
        currentLineChild->getLayout().hadOverflow());
  }
  return deltaFreeSpace;
}

// It distributes the free space to the flexible items.For those flexible items
// whose min and max constraints are triggered, those flex item's clamped size
// is removed from the remaingfreespace.
static void distributeFreeSpaceFirstPass(
    FlexLine& flexLine,
    const FlexDirection mainAxis,
    const float mainAxisownerSize,
    const float availableInnerMainDim,
    const float availableInnerWidth) {
  float flexShrinkScaledFactor = 0;
  float flexGrowFactor = 0;
  float baseMainSize = 0;
  float boundMainSize = 0;
  float deltaFreeSpace = 0;

  for (auto currentLineChild : flexLine.itemsInFlow) {
    float childFlexBasis = boundAxisWithinMinAndMax(
                               currentLineChild,
                               mainAxis,
                               currentLineChild->getLayout().computedFlexBasis,
                               mainAxisownerSize)
                               .unwrap();

    if (flexLine.layout.remainingFreeSpace < 0) {
      flexShrinkScaledFactor =
          -currentLineChild->resolveFlexShrink() * childFlexBasis;

      // Is this child able to shrink?
      if (yoga::isDefined(flexShrinkScaledFactor) &&
          flexShrinkScaledFactor != 0) {
        baseMainSize = childFlexBasis +
            flexLine.layout.remainingFreeSpace /
                flexLine.layout.totalFlexShrinkScaledFactors *
                flexShrinkScaledFactor;
        boundMainSize = boundAxis(
            currentLineChild,
            mainAxis,
            baseMainSize,
            availableInnerMainDim,
            availableInnerWidth);
        if (yoga::isDefined(baseMainSize) && yoga::isDefined(boundMainSize) &&
            baseMainSize != boundMainSize) {
          // By excluding this item's size and flex factor from remaining, this
          // item's min/max constraints should also trigger in the second pass
          // resulting in the item's size calculation being identical in the
          // first and second passes.
          deltaFreeSpace += boundMainSize - childFlexBasis;
          flexLine.layout.totalFlexShrinkScaledFactors -=
              (-currentLineChild->resolveFlexShrink() *
               currentLineChild->getLayout().computedFlexBasis.unwrap());
        }
      }
    } else if (
        yoga::isDefined(flexLine.layout.remainingFreeSpace) &&
        flexLine.layout.remainingFreeSpace > 0) {
      flexGrowFactor = currentLineChild->resolveFlexGrow();

      // Is this child able to grow?
      if (yoga::isDefined(flexGrowFactor) && flexGrowFactor != 0) {
        baseMainSize = childFlexBasis +
            flexLine.layout.remainingFreeSpace /
                flexLine.layout.totalFlexGrowFactors * flexGrowFactor;
        boundMainSize = boundAxis(
            currentLineChild,
            mainAxis,
            baseMainSize,
            availableInnerMainDim,
            availableInnerWidth);

        if (yoga::isDefined(baseMainSize) && yoga::isDefined(boundMainSize) &&
            baseMainSize != boundMainSize) {
          // By excluding this item's size and flex factor from remaining, this
          // item's min/max constraints should also trigger in the second pass
          // resulting in the item's size calculation being identical in the
          // first and second passes.
          deltaFreeSpace += boundMainSize - childFlexBasis;
          flexLine.layout.totalFlexGrowFactors -= flexGrowFactor;
        }
      }
    }
  }
  flexLine.layout.remainingFreeSpace -= deltaFreeSpace;
}

// Do two passes over the flex items to figure out how to distribute the
// remaining space.
//
// The first pass finds the items whose min/max constraints trigger, freezes
// them at those sizes, and excludes those sizes from the remaining space.
//
// The second pass sets the size of each flexible item. It distributes the
// remaining space amongst the items whose min/max constraints didn't trigger in
// the first pass. For the other items, it sets their sizes by forcing their
// min/max constraints to trigger again.
//
// This two pass approach for resolving min/max constraints deviates from the
// spec. The spec
// (https://www.w3.org/TR/CSS-flexbox-1/#resolve-flexible-lengths) describes a
// process that needs to be repeated a variable number of times. The algorithm
// implemented here won't handle all cases but it was simpler to implement and
// it mitigates performance concerns because we know exactly how many passes
// it'll do.
//
// At the end of this function the child nodes would have the proper size
// assigned to them.
//
static void resolveFlexibleLength(
    yoga::Node* const node,
    FlexLine& flexLine,
    const FlexDirection mainAxis,
    const FlexDirection crossAxis,
    const float mainAxisownerSize,
    const float availableInnerMainDim,
    const float availableInnerCrossDim,
    const float availableInnerWidth,
    const float availableInnerHeight,
    const bool mainAxisOverflows,
    const MeasureMode measureModeCrossDim,
    const bool performLayout,
    LayoutData& layoutMarkerData,
    const uint32_t depth,
    const uint32_t generationCount) {
  const float originalFreeSpace = flexLine.layout.remainingFreeSpace;
  // First pass: detect the flex items whose min/max constraints trigger
  distributeFreeSpaceFirstPass(
      flexLine,
      mainAxis,
      mainAxisownerSize,
      availableInnerMainDim,
      availableInnerWidth);

  // Second pass: resolve the sizes of the flexible items
  const float distributedFreeSpace = distributeFreeSpaceSecondPass(
      flexLine,
      node,
      mainAxis,
      crossAxis,
      mainAxisownerSize,
      availableInnerMainDim,
      availableInnerCrossDim,
      availableInnerWidth,
      availableInnerHeight,
      mainAxisOverflows,
      measureModeCrossDim,
      performLayout,
      layoutMarkerData,
      depth,
      generationCount);

  flexLine.layout.remainingFreeSpace = originalFreeSpace - distributedFreeSpace;
}

static void justifyMainAxis(
    yoga::Node* const node,
    FlexLine& flexLine,
    const size_t startOfLineIndex,
    const FlexDirection mainAxis,
    const FlexDirection crossAxis,
    const Direction direction,
    const MeasureMode measureModeMainDim,
    const MeasureMode measureModeCrossDim,
    const float mainAxisownerSize,
    const float ownerWidth,
    const float availableInnerMainDim,
    const float availableInnerCrossDim,
    const float availableInnerWidth,
    const bool performLayout) {
  const auto& style = node->getStyle();

  const float leadingPaddingAndBorderMain =
      node->hasErrata(Errata::StartingEndingEdgeFromFlexDirection)
      ? node->getInlineStartPaddingAndBorder(mainAxis, direction, ownerWidth)
      : node->getFlexStartPaddingAndBorder(mainAxis, direction, ownerWidth);
  const float trailingPaddingAndBorderMain =
      node->hasErrata(Errata::StartingEndingEdgeFromFlexDirection)
      ? node->getInlineEndPaddingAndBorder(mainAxis, direction, ownerWidth)
      : node->getFlexEndPaddingAndBorder(mainAxis, direction, ownerWidth);

  const float gap = node->getGapForAxis(mainAxis);
  // If we are using "at most" rules in the main axis, make sure that
  // remainingFreeSpace is 0 when min main dimension is not given
  if (measureModeMainDim == MeasureMode::AtMost &&
      flexLine.layout.remainingFreeSpace > 0) {
    if (style.minDimension(dimension(mainAxis)).isDefined() &&
        yoga::resolveValue(
            style.minDimension(dimension(mainAxis)), mainAxisownerSize)
            .isDefined()) {
      // This condition makes sure that if the size of main dimension(after
      // considering child nodes main dim, leading and trailing padding etc)
      // falls below min dimension, then the remainingFreeSpace is reassigned
      // considering the min dimension

      // `minAvailableMainDim` denotes minimum available space in which child
      // can be laid out, it will exclude space consumed by padding and border.
      const float minAvailableMainDim =
          yoga::resolveValue(
              style.minDimension(dimension(mainAxis)), mainAxisownerSize)
              .unwrap() -
          leadingPaddingAndBorderMain - trailingPaddingAndBorderMain;
      const float occupiedSpaceByChildNodes =
          availableInnerMainDim - flexLine.layout.remainingFreeSpace;
      flexLine.layout.remainingFreeSpace = yoga::maxOrDefined(
          0.0f, minAvailableMainDim - occupiedSpaceByChildNodes);
    } else {
      flexLine.layout.remainingFreeSpace = 0;
    }
  }

  int numberOfAutoMarginsOnCurrentLine = 0;
  for (size_t i = startOfLineIndex; i < flexLine.endOfLineIndex; i++) {
    auto child = node->getChild(i);
    if (child->getStyle().positionType() != PositionType::Absolute) {
      if (child->getFlexStartMarginValue(mainAxis).unit == _YGUnitAuto) {
        numberOfAutoMarginsOnCurrentLine++;
      }
      if (child->marginTrailingValue(mainAxis).unit == _YGUnitAuto) {
        numberOfAutoMarginsOnCurrentLine++;
      }
    }
  }

  // In order to position the elements in the main axis, we have two controls.
  // The space between the beginning and the first element and the space between
  // each two elements.
  float leadingMainDim = 0;
  float betweenMainDim = gap;
  const Justify justifyContent = node->getStyle().justifyContent();

  if (numberOfAutoMarginsOnCurrentLine == 0) {
    switch (justifyContent) {
      case Justify::Center:
        leadingMainDim = flexLine.layout.remainingFreeSpace / 2;
        break;
      case Justify::FlexEnd:
        leadingMainDim = flexLine.layout.remainingFreeSpace;
        break;
      case Justify::SpaceBetween:
        if (flexLine.itemsInFlow.size() > 1) {
          betweenMainDim +=
              yoga::maxOrDefined(flexLine.layout.remainingFreeSpace, 0.0f) /
              static_cast<float>(flexLine.itemsInFlow.size() - 1);
        }
        break;
      case Justify::SpaceEvenly:
        // Space is distributed evenly across all elements
        leadingMainDim = flexLine.layout.remainingFreeSpace /
            static_cast<float>(flexLine.itemsInFlow.size() + 1);
        betweenMainDim += leadingMainDim;
        break;
      case Justify::SpaceAround:
        // Space on the edges is half of the space between elements
        leadingMainDim = 0.5f * flexLine.layout.remainingFreeSpace /
            static_cast<float>(flexLine.itemsInFlow.size());
        betweenMainDim += leadingMainDim * 2;
        break;
      case Justify::FlexStart:
        break;
    }
  }

  flexLine.layout.mainDim = leadingPaddingAndBorderMain + leadingMainDim;
  flexLine.layout.crossDim = 0;

  float maxAscentForCurrentLine = 0;
  float maxDescentForCurrentLine = 0;
  bool isNodeBaselineLayout = isBaselineLayout(node);
  for (size_t i = startOfLineIndex; i < flexLine.endOfLineIndex; i++) {
    const auto child = node->getChild(i);
    const Style& childStyle = child->getStyle();
    const LayoutResults& childLayout = child->getLayout();
    if (childStyle.display() == Display::None) {
      continue;
    }
    if (childStyle.positionType() == PositionType::Absolute &&
        child->isInlineStartPositionDefined(mainAxis, direction)) {
      if (performLayout) {
        // In case the child is position absolute and has left/top being
        // defined, we override the position to whatever the user said (and
        // margin/border).
        child->setLayoutPosition(
            child->getInlineStartPosition(
                mainAxis, direction, availableInnerMainDim) +
                node->getInlineStartBorder(mainAxis, direction) +
                child->getInlineStartMargin(
                    mainAxis, direction, availableInnerWidth),
            flexStartEdge(mainAxis));
      }
    } else {
      // Now that we placed the element, we need to update the variables.
      // We need to do that only for relative elements. Absolute elements do not
      // take part in that phase.
      if (childStyle.positionType() != PositionType::Absolute) {
        if (child->getFlexStartMarginValue(mainAxis).unit == _YGUnitAuto) {
          flexLine.layout.mainDim += flexLine.layout.remainingFreeSpace /
              static_cast<float>(numberOfAutoMarginsOnCurrentLine);
        }

        if (performLayout) {
          child->setLayoutPosition(
              childLayout.position[flexStartEdge(mainAxis)] +
                  flexLine.layout.mainDim,
              flexStartEdge(mainAxis));
        }

        if (child != flexLine.itemsInFlow.back()) {
          flexLine.layout.mainDim += betweenMainDim;
        }

        if (child->marginTrailingValue(mainAxis).unit == _YGUnitAuto) {
          flexLine.layout.mainDim += flexLine.layout.remainingFreeSpace /
              static_cast<float>(numberOfAutoMarginsOnCurrentLine);
        }
        bool canSkipFlex =
            !performLayout && measureModeCrossDim == MeasureMode::Exactly;
        if (canSkipFlex) {
          // If we skipped the flex step, then we can't rely on the measuredDims
          // because they weren't computed. This means we can't call
          // dimensionWithMargin.
          flexLine.layout.mainDim +=
              child->getMarginForAxis(mainAxis, availableInnerWidth) +
              childLayout.computedFlexBasis.unwrap();
          flexLine.layout.crossDim = availableInnerCrossDim;
        } else {
          // The main dimension is the sum of all the elements dimension plus
          // the spacing.
          flexLine.layout.mainDim +=
              dimensionWithMargin(child, mainAxis, availableInnerWidth);

          if (isNodeBaselineLayout) {
            // If the child is baseline aligned then the cross dimension is
            // calculated by adding maxAscent and maxDescent from the baseline.
            const float ascent = calculateBaseline(child) +
                child->getInlineStartMargin(
                    FlexDirection::Column, direction, availableInnerWidth);
            const float descent =
                child->getLayout().measuredDimension(Dimension::Height) +
                child->getMarginForAxis(
                    FlexDirection::Column, availableInnerWidth) -
                ascent;

            maxAscentForCurrentLine =
                yoga::maxOrDefined(maxAscentForCurrentLine, ascent);
            maxDescentForCurrentLine =
                yoga::maxOrDefined(maxDescentForCurrentLine, descent);
          } else {
            // The cross dimension is the max of the elements dimension since
            // there can only be one element in that cross dimension in the case
            // when the items are not baseline aligned
            flexLine.layout.crossDim = yoga::maxOrDefined(
                flexLine.layout.crossDim,
                dimensionWithMargin(child, crossAxis, availableInnerWidth));
          }
        }
      } else if (performLayout) {
        child->setLayoutPosition(
            childLayout.position[flexStartEdge(mainAxis)] +
                node->getInlineStartBorder(mainAxis, direction) +
                leadingMainDim,
            flexStartEdge(mainAxis));
      }
    }
  }
  flexLine.layout.mainDim += trailingPaddingAndBorderMain;

  if (isNodeBaselineLayout) {
    flexLine.layout.crossDim =
        maxAscentForCurrentLine + maxDescentForCurrentLine;
  }
}

//
// This is the main routine that implements a subset of the flexbox layout
// algorithm described in the W3C CSS documentation:
// https://www.w3.org/TR/CSS3-flexbox/.
//
// Limitations of this algorithm, compared to the full standard:
//  * Display property is always assumed to be 'flex' except for Text nodes,
//    which are assumed to be 'inline-flex'.
//  * The 'zIndex' property (or any form of z ordering) is not supported. Nodes
//    are stacked in document order.
//  * The 'order' property is not supported. The order of flex items is always
//    defined by document order.
//  * The 'visibility' property is always assumed to be 'visible'. Values of
//    'collapse' and 'hidden' are not supported.
//  * There is no support for forced breaks.
//  * It does not support vertical inline directions (top-to-bottom or
//    bottom-to-top text).
//
// Deviations from standard:
//  * Section 4.5 of the spec indicates that all flex items have a default
//    minimum main size. For text blocks, for example, this is the width of the
//    widest word. Calculating the minimum width is expensive, so we forego it
//    and assume a default minimum main size of 0.
//  * Min/Max sizes in the main axis are not honored when resolving flexible
//    lengths.
//  * The spec indicates that the default value for 'flexDirection' is 'row',
//    but the algorithm below assumes a default of 'column'.
//
// Input parameters:
//    - node: current node to be sized and laid out
//    - availableWidth & availableHeight: available size to be used for sizing
//      the node or _YGUndefined if the size is not available; interpretation
//      depends on layout flags
//    - ownerDirection: the inline (text) direction within the owner
//      (left-to-right or right-to-left)
//    - widthMeasureMode: indicates the sizing rules for the width (see below
//      for explanation)
//    - heightMeasureMode: indicates the sizing rules for the height (see below
//      for explanation)
//    - performLayout: specifies whether the caller is interested in just the
//      dimensions of the node or it requires the entire node and its subtree to
//      be laid out (with final positions)
//
// Details:
//    This routine is called recursively to lay out subtrees of flexbox
//    elements. It uses the information in node.style, which is treated as a
//    read-only input. It is responsible for setting the layout.direction and
//    layout.measuredDimensions fields for the input node as well as the
//    layout.position and layout.lineIndex fields for its child nodes. The
//    layout.measuredDimensions field includes any border or padding for the
//    node but does not include margins.
//
//    The spec describes four different layout modes: "fill available", "max
//    content", "min content", and "fit content". Of these, we don't use "min
//    content" because we don't support default minimum main sizes (see above
//    for details). Each of our measure modes maps to a layout mode from the
//    spec (https://www.w3.org/TR/CSS3-sizing/#terms):
//      - MeasureMode::Undefined: max content
//      - MeasureMode::Exactly: fill available
//      - MeasureMode::AtMost: fit content
//
//    When calling calculateLayoutImpl and calculateLayoutInternal, if the
//    caller passes an available size of undefined then it must also pass a
//    measure mode of MeasureMode::Undefined in that dimension.
//
static void calculateLayoutImpl(
    yoga::Node* const node,
    const float availableWidth,
    const float availableHeight,
    const Direction ownerDirection,
    const MeasureMode widthMeasureMode,
    const MeasureMode heightMeasureMode,
    const float ownerWidth,
    const float ownerHeight,
    const bool performLayout,
    LayoutData& layoutMarkerData,
    const uint32_t depth,
    const uint32_t generationCount,
    const LayoutPassReason reason) {
  yoga::assertFatalWithNode(
      node,
      yoga::isUndefined(availableWidth)
          ? widthMeasureMode == MeasureMode::Undefined
          : true,
      "availableWidth is indefinite so widthMeasureMode must be "
      "MeasureMode::Undefined");
  yoga::assertFatalWithNode(
      node,
      yoga::isUndefined(availableHeight)
          ? heightMeasureMode == MeasureMode::Undefined
          : true,
      "availableHeight is indefinite so heightMeasureMode must be "
      "MeasureMode::Undefined");

  (performLayout ? layoutMarkerData.layouts : layoutMarkerData.measures) += 1;

  // Set the resolved resolution in the node's layout.
  const Direction direction = node->resolveDirection(ownerDirection);
  node->setLayoutDirection(direction);

  const FlexDirection flexRowDirection =
      resolveDirection(FlexDirection::Row, direction);
  const FlexDirection flexColumnDirection =
      resolveDirection(FlexDirection::Column, direction);

  const _YGEdge startEdge =
      direction == Direction::LTR ? _YGEdgeLeft : _YGEdgeRight;
  const _YGEdge endEdge = direction == Direction::LTR ? _YGEdgeRight : _YGEdgeLeft;

  const float marginRowLeading =
      node->getInlineStartMargin(flexRowDirection, direction, ownerWidth);
  node->setLayoutMargin(marginRowLeading, startEdge);
  const float marginRowTrailing =
      node->getInlineEndMargin(flexRowDirection, direction, ownerWidth);
  node->setLayoutMargin(marginRowTrailing, endEdge);
  const float marginColumnLeading =
      node->getInlineStartMargin(flexColumnDirection, direction, ownerWidth);
  node->setLayoutMargin(marginColumnLeading, _YGEdgeTop);
  const float marginColumnTrailing =
      node->getInlineEndMargin(flexColumnDirection, direction, ownerWidth);
  node->setLayoutMargin(marginColumnTrailing, _YGEdgeBottom);

  const float marginAxisRow = marginRowLeading + marginRowTrailing;
  const float marginAxisColumn = marginColumnLeading + marginColumnTrailing;

  node->setLayoutBorder(
      node->getInlineStartBorder(flexRowDirection, direction), startEdge);
  node->setLayoutBorder(
      node->getInlineEndBorder(flexRowDirection, direction), endEdge);
  node->setLayoutBorder(
      node->getInlineStartBorder(flexColumnDirection, direction), _YGEdgeTop);
  node->setLayoutBorder(
      node->getInlineEndBorder(flexColumnDirection, direction), _YGEdgeBottom);

  node->setLayoutPadding(
      node->getInlineStartPadding(flexRowDirection, direction, ownerWidth),
      startEdge);
  node->setLayoutPadding(
      node->getInlineEndPadding(flexRowDirection, direction, ownerWidth),
      endEdge);
  node->setLayoutPadding(
      node->getInlineStartPadding(flexColumnDirection, direction, ownerWidth),
      _YGEdgeTop);
  node->setLayoutPadding(
      node->getInlineEndPadding(flexColumnDirection, direction, ownerWidth),
      _YGEdgeBottom);

  if (node->hasMeasureFunc()) {
    measureNodeWithMeasureFunc(
        node,
        availableWidth - marginAxisRow,
        availableHeight - marginAxisColumn,
        widthMeasureMode,
        heightMeasureMode,
        ownerWidth,
        ownerHeight,
        layoutMarkerData,
        reason);
    return;
  }

  const auto childCount = node->getChildCount();
  if (childCount == 0) {
    measureNodeWithoutChildren(
        node,
        availableWidth - marginAxisRow,
        availableHeight - marginAxisColumn,
        widthMeasureMode,
        heightMeasureMode,
        ownerWidth,
        ownerHeight);
    return;
  }

  // If we're not being asked to perform a full layout we can skip the algorithm
  // if we already know the size
  if (!performLayout &&
      measureNodeWithFixedSize(
          node,
          availableWidth - marginAxisRow,
          availableHeight - marginAxisColumn,
          widthMeasureMode,
          heightMeasureMode,
          ownerWidth,
          ownerHeight)) {
    return;
  }

  // At this point we know we're going to perform work. Ensure that each child
  // has a mutable copy.
  node->cloneChildrenIfNeeded();
  // Reset layout flags, as they could have changed.
  node->setLayoutHadOverflow(false);

  // STEP 1: CALCULATE VALUES FOR REMAINDER OF ALGORITHM
  const FlexDirection mainAxis =
      resolveDirection(node->getStyle().flexDirection(), direction);
  const FlexDirection crossAxis = resolveCrossDirection(mainAxis, direction);
  const bool isMainAxisRow = isRow(mainAxis);
  const bool isNodeFlexWrap = node->getStyle().flexWrap() != Wrap::NoWrap;

  const float mainAxisownerSize = isMainAxisRow ? ownerWidth : ownerHeight;
  const float crossAxisownerSize = isMainAxisRow ? ownerHeight : ownerWidth;

  const float paddingAndBorderAxisMain =
      paddingAndBorderForAxis(node, mainAxis, ownerWidth);
  const float paddingAndBorderAxisCross =
      paddingAndBorderForAxis(node, crossAxis, ownerWidth);
  const float leadingPaddingAndBorderCross =
      node->getInlineStartPaddingAndBorder(crossAxis, direction, ownerWidth);

  MeasureMode measureModeMainDim =
      isMainAxisRow ? widthMeasureMode : heightMeasureMode;
  MeasureMode measureModeCrossDim =
      isMainAxisRow ? heightMeasureMode : widthMeasureMode;

  const float paddingAndBorderAxisRow =
      isMainAxisRow ? paddingAndBorderAxisMain : paddingAndBorderAxisCross;
  const float paddingAndBorderAxisColumn =
      isMainAxisRow ? paddingAndBorderAxisCross : paddingAndBorderAxisMain;

  // STEP 2: DETERMINE AVAILABLE SIZE IN MAIN AND CROSS DIRECTIONS

  float availableInnerWidth = calculateAvailableInnerDimension(
      node,
      Dimension::Width,
      availableWidth - marginAxisRow,
      paddingAndBorderAxisRow,
      ownerWidth);
  float availableInnerHeight = calculateAvailableInnerDimension(
      node,
      Dimension::Height,
      availableHeight - marginAxisColumn,
      paddingAndBorderAxisColumn,
      ownerHeight);

  float availableInnerMainDim =
      isMainAxisRow ? availableInnerWidth : availableInnerHeight;
  const float availableInnerCrossDim =
      isMainAxisRow ? availableInnerHeight : availableInnerWidth;

  // STEP 3: DETERMINE FLEX BASIS FOR EACH ITEM

  // Computed basis + margins + gap
  float totalMainDim = 0;
  totalMainDim += computeFlexBasisForChildren(
      node,
      availableInnerWidth,
      availableInnerHeight,
      widthMeasureMode,
      heightMeasureMode,
      direction,
      mainAxis,
      performLayout,
      layoutMarkerData,
      depth,
      generationCount);

  if (childCount > 1) {
    totalMainDim +=
        node->getGapForAxis(mainAxis) * static_cast<float>(childCount - 1);
  }

  const bool mainAxisOverflows =
      (measureModeMainDim != MeasureMode::Undefined) &&
      totalMainDim > availableInnerMainDim;

  if (isNodeFlexWrap && mainAxisOverflows &&
      measureModeMainDim == MeasureMode::AtMost) {
    measureModeMainDim = MeasureMode::Exactly;
  }
  // STEP 4: COLLECT FLEX ITEMS INTO FLEX LINES

  // Indexes of children that represent the first and last items in the line.
  size_t startOfLineIndex = 0;
  size_t endOfLineIndex = 0;

  // Number of lines.
  size_t lineCount = 0;

  // Accumulated cross dimensions of all lines so far.
  float totalLineCrossDim = 0;

  const float crossAxisGap = node->getGapForAxis(crossAxis);

  // Max main dimension of all the lines.
  float maxLineMainDim = 0;
  for (; endOfLineIndex < childCount;
       lineCount++, startOfLineIndex = endOfLineIndex) {
    auto flexLine = calculateFlexLine(
        node,
        ownerDirection,
        mainAxisownerSize,
        availableInnerWidth,
        availableInnerMainDim,
        startOfLineIndex,
        lineCount);

    endOfLineIndex = flexLine.endOfLineIndex;

    // If we don't need to measure the cross axis, we can skip the entire flex
    // step.
    const bool canSkipFlex =
        !performLayout && measureModeCrossDim == MeasureMode::Exactly;

    // STEP 5: RESOLVING FLEXIBLE LENGTHS ON MAIN AXIS
    // Calculate the remaining available space that needs to be allocated. If
    // the main dimension size isn't known, it is computed based on the line
    // length, so there's no more space left to distribute.

    bool sizeBasedOnContent = false;
    // If we don't measure with exact main dimension we want to ensure we don't
    // violate min and max
    if (measureModeMainDim != MeasureMode::Exactly) {
      const auto& style = node->getStyle();
      const float minInnerWidth =
          yoga::resolveValue(style.minDimension(Dimension::Width), ownerWidth)
              .unwrap() -
          paddingAndBorderAxisRow;
      const float maxInnerWidth =
          yoga::resolveValue(style.maxDimension(Dimension::Width), ownerWidth)
              .unwrap() -
          paddingAndBorderAxisRow;
      const float minInnerHeight =
          yoga::resolveValue(style.minDimension(Dimension::Height), ownerHeight)
              .unwrap() -
          paddingAndBorderAxisColumn;
      const float maxInnerHeight =
          yoga::resolveValue(style.maxDimension(Dimension::Height), ownerHeight)
              .unwrap() -
          paddingAndBorderAxisColumn;

      const float minInnerMainDim =
          isMainAxisRow ? minInnerWidth : minInnerHeight;
      const float maxInnerMainDim =
          isMainAxisRow ? maxInnerWidth : maxInnerHeight;

      if (yoga::isDefined(minInnerMainDim) &&
          flexLine.sizeConsumed < minInnerMainDim) {
        availableInnerMainDim = minInnerMainDim;
      } else if (
          yoga::isDefined(maxInnerMainDim) &&
          flexLine.sizeConsumed > maxInnerMainDim) {
        availableInnerMainDim = maxInnerMainDim;
      } else {
        bool useLegacyStretchBehaviour =
            node->hasErrata(Errata::StretchFlexBasis);

        if (!useLegacyStretchBehaviour &&
            ((yoga::isDefined(flexLine.layout.totalFlexGrowFactors) &&
              flexLine.layout.totalFlexGrowFactors == 0) ||
             (yoga::isDefined(node->resolveFlexGrow()) &&
              node->resolveFlexGrow() == 0))) {
          // If we don't have any children to flex or we can't flex the node
          // itself, space we've used is all space we need. Root node also
          // should be shrunk to minimum
          availableInnerMainDim = flexLine.sizeConsumed;
        }

        sizeBasedOnContent = !useLegacyStretchBehaviour;
      }
    }

    if (!sizeBasedOnContent && yoga::isDefined(availableInnerMainDim)) {
      flexLine.layout.remainingFreeSpace =
          availableInnerMainDim - flexLine.sizeConsumed;
    } else if (flexLine.sizeConsumed < 0) {
      // availableInnerMainDim is indefinite which means the node is being sized
      // based on its content. sizeConsumed is negative which means
      // the node will allocate 0 points for its content. Consequently,
      // remainingFreeSpace is 0 - sizeConsumed.
      flexLine.layout.remainingFreeSpace = -flexLine.sizeConsumed;
    }

    if (!canSkipFlex) {
      resolveFlexibleLength(
          node,
          flexLine,
          mainAxis,
          crossAxis,
          mainAxisownerSize,
          availableInnerMainDim,
          availableInnerCrossDim,
          availableInnerWidth,
          availableInnerHeight,
          mainAxisOverflows,
          measureModeCrossDim,
          performLayout,
          layoutMarkerData,
          depth,
          generationCount);
    }

    node->setLayoutHadOverflow(
        node->getLayout().hadOverflow() ||
        (flexLine.layout.remainingFreeSpace < 0));

    // STEP 6: MAIN-AXIS JUSTIFICATION & CROSS-AXIS SIZE DETERMINATION

    // At this point, all the children have their dimensions set in the main
    // axis. Their dimensions are also set in the cross axis with the exception
    // of items that are aligned "stretch". We need to compute these stretch
    // values and set the final positions.

    justifyMainAxis(
        node,
        flexLine,
        startOfLineIndex,
        mainAxis,
        crossAxis,
        direction,
        measureModeMainDim,
        measureModeCrossDim,
        mainAxisownerSize,
        ownerWidth,
        availableInnerMainDim,
        availableInnerCrossDim,
        availableInnerWidth,
        performLayout);

    float containerCrossAxis = availableInnerCrossDim;
    if (measureModeCrossDim == MeasureMode::Undefined ||
        measureModeCrossDim == MeasureMode::AtMost) {
      // Compute the cross axis from the max cross dimension of the children.
      containerCrossAxis =
          boundAxis(
              node,
              crossAxis,
              flexLine.layout.crossDim + paddingAndBorderAxisCross,
              crossAxisownerSize,
              ownerWidth) -
          paddingAndBorderAxisCross;
    }

    // If there's no flex wrap, the cross dimension is defined by the container.
    if (!isNodeFlexWrap && measureModeCrossDim == MeasureMode::Exactly) {
      flexLine.layout.crossDim = availableInnerCrossDim;
    }

    // Clamp to the min/max size specified on the container.
    flexLine.layout.crossDim =
        boundAxis(
            node,
            crossAxis,
            flexLine.layout.crossDim + paddingAndBorderAxisCross,
            crossAxisownerSize,
            ownerWidth) -
        paddingAndBorderAxisCross;

    // STEP 7: CROSS-AXIS ALIGNMENT
    // We can skip child alignment if we're just measuring the container.
    if (performLayout) {
      for (size_t i = startOfLineIndex; i < endOfLineIndex; i++) {
        const auto child = node->getChild(i);
        if (child->getStyle().display() == Display::None) {
          continue;
        }
        if (child->getStyle().positionType() == PositionType::Absolute) {
          // If the child is absolutely positioned and has a
          // top/left/bottom/right set, override all the previously computed
          // positions to set it correctly.
          const bool isChildLeadingPosDefined =
              child->isInlineStartPositionDefined(crossAxis, direction);
          if (isChildLeadingPosDefined) {
            child->setLayoutPosition(
                child->getInlineStartPosition(
                    crossAxis, direction, availableInnerCrossDim) +
                    node->getInlineStartBorder(crossAxis, direction) +
                    child->getInlineStartMargin(
                        crossAxis, direction, availableInnerWidth),
                flexStartEdge(crossAxis));
          }
          // If leading position is not defined or calculations result in Nan,
          // default to border + margin
          if (!isChildLeadingPosDefined ||
              yoga::isUndefined(
                  child->getLayout().position[flexStartEdge(crossAxis)])) {
            child->setLayoutPosition(
                node->getInlineStartBorder(crossAxis, direction) +
                    child->getInlineStartMargin(
                        crossAxis, direction, availableInnerWidth),
                flexStartEdge(crossAxis));
          }
        } else {
          float leadingCrossDim = leadingPaddingAndBorderCross;

          // For a relative children, we're either using alignItems (owner) or
          // alignSelf (child) in order to determine the position in the cross
          // axis
          const Align alignItem = resolveChildAlignment(node, child);

          // If the child uses align stretch, we need to lay it out one more
          // time, this time forcing the cross-axis size to be the computed
          // cross size for the current line.
          if (alignItem == Align::Stretch &&
              child->getFlexStartMarginValue(crossAxis).unit != _YGUnitAuto &&
              child->marginTrailingValue(crossAxis).unit != _YGUnitAuto) {
            // If the child defines a definite size for its cross axis, there's
            // no need to stretch.
            if (!styleDefinesDimension(
                    child, crossAxis, availableInnerCrossDim)) {
              float childMainSize =
                  child->getLayout().measuredDimension(dimension(mainAxis));
              const auto& childStyle = child->getStyle();
              float childCrossSize = childStyle.aspectRatio().isDefined()
                  ? child->getMarginForAxis(crossAxis, availableInnerWidth) +
                      (isMainAxisRow
                           ? childMainSize / childStyle.aspectRatio().unwrap()
                           : childMainSize * childStyle.aspectRatio().unwrap())
                  : flexLine.layout.crossDim;

              childMainSize +=
                  child->getMarginForAxis(mainAxis, availableInnerWidth);

              MeasureMode childMainMeasureMode = MeasureMode::Exactly;
              MeasureMode childCrossMeasureMode = MeasureMode::Exactly;
              constrainMaxSizeForMode(
                  child,
                  mainAxis,
                  availableInnerMainDim,
                  availableInnerWidth,
                  &childMainMeasureMode,
                  &childMainSize);
              constrainMaxSizeForMode(
                  child,
                  crossAxis,
                  availableInnerCrossDim,
                  availableInnerWidth,
                  &childCrossMeasureMode,
                  &childCrossSize);

              const float childWidth =
                  isMainAxisRow ? childMainSize : childCrossSize;
              const float childHeight =
                  !isMainAxisRow ? childMainSize : childCrossSize;

              auto alignContent = node->getStyle().alignContent();
              auto crossAxisDoesNotGrow =
                  alignContent != Align::Stretch && isNodeFlexWrap;
              const MeasureMode childWidthMeasureMode =
                  yoga::isUndefined(childWidth) ||
                      (!isMainAxisRow && crossAxisDoesNotGrow)
                  ? MeasureMode::Undefined
                  : MeasureMode::Exactly;
              const MeasureMode childHeightMeasureMode =
                  yoga::isUndefined(childHeight) ||
                      (isMainAxisRow && crossAxisDoesNotGrow)
                  ? MeasureMode::Undefined
                  : MeasureMode::Exactly;

              calculateLayoutInternal(
                  child,
                  childWidth,
                  childHeight,
                  direction,
                  childWidthMeasureMode,
                  childHeightMeasureMode,
                  availableInnerWidth,
                  availableInnerHeight,
                  true,
                  LayoutPassReason::kStretch,
                  layoutMarkerData,
                  depth,
                  generationCount);
            }
          } else {
            const float remainingCrossDim = containerCrossAxis -
                dimensionWithMargin(child, crossAxis, availableInnerWidth);

            if (child->getFlexStartMarginValue(crossAxis).unit == _YGUnitAuto &&
                child->marginTrailingValue(crossAxis).unit == _YGUnitAuto) {
              leadingCrossDim +=
                  yoga::maxOrDefined(0.0f, remainingCrossDim / 2);
            } else if (
                child->marginTrailingValue(crossAxis).unit == _YGUnitAuto) {
              // No-Op
            } else if (
                child->getFlexStartMarginValue(crossAxis).unit == _YGUnitAuto) {
              leadingCrossDim += yoga::maxOrDefined(0.0f, remainingCrossDim);
            } else if (alignItem == Align::FlexStart) {
              // No-Op
            } else if (alignItem == Align::Center) {
              leadingCrossDim += remainingCrossDim / 2;
            } else {
              leadingCrossDim += remainingCrossDim;
            }
          }
          // And we apply the position
          child->setLayoutPosition(
              child->getLayout().position[flexStartEdge(crossAxis)] +
                  totalLineCrossDim + leadingCrossDim,
              flexStartEdge(crossAxis));
        }
      }
    }

    const float appliedCrossGap = lineCount != 0 ? crossAxisGap : 0.0f;
    totalLineCrossDim += flexLine.layout.crossDim + appliedCrossGap;
    maxLineMainDim =
        yoga::maxOrDefined(maxLineMainDim, flexLine.layout.mainDim);
  }

  // STEP 8: MULTI-LINE CONTENT ALIGNMENT
  // currentLead stores the size of the cross dim
  if (performLayout && (isNodeFlexWrap || isBaselineLayout(node))) {
    float crossDimLead = 0;
    float currentLead = leadingPaddingAndBorderCross;
    if (yoga::isDefined(availableInnerCrossDim)) {
      const float remainingAlignContentDim =
          availableInnerCrossDim - totalLineCrossDim;
      switch (node->getStyle().alignContent()) {
        case Align::FlexEnd:
          currentLead += remainingAlignContentDim;
          break;
        case Align::Center:
          currentLead += remainingAlignContentDim / 2;
          break;
        case Align::Stretch:
          if (availableInnerCrossDim > totalLineCrossDim) {
            crossDimLead =
                remainingAlignContentDim / static_cast<float>(lineCount);
          }
          break;
        case Align::SpaceAround:
          if (availableInnerCrossDim > totalLineCrossDim) {
            currentLead +=
                remainingAlignContentDim / (2 * static_cast<float>(lineCount));
            if (lineCount > 1) {
              crossDimLead =
                  remainingAlignContentDim / static_cast<float>(lineCount);
            }
          } else {
            currentLead += remainingAlignContentDim / 2;
          }
          break;
        case Align::SpaceEvenly:
          if (availableInnerCrossDim > totalLineCrossDim) {
            currentLead +=
                remainingAlignContentDim / static_cast<float>(lineCount + 1);
            if (lineCount > 1) {
              crossDimLead =
                  remainingAlignContentDim / static_cast<float>(lineCount + 1);
            }
          } else {
            currentLead += remainingAlignContentDim / 2;
          }
          break;
        case Align::SpaceBetween:
          if (availableInnerCrossDim > totalLineCrossDim && lineCount > 1) {
            crossDimLead =
                remainingAlignContentDim / static_cast<float>(lineCount - 1);
          }
          break;
        case Align::Auto:
        case Align::FlexStart:
        case Align::Baseline:
          break;
      }
    }
    size_t endIndex = 0;
    for (size_t i = 0; i < lineCount; i++) {
      const size_t startIndex = endIndex;
      size_t ii;

      // compute the line's height and find the endIndex
      float lineHeight = 0;
      float maxAscentForCurrentLine = 0;
      float maxDescentForCurrentLine = 0;
      for (ii = startIndex; ii < childCount; ii++) {
        const auto child = node->getChild(ii);
        if (child->getStyle().display() == Display::None) {
          continue;
        }
        if (child->getStyle().positionType() != PositionType::Absolute) {
          if (child->getLineIndex() != i) {
            break;
          }
          if (isLayoutDimensionDefined(child, crossAxis)) {
            lineHeight = yoga::maxOrDefined(
                lineHeight,
                child->getLayout().measuredDimension(dimension(crossAxis)) +
                    child->getMarginForAxis(crossAxis, availableInnerWidth));
          }
          if (resolveChildAlignment(node, child) == Align::Baseline) {
            const float ascent = calculateBaseline(child) +
                child->getInlineStartMargin(
                    FlexDirection::Column, direction, availableInnerWidth);
            const float descent =
                child->getLayout().measuredDimension(Dimension::Height) +
                child->getMarginForAxis(
                    FlexDirection::Column, availableInnerWidth) -
                ascent;
            maxAscentForCurrentLine =
                yoga::maxOrDefined(maxAscentForCurrentLine, ascent);
            maxDescentForCurrentLine =
                yoga::maxOrDefined(maxDescentForCurrentLine, descent);
            lineHeight = yoga::maxOrDefined(
                lineHeight, maxAscentForCurrentLine + maxDescentForCurrentLine);
          }
        }
      }
      endIndex = ii;
      lineHeight += crossDimLead;
      currentLead += i != 0 ? crossAxisGap : 0;

      if (performLayout) {
        for (ii = startIndex; ii < endIndex; ii++) {
          const auto child = node->getChild(ii);
          if (child->getStyle().display() == Display::None) {
            continue;
          }
          if (child->getStyle().positionType() != PositionType::Absolute) {
            switch (resolveChildAlignment(node, child)) {
              case Align::FlexStart: {
                child->setLayoutPosition(
                    currentLead +
                        child->getInlineStartMargin(
                            crossAxis, direction, availableInnerWidth),
                    flexStartEdge(crossAxis));
                break;
              }
              case Align::FlexEnd: {
                child->setLayoutPosition(
                    currentLead + lineHeight -
                        child->getInlineEndMargin(
                            crossAxis, direction, availableInnerWidth) -
                        child->getLayout().measuredDimension(
                            dimension(crossAxis)),
                    flexStartEdge(crossAxis));
                break;
              }
              case Align::Center: {
                float childHeight =
                    child->getLayout().measuredDimension(dimension(crossAxis));

                child->setLayoutPosition(
                    currentLead + (lineHeight - childHeight) / 2,
                    flexStartEdge(crossAxis));
                break;
              }
              case Align::Stretch: {
                child->setLayoutPosition(
                    currentLead +
                        child->getInlineStartMargin(
                            crossAxis, direction, availableInnerWidth),
                    flexStartEdge(crossAxis));

                // Remeasure child with the line height as it as been only
                // measured with the owners height yet.
                if (!styleDefinesDimension(
                        child, crossAxis, availableInnerCrossDim)) {
                  const float childWidth = isMainAxisRow
                      ? (child->getLayout().measuredDimension(
                             Dimension::Width) +
                         child->getMarginForAxis(mainAxis, availableInnerWidth))
                      : lineHeight;

                  const float childHeight = !isMainAxisRow
                      ? (child->getLayout().measuredDimension(
                             Dimension::Height) +
                         child->getMarginForAxis(
                             crossAxis, availableInnerWidth))
                      : lineHeight;

                  if (!(yoga::inexactEquals(
                            childWidth,
                            child->getLayout().measuredDimension(
                                Dimension::Width)) &&
                        yoga::inexactEquals(
                            childHeight,
                            child->getLayout().measuredDimension(
                                Dimension::Height)))) {
                    calculateLayoutInternal(
                        child,
                        childWidth,
                        childHeight,
                        direction,
                        MeasureMode::Exactly,
                        MeasureMode::Exactly,
                        availableInnerWidth,
                        availableInnerHeight,
                        true,
                        LayoutPassReason::kMultilineStretch,
                        layoutMarkerData,
                        depth,
                        generationCount);
                  }
                }
                break;
              }
              case Align::Baseline: {
                child->setLayoutPosition(
                    currentLead + maxAscentForCurrentLine -
                        calculateBaseline(child) +
                        child->getInlineStartPosition(
                            FlexDirection::Column,
                            direction,
                            availableInnerCrossDim),
                    _YGEdgeTop);

                break;
              }
              case Align::Auto:
              case Align::SpaceBetween:
              case Align::SpaceAround:
              case Align::SpaceEvenly:
                break;
            }
          }
        }
      }
      currentLead += lineHeight;
    }
  }

  // STEP 9: COMPUTING FINAL DIMENSIONS

  node->setLayoutMeasuredDimension(
      boundAxis(
          node,
          FlexDirection::Row,
          availableWidth - marginAxisRow,
          ownerWidth,
          ownerWidth),
      Dimension::Width);

  node->setLayoutMeasuredDimension(
      boundAxis(
          node,
          FlexDirection::Column,
          availableHeight - marginAxisColumn,
          ownerHeight,
          ownerWidth),
      Dimension::Height);

  // If the user didn't specify a width or height for the node, set the
  // dimensions based on the children.
  if (measureModeMainDim == MeasureMode::Undefined ||
      (node->getStyle().overflow() != Overflow::Scroll &&
       measureModeMainDim == MeasureMode::AtMost)) {
    // Clamp the size to the min/max size, if specified, and make sure it
    // doesn't go below the padding and border amount.
    node->setLayoutMeasuredDimension(
        boundAxis(
            node, mainAxis, maxLineMainDim, mainAxisownerSize, ownerWidth),
        dimension(mainAxis));

  } else if (
      measureModeMainDim == MeasureMode::AtMost &&
      node->getStyle().overflow() == Overflow::Scroll) {
    node->setLayoutMeasuredDimension(
        yoga::maxOrDefined(
            yoga::minOrDefined(
                availableInnerMainDim + paddingAndBorderAxisMain,
                boundAxisWithinMinAndMax(
                    node,
                    mainAxis,
                    FloatOptional{maxLineMainDim},
                    mainAxisownerSize)
                    .unwrap()),
            paddingAndBorderAxisMain),
        dimension(mainAxis));
  }

  if (measureModeCrossDim == MeasureMode::Undefined ||
      (node->getStyle().overflow() != Overflow::Scroll &&
       measureModeCrossDim == MeasureMode::AtMost)) {
    // Clamp the size to the min/max size, if specified, and make sure it
    // doesn't go below the padding and border amount.
    node->setLayoutMeasuredDimension(
        boundAxis(
            node,
            crossAxis,
            totalLineCrossDim + paddingAndBorderAxisCross,
            crossAxisownerSize,
            ownerWidth),
        dimension(crossAxis));

  } else if (
      measureModeCrossDim == MeasureMode::AtMost &&
      node->getStyle().overflow() == Overflow::Scroll) {
    node->setLayoutMeasuredDimension(
        yoga::maxOrDefined(
            yoga::minOrDefined(
                availableInnerCrossDim + paddingAndBorderAxisCross,
                boundAxisWithinMinAndMax(
                    node,
                    crossAxis,
                    FloatOptional{
                        totalLineCrossDim + paddingAndBorderAxisCross},
                    crossAxisownerSize)
                    .unwrap()),
            paddingAndBorderAxisCross),
        dimension(crossAxis));
  }

  // As we only wrapped in normal direction yet, we need to reverse the
  // positions on wrap-reverse.
  if (performLayout && node->getStyle().flexWrap() == Wrap::WrapReverse) {
    for (size_t i = 0; i < childCount; i++) {
      const auto child = node->getChild(i);
      if (child->getStyle().positionType() != PositionType::Absolute) {
        child->setLayoutPosition(
            node->getLayout().measuredDimension(dimension(crossAxis)) -
                child->getLayout().position[flexStartEdge(crossAxis)] -
                child->getLayout().measuredDimension(dimension(crossAxis)),
            flexStartEdge(crossAxis));
      }
    }
  }

  if (performLayout) {
    // STEP 10: SIZING AND POSITIONING ABSOLUTE CHILDREN
    for (auto child : node->getChildren()) {
      if (child->getStyle().display() == Display::None ||
          child->getStyle().positionType() != PositionType::Absolute) {
        continue;
      }
      const bool absolutePercentageAgainstPaddingEdge =
          node->getConfig()->isExperimentalFeatureEnabled(
              ExperimentalFeature::AbsolutePercentageAgainstPaddingEdge);

      layoutAbsoluteChild(
          node,
          child,
          absolutePercentageAgainstPaddingEdge
              ? node->getLayout().measuredDimension(Dimension::Width)
              : availableInnerWidth,
          isMainAxisRow ? measureModeMainDim : measureModeCrossDim,
          absolutePercentageAgainstPaddingEdge
              ? node->getLayout().measuredDimension(Dimension::Height)
              : availableInnerHeight,
          direction,
          layoutMarkerData,
          depth,
          generationCount);
    }

    // STEP 11: SETTING TRAILING POSITIONS FOR CHILDREN
    const bool needsMainTrailingPos = mainAxis == FlexDirection::RowReverse ||
        mainAxis == FlexDirection::ColumnReverse;
    const bool needsCrossTrailingPos = crossAxis == FlexDirection::RowReverse ||
        crossAxis == FlexDirection::ColumnReverse;

    // Set trailing position if necessary.
    if (needsMainTrailingPos || needsCrossTrailingPos) {
      for (size_t i = 0; i < childCount; i++) {
        const auto child = node->getChild(i);
        if (child->getStyle().display() == Display::None) {
          continue;
        }
        if (needsMainTrailingPos) {
          setChildTrailingPosition(node, child, mainAxis);
        }

        if (needsCrossTrailingPos) {
          setChildTrailingPosition(node, child, crossAxis);
        }
      }
    }
  }
}

bool gPrintChanges = false;
bool gPrintSkips = false;

static const char* spacer =
    "                                                            ";

static const char* spacerWithLength(const unsigned long level) {
  const size_t spacerLen = strlen(spacer);
  if (level > spacerLen) {
    return &spacer[0];
  } else {
    return &spacer[spacerLen - level];
  }
}

static const char* measureModeName(
    const MeasureMode mode,
    const bool performLayout) {
  switch (mode) {
    case MeasureMode::Undefined:
      return performLayout ? "LAY_UNDEFINED" : "UNDEFINED";
    case MeasureMode::Exactly:
      return performLayout ? "LAY_EXACTLY" : "EXACTLY";
    case MeasureMode::AtMost:
      return performLayout ? "LAY_AT_MOST" : "AT_MOST";
  }
  return "";
}

//
// This is a wrapper around the calculateLayoutImpl function. It determines
// whether the layout request is redundant and can be skipped.
//
// Parameters:
//  Input parameters are the same as calculateLayoutImpl (see above)
//  Return parameter is true if layout was performed, false if skipped
//
bool calculateLayoutInternal(
    yoga::Node* const node,
    const float availableWidth,
    const float availableHeight,
    const Direction ownerDirection,
    const MeasureMode widthMeasureMode,
    const MeasureMode heightMeasureMode,
    const float ownerWidth,
    const float ownerHeight,
    const bool performLayout,
    const LayoutPassReason reason,
    LayoutData& layoutMarkerData,
    uint32_t depth,
    const uint32_t generationCount) {
  LayoutResults* layout = &node->getLayout();

  depth++;

  const bool needToVisitNode =
      (node->isDirty() && layout->generationCount != generationCount) ||
      layout->lastOwnerDirection != ownerDirection;

  if (needToVisitNode) {
    // Invalidate the cached results.
    layout->nextCachedMeasurementsIndex = 0;
    layout->cachedLayout.availableWidth = -1;
    layout->cachedLayout.availableHeight = -1;
    layout->cachedLayout.widthMeasureMode = MeasureMode::Undefined;
    layout->cachedLayout.heightMeasureMode = MeasureMode::Undefined;
    layout->cachedLayout.computedWidth = -1;
    layout->cachedLayout.computedHeight = -1;
  }

  CachedMeasurement* cachedResults = nullptr;

  // Determine whether the results are already cached. We maintain a separate
  // cache for layouts and measurements. A layout operation modifies the
  // positions and dimensions for nodes in the subtree. The algorithm assumes
  // that each node gets laid out a maximum of one time per tree layout, but
  // multiple measurements may be required to resolve all of the flex
  // dimensions. We handle nodes with measure functions specially here because
  // they are the most expensive to measure, so it's worth avoiding redundant
  // measurements if at all possible.
  if (node->hasMeasureFunc()) {
    const float marginAxisRow =
        node->getMarginForAxis(FlexDirection::Row, ownerWidth);
    const float marginAxisColumn =
        node->getMarginForAxis(FlexDirection::Column, ownerWidth);

    // First, try to use the layout cache.
    if (canUseCachedMeasurement(
            widthMeasureMode,
            availableWidth,
            heightMeasureMode,
            availableHeight,
            layout->cachedLayout.widthMeasureMode,
            layout->cachedLayout.availableWidth,
            layout->cachedLayout.heightMeasureMode,
            layout->cachedLayout.availableHeight,
            layout->cachedLayout.computedWidth,
            layout->cachedLayout.computedHeight,
            marginAxisRow,
            marginAxisColumn,
            node->getConfig())) {
      cachedResults = &layout->cachedLayout;
    } else {
      // Try to use the measurement cache.
      for (size_t i = 0; i < layout->nextCachedMeasurementsIndex; i++) {
        if (canUseCachedMeasurement(
                widthMeasureMode,
                availableWidth,
                heightMeasureMode,
                availableHeight,
                layout->cachedMeasurements[i].widthMeasureMode,
                layout->cachedMeasurements[i].availableWidth,
                layout->cachedMeasurements[i].heightMeasureMode,
                layout->cachedMeasurements[i].availableHeight,
                layout->cachedMeasurements[i].computedWidth,
                layout->cachedMeasurements[i].computedHeight,
                marginAxisRow,
                marginAxisColumn,
                node->getConfig())) {
          cachedResults = &layout->cachedMeasurements[i];
          break;
        }
      }
    }
  } else if (performLayout) {
    if (yoga::inexactEquals(
            layout->cachedLayout.availableWidth, availableWidth) &&
        yoga::inexactEquals(
            layout->cachedLayout.availableHeight, availableHeight) &&
        layout->cachedLayout.widthMeasureMode == widthMeasureMode &&
        layout->cachedLayout.heightMeasureMode == heightMeasureMode) {
      cachedResults = &layout->cachedLayout;
    }
  } else {
    for (uint32_t i = 0; i < layout->nextCachedMeasurementsIndex; i++) {
      if (yoga::inexactEquals(
              layout->cachedMeasurements[i].availableWidth, availableWidth) &&
          yoga::inexactEquals(
              layout->cachedMeasurements[i].availableHeight, availableHeight) &&
          layout->cachedMeasurements[i].widthMeasureMode == widthMeasureMode &&
          layout->cachedMeasurements[i].heightMeasureMode ==
              heightMeasureMode) {
        cachedResults = &layout->cachedMeasurements[i];
        break;
      }
    }
  }

  if (!needToVisitNode && cachedResults != nullptr) {
    layout->setMeasuredDimension(
        Dimension::Width, cachedResults->computedWidth);
    layout->setMeasuredDimension(
        Dimension::Height, cachedResults->computedHeight);

    (performLayout ? layoutMarkerData.cachedLayouts
                   : layoutMarkerData.cachedMeasures) += 1;

    if (gPrintChanges && gPrintSkips) {
      yoga::log(
          node,
          LogLevel::Verbose,
          "%s%d.{[skipped] ",
          spacerWithLength(depth),
          depth);
      node->print();
      yoga::log(
          node,
          LogLevel::Verbose,
          "wm: %s, hm: %s, aw: %f ah: %f => d: (%f, %f) %s\n",
          measureModeName(widthMeasureMode, performLayout),
          measureModeName(heightMeasureMode, performLayout),
          availableWidth,
          availableHeight,
          cachedResults->computedWidth,
          cachedResults->computedHeight,
          LayoutPassReasonToString(reason));
    }
  } else {
    if (gPrintChanges) {
      yoga::log(
          node,
          LogLevel::Verbose,
          "%s%d.{%s",
          spacerWithLength(depth),
          depth,
          needToVisitNode ? "*" : "");
      node->print();
      yoga::log(
          node,
          LogLevel::Verbose,
          "wm: %s, hm: %s, aw: %f ah: %f %s\n",
          measureModeName(widthMeasureMode, performLayout),
          measureModeName(heightMeasureMode, performLayout),
          availableWidth,
          availableHeight,
          LayoutPassReasonToString(reason));
    }

    calculateLayoutImpl(
        node,
        availableWidth,
        availableHeight,
        ownerDirection,
        widthMeasureMode,
        heightMeasureMode,
        ownerWidth,
        ownerHeight,
        performLayout,
        layoutMarkerData,
        depth,
        generationCount,
        reason);

    if (gPrintChanges) {
      yoga::log(
          node,
          LogLevel::Verbose,
          "%s%d.}%s",
          spacerWithLength(depth),
          depth,
          needToVisitNode ? "*" : "");
      node->print();
      yoga::log(
          node,
          LogLevel::Verbose,
          "wm: %s, hm: %s, d: (%f, %f) %s\n",
          measureModeName(widthMeasureMode, performLayout),
          measureModeName(heightMeasureMode, performLayout),
          layout->measuredDimension(Dimension::Width),
          layout->measuredDimension(Dimension::Height),
          LayoutPassReasonToString(reason));
    }

    layout->lastOwnerDirection = ownerDirection;

    if (cachedResults == nullptr) {
      layoutMarkerData.maxMeasureCache = std::max(
          layoutMarkerData.maxMeasureCache,
          layout->nextCachedMeasurementsIndex + 1u);

      if (layout->nextCachedMeasurementsIndex ==
          LayoutResults::MaxCachedMeasurements) {
        if (gPrintChanges) {
          yoga::log(node, LogLevel::Verbose, "Out of cache entries!\n");
        }
        layout->nextCachedMeasurementsIndex = 0;
      }

      CachedMeasurement* newCacheEntry;
      if (performLayout) {
        // Use the single layout cache entry.
        newCacheEntry = &layout->cachedLayout;
      } else {
        // Allocate a new measurement cache entry.
        newCacheEntry =
            &layout->cachedMeasurements[layout->nextCachedMeasurementsIndex];
        layout->nextCachedMeasurementsIndex++;
      }

      newCacheEntry->availableWidth = availableWidth;
      newCacheEntry->availableHeight = availableHeight;
      newCacheEntry->widthMeasureMode = widthMeasureMode;
      newCacheEntry->heightMeasureMode = heightMeasureMode;
      newCacheEntry->computedWidth =
          layout->measuredDimension(Dimension::Width);
      newCacheEntry->computedHeight =
          layout->measuredDimension(Dimension::Height);
    }
  }

  if (performLayout) {
    node->setLayoutDimension(
        node->getLayout().measuredDimension(Dimension::Width),
        Dimension::Width);
    node->setLayoutDimension(
        node->getLayout().measuredDimension(Dimension::Height),
        Dimension::Height);

    node->setHasNewLayout(true);
    node->setDirty(false);
  }

  layout->generationCount = generationCount;

  LayoutType layoutType;
  if (performLayout) {
    layoutType = !needToVisitNode && cachedResults == &layout->cachedLayout
        ? LayoutType::kCachedLayout
        : LayoutType::kLayout;
  } else {
    layoutType = cachedResults != nullptr ? LayoutType::kCachedMeasure
                                          : LayoutType::kMeasure;
  }
  Event::publish<Event::NodeLayout>(node, {layoutType});

  return (needToVisitNode || cachedResults == nullptr);
}

void calculateLayout(
    yoga::Node* const node,
    const float ownerWidth,
    const float ownerHeight,
    const Direction ownerDirection) {
  Event::publish<Event::LayoutPassStart>(node);
  LayoutData markerData = {};

  // Increment the generation count. This will force the recursive routine to
  // visit all dirty nodes at least once. Subsequent visits will be skipped if
  // the input parameters don't change.
  gCurrentGenerationCount.fetch_add(1, std::memory_order_relaxed);
  node->resolveDimension();
  float width = _YGUndefined;
  MeasureMode widthMeasureMode = MeasureMode::Undefined;
  const auto& style = node->getStyle();
  if (styleDefinesDimension(node, FlexDirection::Row, ownerWidth)) {
    width =
        (yoga::resolveValue(
             node->getResolvedDimension(dimension(FlexDirection::Row)),
             ownerWidth)
             .unwrap() +
         node->getMarginForAxis(FlexDirection::Row, ownerWidth));
    widthMeasureMode = MeasureMode::Exactly;
  } else if (yoga::resolveValue(
                 style.maxDimension(Dimension::Width), ownerWidth)
                 .isDefined()) {
    width = yoga::resolveValue(style.maxDimension(Dimension::Width), ownerWidth)
                .unwrap();
    widthMeasureMode = MeasureMode::AtMost;
  } else {
    width = ownerWidth;
    widthMeasureMode = yoga::isUndefined(width) ? MeasureMode::Undefined
                                                : MeasureMode::Exactly;
  }

  float height = _YGUndefined;
  MeasureMode heightMeasureMode = MeasureMode::Undefined;
  if (styleDefinesDimension(node, FlexDirection::Column, ownerHeight)) {
    height =
        (yoga::resolveValue(
             node->getResolvedDimension(dimension(FlexDirection::Column)),
             ownerHeight)
             .unwrap() +
         node->getMarginForAxis(FlexDirection::Column, ownerWidth));
    heightMeasureMode = MeasureMode::Exactly;
  } else if (yoga::resolveValue(
                 style.maxDimension(Dimension::Height), ownerHeight)
                 .isDefined()) {
    height =
        yoga::resolveValue(style.maxDimension(Dimension::Height), ownerHeight)
            .unwrap();
    heightMeasureMode = MeasureMode::AtMost;
  } else {
    height = ownerHeight;
    heightMeasureMode = yoga::isUndefined(height) ? MeasureMode::Undefined
                                                  : MeasureMode::Exactly;
  }
  if (calculateLayoutInternal(
          node,
          width,
          height,
          ownerDirection,
          widthMeasureMode,
          heightMeasureMode,
          ownerWidth,
          ownerHeight,
          true,
          LayoutPassReason::kInitial,
          markerData,
          0, // tree root
          gCurrentGenerationCount.load(std::memory_order_relaxed))) {
    node->setPosition(
        node->getLayout().direction(), ownerWidth, ownerHeight, ownerWidth);
    roundLayoutResultsToPixelGrid(node, 0.0f, 0.0f);

#ifdef DEBUG
    if (node->getConfig()->shouldPrintTree()) {
      yoga::print(
          node,
          PrintOptions::Layout | PrintOptions::Children | PrintOptions::Style);
    }
#endif
  }

  Event::publish<Event::LayoutPassEnd>(node, {&markerData});
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



namespace facebook::yoga {

float roundValueToPixelGrid(
    const double value,
    const double pointScaleFactor,
    const bool forceCeil,
    const bool forceFloor) {
  double scaledValue = value * pointScaleFactor;
  // We want to calculate `fractial` such that `floor(scaledValue) = scaledValue
  // - fractial`.
  double fractial = fmod(scaledValue, 1.0);
  if (fractial < 0) {
    // This branch is for handling negative numbers for `value`.
    //
    // Regarding `floor` and `ceil`. Note that for a number x, `floor(x) <= x <=
    // ceil(x)` even for negative numbers. Here are a couple of examples:
    //   - x =  2.2: floor( 2.2) =  2, ceil( 2.2) =  3
    //   - x = -2.2: floor(-2.2) = -3, ceil(-2.2) = -2
    //
    // Regarding `fmodf`. For fractional negative numbers, `fmodf` returns a
    // negative number. For example, `fmodf(-2.2) = -0.2`. However, we want
    // `fractial` to be the number such that subtracting it from `value` will
    // give us `floor(value)`. In the case of negative numbers, adding 1 to
    // `fmodf(value)` gives us this. Let's continue the example from above:
    //   - fractial = fmodf(-2.2) = -0.2
    //   - Add 1 to the fraction: fractial2 = fractial + 1 = -0.2 + 1 = 0.8
    //   - Finding the `floor`: -2.2 - fractial2 = -2.2 - 0.8 = -3
    ++fractial;
  }
  if (yoga::inexactEquals(fractial, 0)) {
    // First we check if the value is already rounded
    scaledValue = scaledValue - fractial;
  } else if (yoga::inexactEquals(fractial, 1.0)) {
    scaledValue = scaledValue - fractial + 1.0;
  } else if (forceCeil) {
    // Next we check if we need to use forced rounding
    scaledValue = scaledValue - fractial + 1.0;
  } else if (forceFloor) {
    scaledValue = scaledValue - fractial;
  } else {
    // Finally we just round the value
    scaledValue = scaledValue - fractial +
        (!std::isnan(fractial) &&
                 (fractial > 0.5 || yoga::inexactEquals(fractial, 0.5))
             ? 1.0
             : 0.0);
  }
  return (std::isnan(scaledValue) || std::isnan(pointScaleFactor))
      ? _YGUndefined
      : (float)(scaledValue / pointScaleFactor);
}

void roundLayoutResultsToPixelGrid(
    yoga::Node* const node,
    const double absoluteLeft,
    const double absoluteTop) {
  const auto pointScaleFactor = node->getConfig()->getPointScaleFactor();

  const double nodeLeft = node->getLayout().position[_YGEdgeLeft];
  const double nodeTop = node->getLayout().position[_YGEdgeTop];

  const double nodeWidth = node->getLayout().dimension(Dimension::Width);
  const double nodeHeight = node->getLayout().dimension(Dimension::Height);

  const double absoluteNodeLeft = absoluteLeft + nodeLeft;
  const double absoluteNodeTop = absoluteTop + nodeTop;

  const double absoluteNodeRight = absoluteNodeLeft + nodeWidth;
  const double absoluteNodeBottom = absoluteNodeTop + nodeHeight;

  if (pointScaleFactor != 0.0f) {
    // If a node has a custom measure function we never want to round down its
    // size as this could lead to unwanted text truncation.
    const bool textRounding = node->getNodeType() == NodeType::Text;

    node->setLayoutPosition(
        roundValueToPixelGrid(nodeLeft, pointScaleFactor, false, textRounding),
        _YGEdgeLeft);

    node->setLayoutPosition(
        roundValueToPixelGrid(nodeTop, pointScaleFactor, false, textRounding),
        _YGEdgeTop);

    // We multiply dimension by scale factor and if the result is close to the
    // whole number, we don't have any fraction To verify if the result is close
    // to whole number we want to check both floor and ceil numbers
    const bool hasFractionalWidth =
        !yoga::inexactEquals(fmod(nodeWidth * pointScaleFactor, 1.0), 0) &&
        !yoga::inexactEquals(fmod(nodeWidth * pointScaleFactor, 1.0), 1.0);
    const bool hasFractionalHeight =
        !yoga::inexactEquals(fmod(nodeHeight * pointScaleFactor, 1.0), 0) &&
        !yoga::inexactEquals(fmod(nodeHeight * pointScaleFactor, 1.0), 1.0);

    node->setLayoutDimension(
        roundValueToPixelGrid(
            absoluteNodeRight,
            pointScaleFactor,
            (textRounding && hasFractionalWidth),
            (textRounding && !hasFractionalWidth)) -
            roundValueToPixelGrid(
                absoluteNodeLeft, pointScaleFactor, false, textRounding),
        Dimension::Width);

    node->setLayoutDimension(
        roundValueToPixelGrid(
            absoluteNodeBottom,
            pointScaleFactor,
            (textRounding && hasFractionalHeight),
            (textRounding && !hasFractionalHeight)) -
            roundValueToPixelGrid(
                absoluteNodeTop, pointScaleFactor, false, textRounding),
        Dimension::Height);
  }

  for (yoga::Node* child : node->getChildren()) {
    roundLayoutResultsToPixelGrid(child, absoluteNodeLeft, absoluteNodeTop);
  }
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


namespace facebook::yoga {

static inline bool sizeIsExactAndMatchesOldMeasuredSize(
    MeasureMode sizeMode,
    float size,
    float lastComputedSize) {
  return sizeMode == MeasureMode::Exactly &&
      yoga::inexactEquals(size, lastComputedSize);
}

static inline bool oldSizeIsUnspecifiedAndStillFits(
    MeasureMode sizeMode,
    float size,
    MeasureMode lastSizeMode,
    float lastComputedSize) {
  return sizeMode == MeasureMode::AtMost &&
      lastSizeMode == MeasureMode::Undefined &&
      (size >= lastComputedSize || yoga::inexactEquals(size, lastComputedSize));
}

static inline bool newMeasureSizeIsStricterAndStillValid(
    MeasureMode sizeMode,
    float size,
    MeasureMode lastSizeMode,
    float lastSize,
    float lastComputedSize) {
  return lastSizeMode == MeasureMode::AtMost &&
      sizeMode == MeasureMode::AtMost && !std::isnan(lastSize) &&
      !std::isnan(size) && !std::isnan(lastComputedSize) && lastSize > size &&
      (lastComputedSize <= size || yoga::inexactEquals(size, lastComputedSize));
}

bool canUseCachedMeasurement(
    const MeasureMode widthMode,
    const float availableWidth,
    const MeasureMode heightMode,
    const float availableHeight,
    const MeasureMode lastWidthMode,
    const float lastAvailableWidth,
    const MeasureMode lastHeightMode,
    const float lastAvailableHeight,
    const float lastComputedWidth,
    const float lastComputedHeight,
    const float marginRow,
    const float marginColumn,
    const yoga::Config* const config) {
  if ((!std::isnan(lastComputedHeight) && lastComputedHeight < 0) ||
      (!std::isnan(lastComputedWidth) && lastComputedWidth < 0)) {
    return false;
  }

  const float pointScaleFactor = config->getPointScaleFactor();

  bool useRoundedComparison = config != nullptr && pointScaleFactor != 0;
  const float effectiveWidth = useRoundedComparison
      ? roundValueToPixelGrid(availableWidth, pointScaleFactor, false, false)
      : availableWidth;
  const float effectiveHeight = useRoundedComparison
      ? roundValueToPixelGrid(availableHeight, pointScaleFactor, false, false)
      : availableHeight;
  const float effectiveLastWidth = useRoundedComparison
      ? roundValueToPixelGrid(
            lastAvailableWidth, pointScaleFactor, false, false)
      : lastAvailableWidth;
  const float effectiveLastHeight = useRoundedComparison
      ? roundValueToPixelGrid(
            lastAvailableHeight, pointScaleFactor, false, false)
      : lastAvailableHeight;

  const bool hasSameWidthSpec = lastWidthMode == widthMode &&
      yoga::inexactEquals(effectiveLastWidth, effectiveWidth);
  const bool hasSameHeightSpec = lastHeightMode == heightMode &&
      yoga::inexactEquals(effectiveLastHeight, effectiveHeight);

  const bool widthIsCompatible =
      hasSameWidthSpec ||
      sizeIsExactAndMatchesOldMeasuredSize(
          widthMode, availableWidth - marginRow, lastComputedWidth) ||
      oldSizeIsUnspecifiedAndStillFits(
          widthMode,
          availableWidth - marginRow,
          lastWidthMode,
          lastComputedWidth) ||
      newMeasureSizeIsStricterAndStillValid(
          widthMode,
          availableWidth - marginRow,
          lastWidthMode,
          lastAvailableWidth,
          lastComputedWidth);

  const bool heightIsCompatible =
      hasSameHeightSpec ||
      sizeIsExactAndMatchesOldMeasuredSize(
          heightMode, availableHeight - marginColumn, lastComputedHeight) ||
      oldSizeIsUnspecifiedAndStillFits(
          heightMode,
          availableHeight - marginColumn,
          lastHeightMode,
          lastComputedHeight) ||
      newMeasureSizeIsStricterAndStillValid(
          heightMode,
          availableHeight - marginColumn,
          lastHeightMode,
          lastAvailableHeight,
          lastComputedHeight);

  return widthIsCompatible && heightIsCompatible;
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



namespace facebook::yoga {

float calculateBaseline(const yoga::Node* node) {
  if (node->hasBaselineFunc()) {
    Event::publish<Event::NodeBaselineStart>(node);

    const float baseline = node->baseline(
        node->getLayout().measuredDimension(Dimension::Width),
        node->getLayout().measuredDimension(Dimension::Height));

    Event::publish<Event::NodeBaselineEnd>(node);

    yoga::assertFatalWithNode(
        node,
        !std::isnan(baseline),
        "Expect custom baseline function to not return NaN");
    return baseline;
  }

  yoga::Node* baselineChild = nullptr;
  const size_t childCount = node->getChildCount();
  for (size_t i = 0; i < childCount; i++) {
    auto child = node->getChild(i);
    if (child->getLineIndex() > 0) {
      break;
    }
    if (child->getStyle().positionType() == PositionType::Absolute) {
      continue;
    }
    if (resolveChildAlignment(node, child) == Align::Baseline ||
        child->isReferenceBaseline()) {
      baselineChild = child;
      break;
    }

    if (baselineChild == nullptr) {
      baselineChild = child;
    }
  }

  if (baselineChild == nullptr) {
    return node->getLayout().measuredDimension(Dimension::Height);
  }

  const float baseline = calculateBaseline(baselineChild);
  return baseline + baselineChild->getLayout().position[_YGEdgeTop];
}

bool isBaselineLayout(const yoga::Node* node) {
  if (isColumn(node->getStyle().flexDirection())) {
    return false;
  }
  if (node->getStyle().alignItems() == Align::Baseline) {
    return true;
  }
  const auto childCount = node->getChildCount();
  for (size_t i = 0; i < childCount; i++) {
    auto child = node->getChild(i);
    if (child->getStyle().positionType() != PositionType::Absolute &&
        child->getStyle().alignSelf() == Align::Baseline) {
      return true;
    }
  }

  return false;
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */



namespace facebook::yoga {

FlexLine calculateFlexLine(
    yoga::Node* const node,
    const Direction ownerDirection,
    const float mainAxisownerSize,
    const float availableInnerWidth,
    const float availableInnerMainDim,
    const size_t startOfLineIndex,
    const size_t lineCount) {
  std::vector<yoga::Node*> itemsInFlow;
  itemsInFlow.reserve(node->getChildren().size());

  float sizeConsumed = 0.0f;
  float totalFlexGrowFactors = 0.0f;
  float totalFlexShrinkScaledFactors = 0.0f;
  size_t endOfLineIndex = startOfLineIndex;
  size_t firstElementInLineIndex = startOfLineIndex;

  float sizeConsumedIncludingMinConstraint = 0;
  const FlexDirection mainAxis = resolveDirection(
      node->getStyle().flexDirection(), node->resolveDirection(ownerDirection));
  const bool isNodeFlexWrap = node->getStyle().flexWrap() != Wrap::NoWrap;
  const float gap = node->getGapForAxis(mainAxis);

  // Add items to the current line until it's full or we run out of items.
  for (; endOfLineIndex < node->getChildren().size(); endOfLineIndex++) {
    auto child = node->getChild(endOfLineIndex);
    if (child->getStyle().display() == Display::None ||
        child->getStyle().positionType() == PositionType::Absolute) {
      if (firstElementInLineIndex == endOfLineIndex) {
        // We haven't found the first contributing element in the line yet.
        firstElementInLineIndex++;
      }
      continue;
    }

    const bool isFirstElementInLine =
        (endOfLineIndex - firstElementInLineIndex) == 0;

    child->setLineIndex(lineCount);
    const float childMarginMainAxis =
        child->getMarginForAxis(mainAxis, availableInnerWidth);
    const float childLeadingGapMainAxis = isFirstElementInLine ? 0.0f : gap;
    const float flexBasisWithMinAndMaxConstraints =
        boundAxisWithinMinAndMax(
            child,
            mainAxis,
            child->getLayout().computedFlexBasis,
            mainAxisownerSize)
            .unwrap();

    // If this is a multi-line flow and this item pushes us over the available
    // size, we've hit the end of the current line. Break out of the loop and
    // lay out the current line.
    if (sizeConsumedIncludingMinConstraint + flexBasisWithMinAndMaxConstraints +
                childMarginMainAxis + childLeadingGapMainAxis >
            availableInnerMainDim &&
        isNodeFlexWrap && itemsInFlow.size() > 0) {
      break;
    }

    sizeConsumedIncludingMinConstraint += flexBasisWithMinAndMaxConstraints +
        childMarginMainAxis + childLeadingGapMainAxis;
    sizeConsumed += flexBasisWithMinAndMaxConstraints + childMarginMainAxis +
        childLeadingGapMainAxis;

    if (child->isNodeFlexible()) {
      totalFlexGrowFactors += child->resolveFlexGrow();

      // Unlike the grow factor, the shrink factor is scaled relative to the
      // child dimension.
      totalFlexShrinkScaledFactors += -child->resolveFlexShrink() *
          child->getLayout().computedFlexBasis.unwrap();
    }

    itemsInFlow.push_back(child);
  }

  // The total flex factor needs to be floored to 1.
  if (totalFlexGrowFactors > 0 && totalFlexGrowFactors < 1) {
    totalFlexGrowFactors = 1;
  }

  // The total flex shrink factor needs to be floored to 1.
  if (totalFlexShrinkScaledFactors > 0 && totalFlexShrinkScaledFactors < 1) {
    totalFlexShrinkScaledFactors = 1;
  }

  return FlexLine{
      std::move(itemsInFlow),
      sizeConsumed,
      endOfLineIndex,
      FlexLineRunningLayout{
          totalFlexGrowFactors,
          totalFlexShrinkScaledFactors,
      }};
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#ifdef ANDROID
#include <android/log.h>
#endif

namespace facebook::yoga {

namespace {

void vlog(
    const yoga::Config* config,
    const yoga::Node* node,
    LogLevel level,
    const char* format,
    va_list args) {
  if (config == nullptr) {
    getDefaultLogger()(nullptr, node, unscopedEnum(level), format, args);
  } else {
    config->log(node, level, format, args);
  }
}
} // namespace

void log(LogLevel level, const char* format, ...) noexcept {
  va_list args;
  va_start(args, format);
  vlog(nullptr, nullptr, level, format, args);
  va_end(args);
}

void log(
    const yoga::Node* node,
    LogLevel level,
    const char* format,
    ...) noexcept {
  va_list args;
  va_start(args, format);
  vlog(
      node == nullptr ? nullptr : node->getConfig(), node, level, format, args);
  va_end(args);
}

void log(
    const yoga::Config* config,
    LogLevel level,
    const char* format,
    ...) noexcept {
  va_list args;
  va_start(args, format);
  vlog(config, nullptr, level, format, args);
  va_end(args);
}

_YGLogger getDefaultLogger() {
  return [](const _YGConfigConstRef /*config*/,
            const _YGNodeConstRef /*node*/,
            _YGLogLevel level,
            const char* format,
            va_list args) -> int {
#ifdef ANDROID
    int androidLevel = _YGLogLevelDebug;
    switch (level) {
      case _YGLogLevelFatal:
        androidLevel = ANDROID_LOG_FATAL;
        break;
      case _YGLogLevelError:
        androidLevel = ANDROID_LOG_ERROR;
        break;
      case _YGLogLevelWarn:
        androidLevel = ANDROID_LOG_WARN;
        break;
      case _YGLogLevelInfo:
        androidLevel = ANDROID_LOG_INFO;
        break;
      case _YGLogLevelDebug:
        androidLevel = ANDROID_LOG_DEBUG;
        break;
      case _YGLogLevelVerbose:
        androidLevel = ANDROID_LOG_VERBOSE;
        break;
    }
    return __android_log_vprint(androidLevel, "yoga", format, args);
#else
    switch (level) {
      case _YGLogLevelError:
      case _YGLogLevelFatal:
        return vfprintf(stderr, format, args);
      case _YGLogLevelWarn:
      case _YGLogLevelInfo:
      case _YGLogLevelDebug:
      case _YGLogLevelVerbose:
      default:
        return vprintf(format, args);
    }
#endif
  };
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <stdexcept>


namespace facebook::yoga {

[[noreturn]] void fatalWithMessage(const char* message) {
#if defined(__cpp_exceptions)
  throw std::logic_error(message);
#else
  std::terminate();
#endif
}

void assertFatal(const bool condition, const char* message) {
  if (!condition) {
    yoga::log(LogLevel::Fatal, "%s\n", message);
    fatalWithMessage(message);
  }
}

void assertFatalWithNode(
    const yoga::Node* const node,
    const bool condition,
    const char* message) {
  if (!condition) {
    yoga::log(node, LogLevel::Fatal, "%s\n", message);
    fatalWithMessage(message);
  }
}

void assertFatalWithConfig(
    const yoga::Config* const config,
    const bool condition,
    const char* message) {
  if (!condition) {
    yoga::log(config, LogLevel::Fatal, "%s\n", message);
    fatalWithMessage(message);
  }
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifdef DEBUG

#include <stdarg.h>



namespace facebook::yoga {

static void indent(std::string& base, uint32_t level) {
  for (uint32_t i = 0; i < level; ++i) {
    base.append("  ");
  }
}

static void appendFormattedString(std::string& str, const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  va_list argsCopy;
  va_copy(argsCopy, args);
  std::vector<char> buf(1 + static_cast<size_t>(vsnprintf(NULL, 0, fmt, args)));
  va_end(args);
  vsnprintf(buf.data(), buf.size(), fmt, argsCopy);
  va_end(argsCopy);
  std::string result = std::string(buf.begin(), buf.end() - 1);
  str.append(result);
}

static void appendFloatOptionalIfDefined(
    std::string& base,
    const std::string key,
    const FloatOptional num) {
  if (num.isDefined()) {
    appendFormattedString(base, "%s: %g; ", key.c_str(), num.unwrap());
  }
}

static void appendNumberIfNotUndefined(
    std::string& base,
    const std::string key,
    const _YGValue number) {
  if (number.unit != _YGUnitUndefined) {
    if (number.unit == _YGUnitAuto) {
      base.append(key + ": auto; ");
    } else {
      std::string unit = number.unit == _YGUnitPoint ? "px" : "%%";
      appendFormattedString(
          base, "%s: %g%s; ", key.c_str(), number.value, unit.c_str());
    }
  }
}

static void appendNumberIfNotAuto(
    std::string& base,
    const std::string& key,
    const _YGValue number) {
  if (number.unit != _YGUnitAuto) {
    appendNumberIfNotUndefined(base, key, number);
  }
}

static void appendNumberIfNotZero(
    std::string& base,
    const std::string& str,
    const _YGValue number) {
  if (number.unit == _YGUnitAuto) {
    base.append(str + ": auto; ");
  } else if (!yoga::inexactEquals(number.value, 0)) {
    appendNumberIfNotUndefined(base, str, number);
  }
}

template <auto Field>
static void
appendEdges(std::string& base, const std::string& key, const Style& style) {
  for (auto edge : ordinals<Edge>()) {
    std::string str = key + "-" + toString(edge);
    appendNumberIfNotZero(base, str, (style.*Field)(unscopedEnum(edge)));
  }
}

void nodeToString(
    std::string& str,
    const yoga::Node* node,
    PrintOptions options,
    uint32_t level) {
  indent(str, level);
  appendFormattedString(str, "<div ");

  if ((options & PrintOptions::Layout) == PrintOptions::Layout) {
    appendFormattedString(str, "layout=\"");
    appendFormattedString(
        str, "width: %g; ", node->getLayout().dimension(Dimension::Width));
    appendFormattedString(
        str, "height: %g; ", node->getLayout().dimension(Dimension::Height));
    appendFormattedString(
        str, "top: %g; ", node->getLayout().position[_YGEdgeTop]);
    appendFormattedString(
        str, "left: %g;", node->getLayout().position[_YGEdgeLeft]);
    appendFormattedString(str, "\" ");
  }

  if ((options & PrintOptions::Style) == PrintOptions::Style) {
    appendFormattedString(str, "style=\"");
    const auto& style = node->getStyle();
    if (style.flexDirection() != yoga::Node{}.getStyle().flexDirection()) {
      appendFormattedString(
          str, "flex-direction: %s; ", toString(style.flexDirection()));
    }
    if (style.justifyContent() != yoga::Node{}.getStyle().justifyContent()) {
      appendFormattedString(
          str, "justify-content: %s; ", toString(style.justifyContent()));
    }
    if (style.alignItems() != yoga::Node{}.getStyle().alignItems()) {
      appendFormattedString(
          str, "align-items: %s; ", toString(style.alignItems()));
    }
    if (style.alignContent() != yoga::Node{}.getStyle().alignContent()) {
      appendFormattedString(
          str, "align-content: %s; ", toString(style.alignContent()));
    }
    if (style.alignSelf() != yoga::Node{}.getStyle().alignSelf()) {
      appendFormattedString(
          str, "align-self: %s; ", toString(style.alignSelf()));
    }
    appendFloatOptionalIfDefined(str, "flex-grow", style.flexGrow());
    appendFloatOptionalIfDefined(str, "flex-shrink", style.flexShrink());
    appendNumberIfNotAuto(str, "flex-basis", style.flexBasis());
    appendFloatOptionalIfDefined(str, "flex", style.flex());

    if (style.flexWrap() != yoga::Node{}.getStyle().flexWrap()) {
      appendFormattedString(str, "flex-wrap: %s; ", toString(style.flexWrap()));
    }

    if (style.overflow() != yoga::Node{}.getStyle().overflow()) {
      appendFormattedString(str, "overflow: %s; ", toString(style.overflow()));
    }

    if (style.display() != yoga::Node{}.getStyle().display()) {
      appendFormattedString(str, "display: %s; ", toString(style.display()));
    }
    appendEdges<&Style::margin>(str, "margin", style);
    appendEdges<&Style::padding>(str, "padding", style);
    appendEdges<&Style::border>(str, "border", style);

    if (style.gap(Gutter::All).isDefined()) {
      appendNumberIfNotUndefined(str, "gap", style.gap(Gutter::All));
    } else {
      appendNumberIfNotUndefined(str, "column-gap", style.gap(Gutter::Column));
      appendNumberIfNotUndefined(str, "row-gap", style.gap(Gutter::Row));
    }

    appendNumberIfNotAuto(str, "width", style.dimension(Dimension::Width));
    appendNumberIfNotAuto(str, "height", style.dimension(Dimension::Height));
    appendNumberIfNotAuto(
        str, "max-width", style.maxDimension(Dimension::Width));
    appendNumberIfNotAuto(
        str, "max-height", style.maxDimension(Dimension::Height));
    appendNumberIfNotAuto(
        str, "min-width", style.minDimension(Dimension::Width));
    appendNumberIfNotAuto(
        str, "min-height", style.minDimension(Dimension::Height));

    if (style.positionType() != yoga::Node{}.getStyle().positionType()) {
      appendFormattedString(
          str, "position: %s; ", toString(style.positionType()));
    }

    appendEdges<&Style::position>(str, "position", style);
    appendFormattedString(str, "\" ");

    if (node->hasMeasureFunc()) {
      appendFormattedString(str, "has-custom-measure=\"true\"");
    }
  }
  appendFormattedString(str, ">");

  const size_t childCount = node->getChildCount();
  if ((options & PrintOptions::Children) == PrintOptions::Children &&
      childCount > 0) {
    for (size_t i = 0; i < childCount; i++) {
      appendFormattedString(str, "\n");
      nodeToString(str, node->getChild(i), options, level + 1);
    }
    appendFormattedString(str, "\n");
    indent(str, level);
  }
  appendFormattedString(str, "</div>");
}

void print(const yoga::Node* node, PrintOptions options) {
  std::string str;
  yoga::nodeToString(str, node, options, 0);
  yoga::log(node, LogLevel::Debug, str.c_str());
}

} // namespace facebook::yoga
#endif
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <cmath>


namespace facebook::yoga {

bool LayoutResults::operator==(LayoutResults layout) const {
  bool isEqual = yoga::inexactEquals(position, layout.position) &&
      yoga::inexactEquals(dimensions_, layout.dimensions_) &&
      yoga::inexactEquals(margin, layout.margin) &&
      yoga::inexactEquals(border, layout.border) &&
      yoga::inexactEquals(padding, layout.padding) &&
      direction() == layout.direction() &&
      hadOverflow() == layout.hadOverflow() &&
      lastOwnerDirection == layout.lastOwnerDirection &&
      nextCachedMeasurementsIndex == layout.nextCachedMeasurementsIndex &&
      cachedLayout == layout.cachedLayout &&
      computedFlexBasis == layout.computedFlexBasis;

  for (uint32_t i = 0; i < LayoutResults::MaxCachedMeasurements && isEqual;
       ++i) {
    isEqual = isEqual && cachedMeasurements[i] == layout.cachedMeasurements[i];
  }

  if (!yoga::isUndefined(measuredDimensions_[0]) ||
      !yoga::isUndefined(layout.measuredDimensions_[0])) {
    isEqual =
        isEqual && (measuredDimensions_[0] == layout.measuredDimensions_[0]);
  }
  if (!yoga::isUndefined(measuredDimensions_[1]) ||
      !yoga::isUndefined(layout.measuredDimensions_[1])) {
    isEqual =
        isEqual && (measuredDimensions_[1] == layout.measuredDimensions_[1]);
  }

  return isEqual;
}

} // namespace facebook::yoga
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <algorithm>
#include <cstddef>
#include <iostream>


namespace facebook::yoga {

Node::Node() : Node{&Config::getDefault()} {}

Node::Node(const yoga::Config* config) : config_{config} {
  yoga::assertFatal(
      config != nullptr, "Attempting to construct Node with null config");

  if (config->useWebDefaults()) {
    useWebDefaults();
  }
}

Node::Node(Node&& node) {
  hasNewLayout_ = node.hasNewLayout_;
  isReferenceBaseline_ = node.isReferenceBaseline_;
  isDirty_ = node.isDirty_;
  nodeType_ = node.nodeType_;
  context_ = node.context_;
  measureFunc_ = node.measureFunc_;
  baselineFunc_ = node.baselineFunc_;
  printFunc_ = node.printFunc_;
  dirtiedFunc_ = node.dirtiedFunc_;
  style_ = node.style_;
  layout_ = node.layout_;
  lineIndex_ = node.lineIndex_;
  owner_ = node.owner_;
  children_ = std::move(node.children_);
  config_ = node.config_;
  resolvedDimensions_ = node.resolvedDimensions_;
  for (auto c : children_) {
    c->setOwner(this);
  }
}

void Node::print() {
  if (printFunc_ != nullptr) {
    printFunc_(this);
  }
}

// TODO: Edge value resolution should be moved to `yoga::Style`
template <auto Field>
CompactValue Node::computeEdgeValueForRow(_YGEdge rowEdge, _YGEdge edge) const {
  if ((style_.*Field)(rowEdge).isDefined()) {
    return (style_.*Field)(rowEdge);
  } else if ((style_.*Field)(edge).isDefined()) {
    return (style_.*Field)(edge);
  } else if ((style_.*Field)(_YGEdgeHorizontal).isDefined()) {
    return (style_.*Field)(_YGEdgeHorizontal);
  } else {
    return (style_.*Field)(_YGEdgeAll);
  }
}

// TODO: Edge value resolution should be moved to `yoga::Style`
template <auto Field>
CompactValue Node::computeEdgeValueForColumn(_YGEdge edge) const {
  if ((style_.*Field)(edge).isDefined()) {
    return (style_.*Field)(edge);
  } else if ((style_.*Field)(_YGEdgeVertical).isDefined()) {
    return (style_.*Field)(_YGEdgeVertical);
  } else {
    return (style_.*Field)(_YGEdgeAll);
  }
}

_YGEdge Node::getInlineStartEdgeUsingErrata(
    FlexDirection flexDirection,
    Direction direction) const {
  return hasErrata(Errata::StartingEndingEdgeFromFlexDirection)
      ? flexStartEdge(flexDirection)
      : inlineStartEdge(flexDirection, direction);
}

_YGEdge Node::getInlineEndEdgeUsingErrata(
    FlexDirection flexDirection,
    Direction direction) const {
  return hasErrata(Errata::StartingEndingEdgeFromFlexDirection)
      ? flexEndEdge(flexDirection)
      : inlineEndEdge(flexDirection, direction);
}

bool Node::isFlexStartPositionDefined(FlexDirection axis) const {
  const _YGEdge startEdge = flexStartEdge(axis);
  auto leadingPosition = isRow(axis)
      ? computeEdgeValueForRow<&Style::position>(_YGEdgeStart, startEdge)
      : computeEdgeValueForColumn<&Style::position>(startEdge);

  return leadingPosition.isDefined();
}

bool Node::isInlineStartPositionDefined(FlexDirection axis, Direction direction)
    const {
  const _YGEdge startEdge = getInlineStartEdgeUsingErrata(axis, direction);
  auto leadingPosition = isRow(axis)
      ? computeEdgeValueForRow<&Style::position>(_YGEdgeStart, startEdge)
      : computeEdgeValueForColumn<&Style::position>(startEdge);

  return leadingPosition.isDefined();
}

bool Node::isFlexEndPositionDefined(FlexDirection axis) const {
  const _YGEdge endEdge = flexEndEdge(axis);
  auto trailingPosition = isRow(axis)
      ? computeEdgeValueForRow<&Style::position>(_YGEdgeEnd, endEdge)
      : computeEdgeValueForColumn<&Style::position>(endEdge);

  return !trailingPosition.isUndefined();
}

bool Node::isInlineEndPositionDefined(FlexDirection axis, Direction direction)
    const {
  const _YGEdge endEdge = getInlineEndEdgeUsingErrata(axis, direction);
  auto trailingPosition = isRow(axis)
      ? computeEdgeValueForRow<&Style::position>(_YGEdgeEnd, endEdge)
      : computeEdgeValueForColumn<&Style::position>(endEdge);

  return trailingPosition.isDefined();
}

float Node::getFlexStartPosition(FlexDirection axis, float axisSize) const {
  const _YGEdge startEdge = flexStartEdge(axis);
  auto leadingPosition = isRow(axis)
      ? computeEdgeValueForRow<&Style::position>(_YGEdgeStart, startEdge)
      : computeEdgeValueForColumn<&Style::position>(startEdge);

  return resolveValue(leadingPosition, axisSize).unwrapOrDefault(0.0f);
}

float Node::getInlineStartPosition(
    FlexDirection axis,
    Direction direction,
    float axisSize) const {
  const _YGEdge startEdge = getInlineStartEdgeUsingErrata(axis, direction);
  auto leadingPosition = isRow(axis)
      ? computeEdgeValueForRow<&Style::position>(_YGEdgeStart, startEdge)
      : computeEdgeValueForColumn<&Style::position>(startEdge);

  return resolveValue(leadingPosition, axisSize).unwrapOrDefault(0.0f);
}

float Node::getFlexEndPosition(FlexDirection axis, float axisSize) const {
  const _YGEdge endEdge = flexEndEdge(axis);
  auto trailingPosition = isRow(axis)
      ? computeEdgeValueForRow<&Style::position>(_YGEdgeEnd, endEdge)
      : computeEdgeValueForColumn<&Style::position>(endEdge);

  return resolveValue(trailingPosition, axisSize).unwrapOrDefault(0.0f);
}

float Node::getInlineEndPosition(
    FlexDirection axis,
    Direction direction,
    float axisSize) const {
  const _YGEdge endEdge = getInlineEndEdgeUsingErrata(axis, direction);
  auto trailingPosition = isRow(axis)
      ? computeEdgeValueForRow<&Style::position>(_YGEdgeEnd, endEdge)
      : computeEdgeValueForColumn<&Style::position>(endEdge);

  return resolveValue(trailingPosition, axisSize).unwrapOrDefault(0.0f);
}

float Node::getFlexStartMargin(FlexDirection axis, float widthSize) const {
  const _YGEdge startEdge = flexStartEdge(axis);
  auto leadingMargin = isRow(axis)
      ? computeEdgeValueForRow<&Style::margin>(_YGEdgeStart, startEdge)
      : computeEdgeValueForColumn<&Style::margin>(startEdge);

  return resolveValue(leadingMargin, widthSize).unwrapOrDefault(0.0f);
}

float Node::getInlineStartMargin(
    FlexDirection axis,
    Direction direction,
    float widthSize) const {
  const _YGEdge startEdge = getInlineStartEdgeUsingErrata(axis, direction);
  auto leadingMargin = isRow(axis)
      ? computeEdgeValueForRow<&Style::margin>(_YGEdgeStart, startEdge)
      : computeEdgeValueForColumn<&Style::margin>(startEdge);

  return resolveValue(leadingMargin, widthSize).unwrapOrDefault(0.0f);
}

float Node::getFlexEndMargin(FlexDirection axis, float widthSize) const {
  const _YGEdge endEdge = flexEndEdge(axis);
  auto trailingMargin = isRow(axis)
      ? computeEdgeValueForRow<&Style::margin>(_YGEdgeEnd, endEdge)
      : computeEdgeValueForColumn<&Style::margin>(endEdge);

  return resolveValue(trailingMargin, widthSize).unwrapOrDefault(0.0f);
}

float Node::getInlineEndMargin(
    FlexDirection axis,
    Direction direction,
    float widthSize) const {
  const _YGEdge endEdge = getInlineEndEdgeUsingErrata(axis, direction);
  auto trailingMargin = isRow(axis)
      ? computeEdgeValueForRow<&Style::margin>(_YGEdgeEnd, endEdge)
      : computeEdgeValueForColumn<&Style::margin>(endEdge);

  return resolveValue(trailingMargin, widthSize).unwrapOrDefault(0.0f);
}

float Node::getInlineStartBorder(FlexDirection axis, Direction direction)
    const {
  const _YGEdge startEdge = getInlineStartEdgeUsingErrata(axis, direction);
  _YGValue leadingBorder = isRow(axis)
      ? computeEdgeValueForRow<&Style::border>(_YGEdgeStart, startEdge)
      : computeEdgeValueForColumn<&Style::border>(startEdge);

  return maxOrDefined(leadingBorder.value, 0.0f);
}

float Node::getFlexStartBorder(FlexDirection axis, Direction direction) const {
  const _YGEdge leadRelativeFlexItemEdge =
      flexStartRelativeEdge(axis, direction);
  _YGValue leadingBorder = isRow(axis)
      ? computeEdgeValueForRow<&Style::border>(
            leadRelativeFlexItemEdge, flexStartEdge(axis))
      : computeEdgeValueForColumn<&Style::border>(flexStartEdge(axis));

  return maxOrDefined(leadingBorder.value, 0.0f);
}

float Node::getInlineEndBorder(FlexDirection axis, Direction direction) const {
  const _YGEdge endEdge = getInlineEndEdgeUsingErrata(axis, direction);
  _YGValue trailingBorder = isRow(axis)
      ? computeEdgeValueForRow<&Style::border>(_YGEdgeEnd, endEdge)
      : computeEdgeValueForColumn<&Style::border>(endEdge);

  return maxOrDefined(trailingBorder.value, 0.0f);
}

float Node::getFlexEndBorder(FlexDirection axis, Direction direction) const {
  const _YGEdge trailRelativeFlexItemEdge = flexEndRelativeEdge(axis, direction);
  _YGValue trailingBorder = isRow(axis)
      ? computeEdgeValueForRow<&Style::border>(
            trailRelativeFlexItemEdge, flexEndEdge(axis))
      : computeEdgeValueForColumn<&Style::border>(flexEndEdge(axis));

  return maxOrDefined(trailingBorder.value, 0.0f);
}

float Node::getInlineStartPadding(
    FlexDirection axis,
    Direction direction,
    float widthSize) const {
  const _YGEdge startEdge = getInlineStartEdgeUsingErrata(axis, direction);
  auto leadingPadding = isRow(axis)
      ? computeEdgeValueForRow<&Style::padding>(_YGEdgeStart, startEdge)
      : computeEdgeValueForColumn<&Style::padding>(startEdge);

  return maxOrDefined(resolveValue(leadingPadding, widthSize).unwrap(), 0.0f);
}

float Node::getFlexStartPadding(
    FlexDirection axis,
    Direction direction,
    float widthSize) const {
  const _YGEdge leadRelativeFlexItemEdge =
      flexStartRelativeEdge(axis, direction);
  auto leadingPadding = isRow(axis)
      ? computeEdgeValueForRow<&Style::padding>(
            leadRelativeFlexItemEdge, flexStartEdge(axis))
      : computeEdgeValueForColumn<&Style::padding>(flexStartEdge(axis));

  return maxOrDefined(resolveValue(leadingPadding, widthSize).unwrap(), 0.0f);
}

float Node::getInlineEndPadding(
    FlexDirection axis,
    Direction direction,
    float widthSize) const {
  const _YGEdge endEdge = getInlineEndEdgeUsingErrata(axis, direction);
  auto trailingPadding = isRow(axis)
      ? computeEdgeValueForRow<&Style::padding>(_YGEdgeEnd, endEdge)
      : computeEdgeValueForColumn<&Style::padding>(endEdge);

  return maxOrDefined(resolveValue(trailingPadding, widthSize).unwrap(), 0.0f);
}

float Node::getFlexEndPadding(
    FlexDirection axis,
    Direction direction,
    float widthSize) const {
  const _YGEdge trailRelativeFlexItemEdge = flexEndRelativeEdge(axis, direction);
  auto trailingPadding = isRow(axis)
      ? computeEdgeValueForRow<&Style::padding>(
            trailRelativeFlexItemEdge, flexEndEdge(axis))
      : computeEdgeValueForColumn<&Style::padding>(flexEndEdge(axis));

  return maxOrDefined(resolveValue(trailingPadding, widthSize).unwrap(), 0.0f);
}

float Node::getInlineStartPaddingAndBorder(
    FlexDirection axis,
    Direction direction,
    float widthSize) const {
  return getInlineStartPadding(axis, direction, widthSize) +
      getInlineStartBorder(axis, direction);
}

float Node::getFlexStartPaddingAndBorder(
    FlexDirection axis,
    Direction direction,
    float widthSize) const {
  return getFlexStartPadding(axis, direction, widthSize) +
      getFlexStartBorder(axis, direction);
}

float Node::getInlineEndPaddingAndBorder(
    FlexDirection axis,
    Direction direction,
    float widthSize) const {
  return getInlineEndPadding(axis, direction, widthSize) +
      getInlineEndBorder(axis, direction);
}

float Node::getFlexEndPaddingAndBorder(
    FlexDirection axis,
    Direction direction,
    float widthSize) const {
  return getFlexEndPadding(axis, direction, widthSize) +
      getFlexEndBorder(axis, direction);
}

float Node::getMarginForAxis(FlexDirection axis, float widthSize) const {
  // The total margin for a given axis does not depend on the direction
  // so hardcoding LTR here to avoid piping direction to this function
  return getInlineStartMargin(axis, Direction::LTR, widthSize) +
      getInlineEndMargin(axis, Direction::LTR, widthSize);
}

float Node::getGapForAxis(FlexDirection axis) const {
  auto gap = isRow(axis) ? style_.resolveColumnGap() : style_.resolveRowGap();
  // TODO: Validate percentage gap, and expose ability to set percentage to
  // public API
  return maxOrDefined(resolveValue(gap, 0.0f /*ownerSize*/).unwrap(), 0.0f);
}

_YGSize Node::measure(
    float width,
    MeasureMode widthMode,
    float height,
    MeasureMode heightMode) {
  return measureFunc_(
      this, width, unscopedEnum(widthMode), height, unscopedEnum(heightMode));
}

float Node::baseline(float width, float height) const {
  return baselineFunc_(this, width, height);
}

// Setters

void Node::setMeasureFunc(_YGMeasureFunc measureFunc) {
  if (measureFunc == nullptr) {
    // TODO: t18095186 Move nodeType to opt-in function and mark appropriate
    // places in Litho
    setNodeType(NodeType::Default);
  } else {
    yoga::assertFatalWithNode(
        this,
        children_.size() == 0,
        "Cannot set measure function: Nodes with measure functions cannot have "
        "children.");
    // TODO: t18095186 Move nodeType to opt-in function and mark appropriate
    // places in Litho
    setNodeType(NodeType::Text);
  }

  measureFunc_ = measureFunc;
}

void Node::replaceChild(Node* child, size_t index) {
  children_[index] = child;
}

void Node::replaceChild(Node* oldChild, Node* newChild) {
  std::replace(children_.begin(), children_.end(), oldChild, newChild);
}

void Node::insertChild(Node* child, size_t index) {
  children_.insert(children_.begin() + static_cast<ptrdiff_t>(index), child);
}

void Node::setConfig(yoga::Config* config) {
  yoga::assertFatal(
      config != nullptr, "Attempting to set a null config on a Node");
  yoga::assertFatalWithConfig(
      config,
      config->useWebDefaults() == config_->useWebDefaults(),
      "UseWebDefaults may not be changed after constructing a Node");

  if (yoga::configUpdateInvalidatesLayout(*config_, *config)) {
    markDirtyAndPropagate();
  }

  config_ = config;
}

void Node::setDirty(bool isDirty) {
  if (isDirty == isDirty_) {
    return;
  }
  isDirty_ = isDirty;
  if (isDirty && dirtiedFunc_) {
    dirtiedFunc_(this);
  }
}

bool Node::removeChild(Node* child) {
  std::vector<Node*>::iterator p =
      std::find(children_.begin(), children_.end(), child);
  if (p != children_.end()) {
    children_.erase(p);
    return true;
  }
  return false;
}

void Node::removeChild(size_t index) {
  children_.erase(children_.begin() + static_cast<ptrdiff_t>(index));
}

void Node::setLayoutDirection(Direction direction) {
  layout_.setDirection(direction);
}

void Node::setLayoutMargin(float margin, _YGEdge edge) {
  assertFatal(
      edge < static_cast<int>(layout_.margin.size()),
      "Edge must be top/left/bottom/right");
  layout_.margin[edge] = margin;
}

void Node::setLayoutBorder(float border, _YGEdge edge) {
  assertFatal(
      edge < static_cast<int>(layout_.border.size()),
      "Edge must be top/left/bottom/right");
  layout_.border[edge] = border;
}

void Node::setLayoutPadding(float padding, _YGEdge edge) {
  assertFatal(
      edge < static_cast<int>(layout_.padding.size()),
      "Edge must be top/left/bottom/right");
  layout_.padding[edge] = padding;
}

void Node::setLayoutLastOwnerDirection(Direction direction) {
  layout_.lastOwnerDirection = direction;
}

void Node::setLayoutComputedFlexBasis(const FloatOptional computedFlexBasis) {
  layout_.computedFlexBasis = computedFlexBasis;
}

void Node::setLayoutPosition(float position, _YGEdge edge) {
  assertFatal(
      edge < static_cast<int>(layout_.position.size()),
      "Edge must be top/left/bottom/right");
  layout_.position[edge] = position;
}

void Node::setLayoutComputedFlexBasisGeneration(
    uint32_t computedFlexBasisGeneration) {
  layout_.computedFlexBasisGeneration = computedFlexBasisGeneration;
}

void Node::setLayoutMeasuredDimension(
    float measuredDimension,
    Dimension dimension) {
  layout_.setMeasuredDimension(dimension, measuredDimension);
}

void Node::setLayoutHadOverflow(bool hadOverflow) {
  layout_.setHadOverflow(hadOverflow);
}

void Node::setLayoutDimension(float dimensionValue, Dimension dimension) {
  layout_.setDimension(dimension, dimensionValue);
}

// If both left and right are defined, then use left. Otherwise return +left or
// -right depending on which is defined.
float Node::relativePosition(
    FlexDirection axis,
    Direction direction,
    float axisSize) const {
  if (isInlineStartPositionDefined(axis, direction)) {
    return getInlineStartPosition(axis, direction, axisSize);
  }

  return -1 * getInlineEndPosition(axis, direction, axisSize);
}

void Node::setPosition(
    const Direction direction,
    const float mainSize,
    const float crossSize,
    const float ownerWidth) {
  /* Root nodes should be always layouted as LTR, so we don't return negative
   * values. */
  const Direction directionRespectingRoot =
      owner_ != nullptr ? direction : Direction::LTR;
  const FlexDirection mainAxis =
      yoga::resolveDirection(style_.flexDirection(), directionRespectingRoot);
  const FlexDirection crossAxis =
      yoga::resolveCrossDirection(mainAxis, directionRespectingRoot);

  // Here we should check for `PositionType::Static` and in this case zero inset
  // properties (left, right, top, bottom, begin, end).
  // https://www.w3.org/TR/css-position-3/#valdef-position-static
  const float relativePositionMain =
      relativePosition(mainAxis, directionRespectingRoot, mainSize);
  const float relativePositionCross =
      relativePosition(crossAxis, directionRespectingRoot, crossSize);

  const _YGEdge mainAxisLeadingEdge =
      getInlineStartEdgeUsingErrata(mainAxis, direction);
  const _YGEdge mainAxisTrailingEdge =
      getInlineEndEdgeUsingErrata(mainAxis, direction);
  const _YGEdge crossAxisLeadingEdge =
      getInlineStartEdgeUsingErrata(crossAxis, direction);
  const _YGEdge crossAxisTrailingEdge =
      getInlineEndEdgeUsingErrata(crossAxis, direction);

  setLayoutPosition(
      (getInlineStartMargin(mainAxis, direction, ownerWidth) +
       relativePositionMain),
      mainAxisLeadingEdge);
  setLayoutPosition(
      (getInlineEndMargin(mainAxis, direction, ownerWidth) +
       relativePositionMain),
      mainAxisTrailingEdge);
  setLayoutPosition(
      (getInlineStartMargin(crossAxis, direction, ownerWidth) +
       relativePositionCross),
      crossAxisLeadingEdge);
  setLayoutPosition(
      (getInlineEndMargin(crossAxis, direction, ownerWidth) +
       relativePositionCross),
      crossAxisTrailingEdge);
}

_YGValue Node::getFlexStartMarginValue(FlexDirection axis) const {
  if (isRow(axis) && style_.margin(_YGEdgeStart).isDefined()) {
    return style_.margin(_YGEdgeStart);
  } else {
    return style_.margin(flexStartEdge(axis));
  }
}

_YGValue Node::marginTrailingValue(FlexDirection axis) const {
  if (isRow(axis) && style_.margin(_YGEdgeEnd).isDefined()) {
    return style_.margin(_YGEdgeEnd);
  } else {
    return style_.margin(flexEndEdge(axis));
  }
}

_YGValue Node::resolveFlexBasisPtr() const {
  _YGValue flexBasis = style_.flexBasis();
  if (flexBasis.unit != _YGUnitAuto && flexBasis.unit != _YGUnitUndefined) {
    return flexBasis;
  }
  if (style_.flex().isDefined() && style_.flex().unwrap() > 0.0f) {
    return config_->useWebDefaults() ? _YGValueAuto : _YGValueZero;
  }
  return _YGValueAuto;
}

void Node::resolveDimension() {
  const Style& style = getStyle();
  for (auto dim : {Dimension::Width, Dimension::Height}) {
    if (style.maxDimension(dim).isDefined() &&
        yoga::inexactEquals(style.maxDimension(dim), style.minDimension(dim))) {
      resolvedDimensions_[yoga::to_underlying(dim)] = style.maxDimension(dim);
    } else {
      resolvedDimensions_[yoga::to_underlying(dim)] = style.dimension(dim);
    }
  }
}

Direction Node::resolveDirection(const Direction ownerDirection) {
  if (style_.direction() == Direction::Inherit) {
    return ownerDirection != Direction::Inherit ? ownerDirection
                                                : Direction::LTR;
  } else {
    return style_.direction();
  }
}

void Node::clearChildren() {
  children_.clear();
  children_.shrink_to_fit();
}

// Other Methods

void Node::cloneChildrenIfNeeded() {
  size_t i = 0;
  for (Node*& child : children_) {
    if (child->getOwner() != this) {
      child = resolveRef(config_->cloneNode(child, this, i));
      child->setOwner(this);
    }
    i += 1;
  }
}

void Node::markDirtyAndPropagate() {
  if (!isDirty_) {
    setDirty(true);
    setLayoutComputedFlexBasis(FloatOptional());
    if (owner_) {
      owner_->markDirtyAndPropagate();
    }
  }
}

float Node::resolveFlexGrow() const {
  // Root nodes flexGrow should always be 0
  if (owner_ == nullptr) {
    return 0.0;
  }
  if (style_.flexGrow().isDefined()) {
    return style_.flexGrow().unwrap();
  }
  if (style_.flex().isDefined() && style_.flex().unwrap() > 0.0f) {
    return style_.flex().unwrap();
  }
  return Style::DefaultFlexGrow;
}

float Node::resolveFlexShrink() const {
  if (owner_ == nullptr) {
    return 0.0;
  }
  if (style_.flexShrink().isDefined()) {
    return style_.flexShrink().unwrap();
  }
  if (!config_->useWebDefaults() && style_.flex().isDefined() &&
      style_.flex().unwrap() < 0.0f) {
    return -style_.flex().unwrap();
  }
  return config_->useWebDefaults() ? Style::WebDefaultFlexShrink
                                   : Style::DefaultFlexShrink;
}

bool Node::isNodeFlexible() {
  return (
      (style_.positionType() != PositionType::Absolute) &&
      (resolveFlexGrow() != 0 || resolveFlexShrink() != 0));
}

void Node::reset() {
  yoga::assertFatalWithNode(
      this,
      children_.size() == 0,
      "Cannot reset a node which still has children attached");
  yoga::assertFatalWithNode(
      this, owner_ == nullptr, "Cannot reset a node still attached to a owner");

  *this = Node{getConfig()};
}

} // namespace facebook::yoga

// Workaround for ambiguous 'Node' definition
#define Node _Node
/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <atomic>
#include <memory>

namespace facebook::yoga {

const char* LayoutPassReasonToString(const LayoutPassReason value) {
  switch (value) {
    case LayoutPassReason::kInitial:
      return "initial";
    case LayoutPassReason::kAbsLayout:
      return "abs_layout";
    case LayoutPassReason::kStretch:
      return "stretch";
    case LayoutPassReason::kMultilineStretch:
      return "multiline_stretch";
    case LayoutPassReason::kFlexLayout:
      return "flex_layout";
    case LayoutPassReason::kMeasureChild:
      return "measure";
    case LayoutPassReason::kAbsMeasureChild:
      return "abs_measure";
    case LayoutPassReason::kFlexMeasure:
      return "flex_measure";
    default:
      return "unknown";
  }
}

namespace {

struct Node {
  std::function<Event::Subscriber> subscriber = nullptr;
  Node* next = nullptr;

  Node(std::function<Event::Subscriber>&& subscriber)
      : subscriber{std::move(subscriber)} {}
};

std::atomic<Node*> subscribers{nullptr};

Node* push(Node* newHead) {
  Node* oldHead;
  do {
    oldHead = subscribers.load(std::memory_order_relaxed);
    if (newHead != nullptr) {
      newHead->next = oldHead;
    }
  } while (!subscribers.compare_exchange_weak(
      oldHead, newHead, std::memory_order_release, std::memory_order_relaxed));
  return oldHead;
}

} // namespace

void Event::reset() {
  auto head = push(nullptr);
  while (head != nullptr) {
    auto current = head;
    head = head->next;
    delete current;
  }
}

void Event::subscribe(std::function<Subscriber>&& subscriber) {
  push(new Node{std::move(subscriber)});
}

void Event::publish(
    _YGNodeConstRef node,
    Type eventType,
    const Data& eventData) {
  for (auto subscriber = subscribers.load(std::memory_order_relaxed);
       subscriber != nullptr;
       subscriber = subscriber->next) {
    subscriber->subscriber(node, eventType, eventData);
  }
}

} // namespace facebook::yoga
#undef Node

///////////////////////////////////////////////////////////
// Flex UI
///////////////////////////////////////////////////////////
#define EXPORT __attribute__((visibility("default")))

#include <stdexcept>

extern "C" {


EXPORT _YGConfigRef FlexUi_ConfigNew() {
	return _YGConfigNew();
}

EXPORT void FlexUi_ConfigFree(_YGConfigRef config) {
	_YGConfigFree(config);
}

EXPORT _YGConfigConstRef FlexUi_ConfigGetDefault() {
	return _YGConfigGetDefault();
}

EXPORT void FlexUi_ConfigSetPointScaleFactor(_YGConfigRef config, float enabled) {
	_YGConfigSetPointScaleFactor(config, enabled);
}

EXPORT void FlexUi_ConfigSetErrata(_YGConfigRef config, _YGErrata errata) {
	_YGConfigSetErrata(config, errata);
}

EXPORT void FlexUi_ConfigSetExperimentalFeatureEnabled(_YGConfigRef config, _YGExperimentalFeature feature, bool enabled) {
	_YGConfigSetExperimentalFeatureEnabled(config, feature, enabled);
}

EXPORT _YGNodeRef FlexUi_NodeNew() {
	return _YGNodeNew();
}

EXPORT void FlexUi_NodeFree(_YGNodeRef node) {
	_YGNodeFree(node);
}

EXPORT void FlexUi_NodeCalculateLayout(_YGNodeRef node, float availableWidth, float availableHeight, _YGDirection ownerDirection) {
	_YGNodeCalculateLayout(node, availableWidth, availableHeight, ownerDirection);
}

EXPORT const char *FlexUi_NodeInsertChild(_YGNodeRef node, _YGNodeRef child, int index) {
	try {
		_YGNodeInsertChild(node, child, index);
		return NULL;
	}
	catch (std::logic_error err) {
		return strdup(err.what());
	}
}

EXPORT void FlexUi_NodeRemoveChild(_YGNodeRef node, _YGNodeRef child) {
	_YGNodeRemoveChild(node, child);
}

EXPORT void FlexUi_NodeRemoveAllChildren(_YGNodeRef node) {
	_YGNodeRemoveAllChildren(node);
}

EXPORT int FlexUi_NodeGetChildCount(_YGNodeConstRef node) {
	return (int) _YGNodeGetChildCount(node);
}

EXPORT const char *FlexUi_NodeSetConfig(_YGNodeRef node, _YGConfigRef config) {
	try {
		_YGNodeSetConfig(node, config);
		return NULL;
	}
	catch (std::logic_error err) {
		return strdup(err.what());
	}
}

EXPORT void FlexUi_NodeSetContext(_YGNodeRef node, void* context) {
	_YGNodeSetContext(node, context);
}

EXPORT void *FlexUi_NodeGetContext(_YGNodeRef node) {
	return _YGNodeGetContext(node);
}

EXPORT void FlexUi_NodeSetMeasureFunc(_YGNodeRef node, _YGMeasureFunc measureFunc) {
	_YGNodeSetMeasureFunc(node, measureFunc);
}

EXPORT bool FlexUi_NodeHasMeasureFunc(_YGNodeRef node) {
	return _YGNodeHasMeasureFunc(node);
}

EXPORT void FlexUi_NodeSetDirty(_YGNodeRef node) {
	_YGNodeMarkDirty(node);
}

EXPORT float FlexUi_NodeLayoutGetLeft(_YGNodeConstRef node) {
	return _YGNodeLayoutGetLeft(node);
}

EXPORT float FlexUi_NodeLayoutGetTop(_YGNodeConstRef node) {
	return _YGNodeLayoutGetTop(node);
}

EXPORT float FlexUi_NodeLayoutGetWidth(_YGNodeConstRef node) {
	return _YGNodeLayoutGetWidth(node);
}

EXPORT float FlexUi_NodeLayoutGetHeight(_YGNodeConstRef node) {
	return _YGNodeLayoutGetHeight(node);
}

EXPORT void FlexUi_NodeStyleSetDirection(_YGNodeRef node, _YGDirection direction) {
	_YGNodeStyleSetDirection(node, direction);
}

EXPORT void FlexUi_NodeStyleSetFlexDirection(_YGNodeRef node, _YGFlexDirection flexDirection) {
	_YGNodeStyleSetFlexDirection(node, flexDirection);
}

EXPORT void FlexUi_NodeStyleSetJustifyContent(_YGNodeRef node, _YGJustify justifyContent) {
	_YGNodeStyleSetJustifyContent(node, justifyContent);
}

EXPORT void FlexUi_NodeStyleSetAlignContent(_YGNodeRef node, _YGAlign alignContent) {
	_YGNodeStyleSetAlignContent(node, alignContent);
}

EXPORT void FlexUi_NodeStyleSetAlignItems(_YGNodeRef node, _YGAlign alignItems) {
	_YGNodeStyleSetAlignItems(node, alignItems);
}

EXPORT void FlexUi_NodeStyleSetAlignSelf(_YGNodeRef node, _YGAlign alignSelf) {
	_YGNodeStyleSetAlignSelf(node, alignSelf);
}

EXPORT void FlexUi_NodeStyleSetPositionType(_YGNodeRef node, _YGPositionType positionType) {
	_YGNodeStyleSetPositionType(node, positionType);
}

EXPORT void FlexUi_NodeStyleSetFlexWrap(_YGNodeRef node, _YGWrap flexWrap) {
	_YGNodeStyleSetFlexWrap(node, flexWrap);
}

EXPORT void FlexUi_NodeStyleSetFlexGrow(_YGNodeRef node, float flexGrow) {
	_YGNodeStyleSetFlexGrow(node, flexGrow);
}

EXPORT void FlexUi_NodeStyleSetFlexShrink(_YGNodeRef node, float flexShrink) {
	_YGNodeStyleSetFlexShrink(node, flexShrink);
}

EXPORT void FlexUi_NodeStyleSetFlexBasis(_YGNodeRef node, float flexBasis) {
	_YGNodeStyleSetFlexBasis(node, flexBasis);
}

EXPORT void FlexUi_NodeStyleSetFlexBasisPercent(_YGNodeRef node, float flexBasis) {
	_YGNodeStyleSetFlexBasisPercent(node, flexBasis);
}

EXPORT void FlexUi_NodeStyleSetFlexBasisAuto(_YGNodeRef node) {
	_YGNodeStyleSetFlexBasisAuto(node);
}

EXPORT void FlexUi_NodeStyleSetPosition(_YGNodeRef node, _YGEdge edge, float position) {
	_YGNodeStyleSetPosition(node, edge, position);
}

EXPORT void FlexUi_NodeStyleSetPositionPercent(_YGNodeRef node, _YGEdge edge, float position) {
	_YGNodeStyleSetPositionPercent(node, edge, position);
}

EXPORT void FlexUi_NodeStyleSetMargin(_YGNodeRef node, _YGEdge edge, float margin) {
	_YGNodeStyleSetMargin(node, edge, margin);
}

EXPORT void FlexUi_NodeStyleSetMarginPercent(_YGNodeRef node, _YGEdge edge, float margin) {
	_YGNodeStyleSetMarginPercent(node, edge, margin);
}

EXPORT void FlexUi_NodeStyleSetMarginAuto(_YGNodeRef node, _YGEdge edge) {
	_YGNodeStyleSetMarginAuto(node, edge);
}

EXPORT void FlexUi_NodeStyleSetPadding(_YGNodeRef node, _YGEdge edge, float padding) {
	_YGNodeStyleSetPadding(node, edge, padding);
}

EXPORT void FlexUi_NodeStyleSetPaddingPercent(_YGNodeRef node, _YGEdge edge, float padding) {
	_YGNodeStyleSetPaddingPercent(node, edge, padding);
}

EXPORT void FlexUi_NodeStyleSetGap(_YGNodeRef node, _YGGutter gutter, float padding) {
	_YGNodeStyleSetGap(node, gutter, padding);
}

EXPORT void FlexUi_NodeStyleSetWidth(_YGNodeRef node, float width) {
	_YGNodeStyleSetWidth(node, width);
}

EXPORT void FlexUi_NodeStyleSetWidthPercent(_YGNodeRef node, float width) {
	_YGNodeStyleSetWidthPercent(node, width);
}

EXPORT void FlexUi_NodeStyleSetWidthAuto(_YGNodeRef node) {
	_YGNodeStyleSetWidthAuto(node);
}

EXPORT void FlexUi_NodeStyleSetHeight(_YGNodeRef node, float height) {
	_YGNodeStyleSetHeight(node, height);
}

EXPORT void FlexUi_NodeStyleSetHeightPercent(_YGNodeRef node, float height) {
	_YGNodeStyleSetHeightPercent(node, height);
}

EXPORT void FlexUi_NodeStyleSetHeightAuto(_YGNodeRef node) {
	_YGNodeStyleSetHeightAuto(node);
}

EXPORT void FlexUi_NodeStyleSetMinWidth(_YGNodeRef node, float minWidth) {
	_YGNodeStyleSetMinWidth(node, minWidth);
}

EXPORT void FlexUi_NodeStyleSetMinWidthPercent(_YGNodeRef node, float minWidth) {
	_YGNodeStyleSetMinWidthPercent(node, minWidth);
}

EXPORT void FlexUi_NodeStyleSetMinHeight(_YGNodeRef node, float minHeight) {
	_YGNodeStyleSetMinHeight(node, minHeight);
}

EXPORT void FlexUi_NodeStyleSetMinHeightPercent(_YGNodeRef node, float minHeight) {
	_YGNodeStyleSetMinHeightPercent(node, minHeight);
}

EXPORT void FlexUi_NodeStyleSetMaxWidth(_YGNodeRef node, float maxWidth) {
	_YGNodeStyleSetMaxWidth(node, maxWidth);
}

EXPORT void FlexUi_NodeStyleSetMaxWidthPercent(_YGNodeRef node, float maxWidth) {
	_YGNodeStyleSetMaxWidthPercent(node, maxWidth);
}

EXPORT void FlexUi_NodeStyleSetMaxHeight(_YGNodeRef node, float maxHeight) {
	_YGNodeStyleSetMaxHeight(node, maxHeight);
}

EXPORT void FlexUi_NodeStyleSetMaxHeightPercent(_YGNodeRef node, float maxHeight) {
	_YGNodeStyleSetMaxHeightPercent(node, maxHeight);
}

EXPORT void FlexUi_NodeStyleSetAspectRatio(_YGNodeRef node, float aspectRatio) {
	_YGNodeStyleSetAspectRatio(node, aspectRatio);
}

}
