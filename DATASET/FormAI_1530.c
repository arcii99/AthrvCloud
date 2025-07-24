//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i, j, area = 0;
    scanf("%d",&n);

    int** points = (int**)malloc(n*sizeof(int*));
    for(i = 0; i < n; i++)
        points[i] = (int*)malloc(2*sizeof(int));

    printf("Enter the coordinates of the vertices:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d %d",&points[i][0],&points[i][1]);
    }

    //calculating area using shoelace formula
    for(i = 0; i < n; i++)
    {
        area += (points[i][0] * points[(i+1)%n][1]) - (points[i][1] * points[(i+1)%n][0]);
    }
    area = abs(area)/2;
    printf("Area of polygon: %d\n",area);

    //finding centroid
    float cx=0,cy=0;
    for(i = 0; i < n; i++)
    {
        cx += (points[i][0]+points[(i+1)%n][0])*(points[i][0]*points[(i+1)%n][1]-points[(i+1)%n][0]*points[i][1]);
        cy += (points[i][1]+points[(i+1)%n][1])*(points[i][0]*points[(i+1)%n][1]-points[(i+1)%n][0]*points[i][1]);
    }
    cx = cx/(6*area);
    cy = cy/(6*area);
    printf("Centroid: (%.2f, %.2f)", cx, cy);

    return 0;
}