//FormAI DATASET v1.0 Category: Math exercise ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c;
    float area, perimeter, s;

    printf("Enter the Length of Sides:\n");
    scanf("%d %d %d", &a, &b, &c);

    if(a+b>c && a+c>b && b+c>a) //check if sides can form a triangle
    {
        printf("It forms a triangle.\n");

        /*Calculate the area of the triangle*/
        s = (float)(a+b+c)/2; //semi-perimeter
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        printf("The area of the Triangle: %.2f\n", area);

        /*Calculate the perimeter of the triangle*/
        perimeter = a+b+c;
        printf("The perimeter of the Triangle: %.2f\n", perimeter);
    }
    else
        printf("It does not form a triangle.\n");

    return 0;
}