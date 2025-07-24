//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS];
char player = 'X', AI = 'O';

int check_win();
void draw_board();
void player_turn();
void AI_turn();

int main()
{
    int choice, check;

    // Initialize the board
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            board[i][j] = '_';
        }
    }

    draw_board();

    // Randomly select who goes first
    srand(time(NULL));
    int first = rand() % 2;

    while (!check_win()) {
        if (first) {
            AI_turn();
            first = 0;
        }
        else {
            player_turn();
            first = 1;
        }

        draw_board();
    }

    return 0;
}

// Function to check if a player has won the game
int check_win()
{
    // Check rows
    for (int i=0; i<ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == player) {
                printf("You win!\n");
                return 1;
            }
            else if (board[i][0] == AI) {
                printf("AI wins!\n");
                return 1;
            }
        }
    }

    // Check columns
    for (int j=0; j<COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == player) {
                printf("You win!\n");
                return 1;
            }
            else if (board[0][j] == AI) {
                printf("AI wins!\n");
                return 1;
            }
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        if (board[1][1] == player) {
            printf("You win!\n");
            return 1;
        }
        else if (board[1][1] == AI) {
            printf("AI wins!\n");
            return 1;
        }
    }

    // Check if board is full
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (board[i][j] == '_') {
                return 0;
            }
        }
    }

    printf("It's a tie!\n");
    return 1;
}

// Function to draw the board
void draw_board()
{
    printf("\n");

    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

// Function for player's turn
void player_turn()
{
    int row, col;

    do {
        printf("Pick a row (1-3): ");
        scanf("%d", &row);
        printf("Pick a column (1-3): ");
        scanf("%d", &col);
    } while (board[row-1][col-1] != '_');

    board[row-1][col-1] = player;
}

// Function for AI's turn
void AI_turn()
{
    int row, col;

    // Check for AI win
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (board[i][j] == '_') {
                board[i][j] = AI;
                if (check_win()) {
                    return;
                }
                board[i][j] = '_';
            }
        }
    }

    // Check for player win and block
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (board[i][j] == '_') {
                board[i][j] = player;
                if (check_win()) {
                    board[i][j] = AI;
                    return;
                }
                board[i][j] = '_';
            }
        }
    }

    // Choose a random spot
    do {
        row = rand() % ROWS;
        col = rand() % COLS;
    } while (board[row][col] != '_');

    board[row][col] = AI;
}