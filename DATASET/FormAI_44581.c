//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Donald Knuth
/* 
 * This program generates unique C Pixel Art using random numbers and algorithms.
 * Written by [Your Name] in Donald Knuth style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// size of the pixel art
#define HEIGHT 10
#define WIDTH 10

// function to generate a random integer between min and max (inclusive)
int rand_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

// function to set a random color for a pixel
void set_color(int x, int y, char pixel[HEIGHT][WIDTH]) {
    switch(rand_int(0, 4)) {
        case 0: pixel[x][y] = ' '; break; // white
        case 1: pixel[x][y] = '.'; break; // light gray
        case 2: pixel[x][y] = 'x'; break; // dark gray
        case 3: pixel[x][y] = '+'; break; // yellow
        case 4: pixel[x][y] = '#'; break; // red
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    char pixel[HEIGHT][WIDTH]; // 2D array to hold the pixel art
    
    // generate the pixel art
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            set_color(i, j, pixel);
        }
    }
    
    // display the pixel art
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%c ", pixel[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}