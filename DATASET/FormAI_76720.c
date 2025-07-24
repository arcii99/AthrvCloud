//FormAI DATASET v1.0 Category: Fractal Generation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Recursive function to plot the fractal pattern
void plotFractal(int x1, int y1, int x2, int y2, int depth) {
    
    // Base case
    if(depth == 0) {
        // Draw a line between x1,y1 and x2,y2
        printf("Draw line from (%d, %d) to (%d, %d)\n", x1, y1, x2, y2);
        return;
    }

    // Calculate midpoint (using integer division)
    int midX = (x1 + x2) / 2;
    int midY = (y1 + y2) / 2;
    
    // Calculate random value for variation in length
    int variation = rand() % 10;
    
    // Calculate length of horizontal and vertical segments
    int hLen = abs(x2 - x1);
    int vLen = abs(y2 - y1);
    
    // Plot the fractal pattern recursively
    plotFractal(x1, y1, midX, y1 + vLen/2 + variation, depth - 1);
    plotFractal(midX, y1 + vLen/2 + variation, midX + hLen/2 + variation, midY, depth - 1);
    plotFractal(midX + hLen/2 + variation, midY, midX, midY + vLen/2 + variation, depth - 1);
    plotFractal(midX, midY + vLen/2 + variation, x2, y2, depth - 1);
}

int main() {
    
    // Seed the random number generator
    srand(time(NULL));

    // Set up initial points of the fractal
    int x1 = 0;
    int y1 = 0;
    int x2 = 100;
    int y2 = 0;

    // Set the depth of the fractal pattern
    int depth = 5;

    // Plot the fractal pattern recursively
    plotFractal(x1, y1, x2, y2, depth);

    return 0;
}