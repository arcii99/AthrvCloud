//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char hex[7], *end;
  long num;
  
  printf("Enter a hexadecimal color code: ");
  scanf("%s", hex);
  
  num = strtol(hex, &end, 16);
  
  if(strlen(hex) != 6 || *end != '\0') {
    printf("\nInvalid hexadecimal color code. Try again!");
    return 1;
  }
  
  int r = (num >> 16) & 0xFF;
  int g = (num >> 8) & 0xFF;
  int b = num & 0xFF;

  printf("\nThe RGB color code for %s is (%d, %d, %d)", hex, r, g, b);

  return 0;
}