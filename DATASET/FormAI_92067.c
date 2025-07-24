//FormAI DATASET v1.0 Category: Smart home light control ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int time, choice;
  char mode[10], auto_mode[] = "auto", manual_mode[] = "manual";

  printf("Welcome to Smart Home Light Control System!\n");
  printf("Enter the current time in hours (0-23): ");
  scanf("%d", &time);

  if (time >= 0 && time <= 11) {
    printf("Good morning! ");
  } else if (time >= 12 && time <= 17) {
    printf("Good afternoon! ");
  } else if (time >= 18 && time <= 23) {
    printf("Good evening! ");
  } else {
    printf("Invalid input! ");
    exit(EXIT_FAILURE);
  }

  printf("Enter the current mode ('auto' or 'manual'): ");
  scanf("%s", mode);

  if (strcmp(mode, auto_mode) == 0) {
    printf("Auto mode is currently active.\n");
    printf("The lights will turn on automatically when it gets dark outside.\n");
  } else if (strcmp(mode, manual_mode) == 0) {
    printf("Manual mode is currently active.\n");
    printf("Do you want to turn on or off the lights? (1 for on, 0 for off): ");
    scanf("%d", &choice);

    if (choice == 1) {
      printf("The lights are turned on.\n");
    } else if (choice == 0) {
      printf("The lights are turned off.\n");
    } else {
      printf("Invalid choice! ");
      exit(EXIT_FAILURE);
    }
  } else {
    printf("Invalid input! ");
    exit(EXIT_FAILURE);
  }

  return 0;
}