//FormAI DATASET v1.0 Category: Smart home light control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  printf("Welcome to the Smart Home Light Control system!\n");
  printf("Press 1 to turn on the lights, or 0 to turn them off.\n");

  bool lightsOn = false;
  int userChoice;

  while (true) {
    printf("Your choice: ");
    scanf("%d", &userChoice);

    if (userChoice == 1) {
      if (lightsOn) {
        printf("The lights are already on! What do you want me to do, add more light??\n");
      } else {
        printf("Turning the lights on! Time to party! 🎉\n");
        lightsOn = true;
      }
    } else if (userChoice == 0) {
      if (lightsOn) {
        printf("Turning the lights off! Goodbye, cruel world. 😴\n");
        lightsOn = false;
      } else {
        printf("The lights are already off, dummy! Did you forget to open your eyes?\n");
      }
    } else {
      printf("Invalid choice! Are you sure you're not a robot...?\n");
    }
  }

  return 0;
}