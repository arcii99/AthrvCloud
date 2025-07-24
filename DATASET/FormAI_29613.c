//FormAI DATASET v1.0 Category: Memory Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void print_board(char board[][COLS]) {
    int i, j;
    printf("\n    1   2   3   4\n");
    printf("   ---------------\n");
    for (i = 0; i < ROWS; ++i) {
        printf("%d |", i+1);
        for (j = 0; j < COLS; ++j) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("  ---------------\n");
    }
    printf("\n");
}

void reset_board(char board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            board[i][j] = ' ';
        }
    }
}

int main() {
    char board[ROWS][COLS];
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int num_pairs = ROWS*COLS/2;
    int pairs_found = 0;
    int remaining_pairs = num_pairs;
    int i, j;
    int r1, c1, r2, c2;
    char symbol1, symbol2;
    int pos1, pos2;
    srand(time(NULL));
    reset_board(board);
    for (i = 0; i < num_pairs; ++i) {
        symbol1 = symbols[i];
        symbol2 = symbols[i];
        pos1 = rand()%(ROWS*COLS);
        while (board[pos1/COLS][pos1%COLS] != ' ') {
            pos1 = rand()%(ROWS*COLS);
        }
        board[pos1/COLS][pos1%COLS] = symbol1;
        pos2 = rand()%(ROWS*COLS);
        while (board[pos2/COLS][pos2%COLS] != ' ') {
            pos2 = rand()%(ROWS*COLS);
        }
        board[pos2/COLS][pos2%COLS] = symbol2;
    }
    printf("Welcome to the Memory Game!\n");
    print_board(board);
    while (remaining_pairs > 0) {
        printf("Enter first card: ");
        scanf("%d %d", &r1, &c1);
        if (r1 < 1 || r1 > ROWS || c1 < 1 || c1 > COLS || board[r1-1][c1-1] == 'X') {
            printf("Invalid input, try again.\n");
            continue;
        }
        board[r1-1][c1-1] = 'X';
        print_board(board);
        printf("Enter second card: ");
        scanf("%d %d", &r2, &c2);
        if (r2 < 1 || r2 > ROWS || c2 < 1 || c2 > COLS || board[r2-1][c2-1] == 'X') {
            printf("Invalid input, try again.\n");
            board[r1-1][c1-1] = ' ';
            continue;
        }
        board[r2-1][c2-1] = 'X';
        print_board(board);
        if (board[r1-1][c1-1] == board[r2-1][c2-1]) {
            printf("Great, you found a pair!\n");
            ++pairs_found;
            --remaining_pairs;
            board[r1-1][c1-1] = ' ';
            board[r2-1][c2-1] = ' ';
        }
        else {
            printf("Sorry, not a pair.\n");
            board[r1-1][c1-1] = ' ';
            board[r2-1][c2-1] = ' ';
        }
    }
    printf("Congratulations, you won!\n");
    return 0;
}