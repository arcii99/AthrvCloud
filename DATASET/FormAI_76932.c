//FormAI DATASET v1.0 Category: Recursive ; Style: calm
#include <stdio.h>

int recursive_sum(int n);

int main()
{
    int n, sum;
    
    printf("Enter a positive integer n: ");
    scanf("%d", &n);
    
    sum = recursive_sum(n);
    
    printf("The sum of the first %d natural numbers is %d\n", n, sum);
    
    return 0;
}

int recursive_sum(int n)
{
    if (n == 1) // base case
    {
        return 1;
    }
    else // recursive case
    {
        return n + recursive_sum(n-1);
    }
}