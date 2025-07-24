//FormAI DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>

int binary_search(int arr[], int n, int x)
{
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int result = binary_search(arr, n, x);
    if (result == -1) {
        printf("Oh dear, couldn't find your number..!");
    }
    else {
        printf("I found that the number you were looking for is present at index %d\n", result);
    }
    return 0;
}