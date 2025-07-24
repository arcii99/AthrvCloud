//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>
void recursiveFunction(int n)
{
    if (n <= 0)
    {
        printf("All done, time to break free and exit the function!");
        return;
    }
  
    printf("I'm loving recursion and can't get enough of it, We are now at %d\n", n);
    recursiveFunction(n-1);
}

int main()
{
    int n = 10;
    recursiveFunction(n);
    return 0;
}