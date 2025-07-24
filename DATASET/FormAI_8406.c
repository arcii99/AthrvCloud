//FormAI DATASET v1.0 Category: Robot movement control ; Style: calm
#include <stdio.h>

// Declare our movement functions
void moveForward(int distance);
void turnLeft();
void turnRight();

int main() {
  // Move forward 10 units
  moveForward(10);
  
  // Turn left
  turnLeft();
  
  // Move forward 5 units
  moveForward(5);
  
  // Turn right
  turnRight();
  
  // Move forward 3 units
  moveForward(3);
  
  // Turn left
  turnLeft();
  
  // Move forward 2 units
  moveForward(2);
  
  return 0;
}

void moveForward(int distance) {
  printf("Moving forward %d units.\n", distance);
}

void turnLeft() {
  printf("Turning left.\n");
}

void turnRight() {
  printf("Turning right.\n");
}