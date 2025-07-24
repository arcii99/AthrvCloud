//FormAI DATASET v1.0 Category: Robot movement control ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Constants for movement directions
#define UP 'W'
#define DOWN 'S'
#define LEFT 'A'
#define RIGHT 'D'
#define STOP ' '

// Function to handle robot movement
void move_robot(char direction) {
  switch(direction) {
    case UP:
      printf("Moving the robot up...\n");
      break;
    case DOWN:
      printf("Moving the robot down...\n");
      break;
    case LEFT:
      printf("Moving the robot left...\n");
      break;
    case RIGHT:
      printf("Moving the robot right...\n");
      break;
    case STOP:
      printf("Stopping the robot...\n");
      break;
    default:
      printf("Invalid direction entered\n");
  }
}

int main() {
  char command; // Variable to store user input

  printf("Welcome to the robot movement program!\n");
  printf("Commands:\nW - Move up\nS - Move down\nA - Move left\nD - Move right\nSPACE - Stop\n");

  while(1) { // Infinite loop for continuous movement
    printf("Enter a command: ");
    scanf(" %c", &command);

    move_robot(command);
  }

  return 0;
}