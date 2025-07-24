//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: invasive
#include <stdio.h>
#include <math.h>

// Function to find the distance between two points
float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to find the area of a triangle given three sides
float area(float a, float b, float c) {
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    float x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of three points\n");
    scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3);

    // Find the length of the three sides of the triangle
    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x3, y3, x1, y1);

    // Check if a triangle is valid or not
    if (a + b > c && b + c > a && c + a > b) {
        printf("The perimeter of the triangle is %f units\n", a + b + c);
        printf("The area of the triangle is %f square units\n", area(a, b, c));
    } else {
        printf("Invalid triangle. The entered coordinates do not form a triangle.\n");
    }

    return 0;
}