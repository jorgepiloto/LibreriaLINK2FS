
#include <Arduino.h>

//--------------------------VARIABLES--------------------------

int pinA = 46;  // PIN CLK
int pinB = 48;  // PIN DT
int pinC = 50;  // PIN SW

int encoderPosCount = 0;
int pinALast;
int aVal;
boolean sentido; //Asumo como sentido positivo el de las agujas del reloj

 //--------------------------VOID SETUP----------------------
 void setup() {

   Serial.begin (115200);             //Comenzamos con la comunciación Serial

   pinMode (pinA,INPUT);              //CLK al pinA, ENTRADA
   pinMode (pinB,INPUT);              //DT al pinB,  ENTRADA
   pinMode (pinC,INPUT_PULLUP);

   pinALast = digitalRead(pinA);      //Leemos el encoder en el pinA

 }

 //--------------------------VOID LOOP----------------------
void loop(){

  if (digitalRead(pinC)== 0){encoderPosCount = 0; Serial.println(encoderPosCount); delay(250);}

  aVal = digitalRead(pinA);          //Volvemos a leer el encoder en el pinA

  if (aVal != pinALast){ //Si el valor leído es distinto al valor anterior, entonces hemos girado el encoder

    if (digitalRead(pinB) != aVal) {  // Si el pinB es distinto del pinA, rotamos en sentido Horario
      encoderPosCount ++;             // Nuestra posición aumenta en una unidad
      sentido = true;
    } else {                          // En caso contrario, rotamos en sentido Antihorario y la posición disminuye una unidad
      sentido = false;
      encoderPosCount--;
    }

    if (sentido){Serial.println(encoderPosCount);} //AUMENTAR
      else{Serial.println(encoderPosCount);} //DISMINUIR
  }

  pinALast = aVal;

} 
