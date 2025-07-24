//FormAI DATASET v1.0 Category: Fractal Generation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

void createFractal(char display[][WIDTH+1], int startX, int startY, int endX, int endY, int depth);

int main()
{
    char display[HEIGHT][WIDTH+1];
    int i, j;
    srand(time(NULL));

    // Generate random starting colors for the fractal
    char colors[] = {'#', '&', '%', '$', '@'};
    char color1 = colors[rand() % 5];
    char color2 = colors[rand() % 5];
    while (color2 == color1)  // Make sure the second color is different from the first
        color2 = colors[rand() % 5];

    // Create the initial display
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (rand() % 2 == 0)
                display[i][j] = color1;
            else
                display[i][j] = color2;
        }
        display[i][WIDTH] = '\0';   // Null-terminate each row
    }

    // Recursively create the fractal
    createFractal(display, 0, 0, WIDTH-1, HEIGHT-1, 5);

    // Display the final result
    for (i = 0; i < HEIGHT; i++)
        printf("%s\n", display[i]);

    return 0;
}

// Recursive function to create the fractal
void createFractal(char display[][WIDTH+1], int startX, int startY, int endX, int endY, int depth)
{
    if (depth == 0)   // Base case: stop recursion
        return;

    int midX = (startX + endX) / 2;
    int midY = (startY + endY) / 2;
    char color = display[midY][midX];  // Get the color of the middle pixel

    // Create the diamond shape
    display[startY][midX] = color;
    display[endY][midX] = color;
    display[midY][startX] = color;
    display[midY][endX] = color;

    // Create the square shapes
    createFractal(display, startX, startY, midX, midY, depth-1);
    createFractal(display, midX, startY, endX, midY, depth-1);
    createFractal(display, startX, midY, midX, endY, depth-1);
    createFractal(display, midX, midY, endX, endY, depth-1);
}