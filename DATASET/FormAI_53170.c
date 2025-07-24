//FormAI DATASET v1.0 Category: Fractal Generation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

char screen[SCREEN_HEIGHT][SCREEN_WIDTH];

// Define a recursive function to generate the fractal
void generate_fractal(int depth, double x, double y, double size, double angle) {
    // Base case: if the depth is 0, just draw a dot at the center of the square
    if (depth == 0) {
        int screen_x = (int) round(x);
        int screen_y = (int) round(y);
        if (screen_x >= 0 && screen_x < SCREEN_WIDTH && 
            screen_y >= 0 && screen_y < SCREEN_HEIGHT) {
            screen[screen_y][screen_x] = '*';
        }
        return;
    }
    
    // Define the coordinates of the corners of the square
    double x1 = x - size / 2;
    double y1 = y - size / 2;
    double x2 = x + size / 2;
    double y2 = y - size / 2;
    double x3 = x + size / 2;
    double y3 = y + size / 2;
    double x4 = x - size / 2;
    double y4 = y + size / 2;
    
    // Define the coordinates of the midpoint of each side of the square
    double xm1 = (x1 + x2) / 2;
    double ym1 = (y1 + y2) / 2;
    double xm2 = (x2 + x3) / 2;
    double ym2 = (y2 + y3) / 2;
    double xm3 = (x3 + x4) / 2;
    double ym3 = (y3 + y4) / 2;
    double xm4 = (x4 + x1) / 2;
    double ym4 = (y4 + y1) / 2;
    
    // Define the distance from the center of the square to each midpoint
    double d1 = sqrt(pow(x - xm1, 2) + pow(y - ym1, 2));
    double d2 = sqrt(pow(x - xm2, 2) + pow(y - ym2, 2));
    double d3 = sqrt(pow(x - xm3, 2) + pow(y - ym3, 2));
    double d4 = sqrt(pow(x - xm4, 2) + pow(y - ym4, 2));
    
    // Define the angle from the center of the square to each midpoint
    double a1 = angle - M_PI / 2;
    double a2 = angle;
    double a3 = angle + M_PI / 2;
    double a4 = angle + M_PI;
    
    // Call the generate_fractal function recursively on each smaller square
    generate_fractal(depth - 1, xm1 + d1 * cos(a1), ym1 + d1 * sin(a1), size / 2, a1);
    generate_fractal(depth - 1, xm2 + d2 * cos(a2), ym2 + d2 * sin(a2), size / 2, a2);
    generate_fractal(depth - 1, xm3 + d3 * cos(a3), ym3 + d3 * sin(a3), size / 2, a3);
    generate_fractal(depth - 1, xm4 + d4 * cos(a4), ym4 + d4 * sin(a4), size / 2, a4);
}

int main() {
    int depth;
    double x, y, size;
    
    // Get input from user
    printf("Enter the depth of the fractal: ");
    scanf("%d", &depth);
    printf("Enter the x coordinate of the center of the fractal: ");
    scanf("%lf", &x);
    printf("Enter the y coordinate of the center of the fractal: ");
    scanf("%lf", &y);
    printf("Enter the size of the fractal: ");
    scanf("%lf", &size);
    
    // Generate the fractal
    generate_fractal(depth, x, y, size, 0);
    
    // Print the fractal to the screen
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            putchar(screen[i][j] ? screen[i][j] : ' ');
        }
        putchar('\n');
    }
    
    return 0;
}