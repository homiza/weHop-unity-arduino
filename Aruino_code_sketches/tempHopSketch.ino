#include <Adafruit_NeoPixel.h>

#define PIN 2   // input pin Neopixel is attached to
#define PIN2 12
#define PIN3 A0

#define NUMPIXELS 96 // number of neopixels in Ring
// 48, 96, 144, 192, 240, 288, 336 ...
#define FORCE_SENSOR_PIN A0 // the FSR and 10K pulldown are connected to A0
#define FORCE_SENSOR_PIN2 A1 // the FSR and 10K pulldown are connected to A1

/*
* Reduced bightness of pads to reduce powe
*/

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels_1 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);

int delayval = 100; // timing delay

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

void setup() {
  pixels_1.begin(); // Initializes the NeoPixel library.
  Serial.begin(9600);
}

void loop() {
 
 // sensorReader();
  //testLights();
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
    pixels_1.setPixelColor(i, pixels.Color(0,0,255));
    pixels_1.show();
    delay(delayval);
    //pixels_1.clear();
  }
  pixels_1.clear();
}

void padJump(){
  for(int i=0;i<12;i++){
      pixels_1.setPixelColor(i, pixels.Color(0,0,255));
        //pixels_1.show();
        //delay(delayval);
  }
  pixels_1.show();
  Serial.print("1,");
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
      pixels_1.setPixelColor(i, pixels.Color(0,0,120));
      
  }
 
  

  if(n == 'q'){
//  delay(2000);
     Serial.println("correct");
    for(int i=0;i<48;i++){
      pixels_1.setPixelColor(i, pixels.Color(0,0,120));
    pixels_1.show();
       pixels_1.clear();
  }
    //pixels_1.show();
    //pixels_1.clear();
      
  }
  else{
  
  pixels_1.show();
  pixels_1.clear();
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


int tempCount;

void pad2(){
  for(int i=49;i<96;i++){
          pixels_1.setPixelColor(i, pixels.Color(0,120,0));
    }

    pixels_1.show();
    //Serial.print("2,");
  //  delay(2000);
    
   // pixels_1.clear();
}
void pad3(){
  for(int i=97;i<144;i++){
          pixels_1.setPixelColor(i, pixels.Color(120,0,0));
    }
    pixels_1.show();
    //Serial.print("3,");
    //delay(2000);
    pixels_1.clear();
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

bool count = false;

//---------------------pressure detect -------------------------------------

//hopCounter++;

void pressureDetect(){
   int analogReading = analogRead(FORCE_SENSOR_PIN);
   int analogReading2 = analogRead(FORCE_SENSOR_PIN2);
   
  if((Serial.available()>0) || (Serial.available()==0)){
    bigSteppers = Serial.read();

   /* if((analogReading < 50) || (analogReading2 < 50)){
      pixels_1.clear();
      endWave();
    }*/
    
    if(analogReading > 50){
      pad1();
      hopCounter++;
      Serial.print(" hopCounter: ");
      Serial.println(hopCounter);
    }
    
     if(analogReading2 > 50){
      
      pad2();
      //count = true;
      //if (count == true){
      //  hopCounter++;
      //
       // count = false;
       Serial.print(" hopCounter: ");
      Serial.println(hopCounter);
      
    }
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
     // pixels_1.clear();
      endWave();  
    }
  }
    
  
}

void forceStep(){
  newSteppers = analogRead(PIN3);
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

void hopAttack(){
  byte randNum = random(0, 4);
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
              delay(2000);
            pixels_1.clear();
            break;
          }
            
      case 1:
          pad2();
          delay(2000);
          break;
      case 2:
          pad3();
          delay(2000);
          break;
      }
    }
  }


///------------test lights------------------------

void testLights(){
    for(int i=0;i<96;i++){
          pixels_1.setPixelColor(i, pixels.Color(0,60,0));
    }
    pixels_1.show();
    pixels_1.clear();
}

  void endWave(){
    pixels_1.clear();
    pixels_1.show();
  }

  //testLights end

//-------------down wave 2 start------------------------------
 void downWave2(){
      for(int i=0; i<46; i++) {

          pixels_1.setPixelColor(i, pixels.Color(255, 0, 0));
          pixels_1.show();
           //delay(2);
          //delay(5);
 
      }
      //pixels.show();
  }
//-------------down wave 2----------------------------------


//-----------  push State --------------------

//---------------------------------------

bool  pushState = false;
int  pushCounter = 0;
bool lastPushState = false;

void sensorReader(){
  int analogReading = analogRead(FORCE_SENSOR_PIN);
  int analogReading2 = analogRead(FORCE_SENSOR_PIN2);

   //pushState = analogReading;
  //Serial.print("Force sensor reading = ");
  //Serial.println(analogReading); // print the raw analog reading

  if(analogReading > 50){
    pushState = true;
  
  Serial.println("Force sensor reading = ");
  Serial.println(analogReading); // print the raw analog reading

  
   if(pushState != lastPushState){

          if(pushState == true){
            pushCounter++;
            Serial.println("on");
            Serial.print("number of button pushes: ");
            Serial.println(pushCounter);
          } else {
            // if the current state is LOW then the button went from on to off:
            Serial.println("off");
            //pushState = false;
          }
          delay(50);
        
        lastPushState = pushState;
  
   }
  }
  

/*
  if (analogReading < 10){       // from 0 to 9
    Serial.println(" -> no pressure");
    pixels_1.clear();
    endWave();}
  else if (analogReading <15){ // from 10 to 199
    Serial.println(" -> light touch");
    pixels_1.clear();
    endWave(); }
  else if (analogReading < 50) {// from 200 to 499
    Serial.println(" -> light squeeze");
    pixels_1.clear();
    endWave();}
 /* else if (analogReading < 800) {// from 500 to 799
    Serial.println(" -> medium squeeze");
    pixels.clear();
    endWave();}
  else{ // from 800 to 1023
    Serial.println(" -> big squeeze");
    //pixels.clear();
    downWave2();}
    
    

  delay(10);*/
  
}
void gameModeSelect(){
  if(modeCounter < 1){
  Serial.println("****************\n** WELCOME TO **\n**** weHOP! ****\n****************\n"); 
    Serial.println("Choose game mode: *freeHop* *Memory* *Math* *Hop Attack* *musicalHop*");
    modeCounter++;
  }
  while(Serial.available()==0){}
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
          
          pressureDetect();
          if(endFreeHop == true){
            //break;
            CurrentTime = millis();
           // break;
          }
          //------------- break loop -----------------
         /*  while(Serial.available()==0){}
           endFunc = Serial.read(); 
           if(endFunc == 'x')
            break;*/
        }
        ElaspedTime = (CurrentTime - StartTime)/1000;
       Serial.println(ElaspedTime); 
      }
   
      if(gameMode == "hopattack"){
        Serial.println("***hopattack mode intiated!****");
        StartTime = millis();
        while(stopTimer == false){
            for(;;){
                hopAttack();
                CurrentTime = millis();
                ElaspedTime = (CurrentTime - StartTime)/1000;
          CountDownTimer = fixedTime - ElaspedTime;
              /**/
              if((CountDownTimer >= 0)){
                   Serial.print("Start Time: ");
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
              }/**/
            }
          } 
          
        
      }
    
     //-----------End statement-----------------
    else{
        Serial.println("Enter valid mode!");
      }
         // Serial.print(modeCounter); 
       //modeCounter++;   
  
 
}
