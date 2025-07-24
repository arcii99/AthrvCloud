//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include <stdio.h>

typedef struct Point {
    int x, y;
} Point;

typedef struct Rectangle {
    Point ul, lr;
} Rectangle;

/* Function to calculate the area of a rectangle */
int area(Rectangle *r) {
    int width = r->lr.x - r->ul.x;
    int height = r->ul.y - r->lr.y;
    return width * height;
}

/* Function to check if two rectangles intersect */
int intersects(Rectangle *r1, Rectangle *r2) {
    if (r1->ul.x > r2->lr.x || r2->ul.x > r1->lr.x)
        return 0;
    if (r1->ul.y < r2->lr.y || r2->ul.y < r1->lr.y)
        return 0;
    return 1;
}

/* Function to calculate the area of the intersecting portion of two rectangles */
int intersection_area(Rectangle *r1, Rectangle *r2) {
    int x_overlap = overlap(r1->ul.x, r1->lr.x, r2->ul.x, r2->lr.x);
    int y_overlap = overlap(r1->ul.y, r1->lr.y, r2->ul.y, r2->lr.y);
    Rectangle r = {{x_overlap, y_overlap}, {x_overlap + (r1->lr.x - r1->ul.x), y_overlap - (r1->ul.y - r1->lr.y)}};
    return area(&r);
}

/* Helper function to calculate the overlap between two ranges */
int overlap(int a1, int a2, int b1, int b2) {
    if (b1 > a1 && b1 < a2)
        return b1;
    if (b2 > a1 && b2 < a2)
        return b2;
    if (a1 > b1 && a1 < b2)
        return a1;
    if (a2 > b1 && a2 < b2)
        return a2;
    return 0;
}

int main() {
    Rectangle r1 = {{0, 0}, {10, 10}};
    Rectangle r2 = {{5, 5}, {15, 15}};
    printf("Area of r1: %d\n", area(&r1));
    printf("Area of r2: %d\n", area(&r2));
    printf("Do r1 and r2 intersect? %s\n", intersects(&r1, &r2) ? "Yes" : "No");
    printf("Intersection area of r1 and r2: %d\n", intersection_area(&r1, &r2));
    return 0;
}