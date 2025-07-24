//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    float x;
    float y;
};

float distance(struct Point p1, struct Point p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

float area(struct Point p1, struct Point p2, struct Point p3) {
    float a = distance(p1, p2);
    float b = distance(p2, p3);
    float c = distance(p3, p1);
    float s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

void print_point(struct Point p) {
    printf("(%f, %f)", p.x, p.y);
}

int main() {
    struct Point a = {0.0, 0.0};
    struct Point b = {3.0, 0.0};
    struct Point c = {1.5, 2.6};
    
    printf("Points:\n");
    print_point(a);
    printf(", ");
    print_point(b);
    printf(", ");
    print_point(c);
    printf("\n\n");
    
    printf("Distances:\n");
    printf("AB: %f\n", distance(a, b));
    printf("BC: %f\n", distance(b, c));
    printf("CA: %f\n", distance(c, a));
    printf("\n");
    
    printf("Area of ABC: %f\n", area(a, b, c));
    
    return 0;
}