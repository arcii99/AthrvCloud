//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

struct Point {
    float x;
    float y;
};

struct Line {
    struct Point p1;
    struct Point p2;
};

float distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

float angle_between(struct Line l1, struct Line l2) {
    float d1 = distance(l1.p1, l2.p1);
    float d2 = distance(l1.p2, l2.p2);
    float dot = (l1.p2.x - l1.p1.x) * (l2.p2.x - l2.p1.x) + (l1.p2.y - l1.p1.y) * (l2.p2.y - l2.p1.y);
    return acos(dot / (d1 * d2)) * 180 / PI;
}

int main() {
    struct Line l1 = { {0, 0}, {1, 0} };
    struct Line l2 = { {0, 0}, {0, 1} };
    float angle = angle_between(l1, l2);
    printf("Angle between l1 and l2: %.2f degrees\n", angle);
    return 0;
}