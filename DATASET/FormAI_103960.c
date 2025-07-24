//FormAI DATASET v1.0 Category: Computer Biology ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int sequence[10], i, sum = 0;
   float average;

   // Prompt the user to enter 10 integer numbers
   printf("Enter 10 integer numbers:\n");

   // Loop through the sequence and get input from the user
   for (i = 0; i < 10; i++) {
      printf("Enter the number #%d: ", i+1);
      scanf("%d", &sequence[i]);
   }

   // Calculate the sum of all the integers in the sequence
   for (i = 0; i < 10; i++) {
      sum += sequence[i];
   }

   // Calculate the average of all the integers in the sequence
   average = (float) sum / 10;

   // Print out the sum and average of all the integers in the sequence
   printf("\nThe sum of all the integers in the sequence is: %d\n", sum);
   printf("The average of all the integers in the sequence is: %.2f\n\n", average);

   // Prompt the user to press enter to continue
   printf("Press enter to continue...");
   getchar();
   return 0;
}