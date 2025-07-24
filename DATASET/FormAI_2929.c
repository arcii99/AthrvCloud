//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 25
#define MAX_ROOMS 8
#define MIN_ROOM_SIZE 4
#define MAX_ROOM_SIZE 10

typedef struct {
    int x, y, width, height;
} Room;

typedef struct Tile {
    char symbol;
    int x, y;
    struct Tile* next;
} Tile;

typedef struct {
    Tile* start;
    Tile* end;
} LinkedList;

void initList(LinkedList* list) {
    list->start = NULL;
    list->end = NULL;
}

void addToList(LinkedList* list, char symbol, int x, int y) {
    Tile* newTile = (Tile*) malloc(sizeof(Tile));
    newTile->symbol = symbol;
    newTile->x = x;
    newTile->y = y;
    newTile->next = NULL;

    if (list->start == NULL) {
        list->start = newTile;
        list->end = newTile;
    }
    else {
        list->end->next = newTile;
        list->end = newTile;
    }
}

void printMap(char map[MAP_HEIGHT][MAP_WIDTH]) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void fillMap(char map[MAP_HEIGHT][MAP_WIDTH], char symbol) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = symbol;
        }
    }
}

void createRoom(char map[MAP_HEIGHT][MAP_WIDTH], Room room) {
    for (int i = room.y; i < room.y + room.height; i++) {
        for (int j = room.x; j < room.x + room.width; j++) {
            if (i == room.y || i == room.y + room.height - 1) {
                map[i][j] = '-';
            }
            else if (j == room.x || j == room.x + room.width - 1) {
                map[i][j] = '|';
            }
            else {
                map[i][j] = '.';
            }
        }
    }
}

void createHCorridor(char map[MAP_HEIGHT][MAP_WIDTH], int startX, int endX, int y) {
    if (startX > endX) {
        int temp = startX;
        startX = endX;
        endX = temp;
    }

    for (int i = startX; i <= endX; i++) {
        map[y][i] = '.';
    }
}

void createVCorridor(char map[MAP_HEIGHT][MAP_WIDTH], int startY, int endY, int x) {
    if (startY > endY) {
        int temp = startY;
        startY = endY;
        endY = temp;
    }

    for (int i = startY; i <= endY; i++) {
        map[i][x] = '.';
    }
}

void createCorridors(char map[MAP_HEIGHT][MAP_WIDTH], Room* rooms, int numRooms) {
    for (int i = 0; i < numRooms - 1; i++) {
        int currentX = rooms[i].x + rooms[i].width / 2;
        int currentY = rooms[i].y + rooms[i].height / 2;
        int nextX = rooms[i+1].x + rooms[i+1].width / 2;
        int nextY = rooms[i+1].y + rooms[i+1].height / 2;

        if (currentX < nextX) {
            createHCorridor(map, currentX, nextX, currentY);
        }
        else {
            createHCorridor(map, nextX, currentX, currentY);
        }

        if (currentY < nextY) {
            createVCorridor(map, currentY, nextY, nextX);
        }
        else {
            createVCorridor(map, nextY, currentY, nextX);
        }
    }
}

void generateRooms(Room* rooms, int numRooms) {
    for (int i = 0; i < numRooms; i++) {
        Room room;
        room.width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        room.height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        room.x = rand() % (MAP_WIDTH - room.width - 1) + 1;
        room.y = rand() % (MAP_HEIGHT - room.height - 1) + 1;

        rooms[i] = room;
    }
}

void generateMap(char map[MAP_HEIGHT][MAP_WIDTH], Room* rooms, int numRooms) {
    fillMap(map, '#');
    generateRooms(rooms, numRooms);

    for (int i = 0; i < numRooms; i++) {
        createRoom(map, rooms[i]);
    }

    createCorridors(map, rooms, numRooms);
}

void printList(LinkedList* list) {
    Tile* current = list->start;
    while (current != NULL) {
        printf("%c (%d, %d)\n", current->symbol, current->x, current->y);
        current = current->next;
    }
}

void createPlayer(char map[MAP_HEIGHT][MAP_WIDTH], int* x, int* y) {
    do {
        *x = rand() % (MAP_WIDTH - 2) + 1;
        *y = rand() % (MAP_HEIGHT - 2) + 1;
    } while (map[*y][*x] != '.');

    map[*y][*x] = '@';
}

void movePlayer(char map[MAP_HEIGHT][MAP_WIDTH], int* x, int* y, int dx, int dy, LinkedList* log) {
    int newX = *x + dx;
    int newY = *y + dy;

    if (newX >= 0 && newX < MAP_WIDTH && newY >= 0 && newY < MAP_HEIGHT) {
        if (map[newY][newX] == '.') {
            map[*y][*x] = '.';
            map[newY][newX] = '@';
            *x = newX;
            *y = newY;

            addToList(log, 'P', newX, newY);
        }
        else {
            addToList(log, 'X', newX, newY);
        }
    }
    else {
        addToList(log, 'X', newX, newY);
    }
}

int main() {
    srand(time(NULL));

    char map[MAP_HEIGHT][MAP_WIDTH];
    Room rooms[MAX_ROOMS];
    generateMap(map, rooms, MAX_ROOMS);

    int playerX, playerY;
    createPlayer(map, &playerX, &playerY);

    LinkedList log;
    initList(&log);

    char playerInput;
    do {
        printMap(map);
        printList(&log);

        printf("WASD to move, Q to quit\n");
        scanf(" %c", &playerInput);

        switch (playerInput) {
        case 'w':
            movePlayer(map, &playerX, &playerY, 0, -1, &log);
            break;
        case 'a':
            movePlayer(map, &playerX, &playerY, -1, 0, &log);
            break;
        case 's':
            movePlayer(map, &playerX, &playerY, 0, 1, &log);
            break;
        case 'd':
            movePlayer(map, &playerX, &playerY, 1, 0, &log);
            break;
        }
    } while (playerInput != 'q');

    return 0;
}