//FormAI DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>

// Function declaration
void decimalToBinary(int decimalNumber);

int main() {
   int decimalNumber;

   printf("Enter a decimal number: ");
   scanf("%d", &decimalNumber);

   printf("Binary representation of %d is: ", decimalNumber);
   decimalToBinary(decimalNumber);

   return 0;
}

// Function to convert decimal to binary
void decimalToBinary(int decimalNumber) {
   int binaryNumber[32], index = 0;

   while (decimalNumber > 0) {
      binaryNumber[index] = decimalNumber % 2;
      decimalNumber /= 2;
      index++;
   }

   for (int i = index - 1; i >= 0; i--) {
      printf("%d", binaryNumber[i]);
   }

   printf("\n");
}