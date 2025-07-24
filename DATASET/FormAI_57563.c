//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point{
    double x, y;
};

struct line{
    struct point p1, p2;
};

double distance(struct point p1, struct point p2) {
    double xdiff = p2.x - p1.x;
    double ydiff = p2.y - p1.y;
    return sqrt(xdiff*xdiff + ydiff*ydiff);
}

int intersect(struct line l1, struct line l2, struct point *intersection) {
    double x1 = l1.p1.x, y1 = l1.p1.y, x2 = l1.p2.x, y2 = l1.p2.y;
    double x3 = l2.p1.x, y3 = l2.p1.y, x4 = l2.p2.x, y4 = l2.p2.y;
    double denom = (y4 - y3)*(x2 - x1) - (x4 - x3)*(y2 - y1);
    double ua, ub;
    if (denom == 0) { // lines are parallel (or coincident)
        return 0;
    }
    ua = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / denom;
    ub = ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3)) / denom;
    if (ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1) { // intersection within line segments,
        intersection->x = x1 + ua*(x2-x1);
        intersection->y = y1 + ua*(y2-y1);
        return 1;
    }
    return 0;
}

int main() {
    struct point p1, p2, p3, p4, intersection;
    printf("Enter the first line: ");
    scanf("%lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y);
    printf("Enter the second line: ");
    scanf("%lf %lf %lf %lf", &p3.x, &p3.y, &p4.x, &p4.y);
    printf("The distance between the points is: %.2lf\n", distance(p1, p2));
    if(intersect((struct line){p1, p2}, (struct line){p3, p4}, &intersection)) {
        printf("The intersection point is: (%.2lf, %.2lf)\n", intersection.x, intersection.y);
    } else {
        printf("The lines do not intersect\n");
    }
    return 0;
}