using System.Reflection;
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
            UnitPropertyDrawer.NoAuto = fieldInfo.GetCustomAttribute<NoAutoAttribute>() != null;
            SerializedProperty unitProperty = property.FindPropertyRelative(nameof(YGValue.Unit));
            SerializedProperty valueProperty = property.FindPropertyRelative(nameof(YGValue.Value));
            property.NextVisible(true);
            position.width *= 1.32f;
            EditorGUI.MultiPropertyField(position, new[]{ new GUIContent(" "), GUIContent.none }, property, label);
            UnitPropertyDrawer.NoAuto = false;
            switch ((Unit) unitProperty.enumValueIndex)
            {
                case Unit.Point:
                case Unit.Percent:
                    if (float.IsNaN(valueProperty.floatValue))
                    {
                        valueProperty.floatValue = 100;
                    }
                    break;

                case Unit.Undefined:
                case Unit.Auto:
                    if (!float.IsNaN(valueProperty.floatValue))
                    {
                        valueProperty.floatValue = float.NaN;
                    }
                    break;
            }
        }

        public override float GetPropertyHeight(SerializedProperty property, GUIContent label)
        {
            return EditorGUI.GetPropertyHeight(SerializedPropertyType.String, label);
        }
    }
}
