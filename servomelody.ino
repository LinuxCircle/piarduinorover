#include <Servo.h>
#include "pitches.h"

#define FIRST_TONE_PIN 7
#define NUM_OF_VOICES 2
#define LED_PIN 13

#define RED 11
#define GREEN 6
#define BLUE 5
#define YELLOW 10
#define WHITE 13


int leds[] = {RED, GREEN, BLUE, YELLOW, WHITE};


// notes in the melody:
int melody1[] = {
  NOTE_E7, NOTE_E7,0,NOTE_E7, 
  0, NOTE_C7, NOTE_E7,0,
  NOTE_G7,0,0,0,
  NOTE_G6,0,0,0,

  NOTE_C7, 0, 0,NOTE_G6, 
  0, 0,NOTE_E6,0,
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G7, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0,0,

  NOTE_C7, 0, 0,NOTE_G6, 
  0, 0,NOTE_E6,0,
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G7, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0,0,
};

int harmony1[] = {
  NOTE_FS6, NOTE_FS6,0,NOTE_FS6, 
  0, NOTE_FS6, NOTE_FS6,0,
  NOTE_B6,0,0,0,
  NOTE_G5,0,0,0,

  NOTE_E5, 0, 0,NOTE_C5, 
  0, 0,NOTE_G4,0,
  0, NOTE_C5, 0, NOTE_D5, 
  0, NOTE_CS5, NOTE_C5, 0,

  NOTE_C5, NOTE_G5, NOTE_B5, 
  NOTE_C6, 0, NOTE_A5, NOTE_B5, 
  0, NOTE_A5, 0,NOTE_E5, 
  NOTE_F5, NOTE_D5, 0,0,

  NOTE_E6, 0, 0,NOTE_C6, 
  0, 0,NOTE_G5,0,
  0, NOTE_C6, 0, NOTE_D6, 
  0, NOTE_CS6, NOTE_C6, 0, 

  NOTE_C6, NOTE_G6, NOTE_B6, 
  NOTE_C7, 0, NOTE_A6, NOTE_B6, 
  0, NOTE_A6, 0,NOTE_E6, 
  NOTE_F6, NOTE_D6, 0,0,
};

int underworld_melody[] = {
  NOTE_C5, NOTE_C6, NOTE_A4, NOTE_A5, 
  NOTE_AS4, NOTE_AS5, 0,
  0,
  NOTE_C5, NOTE_C6, NOTE_A4, NOTE_A5, 
  NOTE_AS4, NOTE_AS5, 0,
  0,
  NOTE_F4, NOTE_F5, NOTE_D4, NOTE_D5,
  NOTE_DS4, NOTE_DS5, 0,
  0,
  NOTE_F4, NOTE_F5, NOTE_D4, NOTE_D5,
  NOTE_DS4, NOTE_DS5, 0,
  0, NOTE_DS5, NOTE_D5, NOTE_CS5,
  NOTE_C5, NOTE_DS5, 
  NOTE_DS5, NOTE_GS4,
  NOTE_G4, NOTE_CS5,
  NOTE_C5, NOTE_FS5,NOTE_F5, NOTE_E4, NOTE_AS5, NOTE_A5,
  NOTE_GS5, NOTE_DS5, NOTE_B4,
  NOTE_AS4, NOTE_A4, NOTE_GS4,
  0, 0, 0
};

