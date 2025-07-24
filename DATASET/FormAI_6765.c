//FormAI DATASET v1.0 Category: Robot movement control ; Style: realistic
#include <stdio.h>

int main(void) {
  // initialize variables
  int direction = 0; // 0 = forward, 1 = backward
  int speed = 50; // between 0 and 100
  int distance = 0;
  int max_distance = 500; // in centimeters

  // print initial status
  printf("Robot is moving forward at speed %d\n", speed);

  // simulate movement
  while (distance < max_distance) {
    distance += speed; // update distance
    if (direction == 0) { // moving forward
      printf("Robot moved forward %d cm\n", speed);
    } else { // moving backward
      printf("Robot moved backward %d cm\n", speed);
    }

    // check if at end of track
    if (distance >= max_distance) {
      printf("Robot reached end of track\n");
      break; // exit loop
    }

    // check if to change direction
    if (distance % 100 == 0) {
      if (direction == 0) { // currently moving forward
        printf("Robot is turning around\n");
        direction = 1; // change to moving backward
      } else { // currently moving backward
        printf("Robot is turning around\n");
        direction = 0; // change to moving forward
      }
    }
  }

  return 0;
}