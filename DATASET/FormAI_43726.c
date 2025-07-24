//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: calm
#include <stdio.h>

int main() {
  char command;

  printf("Welcome to the Drone Remote Control Program!\n");
  printf("Press (u) to move up\n");
  printf("Press (d) to move down\n");
  printf("Press (l) to move left\n");
  printf("Press (r) to move right\n");
  printf("Press (q) to quit\n");

  while (1) {
    printf("\nEnter a command: ");
    command = getchar();

    switch(command) {
      case 'u':
        printf("Moving up\n");
        break;
      case 'd':
        printf("Moving down\n");
        break;
      case 'l':
        printf("Moving left\n");
        break;
      case 'r':
        printf("Moving right\n");
        break;
      case 'q':
        printf("Quitting program\n");
        return 0;
      default:
        printf("Invalid command\n");
        break;
    }
    getchar(); // To remove any extra characters from the buffer
  }

  return 0;
}