//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: thoughtful
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 40
#define MAP_HEIGHT 20
#define NUM_ROOMS 6
#define MAX_ROOM_SIZE 6
#define MIN_ROOM_SIZE 2

typedef struct {
    int x, y, width, height;
} Room;

char map[MAP_WIDTH][MAP_HEIGHT];

void generate_map();
void print_map();

int main() {
    srand(time(NULL));
    
    generate_map();
    print_map();
    
    return 0;
}

void generate_map() {
    // Initialize map with walls
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            map[x][y] = '#';
        }
    }
    
    // Generate rooms
    Room rooms[NUM_ROOMS];
    for (int i = 0; i < NUM_ROOMS; i++) {
        int room_width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        int room_height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        int x = rand() % (MAP_WIDTH - room_width - 1) + 1;
        int y = rand() % (MAP_HEIGHT - room_height - 1) + 1;
        
        Room room = {x, y, room_width, room_height};
        
        // Check if the room overlaps with any existing room
        int overlap = 0;
        for (int j = 0; j < i; j++) {
            if (room.x < rooms[j].x + rooms[j].width && room.x + room.width > rooms[j].x
                && room.y < rooms[j].y + rooms[j].height && room.y + room.height > rooms[j].y) {
                overlap = 1;
                break;
            }
        }
        
        if (!overlap) {
            // Place the room in the map
            for (int x = room.x; x < room.x + room.width; x++) {
                for (int y = room.y; y < room.y + room.height; y++) {
                    map[x][y] = '.';
                }
            }
            
            rooms[i] = room;
        }
    }
    
    // Connect the rooms with corridors
    for (int i = 0; i < NUM_ROOMS - 1; i++) {
        int x1 = rooms[i].x + rooms[i].width / 2;
        int y1 = rooms[i].y + rooms[i].height / 2;
        int x2 = rooms[i + 1].x + rooms[i + 1].width / 2;
        int y2 = rooms[i + 1].y + rooms[i + 1].height / 2;
        
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
            
            map[x1][y1] = '.';
        }
    }
}

void print_map() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}