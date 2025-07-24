//FormAI DATASET v1.0 Category: Robot movement control ; Style: beginner-friendly
#include <stdio.h>

void moveForward(int distance);
void moveBackward(int distance);
void turnLeft(int degrees);
void turnRight(int degrees);

int main() {
  printf("Welcome to C Robot Movement Control!\n");
  printf("Let's move the robot around.\n");

  moveForward(10);
  turnRight(90);
  moveForward(5);
  turnLeft(45);
  moveBackward(3);
  turnRight(30);
  moveForward(2);
  
  return 0;
}

void moveForward(int distance) {
  printf("Moving Forward %d units.\n", distance);
  // Insert code to move the robot forward distance units.
}

void moveBackward(int distance) {
  printf("Moving Backward %d units.\n", distance);
  // Insert code to move the robot backward distance units.
}

void turnLeft(int degrees) {
  printf("Turning Left %d degrees.\n", degrees);
  // Insert code to turn the robot left degrees amount.
}

void turnRight(int degrees) {
  printf("Turning Right %d degrees.\n", degrees);
  // Insert code to turn the robot right degrees amount.
}