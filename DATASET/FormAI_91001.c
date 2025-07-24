//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Ada Lovelace
#include <stdio.h>

#define PI 3.14159

int main()
{
    float radius, area, perimeter;
    
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    
    // Calculate the area of the circle
    area = PI * radius * radius;
    
    // Calculate the perimeter of the circle
    perimeter = 2 * PI * radius;
    
    printf("The area of the circle is: %f\n", area);
    printf("The perimeter of the circle is: %f\n", perimeter);
    
    return 0;
}