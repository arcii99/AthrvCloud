//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char command[100];
  char drone_status[20] = "off";
  int altitude = 0;
  int speed = 0;
  
  printf("Welcome to the Drone Remote Control Program!\n");
  printf("To turn on the drone, type 'on'.\n");
  printf("> ");
  
  fgets(command, 100, stdin);
  
  if (strcmp(command, "on\n") == 0) {
    printf("Drone is now on.\n");
    strcpy(drone_status, "on");
  } else {
    printf("Invalid command.\n");
    exit(0);
  }
  
  while (1) {
    printf("What would you like to do? Type 'help' for a list of commands.\n");
    printf("> ");
    
    fgets(command, 100, stdin);
    
    if (strcmp(command, "help\n") == 0) {
      printf("List of commands:\n");
      printf("'status' - check the drone's status\n");
      printf("'up' - increase the altitude\n");
      printf("'down' - decrease the altitude\n");
      printf("'forward' - increase the speed\n");
      printf("'backward' - decrease the speed\n");
      printf("'off' - turn off the drone\n");
    } else if (strcmp(command, "status\n") == 0) {
      printf("Drone status: %s\n", drone_status);
      printf("Altitude: %d\n", altitude);
      printf("Speed: %d\n", speed);
    } else if (strcmp(command, "up\n") == 0) {
      if (altitude < 100) {
        altitude += 10;
        printf("Altitude increased to %d.\n", altitude);
      } else {
        printf("Maximum altitude reached.\n");
      }
    } else if (strcmp(command, "down\n") == 0) {
      if (altitude > 0) {
        altitude -= 10;
        printf("Altitude decreased to %d.\n", altitude);
      } else {
        printf("Minimum altitude reached.\n");
      }
    } else if (strcmp(command, "forward\n") == 0) {
      if (speed < 100) {
        speed += 10;
        printf("Speed increased to %d.\n", speed);
      } else {
        printf("Maximum speed reached.\n");
      }
    } else if (strcmp(command, "backward\n") == 0) {
      if (speed > 0) {
        speed -= 10;
        printf("Speed decreased to %d.\n", speed);
      } else {
        printf("Minimum speed reached.\n");
      }
    } else if (strcmp(command, "off\n") == 0) {
      printf("Drone is now off.\n");
      strcpy(drone_status, "off");
      altitude = 0;
      speed = 0;
      exit(0);
    } else {
      printf("Invalid command.\n");
    }
  }
  
  return 0;
}