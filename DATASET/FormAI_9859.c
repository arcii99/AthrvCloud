//FormAI DATASET v1.0 Category: Robot movement control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int movement = 0;
  printf("Welcome to the Robot Movement Control\n");

  while (1) {
    printf("Please enter a movement control command:\n");
    printf("1 - Move forward\n");
    printf("2 - Move backward\n");
    printf("3 - Turn left\n");
    printf("4 - Turn right\n");
    scanf("%d", &movement);

    if (movement == 1) {
      printf("Robot is moving forward!\n");
    }

    else if (movement == 2) {
      printf("Robot is moving backward!\n");
    }

    else if (movement == 3) {
      printf("Robot is turning left!\n");
    }

    else if (movement == 4) {
      printf("Robot is turning right!\n");
    }

    else {
      printf("Invalid movement command! Please try again.\n");
      continue;
    }
  }

  return 0;
}