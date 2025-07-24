//FormAI DATASET v1.0 Category: Memory Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS (BOARD_SIZE * BOARD_SIZE / 2)

typedef struct 
{
  int row;
  int column;
} position;

void initialize_board(int board[][BOARD_SIZE])
{
  int pairs[NUM_PAIRS];

  // Populate pairs array with the numbers we want on the board
  for (int i = 0; i < NUM_PAIRS; i++) 
  {
    pairs[i] = i + 1;
  }

  // Shuffle the pairs array using Fisher-Yates algorithm
  for (int i = NUM_PAIRS - 1; i > 0; i--) 
  {
    // Generate a random index between 0 and i (inclusive)
    int j = rand() % (i + 1);

    // Swap the pair at index i with the pair at index j
    int temp = pairs[i];
    pairs[i] = pairs[j];
    pairs[j] = temp;
  }

  // Place pairs on the board
  int pair_index = 0;
  for (int i = 0; i < BOARD_SIZE; i++) 
  {
    for (int j = 0; j < BOARD_SIZE; j++) 
    {
      board[i][j] = pairs[pair_index];
      pair_index++;
    }
  }
}

void print_board(int board[][BOARD_SIZE], int num_revealed, position* revealed_positions) 
{
  for (int i = 0; i < BOARD_SIZE; i++) 
  {
    for (int j = 0; j < BOARD_SIZE; j++) 
    {
      if (num_revealed > 0) 
      {
        int match_found = 0;
        for (int k = 0; k < num_revealed; k++) 
        {
          if (i == revealed_positions[k].row && j == revealed_positions[k].column) 
          {
            printf("%d ", board[i][j]);
            match_found = 1;
            break;
          }
        }
        if (!match_found) 
        {
          printf("X ");
        }
      } 
      else 
      {
        printf("X ");
      }
    }
    printf("\n");
  }
}

int main() 
{
  int board[BOARD_SIZE][BOARD_SIZE];
  position revealed_positions[2];
  int num_pairs_revealed = 0;
  
  initialize_board(board); // set up the board

  while (num_pairs_revealed < NUM_PAIRS) 
  {
    print_board(board, num_pairs_revealed * 2, revealed_positions); // print the current board with revealed positions

    int row;
    int column;

    // Prompt player to choose a position to reveal
    do 
    {
      printf("Choose a row (0 - %d) and column (0 - %d): ", BOARD_SIZE - 1, BOARD_SIZE - 1);
      scanf("%d %d", &row, &column);

      if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE) 
      {
        printf("Invalid position. Please try again.\n");
      }
      else 
      {
        int already_revealed = 0;
        for (int i = 0; i < num_pairs_revealed * 2; i++) 
        {
          if (row == revealed_positions[i].row && column == revealed_positions[i].column) 
          {
            printf("Position already revealed. Please try again.\n");
            already_revealed = 1;
            break;
          }
        }
        if (!already_revealed) 
        {
          break;
        }
      }
    } 
    while (1);

    // Reveal the chosen position
    revealed_positions[num_pairs_revealed * 2].row = row;
    revealed_positions[num_pairs_revealed * 2].column = column;

    printf("The number at [%d, %d] is %d.\n", row, column, board[row][column]);

    num_pairs_revealed += 1;

    if (num_pairs_revealed == NUM_PAIRS) 
    {
      printf("Great job, you won!\n");
      break;
    }

    // Prompt player to choose a second position to reveal
    do 
    {
      printf("Choose another row (0 - %d) and column (0 - %d): ", BOARD_SIZE - 1, BOARD_SIZE - 1);
      scanf("%d %d", &row, &column);

      if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE) 
      {
        printf("Invalid position. Please try again.\n");
      }
      else 
      {
        int already_revealed = 0;
        for (int i = 0; i < num_pairs_revealed * 2 - 1; i++) 
        {
          if (row == revealed_positions[i].row && column == revealed_positions[i].column) 
          {
            printf("Position already revealed. Please try again.\n");
            already_revealed = 1;
            break;
          }
        }
        if (!already_revealed) 
        {
          break;
        }
      }
    } 
    while (1);

    // Reveal the second chosen position
    revealed_positions[num_pairs_revealed * 2 - 1].row = row;
    revealed_positions[num_pairs_revealed * 2 - 1].column = column;

    printf("The number at [%d, %d] is %d.\n", row, column, board[row][column]);

    num_pairs_revealed += 1;

    if (board[revealed_positions[num_pairs_revealed * 2 - 2].row][revealed_positions[num_pairs_revealed * 2 - 2].column]
        != board[revealed_positions[num_pairs_revealed * 2 - 1].row][revealed_positions[num_pairs_revealed * 2 - 1].column]) 
    {
      printf("Sorry, no match. Try again.\n");

      // Hide the previously revealed positions
      revealed_positions[num_pairs_revealed * 2 - 2].row = -1;
      revealed_positions[num_pairs_revealed * 2 - 2].column = -1;
      revealed_positions[num_pairs_revealed * 2 - 1].row = -1;
      revealed_positions[num_pairs_revealed * 2 - 1].column = -1;

      num_pairs_revealed -= 1;
    } 
    else 
    {
      printf("Match found!\n");
    }
  }

  return 0;
}