#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

uint8_t bell[8]  = {0x4, 0xe, 0xe,0xe, 0x1f, 0x0, 0x4};
uint8_t note[8]  = {0x2, 0x3, 0x2, 0xe, 0x1e, 0xc, 0x0};
uint8_t reloj[8] = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};
uint8_t heart[8] = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0};
uint8_t duck[8]  = {0x0, 0xc, 0x1d, 0xf, 0xf, 0x6, 0x0};
uint8_t check[8] = {0x0, 0x1, 0x3, 0x16, 0x1c, 0x8, 0x0};
uint8_t cross[8] = {0x0, 0x1b, 0xe, 0x4, 0xe, 0x1b, 0x0};
uint8_t retarrow[8] = {0x1, 0x1, 0x5, 0x9, 0x1f, 0x8, 0x4};

void setup()
{
  lcd.init();
  lcd.createChar(0, bell);
  lcd.createChar(1, note);
  lcd.createChar(2, reloj);
  lcd.createChar(3, heart);
  lcd.createChar(4, duck);
  lcd.createChar(5, check);
  lcd.createChar(6, cross);
  lcd.createChar(7, retarrow);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello world");
  lcd.write(1);
  lcd.setCursor(0, 1);
  lcd.print("I'm coding A.");
  delay(2000);
  lcd.clear();
}

void intercambiarCeros(int letraByte, int valorUnooCero) {
  for (int i = 0 ; i < 16 ; i++)
  {
    if (i % 2 == valorUnooCero)
    {
      lcd.setCursor(i, 0);
      lcd.write(letraByte);
      delay(250);
    } else if (i % 2 != valorUnooCero)
    {
      lcd.setCursor(i, 1);
      lcd.write(letraByte);
      delay(250);
    }
  }
}

void loop()
{
  lcd.init();
  while (1)
  {
    for (int i = 0 ; i < 8 ; i++)
    {
      lcd.clear();
      intercambiarCeros(i, i % 2);
    }
  }
}
