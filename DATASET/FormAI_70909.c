//FormAI DATASET v1.0 Category: Smart home light control ; Style: Alan Touring
#include <stdio.h>

int main() {
  // Initialize variables for light status and desired state
  int light_status = 0;
  int desired_state = 0;

  // Show current light status and prompt for desired state
  printf("The light is currently %s. Enter 1 to turn it on or 0 to turn it off: ", light_status ? "on" : "off");
  scanf("%d", &desired_state);

  // Check if desired state matches current state and act accordingly
  if (light_status == desired_state) {
    printf("The light is already %s.\n", light_status ? "on" : "off");
  } else {
    light_status = desired_state;
    printf("Turning the light %s.\n", light_status ? "on" : "off");
    // Send signal to smart home device to turn light on/off
  }

  return 0;
}