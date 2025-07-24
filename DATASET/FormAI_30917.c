//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 10

char map[ROWS][COLS];
int maxRooms = 5;
int roomCount = 0;

typedef struct Room {
    int x;
    int y;
    int width;
    int height;
} Room;

void printMap() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void addRoom(Room r) {
    roomCount++;
    for(int i = r.y; i < r.y + r.height; i++) {
        for(int j = r.x; j < r.x + r.width; j++) {
            map[i][j] = '.';
        }
    }
    if(roomCount == maxRooms) {
        printMap();
    }
}

void generateRoom(Room *r) {
    r->x = rand() % (COLS - 4) + 1;
    r->y = rand() % (ROWS - 4) + 1;
    r->width = rand() % 3 + 3;
    r->height = rand() % 3 + 3;
}

int intersects(Room r1, Room r2) {
    return !(r1.x + r1.width < r2.x || r1.x > r2.x + r2.width || r1.y + r1.height < r2.y || r1.y > r2.y + r2.height);
}

void generateMap() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            map[i][j] = '#';
        }
    }
    while(roomCount < maxRooms) {
        Room r;
        generateRoom(&r);
        int intersect = 0;
        for(int i = 0; i < roomCount; i++) {
            if(intersects(r, *(Room *)&map[i])) {
                intersect = 1;
                break;
            }
        }
        if(!intersect) {
            addRoom(r);
        }
    }
}

int main() {
    srand(time(NULL));
    generateMap();
    return 0;
}