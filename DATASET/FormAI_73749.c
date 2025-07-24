//FormAI DATASET v1.0 Category: Smart home light control ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isLightOn = false;

void turnOnLight() {
  isLightOn = true;
  printf("The light is now ON.\n");
}

void turnOffLight() {
  isLightOn = false;
  printf("The light is now OFF.\n");
}

int main() {
  char command[20];
  printf("Welcome to Smart Home Light Control Program!\n");
  
  while (true) {
    printf("Type 'on' to turn on the light or 'off' to turn off the light: ");
    scanf("%s", command);
    
    if (strcmp(command, "on") == 0) {
      if (!isLightOn) {
        turnOnLight();
      } else {
        printf("The light is already on.\n");
      }
    } else if (strcmp(command, "off") == 0) {
      if (isLightOn) {
        turnOffLight();
      } else {
        printf("The light is already off.\n");
    }
    } else {
      printf("Invalid command. Please try again.\n");
    }
  }
  return 0;
}