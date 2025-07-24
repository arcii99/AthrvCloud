//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: grateful
#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

struct Line {
    struct Point start;
    struct Point end;
};

int intersects(struct Line a, struct Line b) {
    double x1 = a.start.x;
    double y1 = a.start.y;
    double x2 = a.end.x;
    double y2 = a.end.y;
    double x3 = b.start.x;
    double y3 = b.start.y;
    double x4 = b.end.x;
    double y4 = b.end.y;

    double denom = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);
    if (fabs(denom) < 1e-6) {
        return 0;
    }

    double t = ((x1-x3)*(y3-y4) - (y1-y3)*(x3-x4))/denom;
    double u = -((x1-x2)*(y1-y3) - (y1-y2)*(x1-x3))/denom;

    if (t >= 0.0 && t <= 1.0 && u >= 0.0 && u <= 1.0) {
        printf("The intersection point is: (%f, %f)\n",
                x1 + t*(x2-x1), y1 + t*(y2-y1));
        return 1;
    }
    return 0;
}

int main() {

    struct Line line1 = {{1.0, 1.0}, {2.0, 2.0}};
    struct Line line2 = {{1.0, 2.0}, {2.0, 1.0}};

    if (intersects(line1, line2)) {
        printf("The lines intersected.\n");
    } else {
        printf("The lines did not intersect.\n");
    }

    return 0;
}