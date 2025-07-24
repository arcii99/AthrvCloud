//FormAI DATASET v1.0 Category: Random ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int randomNumber[10];

   // Generate random numbers
   srand(time(NULL));
   for (int i = 0; i < 10; i++) {
      randomNumber[i] = rand() % 100;
   }

   // Sort the random numbers
   for (int i = 0; i < 10; i++) {
      for (int j = i + 1; j < 10; j++) {
         if (randomNumber[i] > randomNumber[j]) {
            int temp = randomNumber[i];
            randomNumber[i] = randomNumber[j];
            randomNumber[j] = temp;
         }
      }
   }

   // Print the sorted random numbers
   printf("Sorted random numbers: ");
   for (int i = 0; i < 10; i++) {
      printf("%d ", randomNumber[i]);
   }
   printf("\n");

   return 0;
}