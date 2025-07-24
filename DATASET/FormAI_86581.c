//FormAI DATASET v1.0 Category: Recursive ; Style: introspective
#include <stdio.h>

// Recursive function
int intro_recursive(int n)
{
    if(n == 0)
    {
        printf("I am the end of the recursion!\n");
        return 0;
    }
    else
    {
        printf("I am looking at n = %d\n", n);
        intro_recursive(n-1);
        printf("I am looking back at n = %d\n", n);
        return 0;
    }
}

int main()
{
    int num = 5;
    printf("Starting the recursive function...\n");
    intro_recursive(num);
    printf("Recursive function call ended.\n");
    return 0;
}