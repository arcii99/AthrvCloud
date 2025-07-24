//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: minimalist
#include <stdio.h>

struct Point 
{
    double x;
    double y;
};

struct Line
{
    struct Point p1;
    struct Point p2;
};

double length(struct Point p1, struct Point p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main()
{
    struct Point p1, p2, p3;
    struct Line l1, l2;

    /* Enter Points */
    printf("Enter the x and y coordinates of Point 1: ");
    scanf("%lf %lf", &p1.x, &p1.y);

    printf("Enter the x and y coordinates of Point 2: ");
    scanf("%lf %lf", &p2.x, &p2.y);

    printf("Enter the x and y coordinates of Point 3: ");
    scanf("%lf %lf", &p3.x, &p3.y);

    /* Create Lines */
    l1.p1 = p1;
    l1.p2 = p2;

    l2.p1 = p1;
    l2.p2 = p3;

    /* Calculate Lengths */
    double len1 = length(l1.p1, l1.p2);
    double len2 = length(l2.p1, l2.p2);

    /* Determine longest line */
    if (len1 > len2)
    {
        printf("Line 1 is longer with a length of %.2lf", len1);
    }
    else if (len2 > len1)
    {
        printf("Line 2 is longer with a length of %.2lf", len2);
    }
    else
    {
        printf("Both lines are the same length");
    }

    return 0;
}