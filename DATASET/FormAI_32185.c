//FormAI DATASET v1.0 Category: Smart home automation ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main() {
  char command[50];
  int lights_on = 0;
  int temperature = 70;

  printf("Welcome to your smart home!\n");

  while(1) {
    printf("\nEnter command: ");
    fgets(command, 50, stdin);
    strtok(command, "\n");

    if(strcmp(command, "lights on") == 0) {
      if(lights_on == 1) {
        printf("Lights are already on.\n");
      }
      else {
        lights_on = 1;
        printf("Turning lights on.\n");
      }
    }
    else if(strcmp(command, "lights off") == 0) {
      if(lights_on == 0) {
        printf("Lights are already off.\n");
      }
      else {
        lights_on = 0;
        printf("Turning lights off.\n");
      }
    }
    else if(strncmp(command, "set temperature ", 16) == 0) {
      temperature = atoi(command + 16);
      printf("Setting temperature to %d degrees Fahrenheit.\n", temperature);
    }
    else if(strcmp(command, "exit") == 0) {
      printf("Goodbye!\n");
      break;
    }
    else {
      printf("Invalid command. Please try again.\n");
    }
  }

  return 0;
}