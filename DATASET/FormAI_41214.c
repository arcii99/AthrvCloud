//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 10

void printMap(int map[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void generateMap(int map[HEIGHT][WIDTH])
{
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int value = rand() % 2; // randomly generate 0 or 1
            map[i][j] = value;
        }
    }
}

int main()
{
    int map[HEIGHT][WIDTH];

    generateMap(map);
    printMap(map);

    return 0;
}