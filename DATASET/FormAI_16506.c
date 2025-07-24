//FormAI DATASET v1.0 Category: Robot movement control ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
  int x = 0, y = 0;
  char movement;

  printf("Start position: (%d, %d)\n", x, y);

  while (1) {
    printf("Enter movement command (U for up, D for down, L for left, R for right): ");
    scanf(" %c", &movement);

    if (movement == 'U') {
      y++;
    }
    else if (movement == 'D') {
      y--;
    }
    else if (movement == 'L') {
      x--;
    }
    else if (movement == 'R') {
      x++;
    }
    else {
      printf("Invalid movement command! Try again.\n");
      continue;
    }

    printf("Position after movement: (%d, %d)\n", x, y);
  }

  return 0;
}