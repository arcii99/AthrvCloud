//FormAI DATASET v1.0 Category: Robot movement control ; Style: artistic
/* 
   This program controls the movement of a robot that can move forward, backward, turn left and turn right.
   The robot is being controlled by using a simple joystick interface.

   The joystick interface returns 4 different values based on it's position.
   when it's set to 0, the joystick is placed on the left, and the robot needs to turn left.
   when it's set to 1, the joystick is placed on the right, and the robot needs to turn right.
   when it's set to 2, the joystick is placed on the top, and the robot needs to move forward.
   when it's set to 3, the joystick is placed on the bottom, and the robot needs to move backward.
   
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define FORWARD 2
#define BACKWARD 3
#define LEFT 0
#define RIGHT 1

// This function generates a random number between 1 and 10
int randomNumber() {
  return rand() % 10 + 1;
}

int main(void) {
  int joystickPosition;
  int robotPosition[] = {0, 0};

  srand(time(NULL));
  printf("Starting robot movement controller...\n\n");

  while(1) {
    joystickPosition = randomNumber() % 4;
    switch(joystickPosition) {
      case FORWARD:
        robotPosition[1]++;
        printf("Moving FORWARD: (%d, %d)\n", robotPosition[0], robotPosition[1]);
        break;

      case BACKWARD:
        robotPosition[1]--;
        printf("Moving BACKWARD: (%d, %d)\n", robotPosition[0], robotPosition[1]);
        break;

      case LEFT:
        robotPosition[0]--;
        printf("Turning LEFT: (%d, %d)\n", robotPosition[0], robotPosition[1]);
        break;

      case RIGHT:
        robotPosition[0]++;
        printf("Turning RIGHT: (%d, %d)\n", robotPosition[0], robotPosition[1]);
        break;
    }
    usleep(800000); // delay to simulate robot movement
    system("clear"); // clears output so only one line is displayed
    if (robotPosition[0] == -10 || robotPosition[0] == 10 || robotPosition[1] == -10 || robotPosition[1] == 10) {
      printf("ERROR: Robot has reached the end of it's movement area!\n");
      break; // Kills program if it reaches the limit movement area
    }
  }

  return 0;
}