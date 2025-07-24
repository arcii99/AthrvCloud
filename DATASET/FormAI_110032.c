//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: portable
#include <stdio.h>

int main()
{
    unsigned int n, i, firstNum = 0, secondNum = 1, nextNum;
    
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%u", &n);

    printf("Fibonacci Sequence:\n");
    printf("%u ", firstNum);
    
    if(n > 1)
    {
        printf("%u ", secondNum);
    }
    
    for(i=2; i<n; ++i)
    {
        nextNum = firstNum + secondNum;
        printf("%u ", nextNum);
        firstNum = secondNum;
        secondNum = nextNum;
    }
    return 0;
}