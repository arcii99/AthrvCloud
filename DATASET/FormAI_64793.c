//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: inquisitive
#include <stdio.h>

int main() {
  printf("Welcome to Remote control Vehicle Simulation!\n");
  char movement;
  int x = 0, y = 0;
  
  while (1) {
    printf("\nCurrent position : (%d, %d)\n", x, y);
    printf("Enter movement commands (F/B/L/R) or Q to quit: ");
    scanf(" %c", &movement);
    
    switch (movement) {
      case 'F':
      case 'f':
        y++;
        printf("Move Forward\n");
        break;
      case 'B':
      case 'b':
        y--;
        printf("Move Backward\n");
        break;
      case 'L':
      case 'l':
        x--;
        printf("Move Left\n");
        break;
      case 'R':
      case 'r':
        x++;
        printf("Move Right\n");
        break;
      case 'Q':
      case 'q':
        printf("Quitting Remote control Vehicle Simulation. Goodbye!\n");
        return 0;
      default:
        printf("Invalid command. Please try again.\n");
    }
  }
  return 0;
}