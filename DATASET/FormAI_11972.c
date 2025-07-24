//FormAI DATASET v1.0 Category: Temperature Converter ; Style: imaginative
#include <stdio.h>

int main() {
   int option;    // variable to store the user's input choice
   float temp_c, temp_f;    // variables to store temperature in Celsius and Fahrenheit
   
   printf("Welcome to the Temperature Converter!\n\n");

   try_again:  // label for looping back

   printf("Please select an option:\n1. Convert Celsius to Fahrenheit\n2. Convert Fahrenheit to Celsius\n3. Exit\n");
   scanf("%d", &option);

   switch (option) {
      case 1:
         printf("Enter temperature in Celsius: ");
         scanf("%f", &temp_c);
         temp_f = (temp_c * 9/5) + 32;    // formula for conversion
         printf("%.2f°C = %.2f°F\n\n", temp_c, temp_f);
         goto try_again;    // loop back to ask for option again
      case 2:
         printf("Enter temperature in Fahrenheit: ");
         scanf("%f", &temp_f);
         temp_c = (temp_f - 32) * 5/9;    // formula for conversion
         printf("%.2f°F = %.2f°C\n\n", temp_f, temp_c);
         goto try_again;    // loop back to ask for option again
      case 3:
         printf("Thank you for using the Temperature Converter!\n");
         break;
      default:
         printf("Invalid option! Please select again.\n\n");
         goto try_again;    // loop back to ask for option again
   }

   return 0;
}