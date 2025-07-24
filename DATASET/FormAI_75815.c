//FormAI DATASET v1.0 Category: Recursive ; Style: calm
#include <stdio.h>

// Recursive function to calculate the nth Fibonacci number
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n;
    printf("Enter the number of terms you want to calculate: ");
    scanf("%d",&n);
    printf("The first %d Fibonacci numbers are:\n",n);
    for (int i = 0; i < n; i++) {
        printf("%d ",fibonacci(i));
    }
    return 0;
}