//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>

int main() {
   int decimalValue;
   char hexadecimalValue[50];
   int i = 0;

   printf("Enter the decimal value: ");
   scanf("%d", &decimalValue);

   while(decimalValue > 0) {
      int remainder = decimalValue % 16;

      if(remainder < 10) {
         hexadecimalValue[i] = 48 + remainder;
      }
      else {
         hexadecimalValue[i] = 55 + remainder;
      }

      i++;
      decimalValue /= 16;
   }

   printf("The hexadecimal value is: ");

   for(int j = i - 1; j >= 0; j--) {
      printf("%c", hexadecimalValue[j]);
   }

   return 0;
}