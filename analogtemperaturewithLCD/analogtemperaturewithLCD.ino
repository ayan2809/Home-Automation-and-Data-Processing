#include <LiquidCrystal.h>

int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
int buzzer=13;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
Serial.begin(9600);
}

void loop() {

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  //T = (T * 9.0)/ 5.0 + 32.0; 

  if(T <24){
    noTone(buzzer);
  lcd.print("Temp = ");
  lcd.print(T);   
  lcd.print(" C");
  }
  else
  {
    tone(buzzer,450);
    lcd.print("High Temperature");
    //noTone(buzzer);
  }
  delay(500);            
  lcd.clear();
}
