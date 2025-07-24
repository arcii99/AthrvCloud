//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} point;

float distance(point a, point b) {
    float dist = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    return dist;
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    point *points = malloc(n * sizeof(point));

    printf("Enter the coordinates of the points: \n");
    for (int i = 0; i < n; i++) {
        printf("Point %d: ", i+1);
        scanf("%f, %f", &points[i].x, &points[i].y);
    }

    float circum = 0;
    float radius;

    // find the circumference of the minimum enclosing circle
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            float dist = distance(points[i], points[j]);
            if (dist > 2 * radius) {
                float r1 = dist/2;
                point center = { (points[i].x + points[j].x)/2, (points[i].y + points[j].y)/2 };
                for (int k = 0; k < n; k++) {
                    if (distance(center, points[k]) > r1) {
                        // point is outside the minimum enclosing circle
                        r1 = -1;
                        break;
                    }
                }
                if (r1 > radius) {
                    circum = 2 * M_PI * r1;
                    radius = r1;
                }
            }   
        }
    }

    printf("Minimum enclosing circle: Center = (%.2f, %.2f), Radius = %.2f, Circumference = %.2f\n", 
            (points[0].x + points[1].x) / 2, (points[0].y + points[1].y) / 2, radius, circum);

    free(points);
    return 0;
}