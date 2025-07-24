//FormAI DATASET v1.0 Category: Educational ; Style: multivariable
#include <stdio.h>

int main()
{
   // Declare variables
   int a, b, c;
   
   // Ask for user input
   printf("Enter values for a, b, and c: ");
   scanf("%d %d %d", &a, &b, &c);

   // Calculate the average
   float average = (a + b + c) / 3.0;

   // Calculate the variance
   float variance = ((a - average) * (a - average) + (b - average) * (b - average) + (c - average) * (c - average)) / 3.0;

   // Calculate the standard deviation
   float standard_deviation = sqrt(variance);

   // Print results
   printf("The average is: %f\n", average);
   printf("The variance is: %f\n", variance);
   printf("The standard deviation is: %f\n", standard_deviation);

   return 0;
}