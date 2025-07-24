//FormAI DATASET v1.0 Category: Smart home automation ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to turn on/off the lights
void toggleLights(bool isOn) {
   if(isOn) {
      printf("Turning off the lights\n");
   } else {
      printf("Turning on the lights\n");
   }
}

// Function to adjust the thermostat
void adjustTemperature(float temperature, float targetTemperature) {
   if(temperature > targetTemperature) {
      printf("Lowering the temperature to %.2f degrees Celsius\n", targetTemperature);
   } else {
      printf("Increasing the temperature to %.2f degrees Celsius\n", targetTemperature);
   }
}

// Function to unlock/lock the door
void toggleLock(bool isLocked) {
   if(isLocked) {
      printf("Unlocking the door\n");
   } else {
      printf("Locking the door\n");
   }
}

int main() {
   // Initialize variables to represent the current status of the smart home system
   bool lightsOn = true;
   float temperature = 25.0;
   bool doorLocked = true;

   // Simulate a user requesting to turn off the lights
   toggleLights(lightsOn);
   lightsOn = !lightsOn;

   // Simulate a user requesting to adjust the temperature
   float targetTemperature = 20.0;
   adjustTemperature(temperature, targetTemperature);
   temperature = targetTemperature;

   // Simulate a user requesting to lock the door
   toggleLock(doorLocked);
   doorLocked = !doorLocked;

   // Simulate a user requesting to turn on the lights
   toggleLights(lightsOn);
   lightsOn = !lightsOn;

   return 0;
}