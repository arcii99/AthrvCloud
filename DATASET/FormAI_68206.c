//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 30 // The size of the map
#define MAX_ROOMS 10 // The maximum number of rooms on the map

typedef struct {
    int x, y, width, height;
} Room;

void generate_map(int map[MAP_SIZE][MAP_SIZE], Room rooms[MAX_ROOMS], int num_rooms) {
    // Initialize the map to all walls
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '#';
        }
    }
    
    // Generate random rooms
    for (int i = 0; i < num_rooms; i++) {
        // Choose random position and size
        int x = rand() % (MAP_SIZE - 10) + 1;
        int y = rand() % (MAP_SIZE - 10) + 1;
        int width = rand() % 6 + 5;
        int height = rand() % 6 + 5;
        
        // Add room to the list of rooms
        rooms[i] = (Room) {x, y, width, height};
        
        // Carve out the room on the map
        for (int j = x; j < x + width; j++) {
            for (int k = y; k < y + height; k++) {
                map[j][k] = '.';
            }
        }
    }
    
    // Connect the rooms with corridors
    for (int i = 0; i < num_rooms - 1; i++) {
        Room r1 = rooms[i];
        Room r2 = rooms[i+1];
        
        int x1 = r1.x + r1.width/2;
        int y1 = r1.y + r1.height/2;
        int x2 = r2.x + r2.width/2;
        int y2 = r2.y + r2.height/2;
        
        while (x1 != x2) {
            if (x1 < x2) {
                x1++;
            } else {
                x1--;
            }
            map[x1][y1] = '.';
        }
        
        while (y1 != y2) {
            if (y1 < y2) {
                y1++;
            } else {
                y1--;
            }
            map[x1][y1] = '.';
        }
    }
}

int main() {
    int map[MAP_SIZE][MAP_SIZE];
    Room rooms[MAX_ROOMS];
    
    srand(time(NULL));
    
    generate_map(map, rooms, MAX_ROOMS);
    
    // Print the map
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c", map[j][i]);
        }
        printf("\n");
    }
    
    return 0;
}