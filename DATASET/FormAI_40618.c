//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Alan Touring
#include <stdio.h>

int main() {
  int candidate1_votes = 0;
  int candidate2_votes = 0;
  int candidate3_votes = 0;
  int total_votes = 0;
  int vote;

  printf("---Welcome to the Electronic Voting System---\n\n");

  while (1) {
    printf("Please enter your vote (1 for Candidate 1, 2 for Candidate 2, 3 for Candidate 3, or 0 to exit): ");
    scanf("%d", &vote);

    if (vote == 0) {
      break;
    } else if (vote == 1) {
      candidate1_votes++;
    } else if (vote == 2) {
      candidate2_votes++;
    } else if (vote == 3) {
      candidate3_votes++;
    } else {
      printf("Invalid vote!\n");
    }

    total_votes++;
  }

  printf("\n---Election Results---\n\n");
  printf("Candidate 1: %d votes\n", candidate1_votes);
  printf("Candidate 2: %d votes\n", candidate2_votes);
  printf("Candidate 3: %d votes\n", candidate3_votes);
  printf("Total votes: %d\n", total_votes);

  if (candidate1_votes > candidate2_votes && candidate1_votes > candidate3_votes) {
    printf("Candidate 1 is the winner!\n");
  } else if (candidate2_votes > candidate1_votes && candidate2_votes > candidate3_votes) {
    printf("Candidate 2 is the winner!\n");
  } else if (candidate3_votes > candidate1_votes && candidate3_votes > candidate2_votes) {
    printf("Candidate 3 is the winner!\n");
  } else {
    printf("It's a tie!\n");
  }

  return 0;
}