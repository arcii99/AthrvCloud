//FormAI DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_MOVES (ROWS * COLS / 2)

char board[ROWS][COLS];
int moves[MAX_MOVES][2];
int found[MAX_MOVES];

void printBoard() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf("    ");
            } else {
                printf("%2d  ", board[i][j]);
            }
        }
        printf("\n\n");
    }
}

void populateBoard() {
    int nums[MAX_MOVES];
    for (int i = 0; i < MAX_MOVES; i++) {
        nums[i] = i+1;
    }

    int idx = 0;
    while (idx < MAX_MOVES) {
        int r = rand() % MAX_MOVES;
        if (nums[r] > 0) {
            moves[idx][0] = r / 2;
            moves[idx][1] = r % 2;
            board[moves[idx][0]][moves[idx][1]] = nums[r];
            nums[r] = 0;
            idx++;
        }
    }
}

int checkFound(int n) {
    for (int i = 0; i < MAX_MOVES; i++) {
        if (board[moves[i][0]][moves[i][1]] == n && found[i] == 0) {
            found[i] = 1;
            return 1;
        }
    }
    return 0;
}

int main() {
    printf("Welcome to the Memory Game!\n\n");

    srand(time(NULL));
    populateBoard();
    printBoard();

    int numFound = 0;
    int numGuesses = 0;
    while (numFound < MAX_MOVES) {
        numGuesses++;
        int valid = 0;
        int r, c;
        while (!valid) {
            printf("Enter row and column (e.g. 1 2): ");
            scanf("%d %d", &r, &c);
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
                if (board[r][c] == 0) {
                    valid = 1;
                } else if (!checkFound(board[r][c])) {
                    valid = 1;
                    board[r][c] = 0;
                }
            }
            if (!valid) {
                printf("Invalid move, try again.\n");
                printBoard();
            }
        }
        printBoard();
        if (checkFound(board[r][c])) {
            printf("You found a match!\n");
            numFound++;
        } else {
            printf("No match, try again.\n");
        }
    }

    printf("Congratulations, you found all the matches in %d guesses!\n", numGuesses);

    return 0;
}