//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // Initialize random number generator

   printf("Welcome to the automated cyber fortune teller.\n");
   printf("Please think of a question and then press enter to continue.\n");
   getchar();

   int fortune = rand() % 5; // Get a random number

   switch (fortune) {
      case 0:
         printf("The future is not certain for you, but be wary of those who offer easy answers.\n");
         break;
      case 1:
         printf("Your destiny lies in the shadows. Seek guidance from within yourself rather than from those around you.\n");
         break;
      case 2:
         printf("Be cautious in your dealings with corporations. They may promise great rewards but the cost may be too high.\n");
         break;
      case 3:
         printf("Your path is a dangerous one, but if you can keep your wits about you, you will come out on top.\n");
         break;
      case 4:
         printf("The future is not set in stone, but it is up to you to determine your own fate. Choose wisely.\n");
         break;
      default:
         printf("It seems that the fates are undecided about your future. Keep your eyes open for opportunities.\n");
         break;
   }

   return 0;
}