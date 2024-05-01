using Gilzoide.FlexUi.Yoga;
using UnityEditor;
using UnityEngine;

namespace Gilzoide.FlexUi.Editor
{
    [CustomPropertyDrawer(typeof(Unit))]
    public class UnitPropertyDrawer : PropertyDrawer
    {
        internal static bool NoAuto { get; set;}

        static readonly string[] _labels = { "none", "px", "%", "auto" };
        static readonly string[] _noAutoLabels = { "none", "px", "%" };

        public override void OnGUI(Rect position, SerializedProperty property, GUIContent label)
        {
            EditorGUI.BeginProperty(position, label, property);
            property.enumValueIndex = EditorGUI.Popup(position, label.text, property.enumValueIndex, NoAuto ? _noAutoLabels : _labels);
            EditorGUI.EndProperty();
        }
    }
}
