//FormAI DATASET v1.0 Category: Robot movement control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL));
   int x = 0, y = 0;
   int n = 50;
   int i = 0;

   printf("C Robot Movement Control Program Started...\n");

   while (i < n) {
      int direction = rand() % 4; //random number between 0-3
      switch (direction) {
         case 0: y++; break; //move up
         case 1: y--; break; //move down
         case 2: x++; break; //move right
         case 3: x--; break; //move left
      }

      printf("Robot Position: (%d, %d)\n", x, y);
      i++;
   }

   printf("C Robot Movement Control Program Exiting...\n");

   return 0;
}