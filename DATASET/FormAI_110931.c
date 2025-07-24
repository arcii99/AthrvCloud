//FormAI DATASET v1.0 Category: Scientific ; Style: cheerful
#include <stdio.h>

int main() {
  int base, exponent, result = 1;
  printf("Let's do some math!\nEnter a base number: ");
  scanf("%d", &base);
  printf("Enter an exponent: ");
  scanf("%d", &exponent);
  for (int i = 0; i < exponent; i++) {
    result *= base;
  }
  printf("%d to the power of %d is %d\n", base, exponent, result);
  printf("That was some awesome math! Want to try again? (y/n) ");
  char choice;
  scanf(" %c", &choice);
  while (choice != 'n') {
    printf("Enter a base number: ");
    scanf("%d", &base);
    printf("Enter an exponent: ");
    scanf("%d", &exponent);
    result = 1;
    for (int i = 0; i < exponent; i++) {
      result *= base;
    }
    printf("%d to the power of %d is %d\n", base, exponent, result);
    printf("Want to try again? (y/n) ");
    scanf(" %c", &choice);
  }
  printf("Thanks for doing math with me! Goodbye.\n");
  return 0;
}