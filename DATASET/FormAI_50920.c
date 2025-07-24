//FormAI DATASET v1.0 Category: Fractal Generation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800 // Width of the output image
#define HEIGHT 800 // Height of the output image

typedef struct {
    float x;
    float y;
} point;

void drawFractal(point p1, point p2, point p3, int n);

int main() {
    point p1 = {WIDTH/2, 0};
    point p2 = {0, HEIGHT};
    point p3 = {WIDTH, HEIGHT};

    // Draw the initial triangle
    drawFractal(p1, p2, p3, 5);

    return 0;
}

void drawFractal(point p1, point p2, point p3, int n) {
    if(n == 0) {
        // Base case: draw a line between the points
        printf("drawLine(%f,%f,%f,%f)\n", p1.x, p1.y, p2.x, p2.y);
        printf("drawLine(%f,%f,%f,%f)\n", p2.x, p2.y, p3.x, p3.y);
        printf("drawLine(%f,%f,%f,%f)\n", p1.x, p1.y, p3.x, p3.y);
    }
    else {
        // Calculate the midpoint of each side
        point mp1 = {(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
        point mp2 = {(p2.x + p3.x) / 2, (p2.y + p3.y) / 2};
        point mp3 = {(p3.x + p1.x) / 2, (p3.y + p1.y) / 2};

        // Draw the three inner triangles
        drawFractal(p1, mp1, mp3, n - 1);
        drawFractal(mp1, p2, mp2, n - 1);
        drawFractal(mp3, mp2, p3, n - 1);
    }
}