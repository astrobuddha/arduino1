#include <math.h>

const int B = 4275;               // B value of the thermistor

const int R0 = 100000;            // R0 = 100k

const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0
void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int a = analogRead(pinTempSensor);
 
    float R = 1023.0/a-1.0;
    R = R0*R;
 
    float tempC = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet

    float tempF = (tempC * 9.0/5.0) + 32;
 
    Serial.print("temp in F = ");
    Serial.println(tempF);

    delay(10000);
}


/*
-- Blink Code
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(4000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(4000);
}
*/