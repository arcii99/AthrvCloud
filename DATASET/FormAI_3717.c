//FormAI DATASET v1.0 Category: Robot movement control ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to move forward
void moveForward(int distance) {
  printf("Moving forward %d meters.\n", distance);
}

// Function to rotate left
void rotateLeft(int degrees) {
  printf("Rotating left %d degrees.\n", degrees);
}

// Function to rotate right
void rotateRight(int degrees) {
  printf("Rotating right %d degrees.\n", degrees);
}

// Function to move backward
void moveBackward(int distance) {
  printf("Moving backward %d meters.\n", distance);
}

// Main function
int main() {
  printf("*** Robot Movement Control ***\n\n");

  // Move forward 5 meters
  moveForward(5);

  // Rotate left 90 degrees
  rotateLeft(90);

  // Move forward 3 meters
  moveForward(3);

  // Rotate right 45 degrees
  rotateRight(45);

  // Move backward 2 meters
  moveBackward(2);

  // Rotate left 30 degrees
  rotateLeft(30);

  // Move forward 4 meters
  moveForward(4);

  return 0;
}