//FormAI DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>

void decimalToBinary(int decimalnum) {
   int binarynum[32], i = 0;
   while (decimalnum > 0) {
      binarynum[i] = decimalnum % 2;
      decimalnum = decimalnum / 2;
      i++;
   }
   for (int j = i - 1; j >= 0; j--)
      printf("%d", binarynum[j]);
}

void binaryToDecimal(int binarynum) {
   int decimalnum = 0, temp = binarynum, i = 0, rem;
   while (temp > 0) {
      rem = temp % 10;
      temp = temp / 10;
      decimalnum += rem * (1 << i);
      i++;
   }
   printf("%d", decimalnum);
}

int main() {
   int choice, decimalnum, binarynum;
   printf("Enter your choice:\n1. Convert Decimal to Binary\n2. Convert Binary to Decimal\n");
   scanf("%d", &choice);
   switch (choice) {
      case 1:
         printf("Enter a decimal number: ");
         scanf("%d", &decimalnum);
         printf("Binary: ");
         decimalToBinary(decimalnum);
         break;
      case 2:
         printf("Enter a binary number: ");
         scanf("%d", &binarynum);
         printf("Decimal: ");
         binaryToDecimal(binarynum);
         break;
      default:
         printf("Invalid choice!\n");
   }
   return 0;
}