//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
   int decimal_num, rem, i=0;
   char hex_num[20];

   printf("Exciting Hexadecimal Converter Program!\n");

   printf("Enter a decimal number: ");
   scanf("%d", &decimal_num);

   while(decimal_num > 0) {
      rem = decimal_num % 16;

      if(rem < 10)
         hex_num[i] = rem + 48;
      else
         hex_num[i] = rem + 55;

      i++;
      decimal_num = decimal_num/16;
  }

  printf("Hexadecimal number is: ");

  for(i=i-1; i>=0; i--)
      printf("%c", hex_num[i]);

  return 0;
}