//FormAI DATASET v1.0 Category: Binary Converter ; Style: excited
#include <stdio.h>

int main() {
  printf("Welcome to the Binary Converter!\n");
  printf("Enter a decimal number: ");

  int input;
  scanf("%d", &input);

  printf("Binary conversion of %d is: ", input);

  int binary[100];
  int index = 0;

  while (input > 0) {
    binary[index] = input % 2;
    input /= 2;
    index++;
  }

  for (int i = index - 1; i >= 0; i--) {
    printf("%d", binary[i]);
  }

  printf("\n");
  printf("Thanks for using the Binary Converter!\n");

  return 0;
}