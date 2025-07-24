//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complex
#include <stdio.h>

void move(int n, char A, char B, char C) {
  if (n == 1) {
    printf("%c -> %c\n", A, C);
  } else {
    move(n - 1, A, C, B);
    printf("%c -> %c\n", A, C);
    move(n - 1, B, A, C);
  }
}

int main() {
  int n;

  printf("Enter the number of disks: ");
  scanf("%d", &n);

  if (n < 1) {
    printf("Number of disks should be greater than or equal to 1\n");
    return 0;
  }

  printf("Here are the steps to solve the Tower of Hanoi problem with %d disks:\n", n);

  move(n, 'A', 'B', 'C');

  return 0;
}