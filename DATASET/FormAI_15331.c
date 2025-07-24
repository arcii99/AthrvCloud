//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int num) {
   int binaryNum[32];
   int i = 0;
   while (num > 0) {
      binaryNum[i] = num % 2;
      num = num / 2;
      i++;
   }
   for (int j = i - 1; j >= 0; j--)
      printf("%d", binaryNum[j]);
}

int binaryToDecimal(int n) {
   int decimal = 0, base = 1;
   int temp = n;
   while (temp) {
      int lastDigit = temp % 10;
      temp = temp / 10;
      decimal += lastDigit * base;
      base = base * 2;
   }
   return decimal;
}

int main() {
   int num;
   printf("Enter a decimal number: ");
   scanf("%d", &num);
   printf("Binary number of %d is: ", num);
   decimalToBinary(num);
   printf("\n");

   int binNum;
   printf("Enter a binary number: ");
   scanf("%d", &binNum);
   printf("Decimal number of %d is: %d\n", binNum, binaryToDecimal(binNum));

   return 0;
}