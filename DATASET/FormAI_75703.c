//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: grateful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define ROWS 10
#define COLS 10
#define ALIENS 10

bool gameOver;
int playerX, score;
char aliens[ROWS][COLS];
int alienX[ALIENS], alienY[ALIENS];

void init() {
    gameOver = false;
    playerX = 5;
    score = 0;

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            aliens[i][j] = '-';
        }
    }

    srand(time(NULL));
    for(int i = 0; i < ALIENS; i++) {
        alienX[i] = rand() % COLS;
        alienY[i] = rand() % ROWS;
        aliens[alienY[i]][alienX[i]] = 'A';
    }
}

void draw() {
    system("clear");

    printf("Score: %d\n", score);

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i == ROWS - 1 && j == playerX) {
                printf("V");
            }
            else {
                printf("%c", aliens[i][j]);
            }
        }
        printf("\n");
    }
}

void input() {
    char c = getchar();
    if(c == 'a') {
        playerX--;
        if(playerX < 0) {
            playerX = 0;
        }
    }
    else if(c == 'd') {
        playerX++;
        if(playerX >= COLS) {
            playerX = COLS - 1;
        }
    }
}

void update() {
    for(int i = 0; i < ALIENS; i++) {
        aliens[alienY[i]][alienX[i]] = '-';
        alienY[i]++;
        if(alienY[i] >= ROWS) {
            alienY[i] = 0;
            alienX[i] = rand() % COLS;
        }
        aliens[alienY[i]][alienX[i]] = 'A';
    }

    if(aliens[ROWS - 1][playerX] == 'A') {
        gameOver = true;
    }

    if(gameOver == false) {
        score++;
    }
}

int main() {
    init();

    while(gameOver == false) {
        draw();
        input();
        update();
        usleep(50000);
    }

    printf("Game Over!\n");

    return 0;
}