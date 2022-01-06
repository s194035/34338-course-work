#define IOpin1 7
#define IOpin2 6
#define IOpin3 5
int fadeValueR = 0;
int fadeValueG = 0;
int fadeValueB = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    String value1 = Serial.readStringUntil(',');
    Serial.read();
    String value2 = Serial.readStringUntil(',');
    Serial.read();
    String value3 = Serial.readStringUntil('\0');

    fadeValueR = value1.toInt();
    fadeValueG = value2.toInt();
    fadeValueB = value3.toInt();

    analogWrite(IOpin1, fadeValueR);
    analogWrite(IOpin2, fadeValueG);
    analogWrite(IOpin3, fadeValueB);
  }

}

//////////Questions//////////
//What is an RGB value? Why does it use the interval 0-255?
//Answer: An RGB value stands for RED-GREEN-BLUE value and it is used a to associate a specific color with a certain combination of the 3 main colors (red green blue).
//The reason every RGB-value goes from 0-255, is because one color is stored using 3 bytes = 24 bits. This equals 8 bits per main color. Thus, each main color have 2^8 = 256 different intensity levels, which is why the values range from 0-255.

//What does the function Serial.parseInt() do ?
//Answer: Serial.parseInt() looks for the next valid integer in the incoming serial. So if you have a some numbers separated by a comma, then parseInt looks only for the integers in the serial code, but ignores the commas.
