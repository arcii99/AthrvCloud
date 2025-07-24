//FormAI DATASET v1.0 Category: Educational ; Style: puzzling
#include <stdio.h>

int main() {
  int x = 3;
  float y = 4.5;
  char z = '!';

  int result1 = x * y + z;
  float result2 = x / y + z;
  char result3 = x + y / z;

  if (result1 > result2 && result1 > result3) {
    printf("The largest result is: %d\n", result1);
  } else if (result2 > result1 && result2 > result3) {
    printf("The largest result is: %.2f\n", result2);
  } else {
    printf("The largest result is: %c\n", result3);
  }

  int secretNumber = 42;
  int guess;
  int tries = 0;

  printf("Welcome to the Guessing Game!\n");
  
  do {
    printf("Enter your guess (between 1 and 100): ");
    scanf("%d", &guess);
    tries++;
    
    if (guess < secretNumber) {
      printf("Too low! Try again.\n");
    } else if (guess > secretNumber) {
      printf("Too high! Try again.\n");
    } else {
      printf("Congratulations! You guessed the secret number in %d tries.\n", tries);
    }
  } while (guess != secretNumber);

  return 0;
}