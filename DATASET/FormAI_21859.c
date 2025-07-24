//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: standalone
#include<stdio.h>
#include<math.h>

struct point {
    double x;
    double y;
};

struct line {
    struct point p1;
    struct point p2;
};

double distance(struct point p1, struct point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

double findPerimeter(struct line l1, struct line l2, struct line l3) {
    double side1 = distance(l1.p1, l1.p2);
    double side2 = distance(l2.p1, l2.p2);
    double side3 = distance(l3.p1, l3.p2);
    return side1 + side2 + side3;
}

int main() {
    struct point p1 = {0, 0};
    struct point p2 = {4, 0};
    struct point p3 = {0, 3};
    
    struct line l1 = {p1, p2};
    struct line l2 = {p2, p3};
    struct line l3 = {p3, p1};
    
    double perimeter = findPerimeter(l1, l2, l3);
    
    printf("Perimeter of the triangle is: %lf", perimeter);
    
    return 0;
}