//FormAI DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>

int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[10] = {5, 8, 3, 9, 1, 7, 2, 4, 6, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    int index = search(arr, n, x);
    if (index != -1)
    {
        printf("%d is found at index %d", x, index);
    }
    else
    {
        printf("%d is not found in the array", x);
    }
    return 0;
}