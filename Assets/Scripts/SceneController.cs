using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneController : MonoBehaviour
{
    public void switchScenes()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);    
    }
    public void mm4rmSV()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex - 1);   
    }
}
