//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

void generate_pixel_art(int pixels[WIDTH][HEIGHT]) {
    // Generate a random pixel art
    
    srand(time(NULL));
    
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            int color = rand() % 6;
            pixels[i][j] = color;
        }
    }
}

void render_pixel_art(int pixels[WIDTH][HEIGHT]) {
    // Render the pixel art to the console
    
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            switch(pixels[i][j]) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf(":");
                    break;
                case 3:
                    printf("o");
                    break;
                case 4:
                    printf("O");
                    break;
                case 5:
                    printf("X");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    int pixels[WIDTH][HEIGHT];
    
    generate_pixel_art(pixels);
    render_pixel_art(pixels);
    
    return 0;
}