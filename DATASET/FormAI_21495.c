//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: realistic
#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate the area of a triangle using Heron's formula
double areaTriangle(double a, double b, double c) {
    double s = (a + b + c) / 2; // Calculate the semiperimeter
    return sqrt(s * (s - a) * (s - b) * (s - c)); // Return the area
}

// Function to check if three points are collinear
int areCollinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    // Calculate the area of the triangle formed by the points
    double area = areaTriangle(distance(x1, y1, x2, y2), distance(x1, y1, x3, y3), distance(x2, y2, x3, y3));
    if (area == 0) { // If the area is 0, the points are collinear
        return 1;
    }
    return 0;
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of three points: ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    if (areCollinear(x1, y1, x2, y2, x3, y3)) {
        printf("The points are collinear.");
    } else {
        printf("The points are not collinear.");
    }
    return 0;
}