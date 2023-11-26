using Gilzoide.FlexUi.Yoga;
using UnityEngine;

namespace Gilzoide.FlexUi
{
    [CreateAssetMenu]
    public class FlexLayoutConfig : ScriptableObject
    {
        [SerializeField, Min(0)] private float _pointScaleFactor = 1f;
        [SerializeField] private Errata _errata = Errata.None;

        [Header("Experimental Features")]
        [SerializeField] private bool _webFlexBasis = false;
        [SerializeField] private bool _absolutePercentageAgainstPaddingEdge = false;

        public YGConfig Config
        {
            get
            {
                if (_config.IsNull)
                {
                    _config.Instantiate();
                    RefreshConfig();
                }
                return _config;
            }
        }

        private YGConfig _config;

        protected void OnDisable()
        {
            _config.Dispose();
        }

        protected void RefreshConfig()
        {
            YGConfig config = Config;
            config.SetPointScaleFactor(_pointScaleFactor);
            config.SetErrata(_errata);
            config.SetExperimentalFeatureEnabled(ExperimentalFeature.WebFlexBasis, _webFlexBasis);
            config.SetExperimentalFeatureEnabled(ExperimentalFeature.AbsolutePercentageAgainstPaddingEdge, _absolutePercentageAgainstPaddingEdge);
        }

#if UNITY_EDITOR
        private void OnValidate()
        {
            RefreshConfig();
        }
#endif
    }
}
