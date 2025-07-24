//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: portable
#include <stdio.h>
#include <math.h>

#define MAX 100

typedef struct {
    float x, y;
} Point;

/* Function to calculate area of a triangle given 3 points */
float triangleArea(Point a, Point b, Point c) {
    float area = fabs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2);
    return area;
}

/* Function to calculate the perimeter of a polygon */
float polygonPerimeter(Point vertices[], int n) {
    float perimeter = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        perimeter += sqrt(pow(vertices[(i + 1) % n].x - vertices[i % n].x, 2) + pow(vertices[(i + 1) % n].y - vertices[i % n].y, 2));
    }
    return perimeter;
}

/* Function to calculate the area of a polygon */
float polygonArea(Point vertices[], int n) {
    float area = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        area += (vertices[i % n].x * vertices[(i + 1) % n].y - vertices[(i + 1) % n].x * vertices[i % n].y);
    }
    area = fabs(area) / 2;
    return area;
}

int main() {
    int n, i;
    Point vertices[MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the x and y coordinates of each vertex:\n");
    for (i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%f %f", &vertices[i].x, &vertices[i].y);
    }

    printf("Perimeter of polygon: %f\n", polygonPerimeter(vertices, n));
    printf("Area of polygon: %f\n", polygonArea(vertices, n));

    Point a, b, c;
    printf("Enter the coordinates of three points to calculate the area of a triangle:\n");
    printf("Point A: ");
    scanf("%f %f", &a.x, &a.y);
    printf("Point B: ");
    scanf("%f %f", &b.x, &b.y);
    printf("Point C: ");
    scanf("%f %f", &c.x, &c.y);

    printf("Area of triangle: %f\n", triangleArea(a, b, c));

    return 0;
}