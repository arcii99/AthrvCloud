//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: rigorous
/*Program to find the area of a polygon using the Shoelace formula*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point{
    int x,y;
};

int main()
{
    int n,i;
    float area=0.0;

    printf("Enter the number of vertices of polygon: ");
    scanf("%d",&n);

    struct point p[n];

    printf("\nEnter the coordinates of the vertices:\n");

    for(i=0;i<n;i++)
    {
        printf("\nVertex %d : ",i+1);
        scanf("%d%d",&p[i].x,&p[i].y);
    }

    //Calculate area using Shoelace Formula

    for(i=0;i<n-1;i++)
    {
        area+=p[i].x*p[i+1].y-p[i+1].x*p[i].y;
    }

    area+=(p[n-1].x*p[0].y-p[0].x*p[n-1].y);

    area=fabs(area/2);

    printf("\nThe area of the polygon is: %.2f",area);

    return 0;
}