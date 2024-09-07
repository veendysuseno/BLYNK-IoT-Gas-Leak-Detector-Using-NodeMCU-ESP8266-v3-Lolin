/* IoT Project Blynk IoT Gas Leak Detector */

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] ="XXXX";                // masukkan kode autentikasi disini
char ssid[] = "Veendy-Suseno";      //nama wifi
char pass[] = "Admin12345";         //password

int buzzer = D2;
int smokeA0 = A0;
int sensorThres = 600;

void setup() {
    pinMode(buzzer, OUTPUT);
    pinMode(smokeA0, INPUT);
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);
}

void loop() {
    int analogSensor = analogRead(smokeA0);
    Serial.print("Pin A0: ");
    Serial.println(analogSensor);
    if (analogSensor > sensorThres){
        tone(buzzer, 1000, 200);
        Blynk.notify("Alert: Fire in the House");
    }
    else{
        noTone(buzzer);
    }
    delay(100);
    Blynk.run();
}
