#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

// Motor pinnen
int motorA_IN1 = 4;
int motorA_IN2 = 2;
int motorB_IN1 = 19;
int motorB_IN2 = 21;

// Sensor pinnen (8 sensoren)
const int sensorPins[8] = {27, 26, 25, 33, 32, 35, 34, 39};

// PID parameters
float Kp = 19;
float Ki = 0;
float Kd = 10;
float integral = 0;
float lastError = 0;

// Motor snelheidsinstellingen
int baseSpeed = 95;
int maxSpeed = 140;
int leftMotorSpeed;
int rightMotorSpeed;

// Sensorwaarden en gewichten
int sensorValues[8];
int weights[8] = {-6, -5, -4, -3, 3, 4, 5, 6};

// Calibratie instellingen
int blackValues[8];
int whiteValues[8];

// Status van de robot
volatile bool isRunning = false;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("LineFollower"); // Bluetooth naam
  Serial.println("Bluetooth gestart. Wacht op verbinding...");

  pinMode(motorA_IN1, OUTPUT);
  pinMode(motorA_IN2, OUTPUT);
  pinMode(motorB_IN1, OUTPUT);
  pinMode(motorB_IN2, OUTPUT);

  for (int i = 0; i < 8; i++) {
    pinMode(sensorPins[i], INPUT);
  }
}

void loop() {
  if (SerialBT.available()) {
    String command = SerialBT.readStringUntil('\n');
    processCommand(command);
  }

  if (isRunning) {
    int totalWeight = 0;
    int totalActive = 0;

    for (int i = 0; i < 8; i++) {
      sensorValues[i] = analogRead(sensorPins[i]);
      if (sensorValues[i] > 512) { // Drempelwaarde voor lijn detectie
        totalWeight += weights[i] * sensorValues[i];
        totalActive += sensorValues[i];
      }
    }

    if (totalActive == 0) { // Geen lijn gedetecteerd
      stopMotors();
      isRunning = false; // Stop de robot
      SerialBT.println("Robot stopped: lost the line");
      return;
    }

    int error = totalWeight / totalActive;

    // PID berekening
    integral += error;
    float derivative = error - lastError;
    float pidOutput = Kp * error + Ki * integral + Kd * derivative;

    // Stel motor snelheden in
    leftMotorSpeed = baseSpeed - pidOutput;
    rightMotorSpeed = baseSpeed + pidOutput;

    leftMotorSpeed = constrain(leftMotorSpeed, -maxSpeed, maxSpeed); // Veranderen naar zowel negatieve als positieve waarden
    rightMotorSpeed = constrain(rightMotorSpeed, -maxSpeed, maxSpeed); // Veranderen naar zowel negatieve als positieve waarden

    // Controleer de richting en stel de motoren in
    if (leftMotorSpeed >= 0) {
      analogWrite(motorA_IN1, leftMotorSpeed);  // Motor naar voren
      digitalWrite(motorA_IN2, LOW);  // Motor naar voren
    } else {
      analogWrite(motorA_IN1, -leftMotorSpeed);  // Motor achteruit
      digitalWrite(motorA_IN2, HIGH);  // Motor achteruit
    }

    if (rightMotorSpeed >= 0) {
      analogWrite(motorB_IN1, rightMotorSpeed);  // Motor naar voren
      digitalWrite(motorB_IN2, LOW);  // Motor naar voren
    } else {
      analogWrite(motorB_IN1, -rightMotorSpeed);  // Motor achteruit
      digitalWrite(motorB_IN2, HIGH);  // Motor achteruit
    }

    lastError = error;
    delay(5);
  }
}

void processCommand(String command) {
  command.trim(); // Verwijder onzichtbare karakters
  
  if (command.startsWith("Kp")) {
    Kp = command.substring(2).toFloat();
    SerialBT.println("Kp set to: " + String(Kp));
  } else if (command.startsWith("Ki")) {
    Ki = command.substring(2).toFloat();
    SerialBT.println("Ki set to: " + String(Ki));
  } else if (command.startsWith("Kd")) {
    Kd = command.substring(2).toFloat();
    SerialBT.println("Kd set to: " + String(Kd));
  } else if (command.startsWith("baseSpeed")) {
    baseSpeed = command.substring(9).toInt();
    SerialBT.println("Base Speed set to: " + String(baseSpeed));
  } else if (command.startsWith("maxSpeed")) {
    maxSpeed = command.substring(8).toInt();
    SerialBT.println("Max Speed set to: " + String(maxSpeed));
  } else if (command.equals("getPID")) {
    SerialBT.println("Current PID: Kp=" + String(Kp) + " Ki=" + String(Ki) + " Kd=" + String(Kd));
  } else if (command.equals("getSpeed")) {
    SerialBT.println("Current Speeds: Base=" + String(baseSpeed) + " Max=" + String(maxSpeed));
  } else if (command.equals("start")) {
    isRunning = true;
    SerialBT.println("Robot started");
  } else if (command.equals("stop")) {
    isRunning = false;
    stopMotors();
    SerialBT.println("Robot stopped");
  } else if (command.startsWith("calibrate")) {
    onCalibrate(command);
  } else {
    SerialBT.println("Unknown command: " + command);
  }
}

void stopMotors() {
  analogWrite(motorA_IN1, 0);
  digitalWrite(motorA_IN2, LOW);
  analogWrite(motorB_IN1, 0);
  digitalWrite(motorB_IN2, LOW);
}

void onCalibrate(String command) {
  command.trim(); // Verwijder onzichtbare karakters
  if (command.startsWith("calibrate black")) {
    SerialBT.println("Calibrating black...");
    for (int i = 0; i < 8; i++) {
      blackValues[i] = analogRead(sensorPins[i]);
    }
    SerialBT.println("Black calibration done.");
  } else if (command.startsWith("calibrate white")) {
    SerialBT.println("Calibrating white...");
    for (int i = 0; i < 8; i++) {
      whiteValues[i] = analogRead(sensorPins[i]);
    }
    SerialBT.println("White calibration done.");
  }
}
