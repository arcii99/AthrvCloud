//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point {
    int x;
    int y;
} Point;

typedef struct rectangle {
    Point topLeft;
    Point bottomRight;
} Rectangle;

int calculateArea(Rectangle* r) {
    int width = r->bottomRight.x - r->topLeft.x;
    int height = r->bottomRight.y - r->topLeft.y;
    return width * height;
}

int main() {
    Rectangle r = {
        {0, 0},
        {10, 10}
    };
    int area = calculateArea(&r);
    printf("Area: %d\n", area);
    return 0;
}