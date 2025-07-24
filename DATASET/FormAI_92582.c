//FormAI DATASET v1.0 Category: Smart home light control ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void turnOnLight(int lightNum) {
  printf("Turning on light %d\n", lightNum);
  // Code to send command to turn on light
}

void turnOffLight(int lightNum) {
  printf("Turning off light %d\n", lightNum);
  // Code to send command to turn off light
}

int main() {
  int numLights = 5;
  int lightStatus[numLights];

  // Initialize all lights to off
  memset(lightStatus, 0, numLights * sizeof(int));

  // Turn on the first light
  turnOnLight(1);
  lightStatus[0] = 1;

  // Turn off the second light
  turnOffLight(2);
  lightStatus[1] = 0;

  // Turn on all remaining lights
  for (int i = 2; i < numLights; i++) {
    turnOnLight(i+1);
    lightStatus[i] = 1;
  }

  // Change the status of lights using if statement

  if (lightStatus[0] == 1) {
    turnOffLight(1);
    lightStatus[0] = 0;
  } else {
    turnOnLight(1);
    lightStatus[0] = 1;
  }

  return 0;
}