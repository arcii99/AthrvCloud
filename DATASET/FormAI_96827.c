//FormAI DATASET v1.0 Category: Robot movement control ; Style: all-encompassing
#include <stdio.h>

//define maximum Robot movement size
#define MAX_MOVE_SIZE 50

//create a Robot struct
struct Robot {
  int xPos;
  int yPos;
};

//create function to move robot forward
void moveForward(struct Robot *robot) {
  (*robot).yPos++;
  printf("Robot moved forward. New position: x=%d y=%d\n", (*robot).xPos, (*robot).yPos);
}

//create function to move robot backward
void moveBackward(struct Robot *robot) {
  (*robot).yPos--;
  printf("Robot moved backward. New position: x=%d y=%d\n", (*robot).xPos, (*robot).yPos);
}

//create function to move robot left
void moveLeft(struct Robot *robot) {
  (*robot).xPos--;
  printf("Robot moved left. New position: x=%d y=%d\n", (*robot).xPos, (*robot).yPos);
}

//create function to move robot right
void moveRight(struct Robot *robot) {
  (*robot).xPos++;
  printf("Robot moved right. New position: x=%d y=%d\n", (*robot).xPos, (*robot).yPos);
}

int main() {
  //create a Robot object with initial position x=0, y=0
  struct Robot myRobot = {0, 0};
  
  //create an array of Robot moves
  int moves[MAX_MOVE_SIZE] = {0, 1, 2, 3, 0, 2, 1, 3, 1};
  
  //iterate through the moves array
  for(int i = 0; i < MAX_MOVE_SIZE; i++) {
    switch(moves[i]) {
      case 0:
        //move forward
        moveForward(&myRobot);
        break;
      case 1:
        //move backward
        moveBackward(&myRobot);
        break;
      case 2:
        //move left
        moveLeft(&myRobot);
        break;
      case 3:
        //move right
        moveRight(&myRobot);
        break;
      default:
        //unsupported move, do nothing
        break;
    }
  }
  
  return 0;
}