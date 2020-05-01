
//Declaration of Arduino pins used as HCF4511 inputs
const int A=10;
const int B=11;
const int C=12;
const int D=13;
const int p=6;
const int q=7;
const int r=8;
const int s=9;
const int j=2;
const int k=3;
const int l=4;
const int m=5;
void setup() {
  pinMode(A1, INPUT);
  pinMode(A, OUTPUT); 
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT); 
  pinMode(A2, INPUT);
  pinMode(p, OUTPUT); 
  pinMode(q, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(s, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(j, OUTPUT); 
  pinMode(k, OUTPUT);
  pinMode(l, OUTPUT);
  pinMode(m, OUTPUT);
  Serial.begin(9600);
}

int count = 0; //the variable used to show the number

void seg1()
{
    if (count == 0) //write 0000
  {
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);

    }
    
    if (count == 1) //write 0001
  {
            digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      Serial.println(count);
    }
    
    if (count == 2) //write 0010
  {
     digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      Serial.println(count);
    }
    
    if (count == 3) //write 0011
  {
            digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);

      Serial.println(count);
    }
    
    if (count == 4) //write 0100
  {
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      Serial.println(count);
    }
    
    if (count == 5) //write 0101
  {
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      Serial.println(count);
    }
    
    if (count == 6) //write 0110
  {
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    }
    
    if (count == 7) //write 0111
  {
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
    }
    
    if (count == 8) //write 1000
  {
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
    }
    
    if (count == 9) //write 1001
  {
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
    } 
}

//********************************************************************************************

void seg2()
{
    if (count == 0) //write 0000
  {
      digitalWrite(p, LOW);
      digitalWrite(q, LOW);
      digitalWrite(r, LOW);
      digitalWrite(s, LOW);

    }
    
    if (count == 1) //write 0001
  {
            digitalWrite(p, HIGH);
      digitalWrite(q, LOW);
      digitalWrite(r, LOW);
      digitalWrite(s, LOW);
      Serial.println(count);
    }
    
    if (count == 2) //write 0010
  {
     digitalWrite(p, LOW);
      digitalWrite(q, HIGH);
      digitalWrite(r, LOW);
      digitalWrite(s, LOW);
      Serial.println(count);
    }
    
    if (count == 3) //write 0011
  {
            digitalWrite(p, HIGH);
      digitalWrite(q, HIGH);
      digitalWrite(r, LOW);
      digitalWrite(s, LOW);

      Serial.println(count);
    }
    
    if (count == 4) //write 0100
  {
      digitalWrite(p, LOW);
      digitalWrite(q, LOW);
      digitalWrite(r, HIGH);
      digitalWrite(s, LOW);
      Serial.println(count);
    }
    
    if (count == 5) //write 0101
  {
      digitalWrite(p, HIGH);
      digitalWrite(q, LOW);
      digitalWrite(r, HIGH);
      digitalWrite(s, LOW);
      Serial.println(count);
    }
    
    if (count == 6) //write 0110
  {
      digitalWrite(p, LOW);
      digitalWrite(q, HIGH);
      digitalWrite(r, HIGH);
      digitalWrite(s, LOW);
    }
    
    if (count == 7) //write 0111
  {
      digitalWrite(p, HIGH);
      digitalWrite(q, HIGH);
      digitalWrite(r, HIGH);
      digitalWrite(s, LOW);
    }
    
    if (count == 8) //write 1000
  {
      digitalWrite(p, LOW);
      digitalWrite(q, LOW);
      digitalWrite(r, LOW);
      digitalWrite(s, HIGH);
    }
    
    if (count == 9) //write 1001
  {
      digitalWrite(p, HIGH);
      digitalWrite(q, LOW);
      digitalWrite(r, LOW);
      digitalWrite(s, HIGH);
    } 
}
//********************************************************************************************
void seg3()
{
    if (count == 0) //write 0000
  {
      digitalWrite(j, LOW);
      digitalWrite(k, LOW);
      digitalWrite(l, LOW);
      digitalWrite(m, LOW);

    }
    
    if (count == 1) //write 0001
  {
            digitalWrite(j, HIGH);
      digitalWrite(k, LOW);
      digitalWrite(l, LOW);
      digitalWrite(m, LOW);
      Serial.println(count);
    }
    
    if (count == 2) //write 0010
  {
     digitalWrite(j, LOW);
      digitalWrite(k, HIGH);
      digitalWrite(l, LOW);
      digitalWrite(m, LOW);
      Serial.println(count);
    }
    
    if (count == 3) //write 0011
  {
            digitalWrite(j, HIGH);
      digitalWrite(k, HIGH);
      digitalWrite(l, LOW);
      digitalWrite(m, LOW);

      Serial.println(count);
    }
    
    if (count == 4) //write 0100
  {
      digitalWrite(j, LOW);
      digitalWrite(k, LOW);
      digitalWrite(l, HIGH);
      digitalWrite(m, LOW);
      Serial.println(count);
    }
    
    if (count == 5) //write 0101
  {
      digitalWrite(j, HIGH);
      digitalWrite(k, LOW);
      digitalWrite(l, HIGH);
      digitalWrite(m, LOW);
      Serial.println(count);
    }
    
    if (count == 6) //write 0110
  {
      digitalWrite(j, LOW);
      digitalWrite(k, HIGH);
      digitalWrite(l, HIGH);
      digitalWrite(m, LOW);
    }
    
    if (count == 7) //write 0111
  {
      digitalWrite(j, HIGH);
      digitalWrite(k, HIGH);
      digitalWrite(l, HIGH);
      digitalWrite(m, LOW);
    }
    
    if (count == 8) //write 1000
  {
      digitalWrite(j, LOW);
      digitalWrite(k, LOW);
      digitalWrite(l, LOW);
      digitalWrite(m, HIGH);
    }
    
    if (count == 9) //write 1001
  {
      digitalWrite(j, HIGH);
      digitalWrite(k, LOW);
      digitalWrite(l, LOW);
      digitalWrite(m, HIGH);
    } 
}


void loop() {
  if (digitalRead(A1) == LOW) //if button is pressed
    {
    count++; 
    Serial.println(count);
    delay(200); 
    if (count == 10) 
      count = 0;
    seg1(); 
     delay(200);
    }
  if (digitalRead(A2) == LOW) //if button is pressed
    {
    count++; 
    Serial.println(count);
    delay(200);
    if (count == 10) 
      count = 0;
    seg2();
    delay(200);
    }
   if (digitalRead(A3) == LOW) //if button is pressed
    {
    count++; 
    Serial.println(count);
    delay(200); 
    if (count == 10) 
      count = 0;
    seg3();
     delay(200);
    }
    
  if (count == 10)
    count = 0;
  
}
