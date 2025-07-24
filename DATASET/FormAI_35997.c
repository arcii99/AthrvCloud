//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include <stdio.h>

int main()
{
    int n;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    int points[n][2];

    for(int i=0; i<n; i++)
    {
        printf("Enter the point %d: ", i+1);
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    float polygonArea = 0;

    for(int i=0; i<n-1; i++)
    {
        polygonArea += (points[i][0]*points[i+1][1] - points[i+1][0]*points[i][1]);
    }

    polygonArea += (points[n-1][0]*points[0][1] - points[0][0]*points[n-1][1]);

    polygonArea = polygonArea/2;

    printf("The area of the polygon is %.2f square units", polygonArea);

    return 0;
}