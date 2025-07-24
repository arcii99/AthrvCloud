//FormAI DATASET v1.0 Category: Pattern printing ; Style: puzzling
#include <stdio.h>

int main() {
  int num = 1;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < i + 1; j++) {
      printf("%d ", num);
      num += 1;
    }
    printf("\n");
  }

  num -= 1;

  for (int i = 4; i >= 0; i--) {
    for (int j = 0; j < i + 1; j++) {
      printf("%d ", num);
      num -= 1;
    }
    printf("\n");
  }

  for (int i = 5; i < 10; i++) {
    for (int j = 0; j < 10 - i; j++) {
      printf("%d ", num);
      num += 1;
    }
    printf("\n");
  }

  num -= 1;

  for (int i = 9; i >= 5; i--) {
    for (int j = 0; j < 10 - i; j++) {
      printf("%d ", num);
      num -= 1;
    }
    printf("\n");
  }

  return 0;
}