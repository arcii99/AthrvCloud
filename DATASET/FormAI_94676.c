//FormAI DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, playerCount, roundCount, score, answer, userAnswer;
  srand(time(NULL));

  // Prompt the user for the number of players and rounds
  printf("Enter the number of players: ");
  scanf("%d", &playerCount);

  printf("Enter the number of rounds: ");
  scanf("%d", &roundCount);

  // Loop through the rounds
  for (i = 1; i <= roundCount; i++) {
    printf("\nRound %d\n", i);

    // Loop through each player in the round
    for (int j = 1; j <= playerCount; j++) {
      score = 0;
      printf("Player %d's turn\n", j);

      // Generate two random numbers and prompt the player for the answer
      int num1 = rand() % 10 + 1;
      int num2 = rand() % 10 + 1;
      printf("%d + %d = ", num1, num2);
      scanf("%d", &userAnswer);

      // Calculate the correct answer and compare it to the player's answer
      answer = num1 + num2;
      if (userAnswer == answer) {
        score++;
        printf("Correct! Player %d has %d point(s).\n", j, score);
      } else {
        printf("Incorrect. The correct answer is %d. Player %d has %d point(s).\n", answer, j, score);
      }
    }
  }

  printf("\nGame Over\n");

  return 0;
}