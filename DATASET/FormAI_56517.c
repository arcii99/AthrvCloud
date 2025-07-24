//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: complex
#include <stdio.h>
#include <math.h>

// function to calculate the distance between two points
double calculate_distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// function to calculate the area of a circle
double calculate_area_of_circle(int radius) {
    return M_PI * pow(radius, 2);
}

// function to calculate the area of a triangle
double calculate_area_of_triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    double a = calculate_distance(x1, y1, x2, y2);
    double b = calculate_distance(x2, y2, x3, y3);
    double c = calculate_distance(x3, y3, x1, y1);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    // calculate area of circle
    int radius = 5;
    double area_of_circle = calculate_area_of_circle(radius);
    printf("The area of a circle with radius %d is %.2f\n", radius, area_of_circle);

    // calculate area of triangle
    int x1 = 0, y1 = 0;
    int x2 = 4, y2 = 0;
    int x3 = 2, y3 = 3;
    double area_of_triangle = calculate_area_of_triangle(x1, y1, x2, y2, x3, y3);
    printf("The area of a triangle with vertices (%d, %d), (%d, %d), and (%d, %d) is %.2f\n",
           x1, y1, x2, y2, x3, y3, area_of_triangle);

    return 0;
}