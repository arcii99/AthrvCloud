//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>

int main()
{
  int decimal, rem, quotient, i = 1, j, hex_num[100];
  char hexadecimal[100];
  
  // Get the input from the user
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);

  quotient = decimal;

  // Convert decimal to hexadecimal
  while (quotient != 0)
  {
    hex_num[i++] = quotient % 16;
    quotient /= 16;
  }

  // Display the hexadecimal equivalent
  printf("Hexadecimal equivalent of %d is ", decimal);

  for (j = i - 1; j > 0; j--)
  {
    if (hex_num[j] < 10)
      hexadecimal[i - j - 1] = hex_num[j] + 48;
    else
      hexadecimal[i - j - 1] = hex_num[j] + 55;
  }

  hexadecimal[i - 1] = '\0';

  // Print the hexadecimal number
  printf("%s\n", hexadecimal);

  return 0;
}