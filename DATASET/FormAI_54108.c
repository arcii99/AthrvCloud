//FormAI DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>

int main() {
  int size = 7;
  int mid = size / 2;

  for (int i = 0; i < size; i++) {
    printf("*");
  }
  printf("\n");

  for (int i = 0; i < mid; i++) {
    for (int j = 0; j < size; j++) {
      if (j == i || j == mid || j == size - i - 1) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  for (int i = mid - 1; i >= 0; i--) {
    for (int j = 0; j < size; j++) {
      if (j == i || j == mid || j == size - i - 1) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  for (int i = 0; i < size; i++) {
    printf("*");
  }
  printf("\n");

  return 0;
}