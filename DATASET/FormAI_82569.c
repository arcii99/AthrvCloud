//FormAI DATASET v1.0 Category: Robot movement control ; Style: lively
#include <stdio.h>

/* Function to move the robot forward */
void move_forward(int distance) {
  printf("Moving forward %d meters...\n", distance);
  // code to move the robot forward
}

/* Function to move the robot backward */
void move_backward(int distance) {
  printf("Moving backward %d meters...\n", distance);
  // code to move the robot backward
}

/* Function to turn the robot left */
void turn_left(int degrees) {
  printf("Turning left %d degrees...\n", degrees);
  // code to turn the robot left
}

/* Function to turn the robot right */
void turn_right(int degrees) {
  printf("Turning right %d degrees...\n", degrees);
  // code to turn the robot right
}

int main() {
  // move the robot forward 5 meters
  move_forward(5);
  
  // turn the robot left 90 degrees
  turn_left(90);
  
  // move the robot forward 2 meters
  move_forward(2);
  
  // turn the robot right 45 degrees
  turn_right(45);
  
  // move the robot backward 3 meters
  move_backward(3);
  
  return 0;
}