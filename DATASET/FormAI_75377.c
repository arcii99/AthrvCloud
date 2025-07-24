//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: immersive
#include <stdio.h>

int main() {
  int signal;

  printf("Welcome to the Traffic Light Controller program!\n");

  while(1) {
    printf("Please select a traffic signal to change:\n");
    printf("1. Green\n");
    printf("2. Yellow\n");
    printf("3. Red\n");
    scanf("%d", &signal);

    switch(signal) {
      case 1:
        printf("The signal is now Green!\n");
        break;
      case 2:
        printf("The signal is now Yellow!\n");
        break;
      case 3:
        printf("The signal is now Red!\n");
        break;
      default:
        printf("Invalid signal selected. Please try again.\n");
        break;
    }
  }

  return 0;
}