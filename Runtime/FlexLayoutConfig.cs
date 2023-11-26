using Gilzoide.FlexUi.Yoga;
using UnityEngine;

namespace Gilzoide.FlexUi
{
    [CreateAssetMenu]
    public class FlexLayoutConfig : ScriptableObject
    {
        [SerializeField] private bool _isDefaultConfig = false;
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
                    if (_isDefaultConfig)
                    {
                        _config = YGConfig.GetDefaultConfig();
                    }
                    else
                    {
                        _config.Instantiate();
                    }
                    RefreshConfig();
                }
                return _config;
            }
        }

        private YGConfig _config;

        protected void OnDisable()
        {
            if (!_config.Equals(YGConfig.GetDefaultConfig()))
            {
                _config.Dispose();
            }
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
