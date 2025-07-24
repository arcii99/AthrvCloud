//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>

struct Point {
    double x, y;
};

double crossProduct(struct Point A, struct Point B) {
    return A.x * B.y - A.y * B.x;
}

int main() {
    printf("This program calculates the area of a convex polygon given its vertices.\n");
    printf("Please input the number of vertices: ");
    int n;
    scanf("%d", &n);

    struct Point polygon[n];

    printf("Please input the coordinates of the vertices in clockwise or counterclockwise order:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d : ", i+1);
        scanf("%lf %lf", &polygon[i].x, &polygon[i].y);
    }

    double area = 0;
    for (int i = 0; i < n; i++) {
        area += crossProduct(polygon[i], polygon[(i+1) % n]);
    }
    area /= 2;

    printf("The area of the convex polygon is: %lf\n", area);
    return 0;
}