//FormAI DATASET v1.0 Category: Smart home automation ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

// Declare global state variables
bool isLightsOn = false;
bool isAlarmOn = false;
bool isGarageDoorOpen = false;

// Function to turn lights on/off
void toggleLights() {
  isLightsOn = !isLightsOn;
  if (isLightsOn) {
    printf("Lights turned on.\n");
  } else {
    printf("Lights turned off.\n");
  }
}

// Function to arm/disarm alarm
void toggleAlarm() {
  isAlarmOn = !isAlarmOn;
  if (isAlarmOn) {
    printf("Alarm armed.\n");
  } else {
    printf("Alarm disarmed.\n");
  }
}

// Function to open/close garage door
void toggleGarageDoor() {
  isGarageDoorOpen = !isGarageDoorOpen;
  if (isGarageDoorOpen) {
    printf("Garage door opened.\n");
  } else {
    printf("Garage door closed.\n");
  }
}

// Main function
int main() {
  // Display welcome message
  printf("Welcome to Smart Home Automation!\n");

  // Loop to get user input
  while (true) {
    // Display menu options
    printf("\nWhat would you like to do?\n");
    printf("1. Toggle lights\n");
    printf("2. Toggle alarm\n");
    printf("3. Toggle garage door\n");
    printf("4. Exit\n");

    // Get user input
    int option;
    scanf("%d", &option);

    // Handle user input
    switch (option) {
      case 1:
        toggleLights();
        break;
      case 2:
        toggleAlarm();
        break;
      case 3:
        toggleGarageDoor();
        break;
      case 4:
        // Exit program
        printf("Goodbye!\n");
        return 0;
      default:
        // Handle invalid input
        printf("Invalid option selected.\n");
        break;
    }
  }
}