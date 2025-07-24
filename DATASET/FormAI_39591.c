//FormAI DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

/*
 * This program takes a decimal (integer) input from the user and converts it to a binary number.
 * It then prints out the binary number.
 */

int main() {
   int decimalInput;
   char binaryOutput[50];
   int index = 0;

   // User input prompt
   printf("Enter a decimal number: ");
   scanf("%d", &decimalInput);

   // Decimal -> Binary conversion
   while (decimalInput > 0) {
      binaryOutput[index] = decimalInput % 2 + '0';
      decimalInput /= 2;
      index++;
   }

   // Printing Binary number
   printf("The binary equivalent is: ");
   for (int i = index - 1; i >= 0; i--) {
      printf("%c", binaryOutput[i]);
   }

   return 0;
}