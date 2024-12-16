int motorA_IN1 = 4;
int motorA_IN2 = 2;
int motorB_IN1 = 19;
int motorB_IN2 = 21;

void setup() {
  pinMode(motorA_IN1, OUTPUT);
  pinMode(motorA_IN2, OUTPUT);
  pinMode(motorB_IN1, OUTPUT);
  pinMode(motorB_IN2, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 255; i += 5) {
    analogWrite(motorA_IN1, i);
    analogWrite(motorA_IN2, 0);
    analogWrite(motorB_IN1, i);
    analogWrite(motorB_IN2, 0);
    delay(30);
  }
  for (int i = 255; i >= 0; i -= 5) {
    analogWrite(motorA_IN1, 0);
    analogWrite(motorA_IN2, i);
    analogWrite(motorB_IN1, 0);
    analogWrite(motorB_IN2, i);
    delay(30);
  }
}
