//FormAI DATASET v1.0 Category: Recursive ; Style: Ken Thompson
#include <stdio.h>

void recursive_func(int n);

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    recursive_func(num);
    return 0;
}

void recursive_func(int n)
{
    if(n == 0 || n == 1)
        printf("%d ", n);
    else
    {
        recursive_func(n / 2);
        printf("%d ", n % 2);
    }
}