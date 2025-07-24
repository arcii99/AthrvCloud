//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: futuristic
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle
double calculateArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    double b = sqrt(pow((x3-x2),2) + pow((y3-y2),2));
    double c = sqrt(pow((x1-x3),2) + pow((y1-y3),2));

    double s = (a+b+c)/2;

    double area = sqrt(s*(s-a)*(s-b)*(s-c));

    return area;
}

// Function to calculate the centroid of a triangle
void calculateCentroid(double x1, double y1, double x2, double y2, double x3, double y3, double *centroidX, double *centroidY) {
    *centroidX = (x1 + x2 + x3)/3;
    *centroidY = (y1 + y2 + y3)/3;
}

int main() {
    double x1 = 0, y1 = 0, x2 = 4, y2 = 4, x3 = 8, y3 = 0;
    double area;

    area = calculateArea(x1, y1, x2, y2, x3, y3);
    printf("The area of the triangle is: %lf\n",area);

    double centroidX, centroidY;

    calculateCentroid(x1, y1, x2, y2, x3, y3, &centroidX, &centroidY);
    printf("The centroid of the triangle is: (%lf,%lf)\n",centroidX,centroidY);

    return 0;
}