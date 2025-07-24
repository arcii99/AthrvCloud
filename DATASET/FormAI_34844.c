//FormAI DATASET v1.0 Category: Memory Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

// Function to print the game board
void print_board(int board[][SIZE], int revealed[][SIZE]) {
  printf("\n    ");
  for (int i = 1; i <= SIZE; i++) {
    printf("%d   ", i);
  }
  printf("\n  ");
  for (int i = 0; i <= SIZE; i++) {
    printf("____");
  }
  printf("\n");
  for (int i = 0; i < SIZE; i++) {
    printf("%c | ", 'A' + i);
    for (int j = 0; j < SIZE; j++) {
      if (revealed[i][j]) {
        printf("%d | ", board[i][j]);
      } else {
        printf("? | ");
      }
    }
    printf("\n  ");
    for (int j = 0; j <= SIZE; j++) {
      printf("____");
    }
    printf("\n");
  }
}

// Function to check if the game is over or not
int is_game_over(int revealed[][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (!revealed[i][j]) return 0;
    }
  }
  return 1;
}

// Main function
int main() {
  srand(time(0));
  int board[SIZE][SIZE];
  int revealed[SIZE][SIZE] = {0};

  // Initialise the game board
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = rand() % 10;
    }
  }

  // Print the game board
  print_board(board, revealed);

  // Game loop
  while (!is_game_over(revealed)) {
    int i1, j1, i2, j2;
    do {
      printf("\nEnter the row and column of the first card (e.g. A 3): ");
      scanf(" %c %d", &i1, &j1);
      getchar();
      i1 -= 'A';
      j1--;
    } while (i1 < 0 || i1 >= SIZE || j1 < 0 || j1 >= SIZE || revealed[i1][j1]);

    printf("Enter the row and column of the second card (e.g. B 2): ");
    do {
      scanf(" %c %d", &i2, &j2);
      getchar();
      i2 -= 'A';
      j2--;
    } while (i2 < 0 || i2 >= SIZE || j2 < 0 || j2 >= SIZE || revealed[i2][j2] || (i1 == i2 && j1 == j2));

    // Check if the two cards match
    if (board[i1][j1] == board[i2][j2]) {
      revealed[i1][j1] = 1;
      revealed[i2][j2] = 1;
      printf("\nMatch found!\n");
    } else {
      printf("\nNo match!\n");
    }

    // Print the game board after each turn
    print_board(board, revealed);
  }

  printf("\nCongratulations! You have won the game!\n");
  return 0;
}