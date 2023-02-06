#include <Adafruit_NeoPixel.h>
#include <DFRobotDFPlayerMini.h>

 // 48, 96, ... ,336 number of neopixels in Ring
#define FORCE_SENSOR_PIN A0 // the FSR and 10K pulldown are connected to A0
#define FORCE_SENSOR_PIN2 A1 // the FSR and 10K pulldown are connected to A1
#define FORCE_SENSOR_PIN3 A2
#define FORCE_SENSOR_PIN4 A3
#define FORCE_SENSOR_PIN5 A4
#define FORCE_SENSOR_PIN6 A7
#define FORCE_SENSOR_PIN7 A6

#define PIN 4   // input pin Neopixel is attached to
#define NUMPIXELS 336 



#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels_1 = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels_2 = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

DFRobotDFPlayerMini player;

int delayval = 1000; // timing delay

char bigSteppers = ' ';
char endFunc; 
int newSteppers;

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

int modeCounter = 0;
int hopCounter = 0;

unsigned long StartTime;
unsigned long CurrentTime;
unsigned long ElaspedTime;
unsigned long CountDownTimer;
unsigned long oldCountDownTimer;
unsigned long fixedTime = 30;

bool endFreeHop = false;
bool stopTimer = false;

int analogReading;
int analogReading2;

void setup() {
  pixels_1.begin(); // Initializes the NeoPixel library.
  Serial.begin(9600); 
  Serial1.begin(9600);
  if (player.begin(Serial1)) {
    Serial.println("OK");
    player.volume(30);
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
}


void loop() {
  //hopAttack();
   //pixels.clear();
   //freeHop();
  gameModeSelect();
  //matchGame();
  //countDown();
  //pixels_1.show();
  //randomFunc();
  //pressureDetect();
  //forceStep();
 // padJump();

   //padLight();
   
 /*-------------------------------------------------
  setColor();

  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
    
    // Serial.println(i);
    
    if (i == NUMPIXELS){
      i = 0; // start all over again!
        setColor();
    }
  }-------------------------------------------------*/
}

// setColor()
// picks random values to set for RGB

void padLight(){
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,30,0));
       //pixels_1.clear();
  }
  pixels.show();
  delay(100);
  pixels.clear();
   Serial.print("works!!");
}

void padJump(){
  for(int i=0;i<12;i++){
      pixels_1.setPixelColor(i, pixels.Color(0,0,255));
        //pixels_1.show();
        //delay(delayval);
  }
  pixels_1.show();
 
  delay(500);
  pixels_1.clear();
  
  
  for(int i=12;i<24;i++){
      pixels_1.setPixelColor(i, pixels.Color(0,255,0));
        //pixels_1.show();
        //delay(delayval);
  }
  pixels_1.show();
  Serial.print("2,");
  delay(500);
  pixels_1.clear();
  
  for(int i=24;i<36;i++){
      pixels_1.setPixelColor(i, pixels.Color(255,0,0));
        //pixels_1.show();
        //delay(delayval);
  }
  pixels_1.show();
  Serial.print("3,");
  delay(500);
  pixels_1.clear();
}



///brainsstorming -----------------------------------------------
//randomize pattern


 char mg; char n;
void pad1(){
  mg = Serial.read();
  n=mg;
  for(int i=0;i<48;i++){
      pixels_1.setPixelColor(i, pixels.Color(0,0,60));
    
  }
  

  if(n == 'q'){
//  delay(2000);
     Serial.println("correct");
    for(int i=0;i<12;i++){
      pixels_1.setPixelColor(i, pixels.Color(0,0,255));
    pixels_1.show();
       pixels_1.clear();
  }
    //pixels_1.show();
    //pixels_1.clear();
      
  }
  else{
  
  pixels_1.show();
  pixels_1.clear();
  //pixels_1.show();
  }   n=' ';
  //Serial.print("1,");
 
/*  if(mg == 'a'){
    Serial.println("correct");
    pixels_1.show();
    pixels_1.clear();
  }
  if((mg != 'a')|| (mg == ' ')){ 
    Serial.println("wrong!");
    delay(2000);
    pixels_1.clear();}*/
}

void pad8(){
  for(int i=0;i<47;i++){
          pixels_1.setPixelColor(i, pixels.Color(0,0,160));
    }
    pixels_1.show();
    pixels_1.clear();
    //Serial.print("2,");
  // endWave();
}

