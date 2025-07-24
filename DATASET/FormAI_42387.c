//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 80
#define MAP_HEIGHT 24
#define MAX_ROOMS 10
#define ROOM_MIN_SIZE 5
#define ROOM_MAX_SIZE 20

char map[MAP_HEIGHT][MAP_WIDTH];

typedef struct {
    int x, y, width, height;
} Room;

void initMap() {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }
}

void printMap() {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int isOverlap(Room *a, Room *b) {
    return (a->x < b->x + b->width && a->x + a->width > b->x &&
            a->y < b->y + b->height && a->y + a->height > b->y);
}

void createRoom(Room *room) {
    int x, y, width, height;
    width = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
    height = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
    x = rand() % (MAP_WIDTH - width - 1) + 1;
    y = rand() % (MAP_HEIGHT - height - 1) + 1;
    room->x = x;
    room->y = y;
    room->width = width;
    room->height = height;
}

void createRooms(Room *rooms) {
    int i, j, k, overlap;
    for (i = 0; i < MAX_ROOMS; i++) {
        createRoom(&rooms[i]);
        overlap = 0;
        for (j = 0; j < i; j++) {
            if (isOverlap(&rooms[i], &rooms[j])) {
                overlap = 1;
                break;
            }
        }
        if (overlap) {
            i--;
        } else {
            for (j = rooms[i].y; j < rooms[i].y + rooms[i].height; j++) {
                for (k = rooms[i].x; k < rooms[i].x + rooms[i].width; k++) {
                    map[j][k] = '.';
                }
            }
        }
    }
}

void connectRooms(Room *a, Room *b) {
    int x1 = rand() % (a->width - 2) + a->x + 1;
    int y1 = rand() % (a->height - 2) + a->y + 1;
    int x2 = rand() % (b->width - 2) + b->x + 1;
    int y2 = rand() % (b->height - 2) + b->y + 1;
    int dx, dy, x, y, step;
    dx = (x2 - x1) > 0 ? 1 : -1;
    dy = (y2 - y1) > 0 ? 1 : -1;
    x = x1;
    y = y1;
    step = 0;
    while (x != x2 || y != y2) {
        if (step++ > 100) {
            break;
        }
        if (x != x2) {
            x += dx;
            if (map[y][x] != '.') {
                map[y][x] = '#';
            }
        }
        if (y != y2) {
            y += dy;
            if (map[y][x] != '.') {
                map[y][x] = '#';
            }
        }
    }
}

void connectRoomsAll(Room *rooms) {
    int i, j, num_connected;
    Room *connected[MAX_ROOMS];
    for (i = 0; i < MAX_ROOMS; i++) {
        connected[i] = NULL;
    }
    num_connected = 1;
    connected[0] = &rooms[0];
    while (num_connected < MAX_ROOMS) {
        for (i = 1; i < MAX_ROOMS; i++) {
            if (connected[i] != NULL) {
                continue;
            }
            for (j = 0; j < num_connected; j++) {
                if (isOverlap(&rooms[i], connected[j])) {
                    connectRooms(&rooms[i], connected[j]);
                    connected[num_connected++] = &rooms[i];
                    break;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    initMap();
    Room rooms[MAX_ROOMS];
    createRooms(rooms);
    connectRoomsAll(rooms);
    printMap();
    return 0;
}