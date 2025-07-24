//FormAI DATASET v1.0 Category: Binary Converter ; Style: thriller
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char binary[100], tmp[100], *ptr;
  int decimal = 0, i, len;

  printf("Enter binary number: ");
  scanf("%s", binary);
  len = strlen(binary);

  if (len > 31) {
    printf("ERROR: Number too large\n");
    exit(1);
  }

  for (i = 0; i < len; i++) {
    if (binary[i] != '0' && binary[i] != '1') {
      printf("ERROR: Not a binary number\n");
      exit(1);
    }
  }

  ptr = binary + len - 1;
  i = 0;

  while (ptr >= binary) {
    tmp[i++] = *ptr--;
  }
  tmp[i] = '\0';

  for (i = 0; i < len; i++) {
    if (tmp[i] == '1') {
      decimal += 1 << i;
    }
  }

  printf("Decimal representation: %d\n", decimal);

  return 0;
}