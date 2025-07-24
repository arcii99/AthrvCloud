//FormAI DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>

int main() {
  printf("Hello everyone, get ready to be amazed by my C Pattern Printing program!\n\n");

  // First pattern: diagonal lines
  printf("Pattern 1:\n\n");
  int n = 6;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j || i + j == n + 1) {
        printf("* ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
  
  printf("\n---------------------------------------\n\n");

  // Second pattern: pyramid
  printf("Pattern 2:\n\n");
  int rows = 5;
  int count = 1;
  for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= rows - i; j++) {
      printf("  ");
    }
    for (int k = 1; k <= i; k++) {
      printf("%d ", count);
      count++;
    }
    printf("\n");
  }

  printf("\n---------------------------------------\n\n");

  // Third pattern: diamond
  printf("Pattern 3:\n\n");
  int size = 7;
  int mid = (size + 1) / 2;
  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++) {
      if (i <= mid) {
        if (j >= mid - i + 1 && j <= mid + i - 1) {
          printf("* ");
        } else {
          printf("  ");
        }
      } else {
        if (j >= mid - (size - i) + 1 && j <= mid + (size - i) - 1) {
          printf("* ");
        } else {
          printf("  ");
        }
      }
    }
    printf("\n");
  }

  printf("\n---------------------------------------\n\n");

  // Fourth pattern: reverse pyramid
  printf("Pattern 4:\n\n");
  int num = 5;
  for (int i = num; i >= 1; i--) {
    for (int j = 1; j <= num - i; j++) {
      printf("  ");
    }
    for (int k = 1; k <= i; k++) {
      printf("* ");
    }
    printf("\n");
  }
  
  printf("\nWow, wasn't that amazing?! Hope you enjoyed it as much as I did :)\n");
  return 0;
}