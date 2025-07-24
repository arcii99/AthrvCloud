//FormAI DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
   int i, n, sum = 0, sum_sq = 0, ave, var, std_dev;
   float probability;
   srand(time(0)); // seed the random number generator with the current time

   printf("Enter the number of elements in the data set:");
   scanf("%d", &n);
   int data[n];

   printf("\nGenerating %d random numbers...\n", n);
   for(i=0; i<n; i++) {
      data[i] = rand() % 100;
      printf("%d ", data[i]);
   }

   //calculate the mean
   for(i=0; i<n; i++) {
      sum += data[i];
   }
   ave = sum/n;
   printf("\nThe mean value of the data set is %d\n", ave);

   //calculate the variance
   for(i=0; i<n; i++) {
      sum_sq += pow((data[i]-ave), 2);
   }
   var = sum_sq/n;
   printf("The variance of the data set is %d\n", var);

   //calculate the standard deviation
   std_dev = sqrt(var);
   printf("The standard deviation of the data set is %d\n", std_dev);

   //calculate the probability for a random number to be within one standard deviation of the mean
   probability = 1.0*(std_dev+ave - ave)/100;
   printf("The probability that a randomly selected number from the data set is within one standard deviation of the mean is %.2f\n", probability);

   return 0;
}