//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20
#define MAX_ROOMS 6

typedef struct Room {
    int x, y;
    int width, height;
} Room;

void initMap(char map[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // set all cells to wall
            map[i][j] = '#';
        }
    }
}

void placeRoom(Room *room, char map[ROWS][COLS]) {
    for (int i = room->x; i < room->x + room->width; i++) {
        for (int j = room->y; j < room->y + room->height; j++) {
            // set cells within room to floor
            map[i][j] = '.';
        }
    }
}

void initRooms(Room *rooms) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].width = rand() % 6 + 4;
        rooms[i].height = rand() % 6 + 4;
        rooms[i].x = rand() % (ROWS - rooms[i].width - 1);
        rooms[i].y = rand() % (COLS - rooms[i].height - 1);
    }
}

void connectRooms(Room *r1, Room *r2, char map[ROWS][COLS]) {
    int x1 = rand() % r1->width + r1->x;
    int y1 = rand() % r1->height + r1->y;
    int x2 = rand() % r2->width + r2->x;
    int y2 = rand() % r2->height + r2->y;
    while (x1 != x2) {
        if (x1 < x2) {
            x1++;
        } else {
            x1--;
        }
        // create horizontal corridor between rooms
        map[x1][y1] = '.';
    }
    while (y1 != y2) {
        if (y1 < y2) {
            y1++;
        } else {
            y1--;
        }
        // create vertical corridor between rooms
        map[x1][y1] = '.';
    }
}

void generateMap(char map[ROWS][COLS], Room *rooms) {
    // initialize map with all walls
    initMap(map);
    
    // randomly generate rooms
    initRooms(rooms);
    for (int i = 0; i < MAX_ROOMS; i++) {
        placeRoom(&rooms[i], map);
    }
    
    // connect rooms with corridors
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        connectRooms(&rooms[i], &rooms[i+1], map);
    }
}

void printMap(char map[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char map[ROWS][COLS];
    Room rooms[MAX_ROOMS];
    generateMap(map, rooms);
    printMap(map);
    return 0;
}