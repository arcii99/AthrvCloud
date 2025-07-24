//FormAI DATASET v1.0 Category: Robot movement control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Robot Movement Control Program!\n\n");

  // Seed for the random number generator
  srand(time(NULL));

  // Variable declarations
  int x = 0;
  int y = 0;
  int move;
  int energy = 100;

  printf("Starting position: (%d,%d)\n", x, y);
  printf("Energy level: %d\n\n", energy);

  while (energy > 0) {
    // Generate a random movement
    move = rand() % 4;

    switch (move) {
      case 0:
        // Move up
        y++;
        printf("Moved up! New position: (%d,%d)\n", x, y);
        break;
      case 1:
        // Move down
        y--;
        printf("Moved down! New position: (%d,%d)\n", x, y);
        break;
      case 2:
        // Move left
        x--;
        printf("Moved left! New position: (%d,%d)\n", x, y);
        break;
      case 3:
        // Move right
        x++;
        printf("Moved right! New position: (%d,%d)\n", x, y);
        break;
    }

    energy -= 10;
    printf("Energy level: %d\n\n", energy);
  }

  printf("Out of energy! Robot shut down at position (%d,%d).\n", x, y);

  return 0;
}