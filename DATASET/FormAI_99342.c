//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
#include<stdio.h>

int main() {
   int decimal_num, rem, hex_num=0, i=1;

   printf("Enter the decimal number: ");
   scanf("%d", &decimal_num);

   while(decimal_num!=0) {
      rem = decimal_num % 16;
      hex_num = hex_num + rem * i;
      i = i * 10;
      decimal_num = decimal_num / 16;
   }

   printf("The hexadecimal number is: %d", hex_num);

   return 0;
}