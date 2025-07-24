//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 128
#define HEIGHT 64
#define MAX_PLANETS 10

void generate_planet(int x, int y) {
    int size = rand() % 10 + 1;
    for(int i = y - size; i <= y + size; i++) {
        for(int j = x - size; j <= x + size; j++) {
            if(i < 0 || j < 0 || i >= HEIGHT || j >= WIDTH) {
                continue;
            }
            putchar('#');
        }
        putchar('\n');
    }
}

int main() {
    srand(time(NULL));

    // generate star field
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            if(rand() % 100 < 1) {
                putchar('*');
            } else {
                putchar('.');
            }
        }
        putchar('\n');
    }

    // generate planets
    int num_planets = rand() % MAX_PLANETS + 1;
    for(int i = 0; i < num_planets; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        generate_planet(x, y);
    }

    return 0;
}