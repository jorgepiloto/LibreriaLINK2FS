//Ejemplo de un LCD con comunicación Serial


//-------------------------LIBRERIAS-----------------------

#include <Arduino.h>
#include <LiquidCrystal.h>

//-------------LAS CONEXIONES DEL DISPLAY LCD--------------

// VSS pin to GND
// VDD pin to +5V
// VO pin to potentiometer
// RS pin to digital pin 12
// R/W pin to ground
// E pin to digital pin 11

// D0 no attached
// D1 no attached
// D2 no attached
// D3 no attached

// D4 pin to digital pin 5
// D5 pin to digital pin 4
// D6 pin to digital pin 3
// D7 pin to digital pin 2

// A pin to +5V (anode-positive)
// K pin to GND (kathode-negative)


//----------------------VARIABLES-----------------------------

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Iniciamos el display LCD

//---------------------VOID SETUP------------------------------

void setup() {

  lcd.begin(16, 2); //Definimos las dimensiones del display
  lcd.clear(); // Limpiamos la pantalla del mismo

  Serial.begin(115200 ); //Iniciamos la comunicación Serial
}


//---------------------VOID LOOP------------------------------

void loop() {

  if(Serial.available()){
    lcd.clear(); //Borramos la pantalla
    lcd.setCursor(0, 0); //Situamos el cursor en la primera linea
    lcd.print("LINEA SUPERIOR"); //Escribe el texto
    delay(100);
    lcd.setCursor(0, 1); //Nos movemos a la linea inferior 

        while(Serial.available() > 0){
          lcd.write(Serial.read()); //Se imprime en la linea inferior
          }
      }
}

