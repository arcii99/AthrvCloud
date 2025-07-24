//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: modular
#include<stdio.h>

void toh(int, char, char, char);

int main() {
   int num;

   printf("Enter the number of disks : ");
   scanf("%d", &num);

   printf("The sequence of moves involved in the Tower of Hanoi are :\n");
   toh(num, 'A', 'C', 'B');

   return 0;
}

void toh(int num, char from_rod, char to_rod, char aux_rod) {
   if (num == 1) {
      printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
      return;
   }
   toh(num - 1, from_rod, aux_rod, to_rod);
   printf("\n Move disk %d from rod %c to rod %c", num, from_rod, to_rod);
   toh(num - 1, aux_rod, to_rod, from_rod);
}