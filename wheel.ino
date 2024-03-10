const int sensorXPin = A0;        // Pin for X-axis sensor
const int sensorGasPin = A1;      // Pin for Gas sensor
const int sensorBrakePin = A3;    // Pin for Brake sensor

void setup() {
  Serial.begin(22500);  // Initialize serial communication
}

void loop() {
  int sensorXValue = analogRead(sensorXPin) - 10;     // Read X-axis sensor value
  int sensorBrakeValue = analogRead(sensorBrakePin);  // Read Brake sensor value
  int sensorGasValue = analogRead(sensorGasPin);      // Read Gas sensor value

  // Map values for X, Brake, and Gas
  float mappedXValue = map(sensorXValue, 20, 980, -1000, 1000) / 1000.0;
  float mappedGasValue = map(sensorGasValue, 0, 255, -100, 1000) / 1000.0;
  float mappedBrakeValue = map(sensorBrakeValue, 220, 420, -100, 1000) / 1000.0;

  // Set conditions to adjust mappedXValue
  if (sensorXValue >= 480 && sensorXValue <= 505) {
    mappedXValue = 0.0;
  }

  if (sensorXValue >= 960 && sensorXValue <= 990) {
    mappedXValue = 1.0;
  }

  if (sensorXValue >= 5 && sensorXValue <= 40) {
    mappedXValue = -1.0;
  }

  // Set conditions to adjust mappedGasValue
  if (sensorGasValue >= 0 && sensorGasValue <= 50) {
    mappedGasValue = 0.0;
  }

  if (sensorGasValue >=  190 && sensorGasValue <= 999) {
    mappedGasValue = 1.0;
  }

  // Set conditions to adjust mappedBrakeValue
  if (sensorBrakeValue >= 180 && sensorBrakeValue <= 238) {
    mappedBrakeValue = 0.0;
  }

  if (sensorBrakeValue >=  418 && sensorBrakeValue <= 480) {
    mappedBrakeValue = 1.0;
  }

  // Odeslání hodnot na sériovou linku
  Serial.print("X:");
  Serial.print(mappedXValue, 4);
  Serial.print(",");
  Serial.print("Brake:");
  Serial.print(mappedBrakeValue, 4);
  Serial.print(",");
  Serial.print("Gas:");
  Serial.println(mappedGasValue, 4);
}
