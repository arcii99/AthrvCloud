//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
    int board[ROWS][COLS];
    int numbers[76];
    int index = 0;

    // Initialize numbers array
    for(int i = 1; i <= 75; i++) {
        numbers[index++] = i;
    }

    // Initialize board
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    while(1) {
        printf("Press enter to call a number.");
        getchar();

        // Generate a random number
        int randomIndex = rand() % (75 - index);
        int num = numbers[randomIndex];

        // Remove the number from the numbers array
        for(int i = randomIndex; i < index - 1; i++) {
            numbers[i] = numbers[i+1];
        }
        index--;

        // Print the called number
        printf("The number called is: %d\n", num);

        // Check if the number is on the board
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(board[i][j] == num) {
                    board[i][j] = -1; // Mark as called
                }
            }
        }

        // Print the board
        printf(" ---------------------\n");
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(board[i][j] == -1) {
                    printf("| X ");
                } else {
                    printf("| %2d", board[i][j]);
                }
            }
            printf("|\n");
            printf(" ---------------------\n");
        }

        // Check for win conditions
        int row_win = 0;
        int col_win = 0;
        int diag_win1 = 1; // top-left to bottom-right diagonal
        int diag_win2 = 1; // top-right to bottom-left diagonal
        for(int i = 0; i < ROWS; i++) {
            row_win = 1;
            col_win = 1;
            for(int j = 0; j < COLS; j++) {
                if(board[i][j] != -1) {
                    row_win = 0;
                }
                if(board[j][i] != -1) {
                    col_win = 0;
                }
            }
            if(row_win || col_win) {
                printf("BINGO! You won!\n");
                return 0;
            }
            if(board[i][i] != -1) {
                diag_win1 = 0;
            }
            if(board[i][ROWS-i-1] != -1) {
                diag_win2 = 0;
            }
        }
        if(diag_win1 || diag_win2) {
            printf("BINGO! You won!\n");
            return 0;
        }
    }

    return 0;
}