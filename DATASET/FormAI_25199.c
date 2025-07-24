//FormAI DATASET v1.0 Category: Memory Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

int main() {
    int board[MAX_SIZE][MAX_SIZE];
    int size = 4, num_pairs = 8;
    int row, col, row_guess, col_guess, num_guesses = 0;
    int guess1_row = -1, guess1_col = -1, guess2_row = -1, guess2_col = -1;
    int pairs_found = 0;
    srand(time(0));

    if (num_pairs > size*size/2) {
        printf("Error: not enough cells for requested number of pairs");
        return 1;
    }

    // initialize board with random pairs of numbers
    for (int num = 1; num <= num_pairs; num++) {
        for (int pair = 1; pair <= 2; pair++) {
            do {
                row = rand() % size;
                col = rand() % size;
            } while (board[row][col] != 0);
            board[row][col] = num;
        }
    }

    // print board (cheat view)
    printf("C Memory Game\n");
    printf("==============\n");
    printf("Match the pairs of numbers\n");

    for (row = 0; row < size; row++) {
        for (col = 0; col < size; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }

    // game loop
    while (pairs_found < num_pairs) {
        // print board (player view)
        printf("\n");
        for (row = 0; row < size; row++) {
            for (col = 0; col < size; col++) {
                if (board[row][col] == 0) {
                    printf("# ");
                } else if (row == guess1_row && col == guess1_col
                        || row == guess2_row && col == guess2_col) {
                    printf("%d ", board[row][col]);
                } else {
                    printf("? ");
                }
            }
            printf("\n");
        }

        // get player guess
        do {
            printf("Guess a row (0-%d): ", size-1);
            scanf("%d", &row_guess);
            printf("Guess a column (0-%d): ", size-1);
            scanf("%d", &col_guess);
        } while (row_guess < 0 || row_guess >= size
                || col_guess < 0 || col_guess >= size);

        num_guesses++;

        // check guess
        if (board[row_guess][col_guess] == 0) {
            printf("Sorry, no match at (%d,%d)\n", row_guess, col_guess);
            if (guess1_row >= 0) {
                guess1_row = -1;
                guess1_col = -1;
                guess2_row = -1;
                guess2_col = -1;
            }
        } else if (guess1_row == row_guess && guess1_col == col_guess) {
            printf("You already guessed (%d,%d)\n", row_guess, col_guess);
        } else if (guess1_row < 0) {
            guess1_row = row_guess;
            guess1_col = col_guess;
        } else if (guess2_row < 0 && guess1_row != row_guess
                || guess1_col != col_guess) {
            guess2_row = row_guess;
            guess2_col = col_guess;
            if (board[guess1_row][guess1_col] == board[guess2_row][guess2_col]) {
                printf("Match found for %d at (%d,%d) and (%d,%d)!\n",
                        board[guess1_row][guess1_col],
                        guess1_row, guess1_col, guess2_row, guess2_col);
                pairs_found++;
                board[guess1_row][guess1_col] = 0;
                board[guess2_row][guess2_col] = 0;
                guess1_row = -1;
                guess1_col = -1;
                guess2_row = -1;
                guess2_col = -1;
            } else {
                printf("Sorry, no match at (%d,%d) and (%d,%d)\n",
                        guess1_row, guess1_col, guess2_row, guess2_col);
            }
        } else {
            printf("You already made two guesses, please guess again\n");
        }
    }

    printf("Congratulations! You found all %d pairs in %d guesses!\n", num_pairs, num_guesses);

    return 0;
}