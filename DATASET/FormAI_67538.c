//FormAI DATASET v1.0 Category: Robot movement control ; Style: Cryptic
#include <stdio.h>
#include <string.h>

int main() {
  int x = 0;
  int y = 0;
  char direction[15];
  
  printf("Enter a direction to move (up, down, left, or right):\n");
  scanf("%s", direction);
  
  if (strcmp(direction, "up") == 0) {
    printf("Move up!\n");
    y++;
  } else if (strcmp(direction, "down") == 0) {
    printf("Move down!\n");
    y--;
  } else if (strcmp(direction, "left") == 0) {
    printf("Move left!\n");
    x--;
  } else if (strcmp(direction, "right") == 0) {
    printf("Move right!\n");
    x++;
  } else {
    printf("Invalid direction. Try again.\n");
  }
  
  printf("New position: (%d, %d)\n", x, y);
  
  return 0;
}