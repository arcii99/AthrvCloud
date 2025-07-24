//FormAI DATASET v1.0 Category: Scientific ; Style: satisfied
#include <stdio.h>
#include <math.h>

int main(void) {
    double x, y, result;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("Enter the value of y: ");
    scanf("%lf", &y);
    
    // calculate the value of cos(x) + sin(y)
    result = cos(x) + sin(y);
    printf("The value of cos(%.2lf) + sin(%.2lf) is %.2lf\n\n", x, y, result);
    
    // calculate the value of e raised to the power of x
    result = exp(x);
    printf("The value of e raised to the power of %.2lf is %.2lf\n\n", x, result);
    
    // calculate the value of natural logarithm of x
    result = log(x);
    printf("The natural logarithm of %.2lf is %.2lf\n\n", x, result);
    
    // calculate the value of x raised to the power of y
    result = pow(x, y);
    printf("The value of %.2lf raised to the power of %.2lf is %.2lf\n\n", x, y, result);
    
    // calculate the square root of x
    result = sqrt(x);
    printf("The square root of %.2lf is %.2lf\n\n", x, result);
    
    // calculate the absolute value of x
    result = fabs(x);
    printf("The absolute value of %.2lf is %.2lf\n\n", x, result);

    return 0;
}