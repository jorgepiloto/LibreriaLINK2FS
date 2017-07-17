/*
Ejemplo creado por Jorge Martínez, autor de Ingeniero de Aviones
*/

#include <Arduino.h> //Esta librería no afecta en nada al código, pero facilita su desarrollo en otros lenguajes

int t = 250; //La variable que controla el tiempo de los delays

int pot1 = 1; //Hemos conectado el pot1 al pin 1 analógico. MODIFICA EL NUMERO "1"  SEGÚN TU PIN DE CONEXIÓN
int valPot1 = 0; //Aquí alamacenaremos su valor


void setup(){

Serial.begin(115200); //Iniciamos la comunicación serial
pinMode(pot1, INPUT); //Indicamos que el pin de pot1 actúa como un IMPUT

}

void loop(){

  valPot1 = analogRead(pot1); //Leemos el valor de pot1 de forma analógica

  //Dado que arduino simepre lee las inputs analógicas con valores entre 0 y 1023
  //es necesario transformar el valor al rango que nos interesa, al de porcentajes
  //Para ello empleamos la funcion "map"

  valPot1 = map(valPot1, 0, 1023, 0, 100); //Mapeamos valPot1

  //Utilizaremos el ejemplo de la palanca de gases para el motor 1
  //LINK2FS nos pide enviar la instrucción C56 seguida de tres
  //números que indiquen el valor en porcentaje de la potencia
  //deseada en dicho motor

  //Si valPot1 < 10, sólo tendrá una cifra. Por ello mandamos C5600 y luego su valor
  if(valPot1 < 10){Serial.print("C5600"); Serial.println(valPot1);}

  //Si valpot1 está entre 10 y 99 inclusive, tendrá dos cifras
  if(valPot1 >= 10 || valPot1 <=   99){Serial.print("C560"); Serial.println(valPot1);}

  //Si valPot1 vale 100, está al máximo y podemos mandar la instrucción completa
  if(valPot1 == 100){Serial.println("C56100");}

}
