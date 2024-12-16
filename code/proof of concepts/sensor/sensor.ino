int sensorValue1;
int sensorValue2;
int sensorValue3;
int sensorValue4;
int sensorValue5;
int sensorValue6;

const int sensorPin1 = A0;
const int sensorPin2 = A1;
const int sensorPin3 = A2;
const int sensorPin4 = A3;
const int sensorPin5 = A4;
const int sensorPin6 = A5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue1 = map(analogRead(sensorPin1), 0, 1023, 1023, 0);
  sensorValue2 = map(analogRead(sensorPin2), 0, 1023, 1023, 0);
  sensorValue3 = map(analogRead(sensorPin3), 0, 1023, 1023, 0);
  sensorValue4 = map(analogRead(sensorPin4), 0, 1023, 1023, 0);
  sensorValue5 = map(analogRead(sensorPin5), 0, 1023, 1023, 0);
  sensorValue6 = map(analogRead(sensorPin6), 0, 1023, 1023, 0);

  Serial.print("Sensorwaarden: ");
  Serial.print(sensorValue1); Serial.print(" ");
  Serial.print(sensorValue2); Serial.print(" ");
  Serial.print(sensorValue3); Serial.print(" ");
  Serial.print(sensorValue4); Serial.print(" ");
  Serial.print(sensorValue5); Serial.print(" ");
  Serial.print(sensorValue6); Serial.println();

  delay(100);
}