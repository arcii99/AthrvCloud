//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: invasive
#include <stdio.h>

int main() {

  int altitude = 0; // initialize the altitude to zero
  int speed = 0; // initialize the speed to zero

  // the control loop
  while (1) {

    printf("Enter a command (u/d/f/b/l/r): ");
    char input = getchar();

    // process user input
    switch(input) {
      case 'u':
        altitude++;
        printf("Ascending...\n");
        break;
      case 'd':
        altitude--;
        printf("Descending...\n");
        break;
      case 'f':
        speed++;
        printf("Speeding up...\n");
        break;
      case 'b':
        speed--;
        printf("Slowing down...\n");
        break;
      case 'l':
        printf("Turning left...\n");
        break;
      case 'r':
        printf("Turning right...\n");
        break;
      default:
        printf("Invalid command. Try again.\n");
    }

    // show the current drone status
    printf("Altitude: %d | Speed: %d\n", altitude, speed);
  }

  return 0;
}