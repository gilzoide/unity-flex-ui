using System;
using System.Runtime.InteropServices;

namespace Gilzoide.FlexUi.Yoga
{
    [Serializable]
    [StructLayout(LayoutKind.Sequential)]
    public struct YGValue
    {
        public float Value;
        public Unit Unit;

        public YGValue(float value, Unit unit)
        {
            Value = value;
            Unit = unit;
        }

        public static YGValue Percent(float value)
        {
            return new YGValue(value, Unit.Percent);
        }

        public static implicit operator YGValue(float value)
        {
            return new YGValue(value, Unit.Point);
        }

        public static readonly YGValue Zero = new YGValue(0, Unit.Point);
        public static readonly YGValue Undefined = new YGValue(float.NaN, Unit.Undefined);
        public static readonly YGValue Auto = new YGValue(float.NaN, Unit.Auto);
    }
}
