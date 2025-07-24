//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define MAX_OBJECTS 10

typedef enum {
    WALL,
    FLOOR,
    PLAYER,
    OBJECT
} TileType;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int id;
} Object;

// Function prototypes
void initializeMap(TileType map[WIDTH][HEIGHT]);
void printMap(TileType map[WIDTH][HEIGHT]);
void addObjects(TileType map[WIDTH][HEIGHT], Object objects[MAX_OBJECTS], int numObjects);

int main() {
    srand(time(NULL)); // Initialize random number generator with current time
    TileType map[WIDTH][HEIGHT];
    Object objects[MAX_OBJECTS];
    int numObjects = rand() % MAX_OBJECTS; // Random number of objects between 0 and MAX_OBJECTS
    initializeMap(map);
    addObjects(map, objects, numObjects);
    printf("Welcome to my Rogue-Like game!\n");
    printMap(map);
    return 0;
}

// Initialize the map with walls and floors
void initializeMap(TileType map[WIDTH][HEIGHT]) {
    int i, j;
    // Fill borders with walls
    for (i = 0; i < WIDTH; i++) {
        map[i][0] = WALL;
        map[i][HEIGHT-1] = WALL;
    }
    for (j = 0; j < HEIGHT; j++) {
        map[0][j] = WALL;
        map[WIDTH-1][j] = WALL;
    }
    // Fill the rest of the map with floors
    for (i = 1; i < WIDTH-1; i++) {
        for (j = 1; j < HEIGHT-1; j++) {
            map[i][j] = FLOOR;
        }
    }
}

// Print the map with ASCII characters
void printMap(TileType map[WIDTH][HEIGHT]) {
    int i, j;
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            char c;
            switch(map[i][j]) {
                case WALL:
                    c = '#';
                    break;
                case FLOOR:
                    c = '.';
                    break;
                case PLAYER:
                    c = '@';
                    break;
                case OBJECT:
                    c = '!';
                    break;
            }
            printf("%c", c);
        }
        printf("\n");
    }
}

// Add objects randomly to the map
void addObjects(TileType map[WIDTH][HEIGHT], Object objects[MAX_OBJECTS], int numObjects) {
    int i;
    for (i = 0; i < numObjects; i++) {
        int x = rand() % (WIDTH-2) + 1; // Random x coordinate between 1 and WIDTH-2
        int y = rand() % (HEIGHT-2) + 1; // Random y coordinate between 1 and HEIGHT-2
        while (map[x][y] != FLOOR) { // Find a valid floor tile to place object
            x = rand() % (WIDTH-2) + 1;
            y = rand() % (HEIGHT-2) + 1;
        }
        objects[i].pos.x = x;
        objects[i].pos.y = y;
        objects[i].id = i;
        map[x][y] = OBJECT;
    }
}