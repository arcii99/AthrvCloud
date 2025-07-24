//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: introspective
#include <stdio.h>

int main() {
  int altitude = 0;
  int direction = 0;
  
  printf("Welcome to Introspective Drone Remote Control Program!\n");
  printf("Use the arrow keys to adjust altitude and direction.\n");
  
  while (1) {
    int input = getchar(); // Get user input
    
    if (input == 27) { // Check for arrow key code start
      getchar(); // Discard next character
      
      switch(getchar()) { // Check for arrow key direction code
        case 65: // Up arrow
          altitude++;
          printf("Ascending to altitude %d...\n", altitude);
          break;
        case 66: // Down arrow
          altitude--;
          printf("Descending to altitude %d...\n", altitude);
          break;
        case 67: // Right arrow
          direction++;
          printf("Turning right to direction %d...\n", direction);
          break;
        case 68: // Left arrow
          direction--;
          printf("Turning left to direction %d...\n", direction);
          break;
        default:
          printf("Invalid input.\n");
          break;
      }
    }
  }
  
  return 0;
}