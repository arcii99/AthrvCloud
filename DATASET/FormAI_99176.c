//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: paranoid
#include <stdio.h>
#include <math.h>

// Function to find the distance between two 2D points
double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dist = sqrt(dx*dx + dy*dy);
    return dist;
}

// Function to find the circumcenter of a triangle
void circumcenter(double x1, double y1, double x2, double y2, double x3, double y3, double* cx, double* cy) {
    double a = distance(x2, y2, x3, y3);
    double b = distance(x1, y1, x3, y3);
    double c = distance(x1, y1, x2, y2);
    
    double D = 2 * (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
    *cx = ((x1*x1 + y1*y1)*(y2-y3) + (x2*x2 + y2*y2)*(y3-y1) + (x3*x3 + y3*y3)*(y1-y2)) / D;
    *cy = ((x1*x1 + y1*y1)*(x3-x2) + (x2*x2 + y2*y2)*(x1-x3) + (x3*x3 + y3*y3)*(x2-x1)) / D;
}

int main() {
    // Get input coordinates
    double x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the first point: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter the coordinates of the second point: ");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter the coordinates of the third point: ");
    scanf("%lf %lf", &x3, &y3);
    
    // Calculate circumcenter
    double cx, cy;
    circumcenter(x1, y1, x2, y2, x3, y3, &cx, &cy);
    
    // Check if circumcenter is inside the triangle
    double a = distance(x2,y2,x3,y3);
    double b = distance(x1,y1,x3,y3);
    double c = distance(x1,y1,x2,y2);
    double r = a*b*c / (4 * sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c)));
    double dist1 = distance(cx,cy,x1,y1);
    double dist2 = distance(cx,cy,x2,y2);
    double dist3 = distance(cx,cy,x3,y3);
    int isInside = (dist1 < r) && (dist2 < r) && (dist3 < r);
    
    // Print result
    if (isInside) {
        printf("Circumcenter (%lf,%lf) is inside the triangle.\n", cx, cy);
    } else {
        printf("Circumcenter (%lf,%lf) is not inside the triangle.\n", cx, cy);
    }
    
    return 0;
}