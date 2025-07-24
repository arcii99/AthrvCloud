//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: mathematical
#include <stdio.h>
#include <math.h>

struct point {
    double x;
    double y;
};

typedef struct point Point;

double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

double perimeter(Point a, Point b, Point c) {
    return distance(a,b) + distance(b,c) + distance(a,c);
}

double area(Point a, Point b, Point c) {
    double s = perimeter(a,b,c) / 2.0;
    double ab = distance(a,b);
    double ac = distance(a,c);
    double bc = distance(b,c);
    return sqrt(s*(s-ab)*(s-ac)*(s-bc));
}

int main() {
    Point a, b, c;
    
    printf("Enter coordinates for Point A (x y): ");
    scanf("%lf %lf", &a.x, &a.y);
    
    printf("Enter coordinates for Point B (x y): ");
    scanf("%lf %lf", &b.x, &b.y);
    
    printf("Enter coordinates for Point C (x y): ");
    scanf("%lf %lf", &c.x, &c.y);
    
    printf("\nPerimeter of Triangle ABC: %.2lf units\n", perimeter(a,b,c));
    printf("Area of Triangle ABC: %.2lf square units\n", area(a,b,c));
    
    return 0;
}