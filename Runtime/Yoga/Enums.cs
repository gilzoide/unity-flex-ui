// Reference: https://github.com/facebook/yoga/blob/main/yoga/YGEnums.h
using System;

namespace Gilzoide.FlexUi.Yoga
{
    public enum Align
    {
        Auto,
        FlexStart,
        Center,
        FlexEnd,
        Stretch,
        Baseline,
        SpaceBetween,
        SpaceAround,
        SpaceEvenly,
    }

    public enum Dimension
    {
        Width,
        Height,
    }

    public enum Direction
    {
        Inherit,
        LTR,
        RTL,
    }

    public enum Display
    {
        Flex,
        None,
    }

    public enum Edge
    {
        Left,
        Top,
        Right,
        Bottom,
        Start,
        End,
        Horizontal,
        Vertical,
        All,
    }

    [Flags]
    public enum Errata
    {
        None = 0,
        StretchFlexBasis = 1,
        StartingEndingEdgeFromFlexDirection = 2,
        PositionStaticBehavesLikeRelative = 4,
        All = 2147483647,
        Classic = 2147483646,
    }

    public enum ExperimentalFeature
    {
        WebFlexBasis,
        AbsolutePercentageAgainstPaddingEdge,
    }

    [Flags]
    public enum ExperimentalFeatureFlags
    {
        WebFlexBasis = 1 << ExperimentalFeature.WebFlexBasis,
        AbsolutePercentageAgainstPaddingEdge = 1 << ExperimentalFeature.AbsolutePercentageAgainstPaddingEdge,
    }

    public enum FlexDirection
    {
        Column,
        ColumnReverse,
        Row,
        RowReverse,
    }

    public enum Justify
    {
        FlexStart,
        Center,
        FlexEnd,
        SpaceBetween,
        SpaceAround,
        SpaceEvenly,
    }

    public enum Overflow
    {
        Visible,
        Hidden,
        Scroll,
    }

    public enum PositionType
    {
        Static,
        Relative,
        Absolute,
    }

    [Flags]
    public enum PrintOptions
    {
        Layout = 1,
        Style = 2,
        Children = 4,
    }

    public enum Unit
    {
        Undefined,
        Point,
        Percent,
        Auto,
    }

    public enum Wrap
    {
        NoWrap,
        Wrap,
        WrapReverse,
    }
}
