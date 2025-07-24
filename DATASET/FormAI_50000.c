//FormAI DATASET v1.0 Category: Random ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
   int num, i;
   
   srand(time(0)); // seeding rand() with current time

   printf("In gratitude of randomness, here's a lucky number generator!\n");
   printf("Enter the number of random numbers you want: ");
   scanf("%d", &num);
   
   printf("\nHere are your %d random numbers:\n", num);

   for (i = 1; i <= num; i++) {
      printf("%d\n", rand());
   }
   
   printf("\nHope you enjoy the randomness as much as I do!\n");
   return 0;
}