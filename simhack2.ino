
#include <Servo.h>
Servo servo; 
int red= 11;
int green = 9;
int val = 0;

void setup() { 
    pinMode(red,OUTPUT);
    pinMode(green,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(2,INPUT);
  // put your setup code here, to run once:
 Serial.begin(9600);
 servo.attach(4);
 servo.write(0);
 RGB_color(255, 0); // Red
}

void RGB_color(int greenvalue, int redvalue)
 {
  analogWrite(red, redvalue);
  analogWrite(green, greenvalue);
}

void loop() {
  val = digitalRead(2);
  if (val == HIGH)
  {  
  RGB_color(255, 0); // Red
  tone(12, 1000);
  servo.write(180);             
   delay(15);
  delay(5000); 
  
  }
   
    else
    {
      RGB_color(0, 255);
      noTone(12);
      servo.write(0);
      delay(15);
  delay(1000); 
    }
  // put your main code here, to run repeatedly:

}