//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 10

int main() {

    char canvas[HEIGHT][WIDTH+1];
    srand(time(NULL));

    for(int y=0; y<HEIGHT; y++) {
        for(int x=0; x<WIDTH; x++) {
            int r = rand() % 2;
            if(r == 1) {
                canvas[y][x] = '#';
            } else {
                canvas[y][x] = ' ';
            }
        }
        canvas[y][WIDTH] = '\0'; // Null-terminate string
    }

    for(int y=0; y<HEIGHT; y++) {
        printf("%s\n", canvas[y]); // Print entire line at once
    }

    return 0;
}