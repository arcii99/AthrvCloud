//FormAI DATASET v1.0 Category: Recursive ; Style: synchronous
#include <stdio.h>

// This function returns the nth fibonacci number
int fibonacci(int num)
{
    // base cases
    if(num == 0)
        return 0;
    else if(num == 1)
        return 1;
    else
        // recursive case
        return fibonacci(num-1) + fibonacci(num-2);
}

int main()
{
    int i;
    
    // Print first 20 fibonacci numbers
    printf("First 20 fibonacci numbers:\n");
    for(i=0; i<20; i++)
    {
        printf("%d ", fibonacci(i));
    }
    
    return 0;
}