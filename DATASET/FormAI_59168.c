//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

char map[HEIGHT][WIDTH];

void generate_map() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (rand() % 100 < 40) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }
}

void print_map() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    generate_map();
    print_map();
    return 0;
}