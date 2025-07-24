//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: artistic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAP_WIDTH 30
#define MAP_HEIGHT 20
#define MAX_ROOMS 5
#define MAX_ROOM_SIZE 10
#define MIN_ROOM_SIZE 5

#define WALL '#'
#define FLOOR '.'
#define PLAYER '@'

typedef struct {
    int x, y, width, height;
} room;

typedef struct {
    int x, y;
} point;

char map[MAP_HEIGHT][MAP_WIDTH];

void initMap() {
    int i, j;

    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = WALL;
        }
    }
}

void printMap() {
    int i, j;

    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

point getRandomPointInRoom(room r) {
    point p;

    p.x = r.x + rand() % r.width;
    p.y = r.y + rand() % r.height;

    return p;
}

void connectRooms(room a, room b) {
    point start, end;

    start = getRandomPointInRoom(a);
    end = getRandomPointInRoom(b);

    while (start.x != end.x || start.y != end.y) {
        if (start.x < end.x) {
            start.x++;
        } else if (start.x > end.x) {
            start.x--;
        }

        if (start.y < end.y) {
            start.y++;
        } else if (start.y > end.y) {
            start.y--;
        }

        map[start.y][start.x] = FLOOR;
    }
}

room getRandomRoom() {
    room r;

    r.width = MIN_ROOM_SIZE + rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1);
    r.height = MIN_ROOM_SIZE + rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1);
    r.x = rand() % (MAP_WIDTH - r.width - 1) + 1;
    r.y = rand() % (MAP_HEIGHT - r.height - 1) + 1;

    return r;
}

void generateMap() {
    int i, j;
    int roomsCreated = 0;
    room rooms[MAX_ROOMS];

    initMap();

    while (roomsCreated < MAX_ROOMS) {
        room r = getRandomRoom();
        int canCreate = 1;

        for (i = r.y - 1; i < r.y + r.height + 1; i++) {
            for (j = r.x - 1; j < r.x + r.width + 1; j++) {
                if (map[i][j] == FLOOR) {
                    canCreate = 0;
                    break;
                }
            }

            if (!canCreate) {
                break;
            }
        }

        if (canCreate) {
            for (i = r.y; i < r.y + r.height; i++) {
                for (j = r.x; j < r.x + r.width; j++) {
                    map[i][j] = FLOOR;
                }
            }

            rooms[roomsCreated++] = r;
        }
    }

    for (i = 0; i < MAX_ROOMS - 1; i++) {
        connectRooms(rooms[i], rooms[i + 1]);
    }
}

int main() {
    srand(time(NULL));

    generateMap();
    map[1][1] = PLAYER;

    printMap();

    return 0;
}