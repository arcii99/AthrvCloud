//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTICES 1000

typedef struct point {
    double x;
    double y;
} Point;

double calculate_area(Point* vertices, int num_vertices);

int main(void) {
    int num_vertices;
    Point vertices[MAX_VERTICES];
    printf("Enter the number of vertices for the polygon: ");
    scanf("%d", &num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        printf("Enter x-coordinate for vertex %d: ", i+1);
        scanf("%lf", &vertices[i].x);
        printf("Enter y-coordinate for vertex %d: ", i+1);
        scanf("%lf", &vertices[i].y);
    }

    double area = calculate_area(vertices, num_vertices);
    printf("The area of the polygon is %lf\n", area);
    return 0;
}

double calculate_area(Point* vertices, int num_vertices) {
    double area = 0;
    int j = num_vertices - 1;

    for (int i = 0; i < num_vertices; i++) {
        area += (vertices[j].x + vertices[i].x) * (vertices[j].y - vertices[i].y);
        j = i;
    }
    return fabs(area / 2.0);
}