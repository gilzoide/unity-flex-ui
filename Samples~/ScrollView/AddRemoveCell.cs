using UnityEngine;

namespace Gilzoide.FlexUi.Samples.ScrollView
{
    public class AddRemoveCell : MonoBehaviour
    {
        [SerializeField] private RectTransform _viewportContent;
        [SerializeField] private RectTransform _cellPrefab;

        public void AddCell()
        {
            Instantiate(_cellPrefab, _viewportContent);
        }

        public void RemoveCell()
        {
            Destroy(_viewportContent.GetChild(_viewportContent.childCount - 1).gameObject);
        }
    }
}
