//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: invasive
#include <stdio.h>

int main() {
  // Initializing variables
  int batteryLife = 100;
  int distanceFromHome = 0;
  int currentAltitude = 0;

  // Printing welcome message
  printf("Welcome to the C Drone Remote Control Program!\n");

  // Loop for continuous control
  while (1) {
    // Printing current status
    printf("--------------------\n");
    printf("Battery Life: %d%%\n", batteryLife);
    printf("Distance From Home: %d meters\n", distanceFromHome);
    printf("Current Altitude: %d meters\n", currentAltitude);
    printf("--------------------\n");

    // Getting user input
    printf("Enter command (F)orward, (B)ackward, (U)p, (D)own, (L)eft, (R)ight, (C)harge:\n");
    char command = getchar();

    // Handling user command
    switch (command) {
      case 'F':
        distanceFromHome += 10;
        batteryLife--;
        printf("Moving drone forward...\n");
        break;
      case 'B':
        distanceFromHome -= 10;
        batteryLife--;
        printf("Moving drone backward...\n");
        break;
      case 'U':
        currentAltitude += 5;
        batteryLife--;
        printf("Moving drone up...\n");
        break;
      case 'D':
        if (currentAltitude >= 5) {
          currentAltitude -= 5;
          batteryLife--;
          printf("Moving drone down...\n");
        } else {
          printf("Error: Cannot move down. Drone is at minimum altitude.\n");
        }
        break;
      case 'L':
        distanceFromHome -= 5;
        batteryLife--;
        printf("Moving drone left...\n");
        break;
      case 'R':
        distanceFromHome += 5;
        batteryLife--;
        printf("Moving drone right...\n");
        break;
      case 'C':
        batteryLife = 100;
        printf("Charging drone...\n");
        break;
      default:
        printf("Error: Invalid command.\n");
    }

    // Checking battery life
    if (batteryLife <= 0) {
      printf("Error: Drone battery depleted.\n");
      break;
    }
  }

  // Printing goodbye message
  printf("Thank you for using the C Drone Remote Control Program!\n");

  return 0;
}