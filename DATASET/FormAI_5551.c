//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 20

#define PLAYER_WIDTH 3
#define PLAYER_HEIGHT 1
#define PLAYER_START_X (SCREEN_WIDTH/2 - PLAYER_WIDTH/2)
#define PLAYER_START_Y (SCREEN_HEIGHT - PLAYER_HEIGHT - 1)

#define BULLET_WIDTH 1
#define BULLET_HEIGHT 1

#define ALIEN_WIDTH 3
#define ALIEN_HEIGHT 1
#define ALIEN_START_X 1
#define ALIEN_START_Y 1
#define ALIEN_ROWS 3
#define ALIEN_COLS 14
#define ALIEN_SPACING 2

#define GAME_SPEED 250 // in milliseconds

void clearScreen() {
    system("clear||cls");
}

void delay(int ms) {
    clock_t start = clock();
    while(clock() - start < (ms * CLOCKS_PER_SEC/1000));
}

void drawPlayer(char screen[][SCREEN_WIDTH], int playerX) {
    for(int i=0; i<PLAYER_HEIGHT; i++) {
        for(int j=0; j<PLAYER_WIDTH; j++) {
            screen[PLAYER_START_Y+i][playerX+j] = '|';
        }
    }
}

void drawBullet(char screen[][SCREEN_WIDTH], int bulletX, int bulletY) {
    screen[bulletY][bulletX] = '^';
}

void drawAliens(char screen[][SCREEN_WIDTH], int aliensX[][ALIEN_COLS], int aliensY[][ALIEN_COLS]) {
    for(int i=0; i<ALIEN_ROWS; i++) {
        for(int j=0; j<ALIEN_COLS; j++) {
            if(aliensX[i][j] != -1 && aliensY[i][j] != -1) {
                for(int u=0; u<ALIEN_HEIGHT; u++) {
                    for(int v=0; v<ALIEN_WIDTH; v++) {
                        screen[aliensY[i][j]+u][aliensX[i][j]+v] = 'O';
                    }
                }
            }
        }
    }
}

bool detectCollision(int bulletX, int bulletY, int alienX, int alienY) {
    return (bulletX >= alienX && bulletX < alienX+ALIEN_WIDTH && bulletY == alienY) ? true : false;
}

bool isGameOver(int aliensX[][ALIEN_COLS], int aliensY[][ALIEN_COLS]) {
    for(int i=0; i<ALIEN_ROWS; i++) {
        for(int j=0; j<ALIEN_COLS; j++) {
            if(aliensX[i][j] != -1 && aliensY[i][j] != -1) {
                if(aliensY[i][j]+ALIEN_HEIGHT-1 >= PLAYER_START_Y) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
    int playerX = PLAYER_START_X;
    int bulletX=-1, bulletY=-1;
    int aliensX[ALIEN_ROWS][ALIEN_COLS];
    int aliensY[ALIEN_ROWS][ALIEN_COLS];
    bool gameOver = false;
    bool moveRight = true;
    bool fire = false;
    int moveCount = 0;

    srand(time(NULL));

    // init alien position
    for(int i=0; i<ALIEN_ROWS; i++) {
        for(int j=0; j<ALIEN_COLS; j++) {
            aliensX[i][j] = ALIEN_START_X + j*(ALIEN_WIDTH+ALIEN_SPACING);
            aliensY[i][j] = ALIEN_START_Y + i*(ALIEN_HEIGHT+ALIEN_SPACING);
        }
    }

    while(!gameOver) {
        clearScreen();

        // draw screen
        for(int i=0; i<SCREEN_HEIGHT; i++) {
            for(int j=0; j<SCREEN_WIDTH; j++) {
                screen[i][j] = ' ';
            }
            screen[i][SCREEN_WIDTH-1] = '\n';
        }
        drawPlayer(screen, playerX);
        if(bulletY != -1) {
            drawBullet(screen, bulletX, bulletY);
        }
        drawAliens(screen, aliensX, aliensY);

        // display screen
        for(int i=0; i<SCREEN_HEIGHT; i++) {
            printf("%s", screen[i]);
        }

        // detect collision
        if(bulletY != -1) {
            for(int i=0; i<ALIEN_ROWS; i++) {
                for(int j=0; j<ALIEN_COLS; j++) {
                    if(aliensX[i][j] != -1 && aliensY[i][j] != -1) {
                        if(detectCollision(bulletX, bulletY, aliensX[i][j], aliensY[i][j])) {
                            aliensX[i][j] = -1;
                            aliensY[i][j] = -1;
                            bulletX = -1;
                            bulletY = -1;
                        }
                    }
                }
            }
        }

        // game over
        if(isGameOver(aliensX, aliensY)) {
            printf("Game Over\n");
            gameOver = true;
            break;
        }

        // move player
        char command;
        if(scanf("%c", &command) == 1) {
            switch(command) {
                case 'a':   if(playerX > 0) {
                                playerX--;
                            }
                            break;
                case 'd':   if(playerX < SCREEN_WIDTH-PLAYER_WIDTH) {
                                playerX++;
                            }
                            break;
                case ' ':   if(bulletY == -1) {
                                bulletX = playerX + PLAYER_WIDTH/2;
                                bulletY = PLAYER_START_Y-1;
                                fire = true;
                            }
                            break;
            }
        }

        // move aliens
        moveCount++;
        if(moveCount == 10) {
            moveCount = 0;
            int minY = SCREEN_HEIGHT;
            int maxY = -1;
            for(int i=0; i<ALIEN_ROWS; i++) {
                for(int j=0; j<ALIEN_COLS; j++) {
                    if(aliensX[i][j] != -1 && aliensY[i][j] != -1) {
                        if(moveRight) {
                            aliensX[i][j]++;
                            if(aliensX[i][j]+ALIEN_WIDTH == SCREEN_WIDTH) {
                                moveRight = false;
                            }
                        } else {
                            aliensX[i][j]--;
                            if(aliensX[i][j] == 0) {
                                moveRight = true;
                            }
                        }
                        if(aliensY[i][j]+ALIEN_HEIGHT > maxY) {
                            maxY = aliensY[i][j]+ALIEN_HEIGHT;
                        }
                        if(aliensY[i][j] < minY) {
                            minY = aliensY[i][j];
                        }
                    }
                }
            }
            if(fire) {
                bulletY--;
                if(bulletY == minY) {
                    bulletX = -1;
                    bulletY = -1;
                }
            }
        }
        delay(GAME_SPEED);
    }

    return 0;
}