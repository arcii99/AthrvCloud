//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

typedef struct {
    int x;
    int y;
} Point;

char dungeon[WIDTH][HEIGHT];

void generateDungeon() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (rand() % 100 < 40) {
                dungeon[i][j] = '#';
            } else {
                dungeon[i][j] = '.';
            }
        }
    }
}

void printDungeon() {
    int i, j;
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            printf("%c", dungeon[i][j]);
        }
        printf("\n");
    }
}

Point getRandomEmpty() {
    Point p;
    do {
        p.x = rand() % WIDTH;
        p.y = rand() % HEIGHT;
    } while (dungeon[p.x][p.y] != '.');
    return p;
}

void playerTurn(Point *player) {
    char input;
    printf("Enter direction (w,a,s,d): ");
    scanf(" %c", &input);
    switch (input) {
        case 'w':
            if (player->y > 0 && dungeon[player->x][player->y-1] == '.') {
                player->y--;
            }
            break;
        case 'a':
            if (player->x > 0 && dungeon[player->x-1][player->y] == '.') {
                player->x--;
            }
            break;
        case 's':
            if (player->y < HEIGHT-1 && dungeon[player->x][player->y+1] == '.') {
                player->y++;
            }
            break;
        case 'd':
            if (player->x < WIDTH-1 && dungeon[player->x+1][player->y] == '.') {
                player->x++;
            }
            break;
        default:
            printf("Invalid input!\n");
            break;
    }
}

void update(Point *player) {
    dungeon[player->x][player->y] = '@';
}

int main() {
    Point player;
    generateDungeon();
    player = getRandomEmpty();
    dungeon[player.x][player.y] = '@';
    while (1) {
        printDungeon();
        playerTurn(&player);
        update(&player);
    }
    return 0;
}