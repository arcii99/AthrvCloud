//FormAI DATASET v1.0 Category: Math exercise ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, d, e, f; // 6 variables for the multivariable equation
    float x, y, z; // 3 variables for the solutions of the equation
    printf("Enter six values for the equation ax + by + cz + d = e + fx + gy + hz:\n");
    printf("a: "); scanf("%d", &a);
    printf("b: "); scanf("%d", &b);
    printf("c: "); scanf("%d", &c);
    printf("d: "); scanf("%d", &d);
    printf("e: "); scanf("%d", &e);
    printf("f: "); scanf("%d", &f);
    
    if(a*c - b*b == 0) // check if the equation is solvable
    {
        printf("The equation is not solvable!\n");
        return 0;
    }
    else
    {
        y = (a*f - c*d) / (a*c - b*b); // calculate the solution for y
        x = (d - b*y) / a; // calculate the solution for x
        z = (e - a*x - b*y) / c; // calculate the solution for z

        printf("The solution for x is: %.2f\n", x);
        printf("The solution for y is: %.2f\n", y);
        printf("The solution for z is: %.2f\n", z);
        return 0;
    }
}