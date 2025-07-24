//FormAI DATASET v1.0 Category: Recursive ; Style: decentralized
#include <stdio.h>

// Function prototype
int recursive_sum(int num);

int main()
{
    int num, result;
    printf("Enter a number: ");
    scanf("%d", &num);

    result = recursive_sum(num);
    printf("Sum of numbers from 1 to %d is %d\n", num, result);
    return 0;
}

// Function to find sum of numbers from 1 to n recursively
int recursive_sum(int num)
{
    if(num == 0)
        return 0;
    else
        return num + recursive_sum(num-1); // recursive call
}