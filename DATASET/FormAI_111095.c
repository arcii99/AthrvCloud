//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

/* Define the cell struct */
typedef struct {
    char type;          // The type of the cell ('.' for floor and '#' for wall)
    int hardness;       // The hardness of the cell (0 for floor and 1-9 for walls)
} cell_t;

/* Initialize the map with walls */
void init_map(cell_t map[][WIDTH]) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            map[y][x].type = '#';
            map[y][x].hardness = rand() % 9 + 1;
        }
    }
}

/* Generate the rooms */
void generate_rooms(cell_t map[][WIDTH]) {
    int num_rooms = rand() % 6 + 4;      // Random number of rooms (between 4 and 9)
    int i;

    for (i = 0; i < num_rooms; i++) {
        int w = rand() % 10 + 5;    // Random width (between 5 and 14)
        int h = rand() % 5 + 3;     // Random height (between 3 and 7)
        int x = rand() % (WIDTH - w - 2) + 1;      // Random X position (between 1 and WIDTH-1-w)
        int y = rand() % (HEIGHT - h - 2) + 1;     // Random Y position (between 1 and HEIGHT-1-h)

        int j, k;
        for (j = x; j < x + w; j++) {
            for (k = y; k < y + h; k++) {
                map[k][j].type = '.';
                map[k][j].hardness = 0;
            }
        }
    }
}

/* Print the map */
void print_map(cell_t map[][WIDTH]) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%c", map[y][x].type);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));      // Seed the random number generator
    cell_t map[HEIGHT][WIDTH];
    init_map(map);
    generate_rooms(map);
    print_map(map);
    return 0;
}