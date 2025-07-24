//FormAI DATASET v1.0 Category: Memory Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_MOVES 8

void printBoard(int board[ROWS][COLS], int reveal[ROWS][COLS]) {
    printf("    1   2   3   4  \n");
    printf("  +---------------+\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (reveal[i][j]) {
                printf(" %d |", board[i][j]);
            } else {
                printf("   |");
            }
        }
        printf("\n  +---------------+\n");
    }
}

int main() {
    int board[ROWS][COLS] = {{1,2,3,4},
                             {5,6,7,8},
                             {1,2,3,4},
                             {5,6,7,8}};
    int reveal[ROWS][COLS] = {{0,0,0,0},
                              {0,0,0,0},
                              {0,0,0,0},
                              {0,0,0,0}};
    int moves[MAX_MOVES][2] = {{0,0},{0,1},{0,2},{0,3},
                               {1,0},{1,1},{1,2},{1,3}};
    srand(time(0));
    for (int i = MAX_MOVES - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tempR = moves[i][0];
        int tempC = moves[i][1];
        moves[i][0] = moves[j][0];
        moves[i][1] = moves[j][1];
        moves[j][0] = tempR;
        moves[j][1] = tempC;
    }

    printf("Welcome to the Memory Game!\n");
    printf("You will be shown a board with hidden numbers.\n");
    printf("Each turn, you will pick two positions to reveal.\n");
    printf("If the numbers match, they will stay revealed.\n");
    printf("If not, they will be hidden again.\n");
    printf("The goal is to reveal all pairs in the fewest turns possible.\n");
    printf("Let's begin!\n\n");

    int numRevealed = 0;
    int numTurns = 0;
    while (numRevealed < ROWS * COLS) {
        printBoard(board, reveal);
        int r1, c1, r2, c2;
        do {
            printf("Enter the row and column of your first choice: ");
            scanf("%d %d", &r1, &c1);
        } while (r1 < 1 || r1 > ROWS || c1 < 1 || c1 > COLS || reveal[r1-1][c1-1] == 1);

        do {
            printf("Enter the row and column of your second choice: ");
            scanf("%d %d", &r2, &c2);
        } while (r2 < 1 || r2 > ROWS || c2 < 1 || c2 > COLS || reveal[r2-1][c2-1] == 1);

        if (board[r1-1][c1-1] == board[r2-1][c2-1]) {
            numRevealed += 2;
            reveal[r1-1][c1-1] = 1;
            reveal[r2-1][c2-1] = 1;
            printf("Match found!\n");
        } else {
            reveal[r1-1][c1-1] = 0;
            reveal[r2-1][c2-1] = 0;
            printf("No match found.\n");
        }

        numTurns++;
        printf("\n");
    }

    printf("Congratulations, you won in %d turns!\n", numTurns);
    return 0;
}