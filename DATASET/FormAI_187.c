//FormAI DATASET v1.0 Category: Educational ; Style: excited
#include <stdio.h>

int main() {
  printf("Welcome to the exciting world of programming!\n");

  printf("In this program, we will be calculating the area of a circle.\n");

  float radius;
  printf("Please enter the radius of the circle: ");
  scanf("%f", &radius);

  const float pi = 3.14159265359;
  float area = pi * radius * radius;

  printf("The area of the circle with radius %.2f is %.2f.\n", radius, area);

  printf("Now let's move on to something more fun - let's play a guessing game!\n");

  int secret_number = 10;
  int guess;
  int tries = 0;

  do {
    printf("Guess a number between 1 and 20: ");
    scanf("%d", &guess);

    tries++;

    if (guess < secret_number) {
      printf("Sorry, your guess is too low. Try again!\n");
    } else if (guess > secret_number) {
      printf("Sorry, your guess is too high. Try again!\n");
    } else {
      printf("Congratulations, you guessed the secret number in %d tries!\n", tries);
    }
  } while (guess != secret_number);

  printf("Thanks for playing. Until next time! :)\n");

  return 0;
}