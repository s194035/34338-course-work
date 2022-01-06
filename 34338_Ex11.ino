#include <LiquidCrystal.h>
int analogPin = A0;


// initialize the library by associating any needed LCD interface pin
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(115200);

  lcd.begin(16, 2);
}

void loop() {
  float voltage_meas;
  float voltage_actual;
  int temp[9];
  for (int i = 0; i < 10; i++) {
    voltage_meas = analogRead(analogPin); //Measuring the voltage and using A/D converter
    double voltage_actual = map(voltage_meas, 0, 1023, 0, 5); //Mapping the voltage to actual values
    Serial.print("Measured voltage: ");
    Serial.println(voltage_meas);


    Serial.print("Actual voltage: ");
    Serial.println(voltage_actual);


    temp[i] = map(voltage_actual, 0, 5, 18, 30); //Mapping voltage to a corresponding temperature
    Serial.print("Temperature: ");
    Serial.print(temp[i]);
    Serial.println("°");
  }
  float temp_average = average(temp, 10); //Taking the average of 10 measurements
  Serial.print("Average temperature: ");
  Serial.print(temp_average);
  Serial.print("°");
  Serial.println("");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("AVG TEMP: ");
  lcd.print(temp_average);

  lcd.setCursor(0, 1);
  if (temp_average >= 28) {
    lcd.print("COZY");
  }
  else if (temp_average < 28 && temp_average >= 25) {
    lcd.print("MODERATE");
  }
  else {
    lcd.print("COLD");
  }
  delay(5000);
}

//Average function - taken from the internet
float average (int * array, int len) {
  long sum = 0L ;  // sum will be larger than an item, long for safety.
  for (int i = 0 ; i < len ; i++)
    sum += array [i] ;
  return  ((float) sum) / len ;  // average will be fractional, so float may be appropriate.
}

///////////Questions///////////
//What is I2C?
//Answer: I2C is a serial bus that is used to transport data around the microcontroller. It is used to interface with low-speed peripherals in embedded systems and computer motherboards.

//How can you save computational power when printing on the LCD?
//Answer: When you use lcd.print(<string>) the arduino first has to convert the string into some 2D arrays of 1s and 0s that determine which pixels on the LCD has to be turned on or off.
// But if we ourselves determine which pixels should be on or off (that is, we define the 2D arrays ourselves) then we save a some of the computation that the Arduino has to perform.