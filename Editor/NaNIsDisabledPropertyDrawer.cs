using UnityEditor;
using UnityEngine;

namespace Gilzoide.FlexUi.Editor
{
    [CustomPropertyDrawer(typeof(NaNIsDisabledAttribute))]
    public class NaNIsDisabledPropertyDrawer : PropertyDrawer
    {
        public override void OnGUI(Rect position, SerializedProperty property, GUIContent label)
        {
            bool isNaN = float.IsNaN(property.floatValue);
            using (new EditorGUI.DisabledScope(isNaN))
            {
                EditorGUI.showMixedValue = isNaN;
                EditorGUI.PropertyField(position, property, label);
            }
        }
    }
}
