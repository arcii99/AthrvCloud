//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Welcome to the C Drone Remote Control Program!\n\n");

  // Connect to the Drone
  int drone_connected = 0;
  while (!drone_connected) {
    char response;
    printf("Are you connected to the drone? (y/n): ");
    scanf(" %c", &response);

    if (response == 'y' || response == 'Y') {
      printf("Great! Let's get started.\n");
      drone_connected = 1;
    } else if (response == 'n' || response == 'N') {
      printf("Please connect to the drone and try again.\n");
    } else {
      printf("I'm sorry, I didn't understand. Please try again.\n");
    }
  }

  // Take Off
  printf("\n\nPreparing for take off...\n");
  printf("Press 't' to take off.\n");
  char takeoff_response;
  scanf(" %c", &takeoff_response);
  while (takeoff_response != 't') {
    printf("You must press 't' to take off. Try again: ");
    scanf(" %c", &takeoff_response);
  }
  printf("\nTaking off...\n");

  // Flight Controls
  int altitude = 0;
  printf("\n\nUse WASD keys to control the drone.\n");
  printf("W: Increase Altitude\nS: Decrease Altitude\nA: Move Left\nD: Move Right\n");
  printf("Press 'q' to land.\n\n");

  while (1) {
    char input;
    printf("Enter your command: ");
    scanf(" %c", &input);

    if (input == 'w' || input == 'W') {
      altitude++;
      printf("\nAscending to altitude %d...\n", altitude);
    } else if (input == 's' || input == 'S') {
      if (altitude > 0) {
        altitude--;
        printf("\nDescending to altitude %d...\n", altitude);
      } else {
        printf("\nThe drone cannot descend below sea level. Please try something else.\n");
      }
    } else if (input == 'a' || input == 'A') {
      printf("\nMoving left...\n");  
    } else if (input == 'd' || input == 'D') {
      printf("\nMoving right...\n");  
    } else if (input == 'q' || input == 'Q') {
      printf("\nLanding the drone...");
      break;
    } else {
      printf("\nI'm sorry, I didn't understand that command. Please try again.\n");
    }
  }

  // Disconnect from the Drone
  printf("\n\nThanks for flying with us today!\n");
  printf("Would you like to disconnect from the drone? (y/n): ");

  char disconnect_response;
  scanf(" %c", &disconnect_response);
  while (1) {
    if (disconnect_response == 'y' || disconnect_response == 'Y') {
      printf("\nDisconnected from drone.\n");
      break;
    } else if (disconnect_response == 'n' || disconnect_response == 'N') {
      printf("\nThank you. Have a great day!\n");
      break;
    } else {
      printf("\nI'm sorry, I didn't understand that command. Please try again.\n");
      printf("Would you like to disconnect from the drone? (y/n): ");
      scanf(" %c", &disconnect_response);
    }
  }

  return 0;
}