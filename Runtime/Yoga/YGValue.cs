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

        public static readonly YGValue Undefined = new YGValue
        {
            Value = float.NaN,
            Unit = Unit.Undefined,
        };
        public static readonly YGValue Auto = new YGValue
        {
            Value = float.NaN,
            Unit = Unit.Auto,
        };
    }
}
