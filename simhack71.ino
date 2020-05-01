#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
const int slide1= 9;
const int slide2= 8;
const int but3=12;
const int dotButton=10;
const int dashButton=11;
String code = "";
int len = 0;
char ch;
char new_char;
int unit_delay = 250;
int flag1=0,flag2=0,flag3=0;

#define SIZE 26
String morseCode="";
String text="";
int characterAscii=0;
int startPos=0, endPos=0;
int startPos1=0, endPos1=0;
String characterCode="";
int dashButtonState=LOW;
int dotButtonState=LOW;

String letters[SIZE]={

// A to I
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
// J to R 
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
// S to Z
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." 
};

 
 void setup() {
  Serial.begin(9600);
    pinMode(slide1, INPUT_PULLUP);
      pinMode(slide2, INPUT_PULLUP);
  pinMode(dotButton, INPUT);
pinMode(dashButton, INPUT);
       pinMode(but3, INPUT_PULLUP);
 // Serial.println("I am ready...");
  lcd.begin(16, 2);
}
void bin_decode(int a)
{  
  lcd.print("BIN DECODE");
    int sum =0,c=0;
    while(a)
    {
        sum += ((a%10)*pow(2,c++));
        a/=10;
    }
    //print sum
     lcd.clear();
  lcd.print("BIN DECODE");
  lcd.setCursor(0,1);
  lcd.print(sum+1);
    delay(1000);
      lcd.clear();
  lcd.print("BIN DECODE");
}

void bin_encode(int a)
{
  lcd.print("BIN ENCODE");
    int sum=0,c=1;
    while(a)
    {
        sum+= (a%2)*c;
        c=c*10;
        a=a/2;
    }
    //print sum
         lcd.clear();
  lcd.print("BIN ENCODE");
  lcd.setCursor(0,1);
  lcd.print(sum);
    delay(1000);
      lcd.clear();
  lcd.print("BIN ENCODE");
    
}

  void binarycoding()
  { 
     if(digitalRead(slide2)==LOW)
   {  lcd.setCursor(0,0);
     lcd.print("BIN ENCODE");
    }
    else
   {lcd.setCursor(0,0);
     lcd.print("BIN DECODE");
     }

     
   while (Serial.available())
  {
    int a = Serial.parseInt(); 
    Serial.println(a);
    if(digitalRead(slide2)==HIGH)
   { delay(1000);
    bin_decode( a);
    //Serial.println("Encode");
    }
    else
   {delay(1000);
    bin_encode( a);
    //Serial.println("Decode");
     }
    }
  }

    
 void  morsecodeing()
 {
    if(digitalRead(slide2)==HIGH)
 { delay(1000);
 morseencodeing();
 // Serial.println("Encode");
 }
  else
 {delay(1000);
  morsedecodeing();
  // Serial.println("Decode");
     }
 }

 void morsedecodeing()
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MC DECODE");
    lcd.setCursor(0,1);
     dotButtonState=digitalRead(dotButton);
     dashButtonState=digitalRead(dashButton);
     while((digitalRead(but3)== HIGH)!=0)
 { 
  if(digitalRead(dashButton)== LOW)
 
  {
    morseCode.concat("-"); // Storing code in variable morseCode with the help of concatenation function
    Serial.println("-");
     lcd.print("-");
    
    delay(200);
  }
  else if(digitalRead(dotButton)== LOW)
  {
   morseCode.concat(".");
   lcd.print(".");
   Serial.println(".");
   delay(200);
      }
  
}
 if(digitalRead(but3) == LOW)
  {
    static String morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                             "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
                             ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "!"
                            };
    Serial.print("\n");
        int i = 0;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("MC DECODE");
        lcd.setCursor(0,1);
         Serial.print("\nYour Morse code Translation :  ");
         
        while (morse[i] != "!")  
  {
    if (morse[i] == morseCode)
    {
        lcd.print(char('A' + i));
        Serial.print(" ");
      Serial.println(char('A' + i));
      Serial.print(" ");
      break;
    }
    i++;
  }
  if (morse[i] == "!")
  {
    Serial.println("");
    Serial.println("unknown");
    lcd.print("unknown");
  }
 
  morseCode = "";
} 
       
  }

  
  
  void morseencodeing()
  { lcd.setCursor(0,0);
    lcd.print("MC ENCODE");
 
  while (Serial.available())
  { lcd.setCursor(0,0);
    lcd.print("MC ENCODE");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MC ENCODE");
    code = Serial.readString();
    Serial.print(code);
    Serial.print(" = ");
    lcd.setCursor(0, 1);
    String2Morse();
    Serial.println("");
  }
  delay(1000);
}



void dot()
{
  Serial.print(".");

  lcd.print(".");
  }
 
void dash()
{
  Serial.print("-");
   
  lcd.print("-");
}
 
