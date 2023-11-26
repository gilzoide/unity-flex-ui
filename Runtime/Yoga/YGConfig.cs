using System;

namespace Gilzoide.FlexUi.Yoga
{
    public struct YGConfig : IDisposable, IEquatable<YGConfig>
    {
        internal IntPtr _configPtr;

        public bool IsNull => _configPtr == IntPtr.Zero;

        public static YGConfig GetDefaultConfig()
        {
            return new YGConfig
            {
                _configPtr = Yoga.YGConfigGetDefault(),
            };
        }

        public void Instantiate()
        {
            _configPtr = Yoga.YGConfigNew();
        }

        public void Dispose()
        {
            if (!IsNull)
            {
                Free();
                _configPtr = IntPtr.Zero;
            }
        }

        public bool Equals(YGConfig other)
        {
            return _configPtr == other._configPtr;
        }

        public void SetExperimentalFeatures(ExperimentalFeatureFlags experimentalFeatures)
        {
            SetExperimentalFeatureEnabled(ExperimentalFeature.WebFlexBasis, experimentalFeatures.HasFlag(ExperimentalFeatureFlags.WebFlexBasis));
            SetExperimentalFeatureEnabled(ExperimentalFeature.AbsolutePercentageAgainstPaddingEdge, experimentalFeatures.HasFlag(ExperimentalFeatureFlags.AbsolutePercentageAgainstPaddingEdge));
        }

        #region YGConfig

        public void Free()
        {
            Yoga.YGConfigFree(_configPtr);
        }

        public void SetUseWebDefaults(bool enabled)
        {
            Yoga.YGConfigSetUseWebDefaults(_configPtr, enabled);
        }

        public bool GetUseWebDefaults()
        {
            return Yoga.YGConfigGetUseWebDefaults(_configPtr);
        }

        public void SetPointScaleFactor(float enabled)
        {
            Yoga.YGConfigSetPointScaleFactor(_configPtr, enabled);
        }

        public float GetPointScaleFactor()
        {
            return Yoga.YGConfigGetPointScaleFactor(_configPtr);
        }

        public void SetErrata(Errata errata)
        {
            Yoga.YGConfigSetErrata(_configPtr, errata);
        }

        public Errata GetErrata()
        {
            return Yoga.YGConfigGetErrata(_configPtr);
        }

        public void SetExperimentalFeatureEnabled(ExperimentalFeature feature, bool enabled)
        {
            Yoga.YGConfigSetExperimentalFeatureEnabled(_configPtr, feature, enabled);
        }

        public bool IsExperimentalFeatureEnabled(ExperimentalFeature feature)
        {
            return Yoga.YGConfigIsExperimentalFeatureEnabled(_configPtr, feature);
        }

        #endregion
    }
}
