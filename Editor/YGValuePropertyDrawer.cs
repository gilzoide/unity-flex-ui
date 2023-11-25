using System;
using Gilzoide.FlexUi.Yoga;
using UnityEditor;
using UnityEngine;

namespace Gilzoide.FlexUi.Editor
{
    [CustomPropertyDrawer(typeof(YGValue))]
    public class YGValuePropertyDrawer : PropertyDrawer
    {
        public override void OnGUI(Rect position, SerializedProperty property, GUIContent label)
        {
            string value = GetValueAsString(property);
            string newValue = EditorGUI.DelayedTextField(position, label, value).ToLowerInvariant().Trim();
            if (newValue == "auto")
            {
                SetValue(property, YGValue.Auto);
            }
            else if (newValue == "" || newValue == "none" || newValue == "undefined")
            {
                SetValue(property, YGValue.Undefined);
            }
            else if (newValue.EndsWith('%') && ExpressionEvaluator.Evaluate(newValue.TrimEnd('%'), out float percentValue))
            {
                SetValue(property, new YGValue(percentValue, Unit.Percent));
            }
            else if (ExpressionEvaluator.Evaluate(newValue, out float pointValue))
            {
                SetValue(property, new YGValue(pointValue, Unit.Point));
            }
        }

        public override float GetPropertyHeight(SerializedProperty property, GUIContent label)
        {
            return EditorGUI.GetPropertyHeight(SerializedPropertyType.String, label);
        }

        private static string GetValueAsString(SerializedProperty property)
        {
            if (property.hasMultipleDifferentValues)
            {
                return "—";
            }

            int unit = property.FindPropertyRelative(nameof(YGValue.Unit)).enumValueIndex;
            float value = property.FindPropertyRelative(nameof(YGValue.Value)).floatValue;
            switch ((Unit) unit)
            {
                case Unit.Undefined:
                    return "none";

                case Unit.Point:
                    if (float.IsNaN(value))
                    {
                        return "none";
                    }
                    else
                    {
                        return value.ToString();
                    }

                case Unit.Percent:
                    if (float.IsNaN(value))
                    {
                        return "none";
                    }
                    else
                    {
                        return value.ToString() + '%';
                    }

                case Unit.Auto:
                    return "auto";

                default:
                    throw new ArgumentOutOfRangeException(nameof(YGValue.Unit));
            }
        }

        private void SetValue(SerializedProperty property, YGValue value)
        {
            property.FindPropertyRelative(nameof(YGValue.Value)).floatValue = value.Value;
            property.FindPropertyRelative(nameof(YGValue.Unit)).enumValueIndex = (int) value.Unit;
        }
    }
}
