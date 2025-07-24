//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Claude Shannon
#include <stdio.h>

// Function to calculate the area of a triangle
float triangle_area(float x1, float y1, float x2, float y2, float x3, float y3) {
    float area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
    return (area >= 0) ? area : -area;
}

// Function to check if a point lies inside a triangle
int point_in_triangle(float x, float y, float x1, float y1, float x2, float y2, float x3, float y3) {
    float area1, area2, area3, triangle_area_total;
    triangle_area_total = triangle_area(x1, y1, x2, y2, x3, y3);
    area1 = triangle_area(x, y, x2, y2, x3, y3);
    area2 = triangle_area(x1, y1, x, y, x3, y3);
    area3 = triangle_area(x1, y1, x2, y2, x, y);
    return triangle_area_total == (area1 + area2 + area3);
}

// Main function to execute the program
int main() {
    // Initialize points of a triangle
    float x1 = 0.0, y1 = 0.0;
    float x2 = 3.0, y2 = 0.0;
    float x3 = 0.0, y3 = 4.0;
    
    // Initialize point to check
    float x = 1.0, y = 1.0;
    
    // Check if point lies inside the triangle
    if (point_in_triangle(x, y, x1, y1, x2, y2, x3, y3)) {
        printf("The point (%.2f,%.2f) lies inside the triangle.\n", x, y);
    } else {
        printf("The point (%.2f,%.2f) does not lie inside the triangle.\n", x, y);
    }
    
    return 0;
}