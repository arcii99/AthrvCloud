//FormAI DATASET v1.0 Category: System boot optimizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
   int bootSpeed = 0;

   printf("\n\n\n\n\t\tWelcome to the Super Awesome C System boot optimizer!\n");

   printf("\n\n\n\n\t\tHow many seconds do you want to reduce your boot speed by?\n");
   printf("\t\tAnswer with an integer between 1 and 10 (inclusive): ");
   scanf("%d", &bootSpeed);

   if (bootSpeed < 1 || bootSpeed > 10) {
      printf("\n\t\tThat's not between 1 and 10, dude. The program is shutting down.\n");
      exit(0);
   }

   printf("\n\n\n\n\t\tExcellent. Your boot speed is being optimized by %d seconds!\n", bootSpeed);

   for (int i = bootSpeed; i > 0; i--)
   {
      printf("\n\n\n\n\t\tOptimizing boot speed in T minus %d seconds...", i);
      printf("\n\t\t%c", 219);
      sleep(1);
   }

   printf("\n\n\n\n\t\tYour C System is now fully optimized! Enjoy your lightning-fast boot speed, friend!\n");

   return 0;
}