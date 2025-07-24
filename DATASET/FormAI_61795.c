//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: cheerful
#include <stdio.h>

void MoveDisk(int n, char src, char dest) {
  printf("Happy moving disk %d from pole %c to pole %c!\n", n, src, dest);
}

void TowerOfHanoi(int n, char src, char aux, char dest) {
  if (n == 1) {
    MoveDisk(n, src, dest);
    return;
  }

  TowerOfHanoi(n-1, src, dest, aux);
  MoveDisk(n, src, dest);
  TowerOfHanoi(n-1, aux, src, dest);
}

int main() {
  int n = 3;  // number of disks
  TowerOfHanoi(n, 'A', 'B', 'C');
  printf("Success! All disks moved to the destination pole.\n");
  return 0;
}