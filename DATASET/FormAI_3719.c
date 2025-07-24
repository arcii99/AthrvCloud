//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Alan Touring
#include <stdio.h>

void towers(int n, char from_rod, char to_rod, char aux_rod);

int main() {
   int n = 3;

   towers(n, 'A', 'C', 'B');
   return 0;
}

void towers(int n, char from_rod, char to_rod, char aux_rod) {
   if (n == 1) {
      printf("\n Disk 1 from rod %c to rod %c", from_rod, to_rod);
      return;
   }
   towers(n-1, from_rod, aux_rod, to_rod);
   printf("\n Disk %d from rod %c to rod %c", n, from_rod, to_rod);
   towers(n-1, aux_rod, to_rod, from_rod);
}