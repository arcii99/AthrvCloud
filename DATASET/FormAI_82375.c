//FormAI DATASET v1.0 Category: Robot movement control ; Style: ephemeral
#include <stdio.h>

int main() {
  // Initializing variables
  int x_axis = 0, y_axis = 0, speed = 10;
  char direction = 'N';
  
  // Starting the robot
  printf("Starting position: (%d, %d)\n", x_axis, y_axis);
  
  // Looping until the robot reaches a specific point
  while (x_axis != 100 || y_axis != 100) {
    if (direction == 'N') {
      // Moving towards north
      y_axis += speed;
      printf("Moving towards %c. Position: (%d, %d)\n", direction, x_axis, y_axis);
      
      // Checking if the robot has reached the end of the axis
      if (y_axis == 200) {
        printf("Cannot move further towards %c\n", direction);
        break;
      }
    } else if (direction == 'E') {
      // Moving towards east
      x_axis += speed;
      printf("Moving towards %c. Position: (%d, %d)\n", direction, x_axis, y_axis);
      
      // Checking if the robot has reached the end of the axis
      if (x_axis == 200) {
        printf("Cannot move further towards %c\n", direction);
        break;
      }
    } else if (direction == 'S') {
      // Moving towards south
      y_axis -= speed;
      printf("Moving towards %c. Position: (%d, %d)\n", direction, x_axis, y_axis);
      
      // Checking if the robot has reached the end of the axis
      if (y_axis == 0) {
        printf("Cannot move further towards %c\n", direction);
        break;
      }
    } else if (direction == 'W') {
      // Moving towards west
      x_axis -= speed;
      printf("Moving towards %c. Position: (%d, %d)\n", direction, x_axis, y_axis);
      
      // Checking if the robot has reached the end of the axis
      if (x_axis == 0) {
        printf("Cannot move further towards %c\n", direction);
        break;
      }
    }
    
    // Updating the direction of the robot
    if (x_axis == 50 && y_axis == 50) {
      direction = 'E';
      printf("Updating direction to %c\n", direction);
    } else if (x_axis == 100 && y_axis == 100) {
      direction = 'S';
      printf("Updating direction to %c\n", direction);
    }
  }
  
  // Stopping the robot
  printf("Stopping position: (%d, %d)\n", x_axis, y_axis);
  
  return 0;
}