int underworld_melody1[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, 
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, 
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_D4, NOTE_CS4,
  NOTE_C4, NOTE_DS4, 
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4,NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//melody notes in miliseconds
int underworld_tempo[] = {
  200, 200, 200, 200, 
  200, 200, 400,
  800,
  200, 200, 200, 200, 
  200, 200, 400,
  800,
  200, 200, 200, 200, 
  200, 200, 400,
  800,
  200, 200, 200, 200, 
  200, 200, 400,
  400, 133, 133, 133,
  400, 400,
  400, 400,
  400, 400,
  133, 133, 133,133, 133, 133,
  267, 267, 267,
  267, 267, 267,
  800, 800, 800
};

int mel1Durations[] = {
  150, 150, 150,150, 
  150, 150, 150,150,
  150, 150,150,150,
  150, 150,150,150,

  150, 150,150,150,
  150, 150,150,150,
  150, 150, 150,150, 
  150, 150, 150,150, 

  200, 200, 200,
  150, 150,150,150,
  150, 150, 150,150, 
  150, 150, 150,150,

  150, 150, 150,150, 
  150, 150, 150,150,   
  150, 150, 150,150, 
  150, 150, 150,150, 

  200, 200, 200, 
  150, 150, 150,150,   
  150, 150, 150,150, 
  150, 150, 150,150,
};

int harm1Durations[] = {
  150, 150, 150,150, 
  150, 150, 150,150,
    150, 150, 150,150, 
  150, 150, 150,150, 

  150, 150, 150,150, 
  150, 150, 150,150,   
  150, 150, 150,150, 
  150, 150, 150,150, 

  150, 150, 150,150, 
  150, 150, 150,150,   
  150, 150, 150,150, 
  150, 150, 150,150,

  150, 150, 150,150, 
  150, 150, 150,150,   
  150, 150, 150,150, 
  150, 150, 150,150, 

  150, 150, 150,150, 
  150, 150, 150,150,   
  150, 150, 150,150, 
  150, 150, 150,150,
};

int incomingByte = 0;   // for incoming serial data
Servo myservo;  // create servo object to control a servo

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        myservo.attach(9);  // attaches the servo on pin 9 to the servo object
        myservo.write(65);
        Serial.println("Head servo standby");
      
        for (unsigned char i = 0; i < NUM_OF_VOICES; i++) {
          pinMode(i+FIRST_TONE_PIN,OUTPUT);
          Serial.println(i);
        }
      
        //led indicator
        //pinMode(LED_PIN,OUTPUT);

        //leds
        pinMode(RED,OUTPUT);
        pinMode(GREEN,OUTPUT);
        pinMode(BLUE,OUTPUT);
        pinMode(YELLOW,OUTPUT);
        pinMode(WHITE,OUTPUT);   
      
      
        // call magic function to play both voices
        Serial.println("play normal");
       // playTune(melody1, sizeof(melody1)/sizeof(int), mel1Durations, harmony1, sizeof(harmony1)/sizeof(int), mel1Durations);
        //playTune(underworld_melody, sizeof(underworld_melody)/sizeof(int), underworld_tempo, underworld_melody1, sizeof(underworld_melody1)/sizeof(int), underworld_tempo);

}

void led_off(){

                    digitalWrite(RED, LOW);
                  digitalWrite(GREEN, LOW);
                  digitalWrite(BLUE, LOW);
                  digitalWrite(YELLOW, LOW);
                  digitalWrite(WHITE, LOW);
}

