//FormAI DATASET v1.0 Category: Math exercise ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Set up our main function
int main()
{
    // Initialize our variables
    int x, y, z;
    float a, b, c, d;
    
    // Get input from the user
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);
    printf("Enter the value of z: ");
    scanf("%d", &z);
    
    // Do some calculations
    a = pow(x, 2) + pow(y, 2);
    b = pow(y, 2) + pow(z, 2);
    c = sqrt(a) + sqrt(b);
    d = pow(c, 2) / pow(z, 2);
    
    // Print out the results
    printf("a is: %f\n", a);
    printf("b is: %f\n", b);
    printf("c is: %f\n", c);
    
    // Test if d is greater than pi
    if(d > M_PI)
    {
        printf("d is greater than pi.");
    }
    else
    {
        printf("d is less than or equal to pi.");
    }
    
    return 0;
}