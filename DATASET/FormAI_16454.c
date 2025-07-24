//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define MAP_WIDTH 30
#define MAP_HEIGHT 20
#define MAX_ROOMS 6
#define MIN_ROOM_SIZE 3
#define MAX_ROOM_SIZE 6

// define struct for a room
typedef struct {
    int x;
    int y;
    int width;
    int height;
} Room;

// function to randomly generate a room
Room generate_room() {
    // initialize random seed
    srand(time(NULL));
    
    // generate random room dimensions
    int width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
    int height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
    
    // generate random room position
    int x = rand() % (MAP_WIDTH - width - 1) + 1;
    int y = rand() % (MAP_HEIGHT - height - 1) + 1;
    
    // create and return room struct
    Room room = {x, y, width, height};
    return room;
}

// function to check if two rooms overlap
int check_overlap(Room r1, Room r2) {
    return !(r1.x + r1.width < r2.x || r2.x + r2.width < r1.x || r1.y + r1.height < r2.y || r2.y + r2.height < r1.y);
}

// function to create the map
void create_map(char map[MAP_HEIGHT][MAP_WIDTH]) {
    // initialize map to all walls
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }
    
    // generate rooms
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;
    while (num_rooms < MAX_ROOMS) {
        Room new_room = generate_room();
        int overlap = 0;
        for (int i = 0; i < num_rooms; i++) {
            if (check_overlap(new_room, rooms[i])) {
                overlap = 1;
                break;
            }
        }
        if (!overlap) {
            rooms[num_rooms] = new_room;
            num_rooms++;
        }
    }
    
    // carve out rooms in the map
    for (int i = 0; i < MAX_ROOMS; i++) {
        for (int y = rooms[i].y; y < rooms[i].y + rooms[i].height; y++) {
            for (int x = rooms[i].x; x < rooms[i].x + rooms[i].width; x++) {
                map[y][x] = '.';
            }
        }
    }
    
    // connect rooms with corridors
    for (int i = 0; i < MAX_ROOMS - 1; i++) {
        int x1 = rooms[i].x + rooms[i].width / 2;
        int y1 = rooms[i].y + rooms[i].height / 2;
        int x2 = rooms[i+1].x + rooms[i+1].width / 2;
        int y2 = rooms[i+1].y + rooms[i+1].height / 2;
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
            map[y1][x1] = '.';
        }
    }
}

int main() {
    // create map
    char map[MAP_HEIGHT][MAP_WIDTH];
    create_map(map);
    
    // print map to console
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}