//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include <stdio.h>
#include <math.h> 

int main(void) {

  unsigned int decimal_num;
  char hex_num[100];
  int i = 0, remainder;
  char hex_value;

  printf("Enter a decimal number: ");
  scanf("%u", &decimal_num);

  while (decimal_num > 0) {
    remainder = decimal_num % 16;

    if (remainder > 9) {
        hex_value = (char)(remainder - 10 + 'A');
    } else {
        hex_value = (char)(remainder + '0');
    }

    hex_num[i++] = hex_value;
    decimal_num /= 16;
  }

  printf("The equivalent hexadecimal value is: ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%c", hex_num[j]);
  }

  printf("\n");

  return 0;
}