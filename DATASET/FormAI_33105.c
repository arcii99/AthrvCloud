//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: portable
#include <stdio.h>
#include <math.h>

// function to find the area of a triangle given the lengths of its three sides
double areaOfTriangle(double a, double b, double c) {
    // First, we find the semi-perimeter s
    double s = (a + b + c) / 2;
    
    // Then, we apply Heron's formula to calculate the area
    double area = sqrt(s * (s-a) * (s-b) * (s-c));
    return area;
}

// function to find the circumcenter of a triangle given the coordinates of its three vertices
void circumcenterOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3, double *xc, double *yc) {
    // using slope formula to find the mid points of two sides of the triangle
    double midx1 = (x1 + x2) / 2.0;
    double midy1 = (y1 + y2) / 2.0;
    double midx2 = (x1 + x3) / 2.0;
    double midy2 = (y1 + y3) / 2.0;
    
    // finding the slopes of the two lines passing through the midpoint of two sides
    double slope1 = (x2-x1)/(y2-y1);
    double slope2 = (x3-x1)/(y3-y1);
    
    // using the slopes and midpoints, finding the coordinates of the circumcenter
    *xc = (midy2 - midy1 + slope1*midx1 - slope2*midx2) / (slope1 - slope2);
    *yc = (slope1*(*xc - midx1)) + midy1;
}

// main function
int main() {
    double a, b, c, area, xc, yc;
    double x1, y1, x2, y2, x3, y3;
    printf("Enter the lengths of the three sides of the triangle: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    area = areaOfTriangle(a, b, c);
    printf("The area of the triangle is: %.2lf\n", area); // fixing the output to 2 decimal places
    
    printf("Enter the coordinates of the three vertices of the triangle: ");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    
    circumcenterOfTriangle(x1, y1, x2, y2, x3, y3, &xc, &yc);
    printf("The circumcenter of the triangle is: (%.2lf, %.2lf)\n", xc, yc); // fixing the output to 2 decimal places
    
    return 0;
}