// SARASWAT_SYSTEM_SERVER

// USE BLYNK APP FOR HARDWARE AUTH ONLINE.

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


int LED1 = D1;             // if any of the pin will not work
int LED2 = D2;             // change the name of that pin to new pin
int LED3 = D3;
int LED4 = D4;


char auth[] = "AUTH_TOKEN";
char ssid[] = "YOUR_HOTSPOT_NAME";
char pass[] = "YOUR_HOTSOPT_PASSWORD";


BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  digitalWrite(LED1, pinValue);
  // process received value
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V2 to a variable
  digitalWrite(LED2, pinValue);
  // process received value
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V3 to a variable
  digitalWrite(LED3, pinValue);
  // process received value
}

BLYNK_WRITE(V4)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V4 to a variable
  digitalWrite(LED4, pinValue);
  // process received value
}

void setup() 
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  Serial.begin(9600); /* Define baud rate for serial communication */
  Blynk.begin(auth, ssid, pass);
}

void loop() 
{
  Blynk.run();


  if (Serial.available())  /* If data is available on serial port */
  {
    char data_received;
    data_received = Serial.read();  /* Data received from bluetooth */
    if (data_received == '1')
    {
      digitalWrite(LED1, HIGH);
      Blynk.virtualWrite(V1, 1);
      Serial.write("LED1 turned ON\n");
    }
    else if (data_received == '2')
    {
      digitalWrite(LED1, LOW);
      Blynk.virtualWrite(V1, 0);
      Serial.write("LED1 turned OFF\n");
    }
    else if (data_received == '3')
    {
      digitalWrite(LED2, HIGH);
      Blynk.virtualWrite(V2, 1);
      Serial.write("LED turned ON\n");
    }
    else if (data_received == '4')
    {
      digitalWrite(LED2, LOW);
      Blynk.virtualWrite(V2, 0);
      Serial.write("LED2 turned ON\n");
    }
    else if (data_received == '5')
    {
      digitalWrite(LED3, HIGH);
      Blynk.virtualWrite(V3, 1);
      Serial.write("LED3 turned ON\n");
    }
    else if (data_received == '6')
    {
      digitalWrite(LED3, LOW);
      Blynk.virtualWrite(V3, 0);
      Serial.write("LED3 turned ON\n");
    }
    else if (data_received == '7')
    {
      digitalWrite(LED4, HIGH);
      Blynk.virtualWrite(V4, 1);
      Serial.write("LED4 turned ON\n");
    }
    else if (data_received == '8')
    {
      digitalWrite(LED4, LOW);
      Blynk.virtualWrite(V4, 0);
      Serial.write("LED4 turned ON\n");
    }
    else {
    }
  }
}
