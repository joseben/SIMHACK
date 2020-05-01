#include <LiquidCrystal.h>
#include <IRremote.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int green=9;
const int red=8;

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results; 

void setup() {
  pinMode(green, OUTPUT);
  pinMode(red,OUTPUT);
    Serial.begin(9600);
  irrecv.enableIRIn();
 // irrecv.blink13(true);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
 
}

unsigned int pass[6],c=0;


void getdigits() {
  while(1)
  {if(c==6)return;
  if (irrecv.decode(&results)) //irrecv.decode(&results) returns true if anything is recieved, and stores info in varible results
    { pass[c] = results.value; //Get the value of results as an unsigned int, so we can use switch case
    Serial.println(pass[c++]);
     
    irrecv.resume(); // Receive the next value
  }
  }
}
void loop() { 
  //lcd.clear();
   lcd.print("Enter Password");
  //print enter password on lcd
  c=0;
  getdigits();
  int flag =1;
  if(pass[0]!=2295)flag=0;
  if(pass[1]!=34935)flag=0;
  if(pass[2]!=18615)flag=0;
  if(pass[3]!=10455)flag=0;
  if(pass[4]!=43095)flag=0;
  if(pass[5]!=26775)flag=0;
  if(flag==1)
  {  lcd.clear();
    digitalWrite(green,HIGH);
     delay(1000);
   digitalWrite(green,LOW);
    
     //lcd.print("sucess");//print success and o all
  }
  else
  { lcd.clear();
     lcd.print("Incorrect Password");
    digitalWrite(red,HIGH);
     delay(1000);
   digitalWrite(red,LOW);
    
     //failed
  }
  
}