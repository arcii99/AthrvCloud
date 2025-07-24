//FormAI DATASET v1.0 Category: Funny ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int input, num;
  char repeat = 'y';
  
  srand(time(0)); // This initializes the random number generator
  
  while (repeat == 'y') { // Loop until user decides to stop
    
    printf("Guess a number between 1 and 100: ");
    scanf("%d", &input);
    
    num = rand() % 100 + 1; // Generate a random number between 1 and 100
    
    if (input == num) {
      printf("Congratulations! You guessed the number!\n");
    } else {
      printf("Sorry, the number was %d.\n", num);
    }
    
    printf("Would you like to play again? (y/n)\n");
    scanf(" %c", &repeat);
    
  }
  
  while (1) { // This loop may never end
    
    printf("Do you believe that we will break this loop?\n");
  }
  
  return 0;
}