using System;
using System.Diagnostics;

namespace Gilzoide.FlexUi
{
    [Conditional("UNITY_EDITOR")]
    [AttributeUsage(AttributeTargets.Field, AllowMultiple = false)]
    public class NoAutoAttribute : Attribute
    {
    }
}
