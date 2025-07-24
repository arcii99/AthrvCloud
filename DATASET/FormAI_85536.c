//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

char pixel[HEIGHT][WIDTH];

void clear_screen() {
    system("clear");
}

void draw_pixel(int x, int y) {
    pixel[y][x] = '#';
}

void render_screen() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", pixel[i][j]);
        }
        printf("\n");
    }
}

void generate_pixel_art() {
    // randomize seed based on current time
    srand((unsigned int) time(NULL));
    
    // randomly draw pixels
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (rand() % 2 == 0) {
                draw_pixel(j, i);
            }
        }
    }
}

int main() {
    int frames = 20;
    
    // generate and display pixel art for several frames
    for (int f = 0; f < frames; f++) {
        // clear screen and pixel array
        clear_screen();
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                pixel[i][j] = ' ';
            }
        }
        
        // generate new pixel art and render screen
        generate_pixel_art();
        render_screen();
        
        // pause briefly before displaying next frame
        usleep(100000);
    }
    
    return 0;
}