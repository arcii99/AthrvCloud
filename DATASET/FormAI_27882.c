//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define MAX_ROOM_SIZE 6
#define MIN_ROOM_SIZE 3

struct Room {
    int x;
    int y;
    int width;
    int height;
};

char map[MAP_HEIGHT][MAP_WIDTH];

void generate_map() {
    // initialize map to all walls
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }

    // generate rooms
    srand(time(NULL));
    int num_rooms = rand() % 5 + 5;
    struct Room rooms[num_rooms];

    for (int i = 0; i < num_rooms; i++) {
        int room_width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE) + MIN_ROOM_SIZE;
        int room_height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE) + MIN_ROOM_SIZE;
        int room_x = rand() % (MAP_WIDTH - room_width - 1) + 1;
        int room_y = rand() % (MAP_HEIGHT - room_height - 1) + 1;

        // check if room intersects with existing room
        for (int j = 0; j < i; j++) {
            if (room_x < rooms[j].x + rooms[j].width &&
                room_x + room_width > rooms[j].x &&
                room_y < rooms[j].y + rooms[j].height &&
                room_y + room_height > rooms[j].y) {
                    // rooms intersect, try again
                    i--;
                    break;
            }
        }

        // add room to map
        for (int y = room_y; y < room_y+room_height; y++) {
            for (int x = room_x; x < room_x+room_width; x++) {
                map[y][x] = '.';
            }
        }

        rooms[i].x = room_x;
        rooms[i].y = room_y;
        rooms[i].width = room_width;
        rooms[i].height = room_height;
    }

    // connect rooms with corridors
    for (int i = 0; i < num_rooms-1; i++) {
        int x = rooms[i].x + rooms[i].width/2;
        int y = rooms[i].y + rooms[i].height/2;
        int target_x = rooms[i+1].x + rooms[i+1].width/2;
        int target_y = rooms[i+1].y + rooms[i+1].height/2;

        while (x != target_x || y != target_y) {
            if (x < target_x) {
                x++;
            } else if (x > target_x) {
                x--;
            }

            if (y < target_y) {
                y++;
            } else if (y > target_y) {
                y--;
            }

            map[y][x] = '.';
        }
    }
}

void print_map() {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
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