//FormAI DATASET v1.0 Category: Temperature Converter ; Style: cheerful
#include <stdio.h>

int main() {
   float celsius, fahrenheit;
   int option;
   printf("Hey there! Let's convert some temperatures!\n");
   printf("Enter 1 to convert from Celsius to Fahrenheit or Enter 2 to convert from Fahrenheit to Celsius: ");
   scanf("%d", &option);
   if(option == 1){
       printf("Alright! Celsius to Fahrenheit it is!\n");
       printf("Enter temperature in Celsius: ");
       scanf("%f", &celsius);
       fahrenheit = (celsius * 1.8) + 32;
       printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
   }
   else if(option == 2){
       printf("Alright! Fahrenheit to Celsius it is!\n");
       printf("Enter temperature in Fahrenheit: ");
       scanf("%f", &fahrenheit);
       celsius = (fahrenheit - 32) / 1.8;
       printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius);
   }
   else{
       printf("Oopsy Daisy! You have entered an incorrect option. Please try again with option 1 or option 2.\n");
   }
   printf("Thanks for using our temperature converter! Come back soon!\n");
   return 0;
}