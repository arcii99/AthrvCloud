//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAP_ROWS 20
#define MAP_COLS 50

char map[MAP_ROWS][MAP_COLS];

typedef struct Room {
    int x;
    int y;
    int width;
    int height;
} Room;

void initializeMap() {
    for(int i = 0; i < MAP_ROWS; i++) {
        for(int j = 0; j < MAP_COLS; j++) {
            map[i][j] = '#';
        }
    }
}

void printMap() {
    for(int i = 0; i < MAP_ROWS; i++) {
        for(int j = 0; j < MAP_COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void createRoom(Room room) {
    for(int i = room.y; i < room.y + room.height; i++) {
        for(int j = room.x; j < room.x + room.width; j++) {
            map[i][j] = ' ';
        }
    }
}

int checkOverlap(Room room, Room* rooms, int numRooms) {
    for(int i = 0; i < numRooms; i++) {
        if(room.x < rooms[i].x + rooms[i].width &&
           room.x + room.width > rooms[i].x &&
           room.y < rooms[i].y + rooms[i].height &&
           room.y + room.height > rooms[i].y) {
               return 1;
           }
    }
    
    return 0;
}

void createCorridor(int x1, int y1, int x2, int y2) {
    int x = x1;
    int y = y1;
    
    while(x != x2) {
        map[y][x] = ' ';
        if(x < x2) {
            x++;
        } else {
            x--;
        }
    }
    
    while(y != y2) {
        map[y][x] = ' ';
        if(y < y2) {
            y++;
        } else {
            y--;
        }
    }
}

void connectRooms(Room room1, Room room2) {
    int x1 = room1.x + (room1.width / 2);
    int y1 = room1.y + (room1.height / 2);
    int x2 = room2.x + (room2.width / 2);
    int y2 = room2.y + (room2.height / 2);
    
    createCorridor(x1, y1, x2, y2);
}

void generateMap() {
    initializeMap();
    
    int numRooms = 0;
    Room rooms[MAX_ROOMS];
    
    srand(time(NULL));
    
    for(int i = 0; i < MAX_ROOMS; i++) {
        int width = rand() % 10 + 5;
        int height = rand() % 10 + 5;
        int x = rand() % (MAP_COLS - width - 1) + 1;
        int y = rand() % (MAP_ROWS - height - 1) + 1;
        
        Room room = {x, y, width, height};
        
        if(!checkOverlap(room, rooms, numRooms)) {
            createRoom(room);
            rooms[numRooms] = room;
            numRooms++;
        }
    }
    
    for(int i = 0; i < numRooms - 1; i++) {
        connectRooms(rooms[i], rooms[i + 1]);
    }
    
    printMap();
}

int main() {
    generateMap();
    return 0;
}