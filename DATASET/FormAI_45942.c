//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define BOARD_SIZE 15
#define NUM_THREADS 3

typedef struct {
    int x;
    int y;
} position;

int board[BOARD_SIZE][BOARD_SIZE];
position playerPos;

pthread_mutex_t boardLock;

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    playerPos.x = BOARD_SIZE / 2;
    playerPos.y = BOARD_SIZE / 2;
    board[playerPos.x][playerPos.y] = 1;
}

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == playerPos.x && j == playerPos.y) {
                printf("O ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool isGameFinished() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void movePlayer() {
    while (true) {
        char input = getchar();
        if (input == 'w' && playerPos.x > 0) {
            pthread_mutex_lock(&boardLock);
            board[playerPos.x][playerPos.y] = 0;
            playerPos.x -= 1;
            board[playerPos.x][playerPos.y] = 1;
            pthread_mutex_unlock(&boardLock);
        } else if (input == 'a' && playerPos.y > 0) {
            pthread_mutex_lock(&boardLock);
            board[playerPos.x][playerPos.y] = 0;
            playerPos.y -= 1;
            board[playerPos.x][playerPos.y] = 1;
            pthread_mutex_unlock(&boardLock);
        } else if (input == 's' && playerPos.x < BOARD_SIZE - 1) {
            pthread_mutex_lock(&boardLock);
            board[playerPos.x][playerPos.y] = 0;
            playerPos.x += 1;
            board[playerPos.x][playerPos.y] = 1;
            pthread_mutex_unlock(&boardLock);
        } else if (input == 'd' && playerPos.y < BOARD_SIZE - 1) {
            pthread_mutex_lock(&boardLock);
            board[playerPos.x][playerPos.y] = 0;
            playerPos.y += 1;
            board[playerPos.x][playerPos.y] = 1;
            pthread_mutex_unlock(&boardLock);
        }
    }
}

void *printInstructions(void *arg) {
    printf("Use w,a,s,d to move up, left, down and right respectively.\n");
}

void *checkWin(void *arg) {
    while (true) {
        if (isGameFinished()) {
            printf("Congratulations! You have won the game!\n");
            exit(0);
        }
        sleep(5);
    }
}

int main() {
    initializeBoard();

    pthread_t threads[NUM_THREADS];
    pthread_create(&threads[0], NULL, movePlayer, NULL);
    pthread_create(&threads[1], NULL, printInstructions, NULL);
    pthread_create(&threads[2], NULL, checkWin, NULL);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);

    return 0;
}