void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                // say what you got:
                Serial.print("I received: ");
                
                Serial.println(incomingByte);
                //incomingByte = byte(incomingByte);
                Serial.println(incomingByte);
                if(int(incomingByte)==55){//7
                  myservo.write(30);
                  Serial.println("Max Up");
                  tone(8, NOTE_F5, 1000/5);
                }
                else if(int(incomingByte)==54){//6
                  myservo.write(40);
                  Serial.println("Up");
                  tone(8, NOTE_E5, 1000/5);
                }
                else if(int(incomingByte)==53){//5
                  myservo.write(50);
                  Serial.println("Mid Up");
                  tone(8, NOTE_D5, 1000/5);
                }else if(int(incomingByte)==52){//4
                  Serial.println("Straight");
                  myservo.write(60);
                  tone(8, NOTE_C5, 1000/4);
                 
                }else if(int(incomingByte)==51){//3
                  Serial.println("Mid Down");
                  myservo.write(70);
                  tone(8, NOTE_B4, 1000/5);
                }else if(int(incomingByte)==50){//2
                  myservo.write(80);
                  Serial.println("Down");
                  tone(8, NOTE_A4, 1000/5);
                
                }else if(int(incomingByte)==49){//1
                  Serial.println("Max Down");
                  myservo.write(90);
                  tone(8, NOTE_G4, 1000/5);

                }else if(int(incomingByte)==45){//-
                  playTune(melody1, sizeof(melody1)/sizeof(int), mel1Durations, harmony1, sizeof(harmony1)/sizeof(int), mel1Durations);
                }else if(int(incomingByte)==61){//+
                  playTune(underworld_melody, sizeof(underworld_melody)/sizeof(int), underworld_tempo, underworld_melody1, sizeof(underworld_melody1)/sizeof(int), underworld_tempo);
                 }else if(int(incomingByte)==114){//(R)ed
                  Serial.println("red");
                  led_off();
                  digitalWrite(RED, HIGH);
                  digitalWrite(WHITE, HIGH);

                }else if(int(incomingByte)==103){//(g)reen
                  led_off();
                  Serial.println("green");
                  digitalWrite(GREEN, HIGH);
                  digitalWrite(WHITE, HIGH);
                }else if(int(incomingByte)==98){//(b)blue
                  led_off();
                  Serial.println("blue");
                  digitalWrite(BLUE, HIGH);
                  digitalWrite(WHITE, HIGH);
                }else if(int(incomingByte)==121){//(y)ellow
                
                  led_off();
                  Serial.println("yellow");
                  digitalWrite(YELLOW, HIGH);
                  //digitalWrite(RED, HIGH);
                  //digitalWrite(GREEN, HIGH);
                  digitalWrite(WHITE, HIGH);
                }else if(int(incomingByte)==119){//(w)hite
                
                  led_off();
                  Serial.println("white");
                  digitalWrite(BLUE, HIGH);
                  digitalWrite(RED, HIGH);
                  digitalWrite(GREEN, HIGH);
                  digitalWrite(WHITE, HIGH);
                }else{
                  Serial.print("Led off");
                  led_off();
                }
        }


        
}

// no need to modify anything below for basic use
void playTune(int melody[], int melLength, int melDurations[], int harmony[], int harmLength, int harmDurations[])
{
  unsigned int Counts[] = { 0, 0};
  unsigned int Periods[] = { 0, 0};
  unsigned char States[] = { 0, 0};

  unsigned long stopTimeNote1 = 0;
  unsigned long stopTimeNote2 = 0;
  unsigned char TimedPin = 0;
  unsigned int CurrentCount = 0;
  unsigned char i;
  unsigned char indexMel = 0, indexHarm = 0;
  int led=0;
  int count =0;
  while (1) {
    
    CurrentCount = Counts[0];
    TimedPin = 0;

    for (i=1;i<NUM_OF_VOICES;i++) {
      if (Counts[i] < CurrentCount) {
        TimedPin = i;
        CurrentCount = Counts[i];
      } // for
    }
    if (CurrentCount > 3)
      delayMicroseconds(CurrentCount);
    if (Periods[TimedPin] < 65535)
      States[TimedPin] = !States[TimedPin];
    

    //Serial.println(melody[indexMel]);
    if(melody[indexMel]!=0)
      digitalWrite(leds[led], States[TimedPin]);
    digitalWrite(FIRST_TONE_PIN+TimedPin,States[TimedPin]);

//    if(melody[indexMel]!=0)
      
    

    if (millis() >= stopTimeNote1) {
      
      if (indexMel >= melLength)
        break;
      stopTimeNote1 = millis() + melDurations[indexMel];
      Periods[0] = 1000000 / melody[indexMel++];
      
    
    }
    //Serial.println(melody[indexMel]);
    if (millis() >= stopTimeNote2) {
      if (indexHarm >= harmLength)
        break;
      stopTimeNote2 = millis() + harmDurations[indexHarm];
      Periods[1] = 1000000 / harmony[indexHarm++];
      digitalWrite(leds[led],LOW);
    }

    for (i = 0; i < NUM_OF_VOICES; i++) {
      Counts[i] = Counts[i] - CurrentCount;
    }
    Counts[TimedPin] = Periods[TimedPin];
        

    led=indexMel%5; //play different led for each note, except for the 0 ones
    

  }
  led_off();
}
