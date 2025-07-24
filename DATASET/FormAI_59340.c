//FormAI DATASET v1.0 Category: Fractal Generation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    double x;
    double y;
} Point;

int main() {
    srand(time(NULL));

    // Initialize the screen buffer
    char buffer[HEIGHT][WIDTH+1];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            buffer[i][j] = ' ';
        }
        buffer[i][WIDTH] = '\0';
    }

    // Start with a single point
    Point p = {WIDTH/2, HEIGHT/2};

    // Generate points in a fractal pattern
    for (int i = 0; i < WIDTH*HEIGHT; i++) {
        // Random movement
        double angle = (double)rand() / RAND_MAX * M_PI * 2;
        double distance = (double)rand() / RAND_MAX * 10;
        
        // Move the point
        p.x += cos(angle) * distance;
        p.y += sin(angle) * distance;

        // Bound the point within the screen
        if (p.x < 0) p.x = 0;
        if (p.y < 0) p.y = 0;
        if (p.x >= WIDTH) p.x = WIDTH-1;
        if (p.y >= HEIGHT) p.y = HEIGHT-1;

        // Print the character at the point
        buffer[(int)p.y][(int)p.x] = '.';
    }

    // Print the buffer to the screen
    for (int i = 0; i < HEIGHT; i++) {
        printf("%s\n", buffer[i]);
    }

    return 0;
}