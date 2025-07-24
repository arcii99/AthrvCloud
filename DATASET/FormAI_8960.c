//FormAI DATASET v1.0 Category: Temperature monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
   double celsius, farenheit;
   char input;

   do {
       printf("Enter temperature in Celsius: ");
       scanf("%lf", &celsius);
       farenheit = (celsius * 9/5) + 32;
       printf("%.2lf Celsius is equivalent to %.2lf farenheit\n", celsius, farenheit);
       
       printf("Would you like to convert another temperature? (Y/N) ");
       scanf(" %c", &input);
       input = toupper(input); //convert input to uppercase to handle lower-case 'n' or 'y' inputs
       
       while (input != 'Y' && input != 'N') { //validating input
           printf("Invalid input. Please enter either 'Y' or 'N': ");
           scanf(" %c", &input);
           input = toupper(input);
       }
       
   } while (input != 'N');

   printf("Goodbye!");

   return 0;
}