const int sensorPin = A0;
const float alpha = 0.1; //filtering coefficient

float filtered = 0;
int raw = 0;

void setup() {
  Serial.begin(9600);
  filtered = analogRead(sensorPin);
}

void loop() {
  raw = analogRead(sensorPin);
  filtered = alpha * raw + (1 - alpha) * filtered;

  Serial.print(millis());
  Serial.print(",");
  Serial.print(raw);
  Serial.print(",");
  Serial.println(filtered);

  delay(5);
}
