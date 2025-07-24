//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: optimized
//C Rogue-like Game with Procedural Generation example program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define map size and tile values
#define MAP_SIZE_X 50
#define MAP_SIZE_Y 20
#define TILE_WALL 0
#define TILE_FLOOR 1

// Define structs for game objects
typedef struct {
    int x;
    int y;
} Point;
typedef struct {
    Point position;
    int health;
} Player;
typedef struct {
    Point position;
    int type;
} Tile;

// Function to generate random integer values within a range
int randomInt(int min, int max) {
    return (rand() % (max - min)) + min;
}

// Function to initialize map with randomly generated tiles
void initMap(Tile map[MAP_SIZE_Y][MAP_SIZE_X]) {
    int i, j;
    for (i = 0; i < MAP_SIZE_Y; i++) {
        for (j = 0; j < MAP_SIZE_X; j++) {
            if (i == 0 || i == MAP_SIZE_Y - 1 || j == 0 || j == MAP_SIZE_X - 1) {
                // Create border of walls
                map[i][j].type = TILE_WALL;
            } else {
                // Create random floor or wall tile
                if (randomInt(0, 100) < 45) {
                    map[i][j].type = TILE_WALL;
                } else {
                    map[i][j].type = TILE_FLOOR;
                }
            }
            map[i][j].position.x = j;
            map[i][j].position.y = i;
        }
    }
}

// Function to print map to console
void printMap(Tile map[MAP_SIZE_Y][MAP_SIZE_X], Player player) {
    int i, j;
    for (i = 0; i < MAP_SIZE_Y; i++) {
        for (j = 0; j < MAP_SIZE_X; j++) {
            if (i == player.position.y && j == player.position.x) {
                printf("@");
            } else if (map[i][j].type == TILE_WALL) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Function to handle player movement
void movePlayer(Tile map[MAP_SIZE_Y][MAP_SIZE_X], Player *player, int dx, int dy) {
    int newX = player->position.x + dx;
    int newY = player->position.y + dy;
    if (map[newY][newX].type != TILE_WALL) {
        player->position.x = newX;
        player->position.y = newY;
    }
}

// Function to handle game loop
void gameLoop(Tile map[MAP_SIZE_Y][MAP_SIZE_X], Player player) {
    int running = 1;
    char input;
    while (running) {
        printMap(map, player);
        printf("Enter WASD command to move or Q to quit: ");
        scanf(" %c", &input);
        switch (input) {
            case 'w':
                movePlayer(map, &player, 0, -1);
                break;
            case 'a':
                movePlayer(map, &player, -1, 0);
                break;
            case 's':
                movePlayer(map, &player, 0, 1);
                break;
            case 'd':
                movePlayer(map, &player, 1, 0);
                break;
            case 'q':
                running = 0;
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
    }
}

int main() {
    srand(time(NULL));

    // Initialize map and player
    Tile map[MAP_SIZE_Y][MAP_SIZE_X];
    initMap(map);
    Player player = {
        .position = {10, 5},
        .health = 10
    };

    // Start game loop
    gameLoop(map, player);

    return 0;
}