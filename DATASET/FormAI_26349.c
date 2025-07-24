//FormAI DATASET v1.0 Category: Recursive ; Style: satisfied
#include <stdio.h>

void recurse(int num)
{
    if(num <= 0)
        return;
    printf("%d\n", num);
    recurse(num - 1);
}

int sum(int arr[], int n)
{
    if(n <= 0)
        return 0;
    return (arr[n - 1] + sum(arr, n - 1));
}

int main()
{
    // recursive function to print numbers from 10 to 1
    printf("Printing numbers using recursion:\n");
    recurse(10);
    
    // recursive function to calculate sum of array elements
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Sum of array elements: %d", sum(arr, n));
    
    return 0;
}