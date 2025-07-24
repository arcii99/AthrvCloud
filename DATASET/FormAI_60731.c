//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(int board[][4], int score) {
    system("clear");
    printf("\nScore: %d\n\n", score);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                printf("|    ");
            } else {
                printf("| %2d ", board[i][j]);
            }
        }
        printf("|\n");
    }
}

int addNewNumber(int board[][4]) {
    int empty = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                empty++;
            }
        }
    }
    if (empty == 0) {
        return 0;
    }
    int position = rand() % empty;
    int value = (rand() % 2 + 1) * 2;
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                if (count == position) {
                    board[i][j] = value;
                    return 1;
                }
                count++;
            }
        }
    }
    return 0;
}

int moveLeft(int board[][4], int *score) {
    int moved = 0;
    for (int i = 0; i < 4; i++) {
        int last_merged = -1;
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                continue;
            }
            int k;
            for (k = j + 1; k < 4; k++) {
                if (board[i][k] != 0) {
                    break;
                }
            }
            if (k == 4) {
                k--;
            }
            if (board[i][k] == board[i][j] && k != last_merged) {
                board[i][j] *= 2;
                board[i][k] = 0;
                *score += board[i][j];
                last_merged = j;
                moved = 1;
            } else if (k-1 != j) {
                board[i][k-1] = board[i][j];
                board[i][j] = 0;
                moved = 1;
            }
        }
    }
    return moved;
}

int moveRight(int board[][4], int *score) {
    int moved = 0;
    for (int i = 0; i < 4; i++) {
        int last_merged = -1;
        for (int j = 3; j >= 0; j--) {
            if (board[i][j] == 0) {
                continue;
            }
            int k;
            for (k = j - 1; k >= 0; k--) {
                if (board[i][k] != 0) {
                    break;
                }
            }
            if (k == -1) {
                k++;
            }
            if (board[i][k] == board[i][j] && k != last_merged) {
                board[i][j] *= 2;
                board[i][k] = 0;
                *score += board[i][j];
                last_merged = j;
                moved = 1;
            } else if (k+1 != j) {
                board[i][k+1] = board[i][j];
                board[i][j] = 0;
                moved = 1;
            }
        }
    }
    return moved;
}

int moveUp(int board[][4], int *score) {
    int moved = 0;
    for (int i = 0; i < 4; i++) {
        int last_merged = -1;
        for (int j = 0; j < 4; j++) {
            if (board[j][i] == 0) {
                continue;
            }
            int k;
            for (k = j + 1; k < 4; k++) {
                if (board[k][i] != 0) {
                    break;
                }
            }
            if (k == 4) {
                k--;
            }
            if (board[k][i] == board[j][i] && k != last_merged) {
                board[j][i] *= 2;
                board[k][i] = 0;
                *score += board[j][i];
                last_merged = j;
                moved = 1;
            } else if (k-1 != j) {
                board[k-1][i] = board[j][i];
                board[j][i] = 0;
                moved = 1;
            }
        }
    }
    return moved;
}

int moveDown(int board[][4], int *score) {
    int moved = 0;
    for (int i = 0; i < 4; i++) {
        int last_merged = -1;
        for (int j = 3; j >= 0; j--) {
            if (board[j][i] == 0) {
                continue;
            }
            int k;
            for (k = j - 1; k >= 0; k--) {
                if (board[k][i] != 0) {
                    break;
                }
            }
            if (k == -1) {
                k++;
            }
            if (board[k][i] == board[j][i] && k != last_merged) {
                board[j][i] *= 2;
                board[k][i] = 0;
                *score += board[j][i];
                last_merged = j;
                moved = 1;
            } else if (k+1 != j) {
                board[k+1][i] = board[j][i];
                board[j][i] = 0;
                moved = 1;
            }
        }
    }
    return moved;
}

int checkGameOver(int board[][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
            if (j < 3 && board[i][j] == board[i][j+1]) {
                return 0;
            }
            if (i < 3 && board[i][j] == board[i+1][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    int board[4][4] = {0};
    int score = 0;
    addNewNumber(board);
    addNewNumber(board);
    printBoard(board, score);
    while (1) {
        char c = getchar();
        int moved = 0;
        if (c == 'a' || c == 'A') {
            moved = moveLeft(board, &score);
        } else if (c == 'd' || c == 'D') {
            moved = moveRight(board, &score);
        } else if (c == 'w' || c == 'W') {
            moved = moveUp(board, &score);
        } else if (c == 's' || c == 'S') {
            moved = moveDown(board, &score);
        } else if (c == 'q' || c == 'Q') {
            break;
        }
        if (moved) {
            addNewNumber(board);
        }
        printBoard(board, score);
        if (checkGameOver(board)) {
            printf("Game Over! Final Score: %d\n", score);
            break;
        }
    }
    return 0;
}