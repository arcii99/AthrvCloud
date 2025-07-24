//FormAI DATASET v1.0 Category: Funny ; Style: calm
#include <stdio.h>

int main() {
  
  printf("Welcome to the calm program!\n");
  printf("First, let's take a deep breath...\n");
  
  int i;
  for(i=0; i<3; i++) {
    printf(" *inhale* \n");
    printf(" *exhale* \n");
  }
  
  printf("Now that we're feeling calm, let's play a little game of rock-paper-scissors.\n");
  
  char userChoice, computerChoice;
  printf("Type r for rock, p for paper, or s for scissors:\n");
  scanf(" %c", &userChoice);
  
  // Generate random computer choice
  int randomNum = rand() % 3;
  if(randomNum == 0) {
    computerChoice = 'r';
  } else if(randomNum == 1) {
    computerChoice = 'p';
  } else {
    computerChoice = 's';
  }
  
  // Print out choices
  printf("You chose %c. The computer chose %c.\n", userChoice, computerChoice);
  
  // Determine winner
  if((userChoice == 'r' && computerChoice == 's') || 
     (userChoice == 'p' && computerChoice == 'r') ||
     (userChoice == 's' && computerChoice == 'p')) {
    printf("You win! Congratulations!\n");
  } else if((userChoice == 'r' && computerChoice == 'p') || 
            (userChoice == 'p' && computerChoice == 's') ||
            (userChoice == 's' && computerChoice == 'r')) {
    printf("The computer wins. Better luck next time!\n");
  } else {
    printf("It's a tie! Let's play again.\n");
  }
  
  printf("Thanks for playing! Remember to take a deep breath if you're ever feeling stressed.\n");
  
  return 0;
}