//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: brave
#include <stdio.h>

int main() {
  printf("Welcome to C Drone Remote Control!\n");
  int speed = 0;
  int altitude = 0;
  int direction = 0;
  while (1) {
    printf("Current speed: %d\n", speed);
    printf("Current altitude: %d\n", altitude);
    printf("Current direction: %d\n", direction);
    printf("Enter a command (s = speed, a = altitude, d = direction): ");

    char input;
    scanf(" %c", &input);

    if (input == 's') {
      printf("Enter new speed: ");
      scanf("%d", &speed);
    } else if (input == 'a') {
      printf("Enter new altitude: ");
      scanf("%d", &altitude);
    } else if (input == 'd') {
      printf("Enter new direction: ");
      scanf("%d", &direction);
    } else {
      printf("Invalid command.\n");
    }
  }
  return 0;
}