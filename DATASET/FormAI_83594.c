//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function to calculate the distance between two points
double calculateDistance(int x1, int y1, int x2, int y2)
{
    double distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));  //formula for distance calculation
    return distance;
}

//function to calculate the area of a triangle given its three sides
double calculateArea(int a, int b, int c)
{
    double s = (a + b + c) / 2.0;   //half the perimeter
    double area = sqrt(s*(s-a)*(s-b)*(s-c));  //formula for area calculation
    return area;
}

//function to check if three points are collinear
int checkCollinear(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if ((y3-y2)*(x2-x1) == (y2-y1)*(x3-x2))   //formula for checking collinearity
        return 1;   //collinear
    else
        return 0;   //not collinear
}

//main function
int main()
{
    int choice;
    do {
        printf("\n\nChoose an option:\n");
        printf("1. Calculate distance between two points\n");
        printf("2. Calculate area of a triangle\n");
        printf("3. Check if three points are collinear\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
            {
                int x1, y1, x2, y2;
                printf("\nEnter the coordinates of point 1 (x1 y1): ");
                scanf("%d %d", &x1, &y1);
                printf("Enter the coordinates of point 2 (x2 y2): ");
                scanf("%d %d", &x2, &y2);
                double distance = calculateDistance(x1, y1, x2, y2);
                printf("Distance between the two points: %lf", distance);
                break;
            }
            case 2:
            {
                int a, b, c;
                printf("\nEnter the three sides of the triangle (a b c): ");
                scanf("%d %d %d", &a, &b, &c);
                double area = calculateArea(a, b, c);
                printf("Area of the triangle: %lf", area);
                break;
            }
            case 3:
            {
                int x1, y1, x2, y2, x3, y3;
                printf("\nEnter the coordinates of point 1 (x1 y1): ");
                scanf("%d %d", &x1, &y1);
                printf("Enter the coordinates of point 2 (x2 y2): ");
                scanf("%d %d", &x2, &y2);
                printf("Enter the coordinates of point 3 (x3 y3): ");
                scanf("%d %d", &x3, &y3);
                int collinear = checkCollinear(x1, y1, x2, y2, x3, y3);
                if(collinear)
                    printf("The three points are collinear");
                else
                    printf("The three points are not collinear");
                break;
            }
            case 4:
            {
                printf("\nExiting program...");
                break;
            }
            default:
            {
                printf("\nInvalid option!");
                break;
            }
        }
    } while (choice != 4);
    
    return 0;
}