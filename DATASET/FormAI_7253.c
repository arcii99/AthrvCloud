//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

   srand(time(NULL)); // seed random number generator
   
   int probability = rand() % 101; // generate a random number between 0 and 100
   
   // display output based on probability
   if (probability <= 10) {
      printf("The probability of an alien invasion is very low.\n");
   } else if (probability <= 30) {
      printf("There is a moderate chance of an alien invasion.\n");
   } else if (probability <= 70) {
      printf("The probability of an alien invasion is relatively high.\n");
   } else {
      printf("The probability of an alien invasion is extreme! Take cover!\n");
   }
   
   return 0;
}