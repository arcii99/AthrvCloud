//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: calm
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846 // define value of pi

int main() {

    double radius, x_center, y_center, x, y;
    int i, n;

    // Get input values from user
    printf("Enter the radius of circle:\n");
    scanf("%lf", &radius);
    printf("Enter the x coordinate of center:\n");
    scanf("%lf", &x_center);
    printf("Enter the y coordinate of center:\n");
    scanf("%lf", &y_center);
    printf("Enter the number of points you want to generate on the circle:\n");
    scanf("%d", &n);

    printf("The coordinates of the points on the circle are:\n");

    // Calculate the coordinates of the points on the circle
    for(i = 0; i < n; i++) {
        x = x_center + radius*cos(2*PI*i/n);
        y = y_center + radius*sin(2*PI*i/n);

        printf("(%lf, %lf)\n", x, y);
    }
    
    return 0;
}