//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

// Represents a position on the map
struct Position {
    int x;
    int y;
};

// Initializes the map with random walls and paths
void initializeMap(int map[MAP_HEIGHT][MAP_WIDTH]) {
    srand(time(NULL));
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (rand() % 5 == 0) {
                map[i][j] = 1; // 1 represents a wall
            } else {
                map[i][j] = 0; // 0 represents a path
            }
        }
    }
}

// Prints the current state of the map
void printMap(int map[MAP_HEIGHT][MAP_WIDTH], struct Position playerPosition) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (i == playerPosition.y && j == playerPosition.x) {
                printf("@"); // @ represents the player
            } else {
                if (map[i][j] == 1) {
                    printf("#"); // # represents a wall
                } else {
                    printf("."); // . represents a path
                }
            }
        }
        printf("\n");
    }
}

// Moves the player up
void moveUp(struct Position* playerPosition) {
    if (playerPosition->y > 0) {
        playerPosition->y--;
    }
}

// Moves the player down
void moveDown(struct Position* playerPosition) {
    if (playerPosition->y < MAP_HEIGHT - 1) {
        playerPosition->y++;
    }
}

// Moves the player left
void moveLeft(struct Position* playerPosition) {
    if (playerPosition->x > 0) {
        playerPosition->x--;
    }
}

// Moves the player right
void moveRight(struct Position* playerPosition) {
    if (playerPosition->x < MAP_WIDTH - 1) {
        playerPosition->x++;
    }
}

int main() {
    int map[MAP_HEIGHT][MAP_WIDTH];
    initializeMap(map);

    // Start the player in the middle of the map
    struct Position playerPosition = {MAP_WIDTH / 2, MAP_HEIGHT / 2};

    while (1) {
        system("clear"); // Clears the console (for Unix based systems, can be changed for Windows)

        printMap(map, playerPosition);

        char input = getchar(); // Reads keyboard input

        switch (input) {
            case 'w':
                moveUp(&playerPosition);
                break;
            case 's':
                moveDown(&playerPosition);
                break;
            case 'a':
                moveLeft(&playerPosition);
                break;
            case 'd':
                moveRight(&playerPosition);
                break;
            default:
                break;
        }
    }

    return 0;
}