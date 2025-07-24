//FormAI DATASET v1.0 Category: Fractal Generation ; Style: systematic
#include <stdio.h>

// Define Constants (Change these to create different fractals)
#define WIDTH         120
#define HEIGHT        40
#define MAX_ITER      64
#define CENTER_X      -0.5
#define CENTER_Y      0.0
#define SCALE_FACTOR  3.0

// Functions
int mandelbrot(double x0, double y0) {
    double x = 0.0;
    double y = 0.0;
    int i = 0;
    while (x*x + y*y < 4.0 && i < MAX_ITER) {
        double xt = x*x - y*y + x0;
        y = 2.0 * x*y + y0;
        x = xt;
        i++;
    }
    return i;
}

// Main Function
int main() {
    // Initialize Variables
    double x, y;
    int color;
    
    // Loop through each row
    for (int j = 0; j < HEIGHT; j++) {
        // Loop through each column
        for (int i = 0; i < WIDTH; i++) {
            // Calculate the coordinates of the current point in the complex plane
            x = ((double)i - (double)WIDTH/2.0) * SCALE_FACTOR / (double)WIDTH + CENTER_X;
            y = ((double)j - (double)HEIGHT/2.0) * SCALE_FACTOR / (double)HEIGHT + CENTER_Y;

            // Calculate the color of the current point based on the Mandelbrot set
            color = mandelbrot(x, y);

            // Print the color code to the console
            if (color == MAX_ITER) {
                printf(" ");
            } else {
                printf("%c", 'A' + (color % 26));
            }
        }
        
        // Print a new line at the end of each row
        printf("\n");
    }
    
    return 0;
}