void pad2(){
  for(int i=49;i<96;i++){
          pixels_2.setPixelColor(i, pixels.Color(0,160,0));
    }
    pixels_2.show();
    pixels_2.clear();
    //Serial.print("2,");
  //  delay(2000);
  // endWave();
}

void pad3(){
  for(int i=97;i<144;i++){
          pixels_1.setPixelColor(i, pixels.Color(160,0,0));
    }
    pixels_1.show();
    pixels_1.clear();
}

void pad4(){
  for(int i=144;i<192;i++){
          pixels_1.setPixelColor(i, pixels.Color(0,160,0));
    }
    pixels_1.show();
    pixels_1.clear();
}

void pad5(){
  for(int i=144;i<192;i++){
          pixels_1.setPixelColor(i, pixels.Color(0,0,10));
    }
    pixels_1.show();
    pixels_1.clear();
}

void pad6(){
  for(int i=193;i<240;i++){
          pixels_1.setPixelColor(i, pixels.Color(10,0,0));
    }
    pixels_1.show();
    pixels_1.clear();
}
void pad7(){
  for(int i=240;i<288;i++){
          pixels_1.setPixelColor(i, pixels.Color(0,160,0));
    }
    pixels_1.show();
    pixels_1.clear();
}
void endWave(){
     pixels_1.clear();
    pixels_1.show();
//hopCounter += 1;
    
}


void randomFunc(){
  byte randNum = random(0, 1);
  switch(randNum){
    case 0:
      pad1();
      break;
    case 1:
      pad2();
      break;
    case 2:
      pad3();
      break;
   /* default:
      break;*/
  }
}


//--------------------------------------------------------------Pressure Detect start-----------------------------------------------
int lss  = LOW; //lastSteadyState
//int lastPushState = LOW;
int lfs = LOW; //last flickerable state
int currState;
bool addOne = false;
int csreading = 0; 
int cs2reading = 0; 
int lsreading = 0;  

unsigned long ldt = 0;  // the last time the output pin was toggled (lastdebouncetime)
unsigned long debounceDelay = 50;

void pressureDetect(){
   //analogReading = analogRead(FORCE_SENSOR_PIN);
   csreading = analogRead(FORCE_SENSOR_PIN);
   cs2reading = analogRead(FORCE_SENSOR_PIN2);
   Serial.print("Sensor2: ");
   Serial.println(cs2reading);

   if(currState != lfs){
     ldt = millis();
     lfs = csreading;
   }

   if((millis()-ldt > debounceDelay)){
        if(csreading > 100){
          currState = HIGH;
        }
        else if(csreading < 100){
          currState = LOW;
        }
   
  //

 
  if (csreading > 50){
        
         pad8();
       
         if(lss == HIGH  && currState == LOW ){
       
        Serial.print("Button pressed: ");
        //hopCounter++;
        Serial.println(hopCounter);
       // delay(500); 
         }         
      //}
 
      lss = currState;
   
      }
      
      /*else if (csreading < 50){
        pixels_1.clear();
        pixels_1.show();
      }*/
      

      if (cs2reading > 50){
         pad2();
         if(lss == HIGH  && currState == LOW ){
            Serial.print("Button pressed: ");
            hopCounter++;
            Serial.println(hopCounter);
           // delay(500); 
         }          
      //}
 
      lss = currState;
      }

       if(cs2reading < 50 && csreading < 50){

        for(int i = 49; i<96; i++){
             pixels_2.setPixelColor(i, pixels_2.Color(0,0,0));
        }
        pixels_2.show();
        pixels_2.clear();
    
      }  
   }



/*    
     if((lastPushState == HIGH || lastPushState > 50) && ((currState == LOW && currState < 50 ) || (currState == HIGH && currState < 50 ))){
      Serial.print("Button pressed: ");
      hopCounter++;
      Serial.println(hopCounter);
                  
    }

      lastPushState = currState;
    
  if((Serial.available()>0) || (Serial.available()==0)){
    bigSteppers = Serial.read();

    /*
     *   if((lastState == HIGH || lastState > 200) && (currState == LOW || currState < 200)){
       Serial.print("BUTTON PRESSED ");
        counter++;
        Serial.println(counter);
        
      }
     */
    
   
    
    
   /*   
    if(bigSteppers == 'd'){
      pad3();
       hopCounter++;
        Serial.print(" hopCounter: ");
      Serial.println(hopCounter);
    }
   if(bigSteppers == 'x'){
       pixels_1.clear();
        pixels_1.show();
        endFreeHop = true;
    }
    else{
      pixels_1.clear();
        
    }*/

  
    
  //}

}
//------------------------------------------------------------------Pressure Detect end ----------------------------------------------------------------------------

