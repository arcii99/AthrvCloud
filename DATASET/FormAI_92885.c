//FormAI DATASET v1.0 Category: Math exercise ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {

  // Seed the random number generator
  srand(time(NULL));

  // Generate two random numbers between 1 and 50
  int num1 = rand() % 50 + 1;
  int num2 = rand() % 50 + 1;

  // Calculate the sum of the two numbers
  int sum = num1 + num2;

  // Calculate the difference of the two numbers
  int diff = num1 - num2;

  // Calculate the product of the two numbers
  int product = num1 * num2;

  // Calculate the quotient of the two numbers
  float quotient = (float)num1 / (float)num2;

  // Calculate the remainder when num1 is divided by num2
  int remainder = num1 % num2;

  // Calculate the square root of num1
  float sqrtNum1 = sqrt(num1);

  // Calculate the square of num2
  int squareNum2 = pow(num2, 2);

  // Print out the math exercise
  printf("Welcome! Here is your math exercise:\n\n");
  printf("%d + %d = _____\n", num1, num2);
  printf("%d - %d = _____\n", num1, num2);
  printf("%d * %d = _____\n", num1, num2);
  printf("%d / %d = _____\n", num1, num2);
  printf("%d %% %d = _____\n", num1, num2);
  printf("√%d = _____\n", num1);
  printf("%d^2 = _____\n", num2);

  // Prompt user for answers and store them in variables
  int answerSum, answerDiff, answerProduct, answerRemainder, answerSquareNum2;
  float answerQuotient, answerSqrtNum1;
  printf("\nEnter your answers (decimals for division, round to 2 decimal places): \n");
  scanf("%d %d %d %f %d %f %d", &answerSum, &answerDiff, &answerProduct, &answerQuotient, &answerRemainder, &answerSqrtNum1, &answerSquareNum2);

  // Check user's answers and print if correct or incorrect
  printf("\nResults:\n\n");
  if (answerSum == sum) {
    printf("The answer to %d + %d is %d. Great job!\n", num1, num2, sum);
  } else {
    printf("Sorry, the answer to %d + %d is %d.\n", num1, num2, sum);
  }

  if (answerDiff == diff) {
    printf("The answer to %d - %d is %d. You're on fire!\n", num1, num2, diff);
  } else {
    printf("Oops, the answer to %d - %d is %d.\n", num1, num2, diff);
  }

  if (answerProduct == product) {
    printf("The answer to %d * %d is %d. Keep it up!\n", num1, num2, product);
  } else {
    printf("Nope, the answer to %d * %d is %d.\n", num1, num2, product);
  }

  if (answerQuotient == quotient) {
    printf("The answer to %d / %d is %.2f. Fantastic!\n", num1, num2, quotient);
  } else {
    printf("Sorry, the answer to %d / %d is %.2f.\n", num1, num2, quotient);
  }

  if (answerRemainder == remainder) {
    printf("The answer to %d %% %d is %d. You're unstoppable!\n", num1, num2, remainder);
  } else {
    printf("Uh-oh, the answer to %d %% %d is %d.\n", num1, num2, remainder);
  }

  if (fabs(answerSqrtNum1 - sqrtNum1) <= 0.01) {
    printf("The answer to √%d is %.2f. Way to go!\n", num1, sqrtNum1);
  } else {
    printf("Oops, the answer to √%d is %.2f.\n", num1, sqrtNum1);
  }

  if (answerSquareNum2 == squareNum2) {
    printf("The answer to %d^2 is %d. That's amazing!\n", num2, squareNum2);
  } else {
    printf("Nope, the answer to %d^2 is %d.\n", num2, squareNum2);
  }

  // End of program
  printf("\nThanks for playing! Come back again soon!\n");

  return 0;
}