//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: automated
#include <stdio.h>
#include <math.h>

struct point {
    double x;
    double y;
};

double distance(struct point a, struct point b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

struct circle {
    struct point center;
    double radius;
};

int check_point_in_circle(struct point p, struct circle c) {
    double dist = distance(p, c.center);
    if (dist <= c.radius) {
        return 1;
    }
    else {
        return 0;
    }
}

int check_circle_overlap(struct circle c1, struct circle c2) {
    double dist_centers = distance(c1.center, c2.center);
    double radii_sum = c1.radius + c2.radius;
    if (dist_centers <= radii_sum) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    struct point p1, p2, p3;
    struct circle c1, c2;

    printf("Enter the coordinates of point P1: ");
    scanf("%lf %lf", &p1.x, &p1.y);

    printf("Enter the coordinates of point P2: ");
    scanf("%lf %lf", &p2.x, &p2.y);

    printf("Enter the coordinates of point P3: ");
    scanf("%lf %lf", &p3.x, &p3.y);

    printf("Enter the center coordinates of circle C1: ");
    scanf("%lf %lf", &c1.center.x, &c1.center.y);

    printf("Enter the radius of circle C1: ");
    scanf("%lf", &c1.radius);

    printf("Enter the center coordinates of circle C2: ");
    scanf("%lf %lf", &c2.center.x, &c2.center.y);

    printf("Enter the radius of circle C2: ");
    scanf("%lf", &c2.radius);

    printf("Distance between P1 and P2: %lf\n", distance(p1, p2));

    printf("P3 is "); 
    if (!check_point_in_circle(p3, c1)) {
        printf("not ");
    }
    printf("inside C1\n");

    printf("C1 and C2 ");
    if (!check_circle_overlap(c1, c2)) {
        printf("do not ");
    }
    printf("overlap\n");

    return 0;
}