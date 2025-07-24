//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle using its vertices
float area_of_triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    return fabs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

// Function to check if a point is inside a given triangle using barycentric coordinates
int is_point_inside_triangle(float x1, float y1, float x2, float y2, float x3, float y3, float x, float y) {
    float A = area_of_triangle(x1, y1, x2, y2, x3, y3);
    float A1 = area_of_triangle(x, y, x2, y2, x3, y3);
    float A2 = area_of_triangle(x1, y1, x, y, x3, y3);
    float A3 = area_of_triangle(x1, y1, x2, y2, x, y);
    return (A == A1 + A2 + A3);
}

int main() {
    float x1, y1, x2, y2, x3, y3, x, y;
    printf("Enter the coordinates of the first vertex of the triangle (x1 y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of the second vertex of the triangle (x2 y2): ");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates of the third vertex of the triangle (x3 y3): ");
    scanf("%f %f", &x3, &y3);
    printf("Enter the coordinates of the point to check if it is inside the triangle (x y): ");
    scanf("%f %f", &x, &y);
    if(is_point_inside_triangle(x1, y1, x2, y2, x3, y3, x, y)) {
        printf("\nPoint (%.2f, %.2f) is inside the triangle.\n", x, y);
    } else {
        printf("\nPoint (%.2f, %.2f) is outside the triangle.\n", x, y);
    }
    return 0;
}