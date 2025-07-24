//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20
#define WALLS 80
#define PATH 219
#define WALL 178

// Map structure
struct Map {
    char type[ROWS][COLS];
    int start_x;
    int start_y;
    int end_x;
    int end_y;
};

// Function prototypes
void generateMap(struct Map* map);
void printMap(struct Map* map);
void findPath(struct Map* map, int x, int y, int direction);

int main() {
    struct Map map;
    generateMap(&map);
    printf("Map:\n");
    printMap(&map);
    printf("\n");

    printf("Finding path:\n");
    findPath(&map, map.start_x, map.start_y, 0);
    printf("\n");

    printf("Path:\n");
    printMap(&map);

    return 0;
}

// Function to generate the map
void generateMap(struct Map* map) {
    // Set all cells to walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            map->type[i][j] = WALL;
        }
    }

    // Set random cells to paths
    srand(time(NULL));
    for (int i = 0; i < WALLS; i++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        map->type[row][col] = PATH;
    }

    // Set start and end points
    map->start_x = rand() % ROWS;
    map->start_y = rand() % COLS;
    map->type[map->start_x][map->start_y] = 'S';
    map->end_x = rand() % ROWS;
    map->end_y = rand() % COLS;
    map->type[map->end_x][map->end_y] = 'E';
}

// Function to print the map
void printMap(struct Map* map) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", map->type[i][j]);
        }
        printf("\n");
    }
}

// Function to find the path
void findPath(struct Map* map, int x, int y, int direction) {
    // Exit conditions
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        return;
    }
    if (map->type[x][y] == WALL) {
        return;
    }
    if (map->type[x][y] == 'E') {
        return;
    }
    if (map->type[x][y] == PATH && direction != 0) {
        return;
    }

    // Mark current cell as part of the path
    map->type[x][y] = 'X';

    // Recursive calls
    findPath(map, x, y-1, 1); // Left
    findPath(map, x+1, y, 2); // Down
    findPath(map, x, y+1, 3); // Right
    findPath(map, x-1, y, 4); // Up
}