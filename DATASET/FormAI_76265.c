//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: active
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle using Heron's formula
float herons_formula(float a, float b, float c) {
    float s = (a + b + c) / 2.0; // s = half of the triangle's perimeter
    return sqrt(s * (s - a) * (s - b) * (s - c)); // Heron's formula
}

// Function to calculate the distance between two points in 2D space
float distance_between_points(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    float a, b, c, x1, y1, x2, y2;
    printf("Enter three sides of a triangle: ");
    scanf("%f%f%f", &a, &b, &c);
    printf("The area of the triangle is: %f\n", herons_formula(a, b, c));
    printf("Enter the coordinates of two points: ");
    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
    printf("The distance between the two points is: %f\n", distance_between_points(x1, y1, x2, y2));
    return 0;
}