//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: thoughtful
/*
This program takes as input the coordinates of four points in the xy plane: (x1,y1), (x2,y2), (x3,y3) and (x4,y4).
It then determines if the first three points form a right angle triangle. If they do, it calculates the intersection point
of the perpendicular bisectors of the sides. Finally, it outputs the distance between this point and the fourth point.

Author: AI Bot
*/

#include <stdio.h>
#include <math.h>

struct point {
    double x;   
    double y;   
};

int main() {
    struct point p1, p2, p3, p4, mid1, mid2, intpt;
    double a, b, c; // sides of the triangle
    double m1, m2;  // slopes of the perpendicular bisectors
    double x, y;    // intersection point

    // read in the coordinates
    printf("Enter the coordinates of the first point (x,y): ");
    scanf("%lf %lf",&p1.x,&p1.y);
    printf("Enter the coordinates of the second point (x,y): ");
    scanf("%lf %lf",&p2.x,&p2.y);
    printf("Enter the coordinates of the third point (x,y): ");
    scanf("%lf %lf",&p3.x,&p3.y);
    printf("Enter the coordinates of the fourth point (x,y): ");
    scanf("%lf %lf",&p4.x,&p4.y);

    // calculate the sides of the triangle
    a = sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
    b = sqrt((p3.x-p2.x)*(p3.x-p2.x) + (p3.y-p2.y)*(p3.y-p2.y));
    c = sqrt((p1.x-p3.x)*(p1.x-p3.x) + (p1.y-p3.y)*(p1.y-p3.y));

    // check if the triangle is a right triangle
    if (a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b) {

        // calculate the midpoints of the sides
        mid1.x = (p1.x + p2.x) / 2.0;
        mid1.y = (p1.y + p2.y) / 2.0;
        mid2.x = (p2.x + p3.x) / 2.0;
        mid2.y = (p2.y + p3.y) / 2.0;

        // calculate the slopes of the perpendicular bisectors
        m1 = -1.0 / ((p2.y-p1.y)/(p2.x-p1.x));
        m2 = -1.0 / ((p3.y-p2.y)/(p3.x-p2.x));

        // calculate the intersection of the perpendicular bisectors at (x,y)
        x = (m1*mid1.x - m2*mid2.x + mid2.y - mid1.y)/(m1 - m2);
        y = m1*(x - mid1.x) + mid1.y;

        // set the coordinates of the intersection point
        intpt.x = x;
        intpt.y = y;

        // calculate the distance between the intersection point and the fourth point
        double dist = sqrt((intpt.x-p4.x)*(intpt.x-p4.x) + (intpt.y-p4.y)*(intpt.y-p4.y));

        // output the distance
        printf("The distance between the intersection point and the fourth point is %.2f.\n",dist);
    }
    else {
        printf("The first three points do not form a right angle triangle.\n");
    }
    return 0;
}