//FormAI DATASET v1.0 Category: Pattern printing ; Style: Ken Thompson
#include <stdio.h>

int main() {
  int rows = 6;
  for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= i; j++) {
      printf("%c", j + 64);
    }
    printf("\n");
  }
  for (int i = rows - 1; i > 0; i--) {
    for (int j = 1; j <= i; j++) {
      printf("%c", j + 64);
    }
    printf("\n");
  }
  return 0;
}