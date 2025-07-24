//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 15
#define MAX_ENEMIES 5
#define PACMAN_SYMBOL 'C'
#define GHOST_SYMBOL 'G'
#define WALL_SYMBOL '#'
#define DOT_SYMBOL '.'
#define SPACE_SYMBOL ' '

char map[WIDTH][HEIGHT];
int score = 0;
int lives = 3;

struct Entity {
    int x;
    int y;
};

struct Entity pacman;
struct Entity enemies[MAX_ENEMIES];

void initMap() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (i == 0 || i == WIDTH - 1 || j == 0 || j == HEIGHT - 1) {
                map[i][j] = WALL_SYMBOL;
            } else {
                map[i][j] = SPACE_SYMBOL;
            }
        }
    }
    for (i = 1; i <= MAX_ENEMIES; i++) {
        int x = rand() % (WIDTH - 2) + 1;
        int y = rand() % (HEIGHT - 2) + 1;
        enemies[i - 1].x = x;
        enemies[i - 1].y = y;
        if (map[x][y] == DOT_SYMBOL) {
            i--;
        } else {
            map[x][y] = GHOST_SYMBOL;
        }
    }
    pacman.x = WIDTH / 2;
    pacman.y = HEIGHT / 2;
    map[pacman.x][pacman.y] = PACMAN_SYMBOL;
}

void drawMap() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
    printf("Lives: %d\n", lives);
}

void movePacman(int x, int y) {
    if (map[pacman.x + x][pacman.y + y] != WALL_SYMBOL) {
        map[pacman.x][pacman.y] = SPACE_SYMBOL;
        pacman.x += x;
        pacman.y += y;
        if (map[pacman.x][pacman.y] == DOT_SYMBOL) {
            score++;
        }
        map[pacman.x][pacman.y] = PACMAN_SYMBOL;
    }
}

void moveEnemies() {
    int i;
    for (i = 0; i < MAX_ENEMIES; i++) {
        int x, y;
        do {
            x = rand() % 3 - 1;
            y = rand() % 3 - 1;
        } while (map[enemies[i].x + x][enemies[i].y + y] == WALL_SYMBOL || (x == 0 && y == 0));
        if (map[enemies[i].x + x][enemies[i].y + y] == PACMAN_SYMBOL) {
            lives--;
            if (lives == 0) {
                printf("Game over!\nFinal score: %d\n", score);
                exit(0);
            } else {
                printf("You lost a life!\n");
                initMap();
            }
        } else {
            map[enemies[i].x][enemies[i].y] = SPACE_SYMBOL;
            enemies[i].x += x;
            enemies[i].y += y;
            map[enemies[i].x][enemies[i].y] = GHOST_SYMBOL;
        }
    }
}

int main() {
    srand(time(NULL));
    initMap();
    while (1) {
        system("clear");
        drawMap();
        char input = getchar();
        switch (input) {
            case 'w':
                movePacman(-1, 0);
                break;
            case 's':
                movePacman(1, 0);
                break;
            case 'a':
                movePacman(0, -1);
                break;
            case 'd':
                movePacman(0, 1);
                break;
            default:
                break;
        }
        moveEnemies();
    }
    return 0;
}