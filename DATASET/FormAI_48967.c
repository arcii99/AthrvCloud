//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: recursive
#include <stdio.h>

float area_of_triangle(float base, float height)
{
    if(base <= 0 || height <= 0)       // base cases
        return 0;
    
    float area = 0;                     // initialize area
    
    if(base == height)                  // check if equilateral triangle
    {
        float side = base;              // calculate side using base
        area = (sqrt(3) / 4) * side * side;
    }
    else if(base == 2*height)           // check if isosceles triangle
    {
        area = (height * height) / 2;
    } 
    else                                // for scalene triangle
    {
        float hypotenuse = sqrt((base * base) + (height * height));
        area = (base * height) / 2;
        float half_perimeter = (base + height + hypotenuse) / 2;
        area += area_of_triangle(hypotenuse, half_perimeter - base) + area_of_triangle(hypotenuse, half_perimeter - height);
    }
    return area;
}

int main()
{
    float base = 6;
    float height = 3;
    float area = area_of_triangle(base, height);
    printf("Area of triangle with base %.2f and height %.2f is %.2f\n", base, height, area);
    return 0;
}