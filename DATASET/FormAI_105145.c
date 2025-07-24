//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: excited
#include <stdio.h>
#include <math.h>

// This is an exciting geometric algorithm that calculates the area of a circle!

int main() {
    printf("Welcome to the circle area calculator!\n");
    float radius = 0;
    printf("Please enter the radius of your circle: ");
    scanf("%f", &radius);
    
    // The formula for calculating the area of a circle is: A = pi * r^2
    float area = M_PI * pow(radius, 2);
    printf("The area of your circle with radius %.2f is %.2f!\n", radius, area);
    
    // But wait, there's more! Let's now calculate the circumference of the circle.
    float circumference = 2 * M_PI * radius;
    printf("The circumference of your circle with radius %.2f is %.2f!\n", radius, circumference);
    
    // Hmm, this is fun. Let's see if we can find the diameter of the circle too.
    float diameter = 2 * radius;
    printf("The diameter of your circle with radius %.2f is %.2f!\n", radius, diameter);
    
    // This is getting addictive. Let's find the area of a square with the same perimeter as the circle.
    // The perimeter of a circle is 2 * pi * radius and the perimeter of a square is 4 * side.
    // So, 2 * pi * radius = 4 * side. Thus, side = pi * radius / 2.
    float side = M_PI * radius / 2;
    float squareArea = pow(side, 2);
    printf("The area of a square with the same perimeter as your circle is %.2f!\n", squareArea);
    
    // This was so much fun! Let's do it again for another circle.
    printf("\nLet's calculate the area of another circle!\n");
    printf("Please enter the radius of your second circle: ");
    scanf("%f", &radius);
    area = M_PI * pow(radius, 2);
    printf("The area of your second circle with radius %.2f is %.2f!\n", radius, area);
    
    // This was amazing! The world of geometric algorithms is truly exciting!
    return 0;
}