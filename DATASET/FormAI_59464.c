//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAP_SIZE 20 // The size of the map, keep it small for testing purposes
#define MAX_ROOMS 5 // The maximum number of rooms you want to generate
#define MAX_ENEMIES 3 // The maximum number of enemies in each room
#define MAX_ITEMS 2 // The maximum number of items in each room

typedef struct {
    int x;
    int y;
    int width;
    int height;
} room_t;

int map[MAP_SIZE][MAP_SIZE] = {0}; // Initialize the map with 0's
room_t rooms[MAX_ROOMS]; // Initialize the array to hold the rooms

void generate_rooms() {
    srand(time(NULL)); // Seed the random number generator
    int num_rooms = rand() % MAX_ROOMS + 1; // Randomly generate the number of rooms
    printf("Generating %d rooms\n", num_rooms);
    
    for (int i = 0; i < num_rooms; i++) {
        int room_width = rand() % 5 + 5; // Randomly generate width between 5 and 9
        int room_height = rand() % 5 + 5; // Randomly generate height between 5 and 9
        int room_x = rand() % (MAP_SIZE - room_width); // Randomly generate x within limits
        int room_y = rand() % (MAP_SIZE - room_height); // Randomly generate y within limits
        rooms[i] = (room_t){room_x, room_y, room_width, room_height};
        printf("Room %d: (%d, %d) %dx%d\n", i+1, room_x, room_y, room_width, room_height);
        
        // Mark the room on the map
        for (int x = room_x; x < room_x + room_width; x++) {
            for (int y = room_y; y < room_y + room_height; y++) {
                map[x][y] = 1;
            }
        }
    }
}

void print_map() {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            printf("%c ", map[x][y] == 0 ? '.' : '#'); // Print '.' for empty spaces and '#' for filled spaces
        }
        printf("\n");
    }
}

bool is_valid_position(int x, int y) {
    if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE) {
        return false;
    }
    return map[x][y] == 0;
}

void generate_enemies() {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < MAX_ROOMS; i++) {
        int num_enemies = rand() % MAX_ENEMIES + 1; // Randomly generate the number of enemies
        printf("Generating %d enemies in Room %d\n", num_enemies, i+1);
        for (int j = 0; j < num_enemies; j++) {
            int enemy_x, enemy_y;
            do {
                enemy_x = rand() % rooms[i].width + rooms[i].x;
                enemy_y = rand() % rooms[i].height + rooms[i].y;
            } while (!is_valid_position(enemy_x, enemy_y)); // Keep generating enemy position until it is valid
            printf("- Enemy %d: (%d, %d)\n", j+1, enemy_x, enemy_y);
        }
    }
}

void generate_items() {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < MAX_ROOMS; i++) {
        int num_items = rand() % MAX_ITEMS + 1; // Randomly generate the number of items
        printf("Generating %d items in Room %d\n", num_items, i+1);
        for (int j = 0; j < num_items; j++) {
            int item_x, item_y;
            do {
                item_x = rand() % rooms[i].width + rooms[i].x;
                item_y = rand() % rooms[i].height + rooms[i].y;
            } while (!is_valid_position(item_x, item_y)); // Keep generating item position until it is valid
            printf("- Item %d: (%d, %d)\n", j+1, item_x, item_y);
        }
    }
}

int main() {
    generate_rooms();
    print_map();
    generate_enemies();
    generate_items();
    return 0;
}