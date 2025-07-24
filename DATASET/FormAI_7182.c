//FormAI DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main()
{
    int arr[] = { 2, 4, 6, 8, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;

    int index = search(arr, n, x);
    if (index == -1)
        printf("%d is not present in the array.\n", x);
    else
        printf("%d is present at index %d in the array.\n", x, index);
    return 0;
}