//FormAI DATASET v1.0 Category: Table Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define ROWS 6
#define COLS 7

void printBoard(char board[][COLS]);
int checkWin(char board[][COLS], char player);
int checkTie(char board[][COLS]);

int main()
{
    char board[ROWS][COLS], player = '1', column_choice;
    int row, column, row_choice, num_turns = 0;
    srand(time(NULL));
    // Initialize the board with spaces
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = ' ';
        }
    }
    printf("Welcome to Connect 4!\n");
    // Determine randomly which player goes first
    if ((rand() % 2) == 0) {
        player = '1';
        printf("Player %c goes first!\n", player);
    } else {
        player = '2';
        printf("Player %c goes first!\n", player);
    }
    while (1) {
        // Print the board
        printBoard(board);
        // Prompt the player to choose a column
        printf("Player %c, choose a column: ", player);
        scanf("%c", &column_choice);
        column_choice = toupper(column_choice);
        // Check if the input is valid
        while (column_choice < 'A' || column_choice > ('A' + COLS - 1)) {
            fflush(stdin);
            printf("Invalid input, please choose again: ");
            scanf("%c", &column_choice);
            column_choice = toupper(column_choice);
        }
        // Convert the letter into a number
        column = column_choice - 'A';
        // Check if the column is full
        row = ROWS - 1;
        while (row >= 0 && board[row][column] != ' ') {
            row--;
        }
        if (row < 0) {
            printf("Column is already full, please choose again.\n");
            continue;
        }
        // Set the chosen square to the player's number
        board[row][column] = player;
        // Check if the player has won
        if (checkWin(board, player)) {
            printBoard(board);
            printf("Player %c has won the game!\n", player);
            break;
        }
        // Check for a tie
        if (checkTie(board)) {
            printBoard(board);
            printf("The game is a tie!\n");
            break;
        }
        num_turns++;
        // Switch players
        if (player == '1') {
            player = '2';
        } else {
            player = '1';
        }
        fflush(stdin);
    }
    return 0;
}

void printBoard(char board[][COLS])
{
    printf("\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("| %c ", board[row][col]);
        }
        printf("|\n");
    }
    printf("-----------------------------\n");
    printf("  A   B   C   D   E   F   G  \n");
}

int checkWin(char board[][COLS], char player)
{
    // Check for horizontal win
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS - 3; col++) {
            if (board[row][col] == player && board[row][col+1] == player &&
                board[row][col+2] == player && board[row][col+3] == player) {
                return 1;
            }
        }
    }
    // Check for vertical win
    for (int row = 0; row < ROWS - 3; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == player && board[row+1][col] == player &&
                board[row+2][col] == player && board[row+3][col] == player) {
                return 1;
            }
        }
    }
    // Check for diagonal win (bottom left to top right)
    for (int row = 3; row < ROWS; row++) {
        for (int col = 0; col < COLS - 3; col++) {
            if (board[row][col] == player && board[row-1][col+1] == player &&
                board[row-2][col+2] == player && board[row-3][col+3] == player) {
                return 1;
            }
        }
    }
    // Check for diagonal win (top left to bottom right)
    for (int row = 0; row < ROWS - 3; row++) {
        for (int col = 0; col < COLS - 3; col++) {
            if (board[row][col] == player && board[row+1][col+1] == player &&
                board[row+2][col+2] == player && board[row+3][col+3] == player) {
                return 1;
            }
        }
    }
    // No win
    return 0;
}

int checkTie(char board[][COLS])
{
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}