//FormAI DATASET v1.0 Category: Robot movement control ; Style: portable
#include <stdio.h>

#define FORWARD 1
#define BACKWARD -1
#define LEFT 1
#define RIGHT -1

int main() {
  int x_pos = 0;
  int y_pos = 0;
  int facing = LEFT;

  printf("Starting position: (%d, %d)\n", x_pos, y_pos);

  // Move to the right 5 spaces
  for (int i = 0; i < 5; i++) {
    x_pos += facing * FORWARD;
    printf("Moved forward to position: (%d, %d)\n", x_pos, y_pos);
  }

  // Turn around
  facing = RIGHT;
  printf("Turned around\n");

  // Move back to the left 3 spaces
  for (int i = 0; i < 3; i++) {
    x_pos += facing * FORWARD;
    printf("Moved backward to position: (%d, %d)\n", x_pos, y_pos);
  }

  // Turn to face up
  facing = LEFT;
  printf("Turned to face up\n");

  // Move up 2 spaces
  for (int i = 0; i < 2; i++) {
    y_pos += facing * FORWARD;
    printf("Moved forward to position: (%d, %d)\n", x_pos, y_pos);
  }

  // Turn to face down
  facing = RIGHT;
  printf("Turned to face down\n");

  // Move down 4 spaces
  for (int i = 0; i < 4; i++) {
    y_pos += facing * FORWARD;
    printf("Moved backward to position: (%d, %d)\n", x_pos, y_pos);
  }

  printf("Final position: (%d, %d)\n", x_pos, y_pos);

  return 0;
}