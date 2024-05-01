using System;
using System.Diagnostics;
using UnityEngine;

namespace Gilzoide.FlexUi
{
    [Conditional("UNITY_EDITOR")]
    [AttributeUsage(AttributeTargets.Field, AllowMultiple = false)]
    public class NaNIsDisabledAttribute : PropertyAttribute
    {
    }
}
