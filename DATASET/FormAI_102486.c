//FormAI DATASET v1.0 Category: Memory Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_MOVES 25

char board[BOARD_SIZE + 2][BOARD_SIZE + 2] = {}; // Add extra columns and rows for borders

int main() {
    srand(time(NULL)); // Seed the random number generator
    int num_moves = 0;
    int row, col;
    char prev_char = '\0'; // Set to null character to avoid matching on the first move

    // Initialize the game board
    for (int i = 0; i <= BOARD_SIZE + 1; i++) {
        for (int j = 0; j <= BOARD_SIZE + 1; j++) {
            if (i == 0 || i == BOARD_SIZE + 1 || j == 0 || j == BOARD_SIZE + 1) {
                board[i][j] = '|'; // Draw a border around the board
            } else {
                board[i][j] = ' ';
            }
        }
    }

    // Add the letters to the board
    for (char c = 'A'; c <= 'Z'; c++) {
        for (int i = 0; i < 2; i++) {
            do {
                row = rand() % BOARD_SIZE + 1;
                col = rand() % BOARD_SIZE + 1;
            } while (board[row][col] != ' ');
            board[row][col] = c;
        }
    }

    // Play the game
    while (num_moves < MAX_MOVES) {
        // Print the current state of the board
        for (int i = 0; i <= BOARD_SIZE + 1; i++) {
            for (int j = 0; j <= BOARD_SIZE + 1; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("Enter row and column of letter to reveal: ");
        scanf("%d %d", &row, &col);
        if (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE || board[row][col] == ' ') {
            printf("Invalid input, please try again.\n");
        } else {
            char curr_char = board[row][col];
            board[row][col] = curr_char; // Reveal the current character
            if (curr_char == prev_char) { // Match found
                printf("Match found!\n");
                num_moves++;
                prev_char = '\0'; // Reset the previous character
            } else { // No match found
                prev_char = curr_char;
            }
        }
    }

    printf("Game over. You made %d moves.\n", num_moves);

    return 0;
}