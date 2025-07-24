//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>

int uniqueSearch(int arr[], int n, int x)
{
    int i, count = 0;
    
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            count++;
            printf("%d was found at index %d.\n", x, i);
        }
    }
    if (count == 0)
    {
        printf("%d was not found in the array.\n", x);
        return -1;
    }
    else if (count == 1)
    {
        return i - 1;
    }
    else
    {
        printf("%d was found %d times in the array.\n", x, count);
        return -1;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x;
    
    printf("Enter a number to find in the array: ");
    scanf("%d", &x);
    
    uniqueSearch(arr, size, x);
    
    return 0;
}