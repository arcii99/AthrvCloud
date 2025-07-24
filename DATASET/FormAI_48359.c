//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
#include <stdio.h>

void decimal_to_hexadecimal(int decimal_num);

int main()
{
  int decimal_num;

  printf("Enter a decimal number: ");
  scanf("%d", &decimal_num);

  printf("Hexadecimal equivalent: ");
  decimal_to_hexadecimal(decimal_num);
  
  return 0;
}

void decimal_to_hexadecimal(int decimal_num)
{
   int remainder, quotient;

   if (decimal_num == 0)
      return;

   remainder = decimal_num % 16;
   quotient = decimal_num / 16;

   decimal_to_hexadecimal(quotient);

   if (remainder < 10)
      printf("%d", remainder);
   else
      printf("%c", 'A' + remainder - 10);
}