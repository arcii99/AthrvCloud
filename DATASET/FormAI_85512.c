//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
  int red = 0, yellow = 0, green = 0;

  while (1) {
    printf("Traffic Light Controller\n");
    printf("------------------------\n");

    // Green light
    if (red == 0 && yellow == 0 && green == 0) {
      printf("Green Light\n");
      green = 1;
      sleep(5); // Wait for 5 seconds
    }

    // Yellow light
    if (red == 0 && yellow == 0 && green == 1) {
      printf("Yellow Light\n");
      green = 0;
      yellow = 1;
      sleep(2); // Wait for 2 seconds
    }

    // Red light
    if (red == 0 && yellow == 1 && green == 0) {
      printf("Red Light\n");
      yellow = 0;
      red = 1;
      sleep(5); // Wait for 5 seconds
    }

    // Red light blinking
    if (red == 1 && yellow == 0 && green == 0) {
      printf("Red Light Blinking\n");
      red = 0;
      sleep(1); // Wait for 1 second
    }
  }

  return 0;
}