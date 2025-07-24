//FormAI DATASET v1.0 Category: Scientific ; Style: lively
#include <stdio.h>

int main() {
  int num1, num2;
  printf("Welcome to the game of Numbers!\n");
  printf("Enter two numbers to get started:\n");
  scanf("%d%d", &num1, &num2);

  printf("Prime numbers between %d and %d are: \n", num1, num2);
  for (int i = num1; i <= num2; i++) {
    int isPrime = 1; // Assume number is prime by default
    for (int j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        isPrime = 0; // Number is not prime
        break;
      }
    }
    if (isPrime == 1 && i != 1) {
      printf("%d ", i);
    }
  }

  printf("\n\nPerfect squares between %d and %d are: \n", num1, num2);
  for (int i = num1; i <= num2; i++) {
    float squareRoot = sqrt(i);
    if (squareRoot == (int)squareRoot) {
      printf("%d ", i);
    }
  }

  printf("\n\nPalindrome numbers between %d and %d are: \n", num1, num2);
  for (int i = num1; i <= num2; i++) {
    int originalNum = i;
    int reversedNum = 0;
    while (originalNum != 0) {
      reversedNum = reversedNum * 10 + originalNum % 10;
      originalNum /= 10;
    }
    if (i == reversedNum) {
      printf("%d ", i);
    }
  }

  printf("\n\nThanks for playing the game of Numbers!\n");
  return 0;
}