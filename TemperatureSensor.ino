#include <math.h>

int a;

float temperature;
int B=3975; // B value of Thermistor
float resistance;

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    a = analogRead(0);
    resistance = (float) (1023 - a) * 10000 / a; // get the resistance of the sensor;
    temperature = 1 / (log(resistance / 10000) / B + 1 / 298.15) - 273/15; // convert to temperature via datasheet;
    delay(1000);
    Serial.print("current temperature is ");
    Serial.println(temperature);
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