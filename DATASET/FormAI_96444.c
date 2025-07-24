//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 80
#define MAP_HEIGHT 20
#define MAX_ROOMS 10
#define MAX_ROOM_SIZE 10
#define MIN_ROOM_SIZE 5

typedef struct {
    int x;
    int y;
    int width;
    int height;
} room_t;

char map[MAP_HEIGHT][MAP_WIDTH];

void init_map();
void generate_rooms(room_t *rooms, int num_rooms);
void connect_rooms(room_t *rooms, int num_rooms);
void print_map();

int main() {
    srand(time(NULL));
    
    room_t rooms[MAX_ROOMS];
    int num_rooms = rand() % MAX_ROOMS + 1;
    
    generate_rooms(rooms, num_rooms);
    connect_rooms(rooms, num_rooms);
    print_map();
    
    return 0;
}

void init_map() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = '#';
        }
    }
}

void generate_rooms(room_t *rooms, int num_rooms) {
    for (int i = 0; i < num_rooms; i++) {
        rooms[i].width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        rooms[i].height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
        rooms[i].x = rand() % (MAP_WIDTH - rooms[i].width - 1) + 1;
        rooms[i].y = rand() % (MAP_HEIGHT - rooms[i].height - 1) + 1;
        
        for (int j = 0; j < i; j++) {
            if (rooms_overlap(rooms[i], rooms[j])) {
                i--;
                break;
            }
        }
    }
    
    for (int i = 0; i < num_rooms; i++) {
        for (int y = rooms[i].y; y < rooms[i].y + rooms[i].height; y++) {
            for (int x = rooms[i].x; x < rooms[i].x + rooms[i].width; x++) {
                map[y][x] = '.';
            }
        }
    }
}

int rooms_overlap(room_t room1, room_t room2) {
    if (room1.x + room1.width < room2.x ||
        room1.x > room2.x + room2.width ||
        room1.y + room1.height < room2.y ||
        room1.y > room2.y + room2.height) {
        return 0;
    }
    
    return 1;
}

void connect_rooms(room_t *rooms, int num_rooms) {
    for (int i = 0; i < num_rooms - 1; i++) {
        int x1 = rooms[i].x + rand() % rooms[i].width;
        int y1 = rooms[i].y + rand() % rooms[i].height;
        int x2 = rooms[i + 1].x + rand() % rooms[i + 1].width;
        int y2 = rooms[i + 1].y + rand() % rooms[i + 1].height;
        
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

void print_map() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}