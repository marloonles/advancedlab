        
       
        unsigned long currentTime = 0;
        unsigned long lastTime = 0;
        const unsigned long intervalBetweenData = 1000;
         void setup() {
           // make the serial talk faster
           // be sure to also change this in the serial monitor window settings
            Serial.begin(500000);
        }
        void loop() {
          currentTime =  micros();
          
          if (currentTime - lastTime >= intervalBetweenData)
            int sensorValue = analogRead(A0);
            
            lastTime+=intervalBetweenData;
            
            Serial.print(currentTime/1000);
            Serial.print(',');
            Serial.println(analogRead(A0));
            }
