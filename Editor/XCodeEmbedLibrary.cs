#if UNITY_STANDALONE_OSX || UNITY_IOS || UNITY_TVOS || UNITY_VISIONOS
using System.IO;
using UnityEditor;
using UnityEditor.Callbacks;
using UnityEditor.iOS.Xcode;
using UnityEditor.iOS.Xcode.Extensions;

namespace Gilzoide.FlexUi.Editor
{
    public static class XCodeEmbedLibrary
    {
#if UNITY_STANDALONE_OSX
        const string PackageLibraryPath = "Packages/com.gilzoide.flex-ui/Plugins/build/macos/libflex-ui.dylib";
#elif UNITY_IOS
        const string PackageLibraryPath = "Packages/com.gilzoide.flex-ui/Plugins/build/ios/libflex-ui.dylib";
#elif UNITY_TVOS
        const string PackageLibraryPath = "Packages/com.gilzoide.flex-ui/Plugins/build/tvos/libflex-ui.dylib";
#elif UNITY_VISIONOS
        const string PackageLibraryPath = "Packages/com.gilzoide.flex-ui/Plugins/build/visionos/libflex-ui.dylib";
#endif
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

            var pbxProject = new PBXProject();
            pbxProject.ReadFromFile(pbxProjectPath);

            FileUtil.CopyFileOrDirectory(PackageLibraryPath, fullLibraryPath);
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
