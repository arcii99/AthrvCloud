//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the area of a polygon
float calcArea(int x[], int y[], int n)
{
    int i, j;
    float area = 0;
  
    // Shoelace formula
    for (i = 0; i < n; i++)
    {
        j = (i + 1) % n;
        area += x[i] * y[j];
        area -= y[i] * x[j];
    }
    area /= 2;
  
    return area;
}

// Main function
int main()
{
    int n, i;
    float area;
    
    // Reading inputs
    printf("Enter the number of vertices of the polygon: ");
    scanf("%d", &n);
    
    int x[n], y[n];
    
    for (i = 0; i < n; i++)
    {
        printf("Enter the x coordinate of vertex %d: ", i+1);
        scanf("%d", &x[i]);
    
        printf("Enter the y coordinate of vertex %d: ", i+1);
        scanf("%d", &y[i]);
    }
    
    // Calculating area and printing
    area = calcArea(x, y, n);
    printf("The area of the polygon is: %f", area);

    return 0;
}