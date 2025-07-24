//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 10
#define MIN_ROOM_WIDTH 3
#define MIN_ROOM_HEIGHT 3
#define MAX_ROOM_WIDTH 8
#define MAX_ROOM_HEIGHT 8

typedef struct {
    int x, y;
    int width, height;
} Room;

void print_map(char map[MAP_HEIGHT][MAP_WIDTH], int player_x, int player_y) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (x == player_x && y == player_y) {
                putchar('@');
            } else {
                putchar(map[y][x]);
            }
        }
        putchar('\n');
    }
}

int main() {
    char map[MAP_HEIGHT][MAP_WIDTH];
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;
    int player_x = 0, player_y = 0;

    // Initialize map to be all walls
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = '#';
        }
    }

    // RNG initialization
    srand(time(NULL));

    // Generate rooms
    while (num_rooms < MAX_ROOMS) {
        int room_width = rand() % (MAX_ROOM_WIDTH - MIN_ROOM_WIDTH + 1) + MIN_ROOM_WIDTH;
        int room_height = rand() % (MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT + 1) + MIN_ROOM_HEIGHT;
        int room_x = rand() % (MAP_WIDTH - room_width - 1) + 1;
        int room_y = rand() % (MAP_HEIGHT - room_height - 1) + 1;
        Room new_room = {room_x, room_y, room_width, room_height};

        // Check if new room overlaps with any existing rooms
        int overlap = 0;
        for (int i = 0; i < num_rooms; i++) {
            Room existing_room = rooms[i];
            if (!(new_room.x + new_room.width < existing_room.x || new_room.x > existing_room.x + existing_room.width || new_room.y + new_room.height < existing_room.y || new_room.y > existing_room.y + existing_room.height)) {
                overlap = 1;
                break;
            }
        }

        if (!overlap) {
            // Carve out the room from the wall
            for (int y = room_y; y < room_y + room_height; y++) {
                for (int x = room_x; x < room_x + room_width; x++) {
                    map[y][x] = ' ';
                }
            }

            // Add the new room to the list
            rooms[num_rooms] = new_room;
            num_rooms++;

            // Place the player in the first room generated
            if (num_rooms == 1) {
                player_x = room_x + room_width / 2;
                player_y = room_y + room_height / 2;
            }
        }
    }

    // Generate corridor
    for (int i = 0; i < num_rooms - 1; i++) {
        Room room1 = rooms[i];
        Room room2 = rooms[i + 1];

        // Draw horizontal corridor
        int x1 = room1.x + room1.width / 2;
        int y1 = room1.y + room1.height / 2;
        int x2 = room2.x + room2.width / 2;
        int y2 = room2.y + room2.height / 2;

        for (int x = x1; x != x2; x += (x1 < x2) ? 1 : -1) {
            map[y1][x] = ' ';
        }

        // Draw vertical corridor
        for (int y = y1; y != y2; y += (y1 < y2) ? 1 : -1) {
            map[y][x2] = ' ';
        }
    }

    // Print the generated map
    print_map(map, player_x, player_y);

    return 0;
}