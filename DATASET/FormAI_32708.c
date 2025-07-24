//FormAI DATASET v1.0 Category: Robot movement control ; Style: unmistakable
#include <stdio.h>

// Function to move the robot forward
void moveForward(double distance) {
  printf("Moving forward %.2f meters\n", distance);
}

// Function to move the robot backwards
void moveBackward(double distance) {
  printf("Moving backward %.2f meters\n", distance);
}

// Function to turn the robot left
void turnLeft(double angle) {
  printf("Turning left %.2f degrees\n", angle);
}

// Function to turn the robot right
void turnRight(double angle) {
  printf("Turning right %.2f degrees\n", angle);
}

int main() {
  double distance;
  double angle;

  printf("Enter the distance you want to move the robot forward: ");
  scanf("%lf", &distance);
  moveForward(distance);

  printf("Enter the distance you want to move the robot backwards: ");
  scanf("%lf", &distance);
  moveBackward(distance);

  printf("Enter the angle you want to turn the robot left: ");
  scanf("%lf", &angle);
  turnLeft(angle);

  printf("Enter the angle you want to turn the robot right: ");
  scanf("%lf", &angle);
  turnRight(angle);

  return 0;
}