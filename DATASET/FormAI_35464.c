//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: protected
#include <stdio.h>
#include <math.h>

// Define a structure to represent a point in the cartesian coordinate system
struct Point {
    double x;
    double y;
};

// Function to calculate the distance between two points
double distance(struct Point p1, struct Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to calculate the area of a triangle using Heron's Formula
double areaTriangle(struct Point p1, struct Point p2, struct Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main() {
    // Prompt the user to enter the coordinates of three points
    printf("Enter the coordinates of Point A (in the format x y): ");
    struct Point A;
    scanf("%lf %lf", &A.x, &A.y);

    printf("Enter the coordinates of Point B (in the format x y): ");
    struct Point B;
    scanf("%lf %lf", &B.x, &B.y);

    printf("Enter the coordinates of Point C (in the format x y): ");
    struct Point C;
    scanf("%lf %lf", &C.x, &C.y);

    // Calculate the perimeter of the triangle
    double perimeter = distance(A, B) + distance(B, C) + distance(C, A);

    // Calculate the area of the triangle
    double area = areaTriangle(A, B, C);

    // Print the results
    printf("The perimeter of the triangle is: %lf\n", perimeter);
    printf("The area of the triangle is: %lf\n", area);

    return 0;
}