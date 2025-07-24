//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

/* This program calculates the area and perimeter of a triangle given the length of its three sides */

int main() {
    float a, b, c, s, area, perimeter;
    
    printf("Enter the length of side a: ");
    scanf("%f", &a);
    printf("Enter the length of side b: ");
    scanf("%f", &b);
    printf("Enter the length of side c: ");
    scanf("%f", &c);
    
    if (a + b > c && a + c > b && b + c > a) { // Checking the triangle inequality
        perimeter = a + b + c;
        s = perimeter / 2;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
        
        printf("Perimeter of the triangle is: %.2f\n", perimeter);
        printf("Area of the triangle is: %.2f\n", area);
    } else {
        printf("This is not a valid triangle.\n");
    }
    
    return 0;
}