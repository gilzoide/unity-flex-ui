using System.Collections.Generic;
using System.Reflection;
using UnityEditor;
using UnityEngine;

namespace Gilzoide.FlexUi.Editor
{
    [CanEditMultipleObjects]
    [CustomEditor(typeof(FlexLayout))]
    public class FlexLayoutEditor : UnityEditor.Editor
    {
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

                if (GetFoldoutState(foldoutIndex))
                {
                    EditorGUILayout.PropertyField(property, true);
                }
            }
            EditorGUI.indentLevel--;

            if (!serializedObject.isEditingMultipleObjects)
            {
                FlexLayout flexLayout = (FlexLayout) target;
                EditorGUILayout.Space();
                EditorGUILayout.LabelField("Debug", EditorStyles.boldLabel);
                using (new EditorGUI.DisabledScope(true))
                {
                    EditorGUILayout.ObjectField("Root Layout", flexLayout.RootLayoutNode, typeof(FlexLayout), true);
                    EditorGUILayout.ObjectField("Parent Layout", flexLayout.ParentLayoutNode, typeof(FlexLayout), true);
                    List<FlexLayout> children = flexLayout._childrenNodes;
                    if (children?.Count > 0)
                    {
                        foldoutIndex++;
                        bool foldout = GetFoldoutState(foldoutIndex);
                        foldout = EditorGUILayout.Foldout(foldout, "Children", true);
                        SetFoldoutState(foldoutIndex, foldout);
                        if (foldout)
                        {
                            EditorGUI.indentLevel++;
                            int i = 0;
                            foreach (FlexLayout child in flexLayout._childrenNodes)
                            {
                                EditorGUILayout.ObjectField(i.ToString(), child, typeof(FlexLayout), true);
                                i++;
                            }
                            EditorGUI.indentLevel--;
                        }
                    }
                }
            }

            if (serializedObject.ApplyModifiedProperties())
            {
                foreach (Object obj in targets)
                {
                    ((FlexLayout) obj).RefreshRootLayoutImmediate();
                }
            }
        }

        private void SetFoldoutState(int index, bool value)
        {
            SerializedProperty foldoutProperty = serializedObject.FindProperty(nameof(FlexLayout._foldoutState));
            while (foldoutProperty.arraySize < index + 1)
            {
                foldoutProperty.InsertArrayElementAtIndex(foldoutProperty.arraySize);
            }
            foldoutProperty.GetArrayElementAtIndex(index).boolValue = value;
        }

        private bool GetFoldoutState(int index)
        {
            SerializedProperty foldoutProperty = serializedObject.FindProperty(nameof(FlexLayout._foldoutState));
            while (foldoutProperty.arraySize < index + 1)
            {
                foldoutProperty.InsertArrayElementAtIndex(foldoutProperty.arraySize);
            }
            return foldoutProperty.GetArrayElementAtIndex(index).boolValue;
        }
    }
}
