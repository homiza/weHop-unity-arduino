using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ValueAmount : MonoBehaviour
{
    // Start is called before the first frame update
    private Text valueAmount;
    private int valueCounter;

    void Start()
    {
        valueCounter = 0;
        valueAmount = GetComponent<Text>();
    }

    // Update is called once per frame
    private void Update()
    {
        valueAmount.text = valueCounter.ToString();
    }

    public void IncreaseValue()
    {
        valueCounter += 1;
    }
}
