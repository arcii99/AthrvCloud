//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //initialize the random number generator

  int x = 0, y = 0; //coordinates of the vehicle
  int target_x = rand() % 10 + 1; //randomly generate a target x coordinate
  int target_y = rand() % 10 + 1; //randomly generate a target y coordinate

  printf("Remote control vehicle simulation program\n\n");

  while (x != target_x || y != target_y) { //keep looping until the target is reached
    printf("Current coordinates: (%d, %d)\n", x, y);
    printf("Enter a command (up = u, down = d, left = l, right = r): ");

    char command;
    scanf(" %c", &command); //get the user's command

    switch (command) {
      case 'u':
        y++; //move up
        break;
      case 'd':
        y--; //move down
        break;
      case 'l':
        x--; //move left
        break;
      case 'r':
        x++; //move right
        break;
      default:
        printf("Invalid command!\n");
        break;
    }

    if (x < 1 || x > 10 || y < 1 || y > 10) { //if the vehicle goes out of bounds
      printf("Out of bounds!\n");
      x = 5; //reset the vehicle's position to the center of the grid
      y = 5;
    }
  }

  printf("Congratulations, you have reached your destination!\n");

  return 0;
}