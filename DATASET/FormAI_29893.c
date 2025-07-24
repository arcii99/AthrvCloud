//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: realistic
#include <stdio.h>
#include <math.h>

//Function to calculate the distance between two points (x1, y1) and (x2, y2)
double distance(double x1, double y1, double x2, double y2)
{
    double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return dist;
}

//Function to check if a point (x, y) lies inside a circle with center (cx, cy) and radius r
int pointInsideCircle(double x, double y, double cx, double cy, double r)
{
    if (distance(x, y, cx, cy) <= r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    //Taking input from the user
    double cx, cy, r;
    printf("Enter the center coordinates and radius of the circle: ");
    scanf("%lf %lf %lf", &cx, &cy, &r);

    //Calculating the area of the circle
    double area = M_PI * pow(r, 2);
    printf("Area of the circle is: %lf\n", area);

    //Checking if a point inside or outside the circle
    double x, y;
    printf("Enter the x and y coordinates of a point: ");
    scanf("%lf %lf", &x, &y);
    if (pointInsideCircle(x, y, cx, cy, r))
    {
        printf("The point (%lf,%lf) lies inside the circle.\n", x, y);
    }
    else
    {
        printf("The point (%lf,%lf) lies outside the circle.\n", x, y);
    }

    return 0;
}