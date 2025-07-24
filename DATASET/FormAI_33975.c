//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: satisfied
#include <stdio.h>
#include <math.h>

int main() {
    // Define the coordinates of three points in a 2D plane
    int x1 = 1, y1 = 1;
    int x2 = 4, y2 = 4;
    int x3 = 2, y3 = 6;
    
    // Calculate the distance between points (x1,y1) and (x2,y2)
    double distance12 = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    
    // Calculate the distance between points (x2,y2) and (x3,y3)
    double distance23 = sqrt(pow((x3-x2),2) + pow((y3-y2),2));
    
    // Calculate the distance between points (x3,y3) and (x1,y1)
    double distance31 = sqrt(pow((x1-x3),2) + pow((y1-y3),2));
    
    // Calculate the semi-perimeter of the triangle
    double s = (distance12 + distance23 + distance31) / 2;
    
    // Calculate the area of the triangle using Heron's formula
    double area = sqrt(s*(s-distance12)*(s-distance23)*(s-distance31));
    
    // Calculate the perimeter of the triangle
    double perimeter = distance12 + distance23 + distance31;
    
    // Print the results
    printf("The sides of the triangle have lengths: %.2f, %.2f, and %.2f \n", distance12, distance23, distance31);
    printf("The perimeter of the triangle is: %.2f \n", perimeter);
    printf("The area of the triangle is: %.2f \n", area);
    
    return 0;
}