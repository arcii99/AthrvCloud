//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*This program takes input in the form of radians and finds the area of a pentagon, given its side length and the radius of its circumcircle */

int main()
{
    float rad, side, area;
    float pi = 3.1415926535;

    printf("Enter the value of radius:\n");
    scanf("%f",&rad);
    printf("Enter the value of side of pentagon:\n");
    scanf("%f",&side);

    //checking if the inputs are valid
    if(side<=0 || rad<=0)
    {
        printf("Invalid input. Please enter positive non-zero values.\n");
    }

    else
    {
        //finding the apothem using the formula (side/2)/tan(36)
        float apothem = (side/2)/tan(36*pi/180);

        //finding the area using the formula (5/2)*a*r
        area = (5*side*apothem)/2;

        printf("The area of the pentagon is: %0.2f\n",area);
    }

    return 0;

}