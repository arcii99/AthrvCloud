//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

/* This program calculates the area of any convex polygon given its vertices coordinates
   using the Shoelace Formula */

typedef struct {
    int x;
    int y;
} Point;

double calculateArea(Point polygon[], int n) {
    double area = 0.0;
    int j = n - 1;

    for (int i = 0; i < n; i++) {
        area += (double)(polygon[j].x + polygon[i].x) * (double)(polygon[j].y - polygon[i].y);
        j = i;
    }

    return abs(area / 2.0);
}

int main() {
    int n;

    printf("Enter the number of vertices in the polygon: ");
    scanf("%d", &n);

    Point *polygon = calloc(n, sizeof(Point)); // Allocate memory for n points

    for (int i = 0; i < n; i++) {
        printf("Enter the coordinates of vertex %d: ", i + 1);
        scanf("%d %d", &polygon[i].x, &polygon[i].y);
    }

    double area = calculateArea(polygon, n);
    printf("The area of the polygon is: %.2f", area);

    free(polygon); // Free allocated memory

    return 0; // Exit program
}