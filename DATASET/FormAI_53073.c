//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: complex
#include <stdio.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} Point;

double distance(Point p1, Point p2) {
    double diff_x = p1.x - p2.x;
    double diff_y = p1.y - p2.y;
    
    return sqrt(diff_x * diff_x + diff_y * diff_y);
}

void isosceles_triangle(Point p1, Point p2, Point p3) {
    double side1, side2, side3;
    side1 = distance(p1, p2);
    side2 = distance(p2, p3);
    side3 = distance(p3, p1);
    
    if (side1 == side2 || side2 == side3 || side3 == side1) {
        printf("This triangle is isosceles.\n");
    } else {
        printf("This triangle is not isosceles.\n");
    }
}

Point midpoint(Point p1, Point p2) {
    Point midpoint;
    midpoint.x = (p1.x + p2.x) / 2;
    midpoint.y = (p1.y + p2.y) / 2;
    
    return midpoint;
}

double area(Point p1, Point p2, Point p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double s = (a + b + c) / 2;

    return sqrt(s * (s - a) * (s - b) * (s - c));   
}

int main() {
    Point p1 = {1, 1};
    Point p2 = {3, 5};
    Point p3 = {6, 2};
    
    isosceles_triangle(p1, p2, p3);
    printf("The midpoint of p1 and p2 is (%.1f, %.1f)\n", midpoint(p1, p2).x, midpoint(p1, p2).y);
    printf("The area of the triangle is %.2f\n", area(p1, p2, p3));
    
    return 0;
}