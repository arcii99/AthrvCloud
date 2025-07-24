//FormAI DATASET v1.0 Category: Robot movement control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));  // Seed the random number generator with current time

  int x = 0, y = 0;  // Initialize robot's position at (0, 0)
  printf("Robot's starting position: (%d, %d)\n", x, y);

  for (int i = 0; i < 50; i++) {
    int direction = rand() % 4;  // Generate a random direction (0 = up, 1 = right, 2 = down, 3 = left)

    switch (direction) {
      case 0:
        y++;
        printf("Moved up. New position: (%d, %d)\n", x, y);
        break;
      case 1:
        x++;
        printf("Moved right. New position: (%d, %d)\n", x, y);
        break;
      case 2:
        y--;
        printf("Moved down. New position: (%d, %d)\n", x, y);
        break;
      case 3:
        x--;
        printf("Moved left. New position: (%d, %d)\n", x, y);
        break;
    }

    // Check if robot has gone out of bounds
    if (x < -10 || x > 10 || y < -10 || y > 10) {
      printf("Out of bounds! Terminating program.\n");
      break;
    }
  }

  return 0;
}