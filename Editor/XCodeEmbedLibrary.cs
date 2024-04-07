#if UNITY_STANDALONE_OSX || UNITY_IOS || UNITY_TVOS || UNITY_VISIONOS
using System.IO;
using System.Linq;
using UnityEditor;
using UnityEditor.Callbacks;
using UnityEditor.iOS.Xcode;
using UnityEditor.iOS.Xcode.Extensions;

namespace Gilzoide.FlexUi.Editor
{
    public static class XCodeEmbedLibrary
    {
#if UNITY_STANDALONE_OSX
        const string PlatformFolderName = "macos";
#elif UNITY_IOS
        const string PlatformFolderName = "ios";
#elif UNITY_TVOS
        const string PlatformFolderName = "tvos";
#elif UNITY_VISIONOS
        const string PlatformFolderName = "visionos";
#endif
        static string PackageLibraryPath => AssetDatabase.FindAssets($"glob:{PlatformFolderName}/libflex-ui.dylib")
            .Select(AssetDatabase.GUIDToAssetPath)
            .First();
        const string XCodeLibraryPath = "Libraries/libflex-ui.dylib";

        [PostProcessBuild]
        public static void PostProcessBuild(BuildTarget buildTarget, string path)
        {
            string pbxProjectPath = PBXProject.GetPBXProjectPath(path);
            if (!File.Exists(pbxProjectPath))
            {
                return;
            }

            string fullLibraryPath = $"{path}/{XCodeLibraryPath}";
            if (File.Exists(fullLibraryPath))
            {
                return;
            }

            FileUtil.CopyFileOrDirectory(PackageLibraryPath, fullLibraryPath);

            var pbxProject = new PBXProject();
            pbxProject.ReadFromFile(pbxProjectPath);

            string libGuid = pbxProject.AddFile(XCodeLibraryPath, XCodeLibraryPath, PBXSourceTree.Source);
            pbxProject.AddFileToEmbedFrameworks(pbxProject.GetUnityMainTargetGuid(), libGuid);

            pbxProject.WriteToFile(pbxProjectPath);
        }

#if !UNITY_2019_3_OR_NEWER
        public static string GetUnityMainTargetGuid(this PBXProject pbxProject)
        {
            return pbxProject.TargetGuidByName(PBXProject.GetUnityTargetName());
        }
#endif
    }
}
#endif
