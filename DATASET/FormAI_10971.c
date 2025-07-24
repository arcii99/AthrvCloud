//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: beginner-friendly
#include <stdio.h>
int towerOfHanoi(int n, char startRod, char endRod, char tempRod) {
  if (n == 1) {
    printf("\n Move disk 1 from rod %c to rod %c", startRod, endRod);
    return 0;
  }
  towerOfHanoi(n - 1, startRod, tempRod, endRod);
  printf("\n Move disk %d from rod %c to rod %c", n, startRod, endRod);
  towerOfHanoi(n - 1, tempRod, endRod, startRod);
  return 0;
}

int main() {
  int n;
  printf("\nEnter the number of disks: ");
  scanf("%d", &n);
  towerOfHanoi(n, 'A', 'C', 'B');
  return 0;
}