//------------------------------------------------------------
// Programa: A05_blink_pwm.ino (ESP32 + BIOS Shield)
// Autor: Gabriel Bravo Eguren T31A (13-01-2025)
// Descripción: Realiza un programa que, de forma indefinida, haga que un LED esté al 90%
//              de intensidad y cambie al 10% de intensidad (Como un parpadeo pero sin llegar nunca a apagarse
//              del todo ni a encenderse del todo)
//------------------------------------------------------------

#define D1 12

float bmax;
float bmin; 

void setup() 
{
  pinMode(D1, OUTPUT);

  bmax = 255 * 0.9;
  bmin = 255 * 0.1;
}

void loop() 
{
  analogWrite(D1, bmin);
  delay(250);
  analogWrite(D1, bmax);
  delay(250);
}
