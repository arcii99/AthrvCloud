//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include <stdio.h>
#include <math.h>

// Define a Point struct to store x, y coordinates
struct Point {
    double x;
    double y;
};

// Calculate the Euclidean distance between two points
double euclidean_distance(struct Point p1, struct Point p2) {
    double x_diff = p2.x - p1.x;
    double y_diff = p2.y - p1.y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

// Calculate the area of a triangle given three points
double triangle_area(struct Point p1, struct Point p2, struct Point p3) {
    double a = euclidean_distance(p1, p2);
    double b = euclidean_distance(p2, p3);
    double c = euclidean_distance(p3, p1);
    double s = 0.5 * (a + b + c);
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Check if three points are collinear
int is_collinear(struct Point p1, struct Point p2, struct Point p3) {
    double area = triangle_area(p1, p2, p3);
    return area == 0;
}

int main() {
    // Test the functions
    struct Point p1 = {0, 0};
    struct Point p2 = {3, 0};
    struct Point p3 = {1.5, 4.5};
    double distance = euclidean_distance(p1, p3);
    double area = triangle_area(p1, p2, p3);
    int collinear = is_collinear(p1, p2, p3);
    
    printf("Distance between p1 and p3 is %.2f\n", distance);
    printf("Area of triangle p1p2p3 is %.2f\n", area);
    printf("p1, p2, and p3 are %s\n", collinear ? "collinear" : "not collinear");
    
    return 0;
}