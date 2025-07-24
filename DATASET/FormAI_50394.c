//FormAI DATASET v1.0 Category: Smart home light control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Function to turn lights on
void lights_on() {
  printf("Turning Lights On...\n");
}

// Function to turn lights off
void lights_off() {
  printf("Turning Lights Off...\n");
}

int main() {
  int input;

  printf("Welcome to Smart Home Light Control!\n");

  // Get user input
  printf("Enter '1' to turn the lights on or '0' to turn the lights off: ");
  scanf("%d", &input);

  // Check user input and call respective function
  if(input == 1) {
    lights_on();
  } else if(input == 0) {
    lights_off();
  } else {
    printf("Invalid input! Please enter '1' to turn the lights on or '0' to turn the lights off.\n");
  }

  return 0;
}