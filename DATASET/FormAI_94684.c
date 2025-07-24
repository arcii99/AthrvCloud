//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define BOMBS 10

int main() {
    // Initialize game board
    int board[ROWS][COLS] = {0};
    int revealed[ROWS][COLS] = {0};  // 0 for hidden, 1 for revealed, 2 for flag
    int game_over = 0;

    // Randomly place bombs
    srand(time(NULL));
    int bombs = 0;
    while (bombs < BOMBS) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (board[row][col] != -1) {  // check if already has a bomb
            board[row][col] = -1;  // place bomb
            bombs++;
        }
    }

    // Calculate adjacent bombs
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] != -1) {
                int count = 0;
                if (i > 0 && j > 0 && board[i-1][j-1] == -1) count++;
                if (i > 0 && board[i-1][j] == -1) count++;
                if (i > 0 && j < COLS-1 && board[i-1][j+1] == -1) count++;
                if (j > 0 && board[i][j-1] == -1) count++;
                if (j < COLS-1 && board[i][j+1] == -1) count++;
                if (i < ROWS-1 && j > 0 && board[i+1][j-1] == -1) count++;
                if (i < ROWS-1 && board[i+1][j] == -1) count++;
                if (i < ROWS-1 && j < COLS-1 && board[i+1][j+1] == -1) count++;
                board[i][j] = count;
            }
        }
    }

    // Game loop
    while (!game_over) {
        // Print board
        printf("\n   ");
        for (int i = 0; i < COLS; i++) printf("%d ", i);
        printf("\n");
        for (int i = 0; i < ROWS; i++) {
            printf("%d: ", i);
            for (int j = 0; j < COLS; j++) {
                if (!revealed[i][j]) printf("# ");
                else if (board[i][j] == -1) printf("* ");  // exploded bomb
                else if (board[i][j] == 0) printf("  ");  // empty space
                else printf("%d ", board[i][j]);  // number of adjacent bombs
            }
            printf("\n");
        }

        // Check for win
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] != -1 && revealed[i][j]) count++;
            }
        }
        if (count == ROWS*COLS - BOMBS) {
            printf("\nCongratulations, you won!\n");
            break;
        }

        // Get input
        int row, col;
        printf("Enter row and column (e.g. '3 4'): ");
        scanf("%d %d", &row, &col);

        // Check for flag
        char flag;
        printf("Do you want to flag the cell? (y/n): ");
        scanf(" %c", &flag);  // use whitespace to ignore newlines
        if (flag == 'y' || flag == 'Y') {
            revealed[row][col] = 2;
        }

        // Reveal cell
        if (board[row][col] == -1) {
            printf("\nBoom! Game over.\n");
            game_over = 1;
        } else {
            revealed[row][col] = 1;
        }
    }

    return 0;
}