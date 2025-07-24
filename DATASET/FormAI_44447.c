//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 50
#define HEIGHT 30

int getch(void);
void initBoard(void);
void drawBoard(void);
void updateBoard(int, int);
void spawnEnemies(void);
bool isGameOver(void);
void printGameOver(void);

int board[HEIGHT][WIDTH];
int playerPos = 0;
int score = 0;
int level = 1;
int enemyCount = 0;

int main(void) {
    initBoard();
    while (true) {
        drawBoard();
        int key = getch();
        if (key == 'q') break;
        else if (key == 'a' && playerPos > 0) updateBoard(playerPos, --playerPos);
        else if (key == 'd' && playerPos < WIDTH - 1) updateBoard(playerPos, ++playerPos);
        spawnEnemies();
        if (isGameOver()) {
            printGameOver();
            break;
        }
    }
    return 0;
}

int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

void initBoard(void) {
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = 0;
        }
    }
    spawnEnemies();
}

void drawBoard(void) {
    system("clear");
    printf("Score: %d\t\tLevel: %d\n", score, level);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == 0) printf(" ");
            else if (board[i][j] == 1) printf("o");
            else if (board[i][j] == 2) printf("x");
            else if (board[i][j] == 3) printf("-");
        }
        printf("\n");
    }
}

void updateBoard(int prevX, int currX) {
    board[HEIGHT-1][prevX] = 0;
    board[HEIGHT-1][currX] = 1;
}

void spawnEnemies(void) {
    if (enemyCount < level + 1) {
        int enemyPos = rand() % WIDTH;
        while (board[0][enemyPos] == 2) enemyPos = rand() % WIDTH;
        board[0][enemyPos] = 2;
        enemyCount++;
    }
    else {
        enemyCount = 0;
        level++;
    }
    for (int i = HEIGHT-2; i >= 0; i--) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == 2 && board[i+1][j] == 1) {
                board[i][j] = 3;
                board[i+1][j] = 0;
            }
        }
    }
    for (int i = 0; i < WIDTH; i++) {
        if (board[HEIGHT-1][i] == 2) {
            printGameOver();
            exit(0);
        }
    }
}

bool isGameOver(void) {
    for (int i = 0; i < WIDTH; i++) {
        if (board[HEIGHT-1][i] == 1) {
            score += level * 10;
            return true;
        }
    }
    return false;
}

void printGameOver(void) {
    system("clear");
    printf("GAME OVER\n");
    printf("Score: %d\n", score);
}