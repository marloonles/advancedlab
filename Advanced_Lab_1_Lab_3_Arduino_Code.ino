void setup() {  
  Serial.begin(9600);
  const int PotInputPin = A1;
  
const int outPin = 13;

int outputLevel=0;
    
  pinMode(outPin, OUTPUT);
}
void loop() {
  
  int sensorValue = analogRead(A0);
  int potValue = analogRead(A1);

  // Add time to the serial out put.
    
  Serial.print(millis());
  Serial.print(',');
  Serial.print(sensorValue);
  Serial.print(',');
  Serial.println(potValue);
  
  delay(200);
}
