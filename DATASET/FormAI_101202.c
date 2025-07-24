//FormAI DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>

int main() {
   float input, output;
   char unit_type;

   printf("Enter a value and its unit type (e.g. 10m, 5Kg): ");
   scanf("%f%c", &input, &unit_type);

   switch (unit_type) {
      case 'm':
         output = input * 3.28;
         printf("%.2f meters is equal to %.2f feet\n", input, output);
         break;
      case 'f':
         output = input / 3.28;
         printf("%.2f feet is equal to %.2f meters\n", input, output);
         break;
      case 'l':
         output = input * 0.264;
         printf("%.2f liters is equal to %.2f gallons\n", input, output);
         break;
      case 'g':
         output = input / 0.264;
         printf("%.2f gallons is equal to %.2f liters\n", input, output);
         break;
      case 'k':
         output = input * 2.205;
         printf("%.2f kilograms is equal to %.2f pounds\n", input, output);
         break;
      case 'p':
         output = input / 2.205;
         printf("%.2f pounds is equal to %.2f kilograms\n", input, output);
         break;
      default:
         printf("Invalid unit type\n");
   }

   return 0;
}