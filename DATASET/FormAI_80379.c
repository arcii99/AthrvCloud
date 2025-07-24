//FormAI DATASET v1.0 Category: Memory Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main() {
    int board[ROWS][COLS];
    int num_pairs = ROWS * COLS / 2;
    int pairs_found = 0;
    int first_row, first_col, second_row, second_col;
    int first_value, second_value;
    char guess_again;

    // initialize board with random numbers
    srand(time(NULL));
    for (int i = 1; i <= num_pairs; i++) {
        int count = 0;
        while (count < 2) {
            int row = rand() % ROWS;
            int col = rand() % COLS;
            if (board[row][col] == 0) { // make sure the slot is not taken
                board[row][col] = i;
                count++;
            }
        }
    }

    // print the board to start the game
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("|%2d|", board[i][j]);
        }
        printf("\n");
    }

    // game loop
    while (pairs_found < num_pairs) {
        printf("Enter the row and column (e.g. 2 3) of the card you want to open: ");
        scanf("%d %d", &first_row, &first_col);
        first_value = board[first_row - 1][first_col - 1];
        printf("You have chosen card [%d][%d], which has the value %d\n", first_row, first_col, first_value);

        // check if the card chosen is already found
        if (first_value == -1) {
            printf("You have already found the matching pair for this card. Please try another card.\n");
            continue;
        }

        printf("Enter the row and column (e.g. 2 3) of the card you want to check: ");
        scanf("%d %d", &second_row, &second_col);
        second_value = board[second_row - 1][second_col - 1];
        printf("You have chosen card [%d][%d], which has the value %d\n", second_row, second_col, second_value);

        // check if the two cards have the same value
        if (first_value != second_value) {
            printf("The values do not match. Would you like to guess again (y/n)? ");
            scanf(" %c", &guess_again);
            if (guess_again == 'y' || guess_again == 'Y') {
                continue;
            } else {
                printf("Thanks for playing!\n");
                return 0;
            }
        }

        // both values match, so mark both as found
        board[first_row - 1][first_col - 1] = -1;
        board[second_row - 1][second_col - 1] = -1;
        pairs_found++;

        // print updated board
        printf("You found a pair! Here is the updated board:\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("|");
                if (board[i][j] == -1) {
                    printf("**"); // mask the value of found pairs
                } else {
                    printf("%2d", board[i][j]);
                }
                printf("|");
            }
            printf("\n");
        }
    }

    printf("You found all the pairs! Congratulations, you win!\n");
    return 0;
}