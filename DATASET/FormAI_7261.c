//FormAI DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include<stdio.h>

int main()
{
    int a, b, c; //declaring three integers
    printf("Enter three integers:\n");
    scanf("%d %d %d", &a, &b, &c); //taking input from user

    //performing arithmetic operations on the given three integers
    printf("\nAddition of %d, %d and %d is %d", a, b, c, a+b+c);
    printf("\nSubtraction of %d from %d is %d", b, a, a-b);
    printf("\nMultiplication of %d with %d is %d", a, c, a*c);
    printf("\nDivision of %d by %d is %d", c, b, c/b);

    //checking the largest integer among the given three
    if(a>b && a>c)
        printf("\n%d is the largest integer", a);
    else if(b>c)
        printf("\n%d is the largest integer", b);
    else
        printf("\n%d is the largest integer", c);

    //checking whether the numbers are even or odd
    printf("\n\n%d is ", a);
    if(a%2==0)
        printf("even");
    else
        printf("odd");

    printf("\n%d is ", b);
    if(b%2==0)
        printf("even");
    else
        printf("odd");

    printf("\n%d is ", c);
    if(c%2==0)
        printf("even");
    else
        printf("odd");

    return 0;
}