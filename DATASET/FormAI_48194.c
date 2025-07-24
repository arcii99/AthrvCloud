//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_HEIGHT 20
#define MAP_WIDTH 50
#define MAX_ROOMS 10
#define ROOM_MIN_SIZE 4
#define ROOM_MAX_SIZE 8
#define PLAYER '@'
#define WALL '#'
#define FLOOR '.'
#define UP '<'
#define DOWN '>'

// Game map
char gameMap[MAP_HEIGHT][MAP_WIDTH];

// Player position
int playerX, playerY;

// Room structure
typedef struct {
    int x, y;
    int width, height;
} Room;

// Rooms array
Room rooms[MAX_ROOMS];

// Helper function to check if two rooms intersect
int roomsOverlap(Room a, Room b) {
    return (a.x < b.x + b.width &&
            a.x + a.width > b.x &&
            a.y < b.y + b.height &&
            a.y + a.height > b.y);
}

// Helper function to create a room
void createRoom(int idx) {
    int x = rand() % (MAP_WIDTH - ROOM_MAX_SIZE);
    int y = rand() % (MAP_HEIGHT - ROOM_MAX_SIZE);
    int width = ROOM_MIN_SIZE + rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE);
    int height = ROOM_MIN_SIZE + rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE);
    
    rooms[idx] = (Room) { x, y, width, height };
    
    // Draw room walls and floor
    for (int i = y + 1; i < y + height - 1; i++) {
        for (int j = x + 1; j < x + width - 1; j++) {
            gameMap[i][j] = FLOOR;
        }
    }
    for (int i = y; i < y + height; i++) {
        gameMap[i][x] = WALL;
        gameMap[i][x + width - 1] = WALL;
    }
    for (int i = x; i < x + width; i++) {
        gameMap[y][i] = WALL;
        gameMap[y + height - 1][i] = WALL;
    }
}

// Helper function to generate the game map
void generateMap() {
    // Generate rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        createRoom(i);
    }
    
    // Connect rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        int j = (i + 1) % MAX_ROOMS;
        int x1 = rooms[i].x + rooms[i].width / 2;
        int y1 = rooms[i].y + rooms[i].height / 2;
        int x2 = rooms[j].x + rooms[j].width / 2;
        int y2 = rooms[j].y + rooms[j].height / 2;

        while (x1 != x2) {
            if (x1 < x2) {
                x1++;
            } else {
                x1--;
            }
            gameMap[y1][x1] = FLOOR;
        }
        while (y1 != y2) {
            if (y1 < y2) {
                y1++;
            } else {
                y1--;
            }
            gameMap[y1][x1] = FLOOR;
        }
    }
    
    // Place player
    playerX = rooms[0].x + rooms[0].width / 2;
    playerY = rooms[0].y + rooms[0].height / 2;
    gameMap[playerY][playerX] = PLAYER;
    
    // Place stairs
    int stairsX, stairsY;
    do {
        int room = rand() % MAX_ROOMS;
        stairsX = rooms[room].x + rand() % rooms[room].width;
        stairsY = rooms[room].y + rand() % rooms[room].height;
    } while (stairsX == playerX && stairsY == playerY);
    gameMap[stairsY][stairsX] = DOWN;
}

// Helper function to print the game map
void printMap() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", gameMap[i][j]);
        }
        printf("\n");
    }
}

// Helper function to handle player movement
void movePlayer(int dx, int dy) {
    int x = playerX + dx;
    int y = playerY + dy;
    
    if (gameMap[y][x] == WALL) {
        return;
    }
    
    if (gameMap[y][x] == FLOOR) {
        gameMap[playerY][playerX] = FLOOR;
        gameMap[y][x] = PLAYER;
        playerX = x;
        playerY = y;
    }
    
    if (gameMap[y][x] == UP) {
        printf("You climb the stairs up.\n");
    }
    
    if (gameMap[y][x] == DOWN) {
        printf("You climb the stairs down.\n");
    }
}

int main() {
    srand(time(NULL));
    
    generateMap();
    printMap();
    
    // Game loop
    while (1) {
        char input = getchar();
        getchar(); // Discard newline character
        
        switch (input) {
            case 'w': movePlayer(0, -1); break;
            case 'a': movePlayer(-1, 0); break;
            case 's': movePlayer(0, 1); break;
            case 'd': movePlayer(1, 0); break;
            default: break;
        }
        
        printMap();
    }
    
    return 0;
}