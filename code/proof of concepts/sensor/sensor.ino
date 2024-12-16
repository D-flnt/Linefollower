int sensorValue1;
int sensorValue2;
int sensorValue3;
int sensorValue4;
int sensorValue5;
int sensorValue6;
int sensorValue7;
int sensorValue8;

const int sensorPin1 = 27;
const int sensorPin2 = 26;
const int sensorPin3 = 25;
const int sensorPin4 = 33;
const int sensorPin5 = 32;
const int sensorPin6 = 35;
const int sensorPin7 = 34;
const int sensorPin8 = 39;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue1 = map(analogRead(sensorPin1), 0, 4095, 1023, 0);
  sensorValue2 = map(analogRead(sensorPin2), 0, 4095, 1023, 0);
  sensorValue3 = map(analogRead(sensorPin3), 0, 4095, 1023, 0);
  sensorValue4 = map(analogRead(sensorPin4), 0, 4095, 1023, 0);
  sensorValue5 = map(analogRead(sensorPin5), 0, 4095, 1023, 0);
  sensorValue6 = map(analogRead(sensorPin6), 0, 4095, 1023, 0);
  sensorValue7 = map(analogRead(sensorPin7), 0, 4095, 1023, 0);
  sensorValue8 = map(analogRead(sensorPin8), 0, 4095, 1023, 0);

  Serial.print("Sensorwaarden: ");
  Serial.print(sensorValue1); Serial.print(" ");
  Serial.print(sensorValue2); Serial.print(" ");
  Serial.print(sensorValue3); Serial.print(" ");
  Serial.print(sensorValue4); Serial.print(" ");
  Serial.print(sensorValue5); Serial.print(" ");
  Serial.print(sensorValue6); Serial.print(" ");
  Serial.print(sensorValue7); Serial.print(" ");
  Serial.print(sensorValue8); Serial.println();

  delay(100);
}
