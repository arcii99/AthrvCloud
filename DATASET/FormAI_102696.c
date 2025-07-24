//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define COLORS 4

int main(){

    char* pixels[HEIGHT];
    int i, j, k;

    // Allocate memory for each row
    for(i=0; i<HEIGHT; i++){
        pixels[i] = (char*)malloc(sizeof(char)*WIDTH);
    }

    // Randomly generate pixel art
    srand(time(NULL));
    for(i=0; i<HEIGHT; i++){
        for(j=0; j<WIDTH; j++){
            pixels[i][j] = (char)('0' + rand()%COLORS);
        }
    }

    // Print the pixel art
    for(i=0; i<HEIGHT; i++){
        for(j=0; j<WIDTH; j++){
            switch(pixels[i][j]){
                case '0': printf("\e[48;5;231m  "); break;
                case '1': printf("\e[48;5;201m  "); break;
                case '2': printf("\e[48;5;93m  "); break;
                case '3': printf("\e[48;5;229m  "); break;
            }
        }
        printf("\e[m\n");
    }

    // Free allocated memory
    for(i=0; i<HEIGHT; i++){
        free(pixels[i]);
    }

    return 0;
}