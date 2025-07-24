//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: ephemeral
#include <stdio.h>
#define MAX 100

typedef struct {
    int x, y;
} Point;

void print(Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}

float dist(Point a, Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main() {
    int n;
    Point points[MAX]; // maximum number of points
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Read the points from input
    printf("Enter the points: ");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // Find the pair of points with the maximum distance
    float max_distance = 0;
    Point p1, p2;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            float d = dist(points[i], points[j]);
            if(d > max_distance) {
                max_distance = d;
                p1 = points[i];
                p2 = points[j];
            }
        }
    }
    printf("The pair of points with the maximum distance are:\n");
    print(p1);
    print(p2);
    printf("Their distance is %f\n", max_distance);

    return 0;
}