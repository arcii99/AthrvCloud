//FormAI DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Calculates the distance between two points in a 2D Euclidean space */
double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

/* Calculates the perimeter of a triangle given its sides lengths */
double perimeter(double a, double b, double c) {
    return a + b + c;
}

/* Calculates the area of a triangle given its sides lengths */
double area(double a, double b, double c) {
    double p = perimeter(a, b, c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    /* Generate random coordinates for three points on a 2D plane */
    srand(42);
    double x1 = (double) rand() / RAND_MAX;
    double y1 = (double) rand() / RAND_MAX;
    double x2 = (double) rand() / RAND_MAX;
    double y2 = (double) rand() / RAND_MAX;
    double x3 = (double) rand() / RAND_MAX;
    double y3 = (double) rand() / RAND_MAX;

    /* Calculate the sides lengths of the triangle formed by the three points */
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);

    /* Output the coordinates and sides lengths of the triangle */
    printf("Triangle with vertices:\n");
    printf("(%f, %f)\n", x1, y1);
    printf("(%f, %f)\n", x2, y2);
    printf("(%f, %f)\n", x3, y3);
    printf("has sides:\n");
    printf("a = %f\n", a);
    printf("b = %f\n", b);
    printf("c = %f\n", c);

    /* Calculate and output the perimeter and area of the triangle */
    double p = perimeter(a, b, c);
    double s = area(a, b, c);
    printf("perimeter = %f\n", p);
    printf("area = %f\n", s);

    return 0;
}