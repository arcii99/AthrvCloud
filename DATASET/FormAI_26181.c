//FormAI DATASET v1.0 Category: Robot movement control ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed for random number generation

  // initialize robot position
  int x = 0;
  int y = 0;

  printf("Current position: (%d, %d)\n", x, y);

  // generate random movement directions and distances
  for (int i = 1; i <= 10; i++) {
    int direction = rand() % 4; // 0=up, 1=right, 2=down, 3=left
    int distance = rand() % 11; // random distance between 0 and 10

    // update robot position based on movement direction and distance
    switch (direction) {
      case 0:
        y += distance;
        break;
      case 1:
        x += distance;
        break;
      case 2:
        y -= distance;
        break;
      case 3:
        x -= distance;
        break;
    }

    printf("Move %d: %d steps %s\n", i, distance, direction == 0 ? "up" : (direction == 1 ? "right" : (direction == 2 ? "down" : "left")));
    printf("New position: (%d, %d)\n", x, y);
  }

  return 0;
}