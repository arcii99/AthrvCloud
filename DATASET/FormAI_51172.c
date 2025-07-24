//FormAI DATASET v1.0 Category: Math exercise ; Style: shape shifting
#include <stdio.h>
#include <math.h>

int main() {
   double number, result;
   
   printf("Enter a number you would like to calculate the square root of: ");
   scanf("%lf", &number);
   
   if (number < 0) {
      printf("\nCannot calculate the square root of a negative number.");
   }
   else {
      result = sqrt(number);
      printf("\nThe square root of %.2lf is %.2lf", number, result);
   }
   
   return 0;
}