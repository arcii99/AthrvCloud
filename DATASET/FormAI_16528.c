//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define MAX_ROOMS 5
#define ROOM_MIN_SIZE 3
#define ROOM_MAX_SIZE 6

char map[MAP_HEIGHT][MAP_WIDTH];

// Structure for a room
typedef struct {
    int x, y;
    int width, height;
} Room;

// Check if two rooms intersect
int intersect(Room r1, Room r2) {
    if (r1.x > r2.x + r2.width || r1.x + r1.width < r2.x)
        return 0;
    if (r1.y > r2.y + r2.height || r1.y + r1.height < r2.y)
        return 0;
    return 1;
}

// Generate a random room
Room new_room() {
    Room r;
    r.width = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
    r.height = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
    r.x = rand() % (MAP_WIDTH - r.width - 1) + 1;
    r.y = rand() % (MAP_HEIGHT - r.height - 1) + 1;
    return r;
}

// Create a room in the map
void create_room(Room r) {
    int x, y;
    for (y = r.y; y < r.y + r.height; y++) {
        for (x = r.x; x < r.x + r.width; x++) {
            map[y][x] = ' ';
        }
    }
}

// Create a tunnel between two rooms
void create_tunnel(int x1, int y1, int x2, int y2) {
    int x, y;
    if (rand() % 2) {
        for (x = x1; x < x2; x++) {
            map[y1][x] = ' ';
        }
        for (y = y1; y < y2; y++) {
            map[y][x2] = ' ';
        }
    } else {
        for (y = y1; y < y2; y++) {
            map[y][x1] = ' ';
        }
        for (x = x1; x < x2; x++) {
            map[y2][x] = ' ';
        }
    }
}

// Generate the map
void generate_map() {
    int i, j, r, connected = 0;
    Room rooms[MAX_ROOMS];
    srand(time(NULL));
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }
    for (i = 0; i < MAX_ROOMS; i++) {
        do {
            rooms[i] = new_room();
            for (j = 0; j < i; j++) {
                if (intersect(rooms[i], rooms[j])) {
                    break;
                }
            }
        } while (j < i);
        create_room(rooms[i]);
        if (i > 0) {
            create_tunnel(rooms[i-1].x + rooms[i-1].width/2,
                          rooms[i-1].y + rooms[i-1].height/2,
                          rooms[i].x + rooms[i].width/2,
                          rooms[i].y + rooms[i].height/2);
        }
    }
}

// Print the map
void print_map() {
    int i, j;
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generate_map();
    print_map();
    return 0;
}