//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

char screen[HEIGHT][WIDTH];

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point position;
    bool is_alive;
} Alien;

typedef struct {
    Point position;
    bool is_alive;
} Ship;

typedef struct {
    Point position;
    bool is_alive;
} Bullet;

Alien aliens[WIDTH][HEIGHT];
Ship ship;
Bullet bullet;
int score;
bool game_over;

void init() {
    memset(screen, ' ', sizeof(screen));
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            aliens[i][j].position.x = i;
            aliens[i][j].position.y = j;
            aliens[i][j].is_alive = true;
        }
    }
    ship.position.x = WIDTH / 2;
    ship.position.y = HEIGHT - 1;
    ship.is_alive = true;
    bullet.is_alive = false;
    score = 0;
    game_over = false;
}

void draw() {
    memset(screen, ' ', sizeof(screen));
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (aliens[i][j].is_alive) {
                screen[j][i] = 'A';
            }
        }
    }
    if (ship.is_alive) {
        screen[ship.position.y][ship.position.x] = 'S';
    }
    if (bullet.is_alive) {
        screen[bullet.position.y][bullet.position.x] = '|';
    }
    printf("\033[2J\033[1;1H");
    printf("Score: %d\n", score);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(screen[i][j]);
        }
        putchar('\n');
    }
}

bool update() {
    if (game_over) {
        return true;
    }
    // move aliens
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (aliens[i][j].is_alive) {
                aliens[i][j].position.y++;
                if (aliens[i][j].position.y == ship.position.y) {
                    game_over = true;
                    return true;
                }
            }
        }
    }
    // move bullet
    if (bullet.is_alive) {
        bullet.position.y--;
        if (bullet.position.y < 0) {
            bullet.is_alive = false;
        }
    }
    // check collision
    if (bullet.is_alive) {
        if (aliens[bullet.position.x][bullet.position.y].is_alive) {
            aliens[bullet.position.x][bullet.position.y].is_alive = false;
            bullet.is_alive = false;
            score++;
        }
    }
    // check game over
    bool aliens_alive = false;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (aliens[i][j].is_alive) {
                aliens_alive = true;
                break;
            }
        }
        if (aliens_alive) {
            break;
        }
    }
    if (!aliens_alive) {
        game_over = true;
        return true;
    }
    return false;
}

void fire() {
    if (bullet.is_alive || !ship.is_alive) {
        return;
    }
    bullet.is_alive = true;
    bullet.position.x = ship.position.x;
    bullet.position.y = ship.position.y - 1;
}

void move_ship(char ch) {
    if (!ship.is_alive) {
        return;
    }
    switch (ch) {
        case 'h':
            if (ship.position.x > 0) {
                ship.position.x--;
            }
            break;
        case 'j':
            fire();
            break;
        case 'k':
            if (ship.position.x < WIDTH - 1) {
                ship.position.x++;
            }
            break;
    }
}

int main() {
    init();
    while (true) {
        draw();
        if (update()) {
            break;
        }
        char ch = getchar();
        if (tolower(ch) == 'q') {
            break;
        }
        move_ship(ch);
    }
    printf("Game over. Your score is %d.\n", score);
    return 0;
}