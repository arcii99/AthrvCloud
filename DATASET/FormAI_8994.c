//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 80
#define MAP_HEIGHT 25
#define NUM_ROOMS 10
#define MAX_ROOM_SIZE 10
#define MIN_ROOM_SIZE 5

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    int width, height;
} Room;

char map[MAP_WIDTH][MAP_HEIGHT];

int check_room_overlap(Room r) {
    for (int x = r.pos.x-1; x < r.pos.x+r.width+1; x++) {
        for (int y = r.pos.y-1; y < r.pos.y+r.height+1; y++) {
            if (map[x][y] == '.') {
                return 1;
            }
        }
    }
    return 0;
}

void add_room(Room r) {
    for (int x = r.pos.x; x < r.pos.x+r.width; x++) {
        for (int y = r.pos.y; y < r.pos.y+r.height; y++) {
            map[x][y] = '.';
        }
    }
}

void add_corridors(Room r1, Room r2) {
    Point c1 = { r1.pos.x + r1.width/2, r1.pos.y + r1.height/2 };
    Point c2 = { r2.pos.x + r2.width/2, r2.pos.y + r2.height/2 };
    int dx = c1.x - c2.x, dy = c1.y - c2.y;
    while (dx != 0 || dy != 0) {
        if (dx > 0 && map[c1.x-1][c1.y] == '#') {
            c1.x--;
        } else if (dx < 0 && map[c1.x+1][c1.y] == '#') {
            c1.x++;
        } else if (dy > 0 && map[c1.x][c1.y-1] == '#') {
            c1.y--;
        } else if (dy < 0 && map[c1.x][c1.y+1] == '#') {
            c1.y++;
        }
        map[c1.x][c1.y] = '.';
        dx = c1.x - c2.x, dy = c1.y - c2.y;
    }
}

void generate_map() {
    // Initialize the map to all walls
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            map[x][y] = '#';
        }
    }

    // Generate the rooms
    srand(time(NULL));
    Room rooms[NUM_ROOMS];
    int num_rooms = 0;
    while (num_rooms < NUM_ROOMS) {
        Room r = {
            .pos = { rand() % (MAP_WIDTH-MAX_ROOM_SIZE), rand() % (MAP_HEIGHT-MAX_ROOM_SIZE) },
            .width = MIN_ROOM_SIZE + rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE),
            .height = MIN_ROOM_SIZE + rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE)
        };
        if (!check_room_overlap(r)) {
            rooms[num_rooms++] = r;
            add_room(r);
        }
    }

    // Generate the corridors
    for (int i = 0; i < NUM_ROOMS-1; i++) {
        add_corridors(rooms[i], rooms[i+1]);
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

int main() {
    generate_map();
    print_map();
    return 0;
}