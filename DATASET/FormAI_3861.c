//FormAI DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <math.h>

int main() {
   // Declare variables for user input and result
   float base, exponent, result;
   int operation;

   // Print menu and ask user for selection
   printf("Please select an operation:\n");
   printf("1. Power\n");
   printf("2. Root\n");
   printf("Selection: ");
   scanf("%d", &operation);

   // Perform selected operation with user input values
   switch(operation) {
      case 1: 
         printf("Please enter the base: ");
         scanf("%f", &base);
         printf("Please enter the exponent: ");
         scanf("%f", &exponent);
         result = pow(base, exponent);
         printf("%.2f to the power of %.2f is: %.2f", base, exponent, result);
         break;

      case 2:
         printf("Please enter the base: ");
         scanf("%f", &base);
         printf("Please enter the root: ");
         scanf("%f", &exponent);
         result = pow(base, 1.0 / exponent);
         printf("%.2f to the root of %.2f is: %.2f", base, exponent, result);
         break;
      
      default:
         printf("Invalid selection. Please try again.");
         break;
   }

   return 0;
}