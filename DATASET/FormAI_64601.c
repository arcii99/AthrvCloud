//FormAI DATASET v1.0 Category: Table Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

/*
 * This program is a simple implementation of the classic
 * Tic Tac Toe game using C language.
 */

// Prints the current state of the table
void print_table(char table[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("| ");
        for (int j = 0; j < COLS; j++) {
            printf("%c | ", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Checks if the given player has won
int check_win(char table[ROWS][COLS], char symbol) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (table[i][0] == symbol && table[i][1] == symbol && table[i][2] == symbol) {
            return 1;
        }
    }
    // Check columns
    for (int j = 0; j < COLS; j++) {
        if (table[0][j] == symbol && table[1][j] == symbol && table[2][j] == symbol) {
            return 1;
        }
    }
    // Check diagonal
    if (table[0][0] == symbol && table[1][1] == symbol && table[2][2] == symbol) {
        return 1;
    }
    // Check reverse diagonal
    if (table[0][2] == symbol && table[1][1] == symbol && table[2][0] == symbol) {
        return 1;
    }
    return 0;
}

int main() {
    char table[ROWS][COLS];
    char player1_symbol = 'X';
    char player2_symbol = 'O';
    char current_symbol = player1_symbol;
    int turn_num = 0;
    int game_ended = 0;

    // Initialize random seed
    srand(time(NULL));

    // Initialize table
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            table[i][j] = '_';
        }
    }

    // Print instructions
    printf("Welcome to Tic Tac Toe game!\n\n");
    printf("The objective of the game is to get three in a row.\n");
    printf("Player 1 will play with '%c' symbol and Player 2 will play with '%c' symbol.\n", player1_symbol, player2_symbol);
    printf("The player who succeeds in placing three of their symbols in a horizontal, vertical, or diagonal row wins the game.\n\n");
    printf("Let's start!\n\n");

    // Start game loop
    while (!game_ended) {
        print_table(table);
        int row, col;
        // Let current player make a move
        printf("Player %d's turn:\n", current_symbol == player1_symbol ? 1 : 2);
        if (current_symbol == player1_symbol) {
            printf("Enter row number (1-3): ");
            scanf("%d", &row);
            printf("Enter column number (1-3): ");
            scanf("%d", &col);
            row--; // Make zero-indexed
            col--; // Make zero-indexed
            // Check if cell is empty
            if (table[row][col] != '_') {
                printf("The selected cell is not empty. Try again.\n");
                continue;
            }
            table[row][col] = player1_symbol;
        } else {
            // Let computer make a move
            printf("Computer is thinking...\n");
            // Wait for random time between 1-3 seconds to simulate "thinking"
            int wait_time = rand() % 3 + 1;
            time_t start_time, end_time;
            time(&start_time);
            do {
                time(&end_time);
            } while (difftime(end_time, start_time) < wait_time);
            // Randomly select a cell
            do {
                row = rand() % ROWS;
                col = rand() % COLS;
            } while (table[row][col] != '_');
            table[row][col] = player2_symbol;
        }
        // Check if game ended
        if (check_win(table, current_symbol)) {
            printf("Congratulations! Player %d won!\n", current_symbol == player1_symbol ? 1 : 2);
            game_ended = 1;
        } else if (turn_num == ROWS * COLS - 1) {
            printf("It's a tie!\n");
            game_ended = 1;
        }
        // Switch player
        current_symbol = current_symbol == player1_symbol ? player2_symbol : player1_symbol;
        turn_num++;
    }

    print_table(table);

    return 0;
}