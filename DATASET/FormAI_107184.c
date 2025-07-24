//FormAI DATASET v1.0 Category: Smart home light control ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Welcome message
  printf("Welcome to Happy Home Light Control Program!\n");

  // Declare variables
  int numRooms, i, j, lightCount;
  char roomNames[10][20];
  int roomLights[10][10];

  // Ask for the number of rooms in the house
  printf("How many rooms are in your house? ");
  scanf("%d", &numRooms);

  // Ask for the name of each room and the number of lights in each room
  for (i = 0; i < numRooms; i++) {
    printf("What is the name of room %d? ", i + 1);
    scanf("%s", &roomNames[i]);
    printf("How many lights are in the %s? ", roomNames[i]);
    scanf("%d", &lightCount);
    
    // Ask for the state of each light in the room
    for (j = 0; j < lightCount; j++) {
      printf("What is the state of light %d (1 = On, 0 = Off)? ", j + 1);
      scanf("%d", &roomLights[i][j]);
    }
  }

  // Print out the state of each light in each room
  printf("\nCurrent State of Lights:\n");
  for (i = 0; i < numRooms; i++) {
    printf("%s:\n", roomNames[i]);
    for (j = 0; j < lightCount; j++) {
      if (roomLights[i][j] == 1) {
        printf("  Light %d is On.\n", j + 1);
      } else {
        printf("  Light %d is Off.\n", j + 1);
      }
    }
  }

  // Thank the user for using the program
  printf("\nThank you for using Happy Home Light Control Program! Goodbye!\n");

  return 0;
}