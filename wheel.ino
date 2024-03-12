const int sensorXPin = A0;
const int sensorGasPin = A2;
const int sensorBrakePin = A1;
const int sensorButton1Pin = 2;
const int sensorButton2Pin = 3;

const int sensorButton3Pin = 4;
const int sensorButton4Pin = 5;
const int sensorButton5Pin = 6;
const int sensorButton6Pin = 7;
const int sensorButton7Pin = 8;
const int sensorButton8Pin = 9;

void setup() {
  Serial.begin(30000);  // Update baud rate to match Python script
  pinMode(sensorButton1Pin, INPUT);
  pinMode(sensorButton2Pin, INPUT);
  pinMode(sensorButton3Pin, INPUT);
  pinMode(sensorButton4Pin, INPUT);
  pinMode(sensorButton5Pin, INPUT);
  pinMode(sensorButton6Pin, INPUT);
  pinMode(sensorButton7Pin, INPUT);
  pinMode(sensorButton8Pin, INPUT);
    pinMode(11, OUTPUT);  // sets the digital pin 11 as output (LED)

}

void loop() {
  int sensorXValue = analogRead(sensorXPin) - 10;
  int sensorBrakeValue = analogRead(sensorBrakePin);
  int sensorGasValue = analogRead(sensorGasPin);
  int sensorButton1Value = digitalRead(sensorButton1Pin);  // Read button values
  int sensorButton2Value = digitalRead(sensorButton2Pin);
  int sensorButton3Value = digitalRead(sensorButton3Pin);
  int sensorButton4Value = digitalRead(sensorButton4Pin);
  int sensorButton5Value = digitalRead(sensorButton5Pin);
  int sensorButton6Value = digitalRead(sensorButton6Pin);
  int sensorButton7Value = digitalRead(sensorButton7Pin);
  int sensorButton8Value = digitalRead(sensorButton8Pin);

  // Map values for X, Brake, and Gas
  float mappedXValue = map(sensorXValue, 11, 995, -1000, 1000) / 1000.0;
  float mappedGasValue = map(sensorGasValue, 0, 210, -100, 1000) / 1000.0;
  float mappedBrakeValue = map(sensorBrakeValue, 220, 420, -100, 1000) / 1000.0;

  // Set conditions to adjust mappedXValue
  if (sensorXValue >= 480 && sensorXValue <= 511) {
    mappedXValue = 0.0;
  }

  if (sensorXValue >= 975 && sensorXValue <= 1000) {
    mappedXValue = 1.0;
  }

  if (sensorXValue >= 0 && sensorXValue <= 45) {
    mappedXValue = -1.0;
  }

  // Set conditions to adjust mappedGasValue
  if (sensorGasValue >= 0 && sensorGasValue <= 50) {
    mappedGasValue = 0.0;
  }

  if (sensorGasValue >= 192 && sensorGasValue <= 999) {
    mappedGasValue = 1.0;
  }

  // Set conditions to adjust mappedBrakeValue
  if (sensorBrakeValue >= 180 && sensorBrakeValue <= 238) {
    mappedBrakeValue = 0.0;
  }

  if (sensorBrakeValue >= 418 && sensorBrakeValue <= 480) {
    mappedBrakeValue = 1.0;
  }

  // Odeslání hodnot na sériovou linku
  Serial.print("X:");
  Serial.print(mappedXValue,4);
  Serial.print(",");
  Serial.print("Brake:");
  Serial.print(mappedBrakeValue,4);
  Serial.print(",");
  Serial.print("Gas:");
  Serial.print(mappedGasValue,4);
  Serial.print(",");
  Serial.print("Button1:");
  Serial.print(sensorButton1Value);
  Serial.print(",");
  Serial.print("Button2:");
  Serial.print(sensorButton2Value);
  Serial.print(",");
  Serial.print("Button3:");
  Serial.print(sensorButton3Value);
  Serial.print(",");
  Serial.print("Button4:");
  Serial.print(sensorButton4Value);
  Serial.print(",");
  Serial.print("Button5:");
  Serial.print(sensorButton5Value);
  Serial.print(",");
  Serial.print("Button6:");
  Serial.print(sensorButton6Value);
  Serial.print(",");
  Serial.print("Button7:");
  Serial.print(sensorButton7Value);
  Serial.print(",");
  Serial.print("Button8:");
  Serial.println(sensorButton8Value);
if (Serial.available() > 0) {
    String serialCommand = Serial.readStringUntil('\n');
    serialCommand.trim();

    if (serialCommand == "LED = 1") {
      digitalWrite(11, LOW);  // Turn off the LED
    }

} else {
      // Blink the LED every 500ms if no or invalid serial command received
      digitalWrite(11, HIGH);
      delay(500);
      digitalWrite(11, LOW);
      delay(500);
    }

}
