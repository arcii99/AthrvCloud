//FormAI DATASET v1.0 Category: Binary Converter ; Style: accurate
#include <stdio.h>

// function to convert decimal to binary
void decimalToBinary(int decimalNum) {
   int binaryNum[1000], i = 0;
   
   while (decimalNum > 0) {
      binaryNum[i] = decimalNum % 2;
      decimalNum = decimalNum / 2;
      i++;
   }
   
   // printing binary in reverse order
   printf("The binary number is: ");
   for (int j = i - 1; j >= 0; j--)
      printf("%d", binaryNum[j]);

   printf("\n");
}

int main() {
   int decimalNum;

   printf("Enter a decimal number: ");
   scanf("%d", &decimalNum);

   decimalToBinary(decimalNum);

   return 0;
}