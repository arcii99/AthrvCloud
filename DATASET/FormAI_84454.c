//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: portable
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

struct point {
    double x;
    double y;
};

double get_distance(struct point p1, struct point p2) {
    double x_diff = p2.x - p1.x;
    double y_diff = p2.y - p1.y;

    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

double get_angle(struct point center, struct point p1, struct point p2) {
    double dist1 = get_distance(center, p1);
    double dist2 = get_distance(center, p2);

    double dot_product = (p1.x - center.x) * (p2.x - center.x) + (p1.y - center.y) * (p2.y - center.y);
    double cos_theta = dot_product / (dist1 * dist2);

    double theta = acos(cos_theta) * 180 / PI;
    return theta;
}

struct point rotate_point(struct point p, struct point center, double angle) {
    double radians = angle * PI / 180;

    double x_diff = p.x - center.x;
    double y_diff = p.y - center.y;

    double rotated_x = center.x + x_diff * cos(radians) - y_diff * sin(radians);
    double rotated_y = center.y + x_diff * sin(radians) + y_diff * cos(radians);

    struct point rotated_p = {rotated_x, rotated_y};
    return rotated_p;
}

int main() {
    struct point center = {0, 0};
    struct point p1 = {5, 0};
    struct point p2 = {0, 5};

    double angle = get_angle(center, p1, p2);
    printf("Angle between (0,0) -> (5,0) and (0,0) -> (0,5): %.2f degrees\n", angle);

    struct point rotated_p1 = rotate_point(p1, center, 90);
    printf("Rotated point: (%.2f, %.2f)\n", rotated_p1.x, rotated_p1.y);

    return 0;
}