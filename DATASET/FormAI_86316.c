//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

// function prototypes
void print_card(int card[ROWS][COLS]);
bool check_card(int card[ROWS][COLS], bool called_numbers[76]);

int main() {
  int card[ROWS][COLS] = {{0}};
  bool called_numbers[76] = {false};

  srand(time(NULL)); // seed random number generator with current time

  // randomly generate bingo card
  for (int col = 0; col < COLS; col++) {
    // each column can have up to 1-2 non-zero numbers
    int non_zero_count = rand() % 3;
    
    for (int i = 0; i < non_zero_count; i++) {
      int row = rand() % ROWS;
      
      // generate a unique random number for the given column
      bool number_is_unique = false;
      while (!number_is_unique) {
        int num = (col * 15) + (rand() % 15) + 1;
        
        // check if the number is already in the card
        bool number_already_exists = false;
        for (int j = 0; j < ROWS; j++) {
          if (card[j][col] == num) {
            number_already_exists = true;
            break;
          }
        }
        
        if (!number_already_exists) {
          card[row][col] = num;
          number_is_unique = true;
        }
      }
    }
  }
  
  printf("Your bingo card:\n");
  print_card(card);
  
  // play game until someone wins
  bool game_over = false;
  while (!game_over) {
    // randomly generate a number between 1 and 75
    int num = (rand() % 75) + 1;
    called_numbers[num] = true;
    
    printf("Next number: %d\n", num);
    
    // check if the called number is on the card
    if (check_card(card, called_numbers)) {
      printf("Bingo! You win!\n");
      game_over = true;
    }
  }
  
  return 0;
}

// print bingo card
void print_card(int card[ROWS][COLS]) {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      printf("%2d ", card[row][col]);
    }
    printf("\n");
  }
}

// check if the card has a bingo
bool check_card(int card[ROWS][COLS], bool called_numbers[76]) {
  // check rows
  for (int row = 0; row < ROWS; row++) {
    bool bingo = true;
    for (int col = 0; col < COLS; col++) {
      if (!called_numbers[card[row][col]]) {
        bingo = false;
        break;
      }
    }
    if (bingo) {
      return true;
    }
  }
  
  // check columns
  for (int col = 0; col < COLS; col++) {
    bool bingo = true;
    for (int row = 0; row < ROWS; row++) {
      if (!called_numbers[card[row][col]]) {
        bingo = false;
        break;
      }
    }
    if (bingo) {
      return true;
    }
  }
  
  // check diagonals
  bool bingo1 = true, bingo2 = true;
  for (int i = 0; i < ROWS; i++) {
    if (!called_numbers[card[i][i]]) {
      bingo1 = false;
    }
    if (!called_numbers[card[i][COLS-1-i]]) {
      bingo2 = false;
    }
  }
  if (bingo1 || bingo2) {
    return true;
  }
  
  // no bingo
  return false;
}