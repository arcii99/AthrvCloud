//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define WALL '#'
#define FLOOR ' '
#define PLAYER '@'
#define MONSTER 'M'

char map[HEIGHT][WIDTH];

void generateMap();
void printMap(int px, int py);
int movePlayer(int px, int py);

int main() {
    srand(time(NULL));
    int px, py;
    generateMap();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (map[i][j] == FLOOR) {
                px = j;
                py = i;
                break;
            }
        }
    }
    while (1) {
        printMap(px, py);
        if (!movePlayer(px, py)) {
            break;
        }
    }
    printf("GAME OVER\n");
    return 0;
}

void generateMap() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                map[i][j] = WALL;
            } else if (rand() % 100 < 30) {
                map[i][j] = WALL;
            } else {
                map[i][j] = FLOOR;
            }
        }
    }
    int mx, my;
    while (1) {
        mx = rand() % WIDTH;
        my = rand() % HEIGHT;
        if (map[my][mx] == FLOOR) {
            map[my][mx] = MONSTER;
            break;
        }
    }
}

void printMap(int px, int py) {
    system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == px && i == py) {
                printf("%c", PLAYER);
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

int movePlayer(int px, int py) {
    int nx = px, ny = py;
    char c = getchar();
    switch(c) {
        case 'w':
            ny--;
            break;
        case 'a':
            nx--;
            break;
        case 's':
            ny++;
            break;
        case 'd':
            nx++;
            break;
        default:
            return 1;
    }
    if (nx < 0 || nx >= WIDTH || ny < 0 || ny >= HEIGHT) {
        return 1;
    }
    if (map[ny][nx] == WALL) {
        return 1;
    }
    if (map[ny][nx] == MONSTER) {
        printf("YOU LOSE\n");
        return 0;
    }
    map[py][px] = FLOOR;
    map[ny][nx] = PLAYER;
    return 1;
}