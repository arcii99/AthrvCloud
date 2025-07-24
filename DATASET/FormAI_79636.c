//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int board[5][5], i, j, numbers[25], call;
    char response;

    // initialize the board to all zeros
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            board[i][j] = 0;
        }
    }

    // initialize the array of numbers
    for (i = 0; i < 25; i++) {
        numbers[i] = i + 1;
    }

    // shuffle the array of numbers
    srand(time(NULL));
    for (i = 0; i < 25; i++) {
        int random_index = rand() % 25;
        int temp = numbers[i];
        numbers[i] = numbers[random_index];
        numbers[random_index] = temp;
    }

    // print the board and wait for responses
    do {
        printf("B   I   N   G   O\n");
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (board[i][j] == 0) {
                    printf("--  ");
                } else {
                    printf("%02d  ", board[i][j]);
                }
            }
            printf("\n");
        }

        printf("Enter the next number or 'q' to quit: ");
        scanf("%d", &call);

        if (call == 'q') {
            break;
        }

        // mark the number on the board
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (board[i][j] == call) {
                    board[i][j] = -1;
                }
            }
        }

        // check if any horizontal or vertical line is filled
        for (i = 0; i < 5; i++) {
            if (board[i][0] == -1 && board[i][1] == -1 && board[i][2] == -1 && board[i][3] == -1 && board[i][4] == -1) {
                printf("Bingo! Horizontal line filled.\n");
                break;
            }
            if (board[0][i] == -1 && board[1][i] == -1 && board[2][i] == -1 && board[3][i] == -1 && board[4][i] == -1) {
                printf("Bingo! Vertical line filled.\n");
                break;
            }
        }

    } while(call != 'q');

    return 0;
}