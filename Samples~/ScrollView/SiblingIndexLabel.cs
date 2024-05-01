using UnityEngine;
using UnityEngine.UI;

namespace Gilzoide.FlexUi.Samples.ScrollView
{
    [ExecuteAlways]
    public class SiblingIndexLabel : MonoBehaviour
    {
        [SerializeField] private Text _label;

        private void OnEnable()
        {
            _label.text = transform.GetSiblingIndex().ToString();
        }
    }
}
