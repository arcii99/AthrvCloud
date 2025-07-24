//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include <stdio.h>
#include <math.h>

typedef struct Point {
    int x, y;
} Point;

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int isTriangle(Point p1, Point p2, Point p3) {
    double a = dist(p1, p2), b = dist(p2, p3), c = dist(p3, p1);
    return (a + b > c) && (b + c > a) && (c + a > b);
}

int isCollinear(Point p1, Point p2, Point p3) {
    return (p1.y - p2.y) * (p1.x - p3.x) == (p1.y - p3.y) * (p1.x - p2.x);
}

int isConvex(Point p1, Point p2, Point p3, Point p4) {
    double ab = dist(p1, p2), bc = dist(p2, p3), cd = dist(p3, p4), da = dist(p4, p1), ac = dist(p1, p3), bd = dist(p2, p4);
    double abc = acos((ab * ab + ac * ac - bc * bc) / (2 * ab * ac)), bcd = acos((bc * bc + cd * cd - bd * bd) / (2 * bc * cd)), cda = acos((cd * cd + da * da - ac * ac) / (2 * cd * da)), dab = acos((da * da + ab * ab - bd * bd) / (2 * da * ab));
    double sum = abc + bcd + cda + dab;
    return (fabs(sum - 2 * M_PI) < 1e-9);
}

int main() {
    Point p1 = {0, 0}, p2 = {3, 0}, p3 = {0, 4}, p4 = {3, 4};
    printf("%s\n", isTriangle(p1, p2, p3) ? "p1 p2 p3 form a triangle" : "p1 p2 p3 do not form a triangle");
    printf("%s\n", isTriangle(p1, p2, p4) ? "p1 p2 p4 form a triangle" : "p1 p2 p4 do not form a triangle");
    printf("%s\n", isCollinear(p1, p2, p3) ? "p1 p2 p3 are collinear" : "p1 p2 p3 are not collinear");
    printf("%s\n", isCollinear(p1, p2, p4) ? "p1 p2 p4 are collinear" : "p1 p2 p4 are not collinear");
    printf("%s\n", isConvex(p1, p2, p3, p4) ? "p1 p2 p3 p4 form a convex quadrilateral" : "p1 p2 p3 p4 do not form a convex quadrilateral");
    return 0;
}