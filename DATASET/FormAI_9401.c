//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define MAX_ROOMS 6
#define MAX_ROOM_WIDTH 5
#define MAX_ROOM_HEIGHT 5

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point start;
    Point end;
} Room;

typedef struct {
    char map[MAP_WIDTH][MAP_HEIGHT];
    Room rooms[MAX_ROOMS];
    int num_rooms;
} Dungeon;

void reset_map(Dungeon* dungeon) {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            dungeon->map[i][j] = '#';
        }
    }
}

void print_map(Dungeon* dungeon) {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            printf("%c ", dungeon->map[i][j]);
        }
        printf("\n");
    }
}

void connect_rooms(Dungeon* dungeon) {
    // Connect the rooms with corridors
    for (int i = 0; i < dungeon->num_rooms - 1; i++) {
        Room start_room = dungeon->rooms[i];
        Room end_room = dungeon->rooms[i + 1];

        // Get the center points of the rooms
        Point start_center = {
            .x = (start_room.start.x + start_room.end.x) / 2,
            .y = (start_room.start.y + start_room.end.y) / 2,
        };
        Point end_center = {
            .x = (end_room.start.x + end_room.end.x) / 2,
            .y = (end_room.start.y + end_room.end.y) / 2,
        };

        // Connect the centers with a straight line
        for (int j = start_center.x; j <= end_center.x; j++) {
            dungeon->map[j][start_center.y] = '.';
        }
        for (int j = start_center.y; j <= end_center.y; j++) {
            dungeon->map[end_center.x][j] = '.';
        }
    }
}

void generate_dungeon(Dungeon* dungeon) {
    // Reset the map
    reset_map(dungeon);

    // Generate rooms
    dungeon->num_rooms = 0;
    srand(time(0));
    for (int i = 0; i < MAX_ROOMS; i++) {
        // Generate a random room
        int room_width = rand() % MAX_ROOM_WIDTH + 1;
        int room_height = rand() % MAX_ROOM_HEIGHT + 1;
        int room_x = rand() % (MAP_WIDTH - room_width - 1) + 1;
        int room_y = rand() % (MAP_HEIGHT - room_height - 1) + 1;
        Room room = {
            .start = { .x = room_x, .y = room_y },
            .end = { .x = room_x + room_width - 1, .y = room_y + room_height - 1 },
        };

        // Check if the room overlaps with any other rooms
        int overlapping = 0;
        for (int j = 0; j < dungeon->num_rooms; j++) {
            if (room.start.x <= dungeon->rooms[j].end.x && room.end.x >= dungeon->rooms[j].start.x &&
                room.start.y <= dungeon->rooms[j].end.y && room.end.y >= dungeon->rooms[j].start.y) {
                overlapping = 1;
                break;
            }
        }
        if (overlapping) {
            continue;
        }

        // Add the room to the map
        for (int x = room.start.x + 1; x < room.end.x; x++) {
            for (int y = room.start.y + 1; y < room.end.y; y++) {
                dungeon->map[x][y] = '.';
            }
        }
        dungeon->rooms[dungeon->num_rooms] = room;
        dungeon->num_rooms++;

        if (dungeon->num_rooms == MAX_ROOMS) {
            break;
        }
    }

    // Connect the rooms with corridors
    connect_rooms(dungeon);
}

int main() {
    Dungeon dungeon;
    generate_dungeon(&dungeon);
    print_map(&dungeon);
    return 0;
}