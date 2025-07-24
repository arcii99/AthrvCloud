//FormAI DATASET v1.0 Category: Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void initBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", i+1);
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i+1);
        if (i < 9) {
            printf(" ");
        }
        printf("|");
        for (j = 0; j < BOARD_SIZE; j++) {
            printf(" ");
            if (board[i][j] == 0) {
                printf(" ");
            } else if (board[i][j] == 1) {
                printf("O");
            } else if (board[i][j] == 2) {
                printf("X");
            }
            printf(" |");
        }
        printf("\n");
    }
}

int isValid(int x, int y, int board[BOARD_SIZE][BOARD_SIZE]) {
    if (x < 0 || x >= BOARD_SIZE) {
        return 0;
    }
    if (y < 0 || y >= BOARD_SIZE) {
        return 0;
    }
    if (board[x][y] != 0) {
        return 0;
    }
    return 1;
}

int checkWin(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j, k, count;
    // check horizontal lines
    for (i = 0; i < BOARD_SIZE; i++) {
        count = 0;
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 1) {
                count++;
            } else {
                count = 0;
            }
            if (count >= 5) {
                return 1;
            }
        }
        count = 0;
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 2) {
                count++;
            } else {
                count = 0;
            }
            if (count >= 5) {
                return 2;
            }
        }
    }
    // check vertical lines
    for (i = 0; i < BOARD_SIZE; i++) {
        count = 0;
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[j][i] == 1) {
                count++;
            } else {
                count = 0;
            }
            if (count >= 5) {
                return 1;
            }
        }
        count = 0;
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[j][i] == 2) {
                count++;
            } else {
                count = 0;
            }
            if (count >= 5) {
                return 2;
            }
        }
    }
    // check diagonal lines
    for (i = 0; i <= BOARD_SIZE-5; i++) {
        for (j = 0; j <= BOARD_SIZE-5; j++) {
            count = 0;
            for (k = 0; k < 5; k++) {
                if (board[i+k][j+k] == 1) {
                    count++;
                } else {
                    count = 0;
                }
                if (count >= 5) {
                    return 1;
                }
            }
            count = 0;
            for (k = 0; k < 5; k++) {
                if (board[i+k][j+k] == 2) {
                    count++;
                } else {
                    count = 0;
                }
                if (count >= 5) {
                    return 2;
                }
            }
        }
    }
    for (i = 0; i <= BOARD_SIZE-5; i++) {
        for (j = BOARD_SIZE-1; j >= 4; j--) {
            count = 0;
            for (k = 0; k < 5; k++) {
                if (board[i+k][j-k] == 1) {
                    count++;
                } else {
                    count = 0;
                }
                if (count >= 5) {
                    return 1;
                }
            }
            count = 0;
            for (k = 0; k < 5; k++) {
                if (board[i+k][j-k] == 2) {
                    count++;
                } else {
                    count = 0;
                }
                if (count >= 5) {
                    return 2;
                }
            }
        }
    }
    return 0;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int player = 1;
    int x, y;
    initBoard(board);
    srand(time(NULL));
    while (checkWin(board) == 0) {
        clearScreen();
        printf("Player %d's turn:\n", player);
        printBoard(board);
        if (player == 1) {
            printf("Enter row number (1-%d): ", BOARD_SIZE);
            scanf("%d", &x);
            printf("Enter column number (1-%d): ", BOARD_SIZE);
            scanf("%d", &y);
            x -= 1;
            y -= 1;
        } else {
            do {
                x = rand() % BOARD_SIZE;
                y = rand() % BOARD_SIZE;
            } while (!isValid(x, y, board));
        }
        board[x][y] = player;
        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }
    clearScreen();
    printf("Player %d wins!\n", checkWin(board));
    printBoard(board);
    return 0;
}