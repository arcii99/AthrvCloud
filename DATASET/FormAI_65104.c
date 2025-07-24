//FormAI DATASET v1.0 Category: Memory Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initializeBoard(char board[][COLS]);
void printBoard(char board[][COLS], int revealed[][COLS]);
void revealTile(int row, int col, char board[][COLS], int revealed[][COLS]);
int checkGameOver(int revealed[][COLS]);

int main()
{
    char board[ROWS][COLS];
    int revealed[ROWS][COLS] = {0};
    int tile1_row, tile1_col, tile2_row, tile2_col;
    int moves = 0;

    srand(time(NULL)); // Initialize random seed based on current time

    initializeBoard(board);

    while (!checkGameOver(revealed)) { // Loop until game is over
        printBoard(board, revealed);

        // Get user input for first tile
        printf("Enter row and column of first tile: ");
        scanf("%d%d", &tile1_row, &tile1_col);
        while (revealed[tile1_row][tile1_col] == 1) { // Loop if tile is already revealed
            printf("Tile already revealed. Enter row and column of another tile: ");
            scanf("%d%d", &tile1_row, &tile1_col);
        }
        revealTile(tile1_row, tile1_col, board, revealed);

        // Get user input for second tile
        printf("Enter row and column of second tile: ");
        scanf("%d%d", &tile2_row, &tile2_col);
        while ((tile1_row == tile2_row && tile1_col == tile2_col) || revealed[tile2_row][tile2_col] == 1) {
            // Loop if same as first tile or if tile is already revealed
            printf("Invalid tile. Enter row and column of another tile: ");
            scanf("%d%d", &tile2_row, &tile2_col);
        }
        revealTile(tile2_row, tile2_col, board, revealed);

        // Check if tiles match
        if (board[tile1_row][tile1_col] != board[tile2_row][tile2_col]) {
            printf("Sorry, the tiles do not match.\n");
            revealed[tile1_row][tile1_col] = 0;
            revealed[tile2_row][tile2_col] = 0;
        } else {
            printf("Congratulations, the tiles match.\n");
        }

        moves++;
    }

    printf("Game over! You completed the game in %d moves.\n", moves);

    return 0;
}

void initializeBoard(char board[][COLS])
{
    char values[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int count[8] = {0};
    int row, col;

    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            int random = rand() % 8; // Generate random number between 0 and 7
            while (count[random] == 2) { // Loop if value has already been used twice
                random = rand() % 8;
            }
            board[row][col] = values[random]; // Assign value to tile
            count[random]++;
        }
    }
}

void printBoard(char board[][COLS], int revealed[][COLS])
{
    int row, col;

    printf("\n");
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (revealed[row][col]) {
                printf("%c ", board[row][col]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

void revealTile(int row, int col, char board[][COLS], int revealed[][COLS])
{
    revealed[row][col] = 1;
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int checkGameOver(int revealed[][COLS])
{
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (revealed[i][j] == 1) {
                count++;
            }
        }
    }
    if (count == ROWS * COLS) {
        return 1;
    } else {
        return 0;
    }
}