//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the C Drone Remote Control!\n");
  printf("Please enter the command to fly the drone:\n");
  char command;
  scanf("%c", &command);

  switch(command) {
    case 'u':
      printf("The drone is flying up!\n");
      break;
    case 'd':
      printf("The drone is flying down!\n");
      break;
    case 'f':
      printf("The drone is moving forward!\n");
      break;
    case 'b':
      printf("The drone is moving backward!\n");
      break;
    case 'l':
      printf("The drone is moving left!\n");
      break;
    case 'r':
      printf("The drone is moving right!\n");
      break;
    case 's':
      printf("The drone is staying still!\n");
      break;
    default:
      printf("Invalid command!\n");
      break;
  }

  return 0;
}