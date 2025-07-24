//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

typedef struct Point {
    int x;
    int y;
} Point;

float distance(Point p1, Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int numPoints;
    printf("Enter the number of points: ");
    scanf("%d", &numPoints);

    Point points[numPoints];
    for (int i = 0; i < numPoints; i++) {
        printf("\nEnter coordinates for point %d:\n", i + 1);
        printf("x = ");
        scanf("%d", &points[i].x);
        printf("y = ");
        scanf("%d", &points[i].y);
    }

    float longestDistance = 0;
    Point p1, p2;
    for (int i = 0; i < numPoints; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            float d = distance(points[i], points[j]);
            if (d > longestDistance) {
                longestDistance = d;
                p1 = points[i];
                p2 = points[j];
            }
        }
    }

    printf("\nThe two points with the longest distance are: ");
    printf("(%d,%d) and (%d,%d)", p1.x, p1.y, p2.x, p2.y);

    return 0;
}