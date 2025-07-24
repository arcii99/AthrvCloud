//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 50

typedef enum {
    WALL,
    ROOM,
} tile;

typedef struct {
    int x;
    int y;
} point;

point player_pos;

tile map[MAP_SIZE][MAP_SIZE];

void gen_map() {
    // Initialize map with walls
    for (int x = 0; x < MAP_SIZE; x++) {
        for (int y = 0; y < MAP_SIZE; y++) {
            map[x][y] = WALL;
        }
    }

    // Generate rooms
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int room_width = rand() % 10 + 5;
        int room_height = rand() % 10 + 5;
        int room_x = rand() % (MAP_SIZE - room_width - 1) + 1;
        int room_y = rand() % (MAP_SIZE - room_height - 1) + 1;

        for (int x = room_x; x < room_x + room_width; x++) {
            for (int y = room_y; y < room_y + room_height; y++) {
                map[x][y] = ROOM;
            }
        }
    }

    // Connect rooms
    for (int i = 0; i < 10; i++) {
        int room1_x = rand() % MAP_SIZE;
        int room1_y = rand() % MAP_SIZE;

        int room2_x = rand() % MAP_SIZE;
        int room2_y = rand() % MAP_SIZE;

        while (map[room1_x][room1_y] != ROOM) {
            room1_x = rand() % MAP_SIZE;
            room1_y = rand() % MAP_SIZE;
        }

        while ((room2_x == room1_x && room2_y == room1_y) || map[room2_x][room2_y] != ROOM) {
            room2_x = rand() % MAP_SIZE;
            room2_y = rand() % MAP_SIZE;
        }

        point current_pos = {room1_x, room1_y};
        while (current_pos.x != room2_x || current_pos.y != room2_y) {
            if (current_pos.x < room2_x) {
                current_pos.x += 1;
            } else if (current_pos.x > room2_x) {
                current_pos.x -= 1;
            }
            if (current_pos.y < room2_y) {
                current_pos.y += 1;
            } else if (current_pos.y > room2_y) {
                current_pos.y -= 1;
            }
            map[current_pos.x][current_pos.y] = ROOM;
        }
    }

    // Place player in a random room
    int player_room_x, player_room_y;
    do {
        player_room_x = rand() % MAP_SIZE;
        player_room_y = rand() % MAP_SIZE;
    } while (map[player_room_x][player_room_y] != ROOM);
    player_pos.x = player_room_x;
    player_pos.y = player_room_y;
}

void draw_map() {
    for (int x = 0; x < MAP_SIZE; x++) {
        for (int y = 0; y < MAP_SIZE; y++) {
            if (player_pos.x == x && player_pos.y == y) {
                printf("@");
            } else if (map[x][y] == WALL) {
                printf("#");
            } else if (map[x][y] == ROOM) {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    gen_map();
    draw_map();

    return 0;
}