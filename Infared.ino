int speakerPin = 9;
int thresholdVoltage;
int sensorValue;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
  thresholdVoltage = analogRead(A0);
  Serial.println((float)thresholdVoltage * (5.0 / 1023.0));
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);
  if(thresholdVoltage*1.05 < sensorValue) // if the voltage is within 5% of measured voltage 
  {
    playAlarm();
  }
  
  float voltage = sensorValue * (5.0 / 1023.0);
  Serial.println(voltage);
  delay(10);
}

void playAlarm()
{
  int i;
  for(i = 0; i < 255; i = i + 2)
        {
            analogWrite(speakerPin, i);
            delay(10);
        }
        for(i = 255; i > 1; i = i - 2)
        {
            analogWrite(speakerPin, i);
            delay(5);
        }
        for(i = 1; i <= 10; i++)
        {
            
            analogWrite(speakerPin, 200);
            delay(100);
            analogWrite(speakerPin, 25);
            delay(100);
        }
    }
  

