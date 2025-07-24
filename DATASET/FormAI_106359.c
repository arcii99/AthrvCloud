//FormAI DATASET v1.0 Category: Robot movement control ; Style: enthusiastic
#include <stdio.h>

int main() {
  int robotX = 0, robotY = 0; // initialize robot position

  printf("Welcome to the Robot Movement Control Program!\n");
  printf("Enter commands: U for up, D for down, L for left, and R for right.\n");
  char command;

  while (1) {
    scanf("%c", &command); // read user input
    if (command == '\n') continue; // ignore newline character
    if (command == 'U') robotY++;
    else if (command == 'D') robotY--;
    else if (command == 'L') robotX--;
    else if (command == 'R') robotX++;
    else printf("Invalid command!\n"); // handle invalid input
    printf("Robot moved to (%d, %d)\n", robotX, robotY); // print new position
  }

  return 0;
}