//FormAI DATASET v1.0 Category: Smart home automation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// define constants for on and off states
#define ON 1
#define OFF 0

// define struct for each smart device
typedef struct {
  int deviceID;
  int state;
} SmartDevice;

int main() {
  // create an array of 5 smart devices
  SmartDevice devices[5];

  // initialize each device with a random state - 50/50 chance of being on or off
  for (int i = 0; i < 5; i++) {
    devices[i].deviceID = i+1;
    devices[i].state = rand() % 2;
  }

  // print the initial state of each device
  printf("Initial State of Smart Devices:\n");
  for (int i = 0; i < 5; i++) {
    printf("Device %d: %s\n", devices[i].deviceID, devices[i].state == ON ? "ON" : "OFF");
  }

  // simulate a command to turn off all devices
  printf("\nTurning off all devices...\n");
  for (int i = 0; i < 5; i++) {
    devices[i].state = OFF;
  }

  // print the new state of each device after the command
  printf("\nState of Smart Devices after 'turn off' command:\n");
  for (int i = 0; i < 5; i++) {
    printf("Device %d: %s\n", devices[i].deviceID, devices[i].state == ON ? "ON" : "OFF");
  }

  // simulate a command to turn on specific devices
  printf("\nTurning on devices 1 and 4...\n");
  devices[0].state = ON;
  devices[3].state = ON;

  // print the new state of each device after the command
  printf("\nState of Smart Devices after 'turn on' command:\n");
  for (int i = 0; i < 5; i++) {
    printf("Device %d: %s\n", devices[i].deviceID, devices[i].state == ON ? "ON" : "OFF");
  }

  // simulate a command to toggle the state of all devices
  printf("\nToggling the state of all devices...\n");
  for (int i = 0; i < 5; i++) {
    devices[i].state = (devices[i].state == ON) ? OFF : ON;
  }

  // print the new state of each device after the command
  printf("\nState of Smart Devices after 'toggle' command:\n");
  for (int i = 0; i < 5; i++) {
    printf("Device %d: %s\n", devices[i].deviceID, devices[i].state == ON ? "ON" : "OFF");
  }

  return 0;
}