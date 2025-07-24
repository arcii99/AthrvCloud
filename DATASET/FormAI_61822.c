//FormAI DATASET v1.0 Category: Robot movement control ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main() {
  printf("Welcome to the C Robot Movement Control Program!\n");
  
  // initialize robot position to (0,0)
  int x = 0;
  int y = 0;
  
  // loop for user input
  while (1) {
    printf("\nPlease enter a command (F/B/L/R): ");
    char command[2];
    scanf("%s", command);
    
    // check for valid command and move robot accordingly
    if (strcmp(command, "F") == 0) {
      y++;
      printf("Robot has moved forward!\n");
    }
    else if (strcmp(command, "B") == 0) {
      y--;
      printf("Robot has moved backward!\n");
    }
    else if (strcmp(command, "L") == 0) {
      x--;
      printf("Robot has turned left!\n");
    }
    else if (strcmp(command, "R") == 0) {
      x++;
      printf("Robot has turned right!\n");
    }
    else {
      printf("Invalid command. Please try again.\n");
      continue;
    }
    
    // print current robot position
    printf("Robot's position: (%d,%d)\n", x, y);
  }
  
  return 0;
}