//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: minimalist
#include <stdio.h>

typedef struct point {
    double x;
    double y;
} point;

point intersection(point a1, point a2, point b1, point b2) {
    double s1_x, s1_y, s2_x, s2_y;
    s1_x = a2.x - a1.x;
    s1_y = a2.y - a1.y;
    s2_x = b2.x - b1.x;
    s2_y = b2.y - b1.y;

    double s, t;
    s = (-s1_y * (a1.x - b1.x) + s1_x * (a1.y - b1.y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (a1.y - b1.y) - s2_y * (a1.x - b1.x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1) {
        point intersection_point = {a1.x + (t * s1_x), a1.y + (t * s1_y)};
        return intersection_point;
    }

    return (point){0, 0};
}

int main() {
    point A = {1, 1};
    point B = {2, 4};
    point C = {3, 2};
    point D = {6, 5};

    point I = intersection(A, B, C, D);
    printf("Intersection point: (%.2f, %.2f)\n", I.x, I.y);
}