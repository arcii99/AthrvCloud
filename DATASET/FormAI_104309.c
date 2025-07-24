//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: satisfied
#include <stdio.h>
#include <math.h>

// function to calculate the area of a triangle given its three vertices
float triangle_area(float x1, float y1, float x2, float y2, float x3, float y3) {
    float area = fabs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2.0);
    return area;
}

int main() {
    float x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the first vertex: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of the second vertex: ");
    scanf("%f %f", &x2, &y2);
    printf("Enter the coordinates of the third vertex: ");
    scanf("%f %f", &x3, &y3);
    float area = triangle_area(x1, y1, x2, y2, x3, y3);
    printf("The area of the triangle is: %.2f\n", area);
    return 0;
}