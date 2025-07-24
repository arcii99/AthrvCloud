//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <math.h>

float computePerimeter(float x1, float y1, float x2, float y2, float x3, float y3) {
    float side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    float side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    float side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    return side1 + side2 + side3;
}

int main() {
    float x1, y1, x2, y2, x3, y3;
    printf("Enter the x-coordinate and y-coordinate of point A: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the x-coordinate and y-coordinate of point B: ");
    scanf("%f %f", &x2, &y2);
    printf("Enter the x-coordinate and y-coordinate of point C: ");
    scanf("%f %f", &x3, &y3);
    float perimeter = computePerimeter(x1, y1, x2, y2, x3, y3);
    printf("The perimeter of the triangle with vertices A(%f, %f), B(%f, %f), C(%f, %f) is %f\n",
           x1, y1, x2, y2, x3, y3, perimeter);
    return 0;
}