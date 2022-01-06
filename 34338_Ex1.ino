const int pinNumber = LED_BUILTIN;
const int timeUnit = 300;

void setup(){
  Serial.begin(9600);
  pinMode(pinNumber, OUTPUT);
  digitalWrite(pinNumber, LOW);
}

void loop() {
  if(Serial.available() > 0){
  String text = Serial.readString();
  morse(text);
  Serial.flush();
  }
}

//////////Pseudo Code/////////
/*
 * We need function to convert string into morse code
 * 1. Accept string as parameter and convert into char array
 * 2. Create switch-statement for all alphanumeric keys that converts them into short or long dots
 * 3. Use for loop to go through entire char array
 */

 void morse(String text){
  char charArr[50];
  text.toCharArray(charArr, text.length());

  //Iterating through array
    for(int i = 0; i<=text.length(); i++){
      switch(charArr[i]){

        case 'd':
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit*3);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit);
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit);
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit*3);
          break;

       case 'e':
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit*3);
          break;

          
        case 'f':
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit);
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit);
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit*3);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit);
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit*3);
          break;

       case 'i':
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit);
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit*3);
          break;

       case 'k':
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit*3);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit);
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit);
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit*3);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit*3);
          break;

       case 'r':
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit);
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit*3);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit);
          digitalWrite(pinNumber, HIGH);
          delay(timeUnit);
          digitalWrite(pinNumber, LOW);
          delay(timeUnit*3);
          break;
    }
  }
}

//////////Questions/////////
/*
 * Morse code uses 5 ”bits” for representing numbers 0-9, how many bits are needed if you would use binary?
 * Why is this not possible in Morse Code?
 * Answer: You would need 4 bits in binary to represent numbers 0-9.
 * In Morse code there is no uniqueness in a sequence of dots. You also need a certain time delay between them.
 * 
 * Try setting ledpin = LED_BUILTIN, what happens?
 * Answer: The built-in LED on the Arduino lights up, instead of the external LED connected on the breadboard.
 * 
 * What is the value of a after the loop?
    int a = 1;
    for(int i = 0; i < 5; i++){
    a += a;
    }
   Answer: 32 = 2^5
 */
