//FormAI DATASET v1.0 Category: Game ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_GUESSES 10

int generate_random_number(int lower, int upper) { // function to generate random number between a given range
  srand(time(NULL)); // seeding with current time
  int num = (rand() % (upper - lower + 1)) + lower;
  return num;
}

int main() {
  int lower = 1, upper = 100; // initialize lower and upper bound of random number
  int rand_num = generate_random_number(lower, upper); // generate a random number between the range
  
  printf("***Welcome to the Guessing Number Game!***\n");
  printf("You have %d attempts to guess the number between %d - %d \n", MAX_GUESSES, lower, upper);
  
  int guess, num_guesses = 0;
  
  while(num_guesses < MAX_GUESSES) { // keep iterating until max attempts are reached
    printf("Guess the number: ");
    scanf("%d", &guess);
    
    if(guess == rand_num) { // If the number guessed is correct
      printf("Congratulations! You have guessed the number in %d attempts.\n", num_guesses + 1);
      break;
    } else if(guess < rand_num) { // If guessed number is smaller than actual number
      printf("The number is greater than %d\n", guess);
    } else { // If guessed number is greater than actual number
      printf("The number is smaller than %d\n", guess);
    }
    num_guesses++;
  }
  
  if(num_guesses == MAX_GUESSES) { // if all the attempts have been made
    printf("Game over! You could not guess the number in %d attempts. Number was %d\n", MAX_GUESSES, rand_num);
  }
  return 0;
}