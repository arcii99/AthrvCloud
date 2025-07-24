//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: portable
/*
* This program demonstrates a unique geometric algorithm to calculate the intersection point of two lines in 2D space. 
* The program takes four points as input, two for each line and outputs the intersecting point of these lines.
*/

#include <stdio.h>

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point p1, p2;
} Line;

int main() {

    Line l1, l2;
    Point intersectionPoint;

    // Taking input of two lines with four points
    printf("Enter First Line Points (x1,y1) (x2,y2): ");
    scanf("%lf%lf%lf%lf", &l1.p1.x, &l1.p1.y, &l1.p2.x, &l1.p2.y);

    printf("Enter Second Line Points (x1,y1) (x2,y2): ");
    scanf("%lf%lf%lf%lf", &l2.p1.x, &l2.p1.y, &l2.p2.x, &l2.p2.y);

    // Calculating the slope and y-intercept of both the lines
    double slopeL1 = (l1.p2.y - l1.p1.y) / (l1.p2.x - l1.p1.x);
    double slopeL2 = (l2.p2.y - l2.p1.y) / (l2.p2.x - l2.p1.x);

    double yintL1 = l1.p1.y - (slopeL1 * l1.p1.x);
    double yintL2 = l2.p1.y - (slopeL2 * l2.p1.x);

    // If both the lines are parallel, they will never intersect
    if (slopeL1 == slopeL2) {
        printf("The lines are parallel. They will never intersect.\n");
    }
    else {
        // Calculating the point of intersection
        intersectionPoint.x = (yintL2 - yintL1) / (slopeL1 - slopeL2);
        intersectionPoint.y = (slopeL1 * intersectionPoint.x) + yintL1;

        // Printing the intersecting point of two lines
        printf("The lines intersect at point (%.2lf,%.2lf)\n", intersectionPoint.x, intersectionPoint.y);

    }

    return 0;
}