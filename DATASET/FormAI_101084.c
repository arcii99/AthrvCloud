//FormAI DATASET v1.0 Category: Arithmetic ; Style: genious
#include<stdio.h>

int main() {
  int num1, num2, num3;
  float result; //note: float is used to get decimal values in division operation

  printf("Enter three numbers: \n");
  scanf("%d%d%d", &num1, &num2, &num3);

  //addition operation
  result = num1 + num2 + num3;
  printf("The sum of %d, %d and %d is %.2f\n", num1, num2, num3, result);

  //subtraction operation
  result = num1 - num2 - num3;
  printf("The difference between %d, %d and %d is %.2f\n", num1, num2, num3, result);

  //multiplication operation
  result = num1 * num2 * num3;
  printf("The product of %d, %d and %d is %.2f\n", num1, num2, num3, result);

  //division operation
  if(num2 != 0 && num3 != 0) { // zero division check
    result = (float)num1 / (num2 * num3);
    printf("The quotient of %d, %d and %d is %.2f\n", num1, num2, num3, result);
  } else {
    printf("Cannot perform division operation as one or more numbers are zero!");
  }

  //modulo operation
  if(num2 != 0) { // zero division check
    result = num1 % num2;
    printf("The remainder when %d is divided by %d is %.2f\n", num1, num2, result);
  } else {
    printf("Cannot perform modulo operation as second number is zero!");
  }

  return 0;
}