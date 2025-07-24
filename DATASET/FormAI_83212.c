//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include<stdio.h>
#include<stdlib.h>
int main()
{
    printf("Hey! Let me show you some cool geometric algorithms I can perform!\n");
    printf("Enter the radius of a circle: ");
    float radius;
    scanf("%f", &radius);
    float pi = 3.14;
    float area = pi * radius * radius;
    printf("The area of the circle with the entered radius is %f.\n", area);

    printf("Now let's calculate the hypotenuse of a right triangle.\n");
    printf("Enter the length of first leg: ");
    float leg1;
    scanf("%f", &leg1);
    printf("Enter the length of second leg: ");
    float leg2;
    scanf("%f", &leg2);
    float hypotenuse = sqrt(leg1 * leg1 + leg2 * leg2);
    printf("The hypotenuse of this right triangle is %f.\n", hypotenuse);

    printf("Let's move on to the next algorithm which is calculating the sides of a rectangle.\n");
    printf("Enter the perimeter of the rectangle: ");
    float perimeter;
    scanf("%f", &perimeter);
    float length = perimeter / 2;
    printf("Enter the length of the rectangle (half the rectangle's perimeter): %f\n", length);
    float width = perimeter / 2 - length;
    printf("The width of the rectangle is %f.\n", width);

    printf("One more algorithm to go! Let's calculate the area of a triangle with 3 given points.\n");
    printf("Enter the coordinates of the first point as (x,y): ");
    int x1, y1;
    scanf("%d,%d", &x1, &y1);
    printf("Enter the coordinates of the second point as (x,y): ");
    int x2, y2;
    scanf("%d,%d", &x2, &y2);
    printf("Enter the coordinates of the third point as (x,y): ");
    int x3, y3;
    scanf("%d,%d", &x3, &y3);

    float side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    float side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    float side3 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    float s = (side1 + side2 + side3) / 2;
    float triArea = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    printf("The area of the triangle with the entered coordinates is %f.\n", triArea);
    
    printf("Well, that's it. These were my cool geometric algorithms. Hope you had fun!\n");
    return 0;
}