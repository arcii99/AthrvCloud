//FormAI DATASET v1.0 Category: Scientific ; Style: active
#include <stdio.h>

//function to calculate the area of a circle
float area_of_circle(float radius) {
    float area = 3.1416 * radius * radius;
    return area;
}

//function to calculate the perimeter of a circle
float perimeter_of_circle(float radius) {
    float perimeter = 2 * 3.1416 * radius;
    return perimeter;
}

//function to calculate the diameter of a circle
float diameter_of_circle(float radius) {
    float diameter = 2 * radius;
    return diameter;
}

int main() {
    float radius, area, perimeter, diameter;
    
    //asking user to enter the radius of the circle
    printf("Enter the radius of the circle (in cm): ");
    scanf("%f", &radius);
    
    //calculating the area of the circle
    area = area_of_circle(radius);
    printf("The area of the circle is %f sq. cm.\n", area);
    
    //calculating the perimeter of the circle
    perimeter = perimeter_of_circle(radius);
    printf("The perimeter of the circle is %f cm.\n", perimeter);
    
    //calculating the diameter of the circle
    diameter = diameter_of_circle(radius);
    printf("The diameter of the circle is %f cm.\n", diameter);
    
    return 0;
}