//FormAI DATASET v1.0 Category: Robot movement control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int posX = 0, posY = 0;
  
  // Let's randomly generate 10 movements for the robot
  srand(time(NULL));
  
  for (int i = 0; i < 10; i++) {
    int moveX = rand() % 11 - 5; // Move between -5 and 5 on X axis
    int moveY = rand() % 11 - 5; // Move between -5 and 5 on Y axis

    // Let's check if the movement is safe, without hitting any obstacles or going out of bounds
    if (posX + moveX < 0 || posX + moveX > 100 || posY + moveY < 0 || posY + moveY > 100) {
      printf("The robot cannot move there, it is out of bounds.\n");
      continue; // Skip this iteration and generate a new random move
    }

    // Checking for obstacles
    // Let's assume there is an obstacle at (20, 20) with a width of 10 units
    if (posX + moveX >= 20 && posX + moveX <= 30 && posY + moveY >= 20 && posY + moveY <= 30) {
      printf("The robot cannot move there, there is an obstacle in the way.\n");
      continue; // Skip this iteration and generate a new random move
    }

    // If the movement is safe, update the position of the robot
    posX += moveX;
    posY += moveY;
  }

  // Print the final position of the robot
  printf("The final position of the robot is (%d, %d)\n", posX, posY);

  return 0;
}