//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

int main() {
  char hexNum[1000], *ptr;
  long int decNum;
  int i = 0;

  printf("Enter a hexadecimal number: ");
  scanf("%s", hexNum);

  decNum = strtol(hexNum, &ptr, 16);

  printf("\nEquivalent decimal number is: %ld\n", decNum);

  return 0;
}