//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include <stdio.h>
#include <math.h>

float distance(float x1, float y1, float x2, float y2) {
    float dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return dist;
}

int main() {
    float x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of three points (in order x1 y1 x2 y2 x3 y3):\n");
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);
    
    // Calculate the sides of the triangle
    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x3, y3, x1, y1);
    
    // Calculate the semiperimeter
    float s = (a + b + c) / 2;
    
    // Calculate the area using Heron's formula
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    printf("The area of the triangle is %f\n", area);

    // Check if the points are collinear
    float slope1 = (y2 - y1) / (x2 - x1);
    float slope2 = (y3 - y2) / (x3 - x2);
    if (slope1 == slope2) {
        printf("The three points are collinear\n");
    } else {
        printf("The three points are not collinear\n");
    }
    return 0;
}