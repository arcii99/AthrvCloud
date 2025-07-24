//FormAI DATASET v1.0 Category: Math exercise ; Style: scientific
#include <stdio.h>
#include <math.h>

int main() {
   double number, power, result;

   printf("Enter a number: ");
   scanf("%lf", &number);

   printf("Enter the power to raise the number to: ");
   scanf("%lf", &power);

   if (number < 0 && ceil(power) != power) {
       printf("Cannot perform the operation");
   } else {
       result = pow(number, power);
       printf("%.2lf ^ %.2lf = %.2lf", number, power, result);
   }

   return 0;
}