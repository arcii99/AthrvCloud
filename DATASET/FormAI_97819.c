//FormAI DATASET v1.0 Category: Fractal Generation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24


void generate_fractal(char map[HEIGHT][WIDTH], float scale, int iterations) {
    float center_x = (float) WIDTH / 2;
    float center_y = (float) HEIGHT / 2;
    
    // Initialize map with white pixels
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = ' ';
        }
    }
    
    // Generate fractal
    float x, y;
    for (int i = 0; i < iterations; i++) {
        x = (float) rand() / RAND_MAX * WIDTH;
        y = (float) rand() / RAND_MAX * HEIGHT;

        for (int j = 0; j < 100; j++) {
            float rand_angle = (float) rand() / RAND_MAX * 2 * M_PI;
            x += cos(rand_angle) * scale;
            y -= sin(rand_angle) * scale;
            
            // If out of bounds, break
            if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
                break;
            }
            
            // Set pixel
            map[(int) floor(y)][(int) floor(x)] = '*';
        }
    }
}


int main() {
    char map[HEIGHT][WIDTH];
    
    generate_fractal(map, 2, 50);
    
    // Print map
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}