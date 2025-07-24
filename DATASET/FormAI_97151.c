//FormAI DATASET v1.0 Category: Smart home automation ; Style: multivariable
#include <stdio.h>

// Declare variables for home devices
int lights = 0;
int temperature = 0;
int security = 0;

// Function to turn on/off lights
void toggleLights(int option) {
  if(option == 1) {
    lights = 1;
    printf("Lights turned on!\n");
  } else if(option == 0) {
    lights = 0;
    printf("Lights turned off!\n");
  } else {
    printf("Invalid input!\n");
  }
}

// Function to control temperature
void setTemperature(int value) {
  temperature = value;
  printf("Temperature set to %d degrees Celsius\n", value);
}

// Function to enable/disable security mode
void toggleSecurity(int option) {
  if(option == 1) {
    security = 1;
    printf("Security mode enabled!\n");
  } else if(option == 0) {
    security = 0;
    printf("Security mode disabled!\n");
  } else {
    printf("Invalid input!\n");
  }
}

int main() {
  int choice, option, value;

  // Menu prompt for home automation
  do {
    printf("\nHome Automation Menu\n");
    printf("1. Control Lights\n");
    printf("2. Control Temperature\n");
    printf("3. Toggle Security Mode\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\n1. Turn on lights\n");
        printf("2. Turn off lights\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        toggleLights(option);
        break;

      case 2:
        printf("Enter temperature value: ");
        scanf("%d", &value);
        setTemperature(value);
        break;

      case 3:
        printf("\n1. Enable security mode\n");
        printf("2. Disable security mode\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        toggleSecurity(option);
        break;

      case 4:
        printf("\nGoodbye!\n");
        break;

      default:
        printf("\nInvalid choice!\n");
    }
  } while(choice != 4);

  return 0;
}