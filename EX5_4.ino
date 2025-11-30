// EX5_4

#define TRIG 9
#define ECHO 8
#define FAN 5  // PWM pin

long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  return duration * 0.034 / 2;  // cm
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(FAN, OUTPUT);
}

void loop() {
  long d = getDistance();
  Serial.println(d);

  if (d <= 4) {
    analogWrite(FAN, 255);  // full speed
  }
  else if (d > 4 && d <= 20) {
    int speed = map(d, 4, 20, 255, 50); // distance↑ → slower
    analogWrite(FAN, speed);
  }
  else {
    analogWrite(FAN, 0); // off
  }

  delay(2000);
}
