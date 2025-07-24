//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 50
#define MAX_ROOMS 10

typedef struct Room {
    int x, y, width, height;
} Room;

typedef struct Dungeon {
    char map[MAP_SIZE][MAP_SIZE];
    int num_rooms;
    Room rooms[MAX_ROOMS];
} Dungeon;

void init_map(Dungeon *dungeon) {
    // Fill map with walls
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            dungeon->map[i][j] = '#';
        }
    }
}

void generate_rooms(Dungeon *dungeon) {
    // Generate random rooms
    srand(time(NULL));
    dungeon->num_rooms = (rand() % MAX_ROOMS) + 1;
    for (int i = 0; i < dungeon->num_rooms; i++) {
        dungeon->rooms[i].width = (rand() % 7) + 3;
        dungeon->rooms[i].height = (rand() % 7) + 3;
        dungeon->rooms[i].x = rand() % (MAP_SIZE - dungeon->rooms[i].width - 2) + 1;
        dungeon->rooms[i].y = rand() % (MAP_SIZE - dungeon->rooms[i].height - 2) + 1;
        for (int j = dungeon->rooms[i].x; j < dungeon->rooms[i].x + dungeon->rooms[i].width; j++) {
            for (int k = dungeon->rooms[i].y; k < dungeon->rooms[i].y + dungeon->rooms[i].height; k++) {
                dungeon->map[j][k] = '.';
            }
        }
    }
}

void print_map(Dungeon *dungeon) {
    // Print the dungeon's map
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c", dungeon->map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Dungeon dungeon;
    init_map(&dungeon);
    generate_rooms(&dungeon);
    print_map(&dungeon);
    return 0;
}