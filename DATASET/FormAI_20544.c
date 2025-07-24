//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: cheerful
#include <stdio.h>

int main() {

  // Welcome message
  printf("Welcome to the Remote Control Vehicle Simulation Program!\n");

  // Variables for vehicle characteristics
  int speed = 0;
  int battery = 100;
  char direction = 'n';

  // Main program loop
  while (1) {
    // Print status
    printf("Speed: %d\n", speed);
    printf("Battery level: %d\n", battery);
    printf("Direction: %c\n", direction);

    // Take user input
    char input = getchar();

    // Respond to user input
    switch (input) {
      case 's':
        // Speed up
        if (speed < 10) {
          speed++;
        }
        break;
      case 'b':
        // Brake
        speed = 0;
        break;
      case 'l':
        // Turn left
        direction = 'l';
        break;
      case 'r':
        // Turn right
        direction = 'r';
        break;
      case 'e':
        // Exit program
        printf("Goodbye!\n");
        return 0;
      default:
        // Invalid input
        printf("Invalid input! Please try again.\n");
        break;
    }

    // Drain battery
    battery -= speed;

    // Check battery status
    if (battery <= 0) {
      printf("Battery drained! Please charge the vehicle.\n");
      break;
    }
  }

  return 0;
}