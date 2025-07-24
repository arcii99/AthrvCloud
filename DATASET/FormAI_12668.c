//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_MAP_SIZE 20
#define MAX_ROOMS 5

typedef struct {
    int x, y, w, h;
} Room;

// Function declarations
void generate_map(int map[MAX_MAP_SIZE][MAX_MAP_SIZE]);
void print_map(int map[MAX_MAP_SIZE][MAX_MAP_SIZE]);
void generate_rooms(Room rooms[MAX_ROOMS]);
void draw_rooms(int map[MAX_MAP_SIZE][MAX_MAP_SIZE], Room rooms[MAX_ROOMS]);
void connect_rooms(int map[MAX_MAP_SIZE][MAX_MAP_SIZE], Room rooms[MAX_ROOMS]);
int get_random_number(int min, int max);

// Main function
int main() {
    int map[MAX_MAP_SIZE][MAX_MAP_SIZE] = {0};
    Room rooms[MAX_ROOMS];

    srand(time(NULL)); // Seed the random number generator

    generate_map(map);
    generate_rooms(rooms);
    draw_rooms(map, rooms);
    connect_rooms(map, rooms);
    print_map(map);

    return 0;
}

// Function definitions

void generate_map(int map[MAX_MAP_SIZE][MAX_MAP_SIZE]) {
    // Generate a map filled with walls (1s)
    for (int i = 0; i < MAX_MAP_SIZE; i++) {
        for (int j = 0; j < MAX_MAP_SIZE; j++) {
            map[i][j] = 1;
        }
    }
}

void print_map(int map[MAX_MAP_SIZE][MAX_MAP_SIZE]) {
    // Print the map to the console
    for (int i = 0; i < MAX_MAP_SIZE; i++) {
        for (int j = 0; j < MAX_MAP_SIZE; j++) {
            if (map[i][j] == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void generate_rooms(Room rooms[MAX_ROOMS]) {
    // Generate random rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].w = get_random_number(3, 8);
        rooms[i].h = get_random_number(3, 6);
        rooms[i].x = get_random_number(0, MAX_MAP_SIZE - rooms[i].w - 1);
        rooms[i].y = get_random_number(0, MAX_MAP_SIZE - rooms[i].h - 1);
    }
}

void draw_rooms(int map[MAX_MAP_SIZE][MAX_MAP_SIZE], Room rooms[MAX_ROOMS]) {
    // Draw the rooms onto the map
    for (int i = 0; i < MAX_ROOMS; i++) {
        for (int y = rooms[i].y; y < rooms[i].y + rooms[i].h; y++) {
            for (int x = rooms[i].x; x < rooms[i].x + rooms[i].w; x++) {
                map[y][x] = 0;
            }
        }
    }
}

void connect_rooms(int map[MAX_MAP_SIZE][MAX_MAP_SIZE], Room rooms[MAX_ROOMS]) {
    // Connect the rooms with tunnels
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        int x1 = rooms[i].x + rooms[i].w / 2;
        int y1 = rooms[i].y + rooms[i].h / 2;
        int x2 = rooms[i + 1].x + rooms[i + 1].w / 2;
        int y2 = rooms[i + 1].y + rooms[i + 1].h / 2;

        while (x1 != x2 || y1 != y2) {
            if (x1 < x2) {
                x1++;
            } else if (x1 > x2) {
                x1--;
            }

            if (y1 < y2) {
                y1++;
            } else if (y1 > y2) {
                y1--;
            }

            map[y1][x1] = 0;
        }
    }
}

int get_random_number(int min, int max) {
    // Return a random number between min and max (inclusive)
    return rand() % (max - min + 1) + min;
}