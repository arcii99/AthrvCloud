//FormAI DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>
#include <stdbool.h>

// Simple function to toggle a light on or off
void toggle_light(bool *state) {
  *state = !(*state);
  printf("Light has been turned %s.\n", *state ? "on" : "off");
}

int main() {
  // Imagine we have four lights in our home
  bool light1 = false;
  bool light2 = false;
  bool light3 = false;
  bool light4 = false;

  // Handle user input
  int input;
  printf("Enter the number of the light you want to control (1-4): ");
  scanf("%d", &input);

  switch(input) {
    case 1:
      toggle_light(&light1);
      break;
    case 2:
      toggle_light(&light2);
      break;
    case 3:
      toggle_light(&light3);
      break;
    case 4:
      toggle_light(&light4);
      break;
    default:
      printf("Invalid input. Please enter a number between 1-4.\n");
  }

  return 0;
}