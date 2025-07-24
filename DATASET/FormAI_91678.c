//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: minimalist
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle given its three sides
float triangleArea(float a, float b, float c) {
    float p = (a + b + c) / 2; // Calculate half of the perimeter
    return sqrt(p * (p - a) * (p - b) * (p - c)); // Use Heron's formula to calculate the area
}

// Function to calculate the distance between two points in a 2D plane
float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // Use the Pythagorean theorem 
}

// Function to determine if a point is inside a circle given the circle's center and radius
int pointInsideCircle(float x, float y, float centerX, float centerY, float radius) {
    float dist = distance(x, y, centerX, centerY); // Calculate the distance between the point and circle center
    return dist <= radius; // Return whether the distance is less than or equal to the radius
}

int main() {
    float triangleSides[3];
    printf("Enter the three sides of a triangle separated by spaces: ");
    scanf("%f %f %f", &triangleSides[0], &triangleSides[1], &triangleSides[2]);
    float triangleAreaValue = triangleArea(triangleSides[0], triangleSides[1], triangleSides[2]);
    printf("The area of the triangle is %f\n", triangleAreaValue);
    
    float circleCenter[2], circleRadius;
    printf("Enter the x and y coordinates of the circle center and its radius: ");
    scanf("%f %f %f", &circleCenter[0], &circleCenter[1], &circleRadius);
    float point[2];
    printf("Enter the x and y coordinates of a point: ");
    scanf("%f %f", &point[0], &point[1]);
    int pointInside = pointInsideCircle(point[0], point[1], circleCenter[0], circleCenter[1], circleRadius);
    printf("The point is %s the circle.\n", pointInside ? "inside" : "outside");
    
    return 0;
}