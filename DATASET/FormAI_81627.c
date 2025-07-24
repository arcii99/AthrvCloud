//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20
#define MAX_ROOMS 5

struct Room {
    int x, y;
    int width, height;
};

void drawGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void addRoom(char grid[GRID_SIZE][GRID_SIZE], struct Room room) {
    for (int i = room.x; i < room.x + room.width; i++) {
        for (int j = room.y; j < room.y + room.height; j++) {
            grid[i][j] = '.';
        }
    }
}

int roomIntersects(struct Room room1, struct Room room2) {
    int room1top = room1.y;
    int room1left = room1.x;
    int room1right = room1.x + room1.width;
    int room1bottom = room1.y + room1.height;

    int room2top = room2.y;
    int room2left = room2.x;
    int room2right = room2.x + room2.width;
    int room2bottom = room2.y + room2.height;

    if (room1left > room2right || 
        room1right < room2left || 
        room1top > room2bottom || 
        room1bottom < room2top) {
        return 0;
    }
    return 1;
}

void connectRooms(char grid[GRID_SIZE][GRID_SIZE], struct Room room1, struct Room room2) {
    int x1 = (room1.x + (room1.width / 2));
    int y1 = (room1.y + (room1.height / 2));
    int x2 = (room2.x + (room2.width / 2));
    int y2 = (room2.y + (room2.height / 2));

    while (x1 != x2 || y1 != y2) {
        if (x1 < x2) {
            x1++;
            grid[x1][y1] = '.';
        } else if (x1 > x2) {
            x1--;
            grid[x1][y1] = '.';
        }
        if (y1 < y2) {
            y1++;
            grid[x1][y1] = '.';
        } else if (y1 > y2) {
            y1--;
            grid[x1][y1] = '.';
        }
    }
}

void generateMap(char grid[GRID_SIZE][GRID_SIZE]) {
    // Fill the grid with walls
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '#';
        }
    }

    srand(time(NULL));

    // Generate some rooms
    struct Room rooms[MAX_ROOMS];
    for (int i = 0; i < MAX_ROOMS; i++) {
        int width = (rand() % 5) + 5;
        int height = (rand() % 5) + 5;
        int x = (rand() % (GRID_SIZE - width - 1)) + 1;
        int y = (rand() % (GRID_SIZE - height - 1)) + 1;
        rooms[i] = (struct Room){x, y, width, height};

        // Check for intersections
        for (int j = 0; j < i; j++) {
            if (roomIntersects(rooms[j], rooms[i])) {
                i--;
                break;
            }
        }
    }

    // Add rooms to the grid
    for (int i = 0; i < MAX_ROOMS; i++) {
        addRoom(grid, rooms[i]);
    }

    // Connect rooms
    for (int i = 1; i < MAX_ROOMS; i++) {
        connectRooms(grid, rooms[i-1], rooms[i]);
    }
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    generateMap(grid);
    drawGrid(grid);

    return 0;
}