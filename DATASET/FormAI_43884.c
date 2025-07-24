//FormAI DATASET v1.0 Category: Memory Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

int board[BOARD_SIZE][BOARD_SIZE] = {0}; // Initialize the board to all zeros
int score = 0;

void printBoard() {
    printf("\nScore: %d\n", score);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addRandomTile() {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                count++;
            }
        }
    }
    if (count == 0) {
        printf("Game over!\n");
        exit(0);
    }
    int index = rand() % count;
    count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                if (count == index) {
                    board[i][j] = (rand() % 2 + 1) * 2;
                    return;
                }
                count++;
            }
        }
    }
}

void moveLeft() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 1; j < BOARD_SIZE; j++) {
            if (board[i][j] != 0) {
                int k = j - 1;
                while (k >= 0 && board[i][k] == 0) {
                    k--;
                }
                if (k >= 0 && board[i][k] == board[i][j]) {
                    board[i][k] *= 2;
                    score += board[i][k];
                    board[i][j] = 0;
                } else {
                    int temp = board[i][j];
                    board[i][j] = 0;
                    board[i][k + 1] = temp;
                }
            }
        }
    }
}

void moveRight() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = BOARD_SIZE - 2; j >= 0; j--) {
            if (board[i][j] != 0) {
                int k = j + 1;
                while (k < BOARD_SIZE && board[i][k] == 0) {
                    k++;
                }
                if (k < BOARD_SIZE && board[i][k] == board[i][j]) {
                    board[i][k] *= 2;
                    score += board[i][k];
                    board[i][j] = 0;
                } else {
                    int temp = board[i][j];
                    board[i][j] = 0;
                    board[i][k - 1] = temp;
                }
            }
        }
    }
}

void moveUp() {
    for (int j = 0; j < BOARD_SIZE; j++) {
        for (int i = 1; i < BOARD_SIZE; i++) {
            if (board[i][j] != 0) {
                int k = i - 1;
                while (k >= 0 && board[k][j] == 0) {
                    k--;
                }
                if (k >= 0 && board[k][j] == board[i][j]) {
                    board[k][j] *= 2;
                    score += board[k][j];
                    board[i][j] = 0;
                } else {
                    int temp = board[i][j];
                    board[i][j] = 0;
                    board[k + 1][j] = temp;
                }
            }
        }
    }
}

void moveDown() {
    for (int j = 0; j < BOARD_SIZE; j++) {
        for (int i = BOARD_SIZE - 2; i >= 0; i--) {
            if (board[i][j] != 0) {
                int k = i + 1;
                while (k < BOARD_SIZE && board[k][j] == 0) {
                    k++;
                }
                if (k < BOARD_SIZE && board[k][j] == board[i][j]) {
                    board[k][j] *= 2;
                    score += board[k][j];
                    board[i][j] = 0;
                } else {
                    int temp = board[i][j];
                    board[i][j] = 0;
                    board[k - 1][j] = temp;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    addRandomTile();
    addRandomTile();
    while (1) {
        printBoard();
        char move = getchar();
        while (getchar() != '\n'); // Clear stdin buffer
        switch (move) {
            case 'a':
                moveLeft();
                break;
            case 'd':
                moveRight();
                break;
            case 'w':
                moveUp();
                break;
            case 's':
                moveDown();
                break;
            default:
                printf("Invalid move\n");
                continue;
        }
        addRandomTile();
    }
    return 0;
}