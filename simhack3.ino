

#include <LiquidCrystal.h>
const int trigPin = 8;
const int echoPin = 12;
const int buzzer = 13; 
long dur;
float dis;
 int red= 9;
 int green = 11;
 int blue = 10;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);


void setup() {
   pinMode(red,OUTPUT);
   pinMode(green,OUTPUT);
   pinMode(blue,OUTPUT);
   pinMode(buzzer, OUTPUT);
   noTone(buzzer);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   lcd.begin(16, 2);
    lcd.clear();
}
void getping(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  dur = pulseIn(echoPin, HIGH);
  dis= dur*0.034/2;
}

void RGB_color(int greenvalue, int redvalue,int bluevalue)
 {
  analogWrite(red, redvalue);
  analogWrite(green, greenvalue);
    analogWrite(blue,bluevalue);

}
void checkledbuzzer()
{
  if(dis>200)
  {
    RGB_color(255,0, 0);//green
    noTone(buzzer);
  
  }
  else if(dis>=100 &&dis<=200)
  {
    RGB_color(0,0, 255);//blue
    tone(buzzer, 500);
  delay(500);
  noTone(buzzer);
  delay(500);
  }

  else if(dis<100)
  {
    RGB_color(0,255,0);//red
    tone(buzzer, 500);
  delay(250);
  noTone(buzzer);
  delay(250);
  }
  else{
    noTone(buzzer);
  }
}

void loop() {
  noTone(buzzer);
  getping();
  lcd.setCursor(0, 0);
  lcd.print("DISTANCE IN CM");
  lcd.setCursor(0, 1);
  lcd.print(dis);
  checkledbuzzer();
   
}