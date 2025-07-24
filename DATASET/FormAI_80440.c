//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: modular
#include<stdio.h>
#include<math.h>

// Compute the area of a triangle
float computeTriangleArea(float x1, float y1, float x2, float y2, float x3, float y3) {
    float a = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    float b = sqrt(pow(x3-x2,2) + pow(y3-y2,2));
    float c = sqrt(pow(x3-x1,2) + pow(y3-y1,2));
    float s = (a+b+c)/2;
    float area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
}

// Compute the length of a line segment
float computeLineLength(float x1, float y1, float x2, float y2) {
    float length = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    return length;
}

// Compute the distance between two points
float computePointDistance(float x1, float y1, float x2, float y2) {
    float distance = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    return distance;
}

int main() {
    float x1, y1, x2, y2, x3, y3;
    printf("Enter coordinates of the triangle: ");
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);

    float area = computeTriangleArea(x1, y1, x2, y2, x3, y3);
    printf("Area of the triangle is: %.2f\n", area);

    float length = computeLineLength(x1, y1, x2, y2);
    printf("Length of the line segment AB is: %.2f\n", length);

    float distance = computePointDistance(x2, y2, x3, y3);
    printf("Distance between point B and C is: %.2f\n", distance);

    return 0;
}