//-----------------------------End wave -----------------------------------------------------------------------

void forceStep(){
  newSteppers = analogRead(PIN);
    Serial.println(newSteppers);
    if(newSteppers > 200){
          pad1();
      }
   if(newSteppers < 200){
    pixels_1.show();
    pixels_1.clear();
    
 
  }
}


void setColor(){
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
  Serial.print("red: ");
  Serial.println(redColor);
  Serial.print("green: ");
  Serial.println(greenColor);
  Serial.print("blue: ");
  Serial.println(blueColor);
  
}


void countDown(){
  StartTime = millis();
  while(stopTimer == false){
    CurrentTime = millis();
     ElaspedTime = (CurrentTime - StartTime)/1000;
     CountDownTimer = fixedTime - ElaspedTime;
     oldCountDownTimer = (CountDownTimer - 1);
     Serial.print("Elasped Time: ");
     Serial.print(ElaspedTime);
    
    if((CountDownTimer >= 20)){
     Serial.print(", Start Time: ");
      Serial.print(StartTime);
      Serial.print(", Current Time: ");
      Serial.print(CurrentTime);
       Serial.print(", Countdown Timer: ");
      Serial.println(CountDownTimer);
      delay(1000);
    }if(CountDownTimer == 20){
      Serial.println("\nTimer Over!");
      stopTimer = true;
      break;}
  }
    
}

//---------------------------------------------------------HOP ATTACK ------------------------------------------------------------------------HOP ATTACK-----------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void hopAttack(){
  byte randNum = random(0, 7);
    switch(randNum){
      case 0:
          pad8();
          break;
      case 1:
          pad2();
          break;
      case 2:
          pad3();
          break;
      case 3:
          pad4();
          break;
      case 4:
          pad5();
          break;
      case 5:
          pad6();
          break;
      case 6:
          pad7();
          break;
    }
}

