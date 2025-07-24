//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int candidate1 = 0, candidate2 = 0;
  char voter_choice;
  
  printf("Welcome to the Retro Electronic Voting System!\n\n");
  printf("Press C for Candidate 1 or V for Candidate 2.\n");
  
  for (int i = 1; i <= 10; i++) {
    printf("\nVoter %d, what is your choice? ", i);
    scanf(" %c", &voter_choice);
    
    if (voter_choice == 'C' || voter_choice == 'c') {
      candidate1++;
      printf("You have voted for Candidate 1.\n");
    } else if (voter_choice == 'V' || voter_choice == 'v') {
      candidate2++;
      printf("You have voted for Candidate 2.\n");
    } else {
      printf("Invalid choice. Please try again.\n");
      i--;
    }
  }
  
  srand(time(NULL)); // Seed the random number generator with current time
  int winner = (rand() % 2) + 1; // Choose a random winner
  
  printf("\n\nVoting has closed!\n");
  printf("Results:\n");
  printf("Candidate 1: %d votes\n", candidate1);
  printf("Candidate 2: %d votes\n", candidate2);
  
  if (winner == 1) {
    printf("\nCandidate 1 is the randomly selected winner!\n");
  } else {
    printf("\nCandidate 2 is the randomly selected winner!\n");
  }
  
  return 0;
}