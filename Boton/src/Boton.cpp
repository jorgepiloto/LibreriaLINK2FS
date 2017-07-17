/*
Ejemplo creado por Jorge Martínez, autor de Ingeniero de Aviones
*/

#include <Arduino.h>  //Esta librería no afecta en nada al código, pero facilita su desarrollo en otros lenguajes

int t = 250; //Una variable para controlar el tiempo de los delays

int boton1 = 22; //Hemos conectado el boton1 al pin 22. MODIFICA EL NUMERO "22"  SEGÚN TU PIN DE CONEXIÓN
int valBoton1 = 0; //Aquí alamacenaremos su valor

void setup(){

  Serial.begin(115200); //Se inicia la comunicación serial

  pinMode(boton1, INPUT_PULLUP); //Se define el modo en el que actuará el pin


}

void loop(){

  valBoton1 = digitalRead(boton1); //Leemos el estado del boton1 (si está pulsado o no)

  if (valBoton1 == 0){
     //El siguiente comando manda la instrucción deseada por el puerto serial
     //Escribe entre "" el comando de LINK2FS deseado: ejemplo "A06"
     //A06 en LINK2FS alterna entre la frecuencia standby y l activa de COM1
     Serial.println("A06");
     delay(t);
   }

}
