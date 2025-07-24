//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: satisfied
#include <stdio.h>
#include <math.h>

typedef struct {
    double x; 
    double y; 
} Point;

double distance(Point p1, Point p2) {
    double x_diff = p1.x - p2.x;
    double y_diff = p1.y - p2.y;
    return sqrt(x_diff*x_diff + y_diff*y_diff);
}

double perimeter(Point pts[], int num_pts) {
    double perim = 0;
    for(int i = 0; i < num_pts; i++) {
        Point p1 = pts[i];
        Point p2 = (i == num_pts-1) ? pts[0] : pts[i+1];
        perim += distance(p1, p2);
    }
    return perim;
}

double area(Point pts[], int num_pts) {
    double area = 0;
    for(int i = 0; i < num_pts; i++) {
        Point p1 = pts[i];
        Point p2 = (i == num_pts-1) ? pts[0] : pts[i+1];
        area += (p1.x*p2.y - p2.x*p1.y);
    }
    return 0.5*fabs(area);
}

int main() {
    Point square_pts[] = { {0,0}, {0,1}, {1,1}, {1,0} };
    int num_square_pts = sizeof(square_pts)/sizeof(square_pts[0]);
    double square_perim = perimeter(square_pts, num_square_pts);
    double square_area = area(square_pts, num_square_pts);
    printf("A square with vertices at (0,0), (0,1), (1,1), and (1,0):\n");
    printf("Perimeter: %f\n", square_perim);
    printf("Area: %f\n", square_area);
    
    Point triangle_pts[] = { {0,0}, {1.5,4}, {3,0} };
    int num_triangle_pts = sizeof(triangle_pts)/sizeof(triangle_pts[0]);
    double triangle_perim = perimeter(triangle_pts, num_triangle_pts);
    double triangle_area = area(triangle_pts, num_triangle_pts);
    printf("\nA triangle with vertices at (0,0), (1.5,4), and (3,0):\n");
    printf("Perimeter: %f\n", triangle_perim);
    printf("Area: %f\n", triangle_area);
    
    return 0;
}