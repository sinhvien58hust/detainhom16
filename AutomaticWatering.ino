#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int doam = 0;
int doamyeucau = 50;
int dentadoamyeucau = 0;
int set = 1;

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  pinMode(4, INPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(9, INPUT);
  pinMode(10, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print(" HE THONG TUOI ");
  lcd.setCursor(0, 1);
  lcd.print(" CHON SET DE CD");
  delay(3000);
  lcd.clear();
}

void loop() {
  if (digitalRead(4) == 1) set = 1;
  if (digitalRead(9) == 1) set = 2;
  if (set == 1)
  {
    doam = analogRead(A0);
    doam = map(doam, 1023, 700, 0, 100);
    dentadoamyeucau = doamyeucau - doam;
    lcd.setCursor(0, 0);
    lcd.print("soil: ");
    lcd.print(doam);
    lcd.print("%		");
    lcd.setCursor(0, 1);
    lcd.print("SET DO AM: ");
    lcd.print(doamyeucau);
    lcd.print("%	");
    if (dentadoamyeucau < 1) digitalWrite(10, HIGH);
    if (dentadoamyeucau > -1) digitalWrite(10, LOW);
    delay(200);
  }
  if (set == 2)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("H yeu cau:");
    lcd.setCursor(10, 1);
    lcd.print(doamyeucau);
    if (digitalRead(6) == 0) {
      delay(150);
      if (digitalRead(6) == 0) doamyeucau = doamyeucau - 1;
    }
    if (digitalRead(7) == 0) {
      delay(150);
      if (digitalRead(7) == 0) doamyeucau = doamyeucau + 1;
    }
  }
}
