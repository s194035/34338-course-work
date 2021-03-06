int incomingByte = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("I recieved: ");
    Serial.println(char(incomingByte));
  }
}

//////////Questions//////////
//Why are you not receiving what you wrote? (e.g. G becomes 71)
//Answer: This is because the string we receive is changed into ascii-code

//What happens if the serial monitor sends a line ending?
//Answer: If the serial monitor sends a line ending, then every time a string is read by serial.read(), then the monitor will always display "I recieved: 10" in the end, because "10" is the ascii-code for line-feed.

//Try changing the line Serial.print(incomingByte, DEC) to Serial.print((char)incomingByte). What happens? Why?
//Answer: We cast the incomingByte as a char. Thus, even though we declared "incomingByte" as an int, we can read the string from the serial monitor without it being converted into ascii.
