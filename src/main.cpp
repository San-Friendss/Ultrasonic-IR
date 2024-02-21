// Blynk App
#define BLYNK_AUTH_TOKEN_Ultrasonic_IR "Dh7ZDdctd4TInweG0CHJ5B0hW9E1kZdz"
#define BLYMK_AUTH_TOKEN_Motor "l4chGUuJL7Yso2jt3yPCQ377vewUzICt"
#define BLYNK_PRINT Serial

// include the libraries
#include <Arduino.h>
#include <Ultrasonic.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define LED 2

// create an Ultrasonic object
Ultrasonic ultrasonic(16);

// variable to store the range in cm
long RangeInCentimeters, leftDistance, rightDistance;

// Your WiFi credentials.
char ssid[] = "apkmew";
char pass[] = "6410500360";

WidgetBridge bridge(V0);

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
    // Change Web Link Button message to "Congratulations!"
    Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
    Blynk.setProperty(V3, "onImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
    Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
    bridge.setAuthToken(BLYMK_AUTH_TOKEN_Motor);
    digitalWrite(LED, HIGH);
}

void setup()
{
    Serial.begin(9600);
    Blynk.begin(BLYNK_AUTH_TOKEN_Ultrasonic_IR, ssid, pass, "blynk.iot-cm.com", 8080); // Blynk                                                             // Stop the car
}

void loop()
{
    Blynk.run();                            // Blynk
    RangeInCentimeters = ultrasonic.read(); // get the range from the sensor

    bridge.virtualWrite(V5, RangeInCentimeters);
}