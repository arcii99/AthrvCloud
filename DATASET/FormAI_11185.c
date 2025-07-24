//FormAI DATASET v1.0 Category: Smart home automation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// function to turn on/off lights
void turnOnOffLights(bool isOn) {
  if(isOn) {
    printf("Lights are turned ON\n");
  }
  else {
    printf("Lights are turned OFF\n");
  }
}

// function to increase/decrease temperature
void adjustTemperature(int temperature, int* currentTemp) {
  *currentTemp += temperature;
  printf("Temperature adjusted to %d\n", *currentTemp);
}

// function to open/close windows
void openCloseWindows(bool isOpen) {
  if(isOpen) {
    printf("Windows are OPEN\n");
  }
  else {
    printf("Windows are CLOSED\n");
  }
}

int main() {
  bool isLightsOn = false;
  int currentTemperature = 25;
  bool areWindowsOpen = false;

  int userChoice;

  printf("---WELCOME TO SMART HOME AUTOMATION SYSTEM---\n");

  while(true) {
    // display the options to the user
    printf("\nSelect an option:\n1. Turn On/Off Lights\n2. Adjust Temperature\n3. Open/Close Windows\n4. Exit\n");
    scanf("%d", &userChoice);

    switch(userChoice) {
      case 1:
        isLightsOn = !isLightsOn; // toggle the lights
        turnOnOffLights(isLightsOn);
        break;
      case 2:
        int temperatureChange;
        printf("Enter the temperature change (positive for increase, negative for decrease): ");
        scanf("%d", &temperatureChange);
        adjustTemperature(temperatureChange, &currentTemperature);
        break;
      case 3:
        areWindowsOpen = !areWindowsOpen; // toggle the windows
        openCloseWindows(areWindowsOpen);
        break;
      case 4:
        printf("Exiting Smart Home Automation System...\n");
        exit(0);
      default:
        printf("Invalid choice. Please enter a valid choice.\n");
        break;
    }
  }

  return 0;
}