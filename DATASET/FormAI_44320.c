//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: unmistakable
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Struct to hold a point in 2D space
typedef struct Point {
    double x, y;
} Point;

// Calculates distance between two points
double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

// Calculates the sine of an angle given two points and the center of rotation
double sine(Point p1, Point p2, Point center) {
    double opposite = p2.y - center.y;
    double hypotenuse = distance(center, p2);
    return opposite / hypotenuse;
}

// Calculates the cosine of an angle given two points and the center of rotation
double cosine(Point p1, Point p2, Point center) {
    double adjacent = p2.x - center.x;
    double hypotenuse = distance(center, p2);
    return adjacent / hypotenuse;
}

// Rotates a point around a center by a given angle (in radians)
Point rotate(Point p, Point center, double angle) {
    double s = sin(angle);
    double c = cos(angle);

    // Translate point to center
    p.x -= center.x;
    p.y -= center.y;

    // Rotate point
    double xNew = p.x * c - p.y * s;
    double yNew = p.x * s + p.y * c;

    // Translate point back to original position
    p.x = xNew + center.x;
    p.y = yNew + center.y;

    return p;
}

int main() {
    // Create points A, B, and C
    Point A = {0, 0};
    Point B = {4, 0};
    Point C = {0, 3};

    // Find the center point of the circle
    // that passes through points A, B, and C
    double a = distance(B, C);
    double b = distance(A, C);
    double c = distance(A, B);
    double s = (a + b + c)/2;    // Semi-perimeter
    double area = sqrt(s*(s-a)*(s-b)*(s-c));    // Area of triangle
    double radius = a*b*c / (4*area);   // Radius of circumcircle
    Point center = {0, 0};
    center.x = (pow(a, 2)*(b*b + c*c - a*a) + pow(b, 2)*(c*c + a*a - b*b) + pow(c, 2)*(a*a + b*b - c*c)) / (16*area*area);
    center.y = (pow(a, 2)*(2*b*b + 2*c*c - a*a) + pow(b, 2)*(2*c*c + 2*a*a - b*b) + pow(c, 2)*(2*a*a + 2*b*b - c*c)) / (16*area*area);

    // Rotate point A about the center by 60 degrees (1/3 of a full revolution)
    double angle = 60 * PI/180;    // Convert degrees to radians
    Point Anew = rotate(A, center, angle);

    // Print out the original and rotated points
    printf("Point A: (%f, %f)\n", A.x, A.y);
    printf("Point B: (%f, %f)\n", B.x, B.y);
    printf("Point C: (%f, %f)\n", C.x, C.y);
    printf("Center of circle: (%f, %f)\n", center.x, center.y);
    printf("Point A rotated 60 degrees about the center: (%f, %f)\n", Anew.x, Anew.y);

    return 0;
}