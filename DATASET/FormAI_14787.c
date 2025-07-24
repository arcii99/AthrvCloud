//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int board[ROWS][COLS];

typedef struct {
    int row;
    int col;
} Cell;

void *drawNumbers(void *arg);
void *checkWin(void *arg);

int main() {
    srand(time(NULL));
    int i, j, input;
    memset(board, 0, sizeof(board));

    // create thread for drawing numbers
    pthread_t drawThread;
    pthread_create(&drawThread, NULL, drawNumbers, NULL);

    // create thread for checking win status
    pthread_t checkThread;
    pthread_create(&checkThread, NULL, checkWin, NULL);

    // main game loop
    while (1) {
        printf("\n\nEnter the drawn number (0 to exit): ");
        scanf("%d", &input);

        if (input == 0) {
            break;
        }

        // check input against board numbers
        int found = 0;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == input) {
                    board[i][j] = -1;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("\nThat number doesn't exist on the board.\n");
        }
    }

    pthread_cancel(drawThread);
    pthread_cancel(checkThread);

    return 0;
}

// thread to continuously draw random numbers
void *drawNumbers(void *arg) {
    int i, j, num;
    while (1) {
        num = rand() % 25 + 1;
        printf("Drawn number: %d\n", num);

        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    board[i][j] = -1;
                }
            }
        }

        sleep(1);
    }
}

// thread to check win status
void *checkWin(void *arg) {
    int i, j;
    while (1) {
        // check rows
        for (i = 0; i < ROWS; i++) {
            int bingo = 1;
            for (j = 0; j < COLS; j++) {
                if (board[i][j] != -1) {
                    bingo = 0;
                    break;
                }
            }
            if (bingo) {
                printf("\nBingo! Row %d is complete.\n", i+1);
                exit(0);
            }
        }

        // check columns
        for (j = 0; j < COLS; j++) {
            int bingo = 1;
            for (i = 0; i < ROWS; i++) {
                if (board[i][j] != -1) {
                    bingo = 0;
                    break;
                }
            }
            if (bingo) {
                printf("\nBingo! Column %d is complete.\n", j+1);
                exit(0);
            }
        }

        // check diagonals
        if ((board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1)
            || (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1)) {
            printf("\nBingo! Diagonal is complete.\n");
            exit(0);
        }

        sleep(1);
    }
}