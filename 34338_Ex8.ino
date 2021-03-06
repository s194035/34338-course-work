#define IOpin1 7
#define IOpin2 6
#define IOpin3 5

int analogPin = A0;
int val = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  val = analogRead(analogPin);
  float voltage_read = (val - 0)*(3.3-0)/(1023-0)+0; //Map the measured voltage to a value between 3.3V and 0V
  Serial.println(voltage_read); //Print the voltage measured
  
  int RGB_color = map(val, 0, 1023, 0, 255); //Map the voltage to a number between 0-255
  analogWrite(IOpin1, 255);
  analogWrite(IOpin2, abs(RGB_color-255));
  analogWrite(IOpin3, abs(RGB_color-255));
}

//////////Questions//////////
//How is the analog value represented by the MCU?
//Answer: The analog value read with analogRead is a number between 0-1024 because the Arduino uses a 10-bit (2^10) A/D converter. This leaves about 0.003V per unit which is pretty good precision for what we are using it for.

//What is maximum voltage that can be read on A0?
//Answer: The maximum voltage that the ARDUINO can be read is 5V. 
