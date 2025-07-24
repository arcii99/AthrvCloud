//FormAI DATASET v1.0 Category: Robot movement control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int num_moves = 10;
  int x_pos = 0;
  int y_pos = 0;
  printf("Starting at position (%d, %d)\n", x_pos, y_pos);
  for(int i=1; i<=num_moves; i++) {
    int move_direction = rand() % 4;  // 0: up, 1: right, 2: down, 3: left
    switch(move_direction) {
      case 0:
        y_pos++;
        printf("Move #%d: Moving up to position (%d, %d)\n", i, x_pos, y_pos);
        break;
      case 1:
        x_pos++;
        printf("Move #%d: Moving right to position (%d, %d)\n", i, x_pos, y_pos);
        break;
      case 2:
        y_pos--;
        printf("Move #%d: Moving down to position (%d, %d)\n", i, x_pos, y_pos);
        break;
      case 3:
        x_pos--;
        printf("Move #%d: Moving left to position (%d, %d)\n", i, x_pos, y_pos);
        break;
    }
  }
  printf("Finished at position (%d, %d)\n", x_pos, y_pos);
  return 0;
}