//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

char map[HEIGHT][WIDTH+1];

void generate_map() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            map[i][j] = '#';
        }
        map[i][WIDTH] = '\0';
    }
    int x = WIDTH/2, y = HEIGHT/2;
    map[y][x] = '@';

    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        int rx = rand() % (WIDTH-2) + 1;
        int ry = rand() % (HEIGHT-2) + 1;
        if (rx == x && ry == y) {
            i--;
            continue;
        }
        map[ry][rx] = '*';
    }
}

void display_map() {
    system("cls"); // clear the console
    
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        printf("%s\n", map[i]);
    }
}

int main() {
    generate_map();
    display_map();
    return 0;
}