//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: sophisticated
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>

#define HEIGHT 20
#define WIDTH 30

char board[HEIGHT][WIDTH];
int ballX, ballY;
int aiX, aiY;
int playerX, playerY;
int score;

void initBoard() {
    memset(board, ' ', sizeof(board));
    int i;
    for (i = 0; i < WIDTH; ++i) {
        board[0][i] = '-';
        board[HEIGHT-1][i] = '-';
    }
    for (i = 0; i < HEIGHT; ++i) {
        board[i][0] = '|';
        board[i][WIDTH-1] = '|';
    }
    ballX = WIDTH / 2;
    ballY = HEIGHT / 2;
    aiX = 2;
    aiY = HEIGHT / 2;
    playerX = WIDTH - 3;
    playerY = HEIGHT / 2;
    score = 0;
}

void applyAI() {
    if (aiY < ballY) {
        aiY++;
    } else {
        aiY--;
    }
}

void moveBall() {
    if (board[ballY][ballX] == '|') {
        if (ballY == aiY) {
            applyAI();
        } else {
            score++;
            ballX = WIDTH / 2;
            ballY = HEIGHT / 2;
            aiY = HEIGHT / 2;
        }
    } else {
        ballX--;
    }
}

void movePlayer(int dir) {
    if (playerY + dir > 1 && playerY + dir < HEIGHT - 2) {
        playerY += dir;
    }
}

void render() {
    int i, j;
    printf("\033[H\033[J");
    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            if (i == ballY && j == ballX) {
                printf("O");
            } else if (i == aiY && j == aiX) {
                printf("|");
            } else if (i == playerY && j == playerX) {
                printf("|");
            } else {
                printf("%c", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    initBoard();
    int dir = 0;
    int aiDelay = 0;
    clock_t lastTime = clock();
    while (1) {
        if (kbhit()) {
            char ch = getchar();
            if (ch == 'w') {
                dir = -1;
            } else if (ch == 's') {
                dir = 1;
            }
        }
        clock_t currentTime = clock();
        if (currentTime - lastTime > CLOCKS_PER_SEC / 20) {
            moveBall();
            if (++aiDelay == 2) {
                aiDelay = 0;
                applyAI();
            }
            movePlayer(dir);
            render();
            lastTime = currentTime;
            dir = 0;
        }
    }
    return 0;
}