//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: mathematical
#include <stdio.h>
#include <math.h>

/* This program takes in three points representing a triangle in 2D space,
   calculates the angles between the sides using law of cosines, and outputs
   whether the triangle is acute, right, or obtuse.
*/

int main() {
    double x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of point 1 (x y): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter the coordinates of point 2 (x y): ");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter the coordinates of point 3 (x y): ");
    scanf("%lf %lf", &x3, &y3);

    //calculate lengths of sides
    double a = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    double b = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    double c = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));

    //calculate angles using law of cosines
    double A = acos((b*b+c*c-a*a)/(2*b*c));
    double B = acos((c*c+a*a-b*b)/(2*c*a));
    double C = acos((a*a+b*b-c*c)/(2*a*b));

    //convert angles from radians to degrees
    double degA = A*180/M_PI;
    double degB = B*180/M_PI;
    double degC = C*180/M_PI;

    printf("Angle A: %.2lf degrees\n", degA);
    printf("Angle B: %.2lf degrees\n", degB);
    printf("Angle C: %.2lf degrees\n", degC);

    //determine type of triangle
    if(degA<90 && degB<90 && degC<90){
        printf("This is an acute triangle.\n");
    }else if(degA==90 || degB==90 || degC==90){
        printf("This is a right triangle.\n");
    }else{
        printf("This is an obtuse triangle.\n");
    }

    return 0;
}