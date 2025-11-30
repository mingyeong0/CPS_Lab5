// EX5_3  
// I2C HC-SR04 (address assumed 0x20)

#include <Wire.h>
#define SR04_ADDR 0x20

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  Wire.beginTransmission(SR04_ADDR);
  Wire.write(0x01);          // Trigger command
  Wire.endTransmission();

  delay(50);

  Wire.requestFrom(SR04_ADDR, 2);
  if (Wire.available() >= 2) {
    int high = Wire.read();
    int low = Wire.read();
    int distance = (high << 8) | low;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" mm");
  }

  delay(1000);
}

