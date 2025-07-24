//FormAI DATASET v1.0 Category: Chess engine ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'-', '-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-', '-'},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

int evaluate(char board[8][8]) {
   int i, j, score = 0;
   for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
         if (board[i][j] == 'P')
            score += 1;
         else if (board[i][j] == 'N')
            score += 3;
         else if (board[i][j] == 'B')
            score += 3;
         else if (board[i][j] == 'R')
            score += 5;
         else if (board[i][j] == 'Q')
            score += 9;
         else if (board[i][j] == 'p')
            score -= 1;
         else if (board[i][j] == 'n')
            score -= 3;
         else if (board[i][j] == 'b')
            score -= 3;
         else if (board[i][j] == 'r')
            score -= 5;
         else if (board[i][j] == 'q')
            score -= 9;
      }
   }
   return score;
}

int main() {
   int i, j;
   printf("Welcome to the chess engine!\n");
   while (1) {
      printf("Current State:\n");
      for (i = 0; i < 8; i++) {
         for (j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
         }
         printf("\n");
      }
      printf("Current Score: %d\n", evaluate(board));
      printf("Thinking...\n");
      srand(time(0));
      int move = rand() % 8;
      printf("I will move %d spaces.\n", move);
   }
   return 0;
}