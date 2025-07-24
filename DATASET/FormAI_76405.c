//FormAI DATASET v1.0 Category: Smart home automation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
  printf("~~~WELCOME TO THE SMART HOME AUTOMATION SYSTEM!~~~\n\n");
  printf("Initializing system...\n\n");
  
  //sets up random seed
  srand(time(0));
  
  bool lights = false;
  bool thermostat = false;
  bool security = false;
  
  printf("System initialized!\n\n");
  
  //simulate changes in the home environment
  printf("Making changes to the home environment...\n\n");
  
  //randomly turns on/off the lights
  int light_state = rand() % 2;
  if (light_state == 0) {
    lights = false;
    printf("-Lights turned off.\n");
  } else {
    lights = true;
    printf("-Lights turned on.\n");
  }
  
  //randomly adjusts the thermostat temperature
  int thermostat_state = rand() % 3;
  if (thermostat_state == 0) {
    thermostat = false;
    printf("-Thermostat turned off.\n");
  } else if (thermostat_state == 1) {
    thermostat = true;
    printf("-Thermostat turned on.\n");
  } else {
    thermostat = true;
    int temp = rand() % 5 + 70;
    printf("-Thermostat temperature set to %d°F.\n", temp);
  }
  
  //randomly sets the security system state
  int security_state = rand() % 2;
  if (security_state == 0) {
    security = false;
    printf("-Security system deactivated.\n");
  } else {
    security = true;
    printf("-Security system activated.\n");
  }
  
  printf("\nChanges made successfully!\n\n");
  
  //display current system state
  printf("Current system state:\n");
  if (lights) {
    printf("-Lights: ON\n");
  } else {
    printf("-Lights: OFF\n");
  }
  
  if (thermostat) {
    printf("-Thermostat: ON\n");
  } else {
    printf("-Thermostat: OFF\n");
  }
  
  if (thermostat && thermostat_state == 2) {
    int temp = rand() % 5 + 70;
    printf("-Temperature: %d°F\n", temp);
  }
  
  if (security) {
    printf("-Security system: ACTIVATED\n");
  } else {
    printf("-Security system: DEACTIVATED\n");
  }
  
  printf("\nExiting program...\n");
  
  return 0;
}