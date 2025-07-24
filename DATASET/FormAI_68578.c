//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: paranoid
#include <stdio.h>
#include <math.h>

#define MAX_POINTS 1000

struct point {
    double x;
    double y;
};

typedef struct point Point;

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double cross_product(Point a, Point b, Point c) {
    double x1 = b.x - a.x, y1 = b.y - a.y;
    double x2 = c.x - a.x, y2 = c.y - a.y;
    return x1 * y2 - x2 * y1;
}

double dot_product(Point a, Point b, Point c) {
    double x1 = b.x - a.x, y1 = b.y - a.y;
    double x2 = c.x - a.x, y2 = c.y - a.y;
    return x1 * x2 + y1 * y2;
}

int main() {

    Point points[MAX_POINTS];
    int n = 0;

    printf("Enter the number of points (up to %d): ", MAX_POINTS);
    scanf("%d", &n);

    if (n < 3) {
        printf("Error: must enter at least 3 points.\n");
        return 1;
    }

    printf("Enter the points pairwise (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    // Check if points are collinear
    double cp = cross_product(points[0], points[1], points[2]);
    if (cp == 0) {
        printf("Error: points are collinear.\n");
        return 1;
    }

    // Check if points are clockwise or counterclockwise
    int is_ccw = 0;
    for (int i = 0; i < n - 2; i++) {
        double cp2 = cross_product(points[i], points[i+1], points[i+2]);
        if (cp2 == 0) {
            printf("Error: points are collinear.\n");
            return 1;
        }
        if (cp * cp2 < 0) {
            is_ccw = 1;
            break;
        }
    }

    if (is_ccw) {
        printf("Points are in counterclockwise order.\n");
    } else {
        printf("Points are in clockwise order.\n");
    }

    // Compute perimeter
    double perimeter = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        perimeter += distance(points[i], points[j]);
    }

    printf("Perimeter of polygon is: %.2f units.\n", perimeter);

    // Compute area
    double area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += cross_product(points[i], points[j], (Point){0, 0});
    }
    area /= 2;

    printf("Area of polygon is: %.2f units^2.\n", area);

    // Check if point is inside or outside polygon
    Point p;
    printf("Enter a test point (x y): ");
    scanf("%lf %lf", &p.x, &p.y);

    int num_intersections = 0;
    for (int i = 0; i < n; i++) {
        Point a = points[i], b = points[(i+1)%n];
        if ((a.y <= p.y && b.y > p.y) || (a.y > p.y && b.y <= p.y)) {
            double t = (p.y - a.y) / (b.y - a.y);
            double x = a.x + t * (b.x - a.x);
            if (x <= p.x) {
                num_intersections++;
            }
        }
    }

    if (num_intersections % 2 == 1) {
        printf("Point is inside polygon.\n");
    } else {
        printf("Point is outside polygon.\n");
    }

    return 0;
}