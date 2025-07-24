//FormAI DATASET v1.0 Category: Robot movement control ; Style: satisfied
#include <stdio.h>

int main() {
  printf("Welcome to the C Robot movement control program!\n");
  printf("Press 'w' to move forward, 's' to move backward, 'a' to turn left, 'd' to turn right, and 'q' to stop.\n");
  
  char input;
  int x = 0, y = 0;
  
  while (1) {
    input = getchar();
    
    switch(input) {
      case 'w':
        y++;
        break;
      case 's':
        y--;
        break;
      case 'a':
        x--;
        break;
      case 'd':
        x++;
        break;
      case 'q':
        printf("Stopping robot...\n");
        return 0;
      default:
        printf("Invalid input. Please try again.\n");
        break;
    }
    
    printf("Current position: (%d, %d)\n", x, y);
  }
  
  return 0;
}