//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10 // Number of rows in the game board
#define COLS 10 // Number of columns in the game board
#define SHIPS 3 // Number of ships in the game

int board[ROWS][COLS]; // Game board
int ships[SHIPS][2]; // Ship locations

int main() {
    int i, j, k, hit, guess_row, guess_col, attempts = 0;

    // Clear the board
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    // Randomly place the ships
    srand(time(NULL));
    for(k = 0; k < SHIPS; k++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        ships[k][0] = row;
        ships[k][1] = col;
        board[row][col] = 1;
    }

    // Game loop
    do {
        // Print the board
        printf("\n");
        for(i = 0; i < ROWS; i++) {
            for(j = 0; j < COLS; j++) {
                printf("%c ", board[i][j] == -1 ? 'X' : board[i][j] ? 'O' : '-');
            }
            printf("\n");
        }

        // Get the user's guess
        printf("\nEnter row and column (separated by a space): ");
        scanf("%d %d", &guess_row, &guess_col);

        // Determine if the guess is a hit or a miss
        hit = 0;
        for(k = 0; k < SHIPS; k++) {
            if(guess_row == ships[k][0] && guess_col == ships[k][1]) {
                hit = 1;
                board[guess_row][guess_col] = -1;
                printf("\nYou sunk my battleship!");
                break;
            }
        }
        if(!hit) {
            if(guess_row < 0 || guess_row >= ROWS || guess_col < 0 || guess_col >= COLS) {
                printf("\nOops, that's not even in the ocean.");
            } else if(board[guess_row][guess_col] == -1) {
                printf("\nYou already guessed that one!");
            } else {
                printf("\nYou missed my battleship!");
                board[guess_row][guess_col] = -1;
            }
        }

        attempts++;
    } while(hit != SHIPS);

    // Print the final board
    printf("\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c ", board[i][j] == -1 ? 'X' : board[i][j] ? 'O' : '-');
        }
        printf("\n");
    }

    printf("\nYou win! You sunk my battleships in %d attempts.\n\n", attempts);

    return 0;
}