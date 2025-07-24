//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: light-weight
#include <stdio.h>

void moveDiscs(int disc, char startPeg, char endPeg, char midPeg) {
   if (disc == 1) {
      printf("\nMove disc 1 from %c to %c", startPeg, endPeg);
      return;
   }
   moveDiscs(disc - 1, startPeg, midPeg, endPeg);
   printf("\nMove disc %d from %c to %c", disc, startPeg, endPeg);
   moveDiscs(disc - 1, midPeg, endPeg, startPeg);
}

int main() {
   int discNum;
   printf("Enter the number of discs: ");
   scanf("%d", &discNum);
   printf("The moves are: \n");
   moveDiscs(discNum, 'A', 'B', 'C');
   return 0;
}