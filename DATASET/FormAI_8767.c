//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define MAX_MONSTERS 10

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    char map[MAP_SIZE][MAP_SIZE];
    Point playerPos;
    Point exitPos;
    Point monsterPos[MAX_MONSTERS];
    int numMonsters;
} Game;

void init(Game* game) {
    int i, j;

    game->numMonsters = 0;

    // Generate map with walls
    for(i = 0; i < MAP_SIZE; i++) {
        for(j = 0; j < MAP_SIZE; j++) {
            if(i == 0 || i == MAP_SIZE - 1 || j == 0 || j == MAP_SIZE - 1) {
                game->map[i][j] = '#';
            } else {
                game->map[i][j] = '.';
            }
        }
    }

    // Place player randomly
    srand(time(NULL));
    game->playerPos.x = rand() % (MAP_SIZE - 2) + 1;
    game->playerPos.y = rand() % (MAP_SIZE - 2) + 1;
    game->map[game->playerPos.y][game->playerPos.x] = '@';

    // Place exit randomly
    do {
        game->exitPos.x = rand() % (MAP_SIZE - 2) + 1;
        game->exitPos.y = rand() % (MAP_SIZE - 2) + 1;
    } while(game->exitPos.x == game->playerPos.x &&
            game->exitPos.y == game->playerPos.y);
    game->map[game->exitPos.y][game->exitPos.x] = 'E';

    // Place monsters randomly
    game->numMonsters = rand() % (MAX_MONSTERS + 1);
    for(i = 0; i < game->numMonsters; i++) {
        do {
            game->monsterPos[i].x = rand() % (MAP_SIZE - 2) + 1;
            game->monsterPos[i].y = rand() % (MAP_SIZE - 2) + 1;
        } while(game->monsterPos[i].x == game->playerPos.x &&
                game->monsterPos[i].y == game->playerPos.y &&
                game->monsterPos[i].x == game->exitPos.x &&
                game->monsterPos[i].y == game->exitPos.y);
        game->map[game->monsterPos[i].y][game->monsterPos[i].x] = 'M';
    }
}

void draw(Game game) {
    int i, j;

    for(i = 0; i < MAP_SIZE; i++) {
        for(j = 0; j < MAP_SIZE; j++) {
            printf("%c", game.map[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(Game* game, int dx, int dy) {
    int newX = game->playerPos.x + dx;
    int newY = game->playerPos.y + dy;

    if(game->map[newY][newX] == '#') {
        return;
    }

    if(game->map[newY][newX] == 'E') {
        printf("You win!\n");
        exit(0);
    }

    int i;
    for(i = 0; i < game->numMonsters; i++) {
        if(game->monsterPos[i].x == newX && game->monsterPos[i].y == newY) {
            printf("You lose!\n");
            exit(0);
        }
    }

    game->map[game->playerPos.y][game->playerPos.x] = '.';
    game->map[newY][newX] = '@';
    game->playerPos.x = newX;
    game->playerPos.y = newY;
}

int main() {
    Game game;
    init(&game);
    draw(game);

    char c;
    while((c = getchar()) != 'q') {
        switch(c) {
            case 'a': movePlayer(&game, -1, 0); break;
            case 'd': movePlayer(&game, 1, 0); break;
            case 'w': movePlayer(&game, 0, -1); break;
            case 's': movePlayer(&game, 0, 1); break;
        }

        draw(game);
    }

    return 0;
}