//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include <stdio.h>

int main() {

    // Let's start by defining some points in 2D space 
    int x1 = 2, y1 = 3;  
    int x2 = 5, y2 = 1;  
    int x3 = 7, y3 = 5;  
    
    // Now, let's calculate the perimeter of a triangle ABC 
    float distanceAB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));  
    float distanceBC = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));  
    float distanceCA = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));  
    
    float perimeter = distanceAB + distanceBC + distanceCA;  
    
    // Print the perimeter of the triangle 
    printf("The perimeter of the triangle ABC is: %.2f\n", perimeter);  
    
    // Let's now calculate the area of the triangle ABC using Heron's formula 

    // First, calculate the semi-perimeter of the triangle 
    float s = (distanceAB + distanceBC + distanceCA) / 2;  
    
    // Then, use it to calculate the area of the triangle 
    float area = sqrt(s * (s - distanceAB) * (s - distanceBC) * (s - distanceCA));  
    
    // Print the area of the triangle 
    printf("The area of the triangle ABC is: %.2f\n", area);  
    
    return 0;  
}