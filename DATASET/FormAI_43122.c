//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    float x, y;
};

float distance(struct Point p1, struct Point p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

float areaOfTriangle(struct Point p1, struct Point p2, struct Point p3) {
    float a = distance(p1, p2);
    float b = distance(p1, p3);
    float c = distance(p2, p3);
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    struct Point p1, p2, p3;
    
    printf("Enter the coordinates for point 1 (x,y): ");
    scanf("%f,%f", &p1.x, &p1.y);
    
    printf("Enter the coordinates for point 2 (x,y): ");
    scanf("%f,%f", &p2.x, &p2.y);
    
    printf("Enter the coordinates for point 3 (x,y): ");
    scanf("%f,%f", &p3.x, &p3.y);
    
    float result = areaOfTriangle(p1, p2, p3);
    
    printf("Area of the triangle with vertices (%.2f,%.2f), (%.2f,%.2f), and (%.2f,%.2f) is = %.2f\n", 
            p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, result);
    
    return 0;
}