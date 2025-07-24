//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: scientific
#include<stdio.h>
#include<math.h>

// function to calculate the distance between two points
float dist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
}

// function to find the area of a triangle given its three sides
float areaOfTriangle(float a, float b, float c)
{
    float s = (a + b + c) / 2;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

int main()
{
    int x1,x2,x3,y1,y2,y3;
    printf("Enter the coordinates of 3 points (x,y): \n");
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);

    // calculate the distance between each pair of points using the dist() function
    float a = dist(x1,y1,x2,y2);
    float b = dist(x2,y2,x3,y3);
    float c = dist(x3,y3,x1,y1);

    // calculate the perimeter of the triangle using the distances
    float perimeter = a + b + c;

    // calculate the semi-perimeter of the triangle
    float s = perimeter / 2;

    // calculate the area of the triangle using the areaOfTriangle() function
    float area = areaOfTriangle(a,b,c);

    // output the results
    printf("\nThe distances between the points are: ");
    printf("\na = %.2f",a);
    printf("\nb = %.2f",b);
    printf("\nc = %.2f",c);
    printf("\nThe perimeter of the triangle is: %.2f",perimeter);
    printf("\nThe semi-perimeter of the triangle is: %.2f",s);
    printf("\nThe area of the triangle is: %.2f",area);

    return 0;
}