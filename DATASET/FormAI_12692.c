//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point a;
    point b;
    point c;
} triangle;

double distance(point p1, point p2);
point midpoint(point a, point b);
double angle(point p1, point p2, point p3);
int is_obtuse(triangle t);
int is_acute(triangle t);

int main() {
    point p1 = {0,0};
    point p2 = {3,4};
    point p3 = {2,1};
    triangle t = {p1, p2, p3};

    printf("Distance between p1 and p2: %lf\n", distance(p1, p2));
    printf("Midpoint between p1 and p2: (%lf, %lf)\n", midpoint(p1, p2).x, midpoint(p1, p2).y);

    printf("Angle at point p1: %lf degrees\n", angle(p1, p2, p3));
    printf("Angle at point p2: %lf degrees\n", angle(p2, p3, p1));
    printf("Angle at point p3: %lf degrees\n", angle(p3, p1, p2));

    if (is_obtuse(t)) {
        printf("This triangle is obtuse.\n");
    } else if (is_acute(t)) {
        printf("This triangle is acute.\n");
    } else {
        printf("This triangle is neither obtuse nor acute.\n");
    }

    return 0;
}

double distance(point p1, point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

point midpoint(point a, point b) {
    point mid;
    mid.x = (a.x + b.x) / 2;
    mid.y = (a.y + b.y) / 2;
    return mid;
}

double angle(point p1, point p2, point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    return acos( (b*b + c*c - a*a) / (2*b*c) ) * 180 / M_PI;
}

int is_obtuse(triangle t) {
    double a = angle(t.a, t.b, t.c);
    double b = angle(t.b, t.c, t.a);
    double c = angle(t.c, t.a, t.b);
    return a > 90 || b > 90 || c > 90;
}

int is_acute(triangle t) {
    double a = angle(t.a, t.b, t.c);
    double b = angle(t.b, t.c, t.a);
    double c = angle(t.c, t.a, t.b);
    return a < 90 &&  b < 90 && c < 90;
}