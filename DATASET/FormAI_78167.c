//FormAI DATASET v1.0 Category: Memory Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 4
#define COLS 4

// Displays the game board
void display_board(int board[ROWS][COLS], int flipped[ROWS][COLS]) {
  printf("\n   1  2  3  4\n");
  printf(" -------------\n");
  for (int i = 0; i < ROWS; i++) {
    printf("%d |", i+1);
    for (int j = 0; j < COLS; j++) {
      if (flipped[i][j]) {
        printf("%3d", board[i][j]);
      } else {
        printf("  o");
      }
    }
    printf("\n");
  }
}

// Checks if two cards match
int match(int card1, int card2) {
  if (card1 == card2) {
    return 1;
  } else {
    return 0;
  }
}

int main() {

  int board[ROWS][COLS] = {0};
  int flipped[ROWS][COLS] = {0};
  int numPairs = ROWS * COLS / 2; // number of pairs of cards = number of spaces on board / 2
  int pairsGuessed = 0; // number of pairs guessed correctly
  int row1, col1, row2, col2; // coordinates of two cards the player flips over
  int card1, card2; // values of cards at coordinates (row1,col1) and (row2,col2)

  srand(time(NULL)); // seed the random number generator

  // randomly distribute cards on the board
  for (int i = 1; i <= numPairs; i++) {
    int row, col;
    do {
      row = rand() % ROWS;
      col = rand() % COLS;
    } while (board[row][col] != 0);
    board[row][col] = i;
    do {
      row = rand() % ROWS;
      col = rand() % COLS;
    } while (board[row][col] != 0);
    board[row][col] = i;
  }

  printf("Welcome to the Memory Game!\n");
  printf("There are %d pairs of cards on the board.\n", numPairs);
  display_board(board, flipped);

  while (pairsGuessed < numPairs) {
    printf("Enter the row and column of the first card you want to flip: ");
    scanf("%d %d", &row1, &col1);
    if (row1 < 1 || row1 > ROWS || col1 < 1 || col1 > COLS) { // check if input is out of bounds
      printf("Invalid input. Try again.\n");
      continue;
    }
    row1--;
    col1--;

    if (flipped[row1][col1]) { // check if card has already been flipped
      printf("That card has already been flipped. Try again.\n");
      continue;
    }

    flipped[row1][col1] = 1;
    card1 = board[row1][col1];

    display_board(board, flipped);

    printf("Enter the row and column of the second card you want to flip: ");
    scanf("%d %d", &row2, &col2);
    if (row2 < 1 || row2 > ROWS || col2 < 1 || col2 > COLS) { // check if input is out of bounds
      printf("Invalid input. Try again.\n");
      flipped[row1][col1] = 0; // flip first card back over
      continue;
    }
    row2--;
    col2--;

    if (flipped[row2][col2]) { // check if card has already been flipped
      printf("That card has already been flipped. Try again.\n");
      flipped[row1][col1] = 0; // flip first card back over
      continue;
    }

    flipped[row2][col2] = 1;
    card2 = board[row2][col2];

    display_board(board, flipped);

    printf("Card 1: %d\n", card1);
    printf("Card 2: %d\n", card2);

    if (match(card1,card2)) {
      printf("Congratulations, you guessed correctly!\n");
      pairsGuessed++;
    } else {
      printf("Sorry, those cards don't match. Better luck next time!\n");
      flipped[row1][col1] = 0; // flip first card back over
      flipped[row2][col2] = 0; // flip second card back over
    }
  }

  printf("Well done, you matched all the cards! Thanks for playing.\n");

  return 0;
}