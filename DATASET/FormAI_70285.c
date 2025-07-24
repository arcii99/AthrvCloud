//FormAI DATASET v1.0 Category: Bitwise operations ; Style: peaceful
#include <stdio.h>

int main() {
  // Welcome message
  printf("Welcome to the Bitwise Peace Program!\n");

  // Ask for user input
  int number1;
  printf("Enter the first number: ");
  scanf("%d", &number1);
  int number2;
  printf("Enter the second number: ");
  scanf("%d", &number2);

  // Bitwise AND operation
  int resultAnd = number1 & number2;
  printf("The result of %d AND %d is: %d\n", number1, number2, resultAnd);

  // Bitwise OR operation
  int resultOr = number1 | number2;
  printf("The result of %d OR %d is: %d\n", number1, number2, resultOr);

  // Bitwise XOR operation
  int resultXor = number1 ^ number2;
  printf("The result of %d XOR %d is: %d\n", number1, number2, resultXor);

  // Bitwise left shift
  int resultLeftShift = number1 << 2;
  printf("The result of left shifting %d by 2 is: %d\n", number1, resultLeftShift);

  // Bitwise right shift
  int resultRightShift = number2 >> 1;
  printf("The result of right shifting %d by 1 is: %d\n", number2, resultRightShift);

  // One's complement
  int resultOnesComplement = ~number1;
  printf("The result of one's complement of %d is: %d\n", number1, resultOnesComplement);

  // Two's complement
  int resultTwosComplement = ~number2 + 1;
  printf("The result of two's complement of %d is: %d\n", number2, resultTwosComplement);

  // Thank you message
  printf("Thank you for trying the Bitwise Peace Program. Hope it brought peace to your programming :)\n");

  return 0;
}