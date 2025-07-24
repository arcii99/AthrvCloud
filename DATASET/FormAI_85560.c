//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surrealist
#include <stdio.h>

void tower(int n, char start, char end, char temp) {
   if (n == 1) {
      printf("I will move the top disk from tower %c to tower %c.\n", start, end);
      return;
   }
   tower(n - 1, start, temp, end);
   printf("I will move a disk from tower %c to tower %c.\n", start, end);
   tower(n - 1, temp, end, start);
}

int main() {
   printf("Hey there, I am the surrealistic Tower of Hanoi problem program. I see three towers – A, B and C.\n");
   printf("On the first tower (A) there are n disks of different sizes that are stacked in decreasing order of size running\nfrom the bottom to the top.\n");
   printf("I will move the disks one by one to the third tower (C) without placing a bigger disk on top of a smaller one.\n");
   printf("Are you ready for some surrealistic moves? Let's go!\n");

   int n;
   printf("\nEnter the number of disks: ");
   scanf("%d", &n);

   tower(n, 'A', 'C', 'B');

   printf("\nWow, that was surreal! The Tower of Hanoi problem has been solved with the power of surrealism!\n");
   return 0;
}