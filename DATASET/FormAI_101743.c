//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: real-life
#include <stdio.h>
#include <math.h>

// Define a structure to store the coordinates of a point
struct Point {
    float x;
    float y;
};

// Define a function to calculate the distance between two points
float distance(struct Point p1, struct Point p2) {
    return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

// Define a function to calculate the area of a triangle given its three sides
float areaTriangle(float a, float b, float c) {
    // Heron's formula
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Define a function to calculate the perimeter of a triangle given its three sides
float perimeterTriangle(float a, float b, float c) {
    return a + b + c;
}

int main() {
    // Declare three points to form a triangle
    struct Point p1, p2, p3;

    // Input the coordinates of the three points
    printf("Enter the coordinates of point 1: ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Enter the coordinates of point 2: ");
    scanf("%f %f", &p2.x, &p2.y);

    printf("Enter the coordinates of point 3: ");
    scanf("%f %f", &p3.x, &p3.y);

    // Calculate the lengths of the three sides of the triangle
    float a = distance(p1, p2);
    float b = distance(p2, p3);
    float c = distance(p3, p1);

    // Calculate the perimeter and area of the triangle
    float perimeter = perimeterTriangle(a, b, c);
    float area = areaTriangle(a, b, c);

    // Print out the results
    printf("The lengths of the sides of the triangle are: %f, %f, %f\n", a, b, c);
    printf("The perimeter of the triangle is: %f\n", perimeter);
    printf("The area of the triangle is: %f\n", area);

    return 0;
}