String v;
String mm;
void matchGame(){
   //mm = Serial.readString();
while(Serial.available()>=0){
    mm = Serial.readString();
 byte randNum = random(0, 4);

    switch(randNum){
       case 0:
          while(mm == ""){
            for(int i=0;i<12;i++){
                pixels_1.setPixelColor(i, pixels.Color(0,0,255));
            }
            pixels_1.show();
            delay(500);
            v = Serial.readString();
            
            if(v == "a"){
              Serial.println("yes");
              for(int j=0;j<12;j++){
                  pixels_1.setPixelColor(j, pixels.Color(0,0,255));
                    pixels_1.show();
              pixels_1.clear();
                    //break;
              }
            } else
              delay(1000);
            pixels_1.clear();
            break;
          }
            
      case 1:
           while(mm == ""){
            for(int i=12;i<24;i++){
                pixels_1.setPixelColor(i, pixels.Color(0,255,0));
            }
            pixels_1.show();
            delay(500);
            v = Serial.readString();
            
            if(v == "s"){
              Serial.println("yes");
              for(int j=12;j<24;j++){
                  pixels_1.setPixelColor(j, pixels.Color(0,255,0));
                    pixels_1.show();
              pixels_1.clear();
                    //break;
              }
            } else
              delay(1000);
            pixels_1.clear();
            break;
          }
            
      case 2:
           while(mm == ""){
            for(int i=24;i<36;i++){
                pixels_1.setPixelColor(i, pixels.Color(255,0,0));
            }
            pixels_1.show();
            delay(500);
            v = Serial.readString();
            
            if(v == "d"){
              Serial.println("yes");
              for(int j=24;j<36;j++){
                  pixels_1.setPixelColor(j, pixels.Color(255,0,0));
                    pixels_1.show();
              pixels_1.clear();
                    //break;
              }
            } else
              delay(1000);
            pixels_1.clear();
            break;
          }
            
      }
    }
  }

  //----------------------------------FREE HOP -------------------------------------------------
  //--------------------------------------------------------------------------------------------
  //--------------------------------------------------------------------------------------------

 int sensor1; int sensor2; int sensor3; int sensor4; int sensor5; int sensor6; int sensor7;

 

  void freeHop(){
     sensor1 = analogRead(FORCE_SENSOR_PIN);
     sensor2 = analogRead(FORCE_SENSOR_PIN2);
     sensor3 = analogRead(FORCE_SENSOR_PIN3);
     sensor4 = analogRead(FORCE_SENSOR_PIN4);
     sensor5 = analogRead(FORCE_SENSOR_PIN5);
     sensor6 = analogRead(FORCE_SENSOR_PIN6);
     sensor7 = analogRead(FORCE_SENSOR_PIN7);
 
     /*  Serial.print("Sensor1: ");
       Serial.print(sensor1);
       Serial.print(", Sensor2: ");
       Serial.println(sensor2);*/
 /*      Serial.print(", Sensor3: ");
       Serial.print(sensor3);
       Serial.print(", Sensor4: ");
       Serial.print(sensor4);
       Serial.print(", Sensor5: ");
       Serial.print(sensor5);
       Serial.print(", Sensor6: ");
       Serial.print(sensor6);
       Serial.print(", Sensor7: ");
       Serial.println(sensor7);
*/

   //--------------Start of FREEHOP LOGIC ------------------------------------------
  // csreading = analogRead(FORCE_SENSOR_PIN);
  // cs2reading = analogRead(FORCE_SENSOR_PIN2);
  // Serial.print("Sensor2: ");
  // Serial.println(cs2reading);


//{---------------------------------- TILE ONE-------------------------------------
   if(currState != lfs){
     ldt = millis();
     lfs = sensor1;
   }

        if(sensor1 > 100 || sensor2 > 100 || sensor3 > 100 || sensor4 > 100 || sensor5 > 100 || sensor6 > 100 || sensor7 > 50){
          currState = HIGH;
        }
        else if(sensor1 < 100 || sensor2 < 100 || sensor3 < 100 || sensor4 < 100 || sensor5 < 100 || sensor6 < 100 || sensor7 < 50){
          currState = LOW;
        }

      
  if (sensor1 > 50){
        
         pad8(); 
          //player.playMp3Folder(1);
         if(lss == HIGH && currState == LOW )
         {
              Serial.print("Button pressed: ");
               player.playMp3Folder(1);
              hopCounter++;
              Serial.println(hopCounter);
         }         
          lss = currState;
   }
      
//------------------------------------------ TILE TWO ---------------------------------
      if (sensor2 > 50){
         pad2();
         player.playMp3Folder(1);
         if(lss == HIGH && currState == LOW ){
            Serial.print("Button pressed: ");
            hopCounter++;
            Serial.println(hopCounter);
           // delay(500); 
         }          
      lss = currState;
      }

       if(cs2reading < 50 && csreading < 50){

        for(int i = 49; i<96; i++){
             pixels_2.setPixelColor(i, pixels_2.Color(0,0,0));
        }
        pixels_2.show();
        pixels_2.clear();
    
      }  
  
//--------------------------------------TIEL THREEE ---------------------------
      if (sensor3 > 50){
         pad3();
          player.playMp3Folder(1);
         if(lss == HIGH && currState == LOW){
            Serial.print("Button pressed: ");
            hopCounter++;
            Serial.println(hopCounter);
           // delay(500); 
         }          
      lss = currState;
      }
  


// ---------------------------------------------TILE FOUR ------------------------------------------
      if (sensor4 > 50){
         pad4();
          player.playMp3Folder(1);
         if(lss == HIGH && currState == LOW ){
            Serial.print("Button pressed: ");
            hopCounter++;
            Serial.println(hopCounter);
           // delay(500); 
         }          
      lss = currState;
      }
  

 // --------------------------------------TILE 5 -----------------------------------------
       if (sensor5 > 50){
         pad5();
          player.playMp3Folder(1);
         if(lss == HIGH && currState == LOW ){
            Serial.print("Button pressed: ");
            hopCounter++;
            Serial.println(hopCounter);
           // delay(500); 
         }          
      lss = currState;
      }

//---------------------------------------TILE 6 ----------------------------------------
      if (sensor6 > 50){
         pad6();
         player.playMp3Folder(1);
         if(lss == HIGH && currState == LOW ){
            Serial.print("Button pressed: ");
            hopCounter++;
            Serial.println(hopCounter);
           // delay(500); 
         }          
      lss = currState;  
      }
//--------------------------------------TILE 7 -----------------------------------------------

      if (sensor7 > 50){
         pad7();
         player.playMp3Folder(1);
         if(lss == HIGH && currState == LOW ){
            Serial.print("Button pressed: ");
            hopCounter++;
            Serial.println(hopCounter);
           // delay(500); 
         }          
      lss = currState;
      }
  }

