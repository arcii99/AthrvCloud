//FormAI DATASET v1.0 Category: Searching algorithm ; Style: real-life
#include <stdio.h>

// Function to search an element in an array
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {5, 10, 15, 20, 25, 30, 35};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the value you want to search: ");
    int x;
    scanf("%d", &x);

    int result = search(arr, n, x);
    if (result == -1)
        printf("Element not found!");
    else
        printf("Element found at index %d", result);

    return 0;
}