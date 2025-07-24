//FormAI DATASET v1.0 Category: Smart home automation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
  int temp, light, door;
  printf("Welcome to Smart Home Automation System!\n\n");
  printf("Please enter current temperature (in Celsius): ");
  scanf("%d", &temp);

  if (temp > 25) {
    printf("It's too hot inside. Turning on the Air Conditioner.\n");
    // Code to turn on the Air Conditioner
  } else if (temp < 20) {
    printf("It's too cold inside. Turning on the Heater.\n");
    // Code to turn on the Heater
  } else {
    printf("Temperature is perfect.\n");
  }

  printf("\nPlease enter current light level (in Lumens): ");
  scanf("%d", &light);

  if (light < 100) {
    printf("It's too dark inside. Turning on the lights.\n");
    // Code to turn on the lights
  } else if (light > 500) {
    printf("It's too bright inside. Turning off the lights.\n");
    // Code to turn off the lights
  } else {
    printf("Light level is acceptable.\n");
  }

  printf("\nPlease enter the status of the door (1 for open, 0 for closed): ");
  scanf("%d", &door);

  if (door == 1) {
    printf("Door is open. Locking the door.\n");
    // Code to lock the door
  } else {
    printf("Door is closed. Checking for intruders.\n");
    // Code to check for intruders
  }

  printf("\nThank you for using Smart Home Automation System!\n");

  return 0;
}