void A()
{
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void B()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void C()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void D()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void E()
{
  dot();
  delay(unit_delay);
}
void f()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void G()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void H()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void I()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void J()
{
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void K()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void L()
{
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void M()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void N()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void O()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void P()
{
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
}
void Q()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void R()
{
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void S()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void T()
{
  dash();
  delay(unit_delay);
}
void U()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void V()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void W()
{
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void X()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void Y()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void Z()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void one()
{
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void two()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void three()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void four()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void five()
{
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void six()
{
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void seven()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void eight()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void nine()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dot();
  delay(unit_delay);
}
void zero()
{
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
  dash();
  delay(unit_delay);
}
void morse()
{
  if (ch == 'A' || ch == 'a')
  {
    A();
    Serial.print(" ");
  }
  else if (ch == 'B' || ch == 'b')
  {
    B();
    Serial.print(" ");
  }
  else if (ch == 'C' || ch == 'c')
  {
    C();
    Serial.print(" ");
  }
  else if (ch == 'D' || ch == 'd')
  {
    D();
    Serial.print(" ");
  }
  else if (ch == 'E' || ch == 'e')
  {
    E();
    Serial.print(" ");
  }
  else if (ch == 'f' || ch == 'f')
  {
    f();
    Serial.print(" ");
  }
  else if (ch == 'G' || ch == 'g')
  {
    G();
    Serial.print(" ");
  }
  else if (ch == 'H' || ch == 'h')
  {
    H();
    Serial.print(" ");
  }
  else if (ch == 'I' || ch == 'i')
  {
    I();
    Serial.print(" ");
  }
  else if (ch == 'J' || ch == 'j')
  {
    J();
    Serial.print(" ");
  }
  else if (ch == 'K' || ch == 'k')
  {
    K();
    Serial.print(" ");
  }
  else if (ch == 'L' || ch == 'l')
  {
    L();
    Serial.print(" ");
  }
  else if (ch == 'M' || ch == 'm')
  {
    M();
    Serial.print(" ");
  }
  else if (ch == 'N' || ch == 'n')
  {
    N();
    Serial.print(" ");
  }
  else if (ch == 'O' || ch == 'o')
  {
    O();
    Serial.print(" ");
  }
  else if (ch == 'P' || ch == 'p')
  {
    P();
    Serial.print(" ");
  }
  else if (ch == 'Q' || ch == 'q')
  {
    Q();
    Serial.print(" ");
  }
  else if (ch == 'R' || ch == 'r')
  {
    R();
    Serial.print(" ");
  }
  else if (ch == 'S' || ch == 's')
  {
    S();
    Serial.print(" ");
  }
  else if (ch == 'T' || ch == 't')
  {
    T();
    Serial.print(" ");
  }
  else if (ch == 'U' || ch == 'u')
  {
    U();
    Serial.print(" ");
  }
  else if (ch == 'V' || ch == 'v')
  {
    V();
    Serial.print(" ");
  }
  else if (ch == 'W' || ch == 'w')
  {
    W();
    Serial.print(" ");
  }
  else if (ch == 'X' || ch == 'x')
  {
    X();
    Serial.print(" ");
  }
  else if (ch == 'Y' || ch == 'y')
  {
    Y();
    Serial.print(" ");
  }
  else if (ch == 'Z' || ch == 'z')
  {
    Z();
    Serial.print(" ");
  }
  else if (ch == '0')
  {
    zero();
    Serial.print(" ");
  }
  else if (ch == '1')
  {
    one();
    Serial.print(" ");
  }
  else if (ch == '2')
  {
    two();
    Serial.print(" ");
  }
  else if (ch == '3')
  {
    three();
    Serial.print(" ");
  }
  else if (ch == '4')
  {
    four();
    Serial.print(" ");
  }
  else if (ch == '5')
  {
    five();
    Serial.print(" ");
  }
  else if (ch == '6')
  {
    six();
    Serial.print(" ");
  }
  else if (ch == '7')
  {
    seven();
    Serial.print(" ");
  }
  else if (ch == '8')
  {
    eight();
    Serial.print(" ");
  }
  else if (ch == '9')
  {
    nine();
    Serial.print(" ");
  }
  else if(ch == ' ')
  {
    delay(unit_delay*7);
    Serial.print("/ ");
  }
  else
    Serial.println("Unknown");
}
 
void String2Morse()
{
  len = code.length();
  for (int i = 0; i < len; i++)
  {
    ch = code.charAt(i);
    morse();
  }
}

 

char convertIntoText(String characterCode)
{
  characterAscii=65;
  
  for(int index=0; index<SIZE; index++)
  {
    if(characterCode == letters[index])
    {
      return characterAscii;   
    }
    characterAscii++;  
  }

}

void extractLetters(String words)
{
        words.concat('@'); // Placeing @ at the end of word to simplify further processing

        endPos=words.indexOf('@');

        
        //Loop to extracting single character morse Code from string of word        
        while( endPos<words.length() )
       {
         characterCode=words.substring(startPos, endPos);
         
         //Now CharacterCode will now convert in text

         text.concat(convertIntoText(characterCode));
         
         startPos=endPos+1;
         characterCode="";
         
          // if condition is just to terminate loop when our extracting single character code is complete thats all
         if(startPos == words.length() )
         {
           break;
         }
         
         endPos=words.indexOf('@', startPos);   
       
       }
                
        
        Serial.print(text);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("MC DECODE");
        lcd.setCursor(0,1);
        lcd.print(text);
        Serial.print(" ");
        startPos=0;
        endPos=0;
        text="";    
  
}

void loop() {
  if(digitalRead(slide1)==HIGH)
  {morsecodeing();
  
   //Serial.println("Morse");
  }
  else
  {
  binarycoding();
  
   //Serial.println("binary");
  }
  
}
