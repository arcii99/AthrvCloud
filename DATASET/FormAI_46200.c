//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function to calculate the distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

//Function to calculate the perimeter of a triangle
double triangle_perimeter(int x1, int y1, int x2, int y2, int x3, int y3) {
    double perimeter = 0;
    perimeter += distance(x1, y1, x2, y2);
    perimeter += distance(x2, y2, x3, y3);
    perimeter += distance(x1, y1, x3, y3);
    return perimeter;
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    printf("Enter the x and y coordinates for the three vertices of the triangle:\n");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    double perimeter = triangle_perimeter(x1, y1, x2, y2, x3, y3);
    printf("The perimeter of the triangle is: %lf\n", perimeter);
    return 0;
}