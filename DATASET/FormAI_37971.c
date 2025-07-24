//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 25

typedef struct {
    int x;
    int y;
} position;

typedef struct {
    position pos;
    char type;
} entity;

typedef struct {
    char tiles[MAP_WIDTH][MAP_HEIGHT];
    entity player;
    entity enemies[10];
    int numEnemies;
} map;

void generateMap(map* m) {
    int i,j;
    for (i=0; i<MAP_WIDTH; i++) {
        for (j=0; j<MAP_HEIGHT; j++) {
            if (rand() % 10 == 0) {
                m->tiles[i][j] = '#';
            } else {
                m->tiles[i][j] = '.';
            }
        }
    }
    m->player.pos.x = MAP_WIDTH / 2;
    m->player.pos.y = MAP_HEIGHT / 2;
    m->player.type = '@';
    m->numEnemies = 0;
}

void printMap(map* m) {
    int i,j;
    for (j=0; j<MAP_HEIGHT; j++) {
        for (i=0; i<MAP_WIDTH; i++) {
            if (i == m->player.pos.x && j == m->player.pos.y) {
                printf("%c", m->player.type);
            } else {
                int k;
                char foundEnemy = 0;
                for (k=0; k<m->numEnemies; k++) {
                    if (m->enemies[k].pos.x == i && m->enemies[k].pos.y == j) {
                        printf("%c", m->enemies[k].type);
                        foundEnemy = 1;
                        break;
                    }
                }
                if (!foundEnemy) {
                    printf("%c", m->tiles[i][j]);
                }
            }
        }
        printf("\n");
    }
}

int main() {
    srand((unsigned)time(NULL));
    map m;
    generateMap(&m);
    printMap(&m);
    return 0;
}