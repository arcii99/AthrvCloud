//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the C Drone Remote Control Program!\n");
  int loop = 1;
  while (loop) {
    printf("\nPlease enter your command (takeoff, land, forward, backward, left, right): ");
    char input[10];
    scanf("%s", input);
    if (strcmp(input, "takeoff") == 0) {
      printf("\nDrone is taking off...\n");
    }
    else if (strcmp(input, "land") == 0) {
      printf("\nDrone is landing...\n");
      loop = 0;
    }
    else if (strcmp(input, "forward") == 0) {
      printf("\nDrone is moving forward...\n");
    }
    else if (strcmp(input, "backward") == 0) {
      printf("\nDrone is moving backward...\n");
    }
    else if (strcmp(input, "left") == 0) {
      printf("\nDrone is moving left...\n");
    }
    else if (strcmp(input, "right") == 0) {
      printf("\nDrone is moving right...\n");
    }
    else {
      printf("\nInvalid command. Please try again.\n");
    }
  }
  printf("\nProgram finished. Thank you for using the C Drone Remote Control Program!\n");
  return 0;
}