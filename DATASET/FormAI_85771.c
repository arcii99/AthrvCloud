//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: portable
#include <stdio.h>
#include <math.h>

// A function to calculate the area of a triangle given three points
float area(float x1, float y1, float x2, float y2, float x3, float y3) {
    float a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    float b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    float c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    float s = (a + b + c) / 2;
    float ar = sqrt(s * (s - a) * (s - b) * (s - c));
    return ar;
}

int main() {
    // Sample points
    float x1 = 0, y1 = 0;
    float x2 = 1, y2 = 0;
    float x3 = 0, y3 = 1;
    
    // Calculate area of the triangle
    float ar = area(x1, y1, x2, y2, x3, y3);
    printf("Area of triangle with points (%f, %f), (%f, %f), and (%f, %f) is %f", x1, y1, x2, y2, x3, y3, ar);

    return 0;
}