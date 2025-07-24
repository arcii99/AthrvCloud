//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: scalable
#include <stdio.h>

struct Point {
    double x, y;
};

struct Line {
    struct Point p1, p2;
};

// Calculate the distance between two points
double distance(struct Point p1, struct Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

// Calculate the length of a line
double length(struct Line line) {
    return distance(line.p1, line.p2);
}

// Determine if two lines intersect
int intersect(struct Line line1, struct Line line2) {
    double x1 = line1.p1.x;
    double y1 = line1.p1.y;
    double x2 = line1.p2.x;
    double y2 = line1.p2.y;
    double x3 = line2.p1.x;
    double y3 = line2.p1.y;
    double x4 = line2.p2.x;
    double y4 = line2.p2.y;

    double ua = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) /
                ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
    double ub = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) /
                ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

    if (ua >= 0.0 && ua <= 1.0 && ub >= 0.0 && ub <= 1.0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Test the distance function
    struct Point p1 = {0, 0};
    struct Point p2 = {3, 4};
    double d = distance(p1, p2);
    printf("Distance between (%.2lf, %.2lf) and (%.2lf, %.2lf) is %.2lf\n",
           p1.x, p1.y, p2.x, p2.y, d);

    // Test the length function
    struct Line line1 = {{0, 0}, {3, 4}};
    double len1 = length(line1);
    printf("Length of line from (%.2lf, %.2lf) to (%.2lf, %.2lf) is %.2lf\n",
           line1.p1.x, line1.p1.y, line1.p2.x, line1.p2.y, len1);

    // Test the intersect function
    struct Line line2 = {{0, 4}, {3, 0}};
    int i = intersect(line1, line2);
    printf("Lines from (%.2lf, %.2lf) to (%.2lf, %.2lf) and (%.2lf, %.2lf) to (%.2lf, %.2lf) ", 
           line1.p1.x, line1.p1.y, line1.p2.x, line1.p2.y, line2.p1.x, line2.p1.y, line2.p2.x, line2.p2.y);
    if (i) {
        printf("intersect\n");
    } else {
        printf("do not intersect\n");
    }

    return 0;
}