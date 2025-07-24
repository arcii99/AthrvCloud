//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the C Drone Remote Control!\n");
  printf("Initializing drone...\n");
  int droneBattery = 100;
  int droneAltitude = 0;
  char droneDirection = 'N';
  printf("Drone initialized with 100%% battery life.\n");
  printf("Please enter a command:\n");

  char input[50];
  while (fgets(input, 50, stdin)) {
    if (input[0] == 'b') {
      // Battery status
      printf("Current battery level: %d%%\n", droneBattery);
    } else if (input[0] == 'f' && droneBattery - 10 >= 0) {
      // Forward movement
      printf("Moving drone forward...\n");
      droneBattery -= 10;
      printf("Battery level reduced to %d%%\n", droneBattery);
    } else if (input[0] == 'b' && droneBattery - 10 >= 0) {
      // Backward movement
      printf("Moving drone backward...\n");
      droneBattery -= 10;
      printf("Battery level reduced to %d%%\n", droneBattery);
    } else if (input[0] == 'u' && droneBattery - 5 >= 0) {
      // Upward movement
      printf("Moving drone upward...\n");
      droneBattery -= 5;
      droneAltitude += 10;
      printf("Battery level reduced to %d%%\n", droneBattery);
      printf("Drone altitude is now %d feet\n", droneAltitude);
    } else if (input[0] == 'd' && droneBattery - 5 >= 0) {
      // Downward movement
      printf("Moving drone downward...\n");
      droneBattery -= 5;
      droneAltitude -= 10;
      printf("Battery level reduced to %d%%\n", droneBattery);
      printf("Drone altitude is now %d feet\n", droneAltitude);
    } else if (input[0] == 'l' && droneBattery - 15 >= 0) {
      // Left turn
      printf("Turning drone left...\n");
      droneBattery -= 15;
      switch (droneDirection) {
        case 'N':
          droneDirection = 'W';
          break;
        case 'E':
          droneDirection = 'N';
          break;
        case 'S':
          droneDirection = 'E';
          break;
        case 'W':
          droneDirection = 'S';
          break;
      }
      printf("Battery level reduced to %d%%\n", droneBattery);
      printf("Drone is facing %c\n", droneDirection);
    } else if (input[0] == 'r' && droneBattery - 15 >= 0) {
      // Right turn
      printf("Turning drone right...\n");
      droneBattery -= 15;
      switch (droneDirection) {
        case 'N':
          droneDirection = 'E';
          break;
        case 'E':
          droneDirection = 'S';
          break;
        case 'S':
          droneDirection = 'W';
          break;
        case 'W':
          droneDirection = 'N';
          break;
      }
      printf("Battery level reduced to %d%%\n", droneBattery);
      printf("Drone is facing %c\n", droneDirection);
    } else {
      printf("Invalid command. Please try again.\n");
    }
  }
  return 0;
}