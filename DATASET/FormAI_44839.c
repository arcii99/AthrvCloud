//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: light-weight
#include <stdio.h>
#include <math.h>

double polygonArea(double X[], double Y[], int n) 
{
    double area = 0.0;
    int j = n-1;
    for (int i=0; i<n; i++) 
    {
        area += (X[j]+X[i]) * (Y[j]-Y[i]); 
        j = i;
    }
    return fabs(area/2);
}

int main() 
{ 
    int n = 5;
    double X[] = {0, 1, 2, 1, 0};
    double Y[] = {0, 0, 1, 2, 1};
    
    double area = polygonArea(X, Y, n);
    
    printf("The area of the polygon is: %lf\n", area);
    
    return 0;
}