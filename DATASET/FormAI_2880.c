//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: standalone
#include <stdio.h>

void moveDisk(int disk, char from, char to, char aux) {
   if (disk == 1) {
      printf("\n Move disk 1 from %c to peg %c", from, to);
      return;
   }
   moveDisk(disk-1, from, aux, to);
   printf("\n Move disk %d from %c to peg %c", disk, from, to);
   moveDisk(disk-1, aux, to, from);
}

int main() {
   int disks;

   printf("Enter number of disks: ");
   scanf("%d", &disks);

   moveDisk(disks, 'A', 'C', 'B');

   return 0;
}