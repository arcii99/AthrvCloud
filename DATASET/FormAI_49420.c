//FormAI DATASET v1.0 Category: Scientific ; Style: brave
#include <stdio.h>
#include <math.h>

int main()
{
    printf("Welcome to the brave new world of scientific programming!\n");
    printf("Let's calculate the area and circumference of a circle with a radius of 5...\n\n");
    
    float radius = 5;
    float area = M_PI*pow(radius, 2);
    float circumference = 2*M_PI*radius;
    
    printf("The area of a circle with a radius of %.2f is %.2f square units.\n", radius, area);
    printf("The circumference of a circle with a radius of %.2f is %.2f units.\n\n", radius, circumference);
    
    printf("Now let's play with some trigonometric functions...\n\n");
    
    float angle = 30;
    float radians = angle*M_PI/180;
    
    printf("The sine of %f degrees is %.2f.\n", angle, sin(radians));
    printf("The cosine of %f degrees is %.2f.\n", angle, cos(radians));
    printf("The tangent of %f degrees is %.2f.\n\n", angle, tan(radians));
    
    printf("Let's also calculate the square root of 2 and Euler's number...\n\n");
    
    float sqrt2 = sqrt(2);
    float e = exp(1);
    
    printf("The square root of 2 is %.2f.\n", sqrt2);
    printf("Euler's number is %.2f.\n\n", e);
    
    printf("That's it for now. Stay brave, keep coding!\n");
    
    return 0;
}