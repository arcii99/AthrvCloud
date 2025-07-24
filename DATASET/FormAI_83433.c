//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert (char hex[]) {
  int len = strlen(hex);
  int decimal = 0;
  for (int i = 0; i < len; i++) {
    int digit;
    if (hex[i] >= '0' && hex[i] <= '9') {
      digit = hex[i] - '0';
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      digit = hex[i] - 'a' + 10;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      digit = hex[i] - 'A' + 10;
    } else {
      printf("%c is not valid hexadecimal digit\n", hex[i]);
      return;
    }
    decimal = decimal * 16 + digit;
  }
  printf("The hexadecimal value %s is equal to decimal value %d\n", hex, decimal);
}

int main() {
  char hex[100];
  printf("Enter a hexadecimal number: ");
  fgets(hex, 100, stdin); // get input as string
  hex[strcspn(hex, "\n")] = 0; // remove trailing newline character
  convert(hex);
  return 0;
}