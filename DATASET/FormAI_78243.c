//FormAI DATASET v1.0 Category: Memory Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int ROWS = 4, COLS = 4;
    int board[ROWS][COLS];
    int i, j, r, c;
    int num_swaps = 100;
    int guess1_row, guess1_col, guess2_row, guess2_col;
    int num_guesses = 0, num_correct = 0;
    
    srand(time(NULL));
    
    // Fill the board with numbers 1-8
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = (i * COLS + j + 1) / 2;
        }
    }
    
    // Shuffle the board
    for (i = 0; i < num_swaps; i++) {
        r = rand() % ROWS;
        c = rand() % COLS;
        int temp = board[r][c];
        board[r][c] = board[ROWS - r - 1][COLS - c - 1];
        board[ROWS - r - 1][COLS - c - 1] = temp;
    }
    
    // Play the game
    while (1) {
        system("clear");
        printf("Memory Game\n");
        printf("Number of guesses: %d\n", num_guesses);
        printf("Number correct: %d\n", num_correct);
        printf("\n");
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (i == guess1_row && j == guess1_col) {
                    printf("%d ", board[i][j]);
                } else if (i == guess2_row && j == guess2_col) {
                    printf("%d ", board[i][j]);
                } else {
                    printf("# ");
                }
            }
            printf("\n");
        }
        printf("\n");
        printf("Enter the row and column to reveal (e.g. 1 2): ");
        scanf("%d %d", &r, &c);
        printf("\n");
        if (num_guesses % 2 == 0) {
            guess1_row = r;
            guess1_col = c;
        } else {
            guess2_row = r;
            guess2_col = c;
            if (board[guess1_row][guess1_col] == board[guess2_row][guess2_col]) {
                printf("Correct!\n");
                num_correct++;
                if (num_correct == ROWS * COLS / 2) {
                    printf("Congratulations, you win!\n");
                    return 0;
                }
            } else {
                printf("Incorrect.\n");
            }
        }
        num_guesses++;
    }
    return 0;
}