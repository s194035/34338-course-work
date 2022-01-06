int analogPin = A0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  float voltage_meas = analogRead(analogPin); //Measuring the voltage and using A/D converter
  double voltage_actual = map(voltage_meas, 0, 1023, 0, 5); //Mapping the voltage to actual values
  Serial.print("Measured voltage: ");
  Serial.println(voltage_meas);


  Serial.print("Actual voltage: ");
  Serial.println(voltage_actual);


  double temp = map(voltage_actual, 0, 5, 18, 30); //Mapping voltage to a corresponding temperature
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("°");
  Serial.println("");
  delay(5000);
}

//////////Questions//////////
//What is wrong with this conversion from analogRead to voltage?
/*
 * int in = analogRead(A0);
 * double vol = (in / 1024) * 5000
 */
 //Answer: First of all, you should divide with 1023, not 1024 because the highest number to A/D can output is 1023. Second of all, 5000 should be a 5 instead, because the maximum output voltage is 5 volts.

 //What would the output of this code be?
 /*
  char c;
  for(int i = 0; i<4; i++){
      c = '0'+i*2;
      Serial.print(c);
      Serial.write(176);
  }
  */
//Answer: This code prints out 0⸮2⸮4⸮6⸮. It first prints out the value of c (i*2) and then it prints out the corresponding character for the ascii-code 176. But that belongs in the extended ascii library, so the monitor prints out garbage instead.

//What is the difference between print() and write()
//Answer: print() prints out the actual characters as human readable ASCII text. write() writes a binary string to the serial port and it then gets converted from ASCII to readable characters. For example Serial.write(97); will print out 'a' in the terminal.