//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: realistic
#include <stdlib.h>
#include <stdio.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 25

/** STRUCTS **/
typedef struct Point {
    int x;
    int y;
} Point;

/** FUNCTION PROTOTYPES **/
void generateMap(char map[][MAP_WIDTH]);
void drawMap(char map[][MAP_WIDTH]);
Point getRandomLocation(char map[][MAP_WIDTH]);

int main() {
    char map[MAP_HEIGHT][MAP_WIDTH];

    // generate map
    generateMap(map);

    // draw map
    drawMap(map);

    // get random location
    Point player = getRandomLocation(map);

    // print player position
    printf("Player starting position: (%d, %d)\n", player.x, player.y);

    return 0;
}

/**
 * Generates a random map using procedural generation
 *
 * @param map the map to be generated
 */
void generateMap(char map[][MAP_WIDTH]) {
    // fill map with random terrain types
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            map[y][x] = rand() % 2 == 0 ? '.' : '#';
        }
    }

    // add wall border
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        map[y][0] = '#';
        map[y][MAP_WIDTH - 1] = '#';
    }

    for (int x = 0; x < MAP_WIDTH; ++x) {
        map[0][x] = '#';
        map[MAP_HEIGHT - 1][x] = '#';
    }
}

/**
 * Draws the map to stdout
 *
 * @param map the map to be drawn
 */
void drawMap(char map[][MAP_WIDTH]) {
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

/**
 * Returns a random reachable location on the map
 *
 * @param map the map to be searched for a valid location
 * @return a Point containing the x and y coordinates of the location
 */
Point getRandomLocation(char map[][MAP_WIDTH]) {
    Point location;

    do {
        location.x = rand() % MAP_WIDTH;
        location.y = rand() % MAP_HEIGHT;
    } while (map[location.y][location.x] == '#');

    return location;
}