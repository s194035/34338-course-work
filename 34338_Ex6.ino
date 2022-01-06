#define IOpin1  7
#define IOpin2  6
#define IOpin3  5
#define IOpin4  4
#define IOpin5  3
int incomingByte = 0;

void setup() {
  Serial.begin(115200);
  //Calibrate pins as output
  pinMode(IOpin1, OUTPUT);
  pinMode(IOpin2, OUTPUT);
  pinMode(IOpin3, OUTPUT);
  pinMode(IOpin4, OUTPUT);
  pinMode(IOpin5, OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    char letter = char(incomingByte);

    //Lookup table
    switch (letter) {
      case 'a':
        digitalWrite(IOpin5, HIGH);
        digitalWrite(IOpin4, LOW);
        digitalWrite(IOpin3, LOW);
        digitalWrite(IOpin2, LOW);
        digitalWrite(IOpin1, LOW);
        break;
      case 'b':
        digitalWrite(IOpin5, LOW);
        digitalWrite(IOpin4, HIGH);
        digitalWrite(IOpin3, LOW);
        digitalWrite(IOpin2, LOW);
        digitalWrite(IOpin1, LOW);
        break;

      case 'c':
        digitalWrite(IOpin5, LOW);
        digitalWrite(IOpin4, LOW);
        digitalWrite(IOpin3, HIGH);
        digitalWrite(IOpin2, LOW);
        digitalWrite(IOpin1, LOW);
        break;


      case 'd':
        digitalWrite(IOpin5, LOW);
        digitalWrite(IOpin4, LOW);
        digitalWrite(IOpin3, LOW);
        digitalWrite(IOpin2, HIGH);
        digitalWrite(IOpin1, LOW);
        break;

      case 'e':
        digitalWrite(IOpin5, LOW);
        digitalWrite(IOpin4, LOW);
        digitalWrite(IOpin3, LOW);
        digitalWrite(IOpin2, LOW);
        digitalWrite(IOpin1, HIGH);
        break;

      default:
        digitalWrite(IOpin5, LOW);
        digitalWrite(IOpin4, LOW);
        digitalWrite(IOpin3, LOW);
        digitalWrite(IOpin2, LOW);
        digitalWrite(IOpin1, LOW);
    }
  }
}

//////////Questions//////////
//What is a char? How many bits does one use?
//Answer: A char is a character, such as 'a', 'b' ... A char uses a byte of memory, which is 8 bits. A string is actually just an array of chars.

//What is the resulting character stored in the variable mychar?
/*
   char mychar = '4';
   int val = mychar-'0';
   mychar = char(val+'A*-1);
*/

//Answer: D
//mychar = '4'. val = 52-48 = 4 (in ascii). val+'A*-1 = 4+65-1 = 68 (in ascii). 68 = D (in ascii)
