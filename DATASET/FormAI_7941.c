//FormAI DATASET v1.0 Category: Robot movement control ; Style: calm
#include <stdio.h>

#define FORWARD 1
#define BACKWARD -1
#define LEFT 1
#define RIGHT -1

int main() {
  int x = 0, y = 0;
  int direction = LEFT;

  printf("Starting position: (%d,%d)\n", x, y);

  // Move forward 5 steps
  for (int i = 0; i < 5; i++) {
    x += direction * FORWARD;
    printf("Moved forward to (%d,%d)\n", x, y);
  }

  // Turn right
  direction = RIGHT;
  printf("Turning right...\n");

  // Move backward 3 steps
  for (int i = 0; i < 3; i++) {
    y += direction * BACKWARD;
    printf("Moved backward to (%d,%d)\n", x, y);
  }

  // Turn left
  direction = LEFT;
  printf("Turning left...\n");

  // Move forward 2 steps
  for (int i = 0; i < 2; i++) {
    y += direction * FORWARD;
    printf("Moved forward to (%d,%d)\n", x, y);
  }

  // Turn left
  direction = LEFT;
  printf("Turning left...\n");

  // Move forward 4 steps
  for (int i = 0; i < 4; i++) {
    x += direction * FORWARD;
    printf("Moved forward to (%d,%d)\n", x, y);
  }

  return 0;
}