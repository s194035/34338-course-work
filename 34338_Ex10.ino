#define IOpin1 7
#define IOpin2 6
#define IOpin3 5

int analogPin = A0;

void setup() {
  Serial.begin(115200);
  pinMode(IOpin1, OUTPUT);
  pinMode(IOpin2, OUTPUT);
  pinMode(IOpin3, OUTPUT);

}

void loop() {

  float voltage_meas = analogRead(analogPin); //Measuring the voltage and using A/D converter
  double voltage_actual = map(voltage_meas, 0, 1023, 0, 5); //Mapping the voltage to actual values
  Serial.print("Measured voltage: ");
  Serial.println(voltage_meas);


  Serial.print("Actual voltage: ");
  Serial.println(voltage_actual);


  int temp = map(voltage_actual, 0, 5, 18, 30); //Mapping voltage to a corresponding temperature
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("°");
  Serial.println("");

  switch (temp) {
    case 18 ... 23:
      digitalWrite(IOpin1, LOW);
      digitalWrite(IOpin2, LOW);
      digitalWrite(IOpin3, HIGH);
      break;

    case 24 ... 27:
      digitalWrite(IOpin1, LOW);
      digitalWrite(IOpin2, HIGH);
      digitalWrite(IOpin3, LOW);
      break;


    case 28 ... 30:
      digitalWrite(IOpin1, HIGH);
      digitalWrite(IOpin2, LOW);
      digitalWrite(IOpin3, LOW);
      break;

    default:
      digitalWrite(IOpin1, LOW);
      digitalWrite(IOpin2, LOW);
      digitalWrite(IOpin3, LOW);
      break;
  }
}

//////////Questions///////////