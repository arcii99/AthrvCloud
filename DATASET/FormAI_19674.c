//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Sherlock Holmes
#include <stdio.h>

void towerOfHanoi(int n, char from, char to, char aux) {
  if (n == 1) {
    printf("Move disk 1 from rod %c to rod %c\n", from, to);
    return;
  }
  towerOfHanoi(n - 1, from, aux, to);
  printf("Move disk %d from rod %c to rod %c\n", n, from, to);
  towerOfHanoi(n - 1, aux, to, from);
}

int main() {
  int n = 3;  // Number of disks
  towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are the names of the rods
  return 0;
}