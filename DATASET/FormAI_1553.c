//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: high level of detail
#include <stdio.h>

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
   if(n == 1) {
      printf("\nMove disk 1 from peg %c to peg %c", source, destination);
      return;
   }
   towerOfHanoi(n - 1, source, auxiliary, destination);
   printf("\nMove disk %d from peg %c to peg %c", n, source, destination);
   towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
   int n = 3; // We will solve for 3 disks
   printf("The solution for the Tower of Hanoi problem for %d disks is:\n", n);
   towerOfHanoi(n, 'A', 'C', 'B');
   return 0;
}