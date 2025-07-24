//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: intelligent
#include <stdio.h>

int main()
{
  unsigned int num;
  char hex[17];
  int i = 0, j;
  printf("Enter a number: ");
  scanf("%u", &num);

  while (num != 0) 
  {
    int remainder = num % 16;
    if (remainder < 10) 
    {
      hex[i++] = 48 + remainder;
    } 
    else 
    {
      hex[i++] = 55 + remainder;
    }
    num /= 16;
  }
  
  printf("\nHexadecimal number: ");
  for (j = i - 1; j >= 0; j--)
  {
    printf("%c", hex[j]);
  }
  return 0;
}