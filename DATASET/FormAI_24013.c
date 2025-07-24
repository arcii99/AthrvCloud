//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: statistical
#include <stdio.h>
#include <math.h>

// This program calculates the area and perimeter of a circle using geometric formulas with the given radius.

int main()
{
    // Define the radius variable.
    float radius;
    
    // Receive the radius value from the user.
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    
    // Calculate the area and perimeter of the circle using geometric formulas.
    float area = M_PI * pow(radius, 2);
    float perimeter = 2 * M_PI * radius;
    
    // Display the calculated values.
    printf("The area of the circle is: %f\n", area);
    printf("The perimeter of the circle is: %f\n", perimeter);
    
    return 0;
}