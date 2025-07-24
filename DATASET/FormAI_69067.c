//FormAI DATASET v1.0 Category: Memory Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROWS 4
#define COLS 4
#define MAX_ATTEMPTS 10

// Function prototypes
void initializeBoard(int board[ROWS][COLS]);
void displayBoard(int board[ROWS][COLS], int hidden[ROWS][COLS], int attempts);
int validateCoordinates(int row, int col, int hidden[ROWS][COLS]);
void updateHidden(int row1, int col1, int row2, int col2, int hidden[ROWS][COLS]);
int checkForWin(int hidden[ROWS][COLS]);

int main() {
  int board[ROWS][COLS];
  int hidden[ROWS][COLS];
  int row1, col1, row2, col2, temp;
  int attempts = 0;

  // Initialize board and hidden arrays
  initializeBoard(board);
  initializeBoard(hidden);

  // Display banner
  printf("---------------------\n");
  printf("| Medieval Memory Game |\n");
  printf("---------------------\n");
  printf("Match the pairs of knight helmets!\n");
  
  // Main game loop
  while (!checkForWin(hidden)) {
    // Display board
    displayBoard(board, hidden, attempts);

    // Get user input
    printf("Enter the coordinates of the first helmet (row col): ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the coordinates of the second helmet (row col): ");
    scanf("%d %d", &row2, &col2);

    // Verify input
    if (validateCoordinates(row1, col1, hidden) == 0 || validateCoordinates(row2, col2, hidden) == 0) {
      printf("Invalid coordinates! Please enter numbers between 1 and 4.\n");
      continue;
    }
    if (row1 == row2 && col1 == col2) {
      printf("You cannot choose the same helmet twice!\n");
      continue;
    }

    // If pairs match, update hidden array and continue
    if (board[row1-1][col1-1] == board[row2-1][col2-1]) {
      updateHidden(row1-1, col1-1, row2-1, col2-1, hidden);
      printf("You found a match!\n");
      continue;
    } 

    // Pairs do not match, give user another chance
    attempts++;
    if (attempts >= MAX_ATTEMPTS) {
      printf("You ran out of attempts! Game over.\n");
      break;
    } else {
      printf("Helmets did not match! You have %d attempts left.\n", MAX_ATTEMPTS - attempts);
    }
  }

  // Game over
  if (attempts < MAX_ATTEMPTS) {
    printf("Well done! You won the game in %d attempts!\n", attempts+1);
  }
  
  return 0;
}

// Initializes board to random values between 1 and 8
void initializeBoard(int board[ROWS][COLS]) {
  // Seed random number generator
  srand(time(NULL));

  // Iterate over each element in the array
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      // Assign a random value between 1 and 8 to the current element
      board[row][col] = rand() % 8 + 1;
    }
  }
}

// Displays current state of the game board
void displayBoard(int board[ROWS][COLS], int hidden[ROWS][COLS], int attempts) {
  printf("\n  1 2 3 4\n");
  printf(" +-+-+-+-+\n");
  for (int row = 0; row < ROWS; row++) {
    printf("%d|", row+1);
    for (int col = 0; col < COLS; col++) {
      if (hidden[row][col] == 0) {
        printf("?|");
      } else {
        printf("%d|", board[row][col]);
      }
    }
    printf("\n");
    printf(" +-+-+-+-+\n");
  }
  printf("Attempts remaining: %d\n\n", MAX_ATTEMPTS - attempts);
}

// Validates user input coordinates
int validateCoordinates(int row, int col, int hidden[ROWS][COLS]) {
  if (row > 0 && row < ROWS+1 && col > 0 && col < COLS+1 && hidden[row-1][col-1] == 0) {
    return 1;
  } else {
    return 0;
  }
}

// Updates the hidden array to reflect found pairs
void updateHidden(int row1, int col1, int row2, int col2, int hidden[ROWS][COLS]) {
  hidden[row1][col1] = 1;
  hidden[row2][col2] = 1;
}

// Checks if all pairs have been found
int checkForWin(int hidden[ROWS][COLS]) {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      if (hidden[row][col] == 0) {
        return 0;
      }
    }
  }
  return 1;
}