//FormAI DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 4
#define TOTAL_CARDS 20

void print_board(int board[ROWS][COLS], int revealed[ROWS][COLS]) {
  printf("\nMemory Game:\n\n");
  printf("\t0\t1\t2\t3\n");
  
  for (int i = 0; i < ROWS; i++) {
    printf("%d", i);
    for (int j = 0; j < COLS; j++) {
      if (revealed[i][j] == 0) {
        printf("\t?");
      } else {
        printf("\t%d", board[i][j]);
      }
    }
    printf("\n");
  }
}

void initialize_board(int board[ROWS][COLS], int revealed[ROWS][COLS]) {
  int random_numbers[TOTAL_CARDS];
  
  for (int i = 0; i < TOTAL_CARDS; i++) {
    random_numbers[i] = i / 2 + 1;
  }
  
  srand(time(NULL));
  
  for (int i = 0; i < TOTAL_CARDS; i++) {
    int random_index = rand() % TOTAL_CARDS;
    int temp = random_numbers[i];
    random_numbers[i] = random_numbers[random_index];
    random_numbers[random_index] = temp;
  }
  
  int count = 0;
  
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      board[i][j] = random_numbers[count];
      count++;
      revealed[i][j] = 0;
    }
  }
}

int main() {
  int board[ROWS][COLS];
  int revealed[ROWS][COLS];
  int first_card_row, first_card_col;
  
  initialize_board(board, revealed);
  print_board(board, revealed);
  
  while (1) {
    
    printf("\nEnter the row and column of the first card: ");
    scanf("%d %d", &first_card_row, &first_card_col);
    
    printf("\n");
    print_board(board, revealed);
    
    revealed[first_card_row][first_card_col] = 1;
    
    int second_card_row, second_card_col;
    printf("\nEnter the row and column of the second card: ");
    scanf("%d %d", &second_card_row, &second_card_col);
    
    printf("\n");
    print_board(board, revealed);
    
    revealed[second_card_row][second_card_col] = 1;
    
    if (board[first_card_row][first_card_col] == board[second_card_row][second_card_col]) {
      printf("\nMatch found!\n");
    } else {
      printf("\nNo match found.\n");
      revealed[first_card_row][first_card_col] = 0;
      revealed[second_card_row][second_card_col] = 0;
    }
    
    int all_cards_revealed = 1;
    
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (revealed[i][j] == 0) {
          all_cards_revealed = 0;
          break;
        }
      }
      if (all_cards_revealed == 0) {
        break;
      }
    }
    
    if (all_cards_revealed == 1) {
      printf("\nCongratulations! You won!\n");
      break;
    }
    
  }
  
  return 0;
}