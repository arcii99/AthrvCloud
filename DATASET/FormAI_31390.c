//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 24
#define MAX_ROOMS 10
#define MIN_ROOM_SIZE 3
#define MAX_ROOM_SIZE 10
#define WALL '#'
#define FLOOR ' '
#define PLAYER '@'

int dungeon[HEIGHT][WIDTH];

struct Point {
    int x;
    int y;
};

struct Room {
    struct Point position;
    int width;
    int height;
};

struct Player {
    struct Point position;
    bool alive;
};

void printDungeon(struct Player player) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == player.position.y && x == player.position.x) {
                printf("%c", PLAYER);
            } else {
                printf("%c", dungeon[y][x]);
            }
        }
        printf("\n");
    }
}

bool isCollision(struct Room room) {
    for (int y = room.position.y - 1; y < room.position.y + room.height + 1; y++) {
        for (int x = room.position.x - 1; x < room.position.x + room.width + 1; x++) {
            if (dungeon[y][x] == WALL) {
                return true;
            }
        }
    }
    return false;
}

struct Room generateRoom() {
    struct Room room;
    room.width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
    room.height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
    room.position.x = rand() % (WIDTH - room.width - 1) + 1;
    room.position.y = rand() % (HEIGHT - room.height - 1) + 1;
    return room;
}

void placeRoom(struct Room room) {
    for (int y = room.position.y; y < room.position.y + room.height; y++) {
        for (int x = room.position.x; x < room.position.x + room.width; x++) {
            dungeon[y][x] = FLOOR;
        }
    }
}

void placeHorizontalTunnel(int y, int x1, int x2) {
    if (x1 < x2) {
        for (int x = x1; x < x2; x++) {
            dungeon[y][x] = FLOOR;
        }
    } else {
        for (int x = x2; x < x1; x++) {
            dungeon[y][x] = FLOOR;
        }
    }
}

void placeVerticalTunnel(int x, int y1, int y2) {
    if (y1 < y2) {
        for (int y = y1; y < y2; y++) {
            dungeon[y][x] = FLOOR;
        }
    } else {
        for (int y = y2; y < y1; y++) {
            dungeon[y][x] = FLOOR;
        }
    }
}

void connectRooms(struct Room room1, struct Room room2) {
    int x1 = room1.position.x + room1.width / 2;
    int y1 = room1.position.y + room1.height / 2;
    int x2 = room2.position.x + room2.width / 2;
    int y2 = room2.position.y + room2.height / 2;

    if (rand() % 2 == 0) {
        placeHorizontalTunnel(y1, x1, x2);
        placeVerticalTunnel(x2, y1, y2);
    } else {
        placeVerticalTunnel(x1, y1, y2);
        placeHorizontalTunnel(x1, y2, y1);
    }
}

bool isOutOfBounds(struct Point position) {
    return position.x < 0 || position.x >= WIDTH || position.y < 0 || position.y >= HEIGHT;
}

bool isWall(struct Point position) {
    return dungeon[position.y][position.x] == WALL;
}

bool isFloor(struct Point position) {
    return dungeon[position.y][position.x] == FLOOR;
}

struct Point getRandomFloorPosition() {
    struct Point position;
    do {
        position.x = rand() % WIDTH;
        position.y = rand() % HEIGHT;
    } while (!isFloor(position));
    return position;
}

void placePlayer(struct Player *player) {
    player->position = getRandomFloorPosition();
    player->alive = true;
}

void movePlayer(struct Player *player, int dx, int dy) {
    struct Point newPosition = {player->position.x + dx, player->position.y + dy};
    if (!isOutOfBounds(newPosition) && !isWall(newPosition)) {
        player->position = newPosition;
    }
}

int main() {
    srand(time(NULL));
    struct Room rooms[MAX_ROOMS];

    // Fill the dungeon with walls
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            dungeon[y][x] = WALL;
        }
    }

    // Generate rooms
    int roomCount = 0;
    while (roomCount < MAX_ROOMS) {
        struct Room room = generateRoom();
        if (!isCollision(room)) {
            placeRoom(room);
            rooms[roomCount] = room;
            roomCount++;
        }
    }

    // Connect rooms with tunnels
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        connectRooms(rooms[i], rooms[i+1]);
    }

    // Place player
    struct Player player;
    placePlayer(&player);

    // Game loop
    while (player.alive) {
        printDungeon(player);

        // Move player
        int dx = 0;
        int dy = 0;
        printf("Enter move (WASD): ");
        char input = getchar();
        while (getchar() != '\n');
        switch (input) {
            case 'w': dy = -1; break;
            case 'a': dx = -1; break;
            case 's': dy = 1; break;
            case 'd': dx = 1; break;
        }
        movePlayer(&player, dx, dy);
    }

    printf("You died.\n");
    return 0;
}