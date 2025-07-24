//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 30
#define HEIGHT 20

#define PLAYER 'A'
#define INVADER 'V'
#define BULLET '|'

int kbhit();
void setCursorPosition(int x, int y);
void showGame(char game[HEIGHT][WIDTH]);
void initGame(char game[HEIGHT][WIDTH], int *playerX, int *playerY);
void moveInvaders(char game[HEIGHT][WIDTH], int *invadersLeft, int *bulletX, int *bulletY);
void movePlayer(char game[HEIGHT][WIDTH], int playerX, int playerY);
void shoot(char game[HEIGHT][WIDTH], int playerX, int playerY, int *bulletX, int *bulletY);

int main()
{
    char game[HEIGHT][WIDTH];
    int playerX, playerY, invadersLeft = HEIGHT * WIDTH / 3, bulletX = -1, bulletY = -1;

    initGame(game, &playerX, &playerY);

    while (invadersLeft > 0) {
        usleep(100000);
        system("clear");

        if (kbhit()) {
            char c = getchar();
            if (c == 'a' || c == 'A') {
                movePlayer(game, playerX - 1, playerY);
                playerX--;
            } else if (c == 'd' || c == 'D') {
                movePlayer(game, playerX + 1, playerY);
                playerX++;
            } else if (c == ' ') {
                if (bulletY == -1) {
                    shoot(game, playerX, playerY, &bulletX, &bulletY);
                }
            }
        }

        moveInvaders(game, &invadersLeft, &bulletX, &bulletY);

        showGame(game);
    }

    setCursorPosition(HEIGHT/2, WIDTH/2);
    printf("GAME OVER\n");

    return 0;
}

void initGame(char game[HEIGHT][WIDTH], int *playerX, int *playerY) {
    int i, j;
    for (i = 0 ; i < HEIGHT ; i++) {
        for (j = 0 ; j < WIDTH ; j++) {
            game[i][j] = ' ';
        }
    }
    for (i = 0 ; i < WIDTH ; i++) {
        game[HEIGHT-1][i] = INVADER;
    }
    game[HEIGHT-2][WIDTH/2] = PLAYER;
    *playerX = WIDTH/2;
    *playerY = HEIGHT-2;
}

void movePlayer(char game[HEIGHT][WIDTH], int playerX, int playerY) {
    if (playerX < 0 || playerX >= WIDTH) {
        return;
    }
    game[playerY][playerX] = PLAYER;
    game[playerY][playerX-1] = ' ';
    game[playerY][playerX+1] = ' ';
    if (playerY < HEIGHT-2) {
        game[playerY+1][playerX] = ' ';
    }
    if (playerY > 0) {
        game[playerY-1][playerX] = ' ';
    }
    if (playerX > 1) {
        game[playerY][playerX-2] = ' ';
    }
    if (playerX < WIDTH-2) {
        game[playerY][playerX+2] = ' ';
    }
}

void moveInvaders(char game[HEIGHT][WIDTH], int *invadersLeft, int *bulletX, int *bulletY) {
    static int dir = 1; // 1=right, -1=left
    int i, j, invadersMoved = 0;

    if (*bulletY >= 0) {
        game[*bulletY][*bulletX] = ' ';
        *bulletY -= 1;
        if (*bulletY >= 0 && game[*bulletY][*bulletX] == INVADER) {
            game[*bulletY][*bulletX] = ' ';
            *invadersLeft -= 1;
        }
        if (*bulletY < 0) {
            *bulletX = -1;
        }
    }

    for (j = 0 ; j < WIDTH ; j++) {
        if (game[0][j] == INVADER && rand() % 7 != 0) {
            game[0][j] = ' ';
        }
    }

    for (i = HEIGHT-2 ; i >= 0 ; i--) {
        for (j = 0 ; j < WIDTH ; j++) {
            if (game[i][j] == INVADER) {
                game[i+1][j] = INVADER;
                game[i][j] = ' ';
                invadersMoved++;

                if (i+1 == HEIGHT-1) {
                    setCursorPosition(HEIGHT/2, WIDTH/2);
                    printf("GAME OVER\n");
                    exit(0);
                }

                if (game[i+1][j-1] == BULLET || game[i+1][j+1] == BULLET) {
                    game[i+1][j] = ' ';
                    *invadersLeft -= 1;
                }
            }
        }
    }

    if (invadersMoved > 0) {
        if (dir == 1) {
            if (game[HEIGHT-2][WIDTH-1] == INVADER) {
                dir = -1;
            } else {
                movePlayer(game, WIDTH-3, HEIGHT-2);
            }
        } else {
            if (game[HEIGHT-2][0] == INVADER) {
                dir = 1;
            } else {
                movePlayer(game, 2, HEIGHT-2);
            }
        }
    }
}

void shoot(char game[HEIGHT][WIDTH], int playerX, int playerY, int *bulletX, int *bulletY) {
    *bulletX = playerX;
    *bulletY = playerY - 1;
    game[*bulletY][*bulletX] = BULLET;
}

void showGame(char game[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0 ; i < HEIGHT ; i++) {
        for (j = 0 ; j < WIDTH ; j++) {
            printf("%c", game[i][j]);
        }
        printf("\n");
    }
}

int kbhit() {
    struct termios oldt, newt;
    int ch, oldf;

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

void setCursorPosition(int x, int y) {
    printf("\033[%d;%dH", y, x);
}