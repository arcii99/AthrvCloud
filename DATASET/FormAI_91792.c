//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: safe
#include <stdio.h>

void move(int count, char source, char target, char spare) {
  if (count != 0) {
    // move count - 1 disks from source to spare, so they are out of the way
    move(count - 1, source, spare, target);

    // move the nth disk from source to target
    printf("Move disk %d from %c to %c\n", count, source, target);

    // move the count - 1 disks that we left on spare onto target
    move(count - 1, spare, target, source);
  }
}

int main() {
  int n;
  printf("Enter the number of disks:\n");
  scanf("%d", &n);

  // For safety, check that the number of disks is valid
  if (n <= 0) {
    printf("Error: Number of disks must be positive\n");
    return 1;
  }

  move(n, 'A', 'C', 'B');

  return 0;
}