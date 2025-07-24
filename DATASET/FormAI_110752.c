//FormAI DATASET v1.0 Category: Smart home light control ; Style: optimized
#include <stdio.h>

// Function to change the state of the light
void change_light_state(int* light_state) {
  if (*light_state == 0) {
    *light_state = 1; // Turning on the light
  } else {
    *light_state = 0; // Turning off the light
  }
}

int main() {
  // Initializing the light state to off(0)
  int light_state = 0;

  printf("\nWelcome to Smart Home Light Control\n");

  while (1) {
    printf("\nCurrent light state: %s\n", light_state ? "ON" : "OFF");
    printf("\nPlease enter 1 to turn ON or 0 to turn OFF the light: ");

    int user_input;
    scanf("%d", &user_input); // Reading user input

    if (user_input != 1 && user_input != 0) {
      printf("\nInvalid input, please try again\n");
      continue;
    }

    if (user_input == light_state) {
      printf("\nThe light is already %s\n", light_state ? "ON" : "OFF");
    } else {
      change_light_state(&light_state); // Changing the state of the light
      printf("\nThe light is turned %s\n", light_state ? "ON" : "OFF");
    }
  }

  return 0;
}