//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: unmistakable
#include <stdio.h>

void moveDisk(int n, char fromTower, char toTower, char auxTower) {
  if (n == 1) {
    printf("Move disk 1 from %c to %c\n", fromTower, toTower);
    return;
  }
  moveDisk(n - 1, fromTower, auxTower, toTower);
  printf("Move disk %d from %c to %c\n", n, fromTower, toTower);
  moveDisk(n - 1, auxTower, toTower, fromTower);
}

int main() {
  int n;
  printf("Enter the number of disks: ");
  scanf("%d", &n);
  printf("Here's the solution to the Tower of Hanoi problem with %d disks:\n", n);
  moveDisk(n, 'A', 'C', 'B');
  return 0;
}