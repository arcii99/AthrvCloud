//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: inquisitive
#include<stdio.h>
#include<math.h>

struct point{
     float x;
     float y;
};

// Function to calculate distance between two points
float distance(struct point a, struct point b)
{
    float dist = sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2));
    return dist;
}

// Function to calculate angle between three points
float angle(struct point x, struct point y, struct point z)
{
    float a, b, c, angle;
    a = distance(x, y);
    b = distance(y, z);
    c = distance(z, x);

    angle = acos((pow(a,2) + pow(b,2) - pow(c,2)) / (2*a*b));
    angle = angle * (180/M_PI);
    return angle;
}

// Function to check if points are collinear
int collinear(struct point a, struct point b, struct point c) 
{
    if ((b.y-a.y)*(c.x-b.x)-(c.y-b.y)*(b.x-a.x) == 0)
        return 1;
    else
        return 0;
}

int main()
{
    struct point p1, p2, p3;
    
    // Get inputs from user
    printf("Enter the coordinates of first point:\n");
    scanf("%f %f",&p1.x,&p1.y);
    printf("Enter the coordinates of second point:\n");
    scanf("%f %f",&p2.x,&p2.y);
    printf("Enter the coordinates of third point:\n");
    scanf("%f %f",&p3.x,&p3.y);

    // Print distance between two points
    printf("\nDistance between point 1 and point 2 is %f\n", distance(p1,p2));
    printf("Distance between point 2 and point 3 is %f\n", distance(p2,p3));
    printf("Distance between point 3 and point 1 is %f\n", distance(p3,p1));

    // Print angle between three points
    printf("\nAngle at point 1 is %f degrees\n", angle(p1,p2,p3));
    printf("Angle at point 2 is %f degrees\n", angle(p2,p3,p1));
    printf("Angle at point 3 is %f degrees\n", angle(p3,p1,p2));

    // Check if points are collinear
    if (collinear(p1,p2,p3))
        printf("\nThe three points are collinear\n");
    else
        printf("\nThe three points are not collinear\n");

    return 0;
}