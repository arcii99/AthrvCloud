//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 80
#define MAX_ROOMS 10
#define ROOM_MIN_SIZE 4
#define ROOM_MAX_SIZE 10

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

typedef enum {
    EMPTY,
    WALL,
    FLOOR,
    DOOR
} TileType;

typedef struct {
    TileType type;
    char symbol;
    int visible;
} Tile;

Tile map[ROWS][COLS];
Room rooms[MAX_ROOMS];
int numRooms = 0;

void initializeMap();
void drawMap();
void generateRooms();
void placeRoom(Room room);
void connectRooms(Room room1, Room room2);
void drawRoom(Room room);
void drawHorizontalTunnel(int x1, int x2, int y);
void drawVerticalTunnel(int y1, int y2, int x);
void populateMap();
void placePlayer();

int main() {
    srand(time(NULL));
    initializeMap();
    generateRooms();
    populateMap();
    placePlayer();
    drawMap();
    return 0;
}

void initializeMap() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1) {
                map[i][j].type = WALL;
                map[i][j].symbol = '#';
                map[i][j].visible = 1;
            } else {
                map[i][j].type = EMPTY;
                map[i][j].symbol = ' ';
                map[i][j].visible = 0;
            }
        }
    }
}

void drawMap() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            Tile tile = map[i][j];
            if (tile.visible) {
                printf("%c", tile.symbol);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generateRooms() {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        int x = rand() % (COLS - ROOM_MAX_SIZE - 2) + 1;
        int y = rand() % (ROWS - ROOM_MAX_SIZE - 2) + 1;
        int width = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int height = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        Room room = {x, y, width, height};
        placeRoom(room);
        if (i != 0) {
            Room prevRoom = rooms[i - 1];
            connectRooms(room, prevRoom);
        }
        rooms[i] = room;
        numRooms++;
    }
}

void placeRoom(Room room) {
    int i, j;
    for (i = room.y; i < room.y + room.height; i++) {
        for (j = room.x; j < room.x + room.width; j++) {
            if (map[i][j].type == EMPTY) {
                if (i == room.y || i == room.y + room.height - 1 || j == room.x || j == room.x + room.width - 1) {
                    map[i][j].type = WALL;
                    map[i][j].symbol = '#';
                } else {
                    map[i][j].type = FLOOR;
                    map[i][j].symbol = '.';
                }
            }
        }
    }
}

void connectRooms(Room room1, Room room2) {
    int rand1x = rand() % (room1.width - 2) + room1.x + 1;
    int rand1y = rand() % (room1.height - 2) + room1.y + 1;
    int rand2x = rand() % (room2.width - 2) + room2.x + 1;
    int rand2y = rand() % (room2.height - 2) + room2.y + 1;

    if (rand1x < rand2x) {
        drawHorizontalTunnel(rand1x, rand2x, rand1y);
        if (rand1y < rand2y) {
            drawVerticalTunnel(rand1y, rand2y, rand2x);
        } else {
            drawVerticalTunnel(rand2y, rand1y, rand2x);
        }
    } else {
        drawHorizontalTunnel(rand2x, rand1x, rand1y);
        if (rand1y < rand2y) {
            drawVerticalTunnel(rand1y, rand2y, rand1x);
        } else {
            drawVerticalTunnel(rand2y, rand1y, rand1x);
        }
    }
}

void drawHorizontalTunnel(int x1, int x2, int y) {
    int i;
    for (i = x1; i <= x2; i++) {
        if (map[y][i].type == EMPTY) {
            map[y][i].type = FLOOR;
            map[y][i].symbol = '.';
        }
    }
}

void drawVerticalTunnel(int y1, int y2, int x) {
    int i;
    for (i = y1; i <= y2; i++) {
        if (map[i][x].type == EMPTY) {
            map[i][x].type = FLOOR;
            map[i][x].symbol = '.';
        }
    }
}

void populateMap() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (map[i][j].type == FLOOR && rand() % 100 < 20) {
                map[i][j].symbol = ',';
            }
        }
    }
}

void placePlayer() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (map[i][j].type == FLOOR) {
                map[i][j].symbol = '@';
                map[i][j].visible = 1;
                return;
            }
        }
    }
}