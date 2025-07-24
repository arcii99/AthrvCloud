//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HEIGHT 10
#define WIDTH 10

void printPixel(char pixel[HEIGHT][WIDTH]) {
    for (int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%c", pixel[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0)); // seed for random function
    char pixel[HEIGHT][WIDTH];
    // generate pixel art
    for (int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            int randomNum = rand() % 3; // generate values from 0 to 2
            switch(randomNum) {
                case 0:
                    pixel[i][j] = '#'; // black block
                    break;
                case 1:
                    pixel[i][j] = ' '; // white block
                    break;
                case 2:
                    pixel[i][j] = '+'; // gray block
                    break;
            }
        }
    }
    printPixel(pixel); // print generated pixel art
    return 0;
}