using System;
using System.Runtime.InteropServices;

namespace Gilzoide.FlexUi.Yoga
{
    /// <summary>
    /// Value struct that supports point/pixel values, percentages, Undefined and Auto special values.
    /// </summary>
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

        /// <summary>
        /// Factory method for creating a Percent value.
        /// </summary>
        /// <param name="value">Percent value. E.g.: passing 100 returns a value of 100%.</param>
        public static YGValue Percent(float value)
        {
            return new YGValue(value, Unit.Percent);
        }

        public static implicit operator YGValue(float value)
        {
            return new YGValue(value, Unit.Point);
        }

        /// <summary>Zero value</summary>
        public static readonly YGValue Zero = new YGValue(0, Unit.Point);
        /// <summary>Undefined special value</summary>
        public static readonly YGValue Undefined = new YGValue(float.NaN, Unit.Undefined);
        /// <summary>Auto special value</summary>
        public static readonly YGValue Auto = new YGValue(float.NaN, Unit.Auto);
    }
}
