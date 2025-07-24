//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: imaginative
#include <stdio.h>

struct Point {
    int x;
    int y;
};

struct Line {
    struct Point start;
    struct Point end;
};

float compute_distance(struct Point p1, struct Point p2) {
    int x_diff = p1.x - p2.x;
    int y_diff = p1.y - p2.y;
    return sqrt((x_diff * x_diff) + (y_diff * y_diff));
}

int check_intersection(struct Line l1, struct Line l2) {
    int is_intersecting = 0;

    int slope_1 = (l1.end.y - l1.start.y) / (l1.end.x - l1.start.x);
    int slope_2 = (l2.end.y - l2.start.y) / (l2.end.x - l2.start.x);

    if (slope_1 == slope_2) {
        return is_intersecting;
    }

    int x_intersect = ((l2.start.y - l1.start.y) / slope_1) + l1.start.x;

    if ((x_intersect >= l1.start.x && x_intersect <= l1.end.x) && (x_intersect >= l2.start.x && x_intersect <= l2.end.x)) {
        is_intersecting = 1;
    }

    return is_intersecting;
}

int main() {
    struct Line l1 = {{1, 1}, {4, 5}};
    struct Line l2 = {{3, 1}, {6, 5}};

    int is_intersecting = check_intersection(l1, l2);

    if (is_intersecting) {
        printf("The lines intersect.\n");
    } else {
        printf("The lines do not intersect.\n");
    }

    float distance = compute_distance(l1.start, l1.end);

    printf("The distance between the two points is %f.\n", distance);

    return 0;
}