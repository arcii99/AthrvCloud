//FormAI DATASET v1.0 Category: Robot movement control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seeding the random number generator with the current time
  
  int x = 0; // initialize x-coordinate
  int y = 0; // initialize y-coordinate
  
  printf("Starting at position (%d, %d)\n", x, y); // print starting position
  
  for (int i = 0; i < 50; i++) {
    int direction = rand() % 4; // generate random number between 0 and 3
    
    switch (direction) {
      case 0:
        x++; // move right
        printf("Moved right to (%d, %d)\n", x, y);
        break;
      case 1:
        x--; // move left
        printf("Moved left to (%d, %d)\n", x, y);
        break;
      case 2:
        y++; // move up
        printf("Moved up to (%d, %d)\n", x, y);
        break;
      case 3:
        y--; // move down
        printf("Moved down to (%d, %d)\n", x, y);
        break;
      default:
        printf("Invalid direction\n");
        break;
    }
  }
  
  printf("Final position: (%d, %d)\n", x, y); // print final position
  
  return 0;
}