//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 30

typedef struct {
    int x;
    int y;
} Position_t;

typedef struct {
    char symbol;
    int walkable;
} Tile_t;

Tile_t map[MAP_WIDTH][MAP_HEIGHT];

void generateMap() {
    // Fill map with walls
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            map[x][y].symbol = '#';
            map[x][y].walkable = 0;
        }
    }

    // Generate room
    int roomWidth = rand() % 10 + 5;
    int roomHeight = rand() % 6 + 4;
    int roomX = rand() % (MAP_WIDTH - roomWidth - 1) + 1;
    int roomY = rand() % (MAP_HEIGHT - roomHeight - 1) + 1;

    for (int x = roomX; x < roomX + roomWidth; x++) {
        for (int y = roomY; y < roomY + roomHeight; y++) {
            map[x][y].symbol = '.';
            map[x][y].walkable = 1;
        }
    }
}

void printMap(Position_t currentPosition) {
    system("clear");

    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (x == currentPosition.x && y == currentPosition.y) {
                printf("@");
            } else {
                printf("%c", map[x][y].symbol);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Position_t playerPosition = {0, 0};

    generateMap();

    while (1) {
        printMap(playerPosition);

        // Player input handling
        char input;
        do {
            input = getchar();
        } while (input != 'w' && input != 's' && input != 'a' && input != 'd');

        // Move player
        Position_t newPosition;
        newPosition.x = playerPosition.x;
        newPosition.y = playerPosition.y;

        if (input == 'w') {
            newPosition.y--;
        } else if (input == 's') {
            newPosition.y++;
        } else if (input == 'a') {
            newPosition.x--;
        } else if (input == 'd') {
            newPosition.x++;
        }

        if (newPosition.x >= 0 && newPosition.x < MAP_WIDTH && newPosition.y >= 0 && newPosition.y < MAP_HEIGHT && map[newPosition.x][newPosition.y].walkable) {
            playerPosition = newPosition;
        }
    }
    
    return 0;
}