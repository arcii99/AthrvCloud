//FormAI DATASET v1.0 Category: Robot movement control ; Style: Linus Torvalds
#include <stdio.h>

int main() {
  int x = 0;
  int y = 0;
  char direction = 'N';

  printf("Robot movement control program\n");
  printf("Type a direction to move the robot (N, E, S, W):\n");

  while(1) {
    scanf("%c", &direction);
    getchar(); // removes the extra newline character from the input buffer

    switch(direction) {
      case 'N':
        y++;
        printf("Moved North, current position: (%d, %d)\n", x, y);
        break;
      case 'E':
        x++;
        printf("Moved East, current position: (%d, %d)\n", x, y);
        break;
      case 'S':
        y--;
        printf("Moved South, current position: (%d, %d)\n", x, y);
        break;
      case 'W':
        x--;
        printf("Moved West, current position: (%d, %d)\n", x, y);
        break;
      default:
        printf("Invalid input, try again.\n");
    }

    printf("Type another direction to move the robot (N, E, S, W):\n");
  }

  return 0;
}