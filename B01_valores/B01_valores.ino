//------------------------------------------------------------
// Programa: B01_valores.ino (ESP32 + BIOS Shield)
// Autor: Gabriel Bravo Eguren T31A (15-01-2025)
// Descripción: Realiza un programa que muestre en el lcd los números del 1 al 7 separados por
//              comas en la primera línea del LCD cada vez que se pulse P1. Al pulsar P2 se borrará la pantalla.
//              Utiliza un bucle for o while para resolver el ejercicio.
//------------------------------------------------------------

#include <LiquidCrystal_PCF8574.h>

#define P1 27
#define P2 16

bool p1down = false;
bool p2down = false;

LiquidCrystal_PCF8574 lcd(0x3F); 

void setup() 
{
  lcd.begin(16, 2);
  lcd.setBacklight(255);

  pinMode(P1, INPUT_PULLUP);
  pinMode(P2, INPUT_PULLUP);
}

void loop() 
{
  if(!digitalRead(P1)) p1down = true;
  if(!digitalRead(P2)) p2down = true;

  if(digitalRead(P1) && p1down)
  {
    p1down = false;
    String texto = "";

    for(int i = 1; i <= 7; i++)
    {
      texto += i;
      if(i != 7) texto += ",";

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(texto);
      delay(100);
    }
  }

  if(digitalRead(P2) && p2down)
  {
    p2down = false;
    lcd.clear();
  }
}
