//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20
#define MAX_ROOMS 5
#define MIN_ROOM_WIDTH 5
#define MIN_ROOM_HEIGHT 5
#define MAX_ROOM_WIDTH 15
#define MAX_ROOM_HEIGHT 15

typedef struct {
    int x, y;
    int width, height;
} Room;

typedef struct {
    char symbol;
    int x, y;
} Entity;

void initializeMap(char map[][WIDTH]);
void printMap(char map[][WIDTH]);
void generateRooms(Room rooms[]);
void connectRooms(Room rooms[], char map[][WIDTH]);
void placeEntities(Entity entities[]);
void moveEntities(Entity entities[], char map[][WIDTH]);

int main() {
    char map[HEIGHT][WIDTH];
    Room rooms[MAX_ROOMS];
    Entity entities[] = {
        {'@', WIDTH/2, HEIGHT/2},
        {'g', WIDTH/2+1, HEIGHT/2+1},
        {'g', WIDTH/2-1, HEIGHT/2-1},
        {'g', WIDTH/2-1, HEIGHT/2+1},
        {'g', WIDTH/2+1, HEIGHT/2-1},
    };
    srand(time(NULL));
    initializeMap(map);
    generateRooms(rooms);
    connectRooms(rooms, map);
    placeEntities(entities);
    printMap(map);
    while (1) {
        moveEntities(entities, map);
        printMap(map);
        printf("Move: ");
        char move;
        scanf(" %c", &move);
        if (move == 'q') {
            break;
        }
        if (move == 'w') {
            entities[0].y--;
        }
        if (move == 's') {
            entities[0].y++;
        }
        if (move == 'a') {
            entities[0].x--;
        }
        if (move == 'd') {
            entities[0].x++;
        }
    }
    return 0;
}

void initializeMap(char map[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = '#';
        }
    }
}

void printMap(char map[][WIDTH]) {
    system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void generateRooms(Room rooms[]) {
    int roomCount = 0;
    while (roomCount < MAX_ROOMS) {
        int x = rand() % (WIDTH - MAX_ROOM_WIDTH - 1) + 1;
        int y = rand() % (HEIGHT - MAX_ROOM_HEIGHT - 1) + 1;
        int width = rand() % (MAX_ROOM_WIDTH - MIN_ROOM_WIDTH + 1) + MIN_ROOM_WIDTH;
        int height = rand() % (MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT + 1) + MIN_ROOM_HEIGHT;
        Room newRoom = {x, y, width, height};
        int overlapsExistingRooms = 0;
        for (int i = 0; i < roomCount; i++) {
            Room existingRoom = rooms[i];
            if (newRoom.x < existingRoom.x + existingRoom.width && newRoom.x + newRoom.width > existingRoom.x &&
                newRoom.y < existingRoom.y + existingRoom.height && newRoom.y + newRoom.height > existingRoom.y) {
                overlapsExistingRooms = 1;
                break;
            }
        }
        if (!overlapsExistingRooms) {
            rooms[roomCount++] = newRoom;
        }
    }
}

void connectRooms(Room rooms[], char map[][WIDTH]) {
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        Room roomA = rooms[i];
        Room roomB = rooms[i+1];

        int xA = roomA.x + rand() % roomA.width;
        int yA = roomA.y + rand() % roomA.height;
        int xB = roomB.x + rand() % roomB.width;
        int yB = roomB.y + rand() % roomB.height;

        while (xA != xB) {
            if (xA < xB) {
                xA++;
            } else {
                xA--;
            }
            map[yA][xA] = '.';
        }

        while (yA != yB) {
            if (yA < yB) {
                yA++;
            } else {
                yA--;
            }
            map[yA][xA] = '.';
        }
    }
}

void placeEntities(Entity entities[]) {
    for (int i = 0; i < sizeof(entities)/sizeof(entities[0]); i++) {
        Entity e = entities[i];
        printf("%c: %d, %d\n", e.symbol, e.x, e.y);
    }
}

void moveEntities(Entity entities[], char map[][WIDTH]) {
    for (int i = 1; i < sizeof(entities)/sizeof(entities[0]); i++) {
        Entity e = entities[i];
        int dx = rand() % 3 - 1; // -1, 0, or 1
        int dy = rand() % 3 - 1;
        if (dx == 0 && dy == 0) {
            continue;
        }
        if (e.x + dx < 0 || e.y + dy < 0 || e.x + dx >= WIDTH || e.y + dy >= HEIGHT) {
            continue;
        }
        if (map[e.y + dy][e.x + dx] != '#') {
            continue;
        }
        map[e.y][e.x] = '#';
        e.x += dx;
        e.y += dy;
        map[e.y][e.x] = e.symbol;
        entities[i] = e;
    }
}