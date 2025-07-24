//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Donald Knuth
#include<stdio.h>
#include<math.h>

// function declarations
int areaTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
int isInsideTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int p1, int p2);

int main() {
    int x1, y1, x2, y2, x3, y3, p1, p2;
    printf("Triangle vertices (x1 y1), (x2 y2), (x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    printf("Point to test (p1 p2): ");
    scanf("%d %d", &p1, &p2);

    // calculate triangle area
    int area = areaTriangle(x1, y1, x2, y2, x3, y3);

    // calculate areas of sub-triangles formed by point p
    int area1 = areaTriangle(x1, y1, x2, y2, p1, p2);
    int area2 = areaTriangle(x2, y2, x3, y3, p1, p2);
    int area3 = areaTriangle(x1, y1, x3, y3, p1, p2);

    // if sum of areas of sub-triangles is equal to area of main triangle, point is inside
    if (area1 + area2 + area3 == area) {
        printf("Point (%d,%d) is inside the triangle.\n", p1, p2);
    } else {
        printf("Point (%d,%d) is outside the triangle.\n", p1, p2);
    }

    return 0;
}

// function to calculate area of a triangle
int areaTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    return abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2);
}

// function to check if point is inside a triangle
int isInsideTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int p1, int p2) {
    int area = areaTriangle(x1, y1, x2, y2, x3, y3);
    int area1 = areaTriangle(x1, y1, x2, y2, p1, p2);
    int area2 = areaTriangle(x2, y2, x3, y3, p1, p2);
    int area3 = areaTriangle(x1, y1, x3, y3, p1, p2);
    if (area1 + area2 + area3 == area) {
        return 1;
    } else {
        return 0;
    }
}