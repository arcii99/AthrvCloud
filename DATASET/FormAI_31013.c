//FormAI DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>

int main() {
   // Define variables
   double input_val, output_val;
   int selection;
   
   // Print menu of available unit conversions
   printf("Select a unit conversion:\n");
   printf("1. Kilometers to miles\n");
   printf("2. Pounds to kilograms\n");
   printf("3. Inches to centimeters\n");
   
   // Take user input for selection
   printf("Enter your selection (1, 2, or 3): ");
   scanf("%d", &selection);
   
   // Take user input for value to convert
   printf("Enter a value to convert: ");
   scanf("%lf", &input_val);
   
   // Perform conversion based on user selection
   if (selection == 1) {
       output_val = input_val * 0.621371;
       printf("%.2lf kilometers is equal to %.2lf miles.\n", input_val, output_val);
   } else if (selection == 2) {
       output_val = input_val * 0.453592;
       printf("%.2lf pounds is equal to %.2lf kilograms.\n", input_val, output_val);
   } else if (selection == 3) {
       output_val = input_val * 2.54;
       printf("%.2lf inches is equal to %.2lf centimeters.\n", input_val, output_val);
   } else {
       printf("Invalid input.\n");
   }
   
   return 0;
}