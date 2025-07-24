//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void generate_card(int card[ROWS][COLS]);
void display_card(int card[ROWS][COLS]);
int check_for_bingo(int card[ROWS][COLS]);
void mark_number(int card[ROWS][COLS], int number);

int main() {
  int card[ROWS][COLS];
  generate_card(card);
  display_card(card);

  printf("Bingo has started!\n");

  for (int i = 1; i <= 75; i++) {
    printf("Number %d:\n", i);
    mark_number(card, i);
    display_card(card);

    if (check_for_bingo(card) == 1) {
      printf("Bingo! You won on number %d.\n", i);
      return 0;
    }
  }

  printf("All numbers called and no Bingo. Better luck next time!\n");

  return 0;
}

void generate_card(int card[ROWS][COLS]) {
  srand(time(NULL));
  int min, max;

  // Initialize card with zeros
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      card[i][j] = 0;
    }
  }

  // Generate random numbers for each column
  for (int i = 0; i < COLS; i++) {
    min = i * 15 + 1;
    max = (i + 1) * 15;
    for (int j = 0; j < ROWS; j++) {
      int num;
      do {
        num = min + rand() % (max - min + 1);
      } while (num == card[0][i] ||
               num == card[1][i] ||
               num == card[2][i] ||
               num == card[3][i] ||
               num == card[4][i]);
      card[j][i] = num;
    }
  }

  // Mark center square as 'FREE'
  card[2][2] = -1;
}

void display_card(int card[ROWS][COLS]) {
  printf("+---+---+---+---+---+\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (card[i][j] == -1) {
        printf("|FREE");
      } else {
        printf("|%2d ", card[i][j]);
      }
    }
    printf("|\n");
    printf("+---+---+---+---+---+\n");
  }
}

int check_for_bingo(int card[ROWS][COLS]) {
  int bingo, row_sum, col_sum, diag1_sum, diag2_sum;

  // Check rows for bingo
  for (int i = 0; i < ROWS; i++) {
    row_sum = 0;
    for (int j = 0; j < COLS; j++) {
      row_sum += card[i][j];
    }
    if (row_sum == -5) {
      bingo = 1;
      return bingo;
    }
  }

  // Check columns for bingo
  for (int i = 0; i < COLS; i++) {
    col_sum = 0;
    for (int j = 0; j < ROWS; j++) {
      col_sum += card[j][i];
    }
    if (col_sum == -5) {
      bingo = 1;
      return bingo;
    }
  }

  // Check diagonal from top-left to bottom-right
  diag1_sum = card[0][0] + card[1][1] + card[2][2] + card[3][3] + card[4][4];
  if (diag1_sum == -5) {
    bingo = 1;
    return bingo;
  }

  // Check diagonal from bottom-left to top-right
  diag2_sum = card[0][4] + card[1][3] + card[2][2] + card[3][1] + card[4][0];
  if (diag2_sum == -5) {
    bingo = 1;
    return bingo;
  }

  // No bingo
  bingo = 0;
  return bingo;
}

void mark_number(int card[ROWS][COLS], int number) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (card[i][j] == number) {
        card[i][j] = -1;
      }
    }
  }
}