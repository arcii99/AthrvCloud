//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: active
#include<stdio.h>

struct point {
    double x, y;
};

double distance(struct point a, struct point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

double perimeter(struct point *points, int num_points) {
    double peri = 0.0;
    for(int i = 0; i < num_points - 1; i++) {
        peri += distance(points[i], points[i+1]);
    }
    peri += distance(points[num_points-1], points[0]);
    return peri;
}

double area(struct point *points, int num_points) {
    double ar = 0.0;
    int j = num_points - 1;
    for(int i = 0; i < num_points; i++) {
        ar += (points[j].x + points[i].x) * (points[j].y - points[i].y);
        j = i;
    }
    return fabs(ar/2.0);
}

int main() {
    struct point points[] = {{0,0}, {0,5}, {5,5}, {5,0}};
    int num_points = sizeof(points)/sizeof(points[0]);
    
    double peri = perimeter(points, num_points);
    printf("Perimeter of the polygon is: %lf\n", peri);
    
    double ar = area(points, num_points);
    printf("Area of the polygon is: %lf\n", ar);
    
    return 0;
}