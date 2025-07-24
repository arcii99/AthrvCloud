//FormAI DATASET v1.0 Category: Smart home light control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int timeOfDay;
  printf("Enter the time of day (in 24-hour time format): ");
  scanf("%d", &timeOfDay);

  if (timeOfDay < 0 || timeOfDay > 23) {
    printf("Invalid input. Time of day must be between 0 and 23.\n");
    return 1;
  }

  int brightness = 0;
  if (timeOfDay >= 6 && timeOfDay < 10) {
    brightness = 50;
  } else if (timeOfDay >= 10 && timeOfDay < 19) {
    brightness = 100;
  } else if (timeOfDay >= 19 && timeOfDay < 22) {
    brightness = 70;
  } else if (timeOfDay >= 22 || timeOfDay < 6) {
    brightness = 30;
  }

  printf("The current brightness should be set to %d%%\n", brightness);

  return 0;
}