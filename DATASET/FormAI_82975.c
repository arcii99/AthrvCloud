//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: thoughtful
#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points in 3D space
double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
    return sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
}

int main() {
    double x1, y1, z1, x2, y2, z2;

    printf("Enter the coordinates of point 1 (x y z): ");
    scanf("%lf %lf %lf", &x1, &y1, &z1);

    printf("Enter the coordinates of point 2 (x y z): ");
    scanf("%lf %lf %lf", &x2, &y2, &z2);

    double dist = distance(x1, y1, z1, x2, y2, z2);

    printf("The distance between the two points is %lf\n", dist);
    
    // Finding the midpoint of the two points
    double x_mid = (x1 + x2) / 2;
    double y_mid = (y1 + y2) / 2;
    double z_mid = (z1 + z2) / 2;
    printf("The midpoint of the two points is (%lf, %lf, %lf)\n", x_mid, y_mid, z_mid);

    // Finding the equation of the plane that goes through the two points
    double A = y1 * (z2 - z1) + y2 * (z1 - z2) + y_mid * (z1 - z2);
    double B = z1 * (x2 - x1) + z2 * (x1 - x2) + z_mid * (x1 - x2);
    double C = x1 * (y2 - y1) + x2 * (y1 - y2) + x_mid * (y1 - y2);
    double D = -(A * x_mid + B * y_mid + C * z_mid);
    printf("The equation of the plane that goes through the two points is %lfx + %lfy + %lfz + %lf = 0\n", A, B, C, D);

    return 0;
}