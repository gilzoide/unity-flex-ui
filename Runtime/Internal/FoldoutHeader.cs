using System;
using System.Diagnostics;

namespace Gilzoide.FlexUi
{
    [Conditional("UNITY_EDITOR")]
    [AttributeUsage(AttributeTargets.Field, AllowMultiple = false)]
    public class FoldoutHeaderAttribute : Attribute
    {
        public string Title { get; }

        public FoldoutHeaderAttribute(string title)
        {
            Title = title;
        }
    }
}
