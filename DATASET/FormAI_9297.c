//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: systematic
#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

typedef struct Point Point;

double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point points[n];
    printf("Enter the points in (x, y) format:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    double max_distance = -1;
    Point max_a, max_b;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            double d = distance(points[i], points[j]);
            if (d > max_distance) {
                max_distance = d;
                max_a = points[i];
                max_b = points[j];
            }
        }
    }

    printf("The farthest two points are (%.2lf, %.2lf) and (%.2lf, %.2lf) with a distance of %.2lf\n", 
            max_a.x, max_a.y, max_b.x, max_b.y, max_distance);

    return 0;
}