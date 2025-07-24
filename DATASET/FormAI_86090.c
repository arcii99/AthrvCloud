//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>

int Sherlock_Search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            printf("Element found at index %d\n", i);
            return 1;
        }
    }
    printf("Element not found in the array.\n");
    return 0;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10, x = 6;
    
    int result = Sherlock_Search(arr, n, x);
    
    return 0;
}