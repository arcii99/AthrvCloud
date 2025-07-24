//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define MAX_ROOMS 10
#define MIN_ROOM_SIZE 4
#define MAX_ROOM_SIZE 10
#define MAX_MONSTERS 5
#define PLAYER '@'

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

void generateMap(char map[][COLS]);
void placeRooms(char map[][COLS], Room *rooms, int *roomCount);
void connectRooms(char map[][COLS], Room *rooms, int roomCount);
void placeMonsters(char map[][COLS], Point *monsters, int *monsterCount);
void printMap(char map[][COLS]);

int main() {
    char map[ROWS][COLS];
    Room rooms[MAX_ROOMS];
    Point monsters[MAX_MONSTERS];

    int roomCount = 0;
    int monsterCount = 0;

    srand(time(NULL));  // Seed the random number generator

    generateMap(map);
    placeRooms(map, rooms, &roomCount);
    connectRooms(map, rooms, roomCount);
    placeMonsters(map, monsters, &monsterCount);
    printMap(map);

    return 0;
}

void generateMap(char map[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            map[i][j] = '#';
        }
    }
}

void placeRooms(char map[][COLS], Room *rooms, int *roomCount) {
    int attempts = 0;

    while (*roomCount < MAX_ROOMS && attempts < 10000) {
        Room room;

        room.width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        room.height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        room.x = rand() % (COLS - room.width - 1) + 1;
        room.y = rand() % (ROWS - room.height - 1) + 1;

        int intersects = 0;

        for (int i = 0; i < *roomCount; i++) {
            Room r = rooms[i];

            if (room.x < r.x + r.width + 1 && room.x + room.width + 1 > r.x &&
                room.y < r.y + r.height + 1 && room.y + room.height + 1 > r.y) {
                intersects = 1;
                break;
            }
        }

        if (!intersects) {
            for (int i = room.y; i < room.y + room.height; i++) {
                for (int j = room.x; j < room.x + room.width; j++) {
                    map[i][j] = ' ';
                }
            }

            rooms[*roomCount] = room;
            (*roomCount)++;
        }

        attempts++;
    }
}

void connectRooms(char map[][COLS], Room *rooms, int roomCount) {
    for (int i = 0; i < roomCount - 1; i++) {
        Point a = { rooms[i].x + rooms[i].width / 2, rooms[i].y + rooms[i].height / 2 };
        Point b = { rooms[i + 1].x + rooms[i + 1].width / 2, rooms[i + 1].y + rooms[i + 1].height / 2 };

        while (a.x != b.x || a.y != b.y) {
            if (a.x < b.x) {
                a.x++;
            } else if (a.x > b.x) {
                a.x--;
            }

            if (a.y < b.y) {
                a.y++;
            } else if (a.y > b.y) {
                a.y--;
            }

            map[a.y][a.x] = ' ';
        }
    }
}

void placeMonsters(char map[][COLS], Point *monsters, int *monsterCount) {
    int maxMonsters = rand() % (MAX_MONSTERS - 2 + 1) + 2;

    for (int i = 0; i < maxMonsters; i++) {
        Point monster;

        do {
            monster.x = rand() % (COLS - 2) + 1;
            monster.y = rand() % (ROWS - 2) + 1;
        } while (map[monster.y][monster.x] != ' ');

        monsters[*monsterCount] = monster;
        (*monsterCount)++;
    }
}

void printMap(char map[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            putchar(map[i][j]);
        }

        putchar('\n');
    }
}