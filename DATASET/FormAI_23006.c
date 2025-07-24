//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: puzzling
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    Point triangle[3];
    printf("Enter the coordinates of the first point (x, y): ");
    scanf("%lf, %lf", &triangle[0].x, &triangle[0].y);
    printf("Enter the coordinates of the second point (x, y): ");
    scanf("%lf, %lf", &triangle[1].x, &triangle[1].y);
    printf("Enter the coordinates of the third point (x, y): ");
    scanf("%lf, %lf", &triangle[2].x, &triangle[2].y);

    double a = distance(triangle[0], triangle[1]);
    double b = distance(triangle[1], triangle[2]);
    double c = distance(triangle[2], triangle[0]);

    // Check if the triangle is valid
    if (a + b <= c || b + c <= a || c + a <= b) {
        printf("The input points do not form a valid triangle.\n");
        return 0;
    }

    // Calculate the area
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    // Calculate the circumcenter and circumradius
    Point abmid = {(triangle[0].x + triangle[1].x) / 2, (triangle[0].y + triangle[1].y) / 2};
    Point bcmid = {(triangle[1].x + triangle[2].x) / 2, (triangle[1].y + triangle[2].y) / 2};
    double slope1 = (triangle[1].y - triangle[0].y) / (triangle[1].x - triangle[0].x);
    double slope2 = (triangle[2].y - triangle[1].y) / (triangle[2].x - triangle[1].x);
    double x = (slope1 * slope2 * (triangle[0].y - triangle[2].y) + slope2 * (triangle[0].x + triangle[1].x) - slope1 * (triangle[1].x + triangle[2].x)) / (2 * (slope2 - slope1));
    double y = (slope1 * (x - (triangle[0].x + triangle[1].x) / 2) + (triangle[0].y + triangle[1].y) / 2);
    Point circumcenter = {x, y};
    double circumradius = distance(circumcenter, triangle[0]);

    // Calculate the incenter and inradius
    double p = a + b + c;
    Point incenter = {(a * triangle[0].x + b * triangle[1].x + c * triangle[2].x) / p, (a * triangle[0].y + b * triangle[1].y + c * triangle[2].y) / p};
    double inradius = area / s;

    // Calculate the centroid and orthocenter
    Point centroid = {(triangle[0].x + triangle[1].x + triangle[2].x) / 3, (triangle[0].y + triangle[1].y + triangle[2].y) / 3};
    slope1 = (triangle[1].y - triangle[0].y) / (triangle[1].x - triangle[0].x);
    slope2 = (triangle[2].y - triangle[0].y) / (triangle[2].x - triangle[0].x);
    double norm1 = -1 / slope1;
    double norm2 = -1 / slope2;
    double constant1 = (-centroid.y + norm1 * centroid.x);
    double constant2 = (-triangle[2].y + norm2 * triangle[2].x);
    x = (constant2 - constant1) / (norm1 - norm2);
    y = norm1 * x + constant1;
    Point orthocenter = {x, y};

    // Print the results
    printf("Triangle side lengths: %.3f, %.3f, %.3f\n", a, b, c);
    printf("Triangle area: %.3f\n", area);
    printf("Circumcenter: (%.3f, %.3f), Circumradius: %.3f\n", circumcenter.x, circumcenter.y, circumradius);
    printf("Incenter: (%.3f, %.3f), Inradius: %.3f\n", incenter.x, incenter.y, inradius);
    printf("Centroid: (%.3f, %.3f)\n", centroid.x, centroid.y);
    printf("Orthocenter: (%.3f, %.3f)\n", orthocenter.x, orthocenter.y);

    return 0;
}