//FormAI DATASET v1.0 Category: Smart home automation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Welcome to the Smart Home Automation program!

  int temperature = 25; // Temperature in degrees Celsius
  int humidity = 65; // Humidity in percentage
  int motionDetected = 0; // 0 for no motion and 1 for motion detected

  // Smart Thermostat

  if(temperature >= 25)
  {
    printf("The temperature is currently set at %d degrees Celsius. It's too hot, cooling the room down...\n", temperature);
    temperature--;
  }
  else if(temperature <= 20)
  {
    printf("The temperature is currently set at %d degrees Celsius. It's too cold, heating the room up...\n", temperature);
    temperature++;
  }
  else
  {
    printf("The temperature is perfect at %d degrees Celsius.\n", temperature);
  }

  // Smart Humidifier

  if(humidity >= 65)
  {
    printf("The humidity is currently set at %d percent. It's too humid, decreasing the humidity...\n", humidity);
    humidity--;
  }
  else if(humidity <= 55)
  {
    printf("The humidity is currently set at %d percent. It's too dry, increasing the humidity...\n", humidity);
    humidity++;
  }
  else
  {
    printf("The humidity level is perfect at %d percent.\n", humidity);
  }

  // Smart Security System

  if(motionDetected == 1)
  {
    printf("Motion detected in the home! Alerting the homeowner...\n");
  }
  else
  {
    printf("No motion detected in the home. Everything is safe and secure.\n");
  }

  return 0;
}