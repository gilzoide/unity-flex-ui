using System;

namespace Gilzoide.FlexUi.Yoga
{
    public struct YGConfig : IDisposable
    {
        internal IntPtr _configPtr;

        public bool IsNull => _configPtr == IntPtr.Zero;

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
    }
}
