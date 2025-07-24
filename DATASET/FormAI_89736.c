//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    // generate the bingo card
    int card[SIZE][SIZE];
    int i, j;

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(i == SIZE / 2 && j == SIZE / 2) {
                // free space in the middle of the card
                card[i][j] = 0;
            } else {
                card[i][j] = rand() % 15 + j * 15 + 1;
            }
        }
    }

    // print the bingo card
    printf("Let's play Bingo!\n\n");

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }

    int board[SIZE][SIZE] = {0}; // initialize the playing board with all 0's
    int num;

    while(1) {
        printf("\nEnter the number called (or 0 to quit): ");
        scanf("%d", &num);

        if(num == 0) {
            printf("Thanks for playing!\n");
            break;
        }

        // mark all instances of the called number on the playing board
        for(i = 0; i < SIZE; i++) {
            for(j = 0; j < SIZE; j++) {
                if(card[i][j] == num) {
                    board[i][j] = 1;
                }
            }
        }

        // check for a win in any of the rows, columns, or diagonals
        int row_sum, col_sum, diag_sum1, diag_sum2;
        for(i = 0; i < SIZE; i++) {
            row_sum = 0;
            col_sum = 0;
            for(j = 0; j < SIZE; j++) {
                row_sum += board[i][j];
                col_sum += board[j][i];
            }
            if(row_sum == SIZE || col_sum == SIZE) {
                // we have a bingo!
                printf("Bingo! You won!\n");
                return 0;
            }
        }
        diag_sum1 = 0;
        diag_sum2 = 0;
        for(i = 0; i < SIZE; i++) {
            diag_sum1 += board[i][i];
            diag_sum2 += board[i][SIZE - i - 1];
        }
        if(diag_sum1 == SIZE || diag_sum2 == SIZE) {
            // we have a bingo!
            printf("Bingo! You won!\n");
            return 0;
        }
    }

    return 0;
}