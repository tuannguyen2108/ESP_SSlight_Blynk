#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6rl6nGQn5"
#define BLYNK_TEMPLATE_NAME "SS"
#define BLYNK_AUTH_TOKEN "02-d5FXYQoJOXyFtu4z2UIPYviJnM5Eb"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "02-d5FXYQoJOXyFtu4z2UIPYviJnM5Eb";
char ssid[] = "Nguyên Lê";
char pass[] = "123467890";

#define digitalPin D0
#define led D2

int value;
int phantram;

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(led, OUTPUT);
}
void loop()
{
  Blynk.run();
  value = digitalRead(digitalPin); //doc gia tri cam bien
  phantram = map(value, 0, 1, 100, 0);
  Blynk.virtualWrite(V2, phantram); //truyen du lieu tu cam bien len Blynk app
    if (phantram >= 1)
  {
    digitalWrite(led, LOW);
  }
  else
  {
    digitalWrite(led, HIGH);
  }
}
