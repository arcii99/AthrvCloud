//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define MAX_ROOMS 10
#define MIN_ROOM_WIDTH 5
#define MIN_ROOM_HEIGHT 5
#define MAX_ROOM_WIDTH 15
#define MAX_ROOM_HEIGHT 15

typedef struct Room {
    int x, y, width, height;
} Room;

void initializeGrid(char grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = '#';
        }
    }
}

void displayGrid(char grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", grid[y][x]);
        }
        printf("\n");
    }
}

void generateRooms(Room rooms[MAX_ROOMS]) {
    srand(time(NULL));
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].width = rand() % (MAX_ROOM_WIDTH - MIN_ROOM_WIDTH + 1) + MIN_ROOM_WIDTH;
        rooms[i].height = rand() % (MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT + 1) + MIN_ROOM_HEIGHT;
        rooms[i].x = rand() % (WIDTH - rooms[i].width - 1) + 1;
        rooms[i].y = rand() % (HEIGHT - rooms[i].height - 1) + 1;
    }
}

void drawRooms(char grid[HEIGHT][WIDTH], Room rooms[MAX_ROOMS]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        for (int y = rooms[i].y; y < rooms[i].y + rooms[i].height; y++) {
            for (int x = rooms[i].x; x < rooms[i].x + rooms[i].width; x++) {
                grid[y][x] = '.';
            }
        }
    }
}

void drawCorridors(char grid[HEIGHT][WIDTH], Room rooms[MAX_ROOMS]) {
    int x1, x2, y1, y2;
    for (int i = 0; i < MAX_ROOMS-1; i++) {
        x1 = rooms[i].x + (rooms[i].width / 2);
        y1 = rooms[i].y + (rooms[i].height / 2);
        x2 = rooms[i+1].x + (rooms[i+1].width / 2);
        y2 = rooms[i+1].y + (rooms[i+1].height / 2);

        while (x1 != x2) {
            if (x1 < x2) {
                x1++;
            } else {
                x1--;
            }
            grid[y1][x1] = '.';
        }

        while (y1 != y2) {
            if (y1 < y2) {
                y1++;
            } else {
                y1--;
            }
            grid[y1][x1] = '.';
        }
    }
}

int main() {
    char grid[HEIGHT][WIDTH];
    Room rooms[MAX_ROOMS];
    initializeGrid(grid);
    generateRooms(rooms);
    drawRooms(grid, rooms);
    drawCorridors(grid, rooms);
    displayGrid(grid);
    return 0;
}