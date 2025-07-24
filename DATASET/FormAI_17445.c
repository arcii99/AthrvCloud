//FormAI DATASET v1.0 Category: Fractal Generation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 30

int world[WIDTH][HEIGHT];

void setValues() {
    srand((unsigned)time(NULL));

    int i, j;
    for(i=0; i<WIDTH; i++) {
        for(j=0; j<HEIGHT; j++) {
            world[i][j] = rand() % 2;
        }
    }
}

void draw() {
    int i, j;
    for(i=0; i<WIDTH; i++) {
        for(j=0; j<HEIGHT; j++) {
            printf("%c", world[i][j] == 1 ? '*' : ' ');
        }
        printf("\n");
    }
}

int countNeighbors(int x, int y) {
    int neighbors = 0;

    int i, j;
    for(i=-1; i<=1; i++) {
        for(j=-1; j<=1; j++) {
            if(i == 0 && j == 0) {
                continue;
            }

            int checkX = x + i;
            int checkY = y + j;

            if(checkX >= 0 && checkX < WIDTH && checkY >= 0 && checkY < HEIGHT) {
                neighbors += world[checkX][checkY];
            }
        }
    }

    return neighbors;
}

void simulate() {
    int newWorld[WIDTH][HEIGHT];

    int i, j;
    for(i=0; i<WIDTH; i++) {
        for(j=0; j<HEIGHT; j++) {
            int neighbors = countNeighbors(i, j);

            if(world[i][j] == 1) {
                if(neighbors < 2 || neighbors > 3) {
                    newWorld[i][j] = 0;
                } else {
                    newWorld[i][j] = 1;
                }
            } else {
                if(neighbors == 3) {
                    newWorld[i][j] = 1;
                } else {
                    newWorld[i][j] = 0;
                }
            }
        }
    }

    for(i=0; i<WIDTH; i++) {
        for(j=0; j<HEIGHT; j++) {
            world[i][j] = newWorld[i][j];
        }
    }
}

int main() {
    setValues();

    int generation = 0;

    while (generation <= 20) {
        printf("Generation: %d\n", generation);
        draw();
        simulate();
        generation++;
    }

    return 0;
}