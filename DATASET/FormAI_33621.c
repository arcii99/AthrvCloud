//FormAI DATASET v1.0 Category: Searching algorithm ; Style: expert-level
#include <stdio.h>

int interpolation_search(int arr[], int n, int x)
{
    int lo = 0, hi = (n - 1);
 
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        int pos = lo + (((double)(hi - lo) /
            (arr[hi] - arr[lo])) * (x - arr[lo]));
 
        if (arr[pos] == x)
            return pos;
 
        if (arr[pos] < x)
            lo = pos + 1;
 
        else
            hi = pos - 1;
    }
    return -1;
}
 
int main()
{
    int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 16;
    int index = interpolation_search(arr, n, x);
 
    if (index != -1)
        printf("Element found at index %d", index);
    else
        printf("Element not found.");
    return 0;
}