//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
   if (n == 1) {
      printf("\nMove disk 1 from rod %c to rod %c", from_rod, to_rod);
      return;
   }
   towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
   printf("\nMove disk %d from rod %c to rod %c", n, from_rod, to_rod);
   towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main() {
   int n = 3; // Number of disks
   printf("Welcome to the amazing Tower of Hanoi!\n\n");
   printf("Rules:\n");
   printf("- You must move all the disks from rod A to rod C\n");
   printf("- You can only move one disk at a time\n");
   printf("- You cannot place a larger disk on top of a smaller disk\n\n");
   printf("Ready to play? Let's begin!\n\n");

   towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
   printf("\n\nCongratulations, you have won the game!\n");
   return 0;
}