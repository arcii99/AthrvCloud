//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: energetic
#include <stdio.h>

int main() {
    printf("Let's find the area of a triangle using geometric algorithms!\n");
    
    // get user input
    float b, h;
    printf("Please enter the base of the triangle: ");
    scanf("%f", &b);
    printf("Please enter the height of the triangle: ");
    scanf("%f", &h);
    
    // calculate area using geometric algorithm
    float area = 0.5 * b * h;
    
    printf("The area of the triangle is: %f\n", area);
    printf("Amazing!\n");
    
    // bonus: find the length of the hypotenuse of a right triangle using the Pythagorean theorem
    float a, c;
    printf("Let's find the length of the hypotenuse of a right triangle using the Pythagorean theorem!\n");
    printf("Please enter the length of side a: ");
    scanf("%f", &a);
    printf("Please enter the length of side c: ");
    scanf("%f", &c);
    
    // calculate length of hypotenuse using Pythagorean theorem
    float hypotenuse = sqrt(a*a + c*c);
    
    printf("The length of the hypotenuse is: %f\n", hypotenuse);
    printf("Awesome!\n");
    
    return 0;
}