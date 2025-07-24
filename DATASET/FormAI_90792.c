//FormAI DATASET v1.0 Category: Fractal Generation ; Style: active
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 80     // Width of the console
#define HEIGHT 24    // Height of the console
#define INTENSITY 60 // Intensity threshold for coloring pixels

// Function to generate a random float between min and max
float randf(float min, float max)
{
    return min + (max - min) * ((float)rand() / (float)RAND_MAX);
}

// Main function to generate the fractal
void generateFractal(float x1, float y1, float x2, float y2, int depth)
{
    // Base case
    if (depth == 0)
        return;

    // Generate random points inside the box
    float xA = randf(x1, x2);
    float yA = randf(y1, y2);
    float xB = randf(x1, x2);
    float yB = randf(y1, y2);
    float xC = randf(x1, x2);
    float yC = randf(y1, y2);

    // Draw the triangle formed by the random points
    printf("line %d,%d %d,%d %d,%d\n", (int)(xA * WIDTH), (int)(yA * HEIGHT), (int)(xB * WIDTH), (int)(yB * HEIGHT), (int)(xC * WIDTH), (int)(yC * HEIGHT));

    // Generate the 3 smaller triangles
    generateFractal(xA, yA, xB, yB, depth - 1);
    generateFractal(xA, yA, xC, yC, depth - 1);
    generateFractal(xB, yB, xC, yC, depth - 1);
}

int main()
{
    // Initialize pseudo-random number generator
    srand((unsigned int)time(NULL));

    // Print header
    printf("canvas %d %d\n", WIDTH, HEIGHT);
    printf("color 255 255 255\n");
    printf("clear\n");

    // Generate the fractal
    generateFractal(0, 0, 1, 1, 5);

    // Generate random colors and color the pixels
    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;
            printf("color %d %d %d\n", r, g, b);
            printf("point %d %d\n", x, y);
        }
    }

    // Print footer
    printf("show\n");

    // Exit program
    return 0;
}