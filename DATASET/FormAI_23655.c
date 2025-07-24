//FormAI DATASET v1.0 Category: Robot movement control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// define a struct for the robot
struct Robot {
  int x; // x-coordinate of the robot
  int y; // y-coordinate of the robot
  int direction; // direction of the robot (0-3)
};

// function to initialize the robot
struct Robot initializeRobot(int x, int y, int direction)
{
  struct Robot robot;
  robot.x = x;
  robot.y = y;
  robot.direction = direction;
  return robot;
}

// function to move the robot
void moveRobot(struct Robot *robot)
{
  switch (robot->direction) {
    case NORTH:
      robot->y++;
      break;
    case EAST:
      robot->x++;
      break;
    case SOUTH:
      robot->y--;
      break;
    case WEST:
      robot->x--;
      break;
  }
}

// function to turn the robot
void turnRobot(struct Robot *robot, bool clockwise)
{
  if (clockwise) {
    robot->direction = (robot->direction + 1) % 4;
  } else {
    robot->direction = (robot->direction - 1 + 4) % 4;
  }
}

int main()
{
  // initialize the robot
  struct Robot robot = initializeRobot(0, 0, EAST);

  // move the robot forward and turn it
  moveRobot(&robot);
  turnRobot(&robot, true);

  // move the robot forward again and turn it
  moveRobot(&robot);
  turnRobot(&robot, true);

  // move the robot forward again and turn it
  moveRobot(&robot);
  turnRobot(&robot, false);

  // move the robot forward and print its position
  moveRobot(&robot);
  printf("Robot position: (%d, %d)\n", robot.x, robot.y);

  return 0;
}