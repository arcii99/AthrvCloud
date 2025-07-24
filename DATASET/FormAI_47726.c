//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: accurate
#include <stdio.h>

void tower_of_hanoi(int disks, char from_rod, char to_rod, char aux_rod) {
   if (disks == 1) {
      printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
      return;
   }
   tower_of_hanoi(disks - 1, from_rod, aux_rod, to_rod);
   printf("Move disk %d from rod %c to rod %c\n", disks, from_rod, to_rod);
   tower_of_hanoi(disks - 1, aux_rod, to_rod, from_rod);
}

int main() {
   int disks = 4;
   char from_rod = 'A', to_rod = 'C', aux_rod = 'B';

   tower_of_hanoi(disks, from_rod, to_rod, aux_rod);

   return 0;
}