//FormAI DATASET v1.0 Category: Recursive ; Style: innovative
#include <stdio.h>

void recursive_function(int n)
{
    if(n<=0)
        return;
    else
    {
        printf("%d\n", n);
        recursive_function(n-1);
        printf("Back to %d\n", n);
        recursive_function(n-2);
        printf("Back to %d\n", n);
    }
}

int main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    recursive_function(num);
    return 0;
}