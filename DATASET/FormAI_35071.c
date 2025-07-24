//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

/* Tile values */
#define WALL '#'
#define FLOOR '.'
#define PLAYER '@'

struct Point {
    int x;
    int y;
};

bool isOutOfBounds(int x, int y);
bool isInsideRoom(int x, int y);
bool isWall(int x, int y);

char getTileValue(int x, int y);
void setTileValue(int x, int y, char value);

void createRoom(int x, int y, int w, int h);
void createCorridor(struct Point start, struct Point end);

void generateMap();
void displayMap();
void movePlayer(int dx, int dy);
void updatePlayerPosition(char tile);

char map[WIDTH][HEIGHT];
struct Point playerPos;

int main() {
    srand(time(NULL));  // Seed the random number generator
    
    generateMap();
       
    // Initialize player position
    playerPos.x = WIDTH / 2;
    playerPos.y = HEIGHT / 2;
    setTileValue(playerPos.x, playerPos.y, PLAYER);
    
    displayMap();
    
    // Game loop
    while (true) {
        // Get player input
        char input = getchar();
        
        // Move player
        if (input == 'w') {
            movePlayer(0, -1);
        } else if (input == 's') {
            movePlayer(0, 1);
        } else if (input == 'a') {
            movePlayer(-1, 0);
        } else if (input == 'd') {
            movePlayer(1, 0);
        }
    }
    
    return 0;
}

bool isOutOfBounds(int x, int y) {
    return x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT;
}

bool isInsideRoom(int x, int y) {
    if (isOutOfBounds(x, y)) return false;
    return getTileValue(x, y) == FLOOR;
}

bool isWall(int x, int y) {
    if (isOutOfBounds(x, y)) return true;
    return getTileValue(x, y) == WALL;
}

char getTileValue(int x, int y) {
    if (isOutOfBounds(x, y)) {
        return WALL;
    }
    return map[x][y];
}

void setTileValue(int x, int y, char value) {
    if (isOutOfBounds(x, y)) {
        return;
    }
    map[x][y] = value;
}

void createRoom(int x, int y, int w, int h) {
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + h; j++) {
            setTileValue(i, j, FLOOR);
        }
    }
}

void createCorridor(struct Point start, struct Point end) {
    int dx = end.x - start.x;
    int dy = end.y - start.y;
    
    int stepX, stepY;
    
    if (dx < 0) {
        stepX = -1;
        dx = -dx;
    } else {
        stepX = 1;
    }
    
    if (dy < 0) {
        stepY = -1;
        dy = -dy;
    } else {
        stepY = 1;
    }
    
    int x = start.x;
    int y = start.y;
    
    int error = dx - dy;
    
    while (true) {
        setTileValue(x, y, FLOOR);
        
        if (x == end.x && y == end.y) break;
        
        int error2 = error * 2;
        
        if (error2 > -dy) {
            error -= dy;
            x += stepX;
        }
        
        if (error2 < dx) {
            error += dx;
            y += stepY;
        }
    }
}

void generateMap() {
    // Fill map with walls
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            setTileValue(i, j, WALL);
        }
    }
    
    // Create rooms
    int numRooms = 5;
    int minRoomSize = 5;
    int maxRoomSize = 10;
    
    struct Point roomPositions[numRooms];
    
    for (int i = 0; i < numRooms; i++) {
        int w = rand() % (maxRoomSize - minRoomSize + 1) + minRoomSize;
        int h = rand() % (maxRoomSize - minRoomSize + 1) + minRoomSize;
        int x = rand() % (WIDTH - w - 1) + 1;
        int y = rand() % (HEIGHT - h - 1) + 1;
        
        createRoom(x, y, w, h);
        
        roomPositions[i].x = x + w / 2;
        roomPositions[i].y = y + h / 2;
    }
    
    // Connect rooms with corridors
    for (int i = 0; i < numRooms - 1; i++) {
        createCorridor(roomPositions[i], roomPositions[i+1]);
    }
}

void displayMap() {
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            printf("%c", getTileValue(i, j));
        }
        printf("\n");
    }
}

void movePlayer(int dx, int dy) {
    char tile = getTileValue(playerPos.x + dx, playerPos.y + dy);
    if (tile == FLOOR) {
        updatePlayerPosition(tile);
        playerPos.x += dx;
        playerPos.y += dy;
        updatePlayerPosition(PLAYER);
        displayMap();
    }
}

void updatePlayerPosition(char tile) {
    setTileValue(playerPos.x, playerPos.y, tile);
}