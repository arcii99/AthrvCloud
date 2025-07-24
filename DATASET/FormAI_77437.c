//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: complex
#include <stdio.h>
#include <math.h>

// define pi constant for accuracy
#define PI 3.14159265358979323846

// define structure for a 2D point
struct Point2D {
    double x;
    double y;
};

// calculate distance between two points
double distancePoints(struct Point2D p1, struct Point2D p2) {
    double xDist = p2.x - p1.x;
    double yDist = p2.y - p1.y;
    return sqrt(xDist*xDist + yDist*yDist);
}

// calculate area of a triangle given three points
double areaTriangle(struct Point2D p1, struct Point2D p2, struct Point2D p3) {
    double a = distancePoints(p1, p2);
    double b = distancePoints(p2, p3);
    double c = distancePoints(p3, p1);
    double s = (a + b + c) / 2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

// calculate smallest angle of a triangle given three points
double smallestAngle(struct Point2D p1, struct Point2D p2, struct Point2D p3) {
    double a = distancePoints(p1, p2);
    double b = distancePoints(p2, p3);
    double c = distancePoints(p3, p1);
    return acos((a*a + b*b - c*c) / (2*a*b)) * 180 / PI;
}

// check if two line segments intersect using orientation of points
int doIntersect(struct Point2D p1, struct Point2D q1, struct Point2D p2, struct Point2D q2) {
    int o1 = (q1.y - p1.y) * (p2.x - q1.x) - (q1.x - p1.x) * (p2.y - q1.y);
    int o2 = (q1.y - p1.y) * (q2.x - q1.x) - (q1.x - p1.x) * (q2.y - q1.y);
    int o3 = (q2.y - p2.y) * (p1.x - q2.x) - (q2.x - p2.x) * (p1.y - q2.y);
    int o4 = (q2.y - p2.y) * (q1.x - q2.x) - (q2.x - p2.x) * (q1.y - q2.y);
    if (o1 != o2 && o3 != o4)
        return 1;
    return 0;
}

int main() {
    // create three points for a triangle: A(0,0), B(0,5), C(5,5)
    struct Point2D A = {0, 0};
    struct Point2D B = {0, 5};
    struct Point2D C = {5, 5};

    // calculate area and smallest angle of the triangle
    double area = areaTriangle(A, B, C);
    double smallest = smallestAngle(A, B, C);

    // output results
    printf("The area of the triangle is: %f\n", area);
    printf("The smallest angle of the triangle is: %f degrees\n", smallest);

    // create two line segments and check if they intersect
    struct Point2D P1 = {1, 1};
    struct Point2D Q1 = {5, 5};
    struct Point2D P2 = {5, 1};
    struct Point2D Q2 = {1, 5};
    int intersect = doIntersect(P1, Q1, P2, Q2);

    // output results
    if(intersect)
        printf("Line segments intersect!\n");
    else
        printf("Line segments do not intersect.\n");

    return 0;
}