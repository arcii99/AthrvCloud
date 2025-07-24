//FormAI DATASET v1.0 Category: Robot movement control ; Style: excited
#include <stdio.h>

int main() {
  printf("Let's make this robot MOVE!!\n");
  
  // Setting up the robot's movement controls
  int goForward = 1;
  int goBackward = 0;
  int turnLeft = -1;
  int turnRight = 2;
  
  // Starting position of the robot
  int xPos = 0;
  int yPos = 0;
  
  printf("The robot is currently located at position (%d, %d)\n", xPos, yPos);
  
  // Moving the robot forward
  xPos += 5;
  printf("The robot has moved forward 5 units to position (%d, %d)\n", xPos, yPos);
  
  // Turning the robot
  int turn = turnLeft;
  if (turn == turnLeft) {
    printf("The robot has turned left\n");
  } else if (turn == turnRight) {
    printf("The robot has turned right\n");
  } else {
    printf("The robot is going straight\n");
  }
  
  // Moving the robot backward
  yPos -= 3;
  printf("The robot has moved backward 3 units to position (%d, %d)\n", xPos, yPos);
  
  // Turning the robot again
  turn = turnRight;
  if (turn == turnLeft) {
    printf("The robot has turned left\n");
  } else if (turn == turnRight) {
    printf("The robot has turned right\n");
  } else {
    printf("The robot is going straight\n");
  }
  
  // Moving the robot forward again
  xPos += 7;
  printf("The robot has moved forward 7 units to position (%d, %d)\n", xPos, yPos);
  
  // Turning the robot once more and moving it backward
  turn = turnLeft;
  if (turn == turnLeft) {
    printf("The robot has turned left\n");
  } else if (turn == turnRight) {
    printf("The robot has turned right\n");
  } else {
    printf("The robot is going straight\n");
  }
  yPos -= 6;
  printf("The robot has moved backward 6 units to position (%d, %d)\n", xPos, yPos);
  
  printf("The robot's movement has finished! Hooray!\n");
  
  return 0;
}