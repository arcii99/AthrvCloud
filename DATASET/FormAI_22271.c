//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: surprised
#include <stdio.h>

int main() {
  printf("Oh my! This is going to be an amazing Traffic Light Controller program!\n");

  // Initializing variables
  int red_time = 5;
  int yellow_time = 2;
  int green_time = 7;
  int current_light = 1;

  while (1) { // Loop continuously
    if (current_light == 1) {
      printf("[ RED LIGHT : STOP! ]\n\n");
      for (int i = red_time; i >= 0; i--) { // Counting down the time for red light
        printf("  Time Left: %d\n", i);
        sleep(1);
      }
      printf("\n");

      current_light = 2;

    } else if (current_light == 2) {
      printf("[ YELLOW LIGHT : SLOW DOWN ]\n\n");
      for (int i = yellow_time; i >= 0; i--) { // Counting down the time for yellow light
        printf("  Time Left: %d\n", i);
        sleep(1);
      }
      printf("\n");

      current_light = 3;

    } else if (current_light == 3) {
      printf("[ GREEN LIGHT : GO ]\n\n");
      for (int i = green_time; i >= 0; i--) { // Counting down the time for green light
        printf("  Time Left: %d\n", i);
        sleep(1);
      }
      printf("\n");

      current_light = 1;
    }
  }

  return 0;
}