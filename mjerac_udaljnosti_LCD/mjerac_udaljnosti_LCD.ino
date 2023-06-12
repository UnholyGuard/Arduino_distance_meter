#include <LiquidCrystal.h>
const int trig = 6;
const int echo = 7;
long trajanje;
int udaljenost, bt = 1, bt_old;
const int rs = 5, en = 4, d4 = 3, d5 = 2, d6 = 13 , d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
void loop() {
  if (digitalRead(8) == HIGH)    bt = 1;
  if (digitalRead(9) == HIGH)    bt = 2;
  if (digitalRead(10) == HIGH)   bt = 3;
  if (digitalRead(11) == HIGH)   bt = 4;
  if (bt != bt_old) lcd.clear();
  switch (bt) {
    case 1:
      ispis_izbornik();
      break;
    case 2:
      mjerenje();
      ispis_mm();
      break;
    case 3:
      mjerenje();
      ispis_cm();
      break;
    case 4:
      mjerenje();
      ispis_in();
      break;
  }
  bt_old = bt;
}

int mjerenje() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  trajanje = pulseIn(echo, HIGH);
  udaljenost = trajanje * 0.035 / 2;
}
void ispis_izbornik() {
  lcd.setCursor(0, 0);
  lcd.print("1-Izbornik:");
  lcd.setCursor(0, 1);
  lcd.print("2-mm  3-cm  4-in");
  delay(100);
}
void ispis_mm() {
  lcd.setCursor(0, 0);
  lcd.print("Udaljenost:");
  lcd.setCursor(0, 1);
  lcd.print(udaljenost * 10); lcd.print("mm ");
  delay(100);
}
void ispis_cm() {
  lcd.setCursor(0, 0);
  lcd.print("Udaljenost:");
  lcd.setCursor(0, 1);
  lcd.print(udaljenost); lcd.print("cm ");
  delay(100);
}
void ispis_in() {
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print(udaljenost / 2.54); lcd.print("in ");
  delay(100);
}
