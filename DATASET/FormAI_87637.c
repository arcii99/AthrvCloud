//FormAI DATASET v1.0 Category: Random ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int i, n;
   time_t t; // For truly random numbers

   printf("Enter the number of random numbers to generate: ");
   scanf("%d", &n);

   // Intializes random number generator
   srand((unsigned) time(&t));

   // Generate and print n random numbers
   printf("The random numbers are: \n");
   for(i = 0; i < n; i++)
   {
      printf("%d\n", rand());
   }

   return 0;
}