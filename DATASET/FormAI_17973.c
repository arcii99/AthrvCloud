//FormAI DATASET v1.0 Category: Checkers Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

void display_board(char board[][SIZE]); // function to display the checkers board
void initialize_board(char board[][SIZE]); // function to initialize the board with checkers
int move_checkers(char board[][SIZE], int x1, int y1, int x2, int y2, int player); // function to move checkers on the board
int check_valid_move(char board[][SIZE], int x1, int y1, int x2, int y2, int player); // function to check if move is valid
int check_board(char board[][SIZE], int player); // function to check if the game is over
int check_king(char board[][SIZE], int player); // function to check if a checker needs to be kinged

int main()
{
    char board[SIZE][SIZE];
    int player = 1;
    int x1, y1, x2, y2, valid_move;

    // initialize checkers board
    initialize_board(board);

    printf("\n\tWelcome to Checkers Game!\n\n");
    printf("Player 1: O\nPlayer 2: X\n");

    while (1)
    {
        printf("\n");
        display_board(board);

        // take input from the player
        printf("Player %d, please enter the coordinates of the checker you want to move: ", player);
        scanf("%d%d", &x1, &y1);
        printf("Please enter the coordinates of the destination: ");
        scanf("%d%d", &x2, &y2);

        // check if the move is valid
        valid_move = check_valid_move(board, x1, y1, x2, y2, player);

        if (valid_move == 0)
        {
            printf("\nInvalid move!\n");
            continue;
        }
        else
        {
            // move the checker
            move_checkers(board, x1, y1, x2, y2, player);
        }

        // check if the checker needs to be kinged
        if (check_king(board, player) == 1)
        {
            printf("\nKinged the checker!\n");
        }

        // check if the game is over
        if (check_board(board, player) == 1)
        {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        // switch to the other player
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}

// function to display the checkers board
void display_board(char board[][SIZE])
{
    printf("\t");
    for (int y = 0; y < SIZE; y++)
    {
        printf("%d ", y);
    }
    printf("\n\n");

    for (int x = 0; x < SIZE; x++)
    {
        printf("%d\t", x);
        for (int y = 0; y < SIZE; y++)
        {
            printf("%c ", board[x][y]);
        }
        printf("\n");
    }
}

// function to initialize the board with checkers
void initialize_board(char board[][SIZE])
{
    for (int x = 0; x < SIZE; x++)
    {
        for (int y = 0; y < SIZE; y++)
        {
            if (x % 2 == 0)
            {
                if (y % 2 == 0)
                {
                    board[x][y] = ' ';
                }
                else if (x < 3)
                {
                    board[x][y] = 'O';
                }
                else if (x > 4)
                {
                    board[x][y] = 'X';
                }
                else
                {
                    board[x][y] = ' ';
                }
            }
            else
            {
                if (y % 2 == 0)
                {
                    board[x][y] = 'O';
                }
                else if (x < 3)
                {
                    board[x][y] = ' ';
                }
                else if (x > 4)
                {
                    board[x][y] = 'X';
                }
                else
                {
                    board[x][y] = ' ';
                }
            }
        }
    }
}

// function to move checkers on the board
int move_checkers(char board[][SIZE], int x1, int y1, int x2, int y2, int player)
{
  if (board[x2][y2] != ' ') {
    return 0;
  }

  board[x2][y2] = board[x1][y1];
  board[x1][y1] = ' ';

  if ((x2 == 0 && player == 2) || (x2 == SIZE-1 && player == 1)) {
    if (board[x2][y2] == 'O') {
      board[x2][y2] = 'K';
    }
    else if (board[x2][y2] == 'X') {
      board[x2][y2] = 'Q';
    }
  }

  return 1;
}

// function to check if move is valid
int check_valid_move(char board[][SIZE], int x1, int y1, int x2, int y2, int player)
{
  if (x1 < 0 || x1 >= SIZE || x2 < 0 || x2 >= SIZE || y1 < 0 || y1 >= SIZE || y2 < 0 || y2 >= SIZE) {
    return 0;
  }

  // check if the player has selected their own checker
  if ((player == 1 && board[x1][y1] != 'O' && board[x1][y1] != 'K') || (player == 2 && board[x1][y1] != 'X' && board[x1][y1] != 'Q')) {
    return 0;
  }

  // check if the player is trying to move in the wrong direction
  if ((player == 1 && x2 > x1) || (player == 2 && x2 < x1)) {
    return 0;
  }

  // check if the player is trying to move more than one space horizontally or vertically
  if (abs(x2 - x1) > 1 || abs(y2 - y1) > 1) {
    return 0;
  }

  // check if player is trying to move diagonally
  if (abs(x2 - x1) != abs(y2 - y1)) {
    return 0;
  }

  // check if player is trying to move backwards but not kinged
  if ((player == 1 && board[x1][y1] == 'O' && x2 > x1) || (player == 2 && board[x1][y1] == 'X' && x2 < x1)) {
    return 0;
  }

  // check if player is trying to move to a non-empty space
  if (board[x2][y2] != ' ') {
    return 0;
  }

  return 1;
}

// function to check if the game is over
int check_board(char board[][SIZE], int player)
{
  int opponent = (player == 1) ? 2 : 1;
  int count_opponents = 0;

  for (int x = 0; x < SIZE; x++) {
    for (int y = 0; y < SIZE; y++) {
      if (board[x][y] == 'O' || board[x][y] == 'K') {
        count_opponents ++;
      }
      else if (board[x][y] == 'X' || board[x][y] == 'Q') {
        count_opponents ++;
      }
    }
  }

  if (count_opponents == 0) {
    return 1;
  }
  else {
    return 0;
  }
}

// function to check if a checker needs to be kinged
int check_king(char board[][SIZE], int player)
{
  int kinged = 0;

  for (int x = 0; x < SIZE; x++) {
    for (int y = 0; y < SIZE; y++) {
      if (player == 1 && board[x][y] == 'O' && x == 0) {
        board[x][y] = 'K';
        kinged = 1;
      }
      else if (player == 2 && board[x][y] == 'X' && x == SIZE-1) {
        board[x][y] = 'Q';
        kinged = 1;
      }
    }
  }

  return kinged;
}