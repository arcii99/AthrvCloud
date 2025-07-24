//FormAI DATASET v1.0 Category: Smart home light control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Welcome message
  printf("Welcome to the Smart Home Light Control Program!\n\n");

  // User input variables
  char room[20];
  int brightness;

  // Main program loop
  while (1) {
    // Prompt user for room name
    printf("Please enter the name of the room: ");
    scanf("%s", room);

    // Prompt user for brightness level
    printf("Please enter the brightness level (0-100): ");
    scanf("%d", &brightness);

    // Check if user wants to exit program
    if (strcmp(room, "exit") == 0 || brightness == -1) {
      printf("Thank you for using the Smart Home Light Control Program!\n");
      break;
    }

    // Control the lights based on the user input
    printf("Turning on the lights in the %s with a brightness level of %d.\n\n", room, brightness);
  }

  return 0;
}