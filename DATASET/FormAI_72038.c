//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Donald Knuth
#include <stdio.h>

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
  if(n == 1) {
    printf("Move disk %d from %c to %c\n", n, source, destination);
    return;
  }

  towerOfHanoi(n - 1, source, auxiliary, destination);
  printf("Move disk %d from %c to %c\n", n, source, destination);
  towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
  int disks;
  printf("Enter number of disks: ");
  scanf("%d", &disks);

  if(disks <= 0) {
    printf("Invalid number of disks\n");
    return 0;
  }

  printf("Moves required to solve Tower of Hanoi with %d disks:\n", disks);
  towerOfHanoi(disks, 'A', 'C', 'B');

  return 0;
}