//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: optimized
#include <stdio.h>

// Tower of Hanoi function
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
  if (n == 1)
  {
    printf("\tMove disk 1 from rod %c to rod %c\n", from_rod, to_rod);
    return;
  }
  towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
  printf("\tMove disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
  towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
  int n = 4; //number of disks

  printf("Welcome to Tower of Hanoi Solver.\n\n");
  printf("Given three rods: \n\n\t'A'\t'B'\t'C'\n\n");
  printf("The aim of the game is to move all the disks from rod 'A' to rod 'C',\n");
  printf("such that at any given point of time, no larger disk is placed on smaller disk.\n");
  printf("The moves included are:\n\n");

  towerOfHanoi(n, 'A', 'C', 'B'); //A, B and C are the names of rods

  printf("\nAll disks have been moved to rod C!\n");

  return 0;
}