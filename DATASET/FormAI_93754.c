//FormAI DATASET v1.0 Category: Smart home light control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// function to turn the lights ON or OFF
void lightControl(bool status) {
  if(status == true) {
    printf("Lights turned ON\n");
  } else {
    printf("Lights turned OFF\n");
  }
}

int main() {
  char input[10];
  bool isOn = false;

  // loop to take input from the user
  while(true) {
    printf("Enter 'on' to turn the lights on or 'off' to turn them off: ");
    fgets(input, 10, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character

    // check user input and control the lights
    if(strcmp(input, "on") == 0) {
      if(isOn == false) {
        lightControl(true);
        isOn = true;
      } else {
        printf("Lights are already on\n");
      }
    } else if(strcmp(input, "off") == 0) {
      if(isOn == true) {
        lightControl(false);
        isOn = false;
      } else {
        printf("Lights are already off\n");
      }
    } else {
      printf("Invalid input. Try again.\n");
    }
  }

  return 0;
}