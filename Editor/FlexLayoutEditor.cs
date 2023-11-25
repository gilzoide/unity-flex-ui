using System.Collections.Generic;
using System.Reflection;
using UnityEditor;

namespace Gilzoide.FlexUi.Editor
{
    [CustomEditor(typeof(FlexLayout))]
    public class FlexLayoutEditor : UnityEditor.Editor
    {
        private static List<bool> _foldoutState = new List<bool>();

        void OnEnable()
        {
            int foldoutIndex = -1;
            foreach (FieldInfo fieldInfo in typeof(FlexLayout).GetFields(BindingFlags.Instance | BindingFlags.NonPublic))
            {
                if (fieldInfo.GetCustomAttribute<FoldoutHeaderAttribute>() != null)
                {
                    foldoutIndex++;
                    if (_foldoutState.Count <= foldoutIndex)
                    {
                        _foldoutState.Add(false);
                    }
                }
            }
        }

        public override void OnInspectorGUI()
        {
            serializedObject.Update();

            SerializedProperty property = serializedObject.GetIterator();
            property.NextVisible(true);

            // script field
            using (new EditorGUI.DisabledScope(true))
            {
                EditorGUILayout.PropertyField(property);
            }

            EditorGUI.indentLevel++;
            int foldoutIndex = -1;
            while (property.NextVisible(false))
            {
                FieldInfo fieldInfo = typeof(FlexLayout).GetField(property.propertyPath, BindingFlags.Instance | BindingFlags.NonPublic);
                if (fieldInfo.GetCustomAttribute<FoldoutHeaderAttribute>() is FoldoutHeaderAttribute foldoutHeader)
                {
                    EditorGUI.indentLevel--;
                    foldoutIndex++;
                    _foldoutState[foldoutIndex] = EditorGUILayout.Foldout(_foldoutState[foldoutIndex], foldoutHeader.Title, true);
                    EditorGUI.indentLevel++;
                }

                if (_foldoutState[foldoutIndex])
                {
                    EditorGUILayout.PropertyField(property, true);
                }
            }
            EditorGUI.indentLevel++;

            serializedObject.ApplyModifiedProperties();
        }
    }
}
