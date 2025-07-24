//FormAI DATASET v1.0 Category: Recursive ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

int recursiveSum(int num)
{
    if(num <= 0)
    {
        return 0; // Base case
    }
    else
    {
        return num + recursiveSum(num - 1); // Recursive function call 
    }
}

int main()
{
    int n;
    printf("Enter the number of terms for sum: ");
    scanf("%d", &n);
    printf("The sum of first %d natural numbers is %d", n, recursiveSum(n)); // Calling the recursive function
    
    return 0;
}