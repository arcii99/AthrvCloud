//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 50
#define HEIGHT 20
#define MAX_ROOMS 10
#define ROOM_MIN_SIZE 3
#define ROOM_MAX_SIZE 7

int map[WIDTH][HEIGHT];

typedef struct {
    int x, y, width, height;
} Room;

void init_map() {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            map[x][y] = '#'; // set all cells to wall
        }
    }
}

void print_map() {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            printf("%c", map[x][y]);
        }
        printf("\n");
    }
}

bool is_room_colliding(Room room, Room rooms[], int room_count) {
    for(int i = 0; i < room_count; i++) {
        Room r = rooms[i];
        if(room.x < r.x + r.width &&
           room.x + room.width > r.x &&
           room.y < r.y + r.height &&
           room.y + room.height > r.y) {
               return true;
        }
    }
    return false;
}

void create_room(Room room) {
    for(int y = room.y; y < room.y + room.height; y++) {
        for(int x = room.x; x < room.x + room.width; x++) {
            if(x == room.x || x == room.x + room.width - 1 ||
               y == room.y || y == room.y + room.height - 1) {
                   map[x][y] = '#'; // set walls
            } else {
                map[x][y] = '.'; // set floor
            }
        }
    }
}

void connect_rooms(Room room1, Room room2) {
    int x1 = room1.x + room1.width / 2;
    int y1 = room1.y + room1.height / 2;
    int x2 = room2.x + room2.width / 2;
    int y2 = room2.y + room2.height / 2;

    while(x1 != x2 || y1 != y2) {
        if(x1 < x2) x1++;
        else if(x1 > x2) x1--;
        else if(y1 < y2) y1++;
        else if(y1 > y2) y1--;
        map[x1][y1] = '.'; // dig a tunnel
    }
}

void generate_map() {
    Room rooms[MAX_ROOMS];
    int room_count = 0;

    srand(time(0)); // seed random number generator

    for(int i = 0; i < MAX_ROOMS; i++) {
        int x = rand() % (WIDTH - ROOM_MAX_SIZE - 1) + 1;
        int y = rand() % (HEIGHT - ROOM_MAX_SIZE - 1) + 1;
        int width = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        int height = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
        Room room = {x, y, width, height};

        if(!is_room_colliding(room, rooms, room_count)) {
            rooms[room_count] = room;
            room_count++;
        }
    }

    for(int i = 0; i < room_count; i++) {
        create_room(rooms[i]);
    }

    for(int i = 0; i < room_count - 1; i++) {
        connect_rooms(rooms[i], rooms[i+1]);
    }
}

int main() {
    init_map();
    generate_map();
    print_map();

    return 0;
}