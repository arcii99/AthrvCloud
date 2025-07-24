//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: artistic
#include <stdio.h>

int main() {
  int speed = 0;
  int direction = 0;
  
  printf("Welcome to Remote Control Vehicle Simulator!\n\n");
  printf("Use WASD keys to control the vehicle. Press Q to exit.\n\n");
  
  while (1) { // Loop until user enters Q
    printf("Current speed: %d, Current direction: %d\n", speed, direction);
    
    char input = getchar();
    fflush(stdin); // Clear input buffer
    
    if (input == 'q') {
      printf("\nBye!\n");
      break;
    }
    
    switch (input) {
      case 'w':
        speed++;
        break;
      case 's':
        if (speed > 0) speed--;
        break;
      case 'a':
        direction--;
        if (direction < 0) direction += 360;
        break;
      case 'd':
        direction++;
        if (direction >= 360) direction -= 360;
        break;
      default:
        printf("Invalid input.\n");
        break;
    }
  }
  
  return 0;
}