//FormAI DATASET v1.0 Category: Binary Converter ; Style: Alan Touring
#include <stdio.h>

void decimal_to_binary(int n) {
   int binary_num[1000];
   int i = 0;

   while (n > 0) {
      binary_num[i] = n % 2;
      n = n / 2;
      i++;
   }

   printf("Binary number: \n");
   for (int j = i - 1; j >= 0; j--)
      printf("%d", binary_num[j]);
}

int main() {
   int decimal_num;

   printf("Enter a decimal number: ");
   scanf("%d", &decimal_num);
   decimal_to_binary(decimal_num);

   return 0;
}