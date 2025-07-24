//FormAI DATASET v1.0 Category: Smart home automation ; Style: energetic
#include <stdio.h>

int main() {
  int lightsOn = 0;
  int temperature = 70;

  printf("Welcome to your smart home!\n");

  while (1) {
    int command;
    printf("Enter a command (0=lights off, 1=lights on, 2=set temperature, 3=exit): ");
    scanf("%d", &command);

    if (command == 0) {
      lightsOn = 0;
      printf("Lights turned off.\n");
    } else if (command == 1) {
      lightsOn = 1;
      printf("Lights turned on.\n");
    } else if (command == 2) {
      printf("Enter the desired temperature: ");
      scanf("%d", &temperature);
      printf("Temperature set to %d degrees.\n", temperature);
    } else if (command == 3) {
      printf("Goodbye!\n");
      break;
    } else {
      printf("Invalid command.\n");
    }

    if (lightsOn) {
      printf("The lights are on.\n");
    } else {
      printf("The lights are off.\n");
    }

    printf("The temperature is %d degrees.\n", temperature);
  }
  
  return 0;
}