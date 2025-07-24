//FormAI DATASET v1.0 Category: Bitwise operations ; Style: interoperable
#include <stdio.h>

// Bitwise operations Interoperable example
// In this program we will check if a given number is even or odd

#ifdef __cplusplus
extern "C" {
#endif

// Function declaration to determine whether the number is even or odd
void print_even_odd(unsigned int num);

#ifdef __cplusplus
}
#endif

void print_even_odd(unsigned int num) {
  if (num & 1) {
    printf("%d is odd.\n", num);
  } else {
    printf("%d is even.\n", num);
  }
}

int main() {
  unsigned int num = 0;
  printf("Enter a number to determine if it is even or odd: ");
  scanf("%d", &num);

  print_even_odd(num);

  return 0;
}