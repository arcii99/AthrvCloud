//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multivariable
#include <stdio.h>
#include <math.h>

// Define data structure for a point in 3D space
struct Point3D {
    double x;
    double y;
    double z;
};

// Function to calculate the distance between two points in 3D space
double distance(struct Point3D p1, struct Point3D p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Function to find the midpoint of a line segment between two points in 3D space
struct Point3D midpoint(struct Point3D p1, struct Point3D p2) {
    struct Point3D mid;
    mid.x = (p1.x + p2.x) / 2.0;
    mid.y = (p1.y + p2.y) / 2.0;
    mid.z = (p1.z + p2.z) / 2.0;
    return mid;
}

// Function to find the area of a triangle in 3D space, given the lengths of its sides
double triangle_area(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

// Main function
int main() {
    struct Point3D p1 = {0.0, 0.0, 0.0};
    struct Point3D p2 = {1.0, 1.0, 1.0};
    struct Point3D mid = midpoint(p1, p2);
    printf("Midpoint of line segment (%.1lf, %.1lf, %.1lf) to (%.1lf, %.1lf, %.1lf) is (%.1lf, %.1lf, %.1lf)\n", 
           p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, mid.x, mid.y, mid.z);
           
    double dist = distance(p1, p2);
    printf("Distance between points (%.1lf, %.1lf, %.1lf) and (%.1lf, %.1lf, %.1lf) is %.1lf\n",
           p1.x, p1.y, p1.z, p2.x, p2.y, p2.z, dist);
           
    double a = 3.0, b = 4.0, c = 5.0;
    double area = triangle_area(a, b, c);
    printf("Area of triangle with sides %.1lf, %.1lf, and %.1lf is %.1lf\n", a, b, c, area);
    
    return 0;
}