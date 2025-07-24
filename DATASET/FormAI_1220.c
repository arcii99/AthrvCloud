//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int main() {
    srand(time(NULL));
    char canvas[HEIGHT][WIDTH];
    
    // initialize canvas with spaces
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }
    
    // generate random pixels
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int r = rand() % 10;
            if(r == 0) {
                canvas[i][j] = 'X'; // draw a pixel
            }
        }
    }
    
    // print canvas
    printf(" ");
    for(int i = 0; i < WIDTH; i++) {
        printf("_");
    }
    printf("\n");
    for(int i = 0; i < HEIGHT; i++) {
        printf("|");
        for(int j = 0; j < WIDTH; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("|\n");
    }
    printf(" ");
    for(int i = 0; i < WIDTH; i++) {
        printf("-");
    }
    printf("\n");
    
    return 0;
}