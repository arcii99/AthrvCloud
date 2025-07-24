//FormAI DATASET v1.0 Category: Fractal Generation ; Style: real-life
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

void generateFractal(Point topLeft, Point bottomRight, int depth);

int main() {
    // Initialize random seed
    srand(time(NULL));
    // Generate fractal
    Point topLeft = { -2.0, 2.0 };
    Point bottomRight = { 2.0, -2.0 };
    generateFractal(topLeft, bottomRight, 5);
    return 0;
}

void generateFractal(Point topLeft, Point bottomRight, int depth) {
    // Determine width and height of area
    double width = bottomRight.x - topLeft.x;
    double height = topLeft.y - bottomRight.y;
    // Base case: draw rectangle
    if (depth == 0) {
        printf("Draw rectangle from (%f, %f) to (%f, %f)\n", topLeft.x, topLeft.y, bottomRight.x, bottomRight.y);
    }
    // Recursive case: divide area into 4 quadrants and generate each quadrant's fractal
    else {
        // Calculate midpoint of area
        Point midPoint = { topLeft.x + width/2, bottomRight.y + height/2 };
        // Determine random displacement for midpoint
        double displacement = pow(2, -depth);
        double xDisplacement = (double)rand()/(double)RAND_MAX * displacement * width * 2 - displacement * width;
        double yDisplacement = (double)rand()/(double)RAND_MAX * displacement * height * 2 - displacement * height;
        Point displacedMidpoint = { midPoint.x + xDisplacement, midPoint.y + yDisplacement };
        // Divide area into quadrants and generate each quadrant's fractal
        generateFractal(topLeft, displacedMidpoint, depth - 1);
        generateFractal((Point){ displacedMidpoint.x, topLeft.y }, (Point){ bottomRight.x, displacedMidpoint.y }, depth - 1);
        generateFractal((Point){ topLeft.x, displacedMidpoint.y }, (Point){ displacedMidpoint.x, bottomRight.y }, depth - 1);
        generateFractal(displacedMidpoint, bottomRight, depth - 1);
    }
}