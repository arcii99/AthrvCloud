//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int board[5][5] = {0};
    int used[76] = {0};
    int i, j, num, win = 0;

    printf("Welcome to the Bingo Simulator!\n");

    // generate the board
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                board[i][j] = -1;
            } else {
                num = (rand() % 15) + (j * 15) + 1;
                while (used[num]) {
                    num = (rand() % 15) + (j * 15) + 1;
                }
                used[num] = 1;
                board[i][j] = num;
            }
        }
    }

    // print the board
    printf("\nHere is your board:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // play the game
    num = (rand() % 75) + 1;
    while (!win) {
        printf("The next number is: %d\n", num);
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (board[i][j] == num) {
                    board[i][j] = -1;
                }
            }
        }
        // check for win
        win = 1;
        for (i = 0; i < 5; i++) {
            if (board[i][0] == -1 && board[i][1] == -1 && board[i][2] == -1 && board[i][3] == -1 && board[i][4] == -1) {
                printf("BINGO! Horizontal win on row %d!\n", i+1);
                win = 0;
                break;
            }
            if (board[0][i] == -1 && board[1][i] == -1 && board[2][i] == -1 && board[3][i] == -1 && board[4][i] == -1) {
                printf("BINGO! Vertical win on column %d!\n", i+1);
                win = 0;
                break;
            }
        }
        if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
            printf("BINGO! Diagonal win from top left to bottom right!\n");
            win = 0;
        }
        if (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
            printf("BINGO! Diagonal win from top right to bottom left!\n");
            win = 0;
        }
        num = (rand() % 75) + 1;
    }

    printf("Congratulations on the win!\n");
    return 0;
}