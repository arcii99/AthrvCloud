//FormAI DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize variables
  int guess, num, tries = 0;
  
  // Generate random number between 1 and 100
  srand(time(0));
  num = rand() % 100 + 1;
  
  // Start game
  printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n");
  
  // Loop until correct guess
  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    tries++;
    
    // Check if guess is correct
    if (guess == num) {
      printf("Congratulations! You guessed the correct number in %d tries.\n", tries);
    } else if (guess < num) {
      printf("Sorry, your guess is too low. Try again.\n");
    } else {
      printf("Sorry, your guess is too high. Try again.\n");
    }
  } while (guess != num);
  
  return 0;
}