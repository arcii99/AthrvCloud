//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: dynamic
#include <stdio.h>

int main(void) {
  char option;
  int speed = 0;
  while (option != 'x') {
    printf("Enter an option (a = increase speed, b = decrease speed, x = exit): ");
    scanf(" %c", &option);
    switch(option) {
      case 'a':
        if (speed < 10) {
          speed++;
          printf("Speed increased to %d\n", speed);
        } else {
          printf("Maximum speed already reached!\n");
        }
        break;
      case 'b':
        if (speed > 0) {
          speed--;
          printf("Speed decreased to %d\n", speed);
        } else {
          printf("Minimum speed already reached!\n");
        }
        break;
      case 'x':
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid option, please try again.\n");
        break;
    }
  }
  return 0;
}