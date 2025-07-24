//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// CONSTANTS
#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define MAX_ROOMS 5

// STRUCTS
typedef struct Room {
    int x, y, w, h;
} Room;

// FUNCTION PROTOTYPES
void generate_map(int map[MAP_HEIGHT][MAP_WIDTH]);
void add_room(int map[MAP_HEIGHT][MAP_WIDTH], Room room);
void connect_rooms(int map[MAP_HEIGHT][MAP_WIDTH], Room room1, Room room2);

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize map
    int map[MAP_HEIGHT][MAP_WIDTH] = {0};
    
    // Generate rooms
    int num_rooms = 0;
    while (num_rooms < MAX_ROOMS) {
        // Randomly generate room parameters
        int x = rand() % (MAP_WIDTH - 3) + 1;  // leave space for walls
        int y = rand() % (MAP_HEIGHT - 3) + 1; // leave space for walls
        int w = rand() % 5 + 3; // minimum width of 3
        int h = rand() % 5 + 3; // minimum height of 3
        
        // Check if room overlaps with existing rooms
        int overlap = 0;
        for (int i = x - 1; i <= x + w; i++) {
            for (int j = y - 1; j <= y + h; j++) {
                if (map[j][i]) // room already exists here
                    overlap = 1;
            }
        }
        
        // Add room to map if it doesn't overlap
        if (!overlap) {
            Room room = {x, y, w, h};
            add_room(map, room);
            num_rooms++;
        }
    }
    
    // Connect rooms with corridors
    for (int i = 0; i < num_rooms - 1; i++) {
        Room room1, room2;
        for (int j = 0; j < MAP_HEIGHT; j++) {
            for (int k = 0; k < MAP_WIDTH; k++) {
                if (map[j][k] == i + 1)
                    room1 = (Room) {k, j, 1, 1};
                else if (map[j][k] == i + 2)
                    room2 = (Room) {k, j, 1, 1};
            }
        }
        connect_rooms(map, room1, room2);
    }
    
    // Print map
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            if (map[i][j])
                printf(".");
            else
                printf("#");
        }
        printf("\n");
    }
    
    return 0;
}

// Generate random map using rooms and corridors
void generate_map(int map[MAP_HEIGHT][MAP_WIDTH]) {
    // TODO: Implement
    
}

// Add a room to the map
void add_room(int map[MAP_HEIGHT][MAP_WIDTH], Room room) {
    for (int i = room.x; i < room.x + room.w; i++) {
        for (int j = room.y; j < room.y + room.h; j++) {
            map[j][i] = 1;
        }
    }
}

// Connect two rooms with a corridor
void connect_rooms(int map[MAP_HEIGHT][MAP_WIDTH], Room room1, Room room2) {
    int x1 = rand() % room1.w + room1.x;
    int y1 = rand() % room1.h + room1.y;
    int x2 = rand() % room2.w + room2.x;
    int y2 = rand() % room2.h + room2.y;
    
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    while (x1 != x2 || y1 != y2) {
        if (x1 != x2 && rand() % 2) {
            x1 += dx > 0 ? 1 : -1;
        }
        else if (y1 != y2) {
            y1 += dy > 0 ? 1 : -1;
        }
        map[y1][x1] = 1;
    }
}