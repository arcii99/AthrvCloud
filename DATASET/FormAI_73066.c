//FormAI DATASET v1.0 Category: Table Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Define maximum number of characters for name input
#define MAX_NAME_LENGTH 50

// Define game board dimensions
#define BOARD_ROWS 5
#define BOARD_COLS 5

// Define struct for game board
typedef struct GameBoard {
  char board[BOARD_ROWS][BOARD_COLS];
} GameBoard;

// Define struct for player
typedef struct Player {
  char name[MAX_NAME_LENGTH];
  int row;
  int col;
} Player;

// Function to initialize game board with random letters
void initializeBoard(GameBoard* board) {
  // Seed random number generator
  srand(time(NULL));

  // Loop through each space on the board and assign a random letter
  for (int row = 0; row < BOARD_ROWS; row++) {
    for (int col = 0; col < BOARD_COLS; col++) {
      board->board[row][col] = (char) (rand() % 26 + 'a');
    }
  }
}

// Function to print game board
void printBoard(GameBoard* board) {
  printf("\n  ");
  for (int col = 0; col < BOARD_COLS; col++) {
    printf("%c ", 'A' + col);
  }
  printf("\n");

  for (int row = 0; row < BOARD_ROWS; row++) {
    printf("%d ", row + 1);
    for (int col = 0; col < BOARD_COLS; col++) {
      printf("%c ", board->board[row][col]);
    }
    printf("\n");
  }
}

// Function to validate input row and column and return as uppercase
void validateInput(char* input, int* row, int* col) {
  // Convert input row to integer and subtract 1 for zero-indexing
  *row = atoi(&input[1]) - 1;

  // Convert input column to uppercase letter and subtract 'A' for zero-indexing
  *col = toupper(input[0]) - 'A';

  // If row or column is invalid, set both to -1
  if (*row < 0 || *row >= BOARD_ROWS || *col < 0 || *col >= BOARD_COLS) {
    *row = -1;
    *col = -1;
  }
}

// Function to prompt player for their next move and return input as uppercase string
void promptMove(Player* player) {
  // Prompt player for input
  printf("\n%s, enter your next move (ex. A1): ", player->name);
  char input[MAX_NAME_LENGTH];
  fgets(input, MAX_NAME_LENGTH, stdin);

  // Validate input
  int row, col;
  validateInput(input, &row, &col);

  // If input is invalid, prompt player again
  while (row == -1 || col == -1) {
    printf("Invalid input. Please try again.\n");
    printf("%s, enter your next move (ex. A1): ", player->name);
    fgets(input, MAX_NAME_LENGTH, stdin);
    validateInput(input, &row, &col);
  }

  // Update player's row and column
  player->row = row;
  player->col = col;
}

// Function to update game board with player's move and return number of letters captured
int updateBoard(GameBoard* board, Player* player) {
  // Initialize counter for number of letters captured
  int letterCount = 0;

  // If space is empty, set it to '0'
  if (board->board[player->row][player->col] == ' ') {
    board->board[player->row][player->col] = '0';
  }
  // If space is already a number, increment its value by 1
  else if (isdigit(board->board[player->row][player->col])) {
    board->board[player->row][player->col]++;
  }
  // If space has a letter, capture it
  else {
    letterCount++;
    board->board[player->row][player->col] = ' ';
  }

  // Update spaces above, below, left, and right of player's move
  // If space is empty, set it to '0'
  // If space is already a number, increment its value by 1
  // If space has a letter, capture it
  if (player->row - 1 >= 0) {
    if (board->board[player->row - 1][player->col] == ' ') {
      board->board[player->row - 1][player->col] = '0';
    } else if (isdigit(board->board[player->row - 1][player->col])) {
      board->board[player->row - 1][player->col]++;
    } else {
      letterCount++;
      board->board[player->row - 1][player->col] = ' ';
    }
  }
  if (player->row + 1 < BOARD_ROWS) {
    if (board->board[player->row + 1][player->col] == ' ') {
      board->board[player->row + 1][player->col] = '0';
    } else if (isdigit(board->board[player->row + 1][player->col])) {
      board->board[player->row + 1][player->col]++;
    } else {
      letterCount++;
      board->board[player->row + 1][player->col] = ' ';
    }
  }
  if (player->col - 1 >= 0) {
    if (board->board[player->row][player->col - 1] == ' ') {
      board->board[player->row][player->col - 1] = '0';
    } else if (isdigit(board->board[player->row][player->col - 1])) {
      board->board[player->row][player->col - 1]++;
    } else {
      letterCount++;
      board->board[player->row][player->col - 1] = ' ';
    }
  }
  if (player->col + 1 < BOARD_COLS) {
    if (board->board[player->row][player->col + 1] == ' ') {
      board->board[player->row][player->col + 1] = '0';
    } else if (isdigit(board->board[player->row][player->col + 1])) {
      board->board[player->row][player->col + 1]++;
    } else {
      letterCount++;
      board->board[player->row][player->col + 1] = ' ';
    }
  }

  // Return number of letters captured
  return letterCount;
}

