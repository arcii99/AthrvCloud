//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function to find area of a triangle using Heron's formula
double triangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2;   //Calculate semi-perimeter
    double area = sqrt(s * (s-a) * (s-b) * (s-c));    //Apply Heron's formula
    return area;
}

//Function to calculate distance between two points in 2D Coordinate System
double distance(double x1, double y1, double x2, double y2){
    double dist = sqrt(pow(x2-x1,2)+pow(y2-y1,2));    //Calculate Euclidean distance
    return dist;
}

int main() {
    double ax,ay,bx,by,cx,cy;   //Coordinates of triangle vertices
    printf("Enter the coordinates of point A: ");
    scanf("%lf %lf",&ax,&ay);
    printf("Enter the coordinates of point B: ");
    scanf("%lf %lf",&bx,&by);
    printf("Enter the coordinates of point C: ");
    scanf("%lf %lf",&cx,&cy);

    //Calculate lengths of all sides of triangle
    double AB = distance(ax,ay,bx,by);
    double AC = distance(ax,ay,cx,cy);
    double BC = distance(bx,by,cx,cy);

    //Calculate area of the triangle using Heron's formula
    double area = triangleArea(AB,AC,BC);

    printf("The area of the triangle with vertices A(%0.2lf,%0.2lf), B(%0.2lf,%0.2lf) and C(%0.2lf,%0.2lf) is %0.2lf\n",ax,ay,bx,by,cx,cy,area);
    return 0;
}