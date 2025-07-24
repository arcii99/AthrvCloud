//FormAI DATASET v1.0 Category: Memory Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

void shuffle(int *arr, int n) {
    for (int i = n - 1; i >= 1; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printBoard(char board[][BOARD_SIZE]) {
    printf("     1   2   3   4\n");
    printf("   +---+---+---+---+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d  | ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
        printf("   +---+---+---+---+\n");
    }
}

int main() {
    srand(time(NULL));

    int values[NUM_PAIRS * 2];
    char board[BOARD_SIZE][BOARD_SIZE];

    // Initialize values array with pairs of values
    for (int i = 0; i < NUM_PAIRS; i++) {
        values[i] = i;
        values[NUM_PAIRS + i] = i;
    }

    shuffle(values, NUM_PAIRS * 2);

    // Initialize board with '?'s
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '?';
        }
    }

    // Game loop
    int numMatches = 0;
    while (numMatches < NUM_PAIRS) {
        printBoard(board);

        // Get user input
        int arow, acol, brow, bcol;
        printf("Enter the row and column for the first card:\n");
        scanf("%d%d", &arow, &acol);
        while (board[arow - 1][acol - 1] != '?') {
            printf("That card has already been flipped. Enter the row and column for a new card:\n");
            scanf("%d%d", &arow, &acol);
        }

        printf("Enter the row and column for the second card:\n");
        scanf("%d%d", &brow, &bcol);
        while ((arow == brow && acol == bcol) || board[brow - 1][bcol - 1] != '?') {
            printf("Invalid card or card has already been flipped. Enter the row and column for a new card:\n");
            scanf("%d%d", &brow, &bcol);
        }

        // Flip cards
        board[arow - 1][acol - 1] = values[(arow - 1) * BOARD_SIZE + (acol - 1)];
        board[brow - 1][bcol - 1] = values[(brow - 1) * BOARD_SIZE + (bcol - 1)];

        // Check for match
        if (board[arow - 1][acol - 1] == board[brow - 1][bcol - 1]) {
            printf("Match!\n");
            numMatches++;
        } else {
            printf("No match.\n");
            // Flip cards back over
            board[arow - 1][acol - 1] = '?';
            board[brow - 1][bcol - 1] = '?';
        }
    }

    printf("Congratulations, you won!\n");

    return 0;
}