// EX5_1   
// UART 38400 baud, 8N1

void setup() {
  Serial.begin(38400);  // set 8N1
}

void loop() {
  Serial.println("Hello from UART 38400 8N1!");
  delay(1000);
}

