//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: enthusiastic
#include<stdio.h>

int main(){
    
    puts("Welcome to the Geometric Algorithms program!");
    puts("This program will calculate the area and perimeter of a triangle.");

    double base, height, a, b, c, perimeter, semiperimeter, area;
    
    printf("\nEnter the length of base: ");
    scanf("%lf", &base);
    printf("Enter the length of height: ");
    scanf("%lf", &height);
    printf("Enter the length of side a: ");
    scanf("%lf", &a);
    printf("Enter the length of side b: ");
    scanf("%lf", &b);
    printf("Enter the length of side c: ");
    scanf("%lf", &c);

    perimeter = a + b + c;
    semiperimeter = perimeter / 2; 
    area = 0.5 * base * height;

    printf("\nPerimeter of the triangle is: %.2lf", perimeter);
    printf("\nSemiperimeter of the triangle is: %.2lf", semiperimeter);
    printf("\nArea of the triangle is: %.2lf", area);

    return 0;
}