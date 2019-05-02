#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

uint8_t loadingOne[8] = {0xc3, 0xe7, 0xbd, 0x81, 0x99, 0xbd, 0xe7, 0xc3};

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.createChar(0, loadingOne);
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Loading");
  lcd.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