// Function to check if game is over and return the winning player's name
char* checkGameOver(Player* player1, Player* player2, GameBoard* board) {
  // Initialize counters for each player's score
  int player1Score = 0, player2Score = 0;

  // Count number of captured letters for each player
  for (int row = 0; row < BOARD_ROWS; row++) {
    for (int col = 0; col < BOARD_COLS; col++) {
      if (board->board[row][col] == ' ') {
        continue;
      } else if (isdigit(board->board[row][col])) {
        if (board->board[row][col] % 2 == 0) {
          player1Score += board->board[row][col] - 48;
        } else {
          player2Score += board->board[row][col] - 48;
        }
      } else {
        if (((row + 1) + (col + 1)) % 2 == 0) {
          player1Score++;
        } else {
          player2Score++;
        }
      }
    }
  }

  // If one player has more captured letters, they win
  if (player1Score > player2Score) {
    return player1->name;
  } else if (player2Score > player1Score) {
    return player2->name;
  }

  // If number of captured letters is tied, the player with the highest sum of captured numers wins
  int player1Sum = 0, player2Sum = 0;
  for (int row = 0; row < BOARD_ROWS; row++) {
    for (int col = 0; col < BOARD_COLS; col++) {
      if (isdigit(board->board[row][col])) {
        if (board->board[row][col] % 2 == 0) {
          player1Sum += board->board[row][col] - 48;
        } else {
          player2Sum += board->board[row][col] - 48;
        }
      }
    }
  }

  if (player1Sum > player2Sum) {
    return player1->name;
  } else if (player2Sum > player1Sum) {
    return player2->name;
  }

  // If sum of captured numbers is also tied, game is a draw
  return "DRAW";
}

int main() {
  // Initialize game board with random letters
  GameBoard board;
  initializeBoard(&board);

  // Initialize players
  Player player1, player2;
  printf("Welcome, dear friend. In this game, the goal is to capture as many letters as possible. Beware of the numbers, "
         "for they can hinder your progress! Shall we begin?\n\n");
  printf("Player 1, enter your name: ");
  fgets(player1.name, MAX_NAME_LENGTH, stdin);
  printf("Welcome, %s\n", player1.name);
  printf("Player 2, enter your name: ");
  fgets(player2.name, MAX_NAME_LENGTH, stdin);
  printf("Welcome, %s\n", player2.name);

  // Game loop
  while (1) {
    // Print game board
    printf("\n%s's turn:\n", player1.name);
    printBoard(&board);

    // Prompt player 1 for next move and update game board
    promptMove(&player1);
    int lettersCaptured = updateBoard(&board, &player1);
    printf("%d letters captured!\n", lettersCaptured);

    // Check if game is over
    char* winner = checkGameOver(&player1, &player2, &board);
    if (strcmp(winner, "DRAW") == 0) {
      printf("Game is a draw.\n");
      break;
    } else if (strcmp(winner, player1.name) == 0) {
      printf("%s wins!\n", player1.name);
      break;
    } else {
      printf("\n%s's turn:\n", player2.name);
      printBoard(&board);
      promptMove(&player2);
      lettersCaptured = updateBoard(&board, &player2);
      printf("%d letters captured!\n", lettersCaptured);
      winner = checkGameOver(&player1, &player2, &board);
      if (strcmp(winner, "DRAW") == 0) {
        printf("Game is a draw.\n");
        break;
      } else if (strcmp(winner, player2.name) == 0) {
        printf("%s wins!\n", player2.name);
        break;
      }
    }
  }

  return 0;
}