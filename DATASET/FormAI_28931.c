//FormAI DATASET v1.0 Category: Funny ; Style: beginner-friendly
#include <stdio.h>

int main() {
  printf("Welcome to the Funny Number Printer!\n\n");
  printf("Enter a number between 0 and 10,000: ");

  int num;
  scanf("%d", &num);

  // Check if the number is within the valid range
  if (num < 0 || num > 10000) {
    printf("\nOops! That number is outside of the valid range.\n");
    return 0;
  }

  printf("\n\nYou entered: %d\n\nNow let's get funny...\n\n", num);

  // Print out the funny number sequence
  for (int i = 1; i <= num; i++) {
    if (i % 3 == 0 && i % 5 == 0) {
      printf("FizzBuzz\n");
    } else if (i % 3 == 0) {
      printf("Fizz\n");
    } else if (i % 5 == 0) {
      printf("Buzz\n");
    } else {
      printf("%d\n", i);
    }
  }

  return 0;
}