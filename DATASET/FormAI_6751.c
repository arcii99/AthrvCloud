//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: realistic
#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

double getDistance(struct Point p1, struct Point p2) {
    double x_diff = p2.x - p1.x;
    double y_diff = p2.y - p1.y;
    return sqrt(x_diff*x_diff + y_diff*y_diff);
}

int main() {
    struct Point p1 = {1.0, 2.0};
    struct Point p2 = {4.0, 6.0};

    double distance = getDistance(p1, p2);
    printf("Distance between (%.1f,%.1f) and (%.1f,%.1f) is %.2f\n", p1.x, p1.y, p2.x, p2.y, distance);

    return 0;
}