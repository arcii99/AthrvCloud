//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y;     // x and y coordinate
} Point;

typedef struct {
    Point p1, p2;    // endpoints of the line
} Line;

// Calculates the Euclidean distance between two points
double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Calculates the angle in radians between two lines
double angle(Line l1, Line l2) {
    double dx1 = l1.p1.x - l1.p2.x;
    double dy1 = l1.p1.y - l1.p2.y;
    double dx2 = l2.p1.x - l2.p2.x;
    double dy2 = l2.p1.y - l2.p2.y;
    double dot = dx1*dx2 + dy1*dy2;
    double len1 = distance(l1.p1, l1.p2);
    double len2 = distance(l2.p1, l2.p2);
    double angle = acos(dot/(len1*len2));
    return angle;
}

int main() {
    Line l1, l2;
    printf("Please enter the x and y coordinates for endpoint 1 of line 1: ");
    scanf("%lf %lf", &l1.p1.x, &l1.p1.y);
    printf("Please enter the x and y coordinates for endpoint 2 of line 1: ");
    scanf("%lf %lf", &l1.p2.x, &l1.p2.y);
    printf("Please enter the x and y coordinates for endpoint 1 of line 2: ");
    scanf("%lf %lf", &l2.p1.x, &l2.p1.y);
    printf("Please enter the x and y coordinates for endpoint 2 of line 2: ");
    scanf("%lf %lf", &l2.p2.x, &l2.p2.y);

    double angle_rads = angle(l1, l2);
    printf("The angle between the two lines is %.2f radians\n", angle_rads);
    printf("The angle between the two lines is %.2f degrees\n", angle_rads * 180.0 / PI);

    return 0;
}