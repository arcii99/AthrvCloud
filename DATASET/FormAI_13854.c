//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// CONSTANTS
#define MAP_SIZE 75
#define MAX_ENTITIES 1000

// TYPES
enum TileType {WALL, FLOOR};
enum EntityType {PLAYER, ENEMY};

struct Tile {
    enum TileType type;
    char symbol;
} map[MAP_SIZE][MAP_SIZE];

struct Entity {
    int x, y;
    enum EntityType type;
    char symbol;
} entities[MAX_ENTITIES];

// FUNCTIONS
void clearMap() {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j].type = WALL;
            map[i][j].symbol = '#';
        }
    }
}

void createRoom(int x, int y, int width, int height) {
    for (int i = x; i < x+width; i++) {
        for (int j = y; j < y+height; j++) {
            if (i == x || i == x+width-1 || j == y || j == y+height-1) {
                map[i][j].type = WALL;
                map[i][j].symbol = '#';
            } else {
                map[i][j].type = FLOOR;
                map[i][j].symbol = '.';
            }
        }
    }
}

void createCorridor(int x1, int y1, int x2, int y2) {
    while (x1 != x2) {
        map[x1][y1].type = FLOOR;
        map[x1][y1].symbol = '.';
        if (x1 < x2) {
            x1++;
        } else {
            x1--;
        }
    }
    while (y1 != y2) {
        map[x1][y1].type = FLOOR;
        map[x1][y1].symbol = '.';
        if (y1 < y2) {
            y1++;
        } else {
            y1--;
        }
    }
}

void createMap() {
    clearMap();
    srand(time(NULL));
    int n_rooms = rand() % 10 + 10;
    int rooms_x[n_rooms], rooms_y[n_rooms], rooms_width[n_rooms], rooms_height[n_rooms];
    for (int i = 0; i < n_rooms; i++) {
        rooms_x[i] = rand() % (MAP_SIZE-10) + 5;
        rooms_y[i] = rand() % (MAP_SIZE-10) + 5;
        rooms_width[i] = rand() % 10 + 5;
        rooms_height[i] = rand() % 10 + 5;
        createRoom(rooms_x[i], rooms_y[i], rooms_width[i], rooms_height[i]);
    }
    for (int i = 0; i < n_rooms-1; i++) {
        int x1 = rooms_x[i] + rooms_width[i]/2;
        int y1 = rooms_y[i] + rooms_height[i]/2;
        int x2 = rooms_x[i+1] + rooms_width[i+1]/2;
        int y2 = rooms_y[i+1] + rooms_height[i+1]/2;
        createCorridor(x1, y1, x2, y2);
    }
}

void drawMap() {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c", map[i][j].symbol);
        }
        printf("\n");
    }
}

void addEntity(enum EntityType type, char symbol) {
    static int n_entities = 0;
    int x, y;
    do {
        x = rand() % MAP_SIZE;
        y = rand() % MAP_SIZE;
    } while (map[x][y].type != FLOOR);
    entities[n_entities].x = x;
    entities[n_entities].y = y;
    entities[n_entities].type = type;
    entities[n_entities].symbol = symbol;
    n_entities++;
}

void drawEntities() {
    for (int i = 0; i < MAX_ENTITIES; i++) {
        if (entities[i].type != 0) {
            printf("%c - x: %d, y: %d\n", entities[i].symbol, entities[i].x, entities[i].y);
        }
    }
}

// MAIN
int main() {
    createMap();
    addEntity(PLAYER, '@');
    for (int i = 0; i < 10; i++) {
        addEntity(ENEMY, 'e');
    }
    drawMap();
    drawEntities();
    return 0;
}