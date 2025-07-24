//FormAI DATASET v1.0 Category: Chess AI ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[8][8] = {0};

void printBoard() {
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isMoveValid(int x1,int y1,int x2,int y2, int player) {
    if (player == 1) {
        if (board[x1][y1] == 1) {
            if ((x2-x1 == 1 || (x2-x1 == 2 && x1 == 1)) && y2-y1 == 0) {
                if (board[x2][y2] == 0) {
                    return 1;
                }
            }
            else if (x2-x1 == 1 && abs(y2-y1) == 1) {
                if (board[x2][y2] < 0) {
                    return 1;
                }
            }
        }
        else if (board[x1][y1] == 2) {
            if ((x2-x1 == 1 || (x2-x1 == 2 && x1 == 1)) && y2-y1 == 0 && board[x2][y2] == 0) {
                int flag = 1;
                for (int i=x1+1;i<=x2;i++) {
                    if (board[i][y1] != 0) {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1) {
                    return 1;
                }
            }
            else if (abs(x2-x1) == 1 && abs(y2-y1) == 1) {
                if (board[x2][y2] < 0 || board[x2][y2] == 0) {
                    return 0;
                }
                else {
                    return 1;
                }
            }
        }
    }
    else if (player == -1) {
        if (board[x1][y1] == -1) {
            if ((x2-x1 == -1 || (x2-x1 == -2 && x1 == 6)) && y2-y1 == 0) {
                if (board[x2][y2] == 0) {
                    return 1;
                }
            }
            else if (x2-x1 == -1 && abs(y2-y1) == 1) {
                if (board[x2][y2] > 0) {
                    return 1;
                }
            }
        }
        else if (board[x1][y1] == -2) {
            if ((x2-x1 == -1 || (x2-x1 == -2 && x1 == 6)) && y2-y1 == 0 && board[x2][y2] == 0) {
                int flag = 1;
                for (int i=x1-1;i>=x2;i--) {
                    if (board[i][y1] != 0) {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1) {
                    return 1;
                }
            }
            else if (abs(x2-x1) == 1 && abs(y2-y1) == 1) {
                if (board[x2][y2] > 0 || board[x2][y2] == 0) {
                    return 0;
                }
                else {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void play() {
    int turn = 1;
    srand(time(NULL));
    while (1) {
        printf("\nEnter the coordinates of the piece you want to move: ");
        int x1, y1, x2, y2;
        scanf("%d %d", &x1, &y1);
        printf("Enter the coordinates of the destination: ");
        scanf("%d %d", &x2, &y2);
        if (board[x1][y1] == 0 || (board[x1][y1] > 0 && turn == -1) || (board[x1][y1] < 0 && turn == 1) || !isMoveValid(x1, y1, x2, y2, turn)) {
            printf("\nInvalid move! Try again.\n");
            continue;
        }
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = 0;
        turn *= -1;
        printf("\n");
        printBoard();
        if (rand() % 2 == 0) {
            printf("\nAI's turn...\n");
            int ax1, ay1, ax2, ay2;
            do {
                ax1 = rand() % 8;
                ay1 = rand() % 8;
                ax2 = rand() % 8;
                ay2 = rand() % 8;
            } while (board[ax1][ay1] == 0 || (board[ax1][ay1] > 0 && turn == -1) || (board[ax1][ay1] < 0 && turn == 1) || !isMoveValid(ax1, ay1, ax2, ay2, turn));
            board[ax2][ay2] = board[ax1][ay1];
            board[ax1][ay1] = 0;
            turn *= -1;
            printf("\nAI moved from (%d, %d) to (%d, %d)\n", ax1, ay1, ax2, ay2);
            printBoard();
        }
        if (board[x2][y2] == -1) {
            printf("\nAI won!\n");
            break;
        }
        else if (board[x2][y2] == 1) {
            printf("\nYou won!\n");
            break;
        }
    }
}

int main() {
    printf("Welcome to Chess AI, let's begin!\n");
    board[0][0] = board[0][7] = -2;
    board[7][0] = board[7][7] = 2;
    board[0][1] = board[0][6] = -1;
    board[7][1] = board[7][6] = 1;
    for (int i=0;i<8;i++) {
        board[1][i] = -3;
        board[6][i] = 3;
    }
    printBoard();
    play();
    return 0;
}