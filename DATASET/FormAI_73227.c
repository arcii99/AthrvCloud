//FormAI DATASET v1.0 Category: Smart home light control ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIGHTS 5

int main() {
  // Define the lights as an array of booleans
  int lights[MAX_LIGHTS] = {0};

  // Prompt the user to select a light and action
  int light_select, action_select;
  while (1) {
    printf("Select a light (1-%d): ", MAX_LIGHTS);
    scanf("%d", &light_select);

    // Check that the selected light is within the array bounds
    if (light_select < 1 || light_select > MAX_LIGHTS) {
      printf("Invalid light selected.\n");
      continue;
    }

    // Prompt the user to select an action
    printf("Select an action (0=off, 1=on): ");
    scanf("%d", &action_select);

    // Check that the selected action is valid
    if (action_select != 0 && action_select != 1) {
      printf("Invalid action selected.\n");
      continue;
    }

    // Update the light status in the array
    lights[light_select - 1] = action_select;

    // Display the updated state of the lights
    printf("Lights: ");
    for (int i = 0; i < MAX_LIGHTS; i++) {
      printf("%d ", lights[i]);
    }
    printf("\n");
  }

  return 0;
}