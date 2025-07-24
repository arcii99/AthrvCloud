//FormAI DATASET v1.0 Category: Pattern printing ; Style: active
#include <stdio.h>

int main() {
  printf("Creating a unique C pattern:\n");

  // Using nested for loops to print the pattern
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < i; j++) {
      printf("C");
    }
    printf("\n");
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 9; j++) {
      if (i == 0 || i == 4 || j == 0 || j == 8)
        printf("C");
      else
        printf(" ");
    }
    printf("\n");
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10 - i; j++) {
      printf(" ");
    }
    for (int j = 0; j < i; j++) {
      printf("C");
    }
    printf("\n");
  }

  return 0;
}