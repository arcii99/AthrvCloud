//FormAI DATASET v1.0 Category: Pattern printing ; Style: complete
#include <stdio.h>

int main() {
  int n = 5;
  int mid_row = n / 2;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == 0 || i == n - 1 || j == 0 || (j == n - 1 && i <= mid_row) || (j == i - mid_row && i > mid_row)) {
        printf("* ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
  return 0;
}