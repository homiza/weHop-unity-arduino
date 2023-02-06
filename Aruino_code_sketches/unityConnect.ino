#include <SerialCommand.h>

void setup() {
    Serial.begin(9600);
   //while (!Serial) {
   // ; // wait for serial port to connect. Needed for native USB port only
 // }
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
 //establishContact();
}

// the loop function runs over and over again forever
void loop() {


  if (Serial.available()){
    char c = Serial.read();

  
    if(c == 'A'){
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("on"); 
      //delay(1000);
    }
    else if(c == 'Z'){
        digitalWrite(LED_BUILTIN, LOW);
        Serial.println("off"); 
        //delay(1000);
    }
    c == NULL;
  
  }
     // turn the LED on (HIGH is the voltage level)
                // wait for a second
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print('b');   // send a capital A
    delay(300);
  }
  
}
