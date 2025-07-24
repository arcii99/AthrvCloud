//FormAI DATASET v1.0 Category: Binary Converter ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

int main()
{
  int num, decimal_number, remainder, base = 1, binary = 0, no_of_bits = 0;

  printf("Enter a decimal number: ");
  scanf("%d", &num);

  decimal_number = num;

  /* count the number of bits in the binary representation */
  while(decimal_number > 0)
  {
    no_of_bits++;
    decimal_number /= 2;
  }

  decimal_number = num;

  /* convert decimal to binary */
  while(decimal_number > 0)
  {
    remainder = decimal_number % 2;
    binary += remainder * base;
    decimal_number /= 2;
    base *= 10;
  }

  printf("The binary equivalent of %d is ", num);

  /* print leading zeros if needed */
  for(int i = no_of_bits - 1; i >= 0; i--)
  {
    if((binary >> i) & 1)
      printf("1");
    else
      printf("0");
  }

  printf("\n");

  return 0;
}