//FormAI DATASET v1.0 Category: Memory Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main() {
    // display game title
    printf("***** C MEMORY GAME *****\n");

    // initialize game board
    int board[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = 0;
        }
    }

    // randomly assign memory cells
    srand(time(0));
    int count = 1;
    while(count <= 8) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if(board[row][col] == 0) {
            board[row][col] = count;
            count++;
        }
    }

    // initialize game variables
    int num_clicks = 0;
    int clicks[2][2] = { {0,0}, {0,0} };

    // main game loop
    while(1) {
        // display game board
        printf("\n");
        printf("   1 2 3 4\n");
        printf("   -------\n");
        for(int i=0; i<ROWS; i++) {
            printf("%d |", i+1);
            for(int j=0; j<COLS; j++) {
                if(board[i][j] == 0) {
                    printf("  ");
                } else if(board[i][j] < 10) {
                    printf(" %d", board[i][j]);
                } else {
                    printf("%d", board[i][j]);
                }
                printf("|");
            }
            printf("\n  -------\n");
        }

        // check for game completion
        int completed = 1;
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(board[i][j] != 0) {
                    completed = 0;
                }
            }
        }
        if(completed) {
            printf("Congratulations! You won the game.\n");
            break;
        }

        // get user input
        printf("Enter row and column of two cells to flip (e.g. 1 2 3 4): ");
        scanf("%d %d %d %d", &clicks[0][0], &clicks[0][1], &clicks[1][0], &clicks[1][1]);

        // flip selected cells
        for(int i=0; i<2; i++) {
            int row = clicks[i][0] - 1;
            int col = clicks[i][1] - 1;
            if(row < 0 || row >= ROWS || col < 0 || col >= COLS) {
                printf("Invalid cell selected.\n");
                continue;
            }
            if(board[row][col] == 0) {
                printf("This cell is already flipped.\n");
                continue;
            }
            if(num_clicks == 1 && row == clicks[0][0]-1 && col == clicks[0][1]-1) {
                printf("You cannot select the same cell twice in one turn.\n");
                continue;
            }
            board[row][col] *= -1;
        }

        // check for matched cells
        if(num_clicks == 1) {
            int match_found = 0;
            for(int i=0; i<ROWS; i++) {
                for(int j=0; j<COLS; j++) {
                    if(board[i][j] < 0) {
                        board[i][j] *= -1;
                    } else if(board[i][j] > 0) {
                        board[i][j] = 0;
                    }
                }
            }
            if(board[clicks[0][0]-1][clicks[0][1]-1] == board[clicks[1][0]-1][clicks[1][1]-1]) {
                printf("Match found!\n");
                match_found = 1;
            }
            if(!match_found) {
                printf("No match found. Flipping cells back.\n");
                board[clicks[0][0]-1][clicks[0][1]-1] *= -1;
                board[clicks[1][0]-1][clicks[1][1]-1] *= -1;
            }
            num_clicks = 0;
        } else {
            num_clicks = 1;
        }
    }

    return 0;
}