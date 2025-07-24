//FormAI DATASET v1.0 Category: Smart home automation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declare function to check if light is on
bool isLightOn(bool lightStatus) {
  if (lightStatus) {
    printf("The light is on.\n");
    return true;
  } else {
    printf("The light is off.\n");
    return false;
  }
}

int main() {

  // Declare variables

  bool outsideLights = true;
  bool kitchenLight = false;
  bool livingRoomLight = true;
  bool bedroomLight = false;

  // Turn outside lights on
  printf("Turning on outside lights...\n");
  outsideLights = true;

  // Check if kitchen light is on
  isLightOn(kitchenLight);

  // Turn on kitchen light
  printf("Turning on kitchen light...\n");
  kitchenLight = true;
  
  // Check if living room light is on
  isLightOn(livingRoomLight);

  // Turn off living room light
  printf("Turning off living room light...\n");
  livingRoomLight = false;

  // Check if bedroom light is on
  isLightOn(bedroomLight);

  // Turn on bedroom light
  printf("Turning on bedroom light...\n");
  bedroomLight = true;

  // Check if outside lights are on
  isLightOn(outsideLights);

  // Turn off all lights
  printf("Turning off all lights...\n");
  outsideLights = false;
  kitchenLight = false;
  livingRoomLight = false;
  bedroomLight = false;

  // Check if any lights are on
  isLightOn(outsideLights || kitchenLight || livingRoomLight || bedroomLight);

  return 0;
}