//FormAI DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int guess_count = 1, guess_limit = 10;
  int number_to_guess, guessed_number, is_game_over = 0;
  
  srand(time(0));
  number_to_guess = rand() % 100 + 1;

  printf("I am thinking of a number between 1 and 100. Can you guess it?\n");

  while (guess_count <= guess_limit && !is_game_over)
  {
    printf("Enter your guess: ");
    scanf("%d", &guessed_number);

    if (guessed_number == number_to_guess)
    {
      printf("Congratulations! You guessed the number!\n");
      is_game_over = 1;
    }
    else if (guessed_number < number_to_guess)
    {
      printf("Your guess is too low. Try again.\n");
    }
    else
    {
      printf("Your guess is too high. Try again.\n");
    }

    guess_count++;
  }

  if (!is_game_over)
  {
    printf("Sorry, you have reached the guess limit. The number was %d.\n", number_to_guess);
  }

  return 0;
}