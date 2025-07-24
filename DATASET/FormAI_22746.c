//FormAI DATASET v1.0 Category: Smart home automation ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define constants for device status
#define OFF 0
#define ON 1

// Define constants for device types
#define LIGHT 0
#define LOCK 1
#define THERMOSTAT 2

// Struct to store a device and its information
typedef struct {
    int id;
    int type;
    int status;
} Device;

// Function to turn on a device
void turnOn(Device *device) {
    device->status = ON;
    printf("Device %d turned on!\n", device->id);
}

// Function to turn off a device
void turnOff(Device *device) {
    device->status = OFF;
    printf("Device %d turned off!\n", device->id);
}

int main() {
  // Define an array of devices with their IDs, types, and statuses
  Device devices[] = {
      {0, LIGHT, OFF},
      {1, LOCK, OFF},
      {2, THERMOSTAT, OFF}
  };
  
  // Print the initial status of each device
  for (int i = 0; i < sizeof(devices) / sizeof(Device); i++) {
      Device device = devices[i];
      printf("Device %d is a ", device.id);
      switch (device.type) {
          case LIGHT:
              printf("light");
              break;
          case LOCK:
              printf("lock");
              break;
          case THERMOSTAT:
              printf("thermostat");
              break;
      }
      printf(" and is ");
      if (device.status == ON) {
          printf("on.\n");
      } else {
          printf("off.\n");
      }
  }

  // Turn on a light
  Device *light = &devices[0];
  turnOn(light);

  // Turn off the lock
  Device *lock = &devices[1];
  turnOff(lock);

  // Increase the temperature of the thermostat
  Device *thermostat = &devices[2];
  thermostat->status = 75;
  printf("Thermostat temperature increased to %d!\n", thermostat->status);

  // Print the final status of each device
  for (int i = 0; i < sizeof(devices) / sizeof(Device); i++) {
      Device device = devices[i];
      printf("Device %d is a ", device.id);
      switch (device.type) {
          case LIGHT:
              printf("light");
              break;
          case LOCK:
              printf("lock");
              break;
          case THERMOSTAT:
              printf("thermostat");
              break;
      }
      printf(" and is ");
      if (device.status == ON) {
          printf("on.\n");
      } else {
          printf("off.\n");
      }
  }

  return 0;
}