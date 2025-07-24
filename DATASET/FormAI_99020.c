//FormAI DATASET v1.0 Category: Recursive ; Style: Linus Torvalds
#include <stdio.h>

int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

int main()
{
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    if(num < 0)
        printf("Error: Factorial of negative number does not exist.\n");
    else
        printf("Factorial of %d is %d.\n", num, factorial(num));
    return 0;
}