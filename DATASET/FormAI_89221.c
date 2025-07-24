//FormAI DATASET v1.0 Category: Robot movement control ; Style: dynamic
#include <stdio.h>

// function to move the robot forward
void moveForward(int distance) {
  printf("Moving forward %d inches\n", distance);
}

// function to move the robot backward
void moveBackward(int distance) {
  printf("Moving backward %d inches\n", distance);
}

// function to turn the robot left
void turnLeft(int degrees) {
  printf("Turning left %d degrees\n", degrees);
}

// function to turn the robot right
void turnRight(int degrees) {
  printf("Turning right %d degrees\n", degrees);
}

// main function to control the robot's movements
int main() {
  // move forward for 12 inches
  moveForward(12);

  // turn left 90 degrees
  turnLeft(90);

  // move backward for 6 inches
  moveBackward(6);

  // turn right 45 degrees
  turnRight(45);

  // move forward for 9 inches
  moveForward(9);

  // turn left 180 degrees
  turnLeft(180);

  // move backward for 3 inches
  moveBackward(3);

  // turn right 135 degrees
  turnRight(135);

  // move forward for 15 inches
  moveForward(15);

  return 0;
}