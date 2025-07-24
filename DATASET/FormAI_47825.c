//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define MAX_ROOMS 6
#define MAX_ROOM_SIZE 10
#define MIN_ROOM_SIZE 4

char map[HEIGHT][WIDTH];

struct Room {
    int x, y, w, h;
};

void initializeMap() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            map[i][j] = '#';
        }
    }
}

bool intersect(struct Room a, struct Room b) {
    return (a.x <= b.x + b.w &&
            b.x <= a.x + a.w &&
            a.y <= b.y + b.h &&
            b.y <= a.y + a.h);
}

bool isRoomValid(struct Room room, struct Room *rooms, int roomCount) {
    for(int i = 0; i < roomCount; i++) {
        if(intersect(room, rooms[i])) {
            return false;
        }
    }
    return true;
}

void createRoom(struct Room *room, struct Room *rooms, int roomCount) {
    int x = rand() % (WIDTH - MAX_ROOM_SIZE - 1) + 1;
    int y = rand() % (HEIGHT - MAX_ROOM_SIZE - 1) + 1;
    int w = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
    int h = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
    room->x = x;
    room->y = y;
    room->w = w;
    room->h = h;
    if(isRoomValid(*room, rooms, roomCount)) {
        for(int i = y; i < y + h; i++) {
            for(int j = x; j < x + w; j++) {
                map[i][j] = '.';
            }
        }
    } else {
        room->x = -1;
        room->y = -1;
        room->w = -1;
        room->h = -1;
    }
}

void createRooms(struct Room *rooms, int roomCount) {
    for(int i = 0; i < roomCount; i++) {
        createRoom(&rooms[i], rooms, i);
    }
}

void connectRooms(struct Room *a, struct Room *b) {
    int x1 = a->x + a->w/2;
    int y1 = a->y + a->h/2;
    int x2 = b->x + b->w/2;
    int y2 = b->y + b->h/2;
    int w = x2 - x1;
    int h = y2 - y1;
    if(w < 0) {
        for(int i = x1; i >= x2; i--) {
            map[y1][i] = '.';
        }
    } else {
        for(int i = x1; i <= x2; i++) {
            map[y1][i] = '.';
        }
    }
    if(h < 0) {
        for(int i = y1; i >= y2; i--) {
            map[i][x2] = '.';
        }
    } else {
        for(int i = y1; i <= y2; i++) {
            map[i][x2] = '.';
        }
    }
}

void connectRoomsInSequence(struct Room *rooms, int roomCount) {
    for(int i = 0; i < roomCount - 1; i++) {
        connectRooms(&rooms[i], &rooms[i+1]);
    }
}

void printMap() {
    system("clear");
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initializeMap();
    struct Room rooms[MAX_ROOMS];
    createRooms(rooms, MAX_ROOMS);
    connectRoomsInSequence(rooms, MAX_ROOMS);
    printMap();
    return 0;
}