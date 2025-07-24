//FormAI DATASET v1.0 Category: Recursive ; Style: introspective
#include<stdio.h>

void recursive_function(int num);

int main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    recursive_function(num);
    
    return 0;
}

void recursive_function(int num)
{
    printf("Inside recursive_function with num = %d\n", num);

    if(num == 0)
    {
        printf("Reached the base case, num = 0\n");
        return;
    }
    else
    {
        printf("Calling recursive_function(%d)\n", num-1);
        recursive_function(num-1);
    }
}