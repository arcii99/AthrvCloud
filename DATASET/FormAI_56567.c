//FormAI DATASET v1.0 Category: Binary Converter ; Style: optimized
#include <stdio.h>

void print_binary(unsigned int num) {
  int arr[32];
  int i = 0;
  while (num > 0) {
    arr[i] = num % 2;
    num = num / 2;
    i++;
  }
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", arr[j]);
  }
  printf("\n");
}

int main() {
  unsigned int input_num;
  printf("Enter an integer to convert to binary:\n");
  scanf("%u", &input_num);

  printf("Binary representation of %u is ", input_num);
  print_binary(input_num);

  return 0;
}