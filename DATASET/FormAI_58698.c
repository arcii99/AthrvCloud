//FormAI DATASET v1.0 Category: Robot movement control ; Style: scalable
#include <stdio.h>

#define FORWARD 1
#define BACKWARD -1
#define LEFT 2
#define RIGHT -2

int robot_x = 0;
int robot_y = 0;

void moveRobot(int direction, int distance) {
  switch(direction) {
    case FORWARD:
      robot_y += distance; // move robot forward along y-axis
      break;
    case BACKWARD:
      robot_y -= distance; // move robot backward along y-axis
      break;
    case LEFT:
      robot_x -= distance; // move robot left along x-axis
      break;
    case RIGHT:
      robot_x += distance; // move robot right along x-axis
      break;
    default:
      printf("Invalid direction input\n");
      break;
  }
}

int main() {
  int input_direction, input_distance;
  printf("Please input the robot's movement (direction and distance): ");

  while(scanf("%d %d", &input_direction, &input_distance) == 2) {
    moveRobot(input_direction, input_distance);
    printf("The robot's current position is (%d,%d)\n", robot_x, robot_y);
    printf("Please input the robot's next movement (direction and distance): ");
  }

  printf("Program exited successfully\n");
  return 0;
}