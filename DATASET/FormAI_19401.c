//FormAI DATASET v1.0 Category: Robot movement control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define Robot Movement control states
typedef enum {
  STOP,
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
} RobotMovement;

// Define Robot struct
typedef struct {
  RobotMovement movement;  // Movement state of the robot
  int x, y;                // Coordinates of the robot
} Robot;

// Function to move the robot based on its current movement state
void move_robot(Robot *robot) {
  switch(robot->movement) {
    case STOP:
      printf("Robot stopped at (%d, %d).\n", robot->x, robot->y);
      break;
    case FORWARD:
      robot->y++;
      printf("Robot moved forward to (%d, %d).\n", robot->x, robot->y);
      break;
    case BACKWARD:
      robot->y--;
      printf("Robot moved backward to (%d, %d).\n", robot->x, robot->y);
      break;
    case LEFT:
      robot->x--;
      printf("Robot moved left to (%d, %d).\n", robot->x, robot->y);
      break;
    case RIGHT:
      robot->x++;
      printf("Robot moved right to (%d, %d).\n", robot->x, robot->y);
      break;
    default:
      printf("Invalid movement state!\n");
      break;
  }
}

int main() {
  // Create a new Robot object
  Robot robot = {STOP, 0, 0};

  // Move the robot forward 5 units
  robot.movement = FORWARD;
  for(int i = 0; i < 5; i++) {
    move_robot(&robot);
  }

  // Move the robot backward 3 units
  robot.movement = BACKWARD;
  for(int i = 0; i < 3; i++) {
    move_robot(&robot);
  }

  // Move the robot left 2 units
  robot.movement = LEFT;
  for(int i = 0; i < 2; i++) {
    move_robot(&robot);
  }

  // Move the robot right 4 units
  robot.movement = RIGHT;
  for(int i = 0; i < 4; i++) {
    move_robot(&robot);
  }

  // Stop the robot
  robot.movement = STOP;
  move_robot(&robot);

  return 0;
}