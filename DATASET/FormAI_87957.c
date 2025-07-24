//FormAI DATASET v1.0 Category: Educational ; Style: random
#include<stdio.h>

int main() {

    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    if(n % 2 == 0)
        printf("%d is even.\n", n);
    else
        printf("%d is odd.\n", n);

    int i, j;
    printf("Enter two integers separated by space: ");
    scanf("%d %d", &i, &j);

    printf("Sum of %d and %d is %d.\n", i, j, i+j);
    printf("Difference between %d and %d is %d.\n", i, j, i-j);
    printf("Product of %d and %d is %d.\n", i, j, i*j);
    
    float a, b, c;
    printf("Enter three floating point numbers separated by space: ");
    scanf("%f %f %f", &a, &b, &c);

    printf("Sum of %f, %f and %f is %f.\n", a, b, c, a+b+c);
    printf("Average of %f, %f and %f is %f.\n", a, b, c, (a+b+c)/3);

    return 0;
}