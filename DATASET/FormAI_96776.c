//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: peaceful
#include <stdio.h>

#define PI 3.14159

int main(){
    float radius, area;
    
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    
    area = PI * radius * radius;   // Geometric formula
    
    printf("The area of the circle is %.2f\n", area);
    
    return 0;
}