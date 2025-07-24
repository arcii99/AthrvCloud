//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

void generate_map(char map[][WIDTH]);
void print_map(char map[][WIDTH]);

int main(void) {
    char map[HEIGHT][WIDTH];

    srand(time(NULL));
    generate_map(map);

    print_map(map);

    return 0;
}

void generate_map(char map[][WIDTH]) {
    int i, j;

    // Fill map with walls
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            map[i][j] = '#';
        }
    }

    // Generate rooms
    for(i = 0; i < 10; i++) {
        int x = rand() % (WIDTH - 10) + 1;
        int y = rand() % (HEIGHT - 10) + 1;
        int w = rand() % 10 + 5;
        int h = rand() % 4 + 3;

        // Fill room with floors
        for(int m = y; m < y + h; m++) {
            for(int n = x; n < x + w; n++) {
                map[m][n] = '.';
            }
        }
    }
}

void print_map(char map[][WIDTH]) {
    int i, j;

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}