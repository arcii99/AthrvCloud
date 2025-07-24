//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: unmistakable
#include<stdio.h>
#include<math.h>

//This program calculates the area of a circle using geometric algorithms.

int main() {
    float radius, area;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    
    if(radius <= 0) {
        printf("Invalid radius!\n");
        return 0;
    }
    
    area = M_PI * pow(radius, 2);
    printf("The area of the circle is: %f\n", area);
    
    return 0;
}