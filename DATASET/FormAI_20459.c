//FormAI DATASET v1.0 Category: Smart home automation ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

int main() {
  int temp = 0;
  char command[20];
  char device[10];
  char state[10];

  printf("Welcome to your Smart Home! What would you like to do?\n");

  while (1) {
    printf("> ");
    scanf("%s %[^\n]", command, device);

    if (strcmp(command, "check") == 0) {
      // Check the state of the device
      printf("The %s is currently %s.\n", device, state);
    } else if (strcmp(command, "change") == 0) {
      // Change the state of the device
      scanf("%s", state);
      
      if (strcmp(device, "thermostat") == 0) {
        temp = atoi(state);

        if (temp >= 60 && temp <= 80) {
          printf("Setting thermostat to %d degrees.\n", temp);
        } else {
          printf("Invalid temperature. Please enter a temperature between 60 and 80 degrees.\n");
        }
      } else if (strcmp(device, "lights") == 0) {
        if (strcmp(state, "on") == 0 || strcmp(state, "off") == 0) {
          printf("%s the lights.\n", state);
        } else {
          printf("Invalid state. Please enter either 'on' or 'off'.\n");
        }
      } else {
        printf("Invalid device. Please try again.\n");
      }
    } else if (strcmp(command, "exit") == 0) {
      printf("Goodbye!\n");
      return 0;
    } else {
      printf("Invalid command. Please try again.\n");
    }
  }
}