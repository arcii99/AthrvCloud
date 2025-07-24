//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define MAX_ROOMS 5

typedef struct {
    int x;
    int y;
    int w;
    int h;
} Room;

typedef struct {
    int x;
    int y;
} Player;

typedef enum {
    FLOOR,
    WALL,
} Tile;

Tile grid[GRID_SIZE][GRID_SIZE];
Room rooms[MAX_ROOMS];
Player player;

void initializeGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = WALL;
        }
    }
}

void addRoom(int index, int x, int y, int w, int h) {
    rooms[index].x = x;
    rooms[index].y = y;
    rooms[index].w = w;
    rooms[index].h = h;
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + h; j++) {
            grid[i][j] = FLOOR;
        }
    }
}

void generateRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        int w = rand() % 4 + 3;
        int h = rand() % 4 + 3;
        int x = rand() % (GRID_SIZE - w - 1) + 1;
        int y = rand() % (GRID_SIZE - h - 1) + 1;
        addRoom(i, x, y, w, h);
    }
}

void printGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[j][i] == WALL ? '#' : '.');
        }
        printf("\n");
    }
}

void initializePlayer() {
    player.x = rooms[0].x + rooms[0].w / 2;
    player.y = rooms[0].y + rooms[0].h / 2;
}

void movePlayer(char direction) {
    switch (direction) {
        case 'w': {
            if (player.y > 0 && grid[player.x][player.y - 1] == FLOOR) {
                player.y--;
            }
            break;
        }
        case 's': {
            if (player.y < GRID_SIZE - 1 && grid[player.x][player.y + 1] == FLOOR) {
                player.y++;
            }
            break;
        }
        case 'a': {
            if (player.x > 0 && grid[player.x - 1][player.y] == FLOOR) {
                player.x--;
            }
            break;
        }
        case 'd': {
            if (player.x < GRID_SIZE - 1 && grid[player.x + 1][player.y] == FLOOR) {
                player.x++;
            }
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    initializeGrid();
    generateRooms();
    initializePlayer();
    char input;
    while (1) {
        printGrid();
        printf("Enter direction (w, a, s, d):");
        scanf(" %c", &input);
        movePlayer(input);
        system("clear");
    }
    return 0;
}