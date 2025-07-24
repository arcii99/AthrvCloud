//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define MAX_ROOMS 12
#define MIN_SIZE 4
#define MAX_SIZE 10

typedef struct {
    int x;
    int y;
    int width;
    int height;
} room_t;

char dungeon[HEIGHT][WIDTH];

void draw_dungeon();
void fill_dungeon(char fill_char);
void generate_rooms(int num_rooms);
void generate_corridors(room_t rooms[], int num_rooms);
void create_room(room_t room);
int is_overlap(room_t a, room_t b);
int is_within_boundaries(room_t room);
void connect_rooms(room_t a, room_t b);

int main() {
    srand(time(NULL));
    fill_dungeon('#');
    generate_rooms(MAX_ROOMS);
    draw_dungeon();
    return 0;
}

void fill_dungeon(char fill_char) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            dungeon[y][x] = fill_char;
        }
    }
}

void draw_dungeon() {
    for (int y = 0; y < HEIGHT; y++) {
        printf("%s\n", dungeon[y]);
    }
}

void generate_rooms(int num_rooms) {
    int rooms_generated = 0;
    room_t rooms[MAX_ROOMS];
    while (rooms_generated < num_rooms) {
        room_t room;
        room.width = rand() % (MAX_SIZE - MIN_SIZE) + MIN_SIZE;
        room.height = rand() % (MAX_SIZE - MIN_SIZE) + MIN_SIZE;
        room.x = rand() % (WIDTH - room.width - 1) + 1;
        room.y = rand() % (HEIGHT - room.height - 1) + 1;
        if (is_within_boundaries(room)) {
            int overlaps = 0;
            for (int i = 0; i < rooms_generated; i++) {
                if (is_overlap(room, rooms[i])) {
                    overlaps = 1;
                    break;
                }
            }
            if (!overlaps) {
                create_room(room);
                rooms[rooms_generated++] = room;
            }
        }
    }
    generate_corridors(rooms, num_rooms);
}

void generate_corridors(room_t rooms[], int num_rooms) {
    for (int i = 0; i < num_rooms-1; i++) {
        connect_rooms(rooms[i], rooms[i+1]);
    }
}

void create_room(room_t room) {
    for (int y = room.y; y < room.y + room.height; y++) {
        for (int x = room.x; x < room.x + room.width; x++) {
            dungeon[y][x] = '.';
        }
    }
}

int is_overlap(room_t a, room_t b) {
    return a.x < b.x + b.width &&
           a.x + a.width > b.x &&
           a.y < b.y + b.height &&
           a.y + a.height > b.y;
}

int is_within_boundaries(room_t room) {
    return room.x > 0 &&
           room.x < WIDTH - room.width &&
           room.y > 0 &&
           room.y < HEIGHT - room.height;
}

void connect_rooms(room_t a, room_t b) {
    int x = a.x + a.width/2;
    int y = a.y + a.height/2;
    while (x != b.x + b.width/2) {
        x += (x < b.x + b.width/2) ? 1 : -1;
        dungeon[y][x] = '.';
    }
    while (y != b.y + b.height/2) {
        y += (y < b.y + b.height/2) ? 1 : -1;
        dungeon[y][x] = '.';
    }
}