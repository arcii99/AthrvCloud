//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include <stdio.h>

int moves = 0; // count the number of moves

void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
   if(n==1) {
      printf("Move disk 1 from rod %c to rod %c\n", source, destination);
      moves++;
      return;
   }
   tower_of_hanoi(n-1, source, auxiliary, destination);
   printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
   moves++;
   tower_of_hanoi(n-1, auxiliary, destination, source);
}

int main() {
   int n;
   printf("Enter the number of disks: ");
   scanf("%d", &n);
   printf("The sequence of moves involved in the Tower of Hanoi are:\n");
   tower_of_hanoi(n, 'A', 'C', 'B');
   printf("Total number of moves taken: %d\n", moves);
   return 0;
}