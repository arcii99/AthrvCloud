//FormAI DATASET v1.0 Category: Recursive ; Style: distributed
#include <stdio.h>

// function to calculate the nth term of the Fibonacci sequence recursively
int fibonacci(int n)
{
    if(n==0) 
        return 0;
    else if(n==1) 
        return 1;
    else 
        return fibonacci(n-1) + fibonacci(n-2);
}

// function to distribute the calculation of the Fibonacci sequence to multiple nodes
int distribute_fibonacci(int n, int i, int numNodes)
{
    if(i == numNodes-1) // last node
        return fibonacci(n);
    else 
    {
        int a = i * (n/(float)numNodes);
        int b = (i+1) * (n/(float)numNodes);
        int result = 0;
        // send a and b to the next node for calculation
        result += distribute_fibonacci(a, i+1, numNodes);
        result += distribute_fibonacci(b, i+1, numNodes);
        return result;
    }
}

int main()
{
    int n, numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter the value of n to calculate the nth term of the Fibonacci sequence: ");
    scanf("%d", &n);
    int result = distribute_fibonacci(n, 0, numNodes);
    printf("The nth term of the Fibonacci sequence is %d\n", result);
    return 0;
}