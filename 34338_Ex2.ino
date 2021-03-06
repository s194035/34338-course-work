#define pinIO1  7
#define pinIO2  6
#define pinIO3  5
#define timeUnit  500

void setup() {
  Serial.begin(115200);
  pinMode(pinIO1, OUTPUT);
  pinMode(pinIO2, OUTPUT);
  pinMode(pinIO3, OUTPUT);

}

void loop() {
  binaryCounter();

}

void RedYellow(){
  Serial.println("STOP");
  digitalWrite(pinIO1, HIGH);
  delay(4*timeUnit);
  digitalWrite(pinIO2, HIGH);
  Serial.println("PREPARE YOUR ENGINES");
  delay(2*timeUnit);
}

void YellowGreen(){
  digitalWrite(pinIO1, LOW);
  digitalWrite(pinIO2, LOW);
  digitalWrite(pinIO3, HIGH);
  Serial.println("GO");
  delay(4*timeUnit);
}

void GreenYellow(){
  digitalWrite(pinIO3, LOW);
  digitalWrite(pinIO2, HIGH);
  Serial.println("SLOW DOWN");
  delay(2*timeUnit);
}

void YellowRed(){
  digitalWrite(pinIO2, LOW);
  digitalWrite(pinIO1, HIGH);
}

void binaryCounter(){
  int count = 0;
  digitalWrite(pinIO1, LOW);
  digitalWrite(pinIO2, LOW);
  digitalWrite(pinIO3, LOW);
  while(true){
  if(count > 7){count = 0;}
  if(count % 2 > 0){digitalWrite(pinIO3, HIGH);} else {digitalWrite(pinIO3, LOW);}
  if(count % 4 > 1){digitalWrite(pinIO2, HIGH);} else {digitalWrite(pinIO2, LOW);}
  if(count % 8 > 3){digitalWrite(pinIO1, HIGH);} else {digitalWrite(pinIO1, LOW);}
  Serial.println(count);
  count++;
  delay(timeUnit*2);
    }
  }


//////////Questtions//////////
//You should be used to the normal arithmetic operators + - * / , but do you know this operator: %? What is 42 % 5?
//Answer: % is the modulo operator and it gives the remainder of a division between two numbers. 42/5 = 7 (remainder 2) -> 42 % 5 = 2.

//What can you use the %-operator for in this exercise?
//Answer: You check (like I have done) whether or not an LED should be turned on. For example, the number 6: 6%2 = 0, so LSB = 0. 6%4 = 2, so middle bit = 1. 6%8 = 6, so MSB = 1 -> 6 = 110_BIN

//The LEDs have a forward voltage of 2.1V and should have a forward current of 20mA-25mA. What are the forward current of the LED in your curcuit?
//For a digital HIGH, the Arduino delivers 3.3V. The voltage drop across the LED is 2.1V, and the reamining voltage is dropped across the series resistor, which is 56 ohms. The current is I = (3.3V-2.1V)/(56 ohms) = 21mA
