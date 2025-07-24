//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: genious
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
  if (n == 1) {
    printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
    return;
  }
  towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
  printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
  towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
  int n = 5; // Number of disks
  printf("Welcome to the Tower of Hanoi!\n");
  printf("In this game, you must move all disks from the starting rod to the destination rod.\n");
  printf("However, there are a few rules you must follow:\n");
  printf("1. Only one disk can be moved at a time.\n");
  printf("2. A disk can only be moved if it is the uppermost disk on a stack.\n");
  printf("3. A disk can only be moved onto a rod that is either empty or has a larger disk on it.\n");
  printf("You will be given a starting rod (A), a destination rod (B), and an auxiliary rod (C).\n");
  printf("Your job is to use the auxiliary rod (C) to move all disks from the starting rod (A) to the destination rod (B).\n");
  printf("Good luck!\n\n");

  towerOfHanoi(n, 'A', 'B', 'C'); // Starting rod as A, destination rod as B, and auxiliary rod as C

  printf("\nCongratulations, you have successfully completed the Tower of Hanoi!\n");

  return 0;
}