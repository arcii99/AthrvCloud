//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multivariable
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

struct Point {
    float x;
    float y;
    float z;
};

float calcDistance(struct Point p1, struct Point p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    float dz = p1.z - p2.z;
    return sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
}

float calcAngle(struct Point p1, struct Point p2, struct Point p3) {
    float a = calcDistance(p2, p3);
    float b = calcDistance(p1, p3);
    float c = calcDistance(p1, p2);
    return acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c)) * 180 / PI;
}

int main() {
    struct Point p1 = {1.0, 2.0, 3.0};
    struct Point p2 = {4.0, 5.0, 6.0};
    struct Point p3 = {7.0, 8.0, 9.0};

    float distance = calcDistance(p1, p2);
    float angle = calcAngle(p1, p2, p3);

    printf("The distance between p1 and p2 is %.2f\n", distance);
    printf("The angle between p1, p2, and p3 is %.2f degrees\n", angle);

    return 0;
}