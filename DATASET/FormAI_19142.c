//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 100
#define MAX_ROOMS 20

int map[MAP_SIZE][MAP_SIZE];

struct Room {
    int x, y;
    int width, height;
};

void initializeMap() {
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = 0;
        }
    }
}

int isRoomOverlap(struct Room r1, struct Room r2) {
    return !(r1.x + r1.width < r2.x || r2.x + r2.width < r1.x || r1.y + r1.height < r2.y || r2.y + r2.height < r1.y);
}

int validateRoom(struct Room r) {
    if(r.x < 1 || r.y < 1 || r.x + r.width > MAP_SIZE-1 || r.y + r.height > MAP_SIZE-1) {
        return 0;
    }
    for(int i = r.x-1; i < r.x+r.width+1; i++) {
        for(int j = r.y-1; j < r.y+r.height+1; j++) {
            if(map[i][j] == 1) {
                return 0;
            }
        }
    }
    return 1;
}

void drawRoom(struct Room r) {
    for(int i = r.x; i < r.x+r.width; i++) {
        for(int j = r.y; j < r.y+r.height; j++) {
            if(i == r.x || i == r.x+r.width-1 || j == r.y || j == r.y+r.height-1) {
                map[i][j] = 2; // wall
            } else {
                map[i][j] = 1; // floor
            }
        }
    }
}

void generateRooms(int numRooms) {
    struct Room rooms[MAX_ROOMS];
    int numCreatedRooms = 0;
     
    while(numCreatedRooms < numRooms) {
        // create a new room
        struct Room newRoom;
        newRoom.width = rand() % 10 + 5;
        newRoom.height = rand() % 10 + 5;
        newRoom.x = rand() % (MAP_SIZE-newRoom.width-1) + 1;
        newRoom.y = rand() % (MAP_SIZE-newRoom.height-1) + 1;
        
        // validate new room
        int overlapping = 0;
        for(int i = 0; i < numCreatedRooms; i++) {
            if(isRoomOverlap(newRoom, rooms[i])) {
                overlapping = 1;
                break;
            }
        }
        if(!overlapping && validateRoom(newRoom)) {
            rooms[numCreatedRooms] = newRoom;
            drawRoom(newRoom);
            numCreatedRooms++;
        }
    }
}

void printMap() {
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            switch(map[i][j]) {
                case 0: printf("#"); break;
                case 1: printf("."); break;
                case 2: printf("#"); break;
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initializeMap();
    generateRooms(10);
    printMap();
    return 0;
}