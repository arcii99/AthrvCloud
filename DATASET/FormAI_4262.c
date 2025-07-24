//FormAI DATASET v1.0 Category: Binary Converter ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char binary[32];
  int decimal = 0, i, len;

  printf("Enter a binary number: ");
  scanf("%s", binary);

  len = strlen(binary);

  for (i = 0; i < len; i++) {
    if (binary[i] == '1') {
      decimal += 1 << (len - i - 1);
    }
  }

  printf("Decimal equivalent: %d", decimal);

  return 0;
}