//----------------------------------END OF FREE HOP ---------------------------------------------------------FREE HOP
//------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------

//------------------------------------Musical Hop ---------------------------------------------

// 

void musicalHop(){
  
    byte randNum = random(0, 7);
    switch(randNum){
      case 0:
          pad8();
          break;
      case 1:
          pad2();
          break;
      case 2:
          pad3();
          break;
      case 3:
          pad4();
          break;
      case 4:
          pad5();
          break;
      case 5:
          pad6();
          break;
      case 6:
          pad7();
          break;
    }
}


void gameModeSelect(){
  if(modeCounter < 1){
  Serial.println("\n\n****************\n** WELCOME TO **\n**** weHOP! ****\n****************\n"); 
    Serial.println("Choose game mode: *freeHop* *Memory* *Math* *Hop Attack* *musicalHop* *test*");
    modeCounter++;
  }
  while(Serial.available()){}
    String gameMode = Serial.readString();
      //gameMode.trim();
      if(gameMode == "memory"){
        for(;;){
          randomFunc();
        }
      }
  
      if(gameMode == "freehop"){
        Serial.println("***freehop mode initiated!****");
        StartTime = millis();
        for(;;){
          freeHop();
         // pressureDetect();
          if(endFreeHop == true){
            //break;
            CurrentTime = millis();
            break;
          }
          //------------- break loop -----------------
          if(Serial.available()){
           endFunc  = Serial.read(); 
           if(endFunc == 'x')
           endFreeHop = true;
          }
        }
        ElaspedTime = (CurrentTime - StartTime)/1000;
        Serial.print("\nYou made [");
        Serial.print(hopCounter);
        Serial.print("] total jumps in [");
        Serial.print(ElaspedTime);
        Serial.println("] seconds.");
        Serial.println("GOOD JOB! :)");
        modeCounter = 0;
        hopCounter = 0;
        endFreeHop = false;
      }
     
   
      if(gameMode == "hopattack"){
        Serial.println("***hopattack mode intiated!****");
        StartTime = millis();
        while(stopTimer == false){
            for(;;){
                hopAttack();
                //matchGame();
               if(stopTimer == true){
                CurrentTime = millis();
                //stopTimer = false;
                break;
                
              }
           
                CurrentTime = millis();
                ElaspedTime = (CurrentTime - StartTime)/1000;
          CountDownTimer = fixedTime - ElaspedTime;
           
              /**/
              if((CountDownTimer >= 0)){
                 Serial.print("Elasped time: "); 
                    Serial.print(ElaspedTime); 
                   Serial.print(", Start Time: ");
                    Serial.print(StartTime);
                    Serial.print(", Current Time: ");
                    Serial.print(CurrentTime);
                     Serial.print(", Countdown Timer: ");
                    Serial.println(CountDownTimer);
                    delay(1000);
              }if(CountDownTimer == 0){
                Serial.println("\nTimer Over!");
                stopTimer = true;
                //break;
              }/**/

             
            }
        }
        
      }
  if(gameMode == "test"){
    Serial.println("test mode selected!");
     StartTime = millis();
          while(Serial.available()>=0){
            mm = Serial.readString();
            byte randNum = random(0, 4);
           
          // for(;;){
              switch(randNum){
            
             
              /*
            if(CountDownTimer >= 0){
                 Serial.println("Elasped time: "); 
                    Serial.print(ElaspedTime); 
                   Serial.print(", Start Time: ");
                    Serial.print(StartTime);
                    Serial.print(", Current Time: ");
                    Serial.print(CurrentTime);
                     Serial.print(", Countdown Timer: ");
                    Serial.println(CountDownTimer);
                    delay(1000);
              }if(CountDownTimer == 0){
                Serial.println("\nTimer Over!");
                stopTimer = true;
                break;
              }*/
            
             case 0:
              
                //---------case 0 code--------
                while(mm >= ""){
                  for(int i=0;i<12;i++){
                      pixels_1.setPixelColor(i, pixels.Color(0,0,255));
                  }
                  pixels_1.show();
                  delay(500);
                 // v = Serial.readString();
                  
                  //--------timer start---------
                   CurrentTime = millis();
              ElaspedTime = (CurrentTime - StartTime)/1000;
          CountDownTimer = fixedTime - ElaspedTime;
                if(ElaspedTime >= 0){
                 Serial.println("Elasped time: "); 
                    Serial.print(ElaspedTime); 
                   Serial.print(", Start Time: ");
                    Serial.print(StartTime);
                    Serial.print(", Current Time: ");
                    Serial.print(CurrentTime);
                     Serial.print(", Countdown Timer: ");
                    Serial.println(CountDownTimer);
                    delay(200);
                }
                if(ElaspedTime >= 40){
                    Serial.println("\nTimer Over!");
                    stopTimer = true;
                    break;
               }
                   v = Serial.readString();
                  //------t end---

                  if(v == "a"){
                    Serial.println("yes");
                      for(int j=0;j<12;j++){
                          pixels_1.setPixelColor(j, pixels.Color(0,0,255));
                          pixels_1.show();
                          pixels_1.clear();
                          //break;
                      }
                  } else
                    delay(1000);
                  pixels_1.clear();
                  break;
                }

            case 1:
                 while(mm == ""){
                  for(int i=12;i<24;i++){
                      pixels_1.setPixelColor(i, pixels.Color(0,255,0));
                  }
                  pixels_1.show();
                  delay(500);
                 // v = Serial.readString();
                   
                   //--------timer start---------
                   CurrentTime = millis();
              ElaspedTime = (CurrentTime - StartTime)/1000;
          CountDownTimer = fixedTime - ElaspedTime;
                if(ElaspedTime >= 0){
                 Serial.println("Elasped time: "); 
                    Serial.print(ElaspedTime); 
                   Serial.print(", Start Time: ");
                    Serial.print(StartTime);
                    Serial.print(", Current Time: ");
                    Serial.print(CurrentTime);
                     Serial.print(", Countdown Timer: ");
                    Serial.println(CountDownTimer);
                    delay(200);
                }
                if(ElaspedTime >= 40){
                    Serial.println("\nTimer Over!");
                    stopTimer = true;
                    break;
               }
                   v = Serial.readString();
                  //------t end---

                  if(v == "s"){
                    Serial.println("yes");
                      for(int j=12;j<24;j++){
                          pixels_1.setPixelColor(j, pixels.Color(0,255,0));
                          pixels_1.show();
                          pixels_1.clear();
                          //break;
                      }
                  } else
                    delay(1000);
                  pixels_1.clear();
                  break;
                }

            case 2:
                 while(mm == ""){
                  for(int i=24;i<36;i++){
                      pixels_1.setPixelColor(i, pixels.Color(255,0,0));
                  }
                  pixels_1.show();
                  delay(500);
                 // v = Serial.readString();
                   
                         //--------timer start---------
                       CurrentTime = millis();
                      ElaspedTime = (CurrentTime - StartTime)/1000;
                      CountDownTimer = fixedTime - ElaspedTime;
                      if(ElaspedTime >= 0){
                       Serial.println("Elasped time: "); 
                          Serial.print(ElaspedTime); 
                         Serial.print(", Start Time: ");
                          Serial.print(StartTime);
                          Serial.print(", Current Time: ");
                          Serial.print(CurrentTime);
                           Serial.print(", Countdown Timer: ");
                          Serial.println(CountDownTimer);
                          delay(200);
                        }
                      if(ElaspedTime >= 40){
                          Serial.println("\nTimer Over!");
                          stopTimer = true;
                          break;
                       }
                         v = Serial.readString();
                        //------t end---

                  if(v == "d"){
                    Serial.println("yes");
                      for(int j=24;j<36;j++){
                          pixels_1.setPixelColor(j, pixels.Color(255,0,0));
                          pixels_1.show();
                          pixels_1.clear();
                          //break;
                      }
                  } else
                    delay(1000);
                  pixels_1.clear();
                  break;
                }

            }  
              
           // }//-- while true
        
          }
  }//--if test
    
     //-----------End statement-----------------
    else{
      /*
        Serial.println("\nEnter valid mode!!!");
        Serial.println("\n****************\n** WELCOME TO **\n**** weHOP! ****\n****************\n"); 
      Serial.println("Choose game mode: *freeHop* *Memory* *Math* *Hop Attack* *musicalHop* *test*");*/

      }
         // Serial.print(modeCounter); 
       //modeCounter++;   
      
}
