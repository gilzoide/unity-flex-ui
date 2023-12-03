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
            if (!IsNull)
            {
                Yoga.YGConfigFree(_configPtr);
            }
        }

        public void SetPointScaleFactor(float enabled)
        {
            if (!IsNull)
            {
                Yoga.YGConfigSetPointScaleFactor(_configPtr, enabled);
            }
        }

        public void SetErrata(Errata errata)
        {
            if (!IsNull)
            {
                Yoga.YGConfigSetErrata(_configPtr, errata);
            }
        }

        public void SetExperimentalFeatureEnabled(ExperimentalFeature feature, bool enabled)
        {
            if (!IsNull)
            {
                Yoga.YGConfigSetExperimentalFeatureEnabled(_configPtr, feature, enabled);
            }
        }

        #endregion
    }
}
