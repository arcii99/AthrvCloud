//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

void display(char map[HEIGHT][WIDTH]) {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void generateMap(char map[HEIGHT][WIDTH]) {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            if(rand() % 10 == 0) {
                map[i][j] = '#';
            }
            else {
                map[i][j] = '.';
            }
        }
    }
}

int main() {
    srand(time(NULL));
    char map[HEIGHT][WIDTH];
    generateMap(map);
    display(map);
    return 0;
}