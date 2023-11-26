using System.Reflection;
using UnityEditor;

namespace Gilzoide.FlexUi.Editor
{
    [CanEditMultipleObjects]
    [CustomEditor(typeof(FlexLayout))]
    public class FlexLayoutEditor : UnityEditor.Editor
    {
        private bool[] FoldoutState => ((FlexLayout) serializedObject.targetObject)._foldoutState;

        public override void OnInspectorGUI()
        {
            serializedObject.Update();

            SerializedProperty property = serializedObject.GetIterator();
            // script field
            property.NextVisible(true);
            using (new EditorGUI.DisabledScope(true))
            {
                EditorGUILayout.PropertyField(property);
            }

            // configuration field
            property.NextVisible(false);
            EditorGUILayout.PropertyField(property);

            EditorGUI.indentLevel++;
            int foldoutIndex = -1;
            while (property.NextVisible(false))
            {
                FieldInfo fieldInfo = typeof(FlexLayout).GetField(property.propertyPath, BindingFlags.Instance | BindingFlags.NonPublic);
                if (fieldInfo.GetCustomAttribute<FoldoutHeaderAttribute>() is FoldoutHeaderAttribute foldoutHeader)
                {
                    EditorGUI.indentLevel--;
                    foldoutIndex++;
                    bool foldout = GetFoldoutState(foldoutIndex);
                    foldout = EditorGUILayout.Foldout(foldout, foldoutHeader.Title, true);
                    SetFoldoutState(foldoutIndex, foldout);
                    EditorGUI.indentLevel++;
                }

                if (FoldoutState[foldoutIndex])
                {
                    EditorGUILayout.PropertyField(property, true);
                }
            }
            EditorGUI.indentLevel++;

            serializedObject.ApplyModifiedProperties();
        }

        private void SetFoldoutState(int index, bool value)
        {
            SerializedProperty foldoutProperty = serializedObject.FindProperty(nameof(FlexLayout._foldoutState));
            foldoutProperty.GetArrayElementAtIndex(index).boolValue = value;
        }

        private bool GetFoldoutState(int index)
        {
            SerializedProperty foldoutProperty = serializedObject.FindProperty(nameof(FlexLayout._foldoutState));
            return foldoutProperty.GetArrayElementAtIndex(index).boolValue;
        }
    }
}
