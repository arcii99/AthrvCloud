//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define ROOM_MAX_SIZE 6
#define ROOM_MIN_SIZE 3
#define MAX_ROOMS 5

/* Define a structure for our rooms */
typedef struct {
    int x, y, width, height;
} Room;

/* Define a structure for our map */
typedef struct {
    int tiles[MAP_HEIGHT][MAP_WIDTH];
    Room rooms[MAX_ROOMS];
} Map;

/* Function declarations */
void generate_map(Map *map);
void print_map(Map *map);

int main() {
    Map map;
    srand(time(NULL));
    generate_map(&map);
    print_map(&map);
    return 0;
}

void generate_map(Map *map) {
    int i, j, k;
    /* Fill the map with walls initially */
    for(i = 0; i < MAP_HEIGHT; i++) {
        for(j = 0; j < MAP_WIDTH; j++) {
            map->tiles[i][j] = 1;
        }
    }

    /* Construct the rooms */
    int num_rooms = 0;
    for(i = 0; i < MAX_ROOMS; i++) {
        int w = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE) + ROOM_MIN_SIZE;
        int h = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE) + ROOM_MIN_SIZE;
        int x = rand() % (MAP_WIDTH - w - 1) + 1;
        int y = rand() % (MAP_HEIGHT - h - 1) + 1;

        /* Check if the current room intersects with any others */
        int intersect = 0;
        for(j = 0; j < num_rooms; j++) {
            if(x < map->rooms[j].x + map->rooms[j].width &&
               x + w > map->rooms[j].x &&
               y < map->rooms[j].y + map->rooms[j].height &&
               y + h > map->rooms[j].y) {
                intersect = 1;
                break;
            }
        }

        /* If there is no intersection, place the room */
        if(!intersect) {
            Room room = {x, y, w, h};
            map->rooms[num_rooms] = room;
            num_rooms++;
        }
    }

    /* Place the rooms on the map */
    for(i = 0; i < num_rooms; i++) {
        for(j = map->rooms[i].y; j < map->rooms[i].y + map->rooms[i].height; j++) {
            for(k = map->rooms[i].x; k < map->rooms[i].x + map->rooms[i].width; k++) {
                map->tiles[j][k] = 0;
            }
        }
    }
}

void print_map(Map *map) {
    int i, j;
    for(i = 0; i < MAP_HEIGHT; i++) {
        for(j = 0; j < MAP_WIDTH; j++) {
            if(map->tiles[i][j] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}