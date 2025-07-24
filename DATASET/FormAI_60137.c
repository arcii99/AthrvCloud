//FormAI DATASET v1.0 Category: Digital signal processing ; Style: careful
#include<stdio.h>
#include<math.h>

#define PI 3.14159265

int main()
{
    int n, i;
    float x[50], y[50], a, b, w, theta;

    printf("Enter the number of samples: ");
    scanf("%d",&n);

    printf("Enter the values of x[n]: ");
    for(i=0; i<n; i++)
        scanf("%f",&x[i]);

    printf("Enter the values of w: ");
    scanf("%f",&w);

    theta = (w*2*PI)/(float)n; // calculate theta
    
    a = cos(theta); // calculate coefficients a and b
    b = sin(theta);

    y[0] = x[0]; // initial value of y[0]

    for(i=1; i<n; i++)
        y[i] = (a*y[i-1] + b*x[i] - b*y[i-1]); // filter equation

    printf("Original signal: ");
    for(i=0; i<n; i++)
        printf("%6.2f",x[i]);

    printf("\nFiltered signal: ");
    for(i=0; i<n; i++)
        printf("%6.2f",y[i]);

    return 0;
}