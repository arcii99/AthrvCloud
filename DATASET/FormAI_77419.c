//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: real-life
// Program to find the intersection point of two lines in 2D space
#include<stdio.h>

// Structure to represent a point in 2D space
struct Point {
    double x;
    double y;
};

// Function to find the intersection point of two lines
struct Point intersect(struct Point A1, struct Point A2, struct Point B1, struct Point B2) {
    double dx1 = A2.x - A1.x;
    double dy1 = A2.y - A1.y;
    double dx2 = B2.x - B1.x;
    double dy2 = B2.y - B1.y;

    // Finding the determinant of the system of equations
    double det = dx1 * dy2 - dy1 * dx2;

    // Checking if the system of equations is dependent or independent
    if (det == 0) {
        printf("The lines are parallel or coincident.\n");
        struct Point P = {0, 0};
        return P;
    }

    // Finding the intersection point
    double c1 = A1.x * A2.y - A1.y * A2.x;
    double c2 = B1.x * B2.y - B1.y * B2.x;
    double x = (dy2 * c1 - dy1 * c2) / det;
    double y = (-dx2 * c1 + dx1 * c2) / det;
    struct Point P = {x, y};
    return P;
}

int main() {
    // Taking input values for line A and line B
    struct Point A1, A2, B1, B2;
    printf("Enter the coordinates of A1: ");
    scanf("%lf %lf", &A1.x, &A1.y);
    printf("Enter the coordinates of A2: ");
    scanf("%lf %lf", &A2.x, &A2.y);
    printf("Enter the coordinates of B1: ");
    scanf("%lf %lf", &B1.x, &B1.y);
    printf("Enter the coordinates of B2: ");
    scanf("%lf %lf", &B2.x, &B2.y);

    // Finding the intersection point of line A and line B
    struct Point P = intersect(A1, A2, B1, B2);

    // Printing the intersection point coordinates
    printf("The intersection point is: %.2f, %.2f\n", P.x, P.y);
    return 0;
}