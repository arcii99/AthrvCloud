//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: scientific
#include <stdio.h>
#include <math.h>

// This program calculates the area and perimeter of a convex polygon using the shoelace formula

typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the area of a polygon using the shoelace formula
double polygon_area(Point points[], int num_points) {
    double area = 0;
    for (int i = 0; i < num_points; i++) {
        int j = i + 1 < num_points ? i + 1 : 0;
        area += points[i].x * points[j].y;
        area -= points[j].x * points[i].y;
    }
    return fabs(area / 2.0);
}

// Function to calculate the perimeter of a polygon
double polygon_perimeter(Point points[], int num_points) {
    double perimeter = 0;
    for (int i = 0; i < num_points; i++) {
        int j = i + 1 < num_points ? i + 1 : 0;
        double dx = points[j].x - points[i].x;
        double dy = points[j].y - points[i].y;
        perimeter += sqrt(dx * dx + dy * dy);
    }
    return perimeter;
}

// Main function to test the program
int main() {
    int num_points;
    printf("Enter the number of points in the polygon: ");
    scanf("%d", &num_points);
    Point points[num_points];
    for (int i = 0; i < num_points; i++) {
        printf("Enter the x and y coordinates of point %d: ", i+1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    double area = polygon_area(points, num_points);
    double perimeter = polygon_perimeter(points, num_points);
    printf("Area: %lf\nPerimeter: %lf\n", area, perimeter);
    return 0;
}