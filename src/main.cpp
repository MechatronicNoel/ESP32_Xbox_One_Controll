/*****************************************************************************************************************************************************************
   Project name:
     (Xbox One ESP32 Control)
   Copyright:
     (c) Call Me Noel
         Developer: Ing. Jose Noel Dominguez Miralrio
         E-mail: imnooee1@gmail.com
   Descripción:
     Layout de configuración de PINES
     LED1             GPIO14
     LED2             GPIO15
     LED3             GPIO5
     LED4             GPIO33
     BUZZER           GPIO23

   Date : 20 FEB 2019 Time: 9:20 PM

   Release : 1.0

   Configuracion:
     MCU:             ESP32 dev
     Oscillator:      XTAL 32.00000 MHz
     SW:              Visual Studio Code + Platformio 
*/

#include <Arduino.h>
#include "OneController.h"
#include "OneController.cpp"

// Pin Definitions 
#define LED1_Pin 14
#define LED2_Pin 15
#define LED3_Pin 5
#define LED4_Pin 33
#define Buzzer_Pin 23
//////////////////////////////

// setting PWM properties
const int freq = 5000;
const int ledChannel1 = 0;
const int ledChannel2 = 1;
const int ledChannel3 = 2;
const int resolution = 8;
////////////////////////////////


void setup() {

  Serial.begin(115200);
  ledcSetup(ledChannel1, freq, resolution);
  ledcAttachPin(LED1_Pin, ledChannel1);
  ledcAttachPin(LED2_Pin, ledChannel2);
  ledcAttachPin(LED3_Pin, ledChannel3);
  pinMode( LED4_Pin,OUTPUT);
  pinMode( Buzzer_Pin,OUTPUT);
  
}

void loop() {
  
  GetValues();
  ledcWrite(ledChannel1, MyOne.AxisLeftX);
  ledcWrite(ledChannel2, MyOne.AxisLeftY);
  ledcWrite(ledChannel3, MyOne.AxisRightX);

  if (MyOne.Buttons == 1){
    digitalWrite(LED4_Pin,HIGH);
  } else
  {
    digitalWrite(LED4_Pin,LOW);
  }

  if (MyOne.Buttons == 2){
    digitalWrite(Buzzer_Pin,HIGH);
  } else
  {
    digitalWrite(Buzzer_Pin,LOW);
  }

  // Para obtener los demas botones revisamos el valor al precionarlos en el control con la ayuda del software :) 
  

  

 
}