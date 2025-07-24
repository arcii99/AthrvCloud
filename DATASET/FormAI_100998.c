//FormAI DATASET v1.0 Category: Smart home automation ; Style: scalable
#include <stdio.h>
#include <stdbool.h>

// Define states for different devices.
// 0 = OFF, 1 = ON
int livingRoomLights = 0;
int bedroomLights = 0;
int kitchenLights = 0;
int thermostat = 65; // Degrees Fahrenheit
bool doorLocked = true;

// Function to toggle living room lights.
void toggleLivingRoomLights() {
  if (livingRoomLights == 0) {
    printf("Turning on living room lights.\n");
    livingRoomLights = 1;
  } else {
    printf("Turning off living room lights.\n");
    livingRoomLights = 0;
  }
}

// Function to toggle bedroom lights.
void toggleBedroomLights() {
  if (bedroomLights == 0) {
    printf("Turning on bedroom lights.\n");
    bedroomLights = 1;
  } else {
    printf("Turning off bedroom lights.\n");
    bedroomLights = 0;
  }
}

// Function to toggle kitchen lights.
void toggleKitchenLights() {
  if (kitchenLights == 0) {
    printf("Turning on kitchen lights.\n");
    kitchenLights = 1;
  } else {
    printf("Turning off kitchen lights.\n");
    kitchenLights = 0;
  }
}

// Function to adjust thermostat.
void adjustThermostat(int degrees) {
  printf("Adjusting thermostat to %d degrees Fahrenheit.\n", degrees);
  thermostat = degrees;
}

// Function to lock/unlock door.
void toggleDoorLock() {
  if (doorLocked) {
    printf("Unlocking door.\n");
    doorLocked = false;
  } else {
    printf("Locking door.\n");
    doorLocked = true;
  }
}

int main() {
  // Toggle living room lights on.
  toggleLivingRoomLights();

  // Adjust thermostat to 70 degrees Fahrenheit.
  adjustThermostat(70);

  // Toggle kitchen lights on.
  toggleKitchenLights();

  // Lock front door.
  toggleDoorLock();

  // Toggle bedroom lights on.
  toggleBedroomLights();

  // Unlock front door.
  toggleDoorLock();
  
  // Turn off all lights.
  toggleLivingRoomLights();
  toggleBedroomLights();
  toggleKitchenLights();

  return 0;
}