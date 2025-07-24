//FormAI DATASET v1.0 Category: Smart home light control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
  // initializing variables
  int bedroomLight = 0, livingRoomLight = 0, kitchenLight = 0;
  char command;

  printf("Welcome to your Smart Home Light Control System!\n");

  do {
    // printing current light status
    printf("\nCurrent Light Status:\n");
    printf("Bedroom Light: %s\n", bedroomLight ? "On" : "Off");
    printf("Living Room Light: %s\n", livingRoomLight ? "On" : "Off");
    printf("Kitchen Light: %s\n", kitchenLight ? "On" : "Off");

    // asking for user input
    printf("\nPlease enter a command (B for Bedroom, L for Living Room, K for Kitchen, E to exit):\n");
    scanf(" %c", &command);

    // processing user input
    switch (command) {
      case 'B':
        // toggling bedroom light
        bedroomLight = !bedroomLight;
        printf("Bedroom Light turned %s\n", bedroomLight ? "On" : "Off");
        break;
      case 'L':
        // toggling living room light
        livingRoomLight = !livingRoomLight;
        printf("Living Room Light turned %s\n", livingRoomLight ? "On" : "Off");
        break;
      case 'K':
        // toggling kitchen light
        kitchenLight = !kitchenLight;
        printf("Kitchen Light turned %s\n", kitchenLight ? "On" : "Off");
        break;
      case 'E':
        // exiting program
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid command. Please try again.\n");
    }
  } while (1);

  return 0;
}