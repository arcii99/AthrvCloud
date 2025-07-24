//FormAI DATASET v1.0 Category: Temperature monitor ; Style: expert-level
#include <stdio.h>

int main() {
   float celsius, fahrenheit;
   int choice;
   
   printf("Select input temperature scale:\n1. Celsius\n2. Fahrenheit\n");
   scanf("%d", &choice);
   
   if(choice == 1) {
       printf("Enter temperature in Celsius: ");
       scanf("%f", &celsius);
       fahrenheit = (celsius * 9 / 5) + 32;
       printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);
   }
   else if (choice == 2) {
       printf("Enter temperature in Fahrenheit: ");
       scanf("%f", &fahrenheit);
       celsius = (fahrenheit - 32) * 5 / 9;
       printf("%.2f Fahrenheit is equal to %.2f Celsius\n", fahrenheit, celsius);
   }
   else {
       printf("Invalid input\n");
   }
   
   return 0;
}