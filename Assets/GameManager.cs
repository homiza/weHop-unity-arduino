using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public TextMeshProUGUI countText;
    public Button countButton;
    public Button resetButton;

    private int countNumber = 0;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void Count()
    {
        countNumber += 10;
        countText.text = countNumber.ToString();
    
    }

    public void Reset()
    {
        countText.text = "0";
        countNumber = 0;
    }
}
