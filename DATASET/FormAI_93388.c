//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: scalable
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

typedef struct {
    double x,y;
} Point;

Point scale(Point a, double factor){
    Point s;
    s.x = a.x*factor;
    s.y = a.y*factor;
    return s;
}

void rotate(double *x, double *y, double theta){
    double tempx = (*x)*cos(theta) - (*y)*sin(theta);
    double tempy = (*x)*sin(theta) + (*y)*cos(theta);
    *x = tempx;
    *y = tempy;
}

int main(){
    // get user input for scaling and rotation
    double scaleFactor, theta;
    printf("Enter the scaling factor: ");
    scanf("%lf", &scaleFactor);
    printf("Enter the rotation angle (in degrees): ");
    scanf("%lf", &theta);
    theta = theta*PI/180.0;

    // create original point and calculate scaled and rotated points
    Point original, scaled, rotated;
    original.x = 5.0;
    original.y = 4.0;
    scaled = scale(original, scaleFactor);
    rotated = original;
    rotate(&rotated.x, &rotated.y, theta);

    // print results
    printf("Original point: (%.2lf, %.2lf)\n", original.x, original.y);
    printf("Scaled point: (%.2lf, %.2lf)\n", scaled.x, scaled.y);
    printf("Rotated point: (%.2lf, %.2lf)\n", rotated.x, rotated.y);

    return 0;
}