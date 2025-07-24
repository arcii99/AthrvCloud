//FormAI DATASET v1.0 Category: Robot movement control ; Style: innovative
#include <stdio.h>

int main() {
  int x = 0, y = 0;
  printf("Starting position: (%d, %d)\n", x, y);

  char input[10];
  while(1) {
    printf("Enter a direction (u/d/l/r): ");
    fgets(input, 10, stdin);

    if(input[0] == 'u') {
      y += 1;
      printf("Current position: (%d, %d)\n", x, y);
    }
    else if(input[0] == 'd') {
      y -= 1;
      printf("Current position: (%d, %d)\n", x, y);
    }
    else if(input[0] == 'l') {
      x -= 1;
      printf("Current position: (%d, %d)\n", x, y);
    }
    else if(input[0] == 'r') {
      x += 1;
      printf("Current position: (%d, %d)\n", x, y);
    }
    else {
      printf("Invalid direction\n");
    }
  }

  return 0;
}