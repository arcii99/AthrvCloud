//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <termios.h>
#include <fcntl.h>
#include <signal.h>

#define WIDTH 50
#define HEIGHT 20

int score = 0;
int lives = 3;
int level = 1;

char field[HEIGHT][WIDTH];

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    bool active;
} Bullet;

typedef struct {
    Point position;
    bool active;
} Invader;

typedef struct {
    Point position;
    int lives;
} Player;

Player player;
Bullet playerBullet;
Bullet invaderBullets[WIDTH];
Invader invaders[WIDTH];

int invaderDirectionX = 1;
int invaderDirectionY = 0;
int pauseTime = 100000;

int kbhit(void);
void setup();
void draw();
void handleInput();
void update();
void endGame();
void spawnInvaders();
void updateInvaders();
void updatePlayerBullet();
void updateInvaderBullets();
void resetGame();

int main() {
    setup();
    spawnInvaders();

    while(lives > 0) {
        draw();
        handleInput();
        update();

        if(score == WIDTH * HEIGHT) {
            printf("\nCongratulations, you beat the game!\n");
            endGame();
            return 0;
        }

        usleep(pauseTime);
    }

    endGame();
    return 0;
}

void resetGame() {
    score = 0;
    level = 1;
    lives = 3;
    invaderDirectionX = 1;
    invaderDirectionY = 0;
    pauseTime = 100000;

    playerBullet.active = false;

    for(int i = 0; i < WIDTH; i++) {
        invaderBullets[i].active = false;
    }

    for(int i = 0; i < WIDTH; i++) {
        invaders[i].active = false;
    }

    spawnInvaders();
}

void setup() {
    player.position.x = WIDTH / 2;
    player.position.y = HEIGHT - 1;
    player.lives = 3;

    playerBullet.active = false;

    for(int i = 0; i < WIDTH; i++) {
        invaderBullets[i].active = false;
    }

    for(int i = 0; i < WIDTH; i++) {
        invaders[i].active = false;
    }
}

void spawnInvaders() {
    int startX = 5;
    int startY = 5;

    for(int i = 0; i < WIDTH; i++) {
        invaders[i].position.x = startX + (i % 10);
        invaders[i].position.y = startY + (i / 10);
        invaders[i].active = true;
    }
}

void draw() {
    printf("\033[H\033[J"); //clear console

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(field[i][j] == '*') {
                printf("*");
            }
            else if(player.position.x == j && player.position.y == i) {
                printf("P");
            }
            else if(playerBullet.active && playerBullet.position.x == j && playerBullet.position.y == i) {
                printf("|");
            }
            else {
                bool invaderFound = false;

                for(int k = 0; k < WIDTH; k++) {
                    if(invaders[k].active && invaders[k].position.x == j && invaders[k].position.y == i) {
                        printf("I");
                        invaderFound = true;
                        break;
                    }
                    else if(invaderBullets[k].active && invaderBullets[k].position.x == j && invaderBullets[k].position.y == i) {
                        printf("!");
                        invaderFound = true;
                        break;
                    }
                }

                if(!invaderFound) {
                    printf(" ");
                }
            }
        }

        printf("\n");
    }

    printf("Level: %d | Score: %d | Lives: %d\n", level, score, lives);
}

void handleInput() {
    int key = kbhit();
    bool moved = false;

    switch(key) {
        case 'a':
            player.position.x--;
            moved = true;
            break;
        case 'd':
            player.position.x++;
            moved = true;
            break;
        case ' ':
            if(!playerBullet.active) {
                playerBullet.active = true;
                playerBullet.position.x = player.position.x;
                playerBullet.position.y = player.position.y;
            }
            break;
        case 'q':
            endGame();
            break;
        case 'r':
            resetGame();
            break;
    }

    if(moved) {
        if(player.position.x < 0) {
            player.position.x = 0;
        }
        else if(player.position.x >= WIDTH) {
            player.position.x = WIDTH - 1;
        }
    }
}

void update() {
    updatePlayerBullet();
    updateInvaders();
    updateInvaderBullets();

    for(int i = 0; i < WIDTH; i++) {
        if(invaders[i].active && ((playerBullet.active && playerBullet.position.x == invaders[i].position.x && playerBullet.position.y == invaders[i].position.y) || (invaderBullets[i].active && invaderBullets[i].position.x == player.position.x && invaderBullets[i].position.y == player.position.y))) {
            score++;
            invaders[i].active = false;

            if(playerBullet.active && playerBullet.position.x == invaders[i].position.x && playerBullet.position.y == invaders[i].position.y) {
                playerBullet.active = false;
            }

            if(invaderBullets[i].active && invaderBullets[i].position.x == player.position.x && invaderBullets[i].position.y == player.position.y) {
                invaderBullets[i].active = false;
                lives--;

                if(lives <= 0) {
                    endGame();
                    return;
                }

                resetGame();
                break;
            }
        }
        else if(invaders[i].active && invaders[i].position.x + invaderDirectionX < 0 || invaders[i].position.x + invaderDirectionX >= WIDTH) {
            invaderDirectionX *= -1;
            invaderDirectionY = 1;
            break;
        }
        else if(invaders[i].active) {
            invaders[i].position.x += invaderDirectionX;
            invaders[i].position.y += invaderDirectionY;
        }
    }
}

void updatePlayerBullet() {
    if(playerBullet.active) {
        playerBullet.position.y--;

        if(playerBullet.position.y < 0) {
            playerBullet.active = false;
        }
    }
}

void updateInvaders() {
    bool movedDown = false;

    for(int i = 0; i < WIDTH; i++) {
        if(invaders[i].active) {
            if(invaders[i].position.y + 1 >= player.position.y && invaders[i].position.x == player.position.x) {
                lives--;
                resetGame();

                if(lives <= 0) {
                    endGame();
                    return;
                }

                break;
            }
            else {
                if(rand() % (10 - level) == 0 && !invaderBullets[i].active) {
                    invaderBullets[i].active = true;
                    invaderBullets[i].position.x = invaders[i].position.x;
                    invaderBullets[i].position.y = invaders[i].position.y + 1;
                }
            }
        }
    }
}

void updateInvaderBullets() {
    for(int i = 0; i < WIDTH; i++) {
        if(invaderBullets[i].active) {
            invaderBullets[i].position.y++;

            if(invaderBullets[i].position.y >= HEIGHT) {
                invaderBullets[i].active = false;
            }
        }
    }
}

void endGame() {
    printf("Game Over\n");
    printf("Final Score: %d\n", score);
    exit(0);
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

    if(ch != EOF) {
        return ch;
    }

    return 0;
}