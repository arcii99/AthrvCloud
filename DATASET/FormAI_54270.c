//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants for map size and room maximum sizes
#define MAP_WIDTH 80
#define MAP_HEIGHT 30
#define ROOM_MAX_WIDTH 10
#define ROOM_MAX_HEIGHT 10

// create a struct to represent a room
typedef struct {
    int x, y, width, height;
} room;

// create a struct to represent the game map
typedef struct {
    int tiles[MAP_HEIGHT][MAP_WIDTH];
} map;

// function to generate a random integer between two values
int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// function to create a room
room create_room(int x, int y, int width, int height) {
    room r;
    r.x = x;
    r.y = y;
    r.width = width;
    r.height = height;

    return r;
}

// function to generate a random room
room generate_room() {
    int x = random_int(1, MAP_WIDTH - ROOM_MAX_WIDTH - 2); // leave one tile of padding between rooms and map edges
    int y = random_int(1, MAP_HEIGHT - ROOM_MAX_HEIGHT - 2);
    int width = random_int(3, ROOM_MAX_WIDTH);
    int height = random_int(3, ROOM_MAX_HEIGHT);

    return create_room(x, y, width, height);
}

// function to add a room to the map
void add_room_to_map(room r, map *m) {
    int i, j;
    for (i = r.y; i < r.y + r.height; i++) {
        for (j = r.x; j < r.x + r.width; j++) {
            m->tiles[i][j] = 1; // set the tile to 1 (a floor tile)
        }
    }
}

// function to connect two rooms with a corridor
void connect_rooms(room r1, room r2, map *m) {
    int x1 = r1.x + r1.width / 2;
    int y1 = r1.y + r1.height / 2;
    int x2 = r2.x + r2.width / 2;
    int y2 = r2.y + r2.height / 2;

    int i, j;
    for (i = x1; i != x2; i += (x2 - x1) / abs(x2 - x1)) { // move horizontally towards the other room
        m->tiles[y1][i] = 1; // set the tile to 1 (a floor tile)
    }
    for (j = y1; j != y2; j += (y2 - y1) / abs(y2 - y1)) { // move vertically towards the other room
        m->tiles[j][i] = 1; // set the tile to 1 (a floor tile)
    }
}

// function to print the map to the terminal
void print_map(map m) {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            if (m.tiles[i][j] == 0) {
                printf("#"); // print a wall tile
            } else {
                printf("."); // print a floor tile
            }
        }
        printf("\n"); // move to the next row
    }
}

// main function
int main() {
    srand(time(NULL)); // seed the random number generator

    map world = {0}; // create an empty map

    // generate rooms and connect them
    room r1 = generate_room();
    add_room_to_map(r1, &world);

    int num_rooms = random_int(5, 10); // generate 5 to 10 rooms
    int i;
    for (i = 1; i < num_rooms; i++) {
        room r2 = generate_room();
        while (r2.x + r2.width >= MAP_WIDTH || r2.y + r2.height >= MAP_HEIGHT) { // make sure the room doesn't go outside the map
            r2 = generate_room();
        }

        add_room_to_map(r2, &world);
        connect_rooms(r1, r2, &world);

        r1 = r2;
    }

    print_map(world); // print the map to the terminal

    return 0;
}