//FormAI DATASET v1.0 Category: Random ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  printf("Welcome to the introspective C Random Number Guessing Game!\n");
  printf("Think of a number between 1 and 100, and I will try to guess it.\n");
  
  int guess = 0;
  int min = 1;
  int max = 100;
  int num_guesses = 0;
  
  srand(time(NULL)); // Seed the random number generator with the current time
  while (1){ // Keep looping until we guess the correct number
    guess = rand() % (max - min + 1) + min; // Generate a random guess
    
    printf("Is your number %d? (y/n): ", guess);
    char response = getchar();
    while (getchar() != '\n'); // Clear the input buffer
    
    if (response == 'y'){ // We got it right!
      printf("I knew it! It took me %d guesses.\n", num_guesses);
      break; // Exit the loop
    }
    else{ // We didn't get it right
      printf("Hmm, that wasn't it...\n");
      printf("Was it higher or lower than %d? (h/l): ", guess);
      response = getchar();
      while (getchar() != '\n'); // Clear the input buffer
      
      if (response == 'h'){ // The number is higher
        min = guess + 1; // Update the lower bound
      }
      else if (response == 'l'){ // The number is lower
        max = guess - 1; // Update the upper bound
      }
      else{ // Invalid response
        printf("Sorry, I didn't understand that.\n");
      }
    }
    
    num_guesses++; // Increment the number of guesses we've made
  }
  
  return 0;
}