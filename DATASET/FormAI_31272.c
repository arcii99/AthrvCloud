//FormAI DATASET v1.0 Category: Binary Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void printBinary(int n);

int main(void) {

  printf("=====================\n");
  printf("=  Binary Converter  =\n");
  printf("=====================\n\n");

  printf("Enter an integer: ");

  int n;
  scanf("%d", &n);

  printf("\n");

  printf("The binary equivalent of %d is: ", n);

  printBinary(n);

  printf("\n\n");

  return 0;

}

void printBinary(int n) {

  int i;
  for (i = 31; i >= 0; --i) {

    printf("%d", n >> i & 1);

    if (i == 0) {
      printf("\n");
    }

  }

}