//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, k;
  printf("Enter the number of players: ");
  scanf("%d", &n);
  printf("Enter the maximum number of rounds: ");
  scanf("%d", &k);

  int scores[n];
  for (int i = 0; i < n; i++) {
    scores[i] = 0;
  }

  int round = 1;
  while (round <= k) {
    printf("Round %d:\n", round);
    for (int i = 0; i < n; i++) {
      int score;
      printf("Player %d enter your score: ", i+1);
      scanf("%d", &score);
      scores[i] += score;
    }
    printf("Current scores: ");
    for (int i = 0; i < n; i++) {
      printf("%d ", scores[i]);
    }
    printf("\n");
    round++;
  }

  int max_score = 0, winner = 0;
  for (int i = 0; i < n; i++) {
    if (scores[i] > max_score) {
      max_score = scores[i];
      winner = i+1;
    }
  }
  printf("Player %d wins with a score of %d!\n", winner, max_score);

  return 0;
}