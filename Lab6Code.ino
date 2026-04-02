const int ledPin = 9;
const float TWOPI = 2 * 3.1415926;

// Three window sizes
const int window1 = 10;
const int window2 = 25;
const int window3 = 50;

// Buffers for each window
int readings1[window1], readings2[window2], readings3[window3];
int total1 = 0, total2 = 0, total3 = 0;
int index1 = 0, index2 = 0, index3 = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  // Initialize all buffers to zero
  for (int i = 0; i < window1; i++) readings1[i] = 0;
  for (int i = 0; i < window2; i++) readings2[i] = 0;
  for (int i = 0; i < window3; i++) readings3[i] = 0;
}

void loop() {
  // Drive LED with 1 Hz sine wave
  int brightness = 100+50*sin(1.0*TWOPI*millis()/1000);
  analogWrite(ledPin, brightness);

  // Read raw value once
  int raw = analogRead(A0);

  // --- Window 1 ---
  total1 -= readings1[index1];
  readings1[index1] = raw;
  total1 += raw;
  index1 = (index1 + 1) % window1;
  int avg1 = total1 / window1;

  // --- Window 2 ---
  total2 -= readings2[index2];
  readings2[index2] = raw;
  total2 += raw;
  index2 = (index2 + 1) % window2;
  int avg2 = total2 / window2;

  // --- Window 3 ---
  total3 -= readings3[index3];
  readings3[index3] = raw;
  total3 += raw;
  index3 = (index3 + 1) % window3;
  int avg3 = total3 / window3;

  // Print all four: time, raw, avg1, avg2, avg3
  Serial.print(millis());
  Serial.print(",");
  Serial.print(raw);
  Serial.print(",");
  Serial.print(avg1);
  Serial.print(",");
  Serial.print(avg2);
  Serial.print(",");
  Serial.println(avg3);

  delay(10);
}
