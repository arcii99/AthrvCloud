//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define WIDTH 20
#define HEIGHT 10

void drawMap(char map[HEIGHT][WIDTH]) {
    int i,j;
    for(i=0; i<HEIGHT; i++) {
        for(j=0; j<WIDTH; j++)
            printf("%c", map[i][j]);
        printf("\n");
    }
}

void generateMap(char map[HEIGHT][WIDTH]) {
    int i,j;
    srand(time(NULL));
    for(i=0; i<HEIGHT; i++)
        for(j=0; j<WIDTH; j++)
            map[i][j] = (rand()%2 == 0) ? '#' : '.';
}

int main() {
    char map[HEIGHT][WIDTH];

    generateMap(map);
    drawMap(map);

    return 0;
}