//FormAI DATASET v1.0 Category: Binary Converter ; Style: accurate
#include <stdio.h>

void convertToBinary(int decimalNumber) {
   int binaryNumber[32];
   int i = 0;
   while (decimalNumber > 0) {
      binaryNumber[i] = decimalNumber % 2;
      decimalNumber = decimalNumber / 2;
      i++;
   }
   printf("Equivalent binary number is: ");
   for (int j = i - 1; j >= 0; j--)
      printf("%d", binaryNumber[j]);
   printf("\n");
}

int main() {
   int decimalNumber;
   printf("Enter decimal number: ");
   scanf("%d", &decimalNumber);
   convertToBinary(decimalNumber);
   return 0;
}