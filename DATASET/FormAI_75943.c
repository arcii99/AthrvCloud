//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 20

int main() {
  int num_voters, num_candidates;
  int voters[MAX_VOTERS][MAX_CANDIDATES] = {0}; // initialize all votes to zero
  int candidate_votes[MAX_CANDIDATES] = {0}; // initialize all votes to zero

  printf("Welcome to the Cryptic Electronic Voting System!\n");

  // get number of voters
  printf("Enter number of voters: ");
  scanf("%d", &num_voters);

  // get number of candidates
  printf("Enter number of candidates (maximum 20): ");
  scanf("%d", &num_candidates);

  // limit number of candidates to 20
  if (num_candidates > MAX_CANDIDATES) {
    printf("Error: Maximum number of candidates is 20.\n");
    exit(EXIT_FAILURE);
  }

  // record each voter's choice
  for (int i = 0; i < num_voters; i++) {
    printf("Voter %d, please enter your choice (1-%d): ", i+1, num_candidates);
    int choice;
    scanf("%d", &choice);

    // validate choice
    if (choice < 1 || choice > num_candidates) {
      printf("Error: Invalid choice.\n");
      exit(EXIT_FAILURE);
    }

    // record vote
    voters[i][choice-1] = 1;
  }

  // count votes for each candidate
  for (int i = 0; i < num_candidates; i++) {
    for (int j = 0; j < num_voters; j++) {
      if (voters[j][i]) {
        candidate_votes[i]++;
      }
    }
  }

  // determine winner
  int winner = 0;
  int max_votes = candidate_votes[0];
  for (int i = 1; i < num_candidates; i++) {
    if (candidate_votes[i] > max_votes) {
      winner = i;
      max_votes = candidate_votes[i];
    }
  }

  // display results
  printf("Results:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("Candidate %d received %d vote(s).\n", i+1, candidate_votes[i]);
  }
  printf("Candidate %d is the winner!\n", winner+1);

  return 0;
}