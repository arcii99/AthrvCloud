//FormAI DATASET v1.0 Category: Random ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int num, i, j;
   srand(time(NULL)); // seed the random number generator with the current time
   printf("How many random numbers do you want to generate? ");
   scanf("%d", &num); // take the number of random numbers from the user
   
   int random[num]; // create an array to store the random numbers
   
   for(i = 0; i < num; i++)
   {
      random[i] = rand(); // generate a random number and store it in the array
   }

   printf("\nInitial random numbers: ");
   for(i = 0; i < num; i++)
   {
      printf("%d ", random[i]); // print the initial random numbers
   }

   // sort the random numbers in ascending order
   for(i = 0; i < num; i++)
   {
      for(j = i + 1; j < num; j++)
      {
         if(random[i] > random[j])
         {
            int temp = random[i];
            random[i] = random[j];
            random[j] = temp;
         }
      }
   }
   
   printf("\nSorted random numbers: ");
   for(i = 0; i < num; i++)
   {
      printf("%d ", random[i]); // print the sorted random numbers
   }

   return 0;
}