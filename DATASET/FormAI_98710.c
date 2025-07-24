//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <pthread.h>

#define BOARD_WIDTH 60
#define BOARD_HEIGHT 25

int board[BOARD_HEIGHT][BOARD_WIDTH];
int score = 0;
int lives = 3;
int level = 1;
int playerX = BOARD_WIDTH / 2 - 1;
int playerY = BOARD_HEIGHT - 2;
int alienSpeed = 1;
int alienWidth = 5;
int alienHeight = 3;
pthread_t aliensThread;

void initBoard() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (i == playerY && j >= playerX && j < playerX + 2) {
                board[i][j] = 1; // player ship
            } else if (i == 0 || j == 0 || i == BOARD_HEIGHT - 1 || j == BOARD_WIDTH - 1) {
                board[i][j] = 2; // boundaries
            } else {
                board[i][j] = 0; // empty space
            }
        }
    }
}

void printBoard() {
    system("clear");
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            switch (board[i][j]) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("=");
                    break;
                case 2:
                    printf("#");
                    break;
                case 3:
                    printf("o");
                    break;
                case 4:
                    printf("+");
                    break;
            }
        }
        printf("\n");
    }
    printf("Score: %d  Lives: %d\n", score, lives);
}

void movePlayer(int direction) {
    if (direction == 0 && playerX > 1) {
        playerX--;
    } else if (direction == 1 && playerX < BOARD_WIDTH - 2) {
        playerX++;
    }
    board[playerY][playerX] = 1;
    board[playerY][playerX + 1] = 1;
    board[playerY][playerX - 1] = 0;
}

void *moveAliens() {
    while (1) {
        for (int i = 1; i < BOARD_WIDTH - alienWidth - 1; i += alienWidth + 2) {
            for (int j = 1; j < BOARD_HEIGHT / 2; j += alienHeight + 1) {
                for (int k = j; k < j + alienHeight; k++) {
                    if (board[k][i] == 3) {
                        return NULL;
                    }
                }
                for (int k = j; k < j + alienHeight; k++) {
                    board[k][i] = 0;
                    if (k + 1 < BOARD_HEIGHT) {
                        board[k + 1][i] = 3;
                    }
                }
            }
        }
        usleep(100000 / alienSpeed);
    }
}

void shoot(int y, int x) {
    while (y > 0) {
        board[y][x] = 4;
        printBoard();
        usleep(50000);
        board[y][x] = 0;
        y--;
    }
    if (board[y][x] == 3) {
        score += 10;
        board[y][x] = 0;
    }
}

int main() {
    initBoard();
    pthread_create(&aliensThread, NULL, moveAliens, NULL);

    struct termios old, new;
    tcgetattr(STDIN_FILENO, &old);
    new = old;
    new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new);

    while (1) {
        printBoard();

        char c = getchar();
        if (c == 'q') break;

        if (c == 'a') {
            movePlayer(0);
        } else if (c == 'd') {
            movePlayer(1);
        } else if (c == ' ') {
            shoot(playerY - 1, playerX);
        }

        int gameover = 0;
        for (int i = 0; i < BOARD_WIDTH; i++) {
            if (board[BOARD_HEIGHT - 2][i] == 3) {
                gameover = 1;
                break;
            }
        }
        if (gameover) {
            lives--;
            if (lives == 0) {
                printf("Game Over!\n");
                return 0;
            }
            board[playerY][playerX] = 0;
            board[playerY][playerX - 1] = 0;
            board[playerY][playerX + 1] = 0;
            playerX = BOARD_WIDTH / 2 - 1;
            board[playerY][playerX] = 1;
            board[playerY][playerX + 1] = 1;
        }

        int aliensLeft = 0;
        for (int i = 1; i < BOARD_WIDTH - alienWidth - 1; i += alienWidth + 2) {
            for (int j = 1; j < BOARD_HEIGHT / 2; j += alienHeight + 1) {
                for (int k = j; k < j + alienHeight; k++) {
                    if (board[k][i] == 3) {
                        aliensLeft = 1;
                        break;
                    }
                }
            }
        }
        if (!aliensLeft) {
            level++;
            alienSpeed++;
            printf("Level %d!\n", level);
            usleep(500000);
            initBoard();
            pthread_cancel(aliensThread);
            pthread_create(&aliensThread, NULL, moveAliens, NULL);
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &old);
    return 0;
}