//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int board[5][5];
  int numbers[75];
  int i, j, k, num, cnt = 0, flag = 0;
  char c;

  // Initialize the board
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      if (i == 2 && j == 2) {
        board[i][j] = -1;
      } else {
        board[i][j] = 0;
      }
    }
  }

  // Generate the numbers
  for (i = 0; i < 75; i++) {
    numbers[i] = i + 1;
  }

  // Shuffle the numbers using Fisher-Yates algorithm
  srand(time(NULL));
  for (i = 74; i >= 0; i--) {
    j = rand() % (i + 1);
    num = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = num;
  }

  // Print the board and the first number
  printf("Welcome to the C Bingo Simulator!\n\n");
  printf("   B   I   N   G   O\n");
  printf(" -------------------\n");
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      if (board[i][j] == -1) {
        printf("  ");
      } else {
        printf(" %2d", board[i][j]);
      }
      if (j == 4) {
        printf("\n");
      } else {
        printf(" |");
      }
    }
    printf(" -------------------\n");
  }
  printf("\nThe first number is: %d\n\n", numbers[cnt++]);

  // Start the game loop
  while (1) {
    printf("Press 'Enter' to continue or 'Q' to quit.\n");
    c = getchar();
    if (c == 'q' || c == 'Q') {
      printf("\nThank you for playing the C Bingo Simulator!\n");
      return 0;
    }

    // Check for the number on the board
    flag = 0;
    for (i = 0; i < 5; i++) {
      for (j = 0; j < 5; j++) {
        if (board[i][j] == numbers[cnt - 1]) {
          board[i][j] = -2;
          flag = 1;
          break;
        }
      }
      if (flag) {
        break;
      }
    }

    // Print the updated board and number
    printf("\n   B   I   N   G   O\n");
    printf(" -------------------\n");
    for (i = 0; i < 5; i++) {
      for (j = 0; j < 5; j++) {
        if (board[i][j] == -1) {
          printf("  ");
        } else if (board[i][j] < 0) {
          printf(" --");
        } else {
          printf(" %2d", board[i][j]);
        }
        if (j == 4) {
          printf("\n");
        } else {
          printf(" |");
        }
      }
      printf(" -------------------\n");
    }
    printf("\nThe next number is: %d\n\n", numbers[cnt++]);

    // Check for a winner
    for (i = 0; i < 5; i++) {
      flag = 1;
      for (j = 0; j < 5; j++) {
        if (board[i][j] >= 0) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        printf("BINGO! You won with a row!\n");
        printf("Thanks for playing the C Bingo Simulator!\n");
        return 0;
      }
    }
    for (i = 0; i < 5; i++) {
      flag = 1;
      for (j = 0; j < 5; j++) {
        if (board[j][i] >= 0) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        printf("BINGO! You won with a column!\n");
        printf("Thanks for playing the C Bingo Simulator!\n");
        return 0;
      }
    }
    flag = 1;
    for (i = 0; i < 5; i++) {
      if (board[i][i] >= 0) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      printf("BINGO! You won with a diagonal!\n");
      printf("Thanks for playing the C Bingo Simulator!\n");
      return 0;
    }
    flag = 1;
    for (i = 0; i < 5; i++) {
      if (board[i][4 - i] >= 0) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      printf("BINGO! You won with a diagonal!\n");
      printf("Thanks for playing the C Bingo Simulator!\n");
      return 0;
    }

    // Check for a tie (all numbers called)
    if (cnt == 76) {
      printf("Tie game! Thanks for playing the C Bingo Simulator!\n");
      return 0;
    }
  }
}