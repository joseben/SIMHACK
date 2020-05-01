int and1 = 13; 
int and2 = 12;
int and3 = 11;
int LED1 = 2; 
int or1 = 10; 
int orb = 9; 
int or3 = 8; 
int LED2 = 3; 
int nand1 = 7; 
int nand2 = 6; 
int nand3 = 5; 
int LED3 = 4; 


void setup() {
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
  
pinMode(and1, INPUT_PULLUP);
pinMode(and2, INPUT_PULLUP);
pinMode(and3, INPUT_PULLUP);

pinMode(or1, INPUT_PULLUP);
pinMode(orb, INPUT_PULLUP);
pinMode(or3, INPUT_PULLUP);

pinMode(nand1, INPUT_PULLUP);
pinMode(nand2, INPUT_PULLUP);
pinMode(nand3, INPUT_PULLUP);
}

bool AND(bool a, bool b,bool c)  { return ((a&&b)&&c); }
bool OR(bool a, bool b, bool c)   { return a||b||c; }
bool NAND(bool a, bool b, bool c) { return !((a&&b)&&c); }

bool (*gate1)(bool a, bool b, bool c) = AND;
bool (*gate2)(bool a, bool b, bool c) = OR;
bool (*gate3)(bool a, bool b, bool c) = NAND;

void andgate()
{
  gate1 = AND;
  bool a = !digitalRead(and1);  
  bool b = !digitalRead(and2);
  bool c = !digitalRead(and3);
  digitalWrite(LED1, gate1(a,b,c));
}

void orgate()
{
  gate2 = OR;
  bool a = !digitalRead(or1);  
  bool b = !digitalRead(orb);
  bool c = !digitalRead(or3);
  digitalWrite(LED2, gate2(a,b,c));
}
void nandgate()
{
  gate3 = NAND;
  bool a = !digitalRead(nand1);  
  bool b = !digitalRead(nand2);
  bool c = !digitalRead(nand3);
  digitalWrite(LED3, gate3(a,b,c));
}

void loop(){
  andgate();
  orgate();
  nandgate();
}
