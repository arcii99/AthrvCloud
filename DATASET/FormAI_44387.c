//FormAI DATASET v1.0 Category: Robot movement control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 10   // maximum x coordinate
#define MAX_Y 10   // maximum y coordinate
#define MAX_STEP 5 // maximum number of steps to take

// function declaration
void moveRobot(int curX, int curY);

int main() {
  srand(time(NULL)); // initialize random seed

  printf("Starting peaceful C Robot movement control program! \n");

  // generate initial robot position randomly
  int startX = rand() % MAX_X;
  int startY = rand() % MAX_Y;

  // call moveRobot function with starting position
  moveRobot(startX, startY);

  printf("Peaceful C Robot movement control program complete! \n");

  return 0;
}

void moveRobot(int curX, int curY) {
  printf("The robot is at position (%d, %d).\n", curX, curY);
  
  int steps = rand() % MAX_STEP + 1; // random number of steps to take
  
  printf("The robot will take %d steps...\n", steps);
  
  for (int i = 0; i < steps; i++) {
    int direction = rand() % 4; // random direction to move in
    
    switch (direction) {
      case 0: // move up
        if (curY > 0) {
          curY--;
        }
        break;
      case 1: // move right
        if (curX < MAX_X - 1) {
          curX++;
        }
        break;
      case 2: // move down
        if (curY < MAX_Y - 1) {
          curY++;
        }
        break;
      case 3: // move left
        if (curX > 0) {
          curX--;
        }
        break;
    }
    
    printf("Step %d: The robot has moved to position (%d, %d).\n", i+1, curX, curY);
    
    // sleep for a brief moment to simulate real movement
    usleep(500000);
  }
  
  printf("The robot has arrived at its destination. \n");
}