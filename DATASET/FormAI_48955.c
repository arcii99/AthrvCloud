//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define ROOM_HEIGHT 6
#define ROOM_WIDTH 8
#define LEVEL_HEIGHT (MAX_ROOMS * ROOM_HEIGHT)
#define LEVEL_WIDTH (MAX_ROOMS * ROOM_WIDTH)

// Room struct
typedef struct Room {
    int x, y, height, width;
} Room;

// Level struct
typedef struct Level {
    char tiles[LEVEL_HEIGHT][LEVEL_WIDTH];
    Room rooms[MAX_ROOMS];
    int num_rooms;
} Level;

// Function to fill a rectangle with a character
void fill_rect(Level* level, int x, int y, int height, int width, char c) {
    for (int i = x; i < x + height; i++) {
        for (int j = y; j < y + width; j++) {
            level->tiles[i][j] = c;
        }
    }
}

// Function to check if two rooms intersect
int intersects(Room r1, Room r2) {
    return !(r1.x + r1.width < r2.x || r2.x + r2.width < r1.x || r1.y + r1.height < r2.y || r2.y + r2.height < r1.y);
}

// Function to generate random rooms
Room generate_room(int x, int y) {
    Room room;
    room.x = x;
    room.y = y;
    room.height = rand() % (ROOM_HEIGHT - 2) + 3;
    room.width = rand() % (ROOM_WIDTH - 2) + 3;
    return room;
}

// Function to generate rooms and add them to the level
void add_rooms(Level* level) {
    int x = 0, y = 0;
    int num_rooms = 0;
    while (num_rooms < MAX_ROOMS) {
        Room room = generate_room(x, y);
        int intersects_existing = 0;
        for (int i = 0; i < level->num_rooms; i++) {
            if (intersects(room, level->rooms[i])) {
                intersects_existing = 1;
                break;
            }
        }
        if (!intersects_existing) {
            fill_rect(level, room.x, room.y, room.height, room.width, '.');
            level->rooms[num_rooms] = room;
            level->num_rooms++;
            num_rooms++;
        }

        x += ROOM_WIDTH;
        if (x >= LEVEL_WIDTH) {
            x = 0;
            y += ROOM_HEIGHT;
        }
    }
}

// Function to connect rooms with corridors
void connect_rooms(Level* level) {
    for (int i = 0; i < level->num_rooms - 1; i++) {
        int x1 = level->rooms[i].x + level->rooms[i].width / 2;
        int y1 = level->rooms[i].y + level->rooms[i].height / 2;
        int x2 = level->rooms[i+1].x + level->rooms[i+1].width / 2;
        int y2 = level->rooms[i+1].y + level->rooms[i+1].height / 2;

        if (rand() % 2 == 0) {
            fill_rect(level, x1, y1, 1, abs(x2 - x1), '#');
            fill_rect(level, x2, y1, abs(y2 - y1) + 1, 1, '#');
        } else {
            fill_rect(level, x1, y1, abs(y2 - y1) + 1, 1, '#');
            fill_rect(level, x1, y2, 1, abs(x2 - x1) + 1, '#');
        }
    }
}

int main() {
    srand(time(NULL));
    Level level;

    // Fill level with walls
    for (int i = 0; i < LEVEL_HEIGHT; i++) {
        for (int j = 0; j < LEVEL_WIDTH; j++) {
            level.tiles[i][j] = '#';
        }
    }

    // Generate rooms and connect them
    add_rooms(&level);
    connect_rooms(&level);

    // Print level
    for (int i = 0; i < LEVEL_HEIGHT; i++) {
        for (int j = 0; j < LEVEL_WIDTH; j++) {
            printf("%c", level.tiles[i][j]);
        }
        printf("\n");
    }

    return 0;
}