#define buttonPin 7
#define ledPin 6
#define RE(signal, state) (state=(state<<1)|(signal&1)&3)==1
int bState = 0;

void setup() {
 pinMode(buttonPin, INPUT_PULLUP);
 pinMode(ledPin, OUTPUT);
 digitalWrite(ledPin, LOW);
}

void loop() {
  //Non-latching
  //bState = digitalRead(buttonPin);
  //if(bState == HIGH){digitalWrite(ledPin, HIGH);}
  //else{digitalWrite(ledPin, LOW);}
  
  //Latching
  if(bState != digitalRead(buttonPin)){
  if(RE(digitalRead(buttonPin), bState)){
    digitalWrite(ledPin, !digitalRead(ledPin));
    } 
  }
}



//////////Questions//////////
//What is the difference between pinMode(PIN, INPUT) and pinMode(PIN, INPUT_PULLUP)?
//Answer: INPUT just means that the pin is used to read a digital signal (LOW or HIGH), instead of supplying a signal. 
//INPUT_PULLUP means that the pin is used to read a digital signal AND pull the default state of the button to HIGH, when the button is not pressed. This is to avoid a floating voltage pin, where the signal will be undeterminable.

//How often do your program check if the button has been pushed? Does this seem reasonable?
//Answer: The programs checks if the button is pushed every iteration of the loop-function. This seems reasonable, as there could constantly be changes in the button state and it is not taxing on the computer at all.

//What is the operator ! used for?
//Answer: This operator is used to invert a boolean variable. For example, if a = true, then !a = false. a != b
