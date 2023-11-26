using Gilzoide.FlexUi.Yoga;
using UnityEngine;

namespace Gilzoide.FlexUi
{
    [CreateAssetMenu]
    public class FlexLayoutConfig : ScriptableObject
    {
        [Tooltip("If true, this configuration will be used by FlexLayout nodes that do not have a configuration set explicitly.")]
        [SerializeField] private bool _isDefaultConfig = false;

        [Tooltip("Yoga will by deafult round final layout positions and dimensions to the nearst point.\n"
            + "'Point Scale Factor' controls the density of the grid used for layout rounding (e.g. to round to the closest display pixel).\n"
            + "Set this to 0 to avoid rounding the layout results.")]
        [SerializeField, Min(0)] private float _pointScaleFactor = 1f;

        [Tooltip("Configures how Yoga balances W3C conformance vs compatibility with layouts created against earlier versions of Yoga.")]
        [SerializeField] private Errata _errata = Errata.None;

        [Tooltip("Turn experimental Yoga features on or off")]
        [SerializeField] private ExperimentalFeatureFlags _experimentalFeatures = default;

        #region Property getters/setters

        public float PointScaleFactor
        {
            get => _pointScaleFactor;
            set
            {
                _pointScaleFactor = value;
                _config.SetPointScaleFactor(value);
            }
        }
        public Errata Errata
        {
            get => _errata;
            set
            {
                _errata = value;
                _config.SetErrata(value);
            }
        }
        public ExperimentalFeatureFlags ExperimentalFeatures
        {
            get => _experimentalFeatures;
            set
            {
                _experimentalFeatures = value;
                _config.SetExperimentalFeatures(value);
            }
        }

        #endregion

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
            _config.SetPointScaleFactor(_pointScaleFactor);
            _config.SetErrata(_errata);
            _config.SetExperimentalFeatures(_experimentalFeatures);
        }

#if UNITY_EDITOR
        private void OnValidate()
        {
            RefreshConfig();
        }
#endif
    }
}
