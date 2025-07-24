//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 30

int main(){
    // Seed random number generator
    srand(time(0));

    // Generate random pixel art
    int art[HEIGHT][WIDTH];
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            art[i][j] = rand() % 2;
        }
    }

    // Print heart-shaped pixel art
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if((i == 9 && (j == 16 || j == 23)) ||
               (i >= 6 && i <= 9 && j >= 13 && j <= 26 && (i+j)%2 == 0) ||
               (i >= 10 && i <= 16 && j >= 10 && j <= 29 && (((i+j) >= 27 && (i+j) <= 37) || ((j-i) >= 2 && (j-i) <= 12))) ||
               (i >= 10 && i <= 16 && j >= 10 && j <= 29 && (((i+j) >= 13 && (i+j) <= 23) || ((j-i) >= -12 && (j-i) <= -2)))){
                printf("*");
            }
            else{
                printf("%c", art[i][j] ? '#' : ' ');
            }
        }
        printf("\n");
    }

    return 0;
}