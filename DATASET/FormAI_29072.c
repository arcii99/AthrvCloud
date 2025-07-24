//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// function to calculate the area of a triangle 
double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double area;
    area = abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))/2);
    return area;
}

// function to determine if a point lies inside a triangle
int point_in_triangle(double x1, double y1, double x2, double y2, double x3, double y3, double xp, double yp) {
    double area, area1, area2, area3;
    area = triangle_area(x1, y1, x2, y2, x3, y3);
    area1 = triangle_area(x1, y1, x2, y2, xp, yp);
    area2 = triangle_area(x2, y2, x3, y3, xp, yp);
    area3 = triangle_area(x3, y3, x1, y1, xp, yp);
    if(area == (area1 + area2 + area3)) {
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    double x1, y1, x2, y2, x3, y3, xp, yp;
    printf("Enter the x and y coordinates of the first point (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter the x and y coordinates of the second point (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter the x and y coordinates of the third point (x3 y3): ");
    scanf("%lf %lf", &x3, &y3);
    printf("Enter the x and y coordinates of the point you want to check (xp yp): ");
    scanf("%lf %lf", &xp, &yp);
    if(point_in_triangle(x1, y1, x2, y2, x3, y3, xp, yp)) {
        printf("The point (%.2lf, %.2lf) is inside the triangle.\n", xp, yp);
    }
    else{
        printf("The point (%.2lf, %.2lf) is not inside the triangle.\n", xp, yp);
    }
    return 0;
}