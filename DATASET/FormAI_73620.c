//FormAI DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>

int main() {
  int playerScore = 0, computerScore = 0, choice, playerNumber, computerNumber;
  printf("Welcome to the unique C game!\n");
  
  while (playerScore < 3 && computerScore < 3) {
    printf("Player, enter a number between 1 and 10: ");
    scanf("%d", &playerNumber);
    
    if (playerNumber < 1 || playerNumber > 10) {
      printf("Invalid input! Choose a number between 1 and 10.\n");
      continue;
    }
    
    computerNumber = rand() % 10 + 1;
    choice = playerNumber + computerNumber;
    printf("Computer chose %d. The sum is %d.\n", computerNumber, choice);
    
    if (choice % 2 == 0) {
      playerScore++;
      printf("Player wins this round!\n");
    }
    else {
      computerScore++;
      printf("Computer wins this round!\n");
    }
  }
  
  if (playerScore == 3) {
    printf("Congratulations! You won the game!\n");
  }
  else {
    printf("Sorry, you lost. Better luck next time!\n");
  }
  
  return 0;
}