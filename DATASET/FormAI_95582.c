//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: cheerful
#include <stdio.h>

int hex_to_dec(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else if (c >= 'A' && c <= 'F') {
    return c - 'A' + 10;
  } else if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  } else {
    return -1;
  }
}

int main() {
  char hex_num[10];
  int dec_num = 0, hex_len, place = 1, digit;

  printf("Welcome to the Cheerful C Hexadecimal Converter!\n");
  
  printf("Please enter a hexadecimal number: ");
  scanf("%s", hex_num);

  hex_len = strlen(hex_num);

  for (int i = hex_len - 1; i >= 0; i--) {
    digit = hex_to_dec(hex_num[i]);

    if (digit == -1) {
      printf("Invalid hexadecimal number!\n");
      return -1;
    }

    dec_num += digit * place;
    place *= 16;
  }

  printf("The decimal equivalent of the hexadecimal number %s is %d.\n", hex_num, dec_num);

  return 0;
}