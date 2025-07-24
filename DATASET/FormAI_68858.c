//FormAI DATASET v1.0 Category: Pattern printing ; Style: medieval
#include <stdio.h>

int main() {
  int rows = 10;
  int cols = 10;
  int center_row = rows / 2;
  int center_col = cols / 2;
  char letter = 'C';

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      if(i == center_row) {
        printf("%c", letter);
      } else if(i < center_row) {
        if(j == 0 || j == cols - 1) {
          printf("%c", letter);
        } else if(j > center_col) {
          printf("%c", letter);
        } else {
          printf(" ");
        }
      } else {
        if(j == 0 || j == cols - 1) {
          printf("%c", letter);
        } else if(j < center_col) {
          printf("%c", letter);
        } else {
          printf(" ");
        }
      }
    }
    printf("\n");
  }

  return 0;
}