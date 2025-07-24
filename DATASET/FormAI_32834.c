//FormAI DATASET v1.0 Category: Temperature Converter ; Style: brave
#include <stdio.h>

int main() {
   char choice;
   float temperature, convertedTemp;
   
   printf("Welcome to the Temperature Converter!\n");
   printf("Choose an option:\n");
   printf("C -> Fahrenheit\n");
   printf("F -> Celsius\n");
   scanf("%c", &choice);
   
   if(choice == 'C' || choice == 'c') {
      printf("Enter temperature in Celsius: ");
      scanf("%f", &temperature);
      convertedTemp = (temperature*9/5) + 32;
      printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.", temperature, convertedTemp);
   } else if(choice == 'F' || choice == 'f') {
      printf("Enter temperature in Fahrenheit: ");
      scanf("%f", &temperature);
      convertedTemp = (temperature-32)*5/9;
      printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.", temperature, convertedTemp);   
   } else {
      printf("Invalid choice! Please try again.");
   }

   return 0;
}