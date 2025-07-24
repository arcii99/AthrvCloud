//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>
#include <math.h>

#define MAX_POINTS 1000

struct Point {
    double x, y;
};

struct Line {
    double a, b, c;
};

int main() {
    struct Point points[MAX_POINTS];
    int n;

    // Read input
    printf("Enter the number of points: ");
    scanf("%d", &n);
    printf("Enter the points in the format x y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    // Find the line passing through two closest points
    double min_distance = INFINITY;
    struct Line closest_line;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double distance = sqrt(pow(points[j].y-points[i].y, 2) + pow(points[j].x-points[i].x, 2));
            if (distance < min_distance) {
                // Update the line
                closest_line.a = points[j].y-points[i].y;
                closest_line.b = points[i].x-points[j].x;
                closest_line.c = -closest_line.a*points[i].x - closest_line.b*points[i].y;
                min_distance = distance;
            }
        }
    }

    // Print the closest line
    printf("The closest line to the given points is:\n");
    printf("%.2fx + %.2fy + %.2f = 0\n", closest_line.a, closest_line.b, closest_line.c);

    return 0;
}