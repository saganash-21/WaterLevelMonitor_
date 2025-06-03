#include <math.h>

// Pin setup
int sensorPin = A0;         // Sensor analog input
int emptyLED = 2;           // Red LED for "Empty"
int refillLED = 3;          // Yellow LED for "Refill"
int fullLED = 4;            // Green LED for "Full"

// Tank dimensions
float radius = 1.0;  // meters
float length = 2.0;  // meters
float H = 2.0;       // Max water height (tank diameter) in meters

void setup() {
  pinMode(emptyLED, OUTPUT);
  pinMode(refillLED, OUTPUT);
  pinMode(fullLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  float voltage = (sensorValue * 5.0) / 1023.0;    // Convert ADC reading to voltage (0-5V)
  float water_level = (voltage / 5.0) * H;         // Scale voltage to height (0 to 2m)

  // Clamp water_level between 0 and diameter (2 * radius)
  water_level = constrain(water_level, 0, 2 * radius);

  // Calculate segment central angle (radians)
  float theta = 2 * acos((radius - water_level) / radius);

  // Calculate segment area of circular cross-section (m²)
  float segment_area = 0.5 * pow(radius, 2) * (theta - sin(theta));

  // Calculate volume in cubic meters
  float volume_m3 = segment_area * length;

  // Convert to liters (1 m³ = 1000 liters)
  float volume_liters = volume_m3 * 1000.0;

  // Output volume to Serial Monitor
  Serial.print("Water Volume: ");
  Serial.print(volume_liters);
  Serial.print(" litres — State: ");

  // Determine and print state
  if (volume_liters <= 1000) {
    Serial.println("EMPTY");
  } else if (volume_liters < 2000) {
    Serial.println("REFILL");
  } else if (volume_liters >= 4500) {
    Serial.println("FULL");
  } else {
    Serial.println("NORMAL");
  }

  // LED indicators based on volume thresholds
  digitalWrite(emptyLED, volume_liters <= 1000 ? HIGH : LOW);
  digitalWrite(refillLED, volume_liters > 1000 && volume_liters < 2000 ? HIGH : LOW);
  digitalWrite(fullLED, volume_liters >= 4500 ? HIGH : LOW);

  delay(1000);
}
