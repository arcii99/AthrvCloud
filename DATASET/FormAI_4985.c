//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the mind-bending C Drone Remote Control program!\n");

  // Initializing drone variables
  int altitude = 0;
  int speed = 0;
  int direction = 0;

  while (1) {
    // User input for controlling the drone
    printf("\nEnter a command to control the drone: ");
    char command = getchar();

    // Switch case for executing user commands
    switch (command) {
      case 'u':
        printf("\nDrone is moving up!\n");
        altitude++;
        break;
        
      case 'd':
        printf("\nDrone is moving down!\n");
        altitude--;
        break;
        
      case 'f':
        printf("\nDrone is moving forward!\n");
        speed++;
        break;
        
      case 'b':
        printf("\nDrone is moving backward!\n");
        speed--;
        break;
        
      case 'l':
        printf("\nDrone is turning left!\n");
        direction--;
        break;
        
      case 'r':
        printf("\nDrone is turning right!\n");
        direction++;
        break;

      default:
        printf("\nInvalid command!\n");
        break;
    }

    // Drone status display
    printf("\nDrone Status:");
    printf("\nAltitude: %d meters", altitude);
    printf("\nSpeed: %d km/h", speed);
    printf("\nDirection: %d degrees\n", direction);
  }

  return 0;
}