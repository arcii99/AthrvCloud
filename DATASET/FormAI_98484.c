//FormAI DATASET v1.0 Category: Robot movement control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Setting Up Random Seed
  srand(time(0));
  
  // Robot Position Coordinates
  int x = 0;
  int y = 0;
  
  // Movement Control Loop
  while (1) {
    // Generating Random Movement Control Command
    int command = rand() % 4;
    
    if (command == 0) { // Moving Up
      printf("Moving Up\n");
      y++;
    }
    else if (command == 1) { // Moving Down
      printf("Moving Down\n");
      y--;
    }
    else if (command == 2) { // Moving Left
      printf("Moving Left\n");
      x--;
    }
    else { // Moving Right
      printf("Moving Right\n");
      x++;
    }
    
    // Checking If Robot Reached The End Point
    if (x == 10 && y == 10) {
      printf("End Point Reached! Stopping...\n");
      break;
    }
  }
  
  return 0;
}