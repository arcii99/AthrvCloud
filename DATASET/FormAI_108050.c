//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100   // width of pixel art
#define HEIGHT 50   // height of pixel art

void generate_pixel_art(char art[HEIGHT][WIDTH]) {
    srand(time(NULL));   // set random seed
    
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            int color = rand() % 2;   // randomly choose between two colors
            if(color == 0) {
                art[i][j] = '0';    // black color
            } else {
                art[i][j] = '1';    // white color
            }
        }
    }
}

void print_pixel_art(char art[HEIGHT][WIDTH]) {
    printf("\nPixel Art:\n\n");
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char pixel_art[HEIGHT][WIDTH];
    generate_pixel_art(pixel_art);
    print_pixel_art(pixel_art);
    return 0;
}