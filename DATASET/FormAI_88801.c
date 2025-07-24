//FormAI DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// Declare and initialize the 2D array with 16 integers
int arr[ROWS][COLS] = {{0, 1, 2, 3},
                       {4, 5, 6, 7},
                       {8, 9, 10, 11},
                       {12, 13, 14, 15}};

// Declare and initialize the 2D array with 16 booleans
_Bool found[ROWS][COLS] = {{0, 0, 0, 0},
                           {0, 0, 0, 0},
                           {0, 0, 0, 0},
                           {0, 0, 0, 0}};

// Function to print the game board
void print_board() {
  printf("\n\nMEMORY GAME\n\n");

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (found[i][j]) {
        printf("%2d ", arr[i][j]);
      } else {
        printf("## ");
      }
    }
    printf("\n");
  }
}

// Function to check if the game is won
_Bool is_game_won() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (!found[i][j]) {
        return 0;
      }
    }
  }

  return 1;
}

// Function to prompt the user and flip a card
void prompt_flip(int* row1, int* col1, int* row2, int* col2) {
  printf("Enter row and column numbers for the first card:\n");
  scanf("%d %d", row1, col1);

  while (found[*row1][*col1]) {
    printf("That card was already flipped. Enter new row and column numbers for the first card:\n");
    scanf("%d %d", row1, col1);
  }

  found[*row1][*col1] = 1;

  printf("Enter row and column numbers for the second card:\n");
  scanf("%d %d", row2, col2);

  while ((*row1 == *row2 && *col1 == *col2) || found[*row2][*col2]) {
    printf("Invalid input. Enter new row and column numbers for the second card:\n");
    scanf("%d %d", row2, col2);
  }

  found[*row2][*col2] = 1;
}

void sleep(unsigned int sec) {
  unsigned int ret_time = time(0) + sec; 

  while (time(0) < ret_time);
}

int main() {
  srand(time(NULL));

  // Shuffle the array
  for (int i = ROWS * COLS - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    int tmp = arr[i / ROWS][i % COLS];
    arr[i / ROWS][i % COLS] = arr[j / ROWS][j % COLS];
    arr[j / ROWS][j % COLS] = tmp;
  }

  // Main game loop
  while (!is_game_won()) {
    print_board();

    int row1, col1, row2, col2;
    prompt_flip(&row1, &col1, &row2, &col2);

    print_board();

    if (arr[row1][col1] == arr[row2][col2]) {
      printf("You found a match!\n");
    } else {
      printf("Sorry, no match!\n");
      sleep(2);
      found[row1][col1] = 0;
      found[row2][col2] = 0;
    }
  }

  printf("\n\nCongratulations, you won the game!\n");
  return 0;
}