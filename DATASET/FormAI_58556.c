//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: imaginative
#include <stdio.h>

int main() {

  printf("Welcome to the C Drone Remote Control App!\n\n");

  int batteryLife = 100;
  int altitude = 0;
  int distance = 0;
  char flyingStatus = 'L';

  printf("Battery Life: %d%%\n", batteryLife);
  printf("Altitude: %d meters\n", altitude);
  printf("Distance: %d meters\n", distance);
  printf("Flying Status: Landing\n\n");

  while (1) {
    printf("Enter control command: ");
    char command = getchar();

    switch (command) {
      case 'a':
        if (altitude < 500) {
          altitude += 10;
          printf("Altitude increased to %d meters.\n", altitude);
        } else {
          printf("Cannot increase altitude any further.\n");
        }
        break;

      case 'd':
        if (distance < 1000) {
          distance += 10;
          printf("Distance increased to %d meters.\n", distance);
        } else {
          printf("Cannot increase distance any further.\n");
        }
        break;

      case 'w':
        if (batteryLife > 0 && flyingStatus == 'L') {
          batteryLife--;
          printf("Battery Life: %d%%\n", batteryLife);

          if (batteryLife == 0) {
            printf("Drone is out of power.\n");
            flyingStatus = 'D';
          } else {
            altitude += 10;
            printf("Drone is taking off. Altitude increased to %d meters.\n", altitude);
            flyingStatus = 'F';
          }
        } else if (flyingStatus == 'F') {
          altitude += 10;

          if (altitude >= 500) {
            printf("Drone has reached its maximum altitude.\n");
            altitude = 500;
          } else {
            printf("Drone is flying. Altitude increased to %d meters.\n", altitude);
          }
        } else {
          printf("Drone cannot take off or increase altitude any further.\n");
        }
        break;

      case 's':
        if (flyingStatus == 'F') {
          altitude -= 10;

          if (altitude <= 0) {
            printf("Drone has landed.\n");
            altitude = 0;
            flyingStatus = 'L';
          } else {
            printf("Drone is descending. Altitude decreased to %d meters.\n", altitude);
          }
        } else {
          printf("Drone cannot descend any further.\n");
        }
        break;

      case 'x':
        printf("Drone Emergency Landing...\n");
        altitude = 0;
        flyingStatus = 'L';
        break;

      case 'q':
        printf("Shutting down Drone Remote Control App...\n");
        return 0;

      default:
        printf("Invalid command - please enter valid control command.\n");
        break;
    }

    // Clear input buffer
    while ((getchar()) != '\n');
  }

  return 0;
}