//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 80
#define MAP_HEIGHT 24
#define MAX_ROOMS 10

typedef struct Room {
    int x, y, w, h;
} Room;

char map[MAP_HEIGHT][MAP_WIDTH];
Room rooms[MAX_ROOMS];
int num_rooms = 0;

void generate_map();
void place_room(Room room);
void connect_rooms(Room r1, Room r2);
int intersect(Room r1, Room r2);
void print_map();

int main() {
    // Set random seed
    srand(time(NULL));
    
    // Generate map
    generate_map();
    
    // Print map
    print_map();
    
    return 0;
}

void generate_map() {
    // Initialize map with walls
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }
    
    // Place rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        // Generate random room size and position
        int w = rand()%10 + 5;
        int h = rand()%6 + 3;
        int x = rand()%(MAP_WIDTH-w-2) + 1;
        int y = rand()%(MAP_HEIGHT-h-2) + 1;
        
        // Create room
        Room room = {x, y, w, h};
        
        // Check for intersection with existing rooms
        int intersecting = 0;
        for (int j = 0; j < num_rooms; j++) {
            if (intersect(room, rooms[j])) {
                intersecting = 1;
                break;
            }
        }
        
        // Place room if no intersection
        if (!intersecting) {
            place_room(room);
            rooms[num_rooms++] = room;
        }
    }
    
    // Connect rooms
    for (int i = 1; i < num_rooms; i++) {
        connect_rooms(rooms[i-1], rooms[i]);
    }
}

void place_room(Room room) {
    for (int i = room.y; i < room.y+room.h; i++) {
        for (int j = room.x; j < room.x+room.w; j++) {
            map[i][j] = '.';
        }
    }
}

void connect_rooms(Room r1, Room r2) {
    // Calculate centers of each room
    int x1 = r1.x + r1.w/2;
    int y1 = r1.y + r1.h/2;
    int x2 = r2.x + r2.w/2;
    int y2 = r2.y + r2.h/2;
    
    // Draw a horizontal or vertical corridor between the centers
    if (rand()%2 == 0) {
        for (int x = x1; x != x2; x += (x1<x2)?1:-1) {
            map[y1][x] = '.';
        }
        for (int y = y1; y != y2; y += (y1<y2)?1:-1) {
            map[y][x2] = '.';
        }
    } else {
        for (int y = y1; y != y2; y += (y1<y2)?1:-1) {
            map[y][x1] = '.';
        }
        for (int x = x1; x != x2; x += (x1<x2)?1:-1) {
            map[y2][x] = '.';
        }
    }
}

int intersect(Room r1, Room r2) {
    if (r1.x+r1.w < r2.x || r1.x > r2.x+r2.w ||
        r1.y+r1.h < r2.y || r1.y > r2.y+r2.h) {
        return 0;
    }
    return 1;
}

void print_map() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}