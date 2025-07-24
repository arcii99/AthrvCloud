//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: scientific
/*
Title: Area of a Polygon
Description: This program calculates the area of a polygon using the Shoelace Formula. 
Author: John Doe
Date: August 23, 2021
*/

#include <stdio.h>  //Standard Input/Output Library
#include <math.h>

int main()
{
    int n;  //Number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    float x[n], y[n];  //Arrays to store the x and y coordinates of vertices
    printf("Enter the coordinates of vertices:\n");

    for(int i=0; i<n; i++)
    {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }

    //Calculating the area using the Shoelace Formula
    float area = 0;
    for(int i=0; i<n-1; i++)
    {
        area += (x[i]*y[i+1] - x[i+1]*y[i]);
    }
    area += (x[n-1]*y[0] - x[0]*y[n-1]);
    area = fabs(area)/2;

    printf("The area of the polygon is: %0.2f\n", area);

    return 0;
}