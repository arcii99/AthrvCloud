//FormAI DATASET v1.0 Category: Pattern printing ; Style: Cyberpunk
#include <stdio.h>

int main() {
  int rows = 7;

  for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= i; j++) {
      printf("%d", j);
    }
    for (int k = i; k < rows; k++) {
      printf(" ");
    }
    for (int l = 1; l <= rows - i + 1; l++) {
      printf("0");
    }
    for (int m = rows - i; m >= 1; m--) {
      printf(" ");
    }
    for (int n = i; n >= 1; n--) {
      printf("%d", n);
    }
    printf("\n");
  }

  for (int i = 1; i <= rows - 1; i++) {
    for (int j = i; j <= rows - 1; j++) {
      printf("%d", j);
    }
    for (int k = rows - 1; k > i; k--) {
      printf(" ");
    }
    for (int l = 1; l <= i; l++) {
      printf("0");
    }
    for (int m = 1; m <= rows - 1 - i; m++) {
      printf(" ");
    }
    for (int n = rows - i; n >= i; n--) {
      printf("%d", n);
    }
    printf("\n");
  }

  return 0;
}