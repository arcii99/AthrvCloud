//FormAI DATASET v1.0 Category: Robot movement control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[50];
  int x_position = 0;
  int y_position = 0;

  // greet the user
  printf("Hello, I am the robot control program.\n");

  while (1) {
    // prompt the user for input
    printf("Enter a direction to move (up, down, left, right): ");
    fgets(input, sizeof(input), stdin);

    // remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // move the robot based on the user's input
    if (strcmp(input, "up") == 0) {
      y_position++;
      printf("Moving up...\n");
    } else if (strcmp(input, "down") == 0) {
      y_position--;
      printf("Moving down...\n");
    } else if (strcmp(input, "left") == 0) {
      x_position--;
      printf("Moving left...\n");
    } else if (strcmp(input, "right") == 0) {
      x_position++;
      printf("Moving right...\n");
    } else if (strcmp(input, "exit") == 0) {
      printf("Exiting program...\n");
      exit(0);
    } else {
      printf("Invalid input. Please try again.\n");
    }

    // print the robot's current position
    printf("Current position: (%d, %d)\n", x_position, y_position);
  }

  return 0;
}