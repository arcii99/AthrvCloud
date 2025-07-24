//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 50
#define NUM_ROOMS 10
#define MAX_ROOM_SIZE 10
#define MIN_ROOM_SIZE 5

typedef struct Room {
    int x;
    int y;
    int width;
    int height;
} Room;

void generateMap(char map[][MAP_SIZE]);
void printMap(char map[][MAP_SIZE]);
void placeRooms(char map[][MAP_SIZE], Room rooms[]);
void fillRoom(char map[][MAP_SIZE], Room room);
void connectRooms(char map[][MAP_SIZE], Room rooms[]);
void carveTunnel(char map[][MAP_SIZE], int startX, int startY, int endX, int endY);
int getRand(int min, int max);

int main() {
    char map[MAP_SIZE][MAP_SIZE];
    generateMap(map);
    printMap(map);
    return 0;
}

void generateMap(char map[][MAP_SIZE]) {
    srand(time(NULL));
    //initialize the map with wall tiles
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '#';
        }
    }
    Room rooms[NUM_ROOMS];
    //place rooms randomly on the map
    placeRooms(map, rooms);
    //fill rooms with floor tiles
    for(int i = 0; i < NUM_ROOMS; i++) {
        fillRoom(map, rooms[i]);
    }
    //connect rooms with tunnels
    connectRooms(map, rooms);
    //place player at a random position in one of the rooms
    int playerX, playerY;
    do {
        int roomNum = getRand(0, NUM_ROOMS - 1);
        playerX = getRand(rooms[roomNum].x + 1, rooms[roomNum].x + rooms[roomNum].width - 2);
        playerY = getRand(rooms[roomNum].y + 1, rooms[roomNum].y + rooms[roomNum].height - 2);
    } while(map[playerY][playerX] == '#');
    map[playerY][playerX] = '@';
}

void printMap(char map[][MAP_SIZE]) {
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void placeRooms(char map[][MAP_SIZE], Room rooms[]) {
    for(int i = 0; i < NUM_ROOMS; i++) {
        int roomWidth = getRand(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        int roomHeight = getRand(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        int x = getRand(1, MAP_SIZE - roomWidth - 1);
        int y = getRand(1, MAP_SIZE - roomHeight - 1);
        Room room = {x, y, roomWidth, roomHeight};
        //check if room overlaps with other rooms
        int overlap = 0;
        for(int j = 0; j < i; j++) {
            if(room.x < rooms[j].x + rooms[j].width && room.x + room.width > rooms[j].x && room.y < rooms[j].y + rooms[j].height && room.y + room.height > rooms[j].y) {
                overlap = 1;
                break;
            }
        }
        if(overlap == 0) {
            rooms[i] = room;
            //place room on the map
            for(int j = x; j < x + roomWidth; j++) {
                for(int k = y; k < y + roomHeight; k++) {
                    map[k][j] = '.';
                }
            }
        } else {
            i--;
        }
    }
}

void fillRoom(char map[][MAP_SIZE], Room room) {
    for(int i = room.y + 1; i < room.y + room.height - 1; i++) {
        for(int j = room.x + 1; j < room.x + room.width - 1; j++) {
            map[i][j] = '.';
        }
    }
}

void connectRooms(char map[][MAP_SIZE], Room rooms[]) {
    for(int i = 0; i < NUM_ROOMS - 1; i++) {
        //get random point in first room
        int startX = getRand(rooms[i].x + 1, rooms[i].x + rooms[i].width - 2);
        int startY = getRand(rooms[i].y + 1, rooms[i].y + rooms[i].height - 2);
        //get random point in second room
        int endX = getRand(rooms[i+1].x + 1, rooms[i+1].x + rooms[i+1].width - 2);
        int endY = getRand(rooms[i+1].y + 1, rooms[i+1].y + rooms[i+1].height - 2);
        //carve tunnel between the two points
        carveTunnel(map, startX, startY, endX, endY);
    }
}

void carveTunnel(char map[][MAP_SIZE], int startX, int startY, int endX, int endY) {
    int x = startX;
    int y = startY;
    while(x != endX || y != endY) {
        if(x < endX) {
            x++;
        } else if(x > endX) {
            x--;
        }
        if(y < endY) {
            y++;
        } else if(y > endY) {
            y--;
        }
        map[y][x] = '.';
    }
}

int getRand(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}