//FormAI DATASET v1.0 Category: Binary Converter ; Style: secure
#include<stdio.h>

int binaryToDecimal(long long);
long long decimalToBinary(int);

int main() {
   int choice, decimal;
   long long binary;

   printf("Welcome to our Binary Converter Tool!\n");
   printf("Please select the conversion:\n");
   printf("1. Binary to Decimal\n2. Decimal to Binary\n");
   scanf("%d", &choice);

   switch(choice) {
      case 1:
         printf("Enter a binary number: ");
         scanf("%lld", &binary);
         printf("%lld in binary = %d in decimal", binary, binaryToDecimal(binary));
         break;

      case 2:
         printf("Enter a decimal number: ");
         scanf("%d", &decimal);
         printf("%d in decimal = %lld in binary", decimal, decimalToBinary(decimal));
         break;

      default:
         printf("Invalid choice, please try again.");
   }

   return 0;
}

int binaryToDecimal(long long binaryNumber) {
   int decimalNumber = 0, i = 0, remainder;

   while(binaryNumber != 0) {
      remainder = binaryNumber % 10;
      binaryNumber /= 10;
      decimalNumber += remainder * pow(2,i);
      ++i;
   }

   return decimalNumber;
}

long long decimalToBinary(int decimalNumber) {
   long long binaryNumber = 0;
   int remainder, i = 1, step = 1;

   while (decimalNumber != 0) {
      remainder = decimalNumber % 2;
      printf("Step %d: %d/2, Remainder = %d, Quotient = %d\n", step++, decimalNumber, remainder, decimalNumber / 2);
      decimalNumber /= 2;
      binaryNumber += remainder * i;
      i *= 10;
   }

   return binaryNumber;
}