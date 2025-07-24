//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constants
#define WIDTH 40
#define HEIGHT 20
#define MAX_ROOMS 6
#define MIN_ROOM_SIZE 4
#define MAX_ROOM_SIZE 8

// structure to represent a room
typedef struct {
    int x, y;
    int width, height;
} Room;

// structure to represent the game world
typedef struct {
    char tiles[WIDTH][HEIGHT];
    Room rooms[MAX_ROOMS];
    int num_rooms;
} World;

// function to generate a random integer within a range
int rand_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

// function to create a room within the game world
void create_room(World *world, int x, int y, int width, int height) {
    int i, j;
    for (i = x; i < x + width; i++) {
        for (j = y; j < y + height; j++) {
            world->tiles[i][j] = '.';
        }
    }
    if (world->num_rooms < MAX_ROOMS) {
        Room room = {x, y, width, height};
        world->rooms[world->num_rooms++] = room;
    }
}

// function to generate the game world
void generate_world(World *world) {
    int i, j, k, x, y, width, height;
    // fill the world with wall tiles
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            world->tiles[i][j] = '#';
        }
    }
    // create some rooms
    for (k = 0; k < MAX_ROOMS * 5; k++) {
        width = rand_range(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        height = rand_range(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        x = rand_range(1, WIDTH - width - 1);
        y = rand_range(1, HEIGHT - height - 1);
        for (i = x - 1; i <= x + width; i++) {
            for (j = y - 1; j <= y + height; j++) {
                if (world->tiles[i][j] != '#') {
                    goto next;
                }
            }
        }
        create_room(world, x, y, width, height);
        next:;
    }
}

// function to print the game world
void print_world(World *world) {
    int i, j, k;
    // print the top border
    for (i = 0; i < WIDTH + 2; i++) {
        putchar('#');
    }
    putchar('\n');
    // print the world tiles
    for (j = 0; j < HEIGHT; j++) {
        putchar('#');
        for (i = 0; i < WIDTH; i++) {
            char tile = ' ';
            for (k = 0; k < world->num_rooms; k++) {
                if (i >= world->rooms[k].x && i < world->rooms[k].x + world->rooms[k].width &&
                    j >= world->rooms[k].y && j < world->rooms[k].y + world->rooms[k].height) {
                    tile = '.';
                }
            }
            putchar(tile);
        }
        putchar('#');
        putchar('\n');
    }
    // print the bottom border
    for (i = 0; i < WIDTH + 2; i++) {
        putchar('#');
    }
    putchar('\n');
}

// main function
int main() {
    // initialize the random number generator
    srand(time(NULL));
    // create the game world
    World world;
    generate_world(&world);
    // print the game world
    print_world(&world);
    return 0;
}