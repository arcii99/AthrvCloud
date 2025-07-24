//FormAI DATASET v1.0 Category: Fractal Generation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 30

void print_map(char map[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void rec_diamond_square(char map[HEIGHT][WIDTH], int x1, int y1, int x2, int y2, int divide, float roughness) {
    if (divide < 1) return;

    // Calculate midpoint
    int midx = (x1 + x2) / 2;
    int midy = (y1 + y2) / 2;

    // Diamond Step
    float average_diamond = (map[y1][x1] + map[y1][x2] + map[y2][x1] + map[y2][x2]) / 4;
    float noise_diamond = ((double)rand() / (double)RAND_MAX) * divide * roughness;
    map[midy][midx] = average_diamond + noise_diamond;

    // Square Step (North)
    float average_north = (map[y1][midx] + map[midy][x1] + map[midy][x2]) / 3;
    float noise_north = ((double)rand() / (double)RAND_MAX) * divide * roughness;
    map[y1][midx] = average_north + noise_north;

    // Square Step (South)
    float average_south = (map[y2][midx] + map[midy][x1] + map[midy][x2]) / 3;
    float noise_south = ((double)rand() / (double)RAND_MAX) * divide * roughness;
    map[y2][midx] = average_south + noise_south;

    // Square Step (West)
    float average_west = (map[midy][x1] + map[y1][midx] + map[y2][midx]) / 3;
    float noise_west = ((double)rand() / (double)RAND_MAX) * divide * roughness;
    map[midy][x1] = average_west + noise_west;

    // Square Step (East)
    float average_east = (map[midy][x2] + map[y1][midx] + map[y2][midx]) / 3;
    float noise_east = ((double)rand() / (double)RAND_MAX) * divide * roughness;
    map[midy][x2] = average_east + noise_east;

    // Recurse
    rec_diamond_square(map, x1, y1, midx, midy, divide / 2, roughness);
    rec_diamond_square(map, midx, y1, x2, midy, divide / 2, roughness);
    rec_diamond_square(map, x1, midy, midx, y2, divide / 2, roughness);
    rec_diamond_square(map, midx, midy, x2, y2, divide / 2, roughness);
}

int main() {
    srand(time(NULL));

    // Create the map and initialize corners to random values
    char map[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = 32;
        }
    }
    map[0][0] = rand() % 256;
    map[0][WIDTH-1] = rand() % 256;
    map[HEIGHT-1][0] = rand() % 256;
    map[HEIGHT-1][WIDTH-1] = rand() % 256;

    // Recursively generate the fractal
    rec_diamond_square(map, 0, 0, WIDTH-1, HEIGHT-1, WIDTH, 0.5);

    // Print the map
    print_map(map);

    return 0;
}